#!/usr/bin/env bash
set -Eeuo pipefail

# 实车边建图边导航一键入口。
# 不指定 --goal/--route 时打开目标管理窗口；指定后自动加载对应任务。

AUTO_NAV_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd -- "$AUTO_NAV_DIR/.." && pwd)"
SETUP_FILE="$PROJECT_ROOT/install/setup.bash"
GOAL_GUI="$AUTO_NAV_DIR/online_slam_goal_gui.py"
GOAL_DIR="$PROJECT_ROOT/online_slam_goals/reality"

NAMESPACE=""
GOAL_NAME=""
ROUTE_NAME=""
USE_ROBOT_STATE_PUB="True"
USE_RVIZ="True"
LIST_GOALS=0
LIST_ROUTES=0
TEST_MODE=0
GAME_STATUS_TOPIC="/referee/game_status"
NAV_PID=""
TOOL_PID=""
CLEANED_UP=0

usage() {
    cat <<'EOF'
用法：
  ./auto_nav/start_reality_online_slam_nav.sh
  ./auto_nav/start_reality_online_slam_nav.sh --goal 目标名称
  ./auto_nav/start_reality_online_slam_nav.sh --route 路线名称

选项：
  --goal NAME                  自动使用 online_slam_goals/reality/NAME.json
  --route NAME                 自动执行 reality/routes/NAME.json 顺序路线
  --goal-dir DIR               改用其他目标保存目录
  --namespace NS               ROS 命名空间；实车默认留空
  --game-status-topic TOPIC    比赛状态话题，默认 /referee/game_status
  --test-mode                  实车测试专用：确认后绕过比赛开始门控
  --no-robot-state-publisher   不启动仓库内的 robot_state_publisher
  --no-rviz                    不启动 RViz
  --list-goals                 列出已保存目标并退出
  --list-routes                列出已保存路线并退出
  -h, --help                   显示帮助

示例：
  # 正式比赛：加载目标，但收到 RUNNING 前保持静止
  ./auto_nav/start_reality_online_slam_nav.sh --goal home_point

  # 实车测试：窗口二次确认后允许移动
  ./auto_nav/start_reality_online_slam_nav.sh --test-mode --goal home_point

  # 实车测试：按已编排路线逐点导航
  ./auto_nav/start_reality_online_slam_nav.sh --test-mode --route outbound_route
EOF
}

require_value() {
    if [[ $# -lt 2 || -z "$2" ]]; then
        echo "错误：$1 需要一个参数。" >&2
        usage >&2
        exit 2
    fi
}

while [[ $# -gt 0 ]]; do
    case "$1" in
        --goal)
            require_value "$@"
            GOAL_NAME="$2"
            shift 2
            ;;
        --route)
            require_value "$@"
            ROUTE_NAME="$2"
            shift 2
            ;;
        --goal-dir)
            require_value "$@"
            GOAL_DIR="$2"
            shift 2
            ;;
        --namespace)
            if [[ $# -lt 2 ]]; then
                echo "错误：--namespace 需要一个参数；空命名空间无需传此选项。" >&2
                exit 2
            fi
            NAMESPACE="${2#/}"
            NAMESPACE="${NAMESPACE%/}"
            shift 2
            ;;
        --game-status-topic)
            require_value "$@"
            GAME_STATUS_TOPIC="$2"
            shift 2
            ;;
        --test-mode)
            TEST_MODE=1
            shift
            ;;
        --no-robot-state-publisher)
            USE_ROBOT_STATE_PUB="False"
            shift
            ;;
        --no-rviz)
            USE_RVIZ="False"
            shift
            ;;
        --list-goals)
            LIST_GOALS=1
            shift
            ;;
        --list-routes)
            LIST_ROUTES=1
            shift
            ;;
        -h|--help)
            usage
            exit 0
            ;;
        *)
            echo "错误：未知参数 $1" >&2
            usage >&2
            exit 2
            ;;
    esac
done

GOAL_DIR="$(realpath -m -- "$GOAL_DIR")"

if [[ -n "$GOAL_NAME" && -n "$ROUTE_NAME" ]]; then
    echo "错误：--goal 和 --route 不能同时使用。" >&2
    exit 2
fi

if [[ "$LIST_GOALS" -eq 1 ]]; then
    if [[ ! -d "$GOAL_DIR" ]]; then
        echo "目标目录不存在：$GOAL_DIR"
        exit 0
    fi
    found=0
    for goal_file in "$GOAL_DIR"/*.json; do
        [[ -e "$goal_file" ]] || continue
        basename -- "$goal_file" .json
        found=1
    done
    if [[ "$found" -eq 0 ]]; then
        echo "当前没有已保存目标：$GOAL_DIR"
    fi
    exit 0
fi

if [[ "$LIST_ROUTES" -eq 1 ]]; then
    route_dir="$GOAL_DIR/routes"
    if [[ ! -d "$route_dir" ]]; then
        echo "当前没有已保存路线：online_slam_goals/reality/routes"
        exit 0
    fi
    found=0
    for route_file in "$route_dir"/*.json; do
        [[ -e "$route_file" ]] || continue
        basename -- "$route_file" .json
        found=1
    done
    if [[ "$found" -eq 0 ]]; then
        echo "当前没有已保存路线：online_slam_goals/reality/routes"
    fi
    exit 0
fi

if [[ ! -f "$SETUP_FILE" ]]; then
    echo "错误：找不到 $SETUP_FILE，请先编译工作空间。" >&2
    exit 1
fi
if [[ ! -f "$GOAL_GUI" ]]; then
    echo "错误：找不到目标管理工具 $GOAL_GUI" >&2
    exit 1
fi
if [[ -n "$GOAL_NAME" ]]; then
    GOAL_NAME="${GOAL_NAME%.json}"
    if [[ "$GOAL_NAME" == */* || ! -f "$GOAL_DIR/$GOAL_NAME.json" ]]; then
        echo "错误：找不到目标 $GOAL_DIR/$GOAL_NAME.json" >&2
        echo "可使用 --list-goals 查看目标名称。" >&2
        exit 1
    fi
