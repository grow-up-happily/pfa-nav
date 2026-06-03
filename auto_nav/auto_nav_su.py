#!/usr/bin/env python3

# 自动循环导航 - 从文件读取目标点并自动循环导航
import rclpy
from rclpy.node import Node
from action_msgs.msg import GoalStatus
from collections import deque
from geometry_msgs.msg import PoseStamped, Twist
from nav_msgs.msg import Path
from visualization_msgs.msg import Marker, MarkerArray
from nav2_msgs.action import NavigateToPose, NavigateThroughPoses
from rcl_interfaces.msg import Log
from rclpy.action import ActionClient
from rclpy.duration import Duration
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile
from rclpy.time import Time
from std_msgs.msg import Float32, UInt8
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

STRAIGHT_WAYPOINT_IDS = (2, 3)
STRAIGHT_TRANSITIONS = {
    STRAIGHT_WAYPOINT_IDS,
    (STRAIGHT_WAYPOINT_IDS[1], STRAIGHT_WAYPOINT_IDS[0]),
}
BASE_BEGIN_ID = 5
BASE_END_ID = 6
CALIBRATION_MODE_STRAIGHT = 'straight'
CALIBRATION_MODE_BASE_FORWARD = 'base_forward'
CALIBRATION_MODE_BASE_CORRECTION = 'base_correction'
CALIBRATION_MODE_EXTRA_STRAIGHT = 'extra_straight'
EXTRA_STRAIGHT_WAYPOINT_IDS = (4, 5)
EXTRA_STRAIGHT_TRANSITIONS = {EXTRA_STRAIGHT_WAYPOINT_IDS}


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


