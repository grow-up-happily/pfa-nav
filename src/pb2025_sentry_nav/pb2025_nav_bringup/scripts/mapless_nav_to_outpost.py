#!/usr/bin/env python3

import argparse
import math
import sys
import time
from pathlib import Path

import rclpy
import yaml
from action_msgs.msg import GoalStatus
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from nav2_msgs.action import NavigateThroughPoses
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.utilities import remove_ros_args


DEFAULT_ORDER = [1, 2, 3, 4]
STATUS_NAMES = {
    GoalStatus.STATUS_SUCCEEDED: "SUCCEEDED",
    GoalStatus.STATUS_ABORTED: "ABORTED",
    GoalStatus.STATUS_CANCELED: "CANCELED",
}


def default_waypoint_file():
    share = get_package_share_directory("pb2025_nav_bringup")
    return Path(share) / "config" / "reality" / "mapless_outpost_route.yaml"


def positive_float(value):
    number = float(value)
    if not math.isfinite(number) or number <= 0.0:
        raise argparse.ArgumentTypeError(
            "value must be a finite number greater than zero"
        )
    return number


def nonnegative_float(value):
    number = float(value)
    if not math.isfinite(number) or number < 0.0:
        raise argparse.ArgumentTypeError("value must be a finite non-negative number")
    return number


def normalized_frame(frame_id):
    return str(frame_id).strip().strip("/")


def yaw_from_quaternion(quaternion):
    sin_yaw = 2.0 * (quaternion.w * quaternion.z + quaternion.x * quaternion.y)
    cos_yaw = 1.0 - 2.0 * (quaternion.y * quaternion.y + quaternion.z * quaternion.z)
    return math.atan2(sin_yaw, cos_yaw)


def load_route(path, order, max_distance, max_segment_distance):
    with path.open("r", encoding="utf-8") as stream:
        data = yaml.safe_load(stream)

    if not isinstance(data, dict):
        raise ValueError("waypoint YAML root must be a mapping")
    if not order:
        raise ValueError("route order cannot be empty")
    if len(order) != len(set(order)):
        raise ValueError("route order contains duplicate waypoint IDs")

    count = int(data["Waypoints_Num"])
    poses = []
    previous_xy = (0.0, 0.0)
    for waypoint_id in order:
        if waypoint_id < 1 or waypoint_id > count:
            raise ValueError(
                f"waypoint {waypoint_id} is outside the valid range 1..{count}"
            )

        waypoint = data[f"Waypoint_{waypoint_id}"]
        values = {
            "Pos_x": float(waypoint["Pos_x"]),
            "Pos_y": float(waypoint["Pos_y"]),
            "Pos_z": float(waypoint.get("Pos_z", 0.0)),
            "Ori_x": float(waypoint.get("Ori_x", 0.0)),
            "Ori_y": float(waypoint.get("Ori_y", 0.0)),
            "Ori_z": float(waypoint.get("Ori_z", 0.0)),
            "Ori_w": float(waypoint.get("Ori_w", 1.0)),
        }
        if not all(math.isfinite(value) for value in values.values()):
            raise ValueError(f"waypoint {waypoint_id} contains a non-finite value")

        distance = math.hypot(values["Pos_x"], values["Pos_y"])
        if distance > max_distance:
            raise ValueError(
                f"waypoint {waypoint_id} is {distance:.2f} m from the odom origin, "
                f"exceeding --max-distance {max_distance:.2f} m"
            )

        quaternion_norm = math.sqrt(
            sum(values[key] ** 2 for key in ("Ori_x", "Ori_y", "Ori_z", "Ori_w"))
        )
        if abs(quaternion_norm - 1.0) > 0.02:
            raise ValueError(
                f"waypoint {waypoint_id} quaternion norm is {quaternion_norm:.4f}, "
                "expected approximately 1.0"
            )

        current_xy = (values["Pos_x"], values["Pos_y"])
        segment_distance = math.hypot(
            current_xy[0] - previous_xy[0], current_xy[1] - previous_xy[1]
        )
        if segment_distance > max_segment_distance:
            raise ValueError(
                f"leg ending at waypoint {waypoint_id} is "
                f"{segment_distance:.2f} m, exceeding --max-segment-distance "
                f"{max_segment_distance:.2f} m"
            )
        previous_xy = current_xy
        poses.append((waypoint_id, values))

    return normalized_frame(data.get("Frame_Id", "odom")), poses


