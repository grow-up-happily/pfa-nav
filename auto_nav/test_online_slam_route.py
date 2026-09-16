import json
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace

from action_msgs.msg import GoalStatus
from online_slam_goal import OnlineSlamGoal, ROUTE_FORMAT, parse_route_data
from online_slam_goal_gui import build_route_payload


class OnlineSlamRouteTest(unittest.TestCase):
    def write_goal(self, directory, name, x, frame="odom"):
        path = Path(directory) / f"{name}.json"
        path.write_text(
            json.dumps({"frame": frame, "x": x, "y": 1.0, "yaw": 0.0}),
            encoding="utf-8",
        )
        return path

    def test_visual_order_is_preserved_and_duplicates_are_allowed(self):
        with tempfile.TemporaryDirectory() as directory:
            near = self.write_goal(directory, "near", 2.0)
            far = self.write_goal(directory, "far", 9.0)
            payload = build_route_payload("patrol", [near, far, near])

        self.assertEqual(payload["format"], ROUTE_FORMAT)
        self.assertEqual(
            [point["name"] for point in payload["waypoints"]],
            ["near", "far", "near"],
        )
        frame, waypoints = parse_route_data(payload)
        self.assertEqual(frame, "odom")
        self.assertEqual([point["x"] for point in waypoints], [2.0, 9.0, 2.0])

    def test_mixed_coordinate_frames_are_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            odom_goal = self.write_goal(directory, "odom_goal", 2.0, "odom")
            map_goal = self.write_goal(directory, "map_goal", 3.0, "map")
            with self.assertRaisesRegex(ValueError, "不能混用"):
                build_route_payload("invalid", [odom_goal, map_goal])

    def test_unknown_route_format_is_rejected(self):
        with self.assertRaisesRegex(ValueError, "format"):
            parse_route_data(
                {
                    "format": "unknown/v1",
                    "frame": "odom",
                    "waypoints": [{"x": 1.0, "y": 2.0}],
                }
            )

    def test_success_advances_to_next_route_point(self):
        node = OnlineSlamGoal.__new__(OnlineSlamGoal)
        node.route_waypoints = [
            {"name": "near", "x": 2.0, "y": 1.0, "yaw": 0.0},
            {"name": "far", "x": 9.0, "y": 3.0, "yaw": 0.5},
        ]
        node.route_index = 0
        node.goal_sent = True
        node.finished = False
        node.get_clock = lambda: SimpleNamespace(now=lambda: "now")
        node.get_logger = lambda: SimpleNamespace(
            info=lambda _message: None,
            error=lambda _message: None,
        )
        future = SimpleNamespace(
            result=lambda: SimpleNamespace(status=GoalStatus.STATUS_SUCCEEDED)
        )

        node.result_callback(future)

        self.assertEqual(node.route_index, 1)
        self.assertEqual(node.current_goal_name, "far")
        self.assertEqual((node.goal_x, node.goal_y, node.goal_yaw), (9.0, 3.0, 0.5))
        self.assertFalse(node.goal_sent)
        self.assertFalse(node.finished)


if __name__ == "__main__":
    unittest.main()
