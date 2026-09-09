import os

import yaml
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    ExecuteProcess,
    IncludeLaunchDescription,
    OpaqueFunction,
    TimerAction,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def launch_setup(context):
    pkg_simulator = get_package_share_directory("rmu_gazebo_simulator")

    selected_world = LaunchConfiguration("world").perform(context)

    world_sdf_path = os.path.join(
        pkg_simulator, "resource", "worlds", f"{selected_world}_world.sdf"
    )
    ign_config_path = os.path.join(pkg_simulator, "resource", "ign", "gui.config")

    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_simulator, "launch", "gazebo.launch.py")
        ),
        launch_arguments={
            "world_sdf_path": world_sdf_path,
            "ign_config_path": ign_config_path,
        }.items(),
    )

    spawn_robots_launch = TimerAction(
        period=2.0,
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(pkg_simulator, "launch", "spawn_robots.launch.py")
                ),
                launch_arguments={
                    "world": selected_world,
                }.items(),
            )
        ],
    )

    referee_system_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_simulator, "launch", "referee_system.launch.py")
        )
    )

    start_simulation = TimerAction(
        period=3.0,
        actions=[
            ExecuteProcess(
                cmd=[
                    "ign",
                    "service",
                    "-s",
                    "/world/default/control",
                    "--reqtype",
                    "ignition.msgs.WorldControl",
                    "--reptype",
                    "ignition.msgs.Boolean",
                    "--timeout",
                    "5000",
                    "--req",
                    "pause: false",
                ],
                output="screen",
            )
        ],
    )

    return [
        gazebo_launch,
        spawn_robots_launch,
        referee_system_launch,
        start_simulation,
    ]


def generate_launch_description():
    pkg_simulator = get_package_share_directory("rmu_gazebo_simulator")

    gz_world_path = os.path.join(pkg_simulator, "config", "gz_world.yaml")
    with open(gz_world_path) as file:
        config = yaml.safe_load(file)
        default_world = config.get("world")

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "world",
                default_value=default_world,
                description="World name (e.g. rmul_2026, rmuc_2026)",
            ),
            OpaqueFunction(function=launch_setup),
        ]
    )