class MaplessOutpostNavigator(Node):
    def __init__(self, action_name, odom_topic):
        super().__init__("mapless_outpost_navigator")
        self.client = ActionClient(self, NavigateThroughPoses, action_name)
        self.latest_odom = None
        self.odom_sequence = 0
        self.odom_subscription = self.create_subscription(
            Odometry, odom_topic, self._odometry_callback, 10
        )

    def _odometry_callback(self, message):
        self.latest_odom = message
        self.odom_sequence += 1

    def build_goal(self, frame_id, route):
        goal = NavigateThroughPoses.Goal()
        for _, waypoint in route:
            pose = PoseStamped()
            pose.header.frame_id = frame_id
            pose.header.stamp = self.get_clock().now().to_msg()
            pose.pose.position.x = waypoint["Pos_x"]
            pose.pose.position.y = waypoint["Pos_y"]
            pose.pose.position.z = waypoint["Pos_z"]
            pose.pose.orientation.x = waypoint["Ori_x"]
            pose.pose.orientation.y = waypoint["Ori_y"]
            pose.pose.orientation.z = waypoint["Ori_z"]
            pose.pose.orientation.w = waypoint["Ori_w"]
            goal.poses.append(pose)
        return goal

    def wait_until_stationary(
        self, timeout, stable_duration, max_linear_speed, max_angular_speed
    ):
        deadline = time.monotonic() + timeout
        stable_since = None
        last_speeds = None
        last_sequence = -1
        while rclpy.ok() and time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=0.1)
            if self.latest_odom is None or self.odom_sequence == last_sequence:
                continue

            last_sequence = self.odom_sequence
            twist = self.latest_odom.twist.twist
            linear_speed = math.hypot(twist.linear.x, twist.linear.y)
            angular_speed = abs(twist.angular.z)
            last_speeds = (linear_speed, angular_speed)
            if linear_speed <= max_linear_speed and angular_speed <= max_angular_speed:
                if stable_since is None:
                    stable_since = time.monotonic()
                if time.monotonic() - stable_since >= stable_duration:
                    return self.latest_odom
            else:
                stable_since = None

        if self.latest_odom is None:
            self.get_logger().error(f"No odometry received within {timeout:.1f}s")
        else:
            linear_speed, angular_speed = last_speeds
            self.get_logger().error(
                "Robot did not remain stationary for "
                f"{stable_duration:.1f}s (last linear={linear_speed:.3f} m/s, "
                f"angular={angular_speed:.3f} rad/s)"
            )
        return None

    def preflight(self, frame_id, route, args):
        if not self.client.wait_for_server(timeout_sec=args.server_timeout):
            self.get_logger().error(
                "NavigateThroughPoses server unavailable after "
                f"{args.server_timeout:.1f}s"
            )
            return 2

        odometry = self.wait_until_stationary(
            args.odom_timeout,
            args.stable_duration,
            args.max_start_linear_speed,
            args.max_start_angular_speed,
        )
        if odometry is None:
            return 3

        actual_frame = normalized_frame(odometry.header.frame_id)
        if actual_frame != frame_id:
            self.get_logger().error(
                f"Odometry frame is {actual_frame!r}, but route frame is {frame_id!r}"
            )
            return 4

        pose = odometry.pose.pose
        pose_values = (
            pose.position.x,
            pose.position.y,
            pose.position.z,
            pose.orientation.x,
            pose.orientation.y,
            pose.orientation.z,
            pose.orientation.w,
        )
        if not all(math.isfinite(value) for value in pose_values):
            self.get_logger().error("Odometry pose contains a non-finite value")
            return 5

        orientation_norm = math.sqrt(sum(value * value for value in pose_values[3:]))
        if abs(orientation_norm - 1.0) > 0.05:
            self.get_logger().error(
                f"Odometry quaternion norm is {orientation_norm:.4f}, expected "
                "approximately 1.0"
            )
            return 5

        start_offset = math.hypot(pose.position.x, pose.position.y)
        if start_offset > args.max_start_offset and not args.allow_nonzero_start:
            self.get_logger().error(
                f"Current odom pose is {start_offset:.2f} m from the recorded origin; "
                f"limit is {args.max_start_offset:.2f} m. Return to the fixed start pose "
                "or use --allow-nonzero-start only after deliberate route revalidation."
            )
            return 6
        if start_offset > args.max_start_offset:
            self.get_logger().warn(
                f"Overriding non-zero start offset: {start_offset:.2f} m"
            )

        start_yaw = yaw_from_quaternion(pose.orientation)
        if abs(start_yaw) > args.max_start_yaw:
            self.get_logger().error(
                f"Current odom yaw is {start_yaw:.3f} rad from the recorded heading; "
                f"limit is {args.max_start_yaw:.3f} rad. Restart localization at the "
                "fixed physical heading before executing the route."
            )
            return 7

        route_text = " -> ".join(str(waypoint_id) for waypoint_id, _ in route)
        self.get_logger().info(
            f"Preflight passed: frame={frame_id}, start_offset={start_offset:.2f} m, "
            f"start_yaw={start_yaw:.3f} rad, route={route_text}"
        )
        return 0

    def run(self, frame_id, route, args):
        preflight_result = self.preflight(frame_id, route, args)
        if preflight_result != 0:
            return preflight_result
        if not args.execute:
            self.get_logger().warn(
                "PRECHECK ONLY: no movement goal was sent. Re-run with --execute "
                "after checking RViz, the route, low-speed limits, and emergency stop."
            )
            return 0

        route_text = " -> ".join(str(waypoint_id) for waypoint_id, _ in route)
        self.get_logger().warn(
            "EXECUTE ENABLED: sending one-shot odom route "
            f"{route_text} to the candidate outpost firing position."
        )
        send_future = self.client.send_goal_async(self.build_goal(frame_id, route))
        rclpy.spin_until_future_complete(
            self, send_future, timeout_sec=args.server_timeout
        )
        if not send_future.done():
            self.get_logger().error("Timed out while sending the route goal")
            return 8

        goal_handle = send_future.result()
        if goal_handle is None or not goal_handle.accepted:
            self.get_logger().error("The route goal was rejected")
            return 9

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(
            self, result_future, timeout_sec=args.result_timeout
        )
        if not result_future.done():
            self.get_logger().error(
                f"Route did not finish within {args.result_timeout:.1f}s; canceling"
            )
            cancel_future = goal_handle.cancel_goal_async()
            rclpy.spin_until_future_complete(self, cancel_future, timeout_sec=5.0)
            return 10

        status = result_future.result().status
        status_name = STATUS_NAMES.get(status, f"STATUS_{status}")
        if status != GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().error(f"Mapless route finished with {status_name}")
            return 11

        self.get_logger().info(
            "Mapless route succeeded; robot reached the candidate outpost firing position."
        )
        return 0


