#!/usr/bin/env bash
set -Eeuo pipefail

# Real-robot localization and navigation entry point. Resolve every path from
# this repository so an older pfa-nav workspace can never be sourced silently.
WORKSPACE="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
SETUP_FILE="${SETUP_FILE:-$WORKSPACE/install/setup.bash}"
MAP_FILE="${MAP_FILE:-$WORKSPACE/src/pb2025_sentry_nav/pb2025_nav_bringup/map/reality/game.yaml}"
PCD_FILE="${PCD_FILE:-$WORKSPACE/src/pb2025_sentry_nav/point_lio/PCD/scans.pcd}"
NAMESPACE="${NAMESPACE:-}"
USE_RVIZ="${USE_RVIZ:-False}"
ROS_LOG_DIR="${ROS_LOG_DIR:-$WORKSPACE/log/ros}"

for required in "$SETUP_FILE" "$MAP_FILE" "$PCD_FILE"; do
  if [[ ! -f "$required" ]]; then
    echo "ERROR: required navigation file is missing: $required" >&2
    exit 1
  fi
done

mkdir -p "$ROS_LOG_DIR"
export ROS_LOG_DIR

set +u
# shellcheck source=/dev/null
source /opt/ros/humble/setup.bash
# shellcheck source=/dev/null
source "$SETUP_FILE"
set -u

cd "$WORKSPACE"
echo "[pfa_navigation] workspace: $WORKSPACE"
echo "[pfa_navigation] map: $MAP_FILE"
echo "[pfa_navigation] point cloud: $PCD_FILE"
echo "[pfa_navigation] namespace: ${NAMESPACE:-<empty>}"
echo "[pfa_navigation] RViz: $USE_RVIZ"

exec ros2 launch pb2025_nav_bringup rm_navigation_reality_launch.py \
  world:=game \
  map:="$MAP_FILE" \
  prior_pcd_file:="$PCD_FILE" \
  namespace:="$NAMESPACE" \
  slam:=False \
  use_sim_time:=False \
  use_robot_state_pub:=True \
  use_livox_driver:=True \
  use_rviz:="$USE_RVIZ" \
  auto_save_map:=False \
  auto_save_pcd:=False
