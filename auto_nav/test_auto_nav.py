import unittest
import math
from inspect import signature

from auto_nav import (
    AutoNavNode,
    compute_straight_segment_plan,
    should_handoff_to_straight_calibration,
    transform_local_velocity_between_yaws,
)


WAYPOINTS = [
    {"Pos_x": 0.0, "Pos_y": 0.0},
    {"Pos_x": 1.0, "Pos_y": 0.0},
    {"Pos_x": 2.0, "Pos_y": 0.0},
    {"Pos_x": 3.0, "Pos_y": 0.0},
]


class StraightCalibrationHandoffTest(unittest.TestCase):
    def test_default_manual_velocity_topic_matches_final_cmd_vel_frame(self):
        params = signature(AutoNavNode.__init__).parameters

        self.assertEqual(
            params["cmd_vel_topic"].default,
            "/red_standard_robot1/cmd_vel",
        )
        self.assertEqual(params["velocity_frame"].default, "gimbal_yaw")

    def test_chassis_forward_velocity_rotates_into_gimbal_yaw_frame(self):
        vx, vy = transform_local_velocity_between_yaws(
            vx=0.5,
            vy=0.0,
            source_yaw=0.0,
            target_yaw=math.pi / 2.0,
        )

        self.assertAlmostEqual(vx, 0.0)
        self.assertAlmostEqual(vy, -0.5)

    def test_three_to_two_uses_positive_chassis_drive_direction(self):
        _, _, drive_direction = compute_straight_segment_plan(
            WAYPOINTS,
            from_waypoint_idx=2,
            to_waypoint_idx=1,
        )

        self.assertEqual(drive_direction, 1.0)

    def test_handoffs_when_current_target_is_close_and_next_segment_is_calibrated(self):
        should_handoff, next_idx, distance = should_handoff_to_straight_calibration(
            targets=[0, 1, 2, 3],
            current_idx=1,
            calibration_transitions={(2, 3), (3, 2)},
            waypoints=WAYPOINTS,
            current_xy=(1.35, 0.0),
            tolerance=0.8,
        )

        self.assertTrue(should_handoff)
        self.assertEqual(next_idx, 2)
        self.assertAlmostEqual(distance, 0.35)

    def test_does_not_handoff_for_non_calibration_segment(self):
        should_handoff, next_idx, distance = should_handoff_to_straight_calibration(
            targets=[0, 1, 2, 3],
            current_idx=0,
            calibration_transitions={(2, 3), (3, 2)},
            waypoints=WAYPOINTS,
            current_xy=(0.05, 0.0),
            tolerance=0.8,
        )

        self.assertFalse(should_handoff)
        self.assertEqual(next_idx, 1)
        self.assertAlmostEqual(distance, 0.05)

    def test_does_not_handoff_when_target_is_still_far(self):
        should_handoff, next_idx, distance = should_handoff_to_straight_calibration(
            targets=[0, 1, 2, 3],
            current_idx=1,
            calibration_transitions={(2, 3), (3, 2)},
            waypoints=WAYPOINTS,
            current_xy=(0.0, 0.0),
            tolerance=0.8,
        )

        self.assertFalse(should_handoff)
        self.assertEqual(next_idx, 2)
        self.assertAlmostEqual(distance, 1.0)


if __name__ == "__main__":
    unittest.main()
