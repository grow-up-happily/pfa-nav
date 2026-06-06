#!/usr/bin/env bash
set -Eeuo pipefail

# Passive MID360 rosbag recorder.
# This does not start Livox driver, pfa-nav, Point-LIO, SLAM, Nav2, TF, or scans.pcd saving.
# Start it at boot; it waits for the normal real-robot launch to publish Livox topics.
#
# Typical use on the robot:
#   ./mid360_mapping_record.sh
#
# Useful overrides:
#   BAG_ROOT=/data/rosbags/mid360 ./mid360_mapping_record.sh
#   RECORD_MODE=minimal ./mid360_mapping_record.sh
#   RECORD_MODE=debug ./mid360_mapping_record.sh
#   RECORD_MODE=full ./mid360_mapping_record.sh
#   NAMESPACE=red_standard_robot1 ./mid360_mapping_record.sh
#   RECORD_TOPICS="/ns/livox/lidar /ns/livox/imu" ./mid360_mapping_record.sh

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd -- "$SCRIPT_DIR/.." && pwd)"

WORKSPACE="${WORKSPACE:-$REPO_ROOT}"
SETUP_FILE="${SETUP_FILE:-$WORKSPACE/install/setup.bash}"

BAG_ROOT="${BAG_ROOT:-$WORKSPACE/ros2_bag/mid360_pointcloud}"
BAG_NAME="${BAG_NAME:-mid360_pointcloud_$(date +%F_%H-%M-%S)}"
BAG_PATH="$BAG_ROOT/$BAG_NAME"

STORAGE_ID="${STORAGE_ID:-mcap}"
STORAGE_PRESET="${STORAGE_PRESET:-fastwrite}"
SPLIT_SECONDS="${SPLIT_SECONDS:-30}"
SPLIT_SIZE_BYTES="${SPLIT_SIZE_BYTES:-1073741824}"
CACHE_SIZE_BYTES="${CACHE_SIZE_BYTES:-67108864}"
TOPIC_WAIT_SECONDS="${TOPIC_WAIT_SECONDS:-0}"  # 0 means wait forever.
INCLUDE_UNPUBLISHED="${INCLUDE_UNPUBLISHED:-1}"
ROS_LOG_DIR="${ROS_LOG_DIR:-$WORKSPACE/log/ros}"
NAMESPACE="${NAMESPACE:-}"
# Recording profiles:
#   minimal: only raw Livox inputs needed to rebuild the map offline.
#   debug:   minimal + control output + TF, useful for post-match diagnosis. This is the default.
#   full:    record all ROS topics with `ros2 bag record -a`; use only for deep debugging.
RECORD_MODE="${RECORD_MODE:-debug}"

# Fine-grained overrides. Leave these empty in normal use so RECORD_MODE controls them.
RECORD_CMD_VEL="${RECORD_CMD_VEL:-}"       # auto, 1, or 0.
RECORD_TF="${RECORD_TF:-}"                 # 1 or 0.
RECORD_ALL_TOPICS="${RECORD_ALL_TOPICS:-}" # 1 records all topics.

normalize_namespace() {
  local ns="$1"
  ns="${ns#/}"
  ns="${ns%/}"
  printf '%s\n' "$ns"
}

source_ros() {
  if [[ -f "$SETUP_FILE" ]]; then
    set +u
    # shellcheck source=/dev/null
    source "$SETUP_FILE"
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

  if ! command -v ros2 >/dev/null 2>&1; then
    echo "ERROR: ros2 not found. Build/source the workspace or set SETUP_FILE." >&2
    exit 1
  fi
}

