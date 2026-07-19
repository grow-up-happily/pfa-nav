import math
from pathlib import Path

import yaml


PACKAGE_ROOT = Path(__file__).resolve().parents[1]
REALITY_CONFIG = PACKAGE_ROOT / "config" / "reality"


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
