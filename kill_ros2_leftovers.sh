#!/usr/bin/env bash
set -u

# Kill leftover ROS 2 processes for the current user.
# Usage:
#   ./kill_ros2_leftovers.sh
#   ./kill_ros2_leftovers.sh --dry-run
#   ./kill_ros2_leftovers.sh --include-sim --force

DRY_RUN=0
FORCE=0
INCLUDE_SIM=0
ALL_USERS=0
WAIT_SECS=3

usage() {
  cat <<'EOF'
Usage: kill_ros2_leftovers.sh [options]

Options:
  -n, --dry-run       Only print matched processes, do not kill them
  -f, --force         Send SIGKILL immediately instead of graceful shutdown
      --include-sim   Also match gazebo/gz/ign simulation processes
      --all-users     Match processes from all users, not only current user
  -w, --wait SECONDS  Wait time between graceful signals, default: 3
  -h, --help          Show this help

By default this script only kills current-user processes that look like ROS 2
leftovers: ros2 launch/run/bag, processes with --ros-args/__node remaps,
common Nav2/SLAM/TF/driver executables, and project-local ROS Python scripts.
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    -n|--dry-run)
      DRY_RUN=1
      shift
      ;;
    -f|--force)
      FORCE=1
      shift
      ;;
    --include-sim)
      INCLUDE_SIM=1
      shift
      ;;
    --all-users)
      ALL_USERS=1
      shift
      ;;
    -w|--wait)
      if [[ $# -lt 2 || ! "$2" =~ ^[0-9]+$ ]]; then
        echo "[kill_ros2] --wait requires a non-negative integer" >&2
        exit 2
      fi
      WAIT_SECS="$2"
      shift 2
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      echo "[kill_ros2] Unknown option: $1" >&2
      usage
      exit 2
      ;;
  esac
done

SCRIPT_PID=$$
SCRIPT_NAME=$(basename "$0")
WORKSPACE_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

source_if_exists() {
  local setup_file="$1"

  if [[ -f "$setup_file" ]]; then
    set +u
    # shellcheck disable=SC1090
    source "$setup_file"
    set -u
  fi
}

source_if_exists /opt/ros/humble/setup.bash
source_if_exists "${WORKSPACE_DIR}/install/setup.bash"

declare -a ROS_NODES=()
if command -v ros2 >/dev/null 2>&1; then
  mapfile -t ROS_NODES < <(ros2 node list 2>/dev/null | sed '/^[[:space:]]*$/d' | sort -u)
fi

declare -a PIDS=()
declare -A PID_ARGS=()

add_pid() {
  local pid="$1"
  local args="$2"

  [[ -z "$pid" ]] && return
  [[ "$pid" == "$SCRIPT_PID" ]] && return
  [[ "$args" == *"$SCRIPT_NAME"* ]] && return
  [[ -n "${PID_ARGS[$pid]:-}" ]] && return

  PIDS+=("$pid")
  PID_ARGS["$pid"]="$args"
}

match_known_ros_command() {
  local comm="$1"
  local args="$2"

  case "$comm" in
    ros2|rviz2|component_container|component_container_mt|robot_state_publisher|static_transform_publisher)
      return 0
      ;;
    lifecycle_manager|controller_server|planner_server|behavior_server|bt_navigator|waypoint_follower)
      return 0
      ;;
    map_server|map_saver|amcl|slam_toolbox|ekf_node|ukf_node)
      return 0
      ;;
  esac

  local patterns=(
    "ros2 launch"
    "ros2 run"
    "ros2 bag record"
    "ros2 bag play"
    "--ros-args"
    "__node:="
    "__ns:="
    "rclcpp_components"
    "nav2_"
    "tf2_ros"
    "point_lio"
    "pointlio"
    "livox_ros_driver"
    "mid360"
    "pb2025_nav_bringup"
    "hero_lidar"
    "auto_nav.py"
    "hp_nav.py"
    "hp_gimbal_nav.py"
    "goal_pose_publisher.py"
    "cmd_vel_to_gimbal.py"
    "cmd_to_gimbal.py"
    "mock_gimbal.py"
  )

  local pattern
  for pattern in "${patterns[@]}"; do
    [[ "$args" == *"$pattern"* ]] && return 0
  done

  if [[ "$INCLUDE_SIM" -eq 1 ]]; then
    case "$comm" in
      gazebo|gzserver|gzclient|ign|gz)
        return 0
        ;;
    esac
    [[ "$args" == *"ign gazebo"* || "$args" == *"gz sim"* || "$args" == *"gazebo_ros"* ]] && return 0
  fi

  return 1
}

