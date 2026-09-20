#!/usr/bin/env python3
"""Send one fixed goal after an online SLAM map and TF become available.

This is intentionally separate from auto_nav_su.py so it can be used as a
small simulation test tool without changing the existing waypoint state
machine. The goal can be expressed in the SLAM ``map`` frame or in ``odom``.
"""

import argparse
import json
import math
from pathlib import Path

import rclpy
from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PointStamped, PoseStamped
from nav2_msgs.action import NavigateToPose
from nav_msgs.msg import OccupancyGrid
from rclpy.action import ActionClient
from rclpy.duration import Duration
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rclpy.time import Time
from tf2_ros import Buffer, TransformException, TransformListener


ROUTE_FORMAT = "pfa_online_slam_route/v1"


def quaternion_from_yaw(yaw):
    return 0.0, 0.0, math.sin(yaw * 0.5), math.cos(yaw * 0.5)


def parse_route_data(data):
    """Validate and normalize the portable online-SLAM route format."""
    if not isinstance(data, dict) or data.get("format") != ROUTE_FORMAT:
        raise ValueError(f"路线 format 必须是 {ROUTE_FORMAT}")
    frame = data.get("frame")
    if frame not in ("map", "odom"):
        raise ValueError("路线 frame 必须是 map 或 odom")
    raw_waypoints = data.get("waypoints")
    if not isinstance(raw_waypoints, list) or not raw_waypoints:
        raise ValueError("路线 waypoints 必须是非空数组")

    waypoints = []
    for index, waypoint in enumerate(raw_waypoints, start=1):
        if not isinstance(waypoint, dict) or not all(
            key in waypoint for key in ("x", "y")
        ):
            raise ValueError(f"路线第 {index} 个点必须包含 x 和 y")
        try:
            x = float(waypoint["x"])
            y = float(waypoint["y"])
            yaw = float(waypoint.get("yaw", 0.0))
        except (TypeError, ValueError) as exc:
            raise ValueError(f"路线第 {index} 个点坐标不是有效数字") from exc
        if not all(math.isfinite(value) for value in (x, y, yaw)):
            raise ValueError(f"路线第 {index} 个点坐标必须是有限数字")
        waypoints.append(
            {
                "name": str(waypoint.get("name") or f"waypoint_{index}"),
                "x": x,
                "y": y,
                "yaw": yaw,
            }
        )
    return frame, waypoints


