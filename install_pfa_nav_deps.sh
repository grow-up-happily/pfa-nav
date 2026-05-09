#!/usr/bin/env bash
set -euo pipefail

if [ "${EUID:-$(id -u)}" -eq 0 ]; then
  echo "Run this script as your normal user, not with sudo." >&2
  echo "It will ask for sudo only when installing system packages." >&2
  exit 1
fi

if ! grep -q 'VERSION_CODENAME=jammy' /etc/os-release; then
  echo "This script targets Ubuntu 22.04 Jammy for ROS 2 Humble." >&2
  exit 1
fi

SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd "$SCRIPT_DIR"

sudo apt-get update
sudo apt-get install -y \
  curl \
  gnupg \
  lsb-release \
  locales \
  software-properties-common

sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8

sudo add-apt-repository -y universe

ROS_APT_SOURCE_VERSION=$(
  curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest \
    | grep -F "tag_name" \
    | awk -F'"' '{print $4}'
)
ROS_APT_SOURCE_DEB=$(mktemp /tmp/ros2-apt-source.XXXXXX.deb)
trap 'rm -f "$ROS_APT_SOURCE_DEB"' EXIT
curl -L -o "$ROS_APT_SOURCE_DEB" \
  "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.jammy_all.deb"
sudo dpkg -i "$ROS_APT_SOURCE_DEB"

sudo apt-get update
sudo apt-get install -y \
  ros-humble-desktop \
  ros-dev-tools \
  python3-rosdep \
  python3-colcon-common-extensions \
  python3-pip \
  python3-vcstool \
  git-lfs \
  cmake \
  build-essential \
  libeigen3-dev \
  libomp-dev \
  libopencv-dev \
  libgoogle-glog-dev \
  libapr1-dev \
  libaprutil1-dev \
  libunwind-dev \
  libpcl-dev \
  libtbb-dev \
  python3-pytest \
  python3-serial \
  python3-yaml \
  python3-numpy \
  python3-packaging \
  qtbase5-dev \
  libqt5core5a \
  libqt5gui5 \
  libqt5widgets5 \
  ros-humble-navigation2 \
  ros-humble-nav2-bringup \
  ros-humble-nav2-smac-planner \
  ros-humble-slam-toolbox \
  ros-humble-serial-driver \
  ros-humble-joint-state-publisher \
  ros-humble-joy \
  ros-humble-pcl-ros \
  ros-humble-pcl-conversions \
  ros-humble-laser-geometry \
  ros-humble-tf2-sensor-msgs \
  ros-humble-tf2-eigen \
  ros-humble-image-transport \
  ros-humble-camera-info-manager \
  ros-humble-cv-bridge \
  ros-humble-ros-gz \
  ros-humble-ros-gz-bridge \
  ros-humble-ros-gz-sim \
  ros-humble-ament-cmake-black \
  ros-humble-ament-cmake-clang-format

python3 -m pip install --user --upgrade \
  vcstool2 \
  xmacro \
  jinja2 \
  typeguard

git lfs install --skip-repo

if ! sudo test -f /etc/ros/rosdep/sources.list.d/20-default.list; then
  sudo rosdep init
fi
rosdep update

set +u
source /opt/ros/humble/setup.bash
set -u
rosdep install -r --from-paths src --ignore-src --rosdistro humble -y --skip-keys pb2025_sentry_nav

echo "Dependencies installed. To build:"
echo "  cd $SCRIPT_DIR"
echo "  source /opt/ros/humble/setup.bash"
echo "  colcon build --symlink-install --parallel-workers 2 --cmake-args -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF"
