# Copyright 2026
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

import shlex

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, OpaqueFunction, TimerAction
from launch.substitutions import LaunchConfiguration


def _normalized_namespace(namespace):
    return namespace.strip().strip("/")


def _parse_intervals(intervals_text):
    intervals = []
    for value in intervals_text.split(","):
        value = value.strip()
        if value:
            intervals.append(float(value))
    return intervals if intervals else [10.0]


def _create_save_actions(context):
    namespace = _normalized_namespace(LaunchConfiguration("namespace").perform(context))
    save_dir = LaunchConfiguration("save_dir").perform(context)
    file_prefix = LaunchConfiguration("file_prefix").perform(context)
    intervals = _parse_intervals(LaunchConfiguration("intervals").perform(context))
    image_format = LaunchConfiguration("image_format").perform(context)
    map_mode = LaunchConfiguration("map_mode").perform(context)
    free_thresh = float(LaunchConfiguration("free_thresh").perform(context))
    occupied_thresh = float(LaunchConfiguration("occupied_thresh").perform(context))
    service_timeout = float(LaunchConfiguration("service_timeout").perform(context))

    service_name = "/map_saver/save_map"
    map_topic = "/map"
    if namespace:
        service_name = f"/{namespace}{service_name}"
        map_topic = f"/{namespace}{map_topic}"

    actions = []
    for period in intervals:
        save_cmd = (
            f"save_dir={shlex.quote(save_dir)}; "
            f"file_prefix={shlex.quote(file_prefix)}; "
            "stamp=$(date +%Y%m%d_%H%M%S); "
            'map_base="${save_dir}/${file_prefix}_${stamp}"; '
            'mkdir -p "$save_dir" && '
            f'echo "[auto_save_map] saving grid map to ${{map_base}}.{image_format} and ${{map_base}}.yaml" && '
            f"timeout {service_timeout:g}s "
            f"ros2 service call {shlex.quote(service_name)} nav2_msgs/srv/SaveMap "
            '"{'
            f"map_topic: '{map_topic}', "
            "map_url: '${map_base}', "
            f"image_format: '{image_format}', "
            f"map_mode: '{map_mode}', "
            f"free_thresh: {free_thresh:g}, "
            f"occupied_thresh: {occupied_thresh:g}"
            '}"; '
            "status=$?; "
            'if [ "$status" -eq 0 ] && '
            f'[ -f "${{map_base}}.{image_format}" ] && '
            '[ -f "${map_base}.yaml" ]; then '
            f'echo "[auto_save_map] saved grid map: ${{map_base}}.{image_format} ${{map_base}}.yaml"; '
            'elif [ "$status" -eq 0 ]; then '
            f'echo "[auto_save_map] save service returned, but expected files are missing: ${{map_base}}.{image_format} ${{map_base}}.yaml" >&2; '
            "else "
            'echo "[auto_save_map] failed to save grid map: ${map_base} (exit ${status})" >&2; '
            "fi; "
            'exit "$status"'
        )
        actions.append(
            TimerAction(
                period=period,
                actions=[
                    ExecuteProcess(
                        cmd=["bash", "-c", save_cmd],
                        output="screen",
                    )
                ],
            )
        )

    return actions


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "namespace",
                default_value="",
                description="Namespace that owns map_saver and map topics.",
            ),
            DeclareLaunchArgument(
                "save_dir",
                default_value="/home/lcy/sight_test/pfa-nav/src/pb2025_sentry_nav/pb2025_nav_bringup/map/simulation",
                description="Directory where auto-saved .pgm/.yaml maps are written.",
            ),
            DeclareLaunchArgument(
                "file_prefix",
                default_value="auto_map",
                description="Prefix for auto-saved map files.",
            ),
            DeclareLaunchArgument(
                "intervals",
                default_value="10,30,60,90,120,150,180,210,240,270,300",
                description="Comma-separated one-shot save times in seconds after launch.",
            ),
            DeclareLaunchArgument(
                "image_format",
                default_value="pgm",
                description="Map image format passed to nav2 map_saver.",
            ),
            DeclareLaunchArgument(
                "map_mode",
                default_value="trinary",
                description="Map mode passed to nav2 map_saver.",
            ),
            DeclareLaunchArgument(
                "free_thresh",
                default_value="0.25",
                description="Free threshold passed to nav2 map_saver.",
            ),
            DeclareLaunchArgument(
                "occupied_thresh",
                default_value="0.65",
                description="Occupied threshold passed to nav2 map_saver.",
            ),
            DeclareLaunchArgument(
                "service_timeout",
                default_value="15.0",
                description="Seconds to wait for each save service call before giving up.",
            ),
            OpaqueFunction(function=_create_save_actions),
        ]
    )