class OnlineSlamGoal(Node):
    def __init__(
        self,
        x=None,
        y=None,
        yaw=0.0,
        goal_frame="map",
        map_frame="map",
        base_frame="gimbal_yaw",
        click_topic=None,
        goal_file=None,
        save_goal=True,
        start_mode="immediate",
        game_status_topic="/referee/game_status",
        route_waypoints=None,
        record_only=False,
    ):
        super().__init__("online_slam_goal")
        self.goal_x = None if x is None else float(x)
        self.goal_y = None if y is None else float(y)
        self.goal_yaw = float(yaw)
        self.goal_frame = goal_frame
        self.goal_file = Path(goal_file).expanduser() if goal_file else None
        self.save_goal = bool(save_goal)
        self.start_mode = start_mode
        self.start_allowed = start_mode == "immediate"
        self.game_status_topic = game_status_topic
        self.route_waypoints = list(route_waypoints or [])
        self.route_index = 0
        self.record_only = bool(record_only)
        self.current_goal_name = None
        if self.route_waypoints:
            first = self.route_waypoints[0]
            self.goal_x = first["x"]
            self.goal_y = first["y"]
            self.goal_yaw = first["yaw"]
            self.current_goal_name = first["name"]
        self.map_frame = map_frame
        self.base_frame = base_frame
        self.latest_map = None
        self.goal_sent = False
        self.finished = False
        self.start_time = self.get_clock().now()

        self.map_sub = self.create_subscription(
            OccupancyGrid, "map", self.map_callback, 10
        )
        self.game_status_sub = None
        self.game_status_type = None
        if self.start_mode == "referee":
            try:
                from pb_rm_interfaces.msg import GameStatus
            except ModuleNotFoundError as exc:
                raise RuntimeError(
                    "正式比赛模式需要 pb_rm_interfaces；请先执行 "
                    "source /opt/ros/humble/setup.bash && "
                    "source install/setup.bash"
                ) from exc
            self.game_status_type = GameStatus
            self.game_status_sub = self.create_subscription(
                GameStatus,
                self.game_status_topic,
                self.game_status_callback,
                10,
            )
            self.get_logger().warn(
                f"比赛启动门控已启用：等待 {self.game_status_topic} "
                "的 game_progress=RUNNING(4)，收到前绝不发送导航目标"
            )
        else:
            self.get_logger().warn("立即出发模式已启用，不等待比赛开始信号")
        self.click_sub = None
        if click_topic:
            self.click_sub = self.create_subscription(
                PointStamped, click_topic, self.click_callback, 10
            )
        self.nav_client = ActionClient(self, NavigateToPose, "navigate_to_pose")
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.timer = self.create_timer(0.5, self.try_send_goal)
        if self.goal_x is None or self.goal_y is None:
            self.get_logger().info(
                f"等待 RViz 点击目标 ({click_topic})，点击点坐标将按 {self.goal_frame} 解释"
            )
        elif self.route_waypoints:
            self.get_logger().info(
                f"已加载顺序路线，共 {len(self.route_waypoints)} 个点；"
                f"当前等待第 1 个点: {self.current_goal_name}"
            )
        else:
            self.get_logger().info(
                f"已缓存目标点: ({self.goal_x:.3f}, {self.goal_y:.3f}) "
                f"frame={self.goal_frame}, yaw={self.goal_yaw:.3f} rad; "
                "等待在线 SLAM 地图和 TF"
            )

    def map_callback(self, msg):
        self.latest_map = msg

    def game_status_callback(self, msg):
        if self.start_allowed:
            return
        if msg.game_progress == self.game_status_type.RUNNING:
            self.start_allowed = True
            self.get_logger().warn("已收到比赛 RUNNING 状态，导航目标允许发送")

    def click_callback(self, msg):
        if self.goal_x is not None and self.goal_y is not None:
            return
        self.goal_x = float(msg.point.x)
        self.goal_y = float(msg.point.y)
        if msg.header.frame_id and msg.header.frame_id != self.goal_frame:
            self.get_logger().warn(
                f"点击消息 frame={msg.header.frame_id}，但命令行 goal-frame={self.goal_frame}；"
                "将按命令行指定坐标系处理"
            )
        self.get_logger().info(
            f"已记录 RViz 点击目标: ({self.goal_x:.3f}, {self.goal_y:.3f}) "
            f"frame={self.goal_frame}"
        )
        if self.save_goal and self.goal_file is not None:
            self.save_goal_file()
        if self.record_only:
            self.get_logger().info("仅录点模式完成，不发送导航目标")
            self.finished = True

    def save_goal_file(self):
        data = {
            "frame": self.goal_frame,
            "x": self.goal_x,
            "y": self.goal_y,
            "yaw": self.goal_yaw,
        }
        try:
            self.goal_file.parent.mkdir(parents=True, exist_ok=True)
            self.goal_file.write_text(
                json.dumps(data, ensure_ascii=False, indent=2) + "\n",
                encoding="utf-8",
            )
            self.get_logger().info(f"目标点已保存到: {self.goal_file}")
        except OSError as exc:
            self.get_logger().error(f"保存目标点失败 {self.goal_file}: {exc}")

    @staticmethod
    def yaw_from_quaternion(q):
        return math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y * q.y + q.z * q.z),
        )

    def goal_in_map(self):
        """Resolve the fixed goal into map coordinates once map->goal_frame exists."""
        if self.goal_frame == self.map_frame:
            return self.goal_x, self.goal_y, self.goal_yaw
        try:
            transform = self.tf_buffer.lookup_transform(
                self.map_frame, self.goal_frame, Time()
            )
        except TransformException:
            return None
        t = transform.transform.translation
        q = transform.transform.rotation
        source_yaw = self.yaw_from_quaternion(q)
        cos_yaw = math.cos(source_yaw)
        sin_yaw = math.sin(source_yaw)
        map_x = t.x + cos_yaw * self.goal_x - sin_yaw * self.goal_y
        map_y = t.y + sin_yaw * self.goal_x + cos_yaw * self.goal_y
        return map_x, map_y, self.goal_yaw + source_yaw

    def map_contains_goal(self, goal_x, goal_y):
        if self.latest_map is None:
            return False
        info = self.latest_map.info
        if info.resolution <= 0.0 or info.width == 0 or info.height == 0:
            return False
        min_x = info.origin.position.x
        min_y = info.origin.position.y
        max_x = min_x + info.width * info.resolution
        max_y = min_y + info.height * info.resolution
        return min_x <= goal_x < max_x and min_y <= goal_y < max_y

    def tf_ready(self):
        return self.tf_buffer.can_transform(
            self.map_frame,
            self.base_frame,
            Time(),
            timeout=Duration(seconds=0.05),
        )

    def try_send_goal(self):
        if self.goal_sent or self.finished:
            return
        if self.goal_x is None or self.goal_y is None:
            return
        elapsed = (self.get_clock().now() - self.start_time).nanoseconds / 1e9
        if self.latest_map is None:
            if int(elapsed) % 5 == 0:
                self.get_logger().info("等待 /map 发布...")
            return
        goal = self.goal_in_map()
        if goal is None:
            if int(elapsed) % 5 == 0:
                self.get_logger().info(
                    f"等待 TF {self.map_frame}->{self.goal_frame}..."
                )
            return
        goal_x, goal_y, goal_yaw = goal
        if not self.map_contains_goal(goal_x, goal_y):
            if int(elapsed) % 5 == 0:
                self.get_logger().info("目标点尚未落入当前地图范围，继续等待地图扩展...")
            return
        if not self.tf_ready():
            if int(elapsed) % 5 == 0:
                self.get_logger().info(
                    f"等待 TF {self.map_frame}->{self.base_frame}..."
                )
            return
        if not self.nav_client.server_is_ready():
            if int(elapsed) % 5 == 0:
                self.get_logger().info("等待 navigate_to_pose action server...")
            return
        if not self.start_allowed:
            if int(elapsed) % 5 == 0:
                self.get_logger().info(
                    f"导航系统已就绪，仍在等待比赛开始信号: {self.game_status_topic}"
                )
            return

        goal = NavigateToPose.Goal()
        goal.pose = PoseStamped()
        goal.pose.header.frame_id = self.map_frame
        goal.pose.header.stamp = self.get_clock().now().to_msg()
        goal.pose.pose.position.x = goal_x
        goal.pose.pose.position.y = goal_y
        goal.pose.pose.position.z = 0.0
        qx, qy, qz, qw = quaternion_from_yaw(goal_yaw)
        goal.pose.pose.orientation.x = qx
        goal.pose.pose.orientation.y = qy
        goal.pose.pose.orientation.z = qz
        goal.pose.pose.orientation.w = qw

        self.goal_sent = True
        if self.route_waypoints:
            progress = f"[{self.route_index + 1}/{len(self.route_waypoints)}] "
            target_name = self.current_goal_name
        else:
            progress = ""
            target_name = "单点目标"
        self.get_logger().info(
            f"地图、TF 和 action 已就绪，发送 {progress}{target_name}"
        )
        future = self.nav_client.send_goal_async(goal, feedback_callback=self.feedback_callback)
        future.add_done_callback(self.goal_response_callback)

    def feedback_callback(self, feedback_msg):
        distance = feedback_msg.feedback.distance_remaining
        prefix = ""
        if self.route_waypoints:
            prefix = f"路线点 {self.route_index + 1}/{len(self.route_waypoints)} "
        self.get_logger().info(f"{prefix}目标剩余距离: {distance:.3f} m")

    def goal_response_callback(self, future):
        try:
            goal_handle = future.result()
        except Exception as exc:
            self.get_logger().error(f"发送目标失败: {exc}")
            self.finished = True
            return
        if not goal_handle.accepted:
            self.get_logger().error("Nav2 拒绝了目标")
            self.finished = True
            return
        self.get_logger().info("Nav2 已接受目标，等待结果")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.result_callback)

    def result_callback(self, future):
        try:
            wrapped = future.result()
            self.get_logger().info(f"导航结束，状态码: {wrapped.status}")
        except Exception as exc:
            self.get_logger().error(f"读取导航结果失败: {exc}")
            self.finished = True
            return

        if (
            wrapped.status == GoalStatus.STATUS_SUCCEEDED
            and self.route_waypoints
            and self.route_index + 1 < len(self.route_waypoints)
        ):
            self.route_index += 1
            waypoint = self.route_waypoints[self.route_index]
            self.goal_x = waypoint["x"]
            self.goal_y = waypoint["y"]
            self.goal_yaw = waypoint["yaw"]
            self.current_goal_name = waypoint["name"]
            self.goal_sent = False
            self.start_time = self.get_clock().now()
            self.get_logger().info(
                f"切换到路线点 {self.route_index + 1}/{len(self.route_waypoints)}: "
                f"{self.current_goal_name}；若尚未进入地图范围则继续等待地图扩展"
            )
            return

        if self.route_waypoints and wrapped.status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("顺序巡航路线已全部完成")
        elif self.route_waypoints:
            self.get_logger().error(
                f"路线在第 {self.route_index + 1} 个点停止，不会跳过失败点"
            )
        self.finished = True