match_ros_graph_node() {
  local comm="$1"
  local args="$2"
  local node base

  for node in "${ROS_NODES[@]}"; do
    base="${node##*/}"
    [[ -z "$base" ]] && continue

    if [[ "$comm" == "$base" ]]; then
      return 0
    fi

    if [[ "$args" == *"__node:=${base}"* || "$args" == *"name:=${base}"* ]]; then
      return 0
    fi
  done

  return 1
}

if [[ "$ALL_USERS" -eq 1 ]]; then
  PS_CMD=(ps -eo pid=,user=,comm=,args=)
else
  PS_CMD=(ps -u "$USER" -o pid=,user=,comm=,args=)
fi

while read -r pid proc_user comm args; do
  [[ -z "${pid:-}" || -z "${comm:-}" ]] && continue
  args="${args:-}"

  if match_known_ros_command "$comm" "$args" || match_ros_graph_node "$comm" "$args"; then
    add_pid "$pid" "$args"
  fi
done < <("${PS_CMD[@]}")

if [[ "${#PIDS[@]}" -eq 0 ]]; then
  echo "[kill_ros2] No ROS 2 leftover processes matched."
  if command -v ros2 >/dev/null 2>&1; then
    ros2 daemon stop >/dev/null 2>&1 || true
  fi
  exit 0
fi

echo "[kill_ros2] Matched ${#PIDS[@]} process(es):"
for pid in "${PIDS[@]}"; do
  printf '  PID %-8s %s\n' "$pid" "${PID_ARGS[$pid]}"
done

if [[ "$DRY_RUN" -eq 1 ]]; then
  echo "[kill_ros2] Dry run only. No process was killed."
  exit 0
fi

alive_pids() {
  local pid
  for pid in "$@"; do
    if kill -0 "$pid" 2>/dev/null; then
      printf '%s\n' "$pid"
    fi
  done
}

if [[ "$FORCE" -eq 1 ]]; then
  echo "[kill_ros2] Sending SIGKILL..."
  kill -KILL "${PIDS[@]}" 2>/dev/null || true
else
  echo "[kill_ros2] Sending SIGINT..."
  kill -INT "${PIDS[@]}" 2>/dev/null || true
  sleep "$WAIT_SECS"

  mapfile -t STILL_ALIVE < <(alive_pids "${PIDS[@]}")
  if [[ "${#STILL_ALIVE[@]}" -gt 0 ]]; then
    echo "[kill_ros2] Sending SIGTERM to ${#STILL_ALIVE[@]} remaining process(es)..."
    kill -TERM "${STILL_ALIVE[@]}" 2>/dev/null || true
    sleep "$WAIT_SECS"
  fi

  mapfile -t STILL_ALIVE < <(alive_pids "${PIDS[@]}")
  if [[ "${#STILL_ALIVE[@]}" -gt 0 ]]; then
    echo "[kill_ros2] Sending SIGKILL to ${#STILL_ALIVE[@]} stubborn process(es)..."
    kill -KILL "${STILL_ALIVE[@]}" 2>/dev/null || true
  fi
fi

if command -v ros2 >/dev/null 2>&1; then
  ros2 daemon stop >/dev/null 2>&1 || true
fi

sleep 1
mapfile -t STILL_ALIVE < <(alive_pids "${PIDS[@]}")
if [[ "${#STILL_ALIVE[@]}" -eq 0 ]]; then
  echo "[kill_ros2] Done. All matched processes exited."
else
  echo "[kill_ros2] Warning: ${#STILL_ALIVE[@]} process(es) are still alive:"
  for pid in "${STILL_ALIVE[@]}"; do
    printf '  PID %-8s %s\n' "$pid" "${PID_ARGS[$pid]}"
  done
  exit 1
fi
