#!/usr/bin/env python3

# 自动循环导航 - 从文件读取目标点并自动循环导航
import rclpy
from rclpy.node import Node
from action_msgs.msg import GoalStatus
from collections import deque
from geometry_msgs.msg import PoseStamped, Twist
from nav_msgs.msg import Path
from nav2_msgs.action import NavigateToPose, NavigateThroughPoses
from rcl_interfaces.msg import Log
from rclpy.action import ActionClient
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile
from rclpy.time import Time
from tf2_ros import Buffer, TransformException, TransformListener
from tf2_msgs.msg import TFMessage
import yaml
import argparse
import time
import math

ROS_LOG_DEBUG = Log.DEBUG[0]
ROS_LOG_INFO = Log.INFO[0]
ROS_LOG_WARN = Log.WARN[0]
ROS_LOG_ERROR = Log.ERROR[0]
ROS_LOG_FATAL = Log.FATAL[0]


def clamp(value, min_value, max_value):
    return max(min_value, min(max_value, value))


def shortest_angular_distance(current_yaw, target_yaw):
    return math.atan2(
        math.sin(target_yaw - current_yaw),
        math.cos(target_yaw - current_yaw)
    )


def compute_waypoint_segment_geometry(waypoints, from_waypoint_idx, to_waypoint_idx):
    from_wp = waypoints[from_waypoint_idx]
    to_wp = waypoints[to_waypoint_idx]
    dx = float(to_wp['Pos_x']) - float(from_wp['Pos_x'])
    dy = float(to_wp['Pos_y']) - float(from_wp['Pos_y'])
    length = math.hypot(dx, dy)
    if length < 1e-3:
        raise ValueError("直行校准两点距离过短")
    return math.atan2(dy, dx), length


def compute_straight_segment_plan(waypoints, from_waypoint_idx, to_waypoint_idx):
    heading, length = compute_waypoint_segment_geometry(
        waypoints, from_waypoint_idx, to_waypoint_idx
    )
    return heading, length, 1.0


def project_progress(current_xy, start_xy, heading):
    return (
        (current_xy[0] - start_xy[0]) * math.cos(heading) +
        (current_xy[1] - start_xy[1]) * math.sin(heading)
    )


def cross_track_error(current_xy, start_xy, heading):
    return (
        -(current_xy[0] - start_xy[0]) * math.sin(heading) +
        (current_xy[1] - start_xy[1]) * math.cos(heading)
    )


def transform_local_velocity_between_yaws(vx, vy, source_yaw, target_yaw):
    vx_map = math.cos(source_yaw) * vx - math.sin(source_yaw) * vy
    vy_map = math.sin(source_yaw) * vx + math.cos(source_yaw) * vy
    vx_target = math.cos(target_yaw) * vx_map + math.sin(target_yaw) * vy_map
    vy_target = -math.sin(target_yaw) * vx_map + math.cos(target_yaw) * vy_map
    return vx_target, vy_target


def compute_local_approach_velocity(current_xy, current_yaw, target_xy, tolerance, max_speed):
    dx = target_xy[0] - current_xy[0]
    dy = target_xy[1] - current_xy[1]
    distance = math.hypot(dx, dy)
    if distance <= tolerance:
        return 0.0, 0.0, True

    speed = min(abs(max_speed), distance)
    scale = speed / distance
    vx_map = dx * scale
    vy_map = dy * scale

    cos_yaw = math.cos(current_yaw)
    sin_yaw = math.sin(current_yaw)
    vx_local = cos_yaw * vx_map + sin_yaw * vy_map
    vy_local = -sin_yaw * vx_map + cos_yaw * vy_map
    return vx_local, vy_local, False


def should_handoff_to_straight_calibration(
    targets, current_idx, calibration_transitions, waypoints, current_xy, tolerance
):
    if not targets:
        return False, None, float('inf')

    next_idx = (current_idx + 1) % len(targets)
    current_waypoint_idx = targets[current_idx]
    next_waypoint_idx = targets[next_idx]
    current_id = current_waypoint_idx + 1
    next_id = next_waypoint_idx + 1

    waypoint = waypoints[current_waypoint_idx]
    target_x = float(waypoint['Pos_x'])
    target_y = float(waypoint['Pos_y'])
    distance = math.hypot(target_x - current_xy[0], target_y - current_xy[1])

    should_handoff = (
        (current_id, next_id) in calibration_transitions and
        distance <= abs(tolerance)
    )
    return should_handoff, next_idx, distance