def main():
    parser = argparse.ArgumentParser(
        description="在线 SLAM 地图就绪后发送一个固定 NavigateToPose 目标"
    )
    parser.add_argument("--x", type=float, help="目标坐标 x；--wait-click 时可省略")
    parser.add_argument("--y", type=float, help="目标坐标 y；--wait-click 时可省略")
    parser.add_argument("--yaw", type=float, default=0.0, help="目标 yaw，单位 rad")
    parser.add_argument(
        "--goal-frame",
        choices=("map", "odom"),
        default="map",
        help="目标点所在坐标系；odom 适合固定初始位置的相对目标",
    )
    parser.add_argument(
        "--wait-click",
        action="store_true",
        help="不指定 x/y，等待 RViz clicked_point 作为目标",
    )
    parser.add_argument(
        "--click-topic",
        default="clicked_point",
        help="RViz Publish Point 话题；命名空间由 --ros-args __ns 决定",
    )
    parser.add_argument(
        "--goal-file",
        default="online_slam_goal.json",
        help="保存/读取固定目标的 JSON 文件，默认当前目录 online_slam_goal.json",
    )
    parser.add_argument(
        "--use-saved-goal",
        action="store_true",
        help="从 --goal-file 自动加载目标，不需要 RViz 点击",
    )
    parser.add_argument(
        "--route-file",
        default="online_slam_route.json",
        help="顺序路线 JSON 文件",
    )
    parser.add_argument(
        "--use-saved-route",
        action="store_true",
        help="从 --route-file 加载路线，并按顺序逐点导航",
    )
    parser.add_argument(
        "--record-only",
        action="store_true",
        help="记录 RViz 点击并保存后退出，不发送导航目标",
    )
    parser.add_argument(
        "--no-save",
        action="store_true",
        help="--wait-click 模式下不保存本次点击目标",
    )
    parser.add_argument("--map-frame", default="map")
    parser.add_argument("--base-frame", default="gimbal_yaw")
    parser.add_argument(
        "--start-mode",
        choices=("immediate", "referee"),
        default="immediate",
        help="immediate 立即允许发目标；referee 等待比赛状态 RUNNING",
    )
    parser.add_argument(
        "--game-status-topic",
        default="/referee/game_status",
        help="比赛状态话题，消息类型为 pb_rm_interfaces/msg/GameStatus",
    )
    args, ros_args = parser.parse_known_args()
    if args.use_saved_goal and args.use_saved_route:
        parser.error("--use-saved-goal 和 --use-saved-route 不能同时使用")

    saved_goal = None
    route_waypoints = None
    if args.use_saved_goal:
        try:
            saved_goal = json.loads(
                Path(args.goal_file).expanduser().read_text(encoding="utf-8")
            )
        except (OSError, json.JSONDecodeError) as exc:
            parser.error(f"读取目标文件失败 {args.goal_file}: {exc}")
        if saved_goal.get("frame") not in ("map", "odom"):
            parser.error("目标文件 frame 必须是 map 或 odom")
        if not all(key in saved_goal for key in ("x", "y")):
            parser.error("目标文件必须包含 x 和 y")
        args.x = float(saved_goal["x"])
        args.y = float(saved_goal["y"])
        args.yaw = float(saved_goal.get("yaw", 0.0))
        args.goal_frame = saved_goal["frame"]
        args.wait_click = False
    elif args.use_saved_route:
        try:
            route_data = json.loads(
                Path(args.route_file).expanduser().read_text(encoding="utf-8")
            )
            args.goal_frame, route_waypoints = parse_route_data(route_data)
        except (OSError, json.JSONDecodeError, ValueError) as exc:
            parser.error(f"读取路线文件失败 {args.route_file}: {exc}")
        first = route_waypoints[0]
        args.x = first["x"]
        args.y = first["y"]
        args.yaw = first["yaw"]
        args.wait_click = False
    if args.wait_click:
        if args.x is not None or args.y is not None:
            parser.error("--wait-click 不能与 --x/--y 同时使用")
        if args.goal_frame != "odom":
            parser.error("--wait-click 模式请使用 --goal-frame odom，并将 RViz Fixed Frame 设为 odom")
        if args.record_only and args.no_save:
            parser.error("--record-only 不能与 --no-save 同时使用")
    elif args.x is None or args.y is None:
        parser.error("必须同时指定 --x/--y，或使用 --wait-click")
    elif args.record_only:
        parser.error("--record-only 只能与 --wait-click 一起使用")

    rclpy.init(args=ros_args)
    node = OnlineSlamGoal(
        args.x,
        args.y,
        args.yaw,
        goal_frame=args.goal_frame,
        map_frame=args.map_frame,
        base_frame=args.base_frame,
        click_topic=args.click_topic if args.wait_click else None,
        goal_file=args.goal_file,
        save_goal=not args.no_save,
        start_mode=args.start_mode,
        game_status_topic=args.game_status_topic,
        route_waypoints=route_waypoints,
        record_only=args.record_only,
    )
    try:
        while rclpy.ok() and not node.finished:
            rclpy.spin_once(node, timeout_sec=0.2)
    except KeyboardInterrupt:
        node.get_logger().info("用户中止在线 SLAM 目标测试")
    except ExternalShutdownException:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
