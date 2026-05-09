#!/usr/bin/env bash
set -Eeuo pipefail

# Safer ROS 2 bag recording for machines that may lose power directly.
# Usage:
#   ~/ros2_record_safe.sh /topic1 /topic2 /topic3
#   ~/ros2_record_safe.sh
#   RECORD_ALL=1 ~/ros2_record_safe.sh   # force all topics even with arguments

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

BAG_ROOT="${BAG_ROOT:-$SCRIPT_DIR/ros2_bag}"
BAG_NAME="${BAG_NAME:-run_$(date +%F_%H-%M-%S)}"
OUTPUT_DIR="$BAG_ROOT/$BAG_NAME"

STORAGE_ID="${STORAGE_ID:-mcap}"
STORAGE_PRESET="${STORAGE_PRESET:-fastwrite}"

SPLIT_SECONDS="${SPLIT_SECONDS:-5}"
SPLIT_SIZE_BYTES="${SPLIT_SIZE_BYTES:-268435456}"
CACHE_SIZE_BYTES="${CACHE_SIZE_BYTES:-16777216}"
SYNC_INTERVAL="${SYNC_INTERVAL:-1}"
STATS_RATE="${STATS_RATE:-1}"

REINDEX_ON_START="${REINDEX_ON_START:-1}"
RECORD_ALL="${RECORD_ALL:-0}"

source_ros() {
  if command -v ros2 >/dev/null 2>&1; then
    return
  fi

  if [[ -n "${ROS_SETUP:-}" ]]; then
    # shellcheck source=/dev/null
    source "$ROS_SETUP"
  elif [[ -n "${ROS_DISTRO:-}" && -f "/opt/ros/$ROS_DISTRO/setup.bash" ]]; then
    # shellcheck source=/dev/null
    source "/opt/ros/$ROS_DISTRO/setup.bash"
  else
    local setups=()
    shopt -s nullglob
    setups=(/opt/ros/*/setup.bash)
    shopt -u nullglob

    if ((${#setups[@]} > 0)); then
      # shellcheck source=/dev/null
      source "${setups[0]}"
    fi
  fi

  if ! command -v ros2 >/dev/null 2>&1; then
    echo "ERROR: ros2 command not found. Set ROS_SETUP=/opt/ros/<distro>/setup.bash first." >&2
    exit 1
  fi
}

reindex_old_bags() {
  [[ "$REINDEX_ON_START" == "1" ]] || return 0
  [[ -d "$BAG_ROOT" ]] || return 0

  while IFS= read -r -d '' bag_dir; do
    local has_bag_file=""
    has_bag_file="$(find "$bag_dir" -maxdepth 1 -type f \( -name '*.mcap' -o -name '*.db3' \) -print -quit)"
    [[ -f "$bag_dir/metadata.yaml" || -n "$has_bag_file" ]] || continue

    echo "Reindex old bag if needed: $bag_dir"
    ros2 bag reindex "$bag_dir" >/dev/null 2>&1 || true
  done < <(find "$BAG_ROOT" -mindepth 1 -maxdepth 1 -type d -print0)
}

sync_loop() {
  while true; do
    sync -f "$BAG_ROOT" 2>/dev/null || sync || true
    sleep "$SYNC_INTERVAL"
  done
}

stop_children() {
  if [[ -n "${record_pid:-}" ]] && kill -0 "$record_pid" 2>/dev/null; then
    kill -INT "$record_pid" 2>/dev/null || true
    wait "$record_pid" 2>/dev/null || true
  fi

  if [[ -n "${sync_pid:-}" ]] && kill -0 "$sync_pid" 2>/dev/null; then
    kill "$sync_pid" 2>/dev/null || true
    wait "$sync_pid" 2>/dev/null || true
  fi

  sync -f "$BAG_ROOT" 2>/dev/null || sync || true
}

handle_signal() {
  echo
  echo "Stopping ros2 bag record..."
  stop_children
  exit 130
}

source_ros
mkdir -p "$BAG_ROOT"
reindex_old_bags

if [[ "$RECORD_ALL" == "1" ]]; then
  RECORD_TARGETS=(-a)
elif (($# > 0)); then
  RECORD_TARGETS=("$@")
else
  RECORD_TARGETS=(-a)
fi

record_cmd=(
  ros2 bag record
  -s "$STORAGE_ID"
  --storage-preset-profile "$STORAGE_PRESET"
  -d "$SPLIT_SECONDS"
  -b "$SPLIT_SIZE_BYTES"
  --max-cache-size "$CACHE_SIZE_BYTES"
  --stats_max_publishing_rate "$STATS_RATE"
  -o "$OUTPUT_DIR"
  "${RECORD_TARGETS[@]}"
)

echo "Bag output: $OUTPUT_DIR"
echo "Record targets: ${RECORD_TARGETS[*]}"
printf 'Command:'
printf ' %q' "${record_cmd[@]}"
printf '\n'

trap stop_children EXIT
trap handle_signal INT TERM

sync_loop &
sync_pid=$!

"${record_cmd[@]}" &
record_pid=$!

set +e
wait "$record_pid"
record_status=$?
record_pid=""
set -e

exit "$record_status"