class AutoNavNode(Node):
    def __init__(
        self,
        yaml_path,
        order,
        through_all_waypoints=False,
        straight_distance=5.0,
        straight_speed=0.5,
        straight_yaw_tolerance=0.05,
        straight_stop_margin=0.15,
        straight_turn_kp=1.8,
        straight_max_turn_speed=0.8,
        straight_drive_yaw_kp=1.2,
        straight_drive_turn_limit=0.35,
        straight_timeout_extra=5.0,
        cmd_vel_topic='/red_standard_robot1/cmd_vel',
        map_frame='map',
        chassis_frame='chassis',
        velocity_frame='gimbal_yaw',
        yaw_log_distance=0.15,
        tf_topic='/red_standard_robot1/tf',
        tf_static_topic='/red_standard_robot1/tf_static',
        straight_path_topic='/red_standard_robot1/auto_nav_straight_path',
    ):
        super().__init__('auto_nav_node')
        
        # 加载航点
        self.waypoints = self.load_waypoints(yaml_path)
        self.get_logger().info(f"已从 {yaml_path} 加载 {len(self.waypoints)} 个航点")
        
        self.through_all_waypoints = through_all_waypoints

        if self.through_all_waypoints:
            self.targets = list(range(len(self.waypoints)))
            self.get_logger().info("已启用整条路线模式：将一次性规划并经过 YAML 中的全部航点")
        else:
            # 将目标点编号转换为索引（从1开始转为从0开始）
            self.targets = [idx - 1 for idx in order]

        # 验证目标点索引
        for i, idx in enumerate(self.targets):
            if 0 <= idx < len(self.waypoints):
                wp_name = self.waypoints[idx].get('Name', f'Waypoint_{idx+1}')
                if self.through_all_waypoints:
                    self.get_logger().info(f"路线点 {i+1}: 编号 {idx + 1} ({wp_name})")
                else:
                    self.get_logger().info(f"目标点 {i+1}: 编号 {order[i]} ({wp_name})")
            else:
                invalid_id = idx + 1 if self.through_all_waypoints else order[i]
                self.get_logger().error(f"目标点编号 {invalid_id} 超出范围 [1-{len(self.waypoints)}]")
                raise ValueError(f"无效的目标点编号: {invalid_id}")
        
        if not self.targets:
            self.get_logger().error("未加载到任何目标点，退出")
            raise ValueError("目标点列表为空")
        
        # 导航客户端
        self.nav_ac = ActionClient(self, NavigateToPose, '/red_standard_robot1/navigate_to_pose')
        self.nav_through_poses_ac = ActionClient(
            self, NavigateThroughPoses, '/red_standard_robot1/navigate_through_poses'
        )

        self.map_frame = map_frame
        self.chassis_frame = chassis_frame
        self.position_frame = 'gimbal_yaw_fake'
        self.velocity_frame = velocity_frame
        self.yaw_log_distance = abs(yaw_log_distance)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.tf_topic = tf_topic
        self.tf_static_topic = tf_static_topic
        self.straight_path_topic = straight_path_topic
        self.last_tf_warn_time = 0.0
        self.tf_warn_interval = 5.0

        tf_qos = QoSProfile(
            depth=100,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
        )
        tf_static_qos = QoSProfile(
            depth=100,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            history=HistoryPolicy.KEEP_LAST,
        )
        self.namespaced_tf_sub = self.create_subscription(
            TFMessage, tf_topic, self.tf_callback, tf_qos
        )
        self.namespaced_tf_static_sub = self.create_subscription(
            TFMessage, tf_static_topic, self.tf_static_callback, tf_static_qos
        )
        path_qos = QoSProfile(
            depth=1,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            history=HistoryPolicy.KEEP_LAST,
        )
        self.straight_path_pub = self.create_publisher(Path, straight_path_topic, path_qos)
        self.get_logger().info(
            f"方向检查日志: XY 使用 TF {map_frame}->{self.position_frame}, "
            f"yaw 使用 TF {map_frame}->{chassis_frame}, "
            f"监听 {tf_topic}, {tf_static_topic}, 距离阈值 {self.yaw_log_distance:.2f}m"
        )

        # 2->3 / 3->2 之间的直行校准
        self.calibration_transitions = {(2, 3), (3, 2)}
        self.straight_enabled = abs(straight_distance) > 0.0
        self.straight_speed = abs(straight_speed)
        self.straight_yaw_tolerance = abs(straight_yaw_tolerance)
        self.straight_stop_margin = abs(straight_stop_margin)
        self.straight_turn_kp = abs(straight_turn_kp)
        self.straight_max_turn_speed = abs(straight_max_turn_speed)
        self.straight_drive_yaw_kp = abs(straight_drive_yaw_kp)
        self.straight_drive_turn_limit = abs(straight_drive_turn_limit)
        self.straight_timeout_extra = abs(straight_timeout_extra)
        self.straight_start_tolerance = 0.8
        if self.straight_enabled:
            if abs(self.straight_speed) < 1e-3:
                raise ValueError("straight_speed 不能为 0")
        self.cmd_vel_pub = self.create_publisher(Twist, cmd_vel_topic, 10)
        self.get_logger().info(
            f"直线校准速度发布: 底盘控制量先转换到 {self.velocity_frame} 基准，"
            f"再发布到 {cmd_vel_topic}"
        )
        self.rosout_sub = self.create_subscription(Log, '/rosout', self.rosout_callback, 50)
        self.calibrating = False
        self.calibration_phase = None
        self.calibration_heading = 0.0
        self.calibration_drive_direction = 1.0
        self.calibration_length = 0.0
        self.calibration_start_xy = None
        self.calibration_entry_xy = None
        self.calibration_target_xy = None
        self.calibration_start_time = None
        self.calibration_next_idx = None
        self.calibration_pair = None
        self.calibration_last_drive_log_time = 0.0
        self.current_goal_handle = None
        self.goal_sequence = 0
        self.active_goal_sequence = None
        self.ignored_goal_sequences = set()
        self.pending_straight_handoff_next_idx = None
        self.straight_handoff_cancel_requested = False
        self.straight_path_indices = None
        self.recent_nav_logs = deque(maxlen=50)
        self.nav_log_window_sec = 30.0
        self.nav_log_nodes = (
            'bt_navigator',
            'planner_server',
            'controller_server',
            'behavior_server',
            'costmap',
        )

        if self.through_all_waypoints:
            self.get_logger().warn("整条路线模式不会插入 2->3 / 3->2 的直行校准动作")
        elif self.straight_enabled:
            self.get_logger().info(
                "直行校准启用: 2->3 / 3->2 时先对准两点连线，再沿直线通过，"
                f"速度 {self.straight_speed:.2f}m/s"
            )
            self.publish_straight_path_by_waypoint_ids(2, 3)
        else:
            self.get_logger().info("直线校准关闭")
        
        # 循环导航状态
        self.current_idx = 0
        self.sending = False
        self.max_retry = 3
        self.retry_count = 0
        
        # 启动导航循环定时器
        self.timer = self.create_timer(1.0, self.navigation_loop)
        self.straight_handoff_timer = self.create_timer(0.2, self.straight_handoff_loop)
        self.calibration_timer = self.create_timer(0.05, self.calibration_loop)
        self.yaw_log_timer = self.create_timer(0.5, self.yaw_calibration_log_loop)
        self.get_logger().info("自动循环导航节点已启动")

    def tf_callback(self, msg):
        """把命名空间内的 TF 写入本节点的 TF buffer"""
        for transform in msg.transforms:
            self.tf_buffer.set_transform(transform, 'auto_nav_tf')

    def tf_static_callback(self, msg):
        """把命名空间内的静态 TF 写入本节点的 TF buffer"""
        for transform in msg.transforms:
            self.tf_buffer.set_transform_static(transform, 'auto_nav_tf_static')

    def rosout_callback(self, msg):
        """缓存 Nav2 相关 WARN/ERROR，导航失败时一起打印辅助定位原因"""
        if msg.level < ROS_LOG_WARN:
            return
        if not any(node_name in msg.name for node_name in self.nav_log_nodes):
            return
        self.recent_nav_logs.append(
            (time.monotonic(), self.log_level_name(msg.level), msg.name, msg.msg)
        )

    def log_level_name(self, level):
        """转换 /rosout 日志等级为可读字符串"""
        level_names = {
            ROS_LOG_DEBUG: 'DEBUG',
            ROS_LOG_INFO: 'INFO',
            ROS_LOG_WARN: 'WARN',
            ROS_LOG_ERROR: 'ERROR',
            ROS_LOG_FATAL: 'FATAL',
        }
        return level_names.get(level, str(level))

    def goal_status_name(self, status):
        """转换 action 状态码为可读字符串"""
        status_names = {
            GoalStatus.STATUS_UNKNOWN: 'UNKNOWN',
            GoalStatus.STATUS_ACCEPTED: 'ACCEPTED',
            GoalStatus.STATUS_EXECUTING: 'EXECUTING',
            GoalStatus.STATUS_CANCELING: 'CANCELING',
            GoalStatus.STATUS_SUCCEEDED: 'SUCCEEDED',
            GoalStatus.STATUS_CANCELED: 'CANCELED',
            GoalStatus.STATUS_ABORTED: 'ABORTED',
        }
        return status_names.get(status, f'UNKNOWN_STATUS_{status}')

    def log_recent_nav_errors(self):
        """打印最近的 Nav2 WARN/ERROR 日志，辅助解释 action 失败原因"""
        now = time.monotonic()
        recent_logs = [
            item for item in self.recent_nav_logs
            if now - item[0] <= self.nav_log_window_sec
        ]
        if not recent_logs:
            self.get_logger().warn(
                f"最近 {self.nav_log_window_sec:.0f}s 没有缓存到 Nav2 WARN/ERROR，"
                "请查看 planner_server/controller_server 日志"
            )
            return

        self.get_logger().warn(
            f"最近 {self.nav_log_window_sec:.0f}s Nav2 WARN/ERROR，可能是失败原因:"
        )
        for _, level_name, node_name, text in recent_logs[-8:]:
            self.get_logger().warn(f"  [{level_name}] [{node_name}]: {text}")

    def quaternion_to_yaw(self, orientation):
        """从四元数计算 yaw"""
        return self.quaternion_values_to_yaw(
            orientation.x, orientation.y, orientation.z, orientation.w
        )

    def quaternion_values_to_yaw(self, x, y, z, w):
        """从四元数数值计算 yaw"""
        siny_cosp = 2.0 * (
            w * z + x * y
        )
        cosy_cosp = 1.0 - 2.0 * (
            y * y + z * z
        )
        return math.atan2(siny_cosp, cosy_cosp)

    def shortest_angular_distance(self, current_yaw, target_yaw):
        """计算 current_yaw 到 target_yaw 的最短有符号角度差"""
        return shortest_angular_distance(current_yaw, target_yaw)

    def lookup_frame_pose(self, frame):
        """查询指定 frame 在 map 下的位置和 yaw"""
        transform = self.tf_buffer.lookup_transform(
            self.map_frame, frame, Time()
        )
        translation = transform.transform.translation
        yaw = self.quaternion_to_yaw(transform.transform.rotation)
        return translation.x, translation.y, yaw

    def lookup_chassis_pose(self):
        """查询底盘在 map 下的位置和 yaw"""
        return self.lookup_frame_pose(self.chassis_frame)

    def lookup_calibration_pose(self):
        """直线校准用 gimbal_yaw_fake 的 XY、chassis yaw 和速度发布基准 yaw"""
        current_x, current_y, _ = self.lookup_frame_pose(self.position_frame)
        _, _, current_yaw = self.lookup_frame_pose(self.chassis_frame)
        _, _, velocity_yaw = self.lookup_frame_pose(self.velocity_frame)
        return current_x, current_y, current_yaw, velocity_yaw

    def yaw_calibration_log_loop(self):
        """目标点附近打印底盘当前角度、目标角度和角度差"""
        if self.through_all_waypoints or not self.sending or self.calibrating:
            return
        if self.yaw_log_distance <= 0.0:
            return

        waypoint_idx = self.targets[self.current_idx]
        waypoint = self.waypoints[waypoint_idx]

        try:
            current_x, current_y, _ = self.lookup_frame_pose(self.position_frame)
            _, _, current_yaw = self.lookup_frame_pose(self.chassis_frame)
        except TransformException as ex:
            now = time.monotonic()
            if now - self.last_tf_warn_time >= self.tf_warn_interval:
                self.last_tf_warn_time = now
                self.get_logger().warn(
                    f"方向检查日志无法查询 TF "
                    f"{self.map_frame}->{self.position_frame} 或 "
                    f"{self.map_frame}->{self.chassis_frame}: {ex}. "
                    f"当前监听 {self.tf_topic} 和 {self.tf_static_topic}"
                )
            return

        target_x = float(waypoint['Pos_x'])
        target_y = float(waypoint['Pos_y'])
        distance = math.hypot(target_x - current_x, target_y - current_y)
        if distance > self.yaw_log_distance:
            return

        target_yaw = self.quaternion_values_to_yaw(
            float(waypoint['Ori_x']),
            float(waypoint['Ori_y']),
            float(waypoint['Ori_z']),
            float(waypoint['Ori_w'])
        )
        yaw_diff = self.shortest_angular_distance(current_yaw, target_yaw)
        wp_name = waypoint.get('Name', f'Waypoint_{waypoint_idx + 1}')

        self.get_logger().info(
            f"方向检查 [{wp_name}]: 距离 {distance:.3f}m, "
            f"当前 yaw {current_yaw:.3f}rad ({math.degrees(current_yaw):.1f}deg), "
            f"目标 yaw {target_yaw:.3f}rad ({math.degrees(target_yaw):.1f}deg), "
            f"差值 {yaw_diff:.3f}rad ({math.degrees(yaw_diff):.1f}deg)"
        )

    def straight_handoff_loop(self):
        """Nav2 卡在 2/3 点附近时，提前交接到直线校准段。"""
        if self.through_all_waypoints or not self.straight_enabled:
            return
        if self.calibrating or not self.sending:
            return
        if self.pending_straight_handoff_next_idx is not None:
            return

        try:
            current_x, current_y, _ = self.lookup_frame_pose(self.position_frame)
        except TransformException as ex:
            now = time.monotonic()
            if now - self.last_tf_warn_time >= self.tf_warn_interval:
                self.last_tf_warn_time = now
                self.get_logger().warn(
                    f"直线校准交接检查无法查询 TF "
                    f"{self.map_frame}->{self.position_frame}: {ex}"
                )
            return

        should_handoff, next_idx, distance = should_handoff_to_straight_calibration(
            self.targets,
            self.current_idx,
            self.calibration_transitions,
            self.waypoints,
            (current_x, current_y),
            self.straight_start_tolerance,
        )
        if not should_handoff:
            return

        current_id = self.targets[self.current_idx] + 1
        next_id = self.targets[next_idx] + 1
        self.pending_straight_handoff_next_idx = next_idx
        if self.active_goal_sequence is not None:
            self.ignored_goal_sequences.add(self.active_goal_sequence)
        self.get_logger().warn(
            f"Nav2 尚未返回到达 {current_id}，但 {self.position_frame} 距目标点 "
            f"已 {distance:.3f}m <= {self.straight_start_tolerance:.3f}m，"
            f"取消当前 Nav2 goal 并提前交接到 {current_id}->{next_id} 直线校准"
        )

        if self.current_goal_handle is None:
            self.get_logger().info("直线校准交接已挂起，等待当前 Nav2 goal accepted 后取消")
            return

        self.request_cancel_for_straight_handoff()

    def request_cancel_for_straight_handoff(self):
        if self.straight_handoff_cancel_requested:
            return
        if self.current_goal_handle is None:
            return

        self.straight_handoff_cancel_requested = True
        cancel_future = self.current_goal_handle.cancel_goal_async()
        cancel_future.add_done_callback(self.cancel_for_straight_handoff_callback)

    def cancel_for_straight_handoff_callback(self, future):
        try:
            cancel_response = future.result()
            cancel_count = len(cancel_response.goals_canceling)
            if cancel_count > 0:
                self.get_logger().info("当前 Nav2 goal 已请求取消，准备进入直线校准")
            else:
                self.get_logger().warn(
                    "请求取消当前 Nav2 goal 时没有返回正在取消的 goal，仍继续直线校准交接"
                )
        except Exception as ex:
            self.get_logger().warn(f"请求取消当前 Nav2 goal 失败，仍继续直线校准交接: {ex}")

        self.complete_straight_handoff("Nav2 cancel 请求已处理")

    def complete_straight_handoff(self, reason):
        next_idx = self.pending_straight_handoff_next_idx
        if next_idx is None:
            return

        self.pending_straight_handoff_next_idx = None
        self.current_goal_handle = None
        self.active_goal_sequence = None
        self.straight_handoff_cancel_requested = False
        if self.calibrating:
            return

        self.get_logger().info(f"直线校准交接完成: {reason}")
        self.start_straight_calibration(next_idx)

    def load_waypoints(self, yaml_path):
        """从 YAML 文件加载所有航点"""
        with open(yaml_path, 'r') as f:
            data = yaml.safe_load(f)
        waypoints = []
        for i in range(1, data['Waypoints_Num'] + 1):
            waypoints.append(data[f'Waypoint_{i}'])
        return waypoints

    def load_targets_from_file(self, file_path):
        """从文件读取目标点索引列表
        
        文件格式：每行一个目标点编号（从1开始），支持注释（#开头）
        示例：
        # 这是注释
        1
        3
        5
        2
        """
        targets = []
        try:
            with open(file_path, 'r') as f:
                for line_num, line in enumerate(f, 1):
                    line = line.strip()
                    # 跳过空行和注释
                    if not line or line.startswith('#'):
                        continue
                    try:
                        # 解析目标点编号（从1开始，需要转换为索引）
                        idx = int(line) - 1
                        if 0 <= idx < len(self.waypoints):
                            targets.append(idx)
                            wp_name = self.waypoints[idx].get('Name', f'Waypoint_{idx+1}')
                            self.get_logger().info(
                                f"第{line_num}行: 目标点 {line} -> 索引 {idx} ({wp_name})"
                            )
                        else:
                            self.get_logger().warn(
                                f"第{line_num}行: 目标点编号 {line} 超出范围 [1-{len(self.waypoints)}]，已跳过"
                            )
                    except ValueError:
                        self.get_logger().warn(f"第{line_num}行: 无效的目标点编号 '{line}'，已跳过")
            
            self.get_logger().info(f"从 {file_path} 成功加载 {len(targets)} 个目标点")
        except FileNotFoundError:
            self.get_logger().error(f"目标点文件不存在: {file_path}")
        except Exception as e:
            self.get_logger().error(f"读取目标点文件失败: {e}")
        
        return targets

    def send_goal(self, waypoint_idx):
        """发送导航目标点"""
        if self.sending:
            return
        self.current_goal_handle = None
        self.pending_straight_handoff_next_idx = None
        self.straight_handoff_cancel_requested = False
        self.goal_sequence += 1
        goal_sequence = self.goal_sequence
        self.active_goal_sequence = goal_sequence
        
        goal = NavigateToPose.Goal()
        goal.pose = self.build_pose_stamped(waypoint_idx)
        
        self.nav_ac.wait_for_server()
        wp = self.waypoints[waypoint_idx]
        wp_name = wp.get('Name', f'Waypoint_{waypoint_idx+1}')
        self.get_logger().info(
            f"发送目标点 [{self.current_idx + 1}/{len(self.targets)}]: {wp_name}"
        )
        
        self._send_goal_future = self.nav_ac.send_goal_async(goal)
        self._send_goal_future.add_done_callback(
            lambda future, seq=goal_sequence: self.goal_response_callback(future, seq)
        )
        self.sending = True
        self.retry_count = 0

    def send_route_goal(self):
        """一次性发送整条经过所有点的导航路线"""
        if self.sending:
            return

        goal = NavigateThroughPoses.Goal()
        goal.poses = [self.build_pose_stamped(idx) for idx in self.targets]

        self.nav_through_poses_ac.wait_for_server()
        wp_names = [
            self.waypoints[idx].get('Name', f'Waypoint_{idx+1}')
            for idx in self.targets
        ]
        self.get_logger().info(
            f"发送整条路线，共 {len(goal.poses)} 个点: {' -> '.join(wp_names)}"
        )

        self._send_goal_future = self.nav_through_poses_ac.send_goal_async(goal)
        self._send_goal_future.add_done_callback(self.route_goal_response_callback)
        self.sending = True
        self.retry_count = 0

    def build_pose_stamped(self, waypoint_idx):
        """根据 waypoint 索引构造 PoseStamped"""
        wp = self.waypoints[waypoint_idx]
        pose = PoseStamped()
        pose.header.frame_id = 'map'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = float(wp['Pos_x'])
        pose.pose.position.y = float(wp['Pos_y'])
        pose.pose.position.z = float(wp['Pos_z'])
        pose.pose.orientation.x = float(wp['Ori_x'])
        pose.pose.orientation.y = float(wp['Ori_y'])
        pose.pose.orientation.z = float(wp['Ori_z'])
        pose.pose.orientation.w = float(wp['Ori_w'])
        return pose

    def build_path_pose(self, waypoint_idx):
        wp = self.waypoints[waypoint_idx]
        pose = PoseStamped()
        pose.header.frame_id = self.map_frame
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = float(wp['Pos_x'])
        pose.pose.position.y = float(wp['Pos_y'])
        pose.pose.position.z = float(wp['Pos_z'])
        pose.pose.orientation.w = 1.0
        return pose

    def publish_straight_path_by_waypoint_ids(self, from_id, to_id):
        from_idx = from_id - 1
        to_idx = to_id - 1
        if from_idx < 0 or to_idx < 0:
            return
        if from_idx >= len(self.waypoints) or to_idx >= len(self.waypoints):
            return
        self.publish_straight_path(from_idx, to_idx)

    def publish_straight_path(self, from_waypoint_idx, to_waypoint_idx):
        self.straight_path_indices = (from_waypoint_idx, to_waypoint_idx)
        path = Path()
        path.header.frame_id = self.map_frame
        path.header.stamp = self.get_clock().now().to_msg()
        path.poses = [
            self.build_path_pose(from_waypoint_idx),
            self.build_path_pose(to_waypoint_idx),
        ]
        for pose in path.poses:
            pose.header = path.header
        self.straight_path_pub.publish(path)

    def goal_response_callback(self, future, goal_sequence):
        """处理导航目标响应"""
        if goal_sequence != self.active_goal_sequence:
            self.get_logger().info("忽略过期的目标响应")
            return

        goal_handle = future.result()
        if not goal_handle.accepted:
            self.retry_count += 1
            self.active_goal_sequence = None
            if self.pending_straight_handoff_next_idx is not None:
                self.get_logger().warn("当前 Nav2 goal 被拒绝，直接进入直线校准交接")
                self.complete_straight_handoff("Nav2 goal 被拒绝，无需取消")
                return
            if self.retry_count < self.max_retry:
                self.get_logger().warn(f"目标被拒绝，重试第 {self.retry_count} 次...")
                self.sending = False
                self.send_goal(self.targets[self.current_idx])
            else:
                self.get_logger().error(
                    f"目标连续 {self.max_retry} 次被拒绝，继续重试当前点..."
                )
                self.sending = False
                self.retry_count = 0
            return
        
        self.current_goal_handle = goal_handle
        self.get_logger().info('目标已被接受，等待到达...')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(
            lambda future, seq=goal_sequence: self.result_callback(future, seq)
        )
        if self.pending_straight_handoff_next_idx is not None:
            self.request_cancel_for_straight_handoff()

    def route_goal_response_callback(self, future):
        """处理整条路线导航响应"""
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.retry_count += 1
            if self.retry_count < self.max_retry:
                self.get_logger().warn(f"整条路线目标被拒绝，重试第 {self.retry_count} 次...")
                self.sending = False
                self.send_route_goal()
            else:
                self.get_logger().error(
                    f"整条路线连续 {self.max_retry} 次被拒绝，等待下一轮重发..."
                )
                self.sending = False
                self.retry_count = 0
            return

        self.get_logger().info('整条路线目标已被接受，等待执行完成...')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.route_result_callback)

    def result_callback(self, future, goal_sequence=None):
        """处理导航结果"""
        result = future.result()
        status = result.status
        status_name = self.goal_status_name(status)

        if goal_sequence in self.ignored_goal_sequences:
            self.ignored_goal_sequences.discard(goal_sequence)
            self.get_logger().info(
                f"忽略已交接给直线校准的 Nav2 结果: {status_name}"
            )
            self.complete_straight_handoff("Nav2 action 已返回")
            return

        if (
            goal_sequence is not None and
            self.active_goal_sequence is not None and
            goal_sequence != self.active_goal_sequence
        ):
            self.get_logger().info(f"忽略过期的 Nav2 结果: {status_name}")
            return

        self.current_goal_handle = None
        self.active_goal_sequence = None
        
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info('✓ 成功到达目标点')
            # 单目标点模式：到达后结束
            if len(self.targets) == 1:
                self.get_logger().info('单目标点模式，导航完成，退出')
                self.timer.cancel()
                rclpy.shutdown()
                return
            time.sleep(0.5)
        else:
            self.get_logger().warn(f'✗ 导航失败，状态码: {status} ({status_name})')
            self.log_recent_nav_errors()
            self.sending = False
            self.retry_count = 0
            current_wp_name = self.waypoints[self.targets[self.current_idx]].get(
                'Name', f'Waypoint_{self.targets[self.current_idx]+1}'
            )
            self.get_logger().info(f"继续重试当前目标点: {current_wp_name}")
            return

        self.retry_count = 0

        # 切换到下一个目标点
        finished_idx = self.current_idx
        next_idx = (self.current_idx + 1) % len(self.targets)
        if status == GoalStatus.STATUS_SUCCEEDED and self.should_run_straight_calibration(
            finished_idx, next_idx
        ):
            self.start_straight_calibration(next_idx)
            return

        self.sending = False
        self.current_idx = next_idx
        next_wp_name = self.waypoints[self.targets[self.current_idx]].get(
            'Name', f'Waypoint_{self.targets[self.current_idx]+1}'
        )
        self.get_logger().info(f"准备导航到下一个点: {next_wp_name}")

    def should_run_straight_calibration(self, finished_idx, next_idx):
        """判断当前点到下一个点之间是否需要插入直行校准"""
        if self.through_all_waypoints:
            return False
        if not self.straight_enabled:
            return False
        finished_id = self.targets[finished_idx] + 1
        next_id = self.targets[next_idx] + 1
        return (finished_id, next_id) in self.calibration_transitions

    def start_straight_calibration(self, next_idx):
        """开始 2<->3 直线校准，完成后把 next_idx 视为已通过"""
        finished_id = self.targets[self.current_idx] + 1
        next_id = self.targets[next_idx] + 1
        from_waypoint_idx = self.targets[self.current_idx]
        to_waypoint_idx = self.targets[next_idx]

        try:
            heading, nominal_length, drive_direction = compute_straight_segment_plan(
                self.waypoints, from_waypoint_idx, to_waypoint_idx
            )
            current_x, current_y, current_yaw, velocity_yaw = self.lookup_calibration_pose()
        except (ValueError, TransformException) as ex:
            self.get_logger().warn(
                f"无法开始 {finished_id}->{next_id} 直线校准，改用 Nav2 导航到该点: {ex}"
            )
            self.sending = False
            self.current_idx = next_idx
            return

        entry_wp = self.waypoints[from_waypoint_idx]
        target_wp = self.waypoints[to_waypoint_idx]
        entry_xy = (float(entry_wp['Pos_x']), float(entry_wp['Pos_y']))
        target_xy = (float(target_wp['Pos_x']), float(target_wp['Pos_y']))
        entry_distance = math.hypot(entry_xy[0] - current_x, entry_xy[1] - current_y)
        entry_along_offset = project_progress((current_x, current_y), entry_xy, heading)
        entry_cross_offset = cross_track_error((current_x, current_y), entry_xy, heading)
        projected_length = project_progress(target_xy, (current_x, current_y), heading)
        initial_yaw_error = shortest_angular_distance(current_yaw, heading)
        initial_velocity_yaw_error = shortest_angular_distance(velocity_yaw, heading)
        self.sending = False
        self.calibrating = True
        self.calibration_phase = (
            'approach' if entry_distance > self.straight_start_tolerance else 'align'
        )
        self.calibration_heading = heading
        self.calibration_drive_direction = drive_direction
        self.calibration_length = max(projected_length, 0.0)
        self.calibration_start_xy = None
        self.calibration_entry_xy = entry_xy
        self.calibration_target_xy = target_xy
        self.calibration_start_time = self.get_clock().now()
        self.calibration_next_idx = next_idx
        self.calibration_pair = (finished_id, next_id)
        self.calibration_last_drive_log_time = 0.0
        self.publish_straight_path(from_waypoint_idx, to_waypoint_idx)
        self.get_logger().info(
            f"开始 {finished_id}->{next_id} 直线校准: 连线方向 {heading:.3f}rad, "
            f"路径角 {math.degrees(heading):.1f}deg, "
            f"车体朝向 {math.degrees(current_yaw):.1f}deg, "
            f"车体角度差 {math.degrees(initial_yaw_error):.1f}deg, "
            f"速度基准({self.velocity_frame})朝向 {math.degrees(velocity_yaw):.1f}deg, "
            f"速度基准角度差 {math.degrees(initial_velocity_yaw_error):.1f}deg, "
            f"速度方向 {drive_direction:+.0f}, 航点距离 {nominal_length:.2f}m, "
            f"当前需前进 {self.calibration_length:.2f}m, "
            f"当前位置 ({current_x:.3f}, {current_y:.3f}), "
            f"起点沿线偏移 {entry_along_offset:.3f}m, 起点横向偏差 {entry_cross_offset:.3f}m"
        )
        if self.calibration_phase == 'approach':
            self.get_logger().warn(
                f"Nav2 已返回到达 {finished_id}，但 {self.position_frame} 距该点还有 "
                f"{entry_distance:.3f}m > {self.straight_start_tolerance:.3f}m，"
                "先平移补到点内，再做方向对准"
            )

    def calibration_loop(self):
        """直线段定时器：先对准连线，再沿连线正向通过"""
        if not self.calibrating:
            return

        try:
            current_x, current_y, current_yaw, velocity_yaw = self.lookup_calibration_pose()
        except TransformException as ex:
            self.cmd_vel_pub.publish(Twist())
            now = time.monotonic()
            if now - self.last_tf_warn_time >= self.tf_warn_interval:
                self.last_tf_warn_time = now
                self.get_logger().warn(
                    f"直线校准无法查询 TF "
                    f"{self.map_frame}->{self.position_frame} 或 "
                    f"{self.map_frame}->{self.chassis_frame} 或 "
                    f"{self.map_frame}->{self.velocity_frame}: {ex}"
                )
            if self.is_calibration_timeout():
                self.finish_straight_calibration(timeout=True)
            return

        if self.is_calibration_timeout():
            traveled = 0.0
            if self.calibration_start_xy is not None:
                traveled = project_progress(
                    (current_x, current_y),
                    self.calibration_start_xy,
                    self.calibration_heading
                )
            self.finish_straight_calibration(timeout=True, traveled=traveled)
            return

        yaw_error = shortest_angular_distance(current_yaw, self.calibration_heading)
        if self.calibration_phase == 'approach':
            vx, vy, reached_entry = compute_local_approach_velocity(
                (current_x, current_y),
                current_yaw,
                self.calibration_entry_xy,
                self.straight_start_tolerance,
                self.straight_speed
            )
            if reached_entry:
                self.cmd_vel_pub.publish(Twist())
                self.calibration_phase = 'align'
                self.get_logger().info(
                    f"{self.calibration_pair[0]}->{self.calibration_pair[1]} 已补到起点容差内，"
                    "开始方向对准"
                )
                return

            cmd = Twist()
            cmd.linear.x = vx
            cmd.linear.y = vy
            published_cmd = self.publish_calibration_cmd(cmd, current_yaw, velocity_yaw)
            self.log_straight_orientation_debug(
                'approach', current_x, current_y, current_yaw, velocity_yaw, yaw_error,
                published_cmd
            )
            return

        if self.calibration_phase == 'align':
            if abs(yaw_error) <= self.straight_yaw_tolerance:
                self.calibration_phase = 'drive'
                self.calibration_start_xy = (current_x, current_y)
                if self.calibration_target_xy is not None:
                    self.calibration_length = max(
                        project_progress(
                            self.calibration_target_xy,
                            self.calibration_start_xy,
                            self.calibration_heading
                        ),
                        0.0
                    )
                self.get_logger().info(
                    f"{self.calibration_pair[0]}->{self.calibration_pair[1]} 对准完成，"
                    f"开始直线行驶 {self.calibration_length:.2f}m, "
                    f"起步位置 ({current_x:.3f}, {current_y:.3f}), "
                    f"航点线横向偏差 "
                    f"{cross_track_error((current_x, current_y), self.calibration_entry_xy, self.calibration_heading):.3f}m"
                )
                return

            cmd = Twist()
            cmd.angular.z = clamp(
                self.straight_turn_kp * yaw_error,
                -self.straight_max_turn_speed,
                self.straight_max_turn_speed
            )
            published_cmd = self.publish_calibration_cmd(cmd, current_yaw, velocity_yaw)
            self.log_straight_orientation_debug(
                'align', current_x, current_y, current_yaw, velocity_yaw, yaw_error,
                published_cmd
            )
            return

        if self.calibration_start_xy is None:
            self.calibration_start_xy = (current_x, current_y)

        traveled = project_progress(
            (current_x, current_y),
            self.calibration_start_xy,
            self.calibration_heading
        )
        remaining = self.calibration_length - traveled
        if remaining <= self.straight_stop_margin:
            self.finish_straight_calibration(traveled=traveled)
            return

        cmd = Twist()
        cmd.linear.x = self.straight_speed * self.calibration_drive_direction
        cmd.angular.z = clamp(
            self.straight_drive_yaw_kp * yaw_error,
            -self.straight_drive_turn_limit,
            self.straight_drive_turn_limit
        )
        published_cmd = self.publish_calibration_cmd(cmd, current_yaw, velocity_yaw)
        self.log_straight_drive_debug(
            current_x, current_y, current_yaw, velocity_yaw, yaw_error, traveled,
            remaining, published_cmd
        )

    def convert_chassis_cmd_to_velocity_frame(self, cmd, chassis_yaw, velocity_yaw):
        converted_cmd = Twist()
        converted_cmd.linear.x, converted_cmd.linear.y = transform_local_velocity_between_yaws(
            cmd.linear.x, cmd.linear.y, chassis_yaw, velocity_yaw
        )
        converted_cmd.linear.z = cmd.linear.z
        converted_cmd.angular.x = cmd.angular.x
        converted_cmd.angular.y = cmd.angular.y
        converted_cmd.angular.z = cmd.angular.z
        return converted_cmd

    def publish_calibration_cmd(self, cmd, chassis_yaw, velocity_yaw):
        converted_cmd = self.convert_chassis_cmd_to_velocity_frame(
            cmd, chassis_yaw, velocity_yaw
        )
        self.cmd_vel_pub.publish(converted_cmd)
        return converted_cmd

    def log_straight_orientation_debug(
        self, phase, current_x, current_y, current_yaw, velocity_yaw, yaw_error, cmd=None
    ):
        now = time.monotonic()
        if now - self.calibration_last_drive_log_time < 0.5:
            return
        self.calibration_last_drive_log_time = now

        pair_text = "?"
        if self.calibration_pair is not None:
            pair_text = f"{self.calibration_pair[0]}->{self.calibration_pair[1]}"

        cmd_text = ""
        if cmd is not None:
            cmd_text = (
                f", 发布cmd[{self.velocity_frame}] x {cmd.linear.x:.2f}, y {cmd.linear.y:.2f}, "
                f"z {cmd.angular.z:.2f}"
            )

        self.get_logger().info(
            f"直线校准姿态 [{pair_text}/{phase}]: "
            f"xy ({current_x:.3f}, {current_y:.3f}), "
            f"车体朝向 {math.degrees(current_yaw):.1f}deg, "
            f"规划路径角 {math.degrees(self.calibration_heading):.1f}deg, "
            f"车体角度差 {math.degrees(yaw_error):.1f}deg, "
            f"速度基准({self.velocity_frame})朝向 {math.degrees(velocity_yaw):.1f}deg, "
            f"速度基准角度差 "
            f"{math.degrees(shortest_angular_distance(velocity_yaw, self.calibration_heading)):.1f}deg"
            f"{cmd_text}"
        )

    def log_straight_drive_debug(
        self, current_x, current_y, current_yaw, velocity_yaw, yaw_error, traveled,
        remaining, cmd
    ):
        now = time.monotonic()
        if now - self.calibration_last_drive_log_time < 0.5:
            return
        self.calibration_last_drive_log_time = now

        waypoint_line_cross = 0.0
        start_line_cross = 0.0
        if self.calibration_entry_xy is not None:
            waypoint_line_cross = cross_track_error(
                (current_x, current_y), self.calibration_entry_xy, self.calibration_heading
            )
        if self.calibration_start_xy is not None:
            start_line_cross = cross_track_error(
                (current_x, current_y), self.calibration_start_xy, self.calibration_heading
            )

        target_x, target_y = (0.0, 0.0)
        if self.calibration_target_xy is not None:
            target_x, target_y = self.calibration_target_xy

        pair_text = "?"
        if self.calibration_pair is not None:
            pair_text = f"{self.calibration_pair[0]}->{self.calibration_pair[1]}"

        self.get_logger().info(
            f"直线行驶调试 [{pair_text}]: "
            f"xy ({current_x:.3f}, {current_y:.3f}), "
            f"目标 ({target_x:.3f}, {target_y:.3f}), "
            f"进度 {traveled:.2f}/{self.calibration_length:.2f}m, 剩余 {remaining:.2f}m, "
            f"航点线横偏 {waypoint_line_cross:.3f}m, 起步线横偏 {start_line_cross:.3f}m, "
            f"车体朝向 {math.degrees(current_yaw):.1f}deg, "
            f"规划路径角 {math.degrees(self.calibration_heading):.1f}deg, "
            f"车体角度差 {math.degrees(yaw_error):.1f}deg, "
            f"速度基准({self.velocity_frame})朝向 {math.degrees(velocity_yaw):.1f}deg, "
            f"速度基准角度差 "
            f"{math.degrees(shortest_angular_distance(velocity_yaw, self.calibration_heading)):.1f}deg, "
            f"发布cmd[{self.velocity_frame}] x {cmd.linear.x:.2f}, "
            f"y {cmd.linear.y:.2f}, z {cmd.angular.z:.2f}"
        )

    def is_calibration_timeout(self):
        if self.calibration_start_time is None:
            return False
        elapsed = (self.get_clock().now() - self.calibration_start_time).nanoseconds / 1e9
        timeout = self.calibration_length / self.straight_speed + self.straight_timeout_extra
        return elapsed > max(timeout, self.straight_timeout_extra)

    def finish_straight_calibration(self, timeout=False, traveled=0.0):
        """结束直线校准；成功则跳过目标点，超时则交回 Nav2 导航到目标点"""
        self.cmd_vel_pub.publish(Twist())
        self.calibrating = False

        next_idx = self.calibration_next_idx
        pair = self.calibration_pair
        self.calibration_phase = None
        self.calibration_heading = 0.0
        self.calibration_length = 0.0
        self.calibration_start_xy = None
        self.calibration_entry_xy = None
        self.calibration_target_xy = None
        self.calibration_start_time = None
        self.calibration_next_idx = None
        self.calibration_pair = None
        self.calibration_last_drive_log_time = 0.0

        if next_idx is None:
            self.sending = False
            return

        if timeout:
            self.current_idx = next_idx
            next_wp_name = self.waypoints[self.targets[self.current_idx]].get(
                'Name', f'Waypoint_{self.targets[self.current_idx]+1}'
            )
            self.get_logger().warn(
                f"{pair[0]}->{pair[1]} 直线校准超时，已前进 {traveled:.2f}m，"
                f"改由 Nav2 继续导航到: {next_wp_name}"
            )
        else:
            passed_idx = next_idx
            self.current_idx = (next_idx + 1) % len(self.targets)
            passed_wp_name = self.waypoints[self.targets[passed_idx]].get(
                'Name', f'Waypoint_{self.targets[passed_idx]+1}'
            )
            next_wp_name = self.waypoints[self.targets[self.current_idx]].get(
                'Name', f'Waypoint_{self.targets[self.current_idx]+1}'
            )
            self.get_logger().info(
                f"{pair[0]}->{pair[1]} 直线校准完成，已通过 {passed_wp_name}，"
                f"实际前进 {traveled:.2f}m，继续循环导航到: {next_wp_name}"
            )
        self.sending = False

    def route_result_callback(self, future):
        """处理整条路线执行结果"""
        result = future.result()
        status = result.status
        status_name = self.goal_status_name(status)

        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info('✓ 已按顺序通过整条路线中的所有目标点')
        else:
            self.get_logger().warn(f'✗ 整条路线导航失败，状态码: {status} ({status_name})')
            self.log_recent_nav_errors()

        self.sending = False
        self.retry_count = 0
        time.sleep(0.5)
        self.get_logger().info('准备重新发送整条路线')

    def navigation_loop(self):
        """循环导航定时器回调"""
        if not self.sending and not self.calibrating:
            if self.through_all_waypoints:
                self.send_route_goal()
            else:
                self.send_goal(self.targets[self.current_idx])


