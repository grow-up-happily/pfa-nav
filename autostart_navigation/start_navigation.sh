#!/usr/bin/env bash
set -Eeuo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE="$(cd -- "$SCRIPT_DIR/.." && pwd)"

# systemd has no graphical session, so RViz is intentionally disabled.
export WORKSPACE
export USE_RVIZ="${USE_RVIZ:-False}"
export NAMESPACE="${NAMESPACE:-}"

exec "$WORKSPACE/nav.sh"
