# Copyright 2025 Lihan Chen
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    bringup_dir = get_package_share_directory("pb2025_nav_bringup")
    reality_launch = os.path.join(
        bringup_dir, "launch", "rm_navigation_reality_launch.py"
    )
    mapless_params = os.path.join(
        bringup_dir, "config", "reality", "mapless_nav2_params.yaml"
    )

    mapless_rviz = os.path.join(bringup_dir, "rviz", "nav2_mapless_view.rviz")

    namespace = LaunchConfiguration("namespace")
    use_sim_time = LaunchConfiguration("use_sim_time")
    use_composition = LaunchConfiguration("use_composition")
    use_respawn = LaunchConfiguration("use_respawn")
    use_robot_state_pub = LaunchConfiguration("use_robot_state_pub")
    use_livox_driver = LaunchConfiguration("use_livox_driver")
    use_rviz = LaunchConfiguration("use_rviz")

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "namespace", default_value="", description="Top-level namespace"
            ),
            DeclareLaunchArgument(
                "use_sim_time",
                default_value="False",
                description="Use simulation clock",
            ),
            DeclareLaunchArgument(
                "use_composition",
                default_value="False",
                description="Load supported nodes into the Nav2 component container",
            ),
            DeclareLaunchArgument(
                "use_respawn",
                default_value="False",
                description="Respawn crashed non-composed nodes",
            ),
            DeclareLaunchArgument(
                "use_robot_state_pub",
                default_value="True",
                description="Start robot_state_publisher",
            ),
            DeclareLaunchArgument(
                "use_livox_driver",
                default_value="True",
                description="Start livox_ros_driver2; disable while replaying a bag",
            ),
            DeclareLaunchArgument(
                "use_rviz", default_value="True", description="Start RViz"
            ),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(reality_launch),
                launch_arguments={
                    "namespace": namespace,
                    "slam": "False",
                    "mapless": "True",
                    "use_sim_time": use_sim_time,
                    "params_file": mapless_params,
                    "rviz_config_file": mapless_rviz,
                    "use_composition": use_composition,
                    "use_respawn": use_respawn,
                    "use_robot_state_pub": use_robot_state_pub,
                    "use_livox_driver": use_livox_driver,
                    "use_rviz": use_rviz,
                    "auto_save_map": "False",
                    "auto_save_pcd": "False",
                }.items(),
            ),
        ]
    )
