# src 文件说明

> 自动生成，用于快速了解 `src` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `.github` | 目录 | GitHub 配置目录，通常存放 CI 工作流和仓库自动化配置。 |
| `auto_aim_interfaces` | 目录 | ROS 2 包目录：`auto_aim_interfaces`。 |
| `hero_lidar` | 目录 | ROS 2 包目录：`hero_lidar`。 |
| `joint_state_publisher` | 目录 | 项目子目录。 |
| `m-explore-ros2` | 目录 | 项目子目录。 |
| `pb2025_robot_description` | 目录 | ROS 2 包目录：`pb2025_robot_description`。 |
| `pb2025_sentry_nav` | 目录 | 导航相关目录。 |
| `pb_rm_interfaces` | 目录 | ROS 2 包目录：`pb_rm_interfaces`。 |
| `rmoss_core` | 目录 | 项目子目录。 |
| `rmoss_gazebo` | 目录 | Gazebo/Ignition 仿真相关目录。 |
| `rmoss_gz_resources` | 目录 | ROS 2 包目录：`rmoss_gz_resources`。 |
| `rmoss_interfaces` | 目录 | ROS 2 包目录：`rmoss_interfaces`。 |
| `rmu_gazebo_simulator` | 目录 | Gazebo/Ignition 仿真相关目录。 |
| `sdformat_tools` | 目录 | ROS 2 包目录：`sdformat_tools`。 |
| `small_gicp` | 目录 | ROS 2 包目录：`small_gicp`。 |
| `wp_map_tools` | 目录 | ROS 2 包目录：`wp_map_tools`。 |

## README / 实际调用状态

| 目录 | 当前状态 | 说明 |
|---|---|---|
| `pb2025_sentry_nav` | 主导航代码 | README 的仿真/实车导航命令最终进入这里的 `pb2025_nav_bringup`。 |
| `rmu_gazebo_simulator` | README 仿真入口 | 根 README 直接调用 `ros2 launch rmu_gazebo_simulator bringup_sim.launch.py`。 |
| `pb2025_robot_description` | README 直接入口 + 实车条件入口 | README 可单独启动机器人描述；实车导航在 `use_robot_state_pub:=True` 时也会间接启动。 |
| `wp_map_tools` | README 航点工具入口 | README 直接调用 `add_waypoint_*` launch 和 `wp_saver`。 |
| `rmoss_core` / `rmoss_gazebo` / `rmoss_gz_resources` / `rmoss_interfaces` | 仿真支撑依赖 | README 不逐个点名，但 `rmu_gazebo_simulator` 和仿真控制链会用到，不属于未用目录。 |
| `small_gicp` | 定位依赖 | `small_gicp_relocalization` 依赖它；不要当作未调用的普通目录删。 |
| `hero_lidar` | 当前主流程未启用 | `rm_navigation_simulation_launch.py` 里有 `hero_lidar` 节点代码，但 `ld.add_action(start_hero_lidar)` 是注释状态；仅 `wp_map_tools`/部分手动脚本还引用 `/hero_lidar/base_pose`。 |
| `m-explore-ros2` | 当前主 README / 主 launch 未接入 | 自带探索/地图融合 demo，当前导航主流程没有 include 它。 |
| `auto_aim_interfaces` / `pb_rm_interfaces` | 接口包，当前主 README 未直接调用 | 可能给外部模块或旧流程使用；只是不在 README 主启动链里。 |
| `joint_state_publisher` / `sdformat_tools` | 工具/依赖包 | 不是 README 的人工阅读重点；按构建或仿真报错再查。 |

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `.gitignore` | 文件 | Git 忽略规则，排除构建产物、缓存和临时文件。 |
| `.gitmodules` | 文件 | 项目文件，用于 .gitmodules。 |
| `.pre-commit-config.yaml` | 文件 | YAML 数据/配置文件，用于 .pre commit config。 |
