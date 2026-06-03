# src/pb2025_sentry_nav 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `fake_vel_transform` | 目录 | ROS 2 包目录：`fake_vel_transform`。 |
| `ign_sim_pointcloud_tool` | 目录 | ROS 2 包目录：`ign_sim_pointcloud_tool`。 |
| `livox_ros_driver2` | 目录 | ROS 2 包目录：`livox_ros_driver2`。 |
| `loam_interface` | 目录 | ROS 2 包目录：`loam_interface`。 |
| `loop_closure_3d` | 目录 | ROS 2 包目录：`loop_closure_3d`。 |
| `pb2025_nav_bringup` | 目录 | ROS 2 包目录：`pb2025_nav_bringup`。 |
| `pb_nav2_plugins` | 目录 | 导航相关目录。 |
| `pb_omni_pid_pursuit_controller` | 目录 | ROS 2 包目录：`pb_omni_pid_pursuit_controller`。 |
| `pb_teleop_twist_joy` | 目录 | ROS 2 包目录：`pb_teleop_twist_joy`。 |
| `point_lio` | 目录 | ROS 2 包目录：`point_lio`。 |
| `pointcloud_to_laserscan` | 目录 | ROS 2 包目录：`pointcloud_to_laserscan`。 |
| `sensor_scan_generation` | 目录 | ROS 2 包目录：`sensor_scan_generation`。 |
| `small_gicp_relocalization` | 目录 | ROS 2 包目录：`small_gicp_relocalization`。 |
| `terrain_analysis` | 目录 | ROS 2 包目录：`terrain_analysis`。 |
| `terrain_analysis_ext` | 目录 | ROS 2 包目录：`terrain_analysis_ext`。 |

## 主导航链调用状态

| 目录 | 当前状态 | 说明 |
|---|---|---|
| `pb2025_nav_bringup` | 主入口 | README 和本目录 README 的 `rm_navigation_*` 命令都从这里启动。 |
| `livox_ros_driver2` | 实车入口调用 | `rm_navigation_reality_launch.py` 直接启动 `livox_ros_driver2_node`；仿真不调用。 |
| `ign_sim_pointcloud_tool` | 仿真入口调用 | `rm_navigation_simulation_launch.py` 直接启动，用于仿真点云转换。 |
| `point_lio` | SLAM / 定位都会调用 | `slam_launch.py` 和 `localization_launch.py` 都直接启动 `pointlio_mapping`。 |
| `pointcloud_to_laserscan` / `slam_toolbox` | 仅 SLAM 模式调用 | `slam:=True` 时由 `slam_launch.py` 启动；普通定位导航不启动。 |
| `loam_interface` / `sensor_scan_generation` | SLAM / 定位都会调用 | 两个 launch 都会启动，用于里程计/扫描数据衔接。 |
| `small_gicp_relocalization` | 仅定位模式调用 | `slam:=False` 时由 `localization_launch.py` 启动，读取 `prior_pcd_file`。 |
| `terrain_analysis` / `terrain_analysis_ext` / `fake_vel_transform` | 导航模式调用 | `enable_nav:=True` 时由 `navigation_launch.py` 启动或加载。 |
| `pb_teleop_twist_joy` | 随主入口启动 | `joy_teleop_launch.py` 被仿真/实车入口 include。 |
| `pb_omni_pid_pursuit_controller` / `pb_nav2_plugins` | Nav2 参数间接调用 | 通过 `nav2_params.yaml` 的控制器和 costmap 插件加载，不是 launch 里直接 `Node(...)`。 |
| `loop_closure_3d` | 当前主流程未接入 | 有独立包和 README，但 `pb2025_nav_bringup` 的主 launch 链未 include/启动它。 |

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `README.md` | 文件 | 当前目录或模块的说明文档。 |
| `README_en.md` | 文件 | Markdown 文档：pb2025_sentry_nav。 |
