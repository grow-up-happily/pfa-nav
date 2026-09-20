#!/usr/bin/env bash
set -Eeuo pipefail

# SLAM launch wrapper: auto-save grid map + 3D PCD + rosbag on exit
# Usage: ./slam.sh [extra launch args...]
# Example: ./slam.sh world:=rmuc_2025

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Source 环境变量
set +u
source /opt/ros/humble/setup.bash
source "$SCRIPT_DIR/install/setup.bash"
set -u

NAMESPACE="red_standard_robot1"
MAP_SAVE_DIR="$SCRIPT_DIR/src/pb2025_sentry_nav/point_lio/PCD"
MAP_NAME="scans"
BAG_NAME="slam_bag_$(date +%Y%m%d_%H%M%S)"
BAG_PATH="${MAP_SAVE_DIR}/${BAG_NAME}"

EXPECTED_PREFIX="$SCRIPT_DIR/install/pb2025_nav_bringup"
ACTUAL_PREFIX="$(ros2 pkg prefix pb2025_nav_bringup)"
if [[ "$ACTUAL_PREFIX" != "$EXPECTED_PREFIX" ]]; then
    echo "[slam.sh] ERROR: pb2025_nav_bringup resolves to the wrong workspace:" >&2
    echo "  actual:   $ACTUAL_PREFIX" >&2
    echo "  expected: $EXPECTED_PREFIX" >&2
    exit 1
fi

wait_for_sensor() {
    local topic="$1"
    echo "[slam.sh] Checking live sensor data on $topic ..."
    if ! timeout 8s ros2 topic echo "$topic" --once --qos-reliability best_effort >/dev/null 2>&1; then
        echo "[slam.sh] ERROR: no live message received on $topic." >&2
        echo "[slam.sh] Gazebo is absent, paused, or stale. Stop this run, then execute:" >&2
        echo "  $SCRIPT_DIR/kill_ros2_leftovers.sh --include-sim" >&2
        echo "and start one fresh Gazebo instance before running slam.sh again." >&2
        exit 1
    fi
}

# Do not start Point-LIO/Nav2 against a stale Gazebo graph. A topic may still
# be listed after a bad restart, so require an actual message from both sensors.
wait_for_sensor "/${NAMESPACE}/livox/lidar"
wait_for_sensor "/${NAMESPACE}/livox/imu"

stop_process_group() {
    local label="$1"
    local leader_pid="$2"
    local signal attempt

    [[ -n "$leader_pid" ]] || return 0
    kill -0 -- "-$leader_pid" 2>/dev/null || return 0

    for signal in INT TERM KILL; do
        echo "[slam.sh] Stopping $label with SIG$signal ..."
        kill -"$signal" -- "-$leader_pid" 2>/dev/null || true
        for attempt in {1..20}; do
            kill -0 -- "-$leader_pid" 2>/dev/null || break 2
            sleep 0.25
        done
    done

    wait "$leader_pid" 2>/dev/null || true
}

# Wait for nodes to start, then record rosbag in a separate session
echo "[slam.sh] Starting rosbag recording to ${BAG_PATH} ..."
setsid ros2 bag record -a -o "${BAG_PATH}" &
BAG_PID=$!
echo "[slam.sh] Rosbag PID: ${BAG_PID}"

sleep 2

# Launch SLAM in a separate session so Ctrl+C won't reach it
setsid ros2 launch pb2025_nav_bringup rm_navigation_simulation_launch.py \
    slam:=True auto_save_map:=False "$@" &
LAUNCH_PID=$!



cleanup() {
    trap - INT TERM EXIT

    echo ""

    # Stop rosbag - kill entire session group
    stop_process_group "rosbag recording" "${BAG_PID:-}"
    echo "[slam.sh] Rosbag saved to ${BAG_PATH}/"

    # Save grid map via map_saver service
    echo "[slam.sh] Saving grid map..."
    timeout 20s ros2 service call /"${NAMESPACE}"/map_saver/save_map nav2_msgs/srv/SaveMap \
        "{map_topic: '/${NAMESPACE}/map', map_url: '${MAP_SAVE_DIR}/${MAP_NAME}', image_format: 'pgm', map_mode: 'trinary', free_thresh: 0.25, occupied_thresh: 0.65}" \
        || echo "[slam.sh] WARNING: grid map save failed or timed out."
    echo "[slam.sh] Grid map saved to ${MAP_SAVE_DIR}/${MAP_NAME}.pgm/.yaml"

    # Shutdown launch - kill entire session group
    stop_process_group "SLAM launch" "${LAUNCH_PID:-}"
    echo "[slam.sh] 3D PCD saved to ${MAP_SAVE_DIR}/scans.pcd (by point_lio)"
    echo "[slam.sh] Done."
}

trap cleanup INT TERM EXIT

# Keep script alive
while kill -0 $LAUNCH_PID 2>/dev/null; do
    wait $LAUNCH_PID 2>/dev/null
done
