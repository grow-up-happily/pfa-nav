#!/usr/bin/env bash
set -Eeuo pipefail

WORKSPACE="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
START_NOW="${START_NOW:-0}"

START_NOW="$START_NOW" "$WORKSPACE/autostart_mid360_record/install_service.sh"
START_NOW="$START_NOW" "$WORKSPACE/autostart_navigation/install_service.sh"

echo "[install_boot_services] both services now point to: $WORKSPACE"