def straight_waypoint_indices_for_transition(finished_id, next_id):
    if (finished_id, next_id) == STRAIGHT_WAYPOINT_IDS:
        return STRAIGHT_WAYPOINT_IDS[0] - 1, STRAIGHT_WAYPOINT_IDS[1] - 1
    if (finished_id, next_id) == (STRAIGHT_WAYPOINT_IDS[1], STRAIGHT_WAYPOINT_IDS[0]):
        return STRAIGHT_WAYPOINT_IDS[1] - 1, STRAIGHT_WAYPOINT_IDS[0] - 1
    raise ValueError(f"不是 2<->3 直线校准段: {finished_id}->{next_id}")


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
        enable_straight=False,
        enable_base=False,
        base_speed=1.5,
        base_wait_seconds=5.0,
        base_correction_speed=0.5,
        straight_distance=5.0,
        straight_speed=0.5,
        straight_yaw_tolerance=0.05,
        straight_stop_margin=0.15,
        straight_turn_kp=1.8,
        straight_max_turn_speed=0.8,
        straight_drive_yaw_kp=1.2,
        straight_drive_turn_limit=0.35,
        straight_timeout_extra=5.0,
        enable_extra_straight=False,
        extra_straight_wait_seconds=5.0,
        cmd_vel_topic='/cmd_vel',
        map_frame='map',
        chassis_frame='chassis',
        velocity_frame='gimbal_yaw',
        yaw_log_distance=0.15,
        tf_topic='/tf',
        tf_static_topic='/tf_static',
        straight_path_topic='/auto_nav_straight_path',
        waypoint_marker_topic='/waypoint_markers',
        angle_diff_topic='/angle_diff',
        judge_topic='/judge',
        judge_home_id=1,
        judge_remote_id=4,
    ):
        super().__init__('auto_nav_node')
        
        # 加载航点
        self.waypoints = self.load_waypoints(yaml_path)
        self.get_logger().info(f"已从 {yaml_path} 加载 {len(self.waypoints)} 个航点")
        
        self.through_all_waypoints = through_all_waypoints

        self.judge_topic = judge_topic
        self.judge_enabled = bool(judge_topic)
        self.judge_home_id = judge_home_id
        self.judge_remote_id = judge_remote_id
        self.judge_control_active = False
        self.judge_idle = False
        self.last_passed_waypoint_id = None

        if self.judge_enabled:
            required_ids = {
                self.judge_home_id,
                self.judge_remote_id,
                *STRAIGHT_WAYPOINT_IDS,
            }
            for waypoint_id in sorted(required_ids):
                if waypoint_id < 1 or waypoint_id > len(self.waypoints):
                    raise ValueError(
                        f"/judge 模式需要 YAML 包含航点 {waypoint_id}，"
                        f"当前只有 {len(self.waypoints)} 个航点"
                    )

        order_was_provided = order is not None
        if order is None:
            order = [self.judge_home_id if self.judge_enabled else 1]
            self.judge_control_active = self.judge_enabled
            self.judge_idle = self.judge_enabled

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

        self.last_passed_waypoint_id = self.targets[0] + 1
        if self.judge_enabled:
            self.judge_sub = self.create_subscription(
                UInt8, judge_topic, self.judge_callback, 10
            )
            self.get_logger().info(
                f"已订阅 {judge_topic}: data=0 -> 航点 {self.judge_home_id}, "
                f"data=1 -> 航点 {self.judge_remote_id}"
            )
            if not order_was_provided:
                self.get_logger().info("未指定 --order，等待 /judge 指令后开始导航")
        
        # 导航客户端
        self.nav_ac = ActionClient(self, NavigateToPose, '/navigate_to_pose')
        self.nav_through_poses_ac = ActionClient(
            self, NavigateThroughPoses, '/navigate_through_poses'
        )

        self.map_frame = map_frame
        self.chassis_frame = chassis_frame
        self.position_frame = 'gimbal_yaw_fake'
        self.velocity_frame = velocity_frame
        self.yaw_log_distance = abs(yaw_log_distance)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.tf_lookup_timeout = Duration(seconds=0.2)
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
        marker_qos = QoSProfile(
            depth=1,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            history=HistoryPolicy.KEEP_LAST,
        )
        self.waypoint_marker_pub = self.create_publisher(
            MarkerArray, waypoint_marker_topic, marker_qos
        )
        self.waypoint_marker_timer = self.create_timer(1.0, self.publish_waypoint_markers)
        self.get_logger().info(
            f"方向检查日志: XY 使用 TF {map_frame}->{self.position_frame}, "
            f"yaw 使用 TF {map_frame}->{chassis_frame}, "
            f"监听 {tf_topic}, {tf_static_topic}, 距离阈值 {self.yaw_log_distance:.2f}m"
        )

        # 固定使用 YAML 中的 Waypoint_2 和 Waypoint_3 做直行校准段。
        self.calibration_transitions = set(STRAIGHT_TRANSITIONS)
        self.straight_enabled = (
            (bool(enable_straight) or self.judge_enabled) and
            abs(straight_distance) > 0.0
        )
        self.straight_speed = abs(straight_speed)
        self.straight_yaw_tolerance = abs(straight_yaw_tolerance)
        self.straight_stop_margin = abs(straight_stop_margin)
        self.straight_turn_kp = abs(straight_turn_kp)
        self.straight_max_turn_speed = abs(straight_max_turn_speed)
        self.straight_drive_yaw_kp = abs(straight_drive_yaw_kp)
        self.straight_drive_turn_limit = abs(straight_drive_turn_limit)
        self.straight_timeout_extra = abs(straight_timeout_extra)
        self.straight_start_tolerance = 0.8
        self.base_enabled = bool(enable_base)
        self.base_begin_id = BASE_BEGIN_ID
        self.base_end_id = BASE_END_ID
        self.base_begin_idx = self.base_begin_id - 1
        self.base_end_idx = self.base_end_id - 1
        self.base_speed = abs(base_speed)
        self.base_wait_seconds = abs(base_wait_seconds)
        self.base_correction_speed = abs(base_correction_speed)
        if self.base_enabled:
            if self.base_end_idx >= len(self.waypoints):
                raise ValueError(
                    f"enable_base 需要 YAML 至少包含 {self.base_end_id} 个航点"
                )
            if self.base_speed < 1e-3:
                raise ValueError("base_speed 不能为 0")
            if self.base_correction_speed < 1e-3:
                raise ValueError("base_correction_speed 不能为 0")
        if self.straight_enabled:
            if abs(self.straight_speed) < 1e-3:
                raise ValueError("straight_speed 不能为 0")
        self.cmd_vel_pub = self.create_publisher(Twist, cmd_vel_topic, 10)
        self.get_logger().info(
            f"直线校准速度发布: 底盘控制量先转换到 {self.velocity_frame} 基准，"
            f"再发布到 {cmd_vel_topic}"
        )
        self.angle_diff_topic = angle_diff_topic
        self.angle_diff_pub = self.create_publisher(Float32, angle_diff_topic, 10)
        self.publish_angle_diff(0.0)
        self.get_logger().info(
            f"直线校准过程中会将车体与路径的 yaw 偏差(rad) 发布到 {angle_diff_topic}"
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
        self.calibration_mode = CALIBRATION_MODE_STRAIGHT
        self.calibration_speed = self.straight_speed
        self.calibration_stop_margin = self.straight_stop_margin
        self.base_waiting = False
        self.base_wait_until = None
        self.base_wait_next_idx = None
        self.extra_straight_enabled = bool(enable_extra_straight)
        self.extra_straight_wait_seconds = abs(extra_straight_wait_seconds)
        self.extra_straight_waiting = False
        self.extra_straight_wait_until = None
        self.extra_straight_wait_next_idx = None
        self.current_goal_handle = None
        self.goal_sequence = 0
        self.active_goal_sequence = None
        self.ignored_goal_sequences = set()
        self.judge_ignored_goal_sequences = set()
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
            self.get_logger().warn("整条路线模式不会插入 2->3 / 3->2 / base 的直行校准动作")
        elif self.straight_enabled:
            self.get_logger().info(
                "直行校准启用: 2->3 / 3->2 时先对准两点连线，再沿直线通过，"
                f"速度 {self.straight_speed:.2f}m/s"
            )
            self.publish_straight_path_by_waypoint_ids(*STRAIGHT_WAYPOINT_IDS)
        else:
            self.get_logger().info("直线校准关闭")
        if not self.through_all_waypoints and self.base_enabled:
            self.get_logger().info(
                f"base 逻辑启用: {self.base_begin_id}->{self.base_end_id} "
                f"到 {self.base_begin_id} 后对准并以 {self.base_speed:.2f}m/s 冲向 "
                f"{self.base_end_id}，静止 {self.base_wait_seconds:.1f}s 后修正回 "
                f"{self.base_end_id}"
            )
            self.publish_straight_path_by_waypoint_ids(self.base_begin_id, self.base_end_id)
        elif self.base_enabled:
            self.get_logger().warn("base 逻辑在整条路线模式下不会触发")
        if not self.through_all_waypoints and self.extra_straight_enabled:
            self.get_logger().info(
                f"额外直线段启用: {EXTRA_STRAIGHT_WAYPOINT_IDS[0]}->"
                f"{EXTRA_STRAIGHT_WAYPOINT_IDS[1]} 单向，完成后静止 "
                f"{self.extra_straight_wait_seconds:.1f}s 再继续 nav2"
            )
        elif self.extra_straight_enabled:
            self.get_logger().warn("额外直线段在整条路线模式下不会触发")

        # 循环导航状态
        self.current_idx = 0
        self.previous_idx_for_navigation = None
        self.sending = False
        self.max_retry = 3
        self.retry_count = 0

        # 启动导航循环定时器
        self.timer = self.create_timer(1.0, self.navigation_loop)
        self.straight_handoff_timer = self.create_timer(0.2, self.straight_handoff_loop)
        self.calibration_timer = self.create_timer(0.05, self.calibration_loop)
        self.base_wait_timer = self.create_timer(0.1, self.base_wait_loop)
        self.extra_straight_wait_timer = self.create_timer(0.1, self.extra_straight_wait_loop)
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

    def judge_callback(self, msg):
        """接收裁判指令：1 回 1 点，2 去 4 点。直行校准中忽略新指令。"""
        command = int(msg.data)
        if command == 0:
            target_id = self.judge_home_id
        elif command == 1:
            target_id = self.judge_remote_id
        else:
            self.get_logger().warn(f"忽略 /judge 未知值: {command}")
            return

        if self.through_all_waypoints:
            self.get_logger().warn("整条路线模式下忽略 /judge 指令")
            return
        if self.calibrating:
            self.get_logger().warn(
                f"直线校准中忽略 /judge={command}，当前直线段完成后继续原任务"
            )
            return

        current_id = self.current_route_start_id()
        route_ids = self.build_judge_route(current_id, target_id)
        if not route_ids:
            return

        self.activate_judge_route(route_ids, command)

    def current_route_start_id(self):
        if self.last_passed_waypoint_id is not None:
            return self.last_passed_waypoint_id
        if self.targets and 0 <= self.current_idx < len(self.targets):
            return self.targets[self.current_idx] + 1
        return self.judge_home_id

    def build_judge_route(self, current_id, target_id):
        if target_id == self.judge_remote_id:
            if current_id <= self.judge_remote_id:
                route_ids = list(range(current_id, self.judge_remote_id + 1))
            else:
                route_ids = [current_id, self.judge_remote_id]
        elif target_id == self.judge_home_id:
            if current_id >= self.judge_home_id:
                route_ids = list(range(current_id, self.judge_home_id - 1, -1))
            else:
                route_ids = [current_id, self.judge_home_id]
        else:
            route_ids = [current_id, target_id]

        for waypoint_id in route_ids:
            if waypoint_id < 1 or waypoint_id > len(self.waypoints):
                self.get_logger().error(
                    f"/judge 路线包含无效航点 {waypoint_id}，"
                    f"有效范围 [1-{len(self.waypoints)}]"
                )
                return []
        return route_ids

    def activate_judge_route(self, route_ids, command):
        self.cancel_current_goal_for_judge()
        self.targets = [waypoint_id - 1 for waypoint_id in route_ids]
        self.judge_control_active = True
        self.retry_count = 0
        self.last_passed_waypoint_id = route_ids[0]
        self.previous_idx_for_navigation = None

        if len(route_ids) == 1:
            self.current_idx = 0
            self.judge_idle = False
            self.sending = False
            self.get_logger().info(
                f"/judge={command}: 已在目标航点 {route_ids[0]}，继续发布该目标"
            )
            return

        self.current_idx = 1
        self.previous_idx_for_navigation = 0
        self.judge_idle = False
        self.sending = False
        self.get_logger().info(
            f"/judge={command}: 切换路线 {' -> '.join(map(str, route_ids))}"
        )

    def cancel_current_goal_for_judge(self):
        old_sequence = self.active_goal_sequence
        if old_sequence is not None:
            self.judge_ignored_goal_sequences.add(old_sequence)
            self.active_goal_sequence = None

        goal_handle = self.current_goal_handle
        self.current_goal_handle = None
        if goal_handle is None:
            return

        cancel_future = goal_handle.cancel_goal_async()
        cancel_future.add_done_callback(self.judge_cancel_callback)

    def judge_cancel_callback(self, future):
        try:
            cancel_response = future.result()
            cancel_count = len(cancel_response.goals_canceling)
            if cancel_count > 0:
                self.get_logger().info("/judge 已取消当前 Nav2 goal")
            else:
                self.get_logger().info("/judge 切换时当前 Nav2 goal 无需取消")
        except Exception as ex:
            self.get_logger().warn(f"/judge 取消当前 Nav2 goal 失败: {ex}")

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
            self.map_frame, frame, Time(), timeout=self.tf_lookup_timeout
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
        except TransformException:
            # 方向检查只是辅助日志；TF 刚启动时可能短暂不可查，不影响导航。
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
        """禁用提前取消 Nav2；直线校准只在 Nav2 返回成功后触发。"""
        return

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

    def publish_waypoint_markers(self):
        """将所有航点发布为 MarkerArray，供 RViz 显示点位和标签。"""
        mk_array = MarkerArray()
        now = self.get_clock().now().to_msg()
        target_indices = set(self.targets)
        straight_indices = {
            idx - 1 for idx in STRAIGHT_WAYPOINT_IDS
            if 0 < idx <= len(self.waypoints)
        }
        base_indices = set()
        if self.base_enabled:
            base_indices = {
                idx - 1 for idx in (self.base_begin_id, self.base_end_id)
                if 0 < idx <= len(self.waypoints)
            }

        for i, wp in enumerate(self.waypoints):
            if i in base_indices:
                role, color = 'BASE', (1.0, 0.2, 0.0)
            elif i in straight_indices:
                role, color = 'STRAIGHT', (0.0, 0.4, 1.0)
            elif i in target_indices:
                role, color = 'TARGET', (0.0, 1.0, 0.0)
            else:
                role, color = 'WAYPOINT', (0.8, 0.8, 0.8)

            mk = Marker()
            mk.header.frame_id = self.map_frame
            mk.header.stamp = now
            mk.ns = 'waypoints'
            mk.id = i
            mk.type = Marker.SPHERE
            mk.action = Marker.ADD
            mk.pose.position.x = float(wp['Pos_x'])
            mk.pose.position.y = float(wp['Pos_y'])
            mk.pose.position.z = float(wp['Pos_z'])
            mk.pose.orientation.x = float(wp['Ori_x'])
            mk.pose.orientation.y = float(wp['Ori_y'])
            mk.pose.orientation.z = float(wp['Ori_z'])
            mk.pose.orientation.w = float(wp['Ori_w'])
            mk.scale.x = 0.15
            mk.scale.y = 0.15
            mk.scale.z = 0.15
            mk.color.r = color[0]
            mk.color.g = color[1]
            mk.color.b = color[2]
            mk.color.a = 1.0
            mk_array.markers.append(mk)

            text = Marker()
            text.header.frame_id = self.map_frame
            text.header.stamp = now
            text.ns = 'labels'
            text.id = i
            text.type = Marker.TEXT_VIEW_FACING
            text.action = Marker.ADD
            text.pose.position.x = float(wp['Pos_x'])
            text.pose.position.y = float(wp['Pos_y'])
            text.pose.position.z = float(wp['Pos_z']) + 0.25
            text.scale.z = 0.2
            text.color.r = 1.0
            text.color.g = 1.0
            text.color.b = 1.0
            text.color.a = 1.0
            text.text = f'{i + 1}: {wp.get("Name", "")} [{role}]'
            mk_array.markers.append(text)

        self.waypoint_marker_pub.publish(mk_array)

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

        if goal_sequence in self.judge_ignored_goal_sequences:
            self.judge_ignored_goal_sequences.discard(goal_sequence)
            self.get_logger().info(f"忽略 /judge 切换前的 Nav2 结果: {status_name}")
            return

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
            reached_id = self.targets[self.current_idx] + 1
            self.last_passed_waypoint_id = reached_id
            if self.judge_control_active and self.current_idx >= len(self.targets) - 1:
                self.get_logger().info(
                    f"/judge 路线已到达航点 {reached_id}，继续发布该目标"
                )
                self.sending = False
                self.retry_count = 0
                self.judge_idle = False
                return
            # 单目标点模式：到达后结束
            if not self.judge_control_active and len(self.targets) == 1:
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
        next_idx = (
            self.current_idx + 1 if self.judge_control_active
            else (self.current_idx + 1) % len(self.targets)
        )
        if status == GoalStatus.STATUS_SUCCEEDED and self.should_run_base_calibration(
            finished_idx, next_idx
        ):
            self.previous_idx_for_navigation = None
            self.start_base_forward(next_idx)
            return
        if status == GoalStatus.STATUS_SUCCEEDED and self.should_run_straight_calibration(
            finished_idx, next_idx
        ):
            self.previous_idx_for_navigation = None
            self.start_straight_calibration(next_idx)
            return
        if status == GoalStatus.STATUS_SUCCEEDED and self.should_run_extra_straight_calibration(
            finished_idx, next_idx
        ):
            self.previous_idx_for_navigation = None
            self.start_extra_straight_calibration(next_idx)
            return

        self.sending = False
        self.previous_idx_for_navigation = finished_idx
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

    def should_run_base_calibration(self, finished_idx, next_idx):
        """判断当前点到下一个点之间是否需要插入 base 直行逻辑。"""
        if self.through_all_waypoints or not self.base_enabled:
            return False
        finished_id = self.targets[finished_idx] + 1
        return finished_id == self.base_begin_id

    def start_base_forward(self, next_idx):
        """从 base_begin 高速直行到 base_end。"""
        resume_idx = next_idx
        if self.targets[next_idx] + 1 == self.base_end_id:
            resume_idx = (next_idx + 1) % len(self.targets)
        return self.start_straight_calibration(
            resume_idx,
            mode=CALIBRATION_MODE_BASE_FORWARD,
            from_waypoint_idx=self.base_begin_idx,
            to_waypoint_idx=self.base_end_idx,
            speed=self.base_speed,
            stop_margin=self.straight_stop_margin,
            pair=(self.base_begin_id, self.base_end_id),
            fallback_idx=next_idx,
        )

    def start_straight_calibration(
        self,
        next_idx,
        mode=CALIBRATION_MODE_STRAIGHT,
        from_waypoint_idx=None,
        to_waypoint_idx=None,
        speed=None,
        stop_margin=None,
        pair=None,
        fallback_idx=None,
    ):
        """开始直线校准，完成后把 next_idx 视为已通过。"""
        finished_id = self.targets[self.current_idx] + 1
        next_id = self.targets[next_idx] + 1
        display_pair = pair if pair is not None else (finished_id, next_id)

        try:
            if from_waypoint_idx is None or to_waypoint_idx is None:
                from_waypoint_idx, to_waypoint_idx = straight_waypoint_indices_for_transition(
                    finished_id, next_id
                )
            heading, nominal_length, drive_direction = compute_straight_segment_plan(
                self.waypoints, from_waypoint_idx, to_waypoint_idx
            )
            current_x, current_y, current_yaw, velocity_yaw = self.lookup_calibration_pose()
        except (ValueError, TransformException) as ex:
            self.get_logger().warn(
                f"无法开始 {display_pair[0]}->{display_pair[1]} 直线校准，"
                f"改用 Nav2 导航到当前路线目标点: {ex}"
            )
            self.sending = False
            self.current_idx = fallback_idx if fallback_idx is not None else next_idx
            return False

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
        self.calibration_pair = display_pair
        self.calibration_last_drive_log_time = 0.0
        self.calibration_mode = mode
        self.calibration_speed = abs(speed) if speed is not None else self.straight_speed
        self.calibration_stop_margin = (
            abs(stop_margin) if stop_margin is not None else self.straight_stop_margin
        )
        self.publish_straight_path(from_waypoint_idx, to_waypoint_idx)
        self.get_logger().info(
            f"开始 {display_pair[0]}->{display_pair[1]} 直线校准: 连线方向 {heading:.3f}rad, "
            f"路径角 {math.degrees(heading):.1f}deg, "
            f"车体朝向 {math.degrees(current_yaw):.1f}deg, "
            f"车体角度差 {math.degrees(initial_yaw_error):.1f}deg, "
            f"速度基准({self.velocity_frame})朝向 {math.degrees(velocity_yaw):.1f}deg, "
            f"速度基准角度差 {math.degrees(initial_velocity_yaw_error):.1f}deg, "
            f"速度方向 {drive_direction:+.0f}, 航点距离 {nominal_length:.2f}m, "
            f"当前需前进 {self.calibration_length:.2f}m, "
            f"执行速度 {self.calibration_speed:.2f}m/s, "
            f"当前位置 ({current_x:.3f}, {current_y:.3f}), "
            f"起点沿线偏移 {entry_along_offset:.3f}m, 起点横向偏差 {entry_cross_offset:.3f}m"
        )
        if self.calibration_phase == 'approach':
            self.get_logger().warn(
                f"Nav2 已返回到达 {finished_id}，但 {self.position_frame} 距该点还有 "
                f"{entry_distance:.3f}m > {self.straight_start_tolerance:.3f}m，"
                "先平移补到点内，再做方向对准"
            )
        return True

    def calibration_loop(self):
        """直线段定时器：先对准连线，再沿连线正向通过"""
        if not self.calibrating:
            self.publish_angle_diff(0.0)
            return

        try:
            current_x, current_y, current_yaw, velocity_yaw = self.lookup_calibration_pose()
        except TransformException as ex:
            self.cmd_vel_pub.publish(Twist())
            self.publish_angle_diff(0.0)
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
        self.publish_angle_diff(yaw_error)
        if self.calibration_phase == 'approach':
            vx, vy, reached_entry = compute_local_approach_velocity(
                (current_x, current_y),
                current_yaw,
                self.calibration_entry_xy,
                self.straight_start_tolerance,
                self.calibration_speed
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

        # Drive 阶段第二道 yaw 闸：偏差过大时停车回退 align 重新对准（停→对→走）
        drive_yaw_gate = max(self.straight_yaw_tolerance * 3.0, 0.15)
        if abs(yaw_error) > drive_yaw_gate:
            traveled_so_far = project_progress(
                (current_x, current_y),
                self.calibration_start_xy,
                self.calibration_heading
            ) if self.calibration_start_xy is not None else 0.0
            self.calibration_phase = 'align'
            self.calibration_start_xy = None
            self.cmd_vel_pub.publish(Twist())
            self.get_logger().warn(
                f"[YAW-GATE] drive→align 回退触发: "
                f"yaw_error {math.degrees(yaw_error):.1f}deg > "
                f"gate {math.degrees(drive_yaw_gate):.1f}deg, "
                f"xy ({current_x:.3f}, {current_y:.3f}), "
                f"已前进 {traveled_so_far:.2f}m, "
                f"车体朝向 {math.degrees(current_yaw):.1f}deg, "
                f"目标朝向 {math.degrees(self.calibration_heading):.1f}deg"
            )
            return

        traveled = project_progress(
            (current_x, current_y),
            self.calibration_start_xy,
            self.calibration_heading
        )
        remaining = self.calibration_length - traveled
        if remaining <= self.calibration_stop_margin:
            self.finish_straight_calibration(traveled=traveled)
            return

        cmd = Twist()
        cmd.linear.x = self.calibration_speed * self.calibration_drive_direction
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

    def publish_angle_diff(self, value):
        msg = Float32()
        msg.data = float(value)
        self.angle_diff_pub.publish(msg)

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
        # 超时检查已禁用：直线校准持续运行直到到达目标或被回退
        return False

    def finish_straight_calibration(self, timeout=False, traveled=0.0):
        """结束直线校准；成功则跳过目标点，超时则交回 Nav2 导航到目标点"""
        self.cmd_vel_pub.publish(Twist())
        self.publish_angle_diff(0.0)
        self.calibrating = False

        next_idx = self.calibration_next_idx
        pair = self.calibration_pair
        mode = self.calibration_mode
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
        self.calibration_mode = CALIBRATION_MODE_STRAIGHT
        self.calibration_speed = self.straight_speed
        self.calibration_stop_margin = self.straight_stop_margin

        if next_idx is None:
            self.sending = False
            return

        if mode == CALIBRATION_MODE_BASE_FORWARD and not timeout:
            self.start_base_wait(next_idx, traveled)
            return

        if mode == CALIBRATION_MODE_BASE_CORRECTION:
            self.finish_base_correction(next_idx, timeout, traveled)
            return

        if mode == CALIBRATION_MODE_EXTRA_STRAIGHT and not timeout:
            self.start_extra_straight_wait(next_idx, traveled)
            return

        if timeout:
            self.current_idx = next_idx
            self.previous_idx_for_navigation = None
            next_wp_name = self.waypoints[self.targets[self.current_idx]].get(
                'Name', f'Waypoint_{self.targets[self.current_idx]+1}'
            )
            self.get_logger().warn(
                f"{pair[0]}->{pair[1]} 直线校准超时，已前进 {traveled:.2f}m，"
                f"改由 Nav2 继续导航到: {next_wp_name}"
            )
        else:
            passed_idx = next_idx
            passed_id = self.targets[passed_idx] + 1
            self.last_passed_waypoint_id = passed_id
            self.previous_idx_for_navigation = passed_idx
            passed_wp_name = self.waypoints[self.targets[passed_idx]].get(
                'Name', f'Waypoint_{self.targets[passed_idx]+1}'
            )
            if self.judge_control_active and passed_idx >= len(self.targets) - 1:
                self.current_idx = passed_idx
                self.judge_idle = False
                self.get_logger().info(
                    f"{pair[0]}->{pair[1]} 直线校准完成，已到达 /judge 目标 "
                    f"{passed_wp_name}，实际前进 {traveled:.2f}m，继续发布该目标"
                )
                self.sending = False
                return

            self.current_idx = (
                next_idx + 1 if self.judge_control_active
                else (next_idx + 1) % len(self.targets)
            )
            next_wp_name = self.waypoints[self.targets[self.current_idx]].get(
                'Name', f'Waypoint_{self.targets[self.current_idx]+1}'
            )
            continue_text = (
                "继续 /judge 路线到" if self.judge_control_active
                else "继续循环导航到"
            )
            self.get_logger().info(
                f"{pair[0]}->{pair[1]} 直线校准完成，已通过 {passed_wp_name}，"
                f"实际前进 {traveled:.2f}m，{continue_text}: {next_wp_name}"
            )
        self.sending = False

    def start_base_wait(self, next_idx, traveled):
        """base 高速前进完成后，在 base_end 附近静止等待。"""
        self.base_waiting = True
        self.base_wait_until = time.monotonic() + self.base_wait_seconds
        self.base_wait_next_idx = next_idx
        self.sending = False
        self.previous_idx_for_navigation = None
        self.get_logger().info(
            f"{self.base_begin_id}->{self.base_end_id} base 高速前进完成，"
            f"实际前进 {traveled:.2f}m，静止 {self.base_wait_seconds:.1f}s 后修正回 "
            f"{self.base_end_id}"
        )

    def base_wait_loop(self):
        """base 高速段完成后的静止等待。"""
        if not self.base_waiting:
            return
        self.cmd_vel_pub.publish(Twist())
        self.publish_angle_diff(0.0)
        if self.base_wait_until is not None and time.monotonic() < self.base_wait_until:
            return

        next_idx = self.base_wait_next_idx
        self.base_waiting = False
        self.base_wait_until = None
        self.base_wait_next_idx = None
        if next_idx is None:
            self.sending = False
            return
        if not self.start_base_end_correction(next_idx):
            self.current_idx = next_idx
            self.previous_idx_for_navigation = None
            self.sending = False

    def should_run_extra_straight_calibration(self, finished_idx, next_idx):
        """判断当前点到下一个点之间是否需要插入额外直线段（4->5 单向）。"""
        if self.through_all_waypoints or not self.extra_straight_enabled:
            return False
        finished_id = self.targets[finished_idx] + 1
        next_id = self.targets[next_idx] + 1
        return (finished_id, next_id) in EXTRA_STRAIGHT_TRANSITIONS

    def start_extra_straight_calibration(self, next_idx):
        """复用 start_straight_calibration 跑 4->5 单向直线段。

        next_idx 是 EXTRA 段终点（5）在 targets 中的位置；校准完成后跳过该点直接去
        order 中的下一个点（与 STRAIGHT/BASE 完成行为一致），避免 nav2 重走 5。
        """
        resume_idx = (next_idx + 1) % len(self.targets)
        return self.start_straight_calibration(
            resume_idx,
            mode=CALIBRATION_MODE_EXTRA_STRAIGHT,
            from_waypoint_idx=EXTRA_STRAIGHT_WAYPOINT_IDS[0] - 1,
            to_waypoint_idx=EXTRA_STRAIGHT_WAYPOINT_IDS[1] - 1,
            speed=self.straight_speed,
            stop_margin=self.straight_stop_margin,
            pair=EXTRA_STRAIGHT_WAYPOINT_IDS,
            fallback_idx=next_idx,
        )

    def start_extra_straight_wait(self, next_idx, traveled):
        """额外直线段到达终点后，进入静止等待阶段（不修正回退）。"""
        self.extra_straight_waiting = True
        self.extra_straight_wait_until = time.monotonic() + self.extra_straight_wait_seconds
        self.extra_straight_wait_next_idx = next_idx
        self.sending = False
        self.previous_idx_for_navigation = None
        self.get_logger().info(
            f"{EXTRA_STRAIGHT_WAYPOINT_IDS[0]}->{EXTRA_STRAIGHT_WAYPOINT_IDS[1]} "
            f"额外直线段完成，实际前进 {traveled:.2f}m，"
            f"静止 {self.extra_straight_wait_seconds:.1f}s 后继续 nav2 导航"
        )

    def extra_straight_wait_loop(self):
        """额外直线段完成后的静止等待，等到时间后由 navigation_loop 接管。"""
        if not self.extra_straight_waiting:
            return
        self.cmd_vel_pub.publish(Twist())
        self.publish_angle_diff(0.0)
        if (
            self.extra_straight_wait_until is not None
            and time.monotonic() < self.extra_straight_wait_until
        ):
            return

        next_idx = self.extra_straight_wait_next_idx
        self.extra_straight_waiting = False
        self.extra_straight_wait_until = None
        self.extra_straight_wait_next_idx = None
        if next_idx is None:
            self.sending = False
            return
        self.current_idx = next_idx
        self.previous_idx_for_navigation = None
        self.sending = False
        next_wp_name = self.waypoints[self.targets[self.current_idx]].get(
            'Name', f'Waypoint_{self.targets[self.current_idx]+1}'
        )
        self.get_logger().info(
            f"额外直线段静止结束，继续 nav2 导航到: {next_wp_name}"
        )

    def start_base_end_correction(self, next_idx):
        """等待后沿 base_begin/base_end 航点连线修正回 base_end。"""
        try:
            line_heading, _, _ = compute_straight_segment_plan(
                self.waypoints, self.base_begin_idx, self.base_end_idx
            )
            current_x, current_y, current_yaw, velocity_yaw = self.lookup_calibration_pose()
        except (ValueError, TransformException) as ex:
            self.get_logger().warn(
                f"无法开始 base 回到 {self.base_end_id} 的直行修正，"
                f"改由 Nav2 导航到该点: {ex}"
            )
            return False

        target_wp = self.waypoints[self.base_end_idx]
        begin_wp = self.waypoints[self.base_begin_idx]
        current_xy = (current_x, current_y)
        target_xy = (float(target_wp['Pos_x']), float(target_wp['Pos_y']))
        begin_xy = (float(begin_wp['Pos_x']), float(begin_wp['Pos_y']))
        signed_remaining = project_progress(target_xy, current_xy, line_heading)
        correction_length = abs(signed_remaining)
        if correction_length <= min(self.straight_stop_margin, 0.05):
            self.get_logger().info(
                f"base 已在 {self.base_end_id} 附近，距离修正量 "
                f"{correction_length:.2f}m，继续导航"
            )
            self.finish_base_correction(next_idx, timeout=False, traveled=0.0)
            return True

        heading = line_heading if signed_remaining >= 0.0 else line_heading + math.pi
        heading = math.atan2(math.sin(heading), math.cos(heading))
        yaw_error = shortest_angular_distance(current_yaw, heading)
        velocity_yaw_error = shortest_angular_distance(velocity_yaw, heading)

        self.sending = False
        self.calibrating = True
        self.calibration_phase = 'align'
        self.calibration_heading = heading
        self.calibration_drive_direction = 1.0
        self.calibration_length = correction_length
        self.calibration_start_xy = None
        self.calibration_entry_xy = begin_xy
        self.calibration_target_xy = target_xy
        self.calibration_start_time = self.get_clock().now()
        self.calibration_next_idx = next_idx
        self.calibration_pair = (self.base_end_id, self.base_end_id)
        self.calibration_last_drive_log_time = 0.0
        self.calibration_mode = CALIBRATION_MODE_BASE_CORRECTION
        self.calibration_speed = self.base_correction_speed
        self.calibration_stop_margin = min(self.straight_stop_margin, 0.05)
        self.publish_straight_path(self.base_begin_idx, self.base_end_idx)
        self.get_logger().info(
            f"开始 base 回到 {self.base_end_id} 直行修正: "
            f"修正距离 {correction_length:.2f}m, 路径角 {math.degrees(heading):.1f}deg, "
            f"车体角度差 {math.degrees(yaw_error):.1f}deg, "
            f"速度基准角度差 {math.degrees(velocity_yaw_error):.1f}deg, "
            f"速度 {self.base_correction_speed:.2f}m/s"
        )
        return True

    def finish_base_correction(self, next_idx, timeout=False, traveled=0.0):
        """base 修正到 base_end 后，回到 base 前原路线的后续目标。"""
        if timeout:
            self.current_idx = next_idx
            self.previous_idx_for_navigation = None
            next_wp_name = self.waypoints[self.targets[self.current_idx]].get(
                'Name', f'Waypoint_{self.targets[self.current_idx]+1}'
            )
            self.get_logger().warn(
                f"base 回到 {self.base_end_id} 直行修正超时，已前进 {traveled:.2f}m，"
                f"改由 Nav2 继续导航到: {next_wp_name}"
            )
        else:
            self.current_idx = next_idx
            self.previous_idx_for_navigation = None
            next_wp_name = self.waypoints[self.targets[self.current_idx]].get(
                'Name', f'Waypoint_{self.targets[self.current_idx]+1}'
            )
            self.get_logger().info(
                f"base 已修正到 {self.base_end_id}，已通过该点，"
                f"实际前进 {traveled:.2f}m，继续循环导航到: {next_wp_name}"
            )
        self.sending = False

    def maybe_start_straight_before_nav(self):
        """发 Nav2 goal 前检查上一段是否应直接走 2<->3 直线校准。"""
        if self.previous_idx_for_navigation is None:
            return False
        if not self.should_run_straight_calibration(
            self.previous_idx_for_navigation, self.current_idx
        ):
            return False

        from_idx = self.previous_idx_for_navigation
        to_idx = self.current_idx
        from_id = self.targets[from_idx] + 1
        to_id = self.targets[to_idx] + 1
        self.get_logger().info(
            f"导航前检查命中 {from_id}->{to_id}，直接进入直线校准，不发送 Nav2 goal"
        )
        self.previous_idx_for_navigation = None
        self.current_idx = from_idx
        return self.start_straight_calibration(to_idx)

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
        if not self.sending and not self.calibrating and not self.base_waiting and not self.extra_straight_waiting:
            if self.judge_control_active:
                if self.judge_idle:
                    return
                if self.current_idx >= len(self.targets):
                    self.get_logger().warn("/judge 路线索引越界，停止并等待下一条指令")
                    self.judge_idle = True
                    return
            if self.through_all_waypoints:
                self.send_route_goal()
            else:
                if self.maybe_start_straight_before_nav():
                    return
                self.send_goal(self.targets[self.current_idx])


def main():
    parser = argparse.ArgumentParser(description='自动循环导航 - 从文件读取目标点并循环导航')
    waypoint_file_group = parser.add_mutually_exclusive_group()
    waypoint_file_group.add_argument(
        '--yaml',
        type=str,
        default='waypoints.yaml',
        help='航点 YAML 文件路径'
    )
    waypoint_file_group.add_argument(
        '--red',
        action='store_const',
        dest='yaml',
        const='waypoints_red.yaml',
        help='读取 waypoints_red.yaml'
    )
    waypoint_file_group.add_argument(
        '--blue',
        action='store_const',
        dest='yaml',
        const='waypoints_blue.yaml',
        help='读取 waypoints_blue.yaml'
    )
    parser.add_argument(
        '--order',
        type=int,
        nargs='+',
        default=None,
        help='循环点编号列表（从1开始）；未指定时等待 /judge 指令'
    )
    parser.add_argument(
        '--through-all-waypoints',
        action='store_true',
        help='忽略 --order，一次性读取 YAML 中全部航点并通过 NavigateThroughPoses 规划经过所有点'
    )
    parser.add_argument(
        '--enable-straight',
        action='store_true',
        help='启用 2->3 / 3->2 直线校准；默认关闭'
    )
    parser.add_argument(
        '--enable-base',
        action='store_true',
        help='启用 base 逻辑：5->6 高速直行，静止 5 秒后修正回 6；默认关闭'
    )
    parser.add_argument(
        '--enable-extra-straight',
        action='store_true',
        help='启用 4->5 单向额外直线段（停→对→走），到达 5 后静止 N 秒再交回 nav2；默认关闭'
    )
    parser.add_argument(
        '--extra-straight-wait-seconds',
        type=float,
        default=5.0,
        help='额外直线段到达 5 后的静止等待时间，单位 s'
    )
    parser.add_argument(
        '--base-speed',
        type=float,
        default=1.5,
        help='base 5->6 高速直行速度，单位 m/s'
    )
    parser.add_argument(
        '--base-wait-seconds',
        type=float,
        default=5.0,
        help='base 到达 6 附近后的静止等待时间，单位 s'
    )
    parser.add_argument(
        '--base-correction-speed',
        type=float,
        default=0.5,
        help='base 等待后修正回 6 点的直行速度，单位 m/s'
    )
    parser.add_argument(
        '--straight-distance',
        type=float,
        default=5.0,
        help='兼容旧参数：配合 --enable-straight 使用；设为 0 可强制关闭直线校准'
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
        default='/cmd_vel',
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
        default='/tf',
        help='方向检查日志使用的 TF 话题'
    )
    parser.add_argument(
        '--tf-static-topic',
        type=str,
        default='/tf_static',
        help='方向检查日志使用的静态 TF 话题'
    )
    parser.add_argument(
        '--straight-path-topic',
        type=str,
        default='/auto_nav_straight_path',
        help='RViz 显示 2-3 直线校准路径的 nav_msgs/Path 话题'
    )
    parser.add_argument(
        '--waypoint-marker-topic',
        type=str,
        default='/waypoint_markers',
        help='RViz 显示所有航点的 visualization_msgs/MarkerArray 话题'
    )
    parser.add_argument(
        '--angle-diff-topic',
        type=str,
        default='/angle_diff',
        help='直线校准时发布 yaw 偏差(rad)的 std_msgs/Float32 话题；未校准时发布 0.0'
    )
    parser.add_argument(
        '--judge-topic',
        type=str,
        default='/judge',
        help='接收裁判指令的 std_msgs/msg/UInt8 话题；空字符串可关闭'
    )
    parser.add_argument(
        '--judge-home-id',
        type=int,
        default=1,
        help='/judge=0 时回到的航点编号'
    )
    parser.add_argument(
        '--judge-remote-id',
        type=int,
        default=4,
        help='/judge=1 时前往的航点编号'
    )
    args = parser.parse_args()
    
    rclpy.init()
    node = None
    
    try:
        node = AutoNavNode(
            yaml_path=args.yaml,
            order=args.order,
            through_all_waypoints=args.through_all_waypoints,
            enable_straight=args.enable_straight,
            enable_base=args.enable_base,
            base_speed=args.base_speed,
            base_wait_seconds=args.base_wait_seconds,
            base_correction_speed=args.base_correction_speed,
            straight_distance=args.straight_distance,
            straight_speed=args.straight_speed,
            straight_yaw_tolerance=args.straight_yaw_tolerance,
            straight_stop_margin=args.straight_stop_margin,
            straight_turn_kp=args.straight_turn_kp,
            straight_max_turn_speed=args.straight_max_turn_speed,
            straight_drive_yaw_kp=args.straight_drive_yaw_kp,
            straight_drive_turn_limit=args.straight_drive_turn_limit,
            straight_timeout_extra=args.straight_timeout_extra,
            enable_extra_straight=args.enable_extra_straight,
            extra_straight_wait_seconds=args.extra_straight_wait_seconds,
            cmd_vel_topic=args.cmd_vel_topic,
            map_frame=args.map_frame,
            chassis_frame=args.chassis_frame,
            velocity_frame=args.velocity_frame,
            yaw_log_distance=args.yaw_log_distance,
            tf_topic=args.tf_topic,
            tf_static_topic=args.tf_static_topic,
            straight_path_topic=args.straight_path_topic,
            waypoint_marker_topic=args.waypoint_marker_topic,
            angle_diff_topic=args.angle_diff_topic,
            judge_topic=args.judge_topic,
            judge_home_id=args.judge_home_id,
            judge_remote_id=args.judge_remote_id
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