configure_record_mode() {
  # Convert the user-facing RECORD_MODE into concrete recording switches.
  # Explicit RECORD_CMD_VEL/RECORD_TF/RECORD_ALL_TOPICS env vars still win,
  # which makes one-off overrides possible without adding more modes.
  case "$RECORD_MODE" in
    minimal)
      # Smallest bag for offline mapping: raw point cloud + IMU only.
      RECORD_CMD_VEL="${RECORD_CMD_VEL:-0}"
      RECORD_TF="${RECORD_TF:-0}"
      RECORD_ALL_TOPICS="${RECORD_ALL_TOPICS:-0}"
      ;;
    debug)
      # Default match-day bag: still small, but keeps control output and TF
      # so navigation behavior can be diagnosed after replay.
      RECORD_CMD_VEL="${RECORD_CMD_VEL:-1}"
      RECORD_TF="${RECORD_TF:-1}"
      RECORD_ALL_TOPICS="${RECORD_ALL_TOPICS:-0}"
      ;;
    full)
      # Full ROS graph capture. This can grow quickly and should not be the
      # default on the robot unless disk space and CPU load have been checked.
      RECORD_CMD_VEL="${RECORD_CMD_VEL:-1}"
      RECORD_TF="${RECORD_TF:-1}"
      RECORD_ALL_TOPICS="${RECORD_ALL_TOPICS:-1}"
      ;;
    *)
      echo "ERROR: unsupported RECORD_MODE='$RECORD_MODE'. Use minimal, debug, or full." >&2
      exit 1
      ;;
  esac
}

sensor_topic_sets() {
  local ns
  ns="$(normalize_namespace "$NAMESPACE")"

  if [[ -n "$ns" ]]; then
    printf '/%s/livox/lidar /%s/livox/imu\n' "$ns" "$ns"
  fi

  printf '/livox/lidar /livox/imu\n'
}

topic_list_has_all() {
  local topic_list="$1"
  shift

  local topic
  for topic in "$@"; do
    if ! grep -Fxq "$topic" <<<"$topic_list"; then
      return 1
    fi
  done

  return 0
}

append_topic_if_missing() {
  local topic="$1"
  local existing

  for existing in "${topics[@]}"; do
    if [[ "$existing" == "$topic" ]]; then
      return 0
    fi
  done

  topics+=("$topic")
}

append_optional_topics() {
  local topic_list="$1"
  local ns topic
  ns="$(normalize_namespace "$NAMESPACE")"

  if [[ -n "${EXTRA_TOPICS:-}" ]]; then
    # shellcheck disable=SC2206
    local extra_topics=($EXTRA_TOPICS)
    for topic in "${extra_topics[@]}"; do
      append_topic_if_missing "$topic"
    done
  fi

  case "$RECORD_CMD_VEL" in
    0|false|False|FALSE|no|No|NO|off|Off|OFF)
      ;;
    auto)
      local cmd_vel_candidates=()
      if [[ -n "$ns" ]]; then
        cmd_vel_candidates+=(
          "/$ns/cmd_vel"
          "/$ns/cmd_vel_nav2_result"
          "/$ns/cmd_vel_controller"
        )
      fi
      cmd_vel_candidates+=("/cmd_vel" "/cmd_vel_nav2_result" "/cmd_vel_controller")

      for topic in "${cmd_vel_candidates[@]}"; do
        if grep -Fxq "$topic" <<<"$topic_list"; then
          append_topic_if_missing "$topic"
        fi
      done
      ;;
    *)
      if [[ -n "${CMD_VEL_TOPICS:-}" ]]; then
        # shellcheck disable=SC2206
        local cmd_vel_topics=($CMD_VEL_TOPICS)
        for topic in "${cmd_vel_topics[@]}"; do
          append_topic_if_missing "$topic"
        done
      else
        if [[ -n "$ns" ]]; then
          append_topic_if_missing "/$ns/cmd_vel"
          append_topic_if_missing "/$ns/cmd_vel_nav2_result"
          append_topic_if_missing "/$ns/cmd_vel_controller"
        fi
        append_topic_if_missing "/cmd_vel"
        append_topic_if_missing "/cmd_vel_nav2_result"
        append_topic_if_missing "/cmd_vel_controller"
      fi
      ;;
  esac

  case "$RECORD_TF" in
    1|true|True|TRUE|yes|Yes|YES|on|On|ON)
      append_topic_if_missing "/tf"
      append_topic_if_missing "/tf_static"
      ;;
  esac
}

