#!/usr/bin/env python3
import os
import yaml

import rclpy
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped, TransformStamped
from rclpy.duration import Duration
from rclpy.node import Node
from tf2_ros import Buffer, TransformBroadcaster, TransformListener


class WaypointStaticPublisher(Node):
    """持续发布 map->base TF，支持 waypoint 初始值和 RViz Pose 工具更新。"""

    def __init__(self):
        super().__init__('waypoint_static_publisher')

        self.declare_parameter('waypoints_file', '')
        self.declare_parameter('pose_topic', '/hero_lidar/base_pose')
        self.declare_parameter('initial_pose_topic', '/initialpose')
        self.declare_parameter('publish_rate', 10.0)

        self.parent_frame = 'map'
        self.child_frame = 'base'

        self.broadcaster = TransformBroadcaster(self)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.base_pose = None

        waypoints_file = self.get_parameter('waypoints_file').value
        self._load_initial_pose_from_waypoints(waypoints_file)

        pose_topic = self.get_parameter('pose_topic').value
        if pose_topic:
            self.pose_sub = self.create_subscription(
                PoseStamped,
                pose_topic,
                self.goal_pose_callback,
                10,
            )
            self.get_logger().info(
                f'Listening for hero_lidar PoseStamped updates on {pose_topic}.'
            )

        initial_pose_topic = self.get_parameter('initial_pose_topic').value
        if initial_pose_topic:
            self.initial_pose_sub = self.create_subscription(
                PoseWithCovarianceStamped,
                initial_pose_topic,
                self.initial_pose_callback,
                10,
            )
            self.get_logger().info(
                f'Listening for RViz initial pose updates on {initial_pose_topic}.'
            )

        publish_rate = float(self.get_parameter('publish_rate').value)
        if publish_rate <= 0.0:
            self.get_logger().warning(
                f'Invalid publish_rate={publish_rate}, fallback to 10.0 Hz.'
            )
            publish_rate = 10.0

        self.create_timer(1.0 / publish_rate, self.publish_transform)
        self.create_timer(1.0, self._print_chassis_base)

    def _load_initial_pose_from_waypoints(self, waypoints_file: str):
        waypoint_path = waypoints_file or os.path.join(os.getcwd(), 'waypoints.yaml')
        if not os.path.exists(waypoint_path):
            if waypoints_file:
                self.get_logger().error(f'waypoints file not found: {waypoint_path}')
            else:
                self.get_logger().warning(
                    f'Waypoint file not found: {waypoint_path}. Waiting for RViz pose updates.'
                )
            return

        try:
            with open(waypoint_path, 'r', encoding='utf-8') as file:
                data = yaml.safe_load(file)
        except Exception as exc:
            self.get_logger().error(f'failed to parse yaml: {exc}')
            return

        waypoint = self._extract_first_waypoint(data)
        if waypoint is None:
            self.get_logger().error(f'no waypoint entries found in {waypoint_path}')
            return

        raw_x = self._ci_key_lookup(waypoint, {'posx', 'x', 'px'})
        raw_y = self._ci_key_lookup(waypoint, {'posy', 'y', 'py'})
        raw_z = self._ci_key_lookup(waypoint, {'posz', 'z', 'pz'})
        raw_qx = self._ci_key_lookup(waypoint, {'orix', 'qx'})
        raw_qy = self._ci_key_lookup(waypoint, {'oriy', 'qy'})
        raw_qz = self._ci_key_lookup(waypoint, {'oriz', 'qz'})
        raw_qw = self._ci_key_lookup(waypoint, {'oriw', 'qw'})

        try:
            self._update_pose(
                raw_x,
                raw_y,
                raw_z if raw_z is not None else 0.0,
                raw_qx if raw_qx is not None else 0.0,
                raw_qy if raw_qy is not None else 0.0,
                raw_qz if raw_qz is not None else 0.0,
                raw_qw if raw_qw is not None else 1.0,
                f'waypoint file {waypoint_path}',
            )
        except Exception as exc:
            self.get_logger().error(f'failed to parse first waypoint coordinates: {exc}')
            return

    def _extract_first_waypoint(self, data):
        first = None

        if isinstance(data, dict):
            for key in sorted(data.keys()):
                if isinstance(key, str) and key.lower().startswith('waypoint') and isinstance(data[key], dict):
                    first = data[key]
                    break

            if first is None:
                for value in data.values():
                    if isinstance(value, dict):
                        first = value
                        break

        elif isinstance(data, (list, tuple)) and len(data) > 0:
            first = data[0]

        if isinstance(first, dict):
            return first
        return None

    def _ci_key_lookup(self, data, targets):
        for key, value in data.items():
            normalized_key = ''.join(key.lower().split('_'))
            if normalized_key in targets:
                return value
        return None

    def _update_pose(self, x, y, z, qx, qy, qz, qw, source: str):
        self.base_pose = {
            'x': float(x),
            'y': float(y),
            'z': float(z),
            'qx': float(qx),
            'qy': float(qy),
            'qz': float(qz),
            'qw': float(qw),
        }
        self.get_logger().info(
            f'Updated {self.parent_frame}->{self.child_frame} from {source}: '
            f'x={self.base_pose["x"]:.3f}, y={self.base_pose["y"]:.3f}'
        )

    def goal_pose_callback(self, msg: PoseStamped):
        frame_id = msg.header.frame_id or 'map'
        if frame_id not in ('map', self.parent_frame):
            self.get_logger().warning(
                f'Ignoring PoseStamped in frame {frame_id}, expected map or {self.parent_frame}.'
            )
            return

        pose = msg.pose
        self._update_pose(
            pose.position.x,
            pose.position.y,
            pose.position.z,
            pose.orientation.x,
            pose.orientation.y,
            pose.orientation.z,
            pose.orientation.w,
            'RViz hero_lidar pose',
        )

    def initial_pose_callback(self, msg: PoseWithCovarianceStamped):
        pose = msg.pose.pose
        self._update_pose(
            pose.position.x,
            pose.position.y,
            pose.position.z,
            pose.orientation.x,
            pose.orientation.y,
            pose.orientation.z,
            pose.orientation.w,
            'RViz initialpose',
        )

    def publish_transform(self):
        if self.base_pose is None:
            return

        transform = TransformStamped()
        transform.header.stamp = self.get_clock().now().to_msg()
        transform.header.frame_id = self.parent_frame
        transform.child_frame_id = self.child_frame
        transform.transform.translation.x = self.base_pose['x']
        transform.transform.translation.y = self.base_pose['y']
        transform.transform.translation.z = self.base_pose['z']
        transform.transform.rotation.x = self.base_pose['qx']
        transform.transform.rotation.y = self.base_pose['qy']
        transform.transform.rotation.z = self.base_pose['qz']
        transform.transform.rotation.w = self.base_pose['qw']

        self.broadcaster.sendTransform(transform)

    def _print_chassis_base(self):
        target_frame = 'base_footprint'
        source_frame = 'base'
        try:
            trans = self.tf_buffer.lookup_transform(
                target_frame,
                source_frame,
                rclpy.time.Time(),
                timeout=Duration(seconds=0.5),
            )
            translation = trans.transform.translation
            rotation = trans.transform.rotation
            self.get_logger().info(
                f'{target_frame}->{source_frame}: trans=({translation.x:.3f}, {translation.y:.3f}, {translation.z:.3f}), '
                f'quat=({rotation.x:.3f}, {rotation.y:.3f}, {rotation.z:.3f}, {rotation.w:.3f})'
            )
        except Exception as exc:
            self.get_logger().debug(f'{target_frame}->{source_frame} not available: {exc}')


def main(args=None):
    rclpy.init(args=args)
    node = None
    try:
        node = WaypointStaticPublisher()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if node:
            node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