def parse_args(args):
    parser = argparse.ArgumentParser(
        description="Preflight or execute the mapless route to the outpost firing position"
    )
    parser.add_argument(
        "--execute",
        action="store_true",
        help="Send the route after preflight; without this flag no movement goal is sent",
    )
    parser.add_argument(
        "--waypoints",
        type=Path,
        default=default_waypoint_file(),
        help="Waypoint YAML whose coordinates are relative to the Point-LIO odom origin",
    )
    parser.add_argument(
        "--order",
        type=int,
        nargs="+",
        default=DEFAULT_ORDER,
        help="One-based route order; default: 1 2 3 4",
    )
    parser.add_argument(
        "--action-name",
        default="navigate_through_poses",
        help="Relative NavigateThroughPoses action name",
    )
    parser.add_argument(
        "--odom-topic", default="odometry", help="Relative odometry topic name"
    )
    parser.add_argument("--server-timeout", type=positive_float, default=30.0)
    parser.add_argument("--result-timeout", type=positive_float, default=180.0)
    parser.add_argument("--odom-timeout", type=positive_float, default=10.0)
    parser.add_argument("--stable-duration", type=positive_float, default=1.0)
    parser.add_argument(
        "--max-distance",
        type=positive_float,
        default=20.0,
        help="Reject route points farther than this from the odom origin",
    )
    parser.add_argument(
        "--max-segment-distance",
        type=positive_float,
        default=12.0,
        help="Reject consecutive route points farther apart than this",
    )
    parser.add_argument(
        "--max-start-offset",
        type=nonnegative_float,
        default=1.0,
        help="Maximum allowed current XY distance from the recorded odom origin",
    )
    parser.add_argument(
        "--max-start-yaw",
        type=nonnegative_float,
        default=0.25,
        help="Maximum allowed absolute odom yaw at dispatch time, in radians",
    )
    parser.add_argument("--max-start-linear-speed", type=nonnegative_float, default=0.1)
    parser.add_argument(
        "--max-start-angular-speed", type=nonnegative_float, default=0.2
    )
    parser.add_argument(
        "--allow-nonzero-start",
        action="store_true",
        help="Override only the start-offset gate; frame and stationary gates remain active",
    )
    return parser.parse_args(args)


def main():
    args = parse_args(remove_ros_args(sys.argv)[1:])
    rclpy.init()
    node = None
    exit_code = 1
    try:
        frame_id, route = load_route(
            args.waypoints,
            args.order,
            args.max_distance,
            args.max_segment_distance,
        )
        if frame_id != "odom":
            raise ValueError(f"mapless route must use Frame_Id=odom, got {frame_id!r}")
        node = MaplessOutpostNavigator(args.action_name, args.odom_topic)
        exit_code = node.run(frame_id, route, args)
    except (OSError, KeyError, TypeError, ValueError, yaml.YAMLError) as error:
        print(f"mapless_nav_to_outpost: {error}", file=sys.stderr)
        exit_code = 1
    except KeyboardInterrupt:
        exit_code = 130
    finally:
        if node is not None:
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
    raise SystemExit(exit_code)


if __name__ == "__main__":
    main()
