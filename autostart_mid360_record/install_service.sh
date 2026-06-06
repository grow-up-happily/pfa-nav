#!/usr/bin/env bash
set -Eeuo pipefail

# Install the passive MID360 recorder as a systemd service.
# The service file must contain absolute paths, so this installer generates
# those paths from the repository location where it is executed.

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE="$(cd -- "$SCRIPT_DIR/.." && pwd)"
SERVICE_NAME="${SERVICE_NAME:-mid360_mapping_record.service}"
SERVICE_PATH="/etc/systemd/system/$SERVICE_NAME"
RECORD_MODE="${RECORD_MODE:-debug}"
SERVICE_USER="${SERVICE_USER:-$(id -un)}"

if [[ ! -x "$SCRIPT_DIR/mid360_mapping_record.sh" ]]; then
  chmod +x "$SCRIPT_DIR/mid360_mapping_record.sh"
fi

tmp_service="$(mktemp)"
trap 'rm -f "$tmp_service"' EXIT

cat >"$tmp_service" <<EOF
[Unit]
Description=Passive MID360 rosbag recorder
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
User=$SERVICE_USER
WorkingDirectory=$WORKSPACE
Environment=WORKSPACE=$WORKSPACE
Environment=BAG_ROOT=$WORKSPACE/ros2_bag/mid360_pointcloud
Environment=ROS_LOG_DIR=$WORKSPACE/log/ros
Environment=RECORD_MODE=$RECORD_MODE
ExecStart=$SCRIPT_DIR/mid360_mapping_record.sh
Restart=on-failure
RestartSec=5
KillSignal=SIGINT
TimeoutStopSec=30

[Install]
WantedBy=multi-user.target
EOF

echo "[install_mid360_record] workspace: $WORKSPACE"
echo "[install_mid360_record] service user: $SERVICE_USER"
echo "[install_mid360_record] record mode: $RECORD_MODE"
echo "[install_mid360_record] installing: $SERVICE_PATH"

sudo cp "$tmp_service" "$SERVICE_PATH"
sudo systemctl daemon-reload
sudo systemctl enable --now "$SERVICE_NAME"

echo "[install_mid360_record] installed and started."
echo "[install_mid360_record] check status:"
echo "  systemctl status $SERVICE_NAME"
echo "  journalctl -u $SERVICE_NAME -f"
