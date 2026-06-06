#!/usr/bin/env bash
set -Eeuo pipefail

# One-key Gazebo + simulation prior-navigation helper.
# Starts a Gazebo competition world, then starts pb2025 simulation navigation
# using the installed prior map, defaulting to world:=game.

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

GAZEBO_WORLD="${GAZEBO_WORLD:-rmuc_2026}"
NAV_WORLD="${NAV_WORLD:-game}"
NAMESPACE="${NAMESPACE:-red_standard_robot1}"
GAZEBO_STARTUP_SECONDS="${GAZEBO_STARTUP_SECONDS:-8}"
ROS_LOG_DIR="${ROS_LOG_DIR:-$SCRIPT_DIR/log/ros}"

if [[ $# -gt 0 && "$1" != *":="* ]]; then
  GAZEBO_WORLD="$1"
  shift
fi

nav_args=("$@")

log() {
  echo "[sim_prior_nav] $*"
}

die() {
  echo "[sim_prior_nav] ERROR: $*" >&2
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

cleanup() {
  trap - INT TERM EXIT

  if [[ -n "${nav_pid:-}" ]] && kill -0 "$nav_pid" 2>/dev/null; then
    log "Stopping prior navigation launch..."
    kill -INT "-$nav_pid" 2>/dev/null || true
    wait "$nav_pid" 2>/dev/null || true
  fi

  if [[ -n "${gazebo_pid:-}" ]] && kill -0 "$gazebo_pid" 2>/dev/null; then
    log "Stopping Gazebo launch..."
    kill -INT "-$gazebo_pid" 2>/dev/null || true
    wait "$gazebo_pid" 2>/dev/null || true
  fi
}

source_ros
mkdir -p "$ROS_LOG_DIR"
export ROS_LOG_DIR

gazebo_cmd=(
  ros2 launch rmu_gazebo_simulator bringup_sim.launch.py
  world:="$GAZEBO_WORLD"
)

nav_cmd=(
  ros2 launch pb2025_nav_bringup rm_navigation_simulation_launch.py
  world:="$NAV_WORLD"
  slam:=False
  namespace:="$NAMESPACE"
  "${nav_args[@]}"
)

log "Starting Gazebo world: $GAZEBO_WORLD"
printf '[sim_prior_nav] gazebo command:'
printf ' %q' "${gazebo_cmd[@]}"
printf '\n'

trap cleanup INT TERM

setsid "${gazebo_cmd[@]}" &
gazebo_pid=$!

log "Waiting ${GAZEBO_STARTUP_SECONDS}s for Gazebo startup..."
sleep "$GAZEBO_STARTUP_SECONDS"

log "Starting simulation prior navigation with map world: $NAV_WORLD"
printf '[sim_prior_nav] nav command:'
printf ' %q' "${nav_cmd[@]}"
printf '\n'

setsid "${nav_cmd[@]}" &
nav_pid=$!

set +e
wait "$nav_pid"
nav_status=$?
set -e
cleanup
exit "$nav_status"