def main():
    parser = argparse.ArgumentParser(description='自动循环导航 - 从文件读取目标点并循环导航')
    parser.add_argument(
        '--yaml', 
        type=str, 
        default='waypoints.yaml', 
        help='航点 YAML 文件路径'
    )
    parser.add_argument(
        '--order',
        type=int,
        nargs='+',
        default=[1],
        help='循环点编号列表（从1开始）'
    )
    parser.add_argument(
        '--through-all-waypoints',
        action='store_true',
        help='忽略 --order，一次性读取 YAML 中全部航点并通过 NavigateThroughPoses 规划经过所有点'
    )
    parser.add_argument(
        '--straight-distance',
        type=float,
        default=5.0,
        help='兼容旧参数：非 0 启用 2->3 / 3->2 直线校准；实际距离由两点坐标自动计算'
    )
    parser.add_argument(
        '--straight-speed',
        type=float,
        default=0.5,
        help='2->3 / 3->2 之间直行校准速度，单位 m/s'
    )
    parser.add_argument(
        '--cmd-vel-topic',
        type=str,
        default='/red_standard_robot1/cmd_vel',
        help='直行校准时发布 Twist 的话题，默认发布到 fake_vel_transform 后的 /cmd_vel'
    )
    parser.add_argument(
        '--straight-yaw-tolerance',
        type=float,
        default=0.05,
        help='直线校准对准阶段的 yaw 容差，单位 rad'
    )
    parser.add_argument(
        '--straight-stop-margin',
        type=float,
        default=0.15,
        help='距离 2/3 目标点剩余多少米时认为直线段完成'
    )
    parser.add_argument(
        '--straight-turn-kp',
        type=float,
        default=1.8,
        help='直线校准对准阶段角速度比例系数'
    )
    parser.add_argument(
        '--straight-max-turn-speed',
        type=float,
        default=0.8,
        help='直线校准对准阶段最大角速度，单位 rad/s'
    )
    parser.add_argument(
        '--straight-drive-yaw-kp',
        type=float,
        default=1.2,
        help='直线校准直行阶段方向修正比例系数'
    )
    parser.add_argument(
        '--straight-drive-turn-limit',
        type=float,
        default=0.35,
        help='直线校准直行阶段最大修正角速度，单位 rad/s'
    )
    parser.add_argument(
        '--straight-timeout-extra',
        type=float,
        default=5.0,
        help='直线校准理论行驶时间之外的超时余量，单位 s'
    )
    parser.add_argument(
        '--map-frame',
        type=str,
        default='map',
        help='打印方向检查日志时使用的全局坐标系'
    )
    parser.add_argument(
        '--chassis-frame',
        type=str,
        default='chassis',
        help='打印方向检查日志时检查的底盘坐标系'
    )
    parser.add_argument(
        '--velocity-frame',
        type=str,
        default='gimbal_yaw',
        help='直线校准发布速度前要转换到的速度基准坐标系，默认匹配 /cmd_vel'
    )
    parser.add_argument(
        '--yaw-log-distance',
        type=float,
        default=0.15,
        help='距离目标点多少米内开始打印当前角度和目标角度差；设为 0 可关闭'
    )
    parser.add_argument(
        '--tf-topic',
        type=str,
        default='/red_standard_robot1/tf',
        help='方向检查日志使用的 TF 话题'
    )
    parser.add_argument(
        '--tf-static-topic',
        type=str,
        default='/red_standard_robot1/tf_static',
        help='方向检查日志使用的静态 TF 话题'
    )
    parser.add_argument(
        '--straight-path-topic',
        type=str,
        default='/red_standard_robot1/auto_nav_straight_path',
        help='RViz 显示 2-3 直线校准路径的 nav_msgs/Path 话题'
    )
    args = parser.parse_args()
    
    rclpy.init()
    node = None
    
    try:
        node = AutoNavNode(
            yaml_path=args.yaml,
            order=args.order,
            through_all_waypoints=args.through_all_waypoints,
            straight_distance=args.straight_distance,
            straight_speed=args.straight_speed,
            straight_yaw_tolerance=args.straight_yaw_tolerance,
            straight_stop_margin=args.straight_stop_margin,
            straight_turn_kp=args.straight_turn_kp,
            straight_max_turn_speed=args.straight_max_turn_speed,
            straight_drive_yaw_kp=args.straight_drive_yaw_kp,
            straight_drive_turn_limit=args.straight_drive_turn_limit,
            straight_timeout_extra=args.straight_timeout_extra,
            cmd_vel_topic=args.cmd_vel_topic,
            map_frame=args.map_frame,
            chassis_frame=args.chassis_frame,
            velocity_frame=args.velocity_frame,
            yaw_log_distance=args.yaw_log_distance,
            tf_topic=args.tf_topic,
            tf_static_topic=args.tf_static_topic,
            straight_path_topic=args.straight_path_topic
        )
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("\n节点已停止")
    except Exception as e:
        if rclpy.ok():
            print(f"错误: {e}")
    finally:
        if node is not None:
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
