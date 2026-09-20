#!/usr/bin/env bash

WORKSPACE="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
cd "$WORKSPACE" || exit 1
source /opt/ros/humble/setup.bash
source "$WORKSPACE/install/setup.bash"
exec bash
