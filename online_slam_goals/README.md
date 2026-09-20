# 在线建图导航点

- `simulation/`：仿真录制和使用的目标点。
- `reality/`：实车录制和使用的目标点。
- `simulation/routes/`：由仿真单点编排出的顺序路线。
- `reality/routes/`：由实车单点编排出的顺序路线。

目标文件使用 JSON 格式，坐标默认记录在 `odom` 坐标系中。两个环境的文件不要混用。

## 目标管理 GUI 用法

以下命令都在项目根目录执行：

```bash
cd /home/pfa/sight/new/pfa-nav
source /opt/ros/humble/setup.bash
source install/setup.bash
```

GUI 的模式不是由单独的 `--simulation` 或 `--reality` 参数选择，而是由时间源、目标目录和启动门控参数共同决定。

### 仿真模式

先启动 Gazebo 和在线建图，再打开 GUI：

```bash
# 终端 1
ros2 launch rmu_gazebo_simulator bringup_sim.launch.py

# 终端 2
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch pb2025_nav_bringup rm_navigation_simulation_launch.py slam:=True

# 终端 3
source /opt/ros/humble/setup.bash
source install/setup.bash
python3 auto_nav/online_slam_goal_gui.py \
  --namespace red_standard_robot1 \
  --use-sim-time true \
  --start-mode immediate \
  --goal-dir online_slam_goals/simulation
```

这些也是 GUI 的默认值，因此终端 3 可以简写为：

```bash
python3 auto_nav/online_slam_goal_gui.py
```

### 实车正式比赛模式

推荐使用一键脚本，它会同时启动实车在线建图、Nav2、RViz 和配置好的 GUI：

```bash
./auto_nav/start_reality_online_slam_nav.sh
```

该模式使用系统时间和 `reality/` 目录，并等待裁判系统发布 `game_progress=RUNNING(4)` 后才发送目标。默认比赛状态话题是 `/referee/game_status`，话题不同时使用：

```bash
./auto_nav/start_reality_online_slam_nav.sh \
  --game-status-topic /实际的比赛状态话题
```

如果实车导航已经由其他命令启动，只单独打开正式比赛模式 GUI，可使用等价命令：

```bash
python3 auto_nav/online_slam_goal_gui.py \
  --namespace '' \
  --use-sim-time false \
  --start-mode referee \
  --game-status-topic /referee/game_status \
  --goal-dir online_slam_goals/reality
```

### 实车测试模式

实车测试会绕过裁判系统门控，因此必须显式使用 `--test-mode`。GUI 在开始移动前还会弹出安全确认：

```bash
./auto_nav/start_reality_online_slam_nav.sh --test-mode
```

如果实车导航已经由其他命令启动，只单独打开测试模式 GUI，可使用等价命令：

```bash
python3 auto_nav/online_slam_goal_gui.py \
  --namespace '' \
  --use-sim-time false \
  --start-mode immediate \
  --confirm-before-start \
  --goal-dir online_slam_goals/reality
```

### 自动执行已保存目标或路线

GUI 参数使用 `--auto-goal` 和 `--auto-route`，名称可以省略 `.json`：

```bash
# 仿真目标
python3 auto_nav/online_slam_goal_gui.py --auto-goal 1

# 仿真路线
python3 auto_nav/online_slam_goal_gui.py --auto-route route_20260916_164513

# 实车测试目标或路线
./auto_nav/start_reality_online_slam_nav.sh --test-mode --goal home_point
./auto_nav/start_reality_online_slam_nav.sh --test-mode --route outbound_route

# 正式比赛目标或路线：等待 RUNNING 后执行
./auto_nav/start_reality_online_slam_nav.sh --goal home_point
./auto_nav/start_reality_online_slam_nav.sh --route outbound_route
```

`--auto-goal` 和 `--auto-route` 不能同时使用。

### 查看已保存内容

```bash
# 仿真
python3 auto_nav/online_slam_goal_gui.py --list-goals
python3 auto_nav/online_slam_goal_gui.py --list-routes

# 实车
./auto_nav/start_reality_online_slam_nav.sh --list-goals
./auto_nav/start_reality_online_slam_nav.sh --list-routes
```

### GUI 模式参数对照

| 模式 | `--namespace` | `--use-sim-time` | `--start-mode` | `--confirm-before-start` | `--goal-dir` |
| --- | --- | --- | --- | --- | --- |
| 仿真 | `red_standard_robot1` | `true` | `immediate` | 不需要 | `online_slam_goals/simulation` |
| 实车正式比赛 | 空字符串 | `false` | `referee` | 不需要 | `online_slam_goals/reality` |
| 实车测试 | 空字符串 | `false` | `immediate` | 必须使用 | `online_slam_goals/reality` |

GUI 中可以录入并导航、只录入目标点、使用已保存目标、编排顺序路线，以及执行已保存路线。录点时在 RViz 中使用 `Publish Point`；RViz 的 Fixed Frame 应为 `odom`。

关闭 GUI 窗口时，它会同步停止自己启动的目标节点；在启动 GUI 的终端按 `Ctrl+C` 也会执行相同清理，不会留下持续输出日志的后台目标节点。

### `pb_rm_interfaces` 找不到

`pb_rm_interfaces/msg/GameStatus` 只用于实车正式比赛的裁判门控。仿真和实车测试的 `immediate` 模式不依赖该消息包。

正式比赛模式若提示 `No module named 'pb_rm_interfaces'`，说明当前终端没有加载已编译的工作空间：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
```

如果执行后仍找不到，重新编译接口包并再次加载工作空间：

```bash
colcon build --symlink-install --packages-select pb_rm_interfaces
source install/setup.bash
```

顺序路线统一使用 `pfa_online_slam_route/v1` 格式：

```json
{
  "format": "pfa_online_slam_route/v1",
  "name": "outbound_route",
  "frame": "odom",
  "waypoints": [
    {"name": "near", "x": 2.0, "y": 0.0, "yaw": 0.0},
    {"name": "middle", "x": 6.0, "y": 0.0, "yaw": 0.0},
    {"name": "target", "x": 9.0, "y": 0.0, "yaw": 0.0}
  ]
}
```

路线按照 `waypoints` 数组顺序执行。第一个点必须位于启动后能够规划的地图范围内，否则机器人没有移动，地图也无法继续扩展。
