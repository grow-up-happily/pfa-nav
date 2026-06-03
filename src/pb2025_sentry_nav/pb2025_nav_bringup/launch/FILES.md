# src/pb2025_sentry_nav/pb2025_nav_bringup/launch 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav/pb2025_nav_bringup/launch` 这一层目录中的文件和子目录作用。

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `auto_save_map.launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 auto save map.launch 相关节点。 |
| `bringup_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 bringup launch 相关节点。 |
| `joy_teleop_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 joy teleop launch 相关节点。 |
| `localization_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 localization launch 相关节点。 |
| `navigation_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 navigation launch 相关节点。 |
| `rm_multi_navigation_simulation_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 rm multi navigation simulation launch 相关节点。 |
| `rm_navigation_reality_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 rm navigation reality launch 相关节点。 |
| `rm_navigation_simulation_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 rm navigation simulation launch 相关节点。 |
| `robot_state_publisher_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 robot state publisher launch 相关节点。 |
| `rviz_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 rviz launch 相关节点。 |
| `slam_launch.py` | 文件 | ROS 2 launch 启动脚本，用于启动 slam launch 相关节点。 |

## README / 实际调用状态

| Launch | 当前状态 | 说明 |
|---|---|---|
| `rm_navigation_simulation_launch.py` | 根 README 直接调用 | 仿真导航/建图入口；默认 `world=rmuc_2026`，README 示例覆盖成 `rmuc_2025`。 |
| `rm_navigation_reality_launch.py` | 根 README 直接调用 | 实车导航/建图入口；默认用 `config/reality/nav2_params.yaml`，README 实车建图示例传 `use_robot_state_pub:=True`。 |
| `rm_multi_navigation_simulation_launch.py` | 本目录 README 提到，根 README 未提 | 多机器人仿真入口，会按机器人列表 include 多个 `rm_navigation_simulation_launch.py`。 |
| `bringup_launch.py` | 内部主链 | 被仿真/实车入口 include；按 `slam` 选择 `slam_launch.py` 或 `localization_launch.py`，按 `enable_nav` 决定是否启动 `navigation_launch.py`。 |
| `slam_launch.py` | 条件调用 | `slam:=True` 时启动 `point_lio`、`slam_toolbox`、`pointcloud_to_laserscan`、`loam_interface`、`sensor_scan_generation` 等。 |
| `localization_launch.py` | 条件调用 | `slam:=False` 时启动 `point_lio`、`prior_pcd_publisher.py`、`small_gicp_relocalization`、`map_server` 等。 |
| `navigation_launch.py` | 条件调用 | `enable_nav:=True` 时启动 Nav2 导航栈和地形分析相关节点；默认会启动。 |
| `joy_teleop_launch.py` | 内部调用 | 被仿真/实车入口 include；README 参数表提到手柄参数在 `nav2_params.yaml` 中。 |
| `rviz_launch.py` | 条件调用 | `use_rviz:=True` 时启动，默认 True。 |
| `robot_state_publisher_launch.py` | 实车条件调用 | 只在 `rm_navigation_reality_launch.py` 中由 `use_robot_state_pub` 控制；默认 False。 |
| `auto_save_map.launch.py` | SLAM 条件调用 | 只在 `slam_launch.py` 中由 `auto_save_map` 控制；默认 True，但前提是进入 `slam:=True`。 |

## 参数状态

| 参数 | 当前用法 | 注意 |
|---|---|---|
| `params_file` | 仿真默认 `config/simulation/nav2_params.yaml`，实车默认 `config/reality/nav2_params.yaml` | 可用 launch 参数覆盖，手柄配置也随这个文件传给 `joy_teleop_launch.py`。 |
| `map` / `world` | 默认按 `map/<模式>/<world>.yaml` 拼路径 | 如果对应 YAML 不存在，直接启动会失败；测试时优先确认 `world` 和文件名一致。 |
| `prior_pcd_file` | 定位模式传给 `point_lio`、`prior_pcd_publisher.py`、`small_gicp_relocalization` | 仿真默认指向 `pcd/simulation/scans.pcd`，但当前仓库没有这个目录/文件；实车默认按 `pcd/reality/<world>.pcd` 拼。 |
| `auto_save_map` / `auto_save_pcd` | 只在 SLAM 链真正生效 | 普通 `slam:=False` 导航不会触发自动保存地图/PCD。 |
| `use_robot_state_pub` | 只影响实车入口 | README 实车建图示例设为 True；如果整车系统已有 robot_state_publisher，可保持 False。 |
| `use_rviz` / `use_composition` / `use_respawn` | 运行方式参数 | README 参数表有说明；不代表新文件被调用，只控制是否打开 RViz、是否组件化和崩溃重启策略。 |

## 当前未启用点

| 项 | 状态 | 说明 |
|---|---|---|
| `hero_lidar` 节点 | 当前未调用 | `rm_navigation_simulation_launch.py` 中相关 `Node(...)` 和 `ld.add_action(start_hero_lidar)` 都是注释状态。 |
| `loop_closure_3d` | 当前未接入 | 这层 launch 没有 include/启动 loop closure 包。 |
