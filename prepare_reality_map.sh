#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BRINGUP_DIR="$SCRIPT_DIR/src/pb2025_sentry_nav/pb2025_nav_bringup"
POINT_LIO_PCD_DIR="$SCRIPT_DIR/src/pb2025_sentry_nav/point_lio/PCD"
REALITY_MAP_DIR="$BRINGUP_DIR/map/reality"
REALITY_PCD_DIR="$BRINGUP_DIR/pcd/reality"

WORLD=""
MAP_NAME=""
MAP_INPUT_DIR="$PWD"
PCD_FILE=""
ACTION="move"
FORCE=false

usage() {
    cat <<EOF
Usage: $(basename "$0") <world> [options]

Prepare real-robot SLAM output for slam:=False navigation.

Options:
  -m, --map-name NAME   Saved map basename, without .yaml/.pgm. Defaults to <world>.
      --map-dir DIR     Directory containing the saved .yaml/.pgm. Defaults to current dir.
      --pcd FILE        PCD file to install. Defaults to point_lio/PCD/scans.pcd or scan.pcd.
      --copy            Copy files instead of moving them.
      --force           Overwrite existing target files.
  -h, --help            Show this help.

Examples:
  $(basename "$0") game
  $(basename "$0") game --map-name my_saved_map
  $(basename "$0") game --map-dir /tmp/maps --pcd src/pb2025_sentry_nav/point_lio/PCD/scans.pcd
EOF
}

die() {
    echo "Error: $*" >&2
    exit 1
}

log() {
    echo "[prepare_reality_map] $*"
}

real_path() {
    realpath -m "$1"
}

validate_name() {
    local label="$1"
    local value="$2"

    [[ "$value" =~ ^[A-Za-z0-9._-]+$ ]] || die "$label can only contain letters, numbers, dot, underscore, and dash: $value"
    [[ "$value" != "." && "$value" != ".." ]] || die "$label cannot be '.' or '..'"
}

resolve_pcd_file() {
    if [[ -n "$PCD_FILE" ]]; then
        echo "$PCD_FILE"
        return
    fi

    local candidates=(
        "$POINT_LIO_PCD_DIR/scans.pcd"
        "$POINT_LIO_PCD_DIR/scan.pcd"
        "$PWD/scans.pcd"
        "$PWD/scan.pcd"
    )

    local candidate
    for candidate in "${candidates[@]}"; do
        if [[ -f "$candidate" ]]; then
            echo "$candidate"
            return
        fi
    done

    die "No PCD file found. Pass --pcd /path/to/scans.pcd"
}

place_file() {
    local src="$1"
    local dst="$2"

    [[ -f "$src" ]] || die "source file not found: $src"
    mkdir -p "$(dirname "$dst")"

    local src_real
    local dst_real
    src_real="$(real_path "$src")"
    dst_real="$(real_path "$dst")"

    if [[ "$src_real" == "$dst_real" ]]; then
        log "Already in place: $dst"
        return
    fi

    if [[ -e "$dst" && "$FORCE" != true ]]; then
        die "target already exists: $dst (use --force to overwrite)"
    fi

    if [[ "$FORCE" == true ]]; then
        rm -f "$dst"
    fi

    if [[ "$ACTION" == "copy" ]]; then
        cp "$src" "$dst"
        log "Copied $src -> $dst"
    else
        mv "$src" "$dst"
        log "Moved $src -> $dst"
    fi
}

rewrite_yaml_image() {
    local yaml_file="$1"
    local image_file="$2"

    command -v python3 >/dev/null 2>&1 || die "python3 is required to update the YAML image field"

    python3 - "$yaml_file" "$image_file" <<'PY'
import re
import sys
from pathlib import Path

yaml_path = Path(sys.argv[1])
image_name = sys.argv[2]

lines = yaml_path.read_text(encoding="utf-8").splitlines(keepends=True)
pattern = re.compile(r"^(\s*)image\s*:")
updated = False

for i, line in enumerate(lines):
    match = pattern.match(line)
    if match:
        newline = "\n" if line.endswith("\n") else ""
        lines[i] = f"{match.group(1)}image: {image_name}{newline}"
        updated = True
        break

if not updated:
    if lines and not lines[-1].endswith("\n"):
        lines[-1] += "\n"
    lines.append(f"image: {image_name}\n")

yaml_path.write_text("".join(lines), encoding="utf-8")
PY

    log "Updated YAML image field: $yaml_file -> $image_file"
}

while [[ $# -gt 0 ]]; do
    case "$1" in
        -m|--map-name)
            [[ $# -ge 2 ]] || die "$1 requires a value"
            MAP_NAME="$2"
            shift 2
            ;;
        --map-dir)
            [[ $# -ge 2 ]] || die "$1 requires a value"
            MAP_INPUT_DIR="$2"
            shift 2
            ;;
        --pcd)
            [[ $# -ge 2 ]] || die "$1 requires a value"
            PCD_FILE="$2"
            shift 2
            ;;
        --copy)
            ACTION="copy"
            shift
            ;;
        --force)
            FORCE=true
            shift
            ;;
        -h|--help)
            usage
            exit 0
            ;;
        -*)
            die "unknown option: $1"
            ;;
        *)
            [[ -z "$WORLD" ]] || die "only one world name is allowed"
            WORLD="$1"
            shift
            ;;
    esac
done

[[ -n "$WORLD" ]] || { usage; exit 1; }
validate_name "world" "$WORLD"

if [[ -z "$MAP_NAME" ]]; then
    MAP_NAME="$WORLD"
fi
validate_name "map name" "$MAP_NAME"

MAP_YAML="$MAP_INPUT_DIR/$MAP_NAME.yaml"
MAP_PGM="$MAP_INPUT_DIR/$MAP_NAME.pgm"
PCD_SOURCE="$(resolve_pcd_file)"

DEST_YAML="$REALITY_MAP_DIR/$WORLD.yaml"
DEST_PGM="$REALITY_MAP_DIR/$WORLD.pgm"
DEST_PCD="$REALITY_PCD_DIR/$WORLD.pcd"

place_file "$MAP_YAML" "$DEST_YAML"
place_file "$MAP_PGM" "$DEST_PGM"
place_file "$PCD_SOURCE" "$DEST_PCD"
rewrite_yaml_image "$DEST_YAML" "$WORLD.pgm"

cat <<EOF

Done.

Reality navigation can now be started with:
  ros2 launch pb2025_nav_bringup rm_navigation_reality_launch.py world:=$WORLD slam:=False use_robot_state_pub:=True

No colcon build is required after this map/pcd move because the launch file reads these source-tree paths directly.
EOF
