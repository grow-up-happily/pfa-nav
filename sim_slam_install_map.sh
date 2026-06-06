#!/usr/bin/env bash
set -Eeuo pipefail

# One-key Gazebo + simulation SLAM helper.
# Start Gazebo and simulation SLAM, then press Ctrl+C after mapping. The script saves the
# final grid map and installs the newest PCD into simulation prior-navigation paths.

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
BRINGUP_DIR="$SCRIPT_DIR/src/pb2025_sentry_nav/pb2025_nav_bringup"
POINT_LIO_PCD_DIR="$SCRIPT_DIR/src/pb2025_sentry_nav/point_lio/PCD"
SIM_MAP_DIR="$BRINGUP_DIR/map/simulation"
SIM_PCD_DIR="$BRINGUP_DIR/pcd/simulation"

NAMESPACE="${NAMESPACE:-red_standard_robot1}"
WORLD="${WORLD:-rmuc_2026}"
INSTALL_NAME="${INSTALL_NAME:-game}"
MAP_NAME="${MAP_NAME:-}"
SAVE_TIMEOUT="${SAVE_TIMEOUT:-20s}"
ROS_LOG_DIR="${ROS_LOG_DIR:-$SCRIPT_DIR/log/ros}"
GAZEBO_STARTUP_SECONDS="${GAZEBO_STARTUP_SECONDS:-8}"
SESSION_ID="$(date +%Y%m%d_%H%M%S)"
WORK_DIR="${WORK_DIR:-$SCRIPT_DIR/build/sim_slam_install/$SESSION_ID}"

