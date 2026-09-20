#!/usr/bin/env bash
set -Eeuo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE="$(cd -- "$SCRIPT_DIR/.." && pwd)"
SERVICE_NAME="${SERVICE_NAME:-pfa-navigation.service}"
SERVICE_PATH="/etc/systemd/system/$SERVICE_NAME"
SERVICE_USER="${SERVICE_USER:-$(id -un)}"
START_NOW="${START_NOW:-0}"

for required in \
  "$WORKSPACE/nav.sh" \
  "$WORKSPACE/install/setup.bash" \
  "$WORKSPACE/src/pb2025_sentry_nav/pb2025_nav_bringup/map/reality/game.yaml" \
  "$WORKSPACE/src/pb2025_sentry_nav/point_lio/PCD/scans.pcd"; do
  if [[ ! -e "$required" ]]; then
    echo "ERROR: required file is missing: $required" >&2
    exit 1
  fi
done

chmod +x "$WORKSPACE/nav.sh" "$SCRIPT_DIR/start_navigation.sh"
tmp_service="$(mktemp)"
trap 'rm -f "$tmp_service"' EXIT
sed \
  -e "s|__USER__|$SERVICE_USER|g" \
  -e "s|__WORKSPACE__|$WORKSPACE|g" \
  "$SCRIPT_DIR/pfa-navigation.service" >"$tmp_service"

echo "[install_navigation] workspace: $WORKSPACE"
echo "[install_navigation] service user: $SERVICE_USER"
sudo install -m 0644 "$tmp_service" "$SERVICE_PATH"
sudo systemctl daemon-reload
sudo systemctl enable "$SERVICE_NAME"

if [[ "$START_NOW" == "1" ]]; then
  sudo systemctl restart "$SERVICE_NAME"
  echo "[install_navigation] installed, enabled, and started."
else
  echo "[install_navigation] installed and enabled; it will start on next boot."
fi
