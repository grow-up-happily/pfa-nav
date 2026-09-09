# Copyright 2026 Lihan Chen
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import math
from pathlib import Path
from xml.etree import ElementTree

import yaml


PACKAGE_ROOT = Path(__file__).resolve().parents[1]
REALITY_CONFIG = PACKAGE_ROOT / "config" / "reality"
SIMULATION_CONFIG = PACKAGE_ROOT / "config" / "simulation"
MAPLESS_RVIZ = PACKAGE_ROOT / "rviz" / "nav2_mapless_view.rviz"


def load_yaml(path):
    with path.open("r", encoding="utf-8") as stream:
        return yaml.safe_load(stream)


def node_params(config, node_name):
    return config[node_name]["ros__parameters"]


def test_mapless_costmaps_are_odom_rolling_and_have_no_static_layer():
    config = load_yaml(REALITY_CONFIG / "mapless_nav2_params.yaml")
    local = config["local_costmap"]["local_costmap"]["ros__parameters"]
    global_ = config["global_costmap"]["global_costmap"]["ros__parameters"]

    assert local["global_frame"] == "odom"
    assert global_["global_frame"] == "odom"
    assert global_["rolling_window"] is True
    assert all("static" not in plugin.lower() for plugin in local["plugins"])
    assert all("static" not in plugin.lower() for plugin in global_["plugins"])


def test_mapless_servers_use_odom_and_point_lio_has_no_prior_pcd():
    config = load_yaml(REALITY_CONFIG / "mapless_nav2_params.yaml")

    assert node_params(config, "bt_navigator")["global_frame"] == "odom"
    assert node_params(config, "behavior_server")["global_frame"] == "odom"
    assert node_params(config, "point_lio")["prior_pcd"]["enable"] is False
    assert node_params(config, "fake_vel_transform")["init_spin_speed"] == 0.0


def test_mapless_planner_matches_holonomic_base():
    config = load_yaml(REALITY_CONFIG / "mapless_nav2_params.yaml")
    planner = node_params(config, "planner_server")["GridBased"]

    assert planner["plugin"] == "nav2_smac_planner/SmacPlanner2D"
    assert "motion_model_for_search" not in planner


def test_mapless_through_poses_tree_uses_odom_for_goal_pruning():
    config = load_yaml(REALITY_CONFIG / "mapless_nav2_params.yaml")
    bt_path = node_params(config, "bt_navigator")["default_nav_through_poses_bt_xml"]
    assert bt_path.endswith("/behavior_trees/navigate_through_poses_mapless.xml")

    tree = ElementTree.parse(
        PACKAGE_ROOT / "behavior_trees" / "navigate_through_poses_mapless.xml"
    )
    remove_passed_goals = tree.find(".//RemovePassedGoals")
    assert remove_passed_goals is not None
    assert remove_passed_goals.attrib["global_frame"] == "odom"
    assert remove_passed_goals.attrib["robot_base_frame"] == "gimbal_yaw_fake"


def test_mapless_velocity_is_capped_for_initial_field_tests():
    config = load_yaml(REALITY_CONFIG / "mapless_nav2_params.yaml")
    controller = node_params(config, "controller_server")["FollowPath"]
    smoother = node_params(config, "velocity_smoother")

    assert abs(controller["v_linear_min"]) <= 0.5
    assert controller["v_linear_max"] <= 0.5
    assert abs(controller["v_angular_min"]) <= 1.0
    assert controller["v_angular_max"] <= 1.0
    assert max(abs(value) for value in smoother["max_velocity"][:2]) <= 0.5
    assert max(abs(value) for value in smoother["min_velocity"][:2]) <= 0.5


def test_outpost_route_is_finite_normalized_and_bounded():
    route = load_yaml(REALITY_CONFIG / "mapless_outpost_route.yaml")

    assert route["Frame_Id"] == "odom"
    assert route["Route_Order"] == [1, 2, 3, 4]
    assert route["Waypoints_Num"] >= len(route["Route_Order"])

    previous = (0.0, 0.0)
    for waypoint_id in route["Route_Order"]:
        waypoint = route[f"Waypoint_{waypoint_id}"]
        values = [
            float(waypoint[key])
            for key in (
                "Pos_x",
                "Pos_y",
                "Pos_z",
                "Ori_x",
                "Ori_y",
                "Ori_z",
                "Ori_w",
            )
        ]
        assert all(math.isfinite(value) for value in values)
        assert math.hypot(values[0], values[1]) <= 20.0
        quaternion_norm = math.sqrt(sum(value * value for value in values[3:]))
        assert math.isclose(quaternion_norm, 1.0, abs_tol=0.02)
        segment = math.hypot(values[0] - previous[0], values[1] - previous[1])
        assert segment <= 12.0
        previous = values


def test_mapless_runner_requires_explicit_execute_gate():
    runner = PACKAGE_ROOT / "scripts" / "mapless_nav_to_outpost.py"
    source = runner.read_text(encoding="utf-8")

    execute_gate = source.index("if not args.execute:")
    goal_send = source.index("send_goal_async")
    assert '"--execute"' in source
    assert execute_gate < goal_send


def test_mapless_wrapper_enables_mapless_mode_and_disables_slam():
    launch_file = PACKAGE_ROOT / "launch" / "rm_navigation_mapless_launch.py"
    launch_text = launch_file.read_text(encoding="utf-8")

    assert '"mapless": "True"' in launch_text
    assert '"slam": "False"' in launch_text


def test_simulation_mapless_mode_selects_mapless_rviz_config():
    launch_file = PACKAGE_ROOT / "launch" / "rm_navigation_simulation_launch.py"
    launch_text = launch_file.read_text(encoding="utf-8")

    assert '"rviz", "nav2_mapless_view.rviz"' in launch_text
    assert '"rviz", "nav2_default_view.rviz"' in launch_text
    assert "mapless," in launch_text


def test_simulation_uses_ground_truth_only_for_scan_registration():
    simulation = load_yaml(SIMULATION_CONFIG / "nav2_params.yaml")
    mapless = load_yaml(REALITY_CONFIG / "mapless_nav2_params.yaml")

    simulation_interface = node_params(simulation, "loam_interface")
    assert simulation_interface["use_ground_truth"] is True
    assert simulation_interface["ground_truth_odometry_topic"] == "chassis_odometry_gt"
    assert simulation_interface["sensor_scan_topic"] == "velodyne_points"
    assert node_params(mapless, "loam_interface")["use_ground_truth"] is False


def test_mapless_rviz_uses_odom_and_displays_live_point_clouds():
    rviz_config = load_yaml(MAPLESS_RVIZ)
    manager = rviz_config["Visualization Manager"]
    displays = {display["Name"]: display for display in manager["Displays"]}

    assert manager["Global Options"]["Fixed Frame"] == "odom"
    assert displays["TerrainMapExt"]["Topic"]["Value"] == "terrain_map_ext"
    assert displays["RegisteredCloud"]["Topic"]["Value"] == "registered_scan"
    assert displays["RegisteredCloud"]["Enabled"] is True
    assert "PriorMap" not in displays
    assert "Map" not in displays

    rviz_text = MAPLESS_RVIZ.read_text(encoding="utf-8")
    assert "Class: wp_map_tools/HeroBasePoseTool" not in rviz_text