if [[ $# -gt 0 && "$1" != *":="* ]]; then
  WORLD="$1"
  shift
fi

if [[ -z "$MAP_NAME" ]]; then
  MAP_NAME="$INSTALL_NAME"
fi

MAP_BASE="$WORK_DIR/$MAP_NAME"

launch_args=("$@")

log() {
  echo "[sim_slam_install] $*"
}

die() {
  echo "[sim_slam_install] ERROR: $*" >&2
  exit 1
}

source_ros() {
  if [[ -f "$SCRIPT_DIR/install/setup.bash" ]]; then
    set +u
    # shellcheck source=/dev/null
    source "$SCRIPT_DIR/install/setup.bash"
    set -u
  elif [[ -n "${ROS_DISTRO:-}" && -f "/opt/ros/$ROS_DISTRO/setup.bash" ]]; then
    set +u
    # shellcheck source=/dev/null
    source "/opt/ros/$ROS_DISTRO/setup.bash"
    set -u
  elif [[ -f /opt/ros/humble/setup.bash ]]; then
    set +u
    # shellcheck source=/dev/null
    source /opt/ros/humble/setup.bash
    set -u
  fi

  command -v ros2 >/dev/null 2>&1 || die "ros2 not found. Build/source the workspace first."
}

backup_if_exists() {
  local path="$1"
  if [[ -e "$path" ]]; then
    local backup="${path}.bak_${SESSION_ID}"
    mv "$path" "$backup"
    log "Backed up $path -> $backup"
  fi
}

install_file() {
  local src="$1"
  local dst="$2"
  [[ -f "$src" ]] || die "source file not found: $src"
  mkdir -p "$(dirname "$dst")"
  backup_if_exists "$dst"
  cp "$src" "$dst"
  log "Installed $src -> $dst"
}

rewrite_yaml_image() {
  local yaml_file="$1"
  local image_name="$2"

  if grep -Eq '^[[:space:]]*image[[:space:]]*:' "$yaml_file"; then
    sed -i -E "s#^([[:space:]]*image[[:space:]]*:).*#\1 $image_name#" "$yaml_file"
  else
    printf '\nimage: %s\n' "$image_name" >> "$yaml_file"
  fi
  log "Updated YAML image field: $yaml_file -> $image_name"
}

call_save_map() {
  local service="/${NAMESPACE}/map_saver/save_map"
  local map_topic="/${NAMESPACE}/map"

  if [[ -z "$NAMESPACE" ]]; then
    service="/map_saver/save_map"
    map_topic="/map"
  fi

  mkdir -p "$WORK_DIR"
  log "Saving grid map via $service -> ${MAP_BASE}.pgm/.yaml"
  timeout "$SAVE_TIMEOUT" ros2 service call "$service" nav2_msgs/srv/SaveMap \
    "{map_topic: '$map_topic', map_url: '$MAP_BASE', image_format: 'pgm', map_mode: 'trinary', free_thresh: 0.25, occupied_thresh: 0.65}"
}

find_latest_pcd() {
  if [[ -f "$POINT_LIO_PCD_DIR/scans.pcd" ]]; then
    printf '%s\n' "$POINT_LIO_PCD_DIR/scans.pcd"
    return
  fi

  find "$POINT_LIO_PCD_DIR" -maxdepth 1 -type f -name '*.pcd' -printf '%T@ %p\n' \
    | sort -nr \
    | head -n 1 \
    | cut -d' ' -f2-
}

install_outputs() {
  local src_yaml="$MAP_BASE.yaml"
  local src_pgm="$MAP_BASE.pgm"
  local src_pcd
  src_pcd="$(find_latest_pcd)"

  [[ -f "$src_yaml" ]] || die "saved map yaml not found: $src_yaml"
  [[ -f "$src_pgm" ]] || die "saved map pgm not found: $src_pgm"
  [[ -n "$src_pcd" && -f "$src_pcd" ]] || die "no PCD found in $POINT_LIO_PCD_DIR"

  install_file "$src_yaml" "$SIM_MAP_DIR/$INSTALL_NAME.yaml"
  install_file "$src_pgm" "$SIM_MAP_DIR/$INSTALL_NAME.pgm"
  rewrite_yaml_image "$SIM_MAP_DIR/$INSTALL_NAME.yaml" "$INSTALL_NAME.pgm"

  # rm_navigation_simulation_launch.py defaults prior_pcd_file to pcd/simulation/scans.pcd.
  install_file "$src_pcd" "$SIM_PCD_DIR/scans.pcd"
  install_file "$src_pcd" "$SIM_PCD_DIR/$INSTALL_NAME.pcd"
}

cleanup() {
  trap - INT TERM EXIT

  log "Finishing simulation SLAM session..."
  call_save_map || log "Map save failed; will still try to stop launch and install existing outputs."

  if [[ -n "${slam_pid:-}" ]] && kill -0 "$slam_pid" 2>/dev/null; then
    log "Stopping simulation SLAM launch..."
    kill -INT "-$slam_pid" 2>/dev/null || true
    wait "$slam_pid" 2>/dev/null || true
  fi

  if [[ -n "${gazebo_pid:-}" ]] && kill -0 "$gazebo_pid" 2>/dev/null; then
    log "Stopping Gazebo launch..."
    kill -INT "-$gazebo_pid" 2>/dev/null || true
    wait "$gazebo_pid" 2>/dev/null || true
  fi

  install_outputs

  cat <<EOF

Done.

Simulation prior navigation can now be started with:
  ros2 launch pb2025_nav_bringup rm_navigation_simulation_launch.py world:=$INSTALL_NAME slam:=False

Installed:
  $SIM_MAP_DIR/$INSTALL_NAME.yaml
  $SIM_MAP_DIR/$INSTALL_NAME.pgm
  $SIM_PCD_DIR/scans.pcd
  $SIM_PCD_DIR/$INSTALL_NAME.pcd
EOF
}

source_ros
mkdir -p "$WORK_DIR" "$SIM_MAP_DIR" "$SIM_PCD_DIR" "$ROS_LOG_DIR"
export ROS_LOG_DIR

gazebo_cmd=(
  ros2 launch rmu_gazebo_simulator bringup_sim.launch.py
  world:="$WORLD"
)

slam_cmd=(
  ros2 launch pb2025_nav_bringup rm_navigation_simulation_launch.py
  world:="$WORLD"
  slam:=True
  namespace:="$NAMESPACE"
  auto_save_map:=False
  auto_save_pcd:=True
  "${launch_args[@]}"
)

log "Starting Gazebo world: $WORLD"
printf '[sim_slam_install] gazebo command:'
printf ' %q' "${gazebo_cmd[@]}"
printf '\n'

trap cleanup INT TERM

setsid "${gazebo_cmd[@]}" &
gazebo_pid=$!

log "Waiting ${GAZEBO_STARTUP_SECONDS}s for Gazebo startup..."
sleep "$GAZEBO_STARTUP_SECONDS"

log "Starting simulation SLAM. Press Ctrl+C after mapping is complete."
printf '[sim_slam_install] slam command:'
printf ' %q' "${slam_cmd[@]}"
printf '\n'

setsid "${slam_cmd[@]}" &
slam_pid=$!

set +e
wait "$slam_pid"
launch_status=$?
set -e
cleanup
exit "$launch_status"