resolve_record_topics() {
  local deadline topic_list topic_set

  if [[ "$TOPIC_WAIT_SECONDS" == "0" ]]; then
    deadline=0
  else
    deadline=$((SECONDS + TOPIC_WAIT_SECONDS))
  fi

  while true; do
    topic_list="$(ros2 topic list 2>/dev/null || true)"

    if [[ -n "${RECORD_TOPICS:-}" ]]; then
      # shellcheck disable=SC2206
      topics=($RECORD_TOPICS)
      if topic_list_has_all "$topic_list" "${topics[@]}"; then
        append_optional_topics "$topic_list"
        return 0
      fi
    else
      while IFS= read -r topic_set; do
        # shellcheck disable=SC2206
        local candidate_topics=($topic_set)
        if topic_list_has_all "$topic_list" "${candidate_topics[@]}"; then
          topics=("${candidate_topics[@]}")
          append_optional_topics "$topic_list"
          return 0
        fi
      done < <(sensor_topic_sets)
    fi

    if [[ "$deadline" != "0" && "$SECONDS" -ge "$deadline" ]]; then
      echo "WARN: did not see all sensor topics within ${TOPIC_WAIT_SECONDS}s; recording will still start with the first candidate set." >&2
      if [[ -n "${RECORD_TOPICS:-}" ]]; then
        # shellcheck disable=SC2206
        topics=($RECORD_TOPICS)
      else
        read -r topic_set < <(sensor_topic_sets)
        # shellcheck disable=SC2206
        topics=($topic_set)
      fi
      append_optional_topics "$topic_list"
      return 0
    fi

    sleep 1
  done
}

stop_children() {
  trap - EXIT INT TERM

  if [[ -n "${record_pid:-}" ]] && kill -0 "$record_pid" 2>/dev/null; then
    echo "[mid360_record] stopping rosbag..."
    kill -INT "$record_pid" 2>/dev/null || true
    wait "$record_pid" 2>/dev/null || true
  fi

  sync -f "$BAG_ROOT" 2>/dev/null || sync || true
}

handle_signal() {
  echo
  stop_children
  exit 130
}

source_ros
configure_record_mode
mkdir -p "$BAG_ROOT"
mkdir -p "$ROS_LOG_DIR"
export ROS_LOG_DIR

topics=()

echo "[mid360_record] workspace: $WORKSPACE"
echo "[mid360_record] bag: $BAG_PATH"
echo "[mid360_record] record mode: $RECORD_MODE"
echo "[mid360_record] namespace override: ${NAMESPACE:-<none>}"

trap stop_children EXIT
trap handle_signal INT TERM

resolve_record_topics

echo "[mid360_record] topics: ${topics[*]}"

record_cmd=(
  ros2 bag record
  -s "$STORAGE_ID"
  --storage-preset-profile "$STORAGE_PRESET"
  -d "$SPLIT_SECONDS"
  -b "$SPLIT_SIZE_BYTES"
  --max-cache-size "$CACHE_SIZE_BYTES"
)

if [[ "$INCLUDE_UNPUBLISHED" == "1" ]]; then
  record_cmd+=(--include-unpublished-topics)
fi

if [[ "$RECORD_ALL_TOPICS" == "1" ]]; then
  # Full mode ignores the explicit topic list and records the complete ROS graph.
  # We still resolved Livox topics above so recording starts only after the
  # normal robot stack is publishing sensor data.
  record_cmd+=(
    -a
    -o "$BAG_PATH"
  )
else
  # Minimal/debug modes record a bounded topic list to reduce disk pressure and
  # avoid affecting normal mapping/navigation.
  record_cmd+=(
    -o "$BAG_PATH"
    "${topics[@]}"
  )
fi

printf '[mid360_record] record command:'
printf ' %q' "${record_cmd[@]}"
printf '\n'
"${record_cmd[@]}" &
record_pid=$!

wait "$record_pid"
record_pid=""