fi
if [[ -n "$ROUTE_NAME" ]]; then
    ROUTE_NAME="${ROUTE_NAME%.json}"
    if [[ "$ROUTE_NAME" == */* || ! -f "$GOAL_DIR/routes/$ROUTE_NAME.json" ]]; then
        echo "错误：找不到路线 online_slam_goals/reality/routes/$ROUTE_NAME.json" >&2
        echo "可使用 --list-routes 查看路线名称。" >&2
        exit 1
    fi
fi
if [[ -z "${DISPLAY:-}" && -z "${WAYLAND_DISPLAY:-}" ]]; then
    echo "错误：当前没有图形桌面环境，无法打开 RViz 和目标管理窗口。" >&2
    exit 1
fi

set +u
source /opt/ros/humble/setup.bash
source "$SETUP_FILE"
set -u

cleanup() {
    local exit_code=$?
    if [[ "$CLEANED_UP" -eq 1 ]]; then
        return "$exit_code"
    fi
    CLEANED_UP=1
    trap - EXIT INT TERM

    echo
    echo "[实车在线导航] 正在关闭目标工具和导航节点……"
    if [[ -n "$TOOL_PID" ]]; then
        kill -INT -- "-$TOOL_PID" 2>/dev/null || true
    fi
    if [[ -n "$NAV_PID" ]]; then
        kill -INT -- "-$NAV_PID" 2>/dev/null || true
    fi
    [[ -z "$TOOL_PID" ]] || wait "$TOOL_PID" 2>/dev/null || true
    [[ -z "$NAV_PID" ]] || wait "$NAV_PID" 2>/dev/null || true
    return "$exit_code"
}
trap cleanup EXIT INT TERM

echo "[实车在线导航] 工作空间：$PROJECT_ROOT"
echo "[实车在线导航] ROS 命名空间：${NAMESPACE:-<空>}"
echo "[实车在线导航] 时间源：系统时间（use_sim_time=False）"
if [[ "$TEST_MODE" -eq 1 ]]; then
    echo "[实车在线导航] 模式：实车测试（窗口确认后允许移动）"
else
    echo "[实车在线导航] 模式：正式比赛（等待 $GAME_STATUS_TOPIC 的 RUNNING 状态）"
fi
if [[ -n "$GOAL_NAME" ]]; then
    echo "[实车在线导航] 自动目标：$GOAL_NAME"
elif [[ -n "$ROUTE_NAME" ]]; then
    echo "[实车在线导航] 自动路线：$ROUTE_NAME"
else
    echo "[实车在线导航] 未指定自动目标或路线，请在弹出的窗口中选择或录入。"
fi

setsid ros2 launch pb2025_nav_bringup rm_navigation_reality_launch.py \
    slam:=True \
    namespace:="$NAMESPACE" \
    use_sim_time:=False \
    use_robot_state_pub:="$USE_ROBOT_STATE_PUB" \
    use_rviz:="$USE_RVIZ" \
    rviz_fixed_frame:=odom &
NAV_PID=$!

tool_command=(
    python3 "$GOAL_GUI"
    --namespace "$NAMESPACE"
    --goal-dir "$GOAL_DIR"
    --use-sim-time false
    --game-status-topic "$GAME_STATUS_TOPIC"
)
if [[ "$TEST_MODE" -eq 1 ]]; then
    tool_command+=(--start-mode immediate --confirm-before-start)
else
    tool_command+=(--start-mode referee)
fi
if [[ -n "$GOAL_NAME" ]]; then
    tool_command+=(--auto-goal "$GOAL_NAME")
elif [[ -n "$ROUTE_NAME" ]]; then
    tool_command+=(--auto-route "$ROUTE_NAME")
fi

setsid "${tool_command[@]}" &
TOOL_PID=$!

sleep 1
if ! kill -0 "$NAV_PID" 2>/dev/null; then
    echo "错误：实车导航 launch 启动后立即退出，请检查上方日志。" >&2
    exit 1
fi
if ! kill -0 "$TOOL_PID" 2>/dev/null; then
    echo "错误：目标管理窗口启动失败，请检查上方日志。" >&2
    exit 1
fi

echo "[实车在线导航] 已全部启动。按 Ctrl+C 可统一关闭。"
wait "$NAV_PID"
