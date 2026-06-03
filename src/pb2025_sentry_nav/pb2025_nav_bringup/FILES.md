# src/pb2025_sentry_nav/pb2025_nav_bringup 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav/pb2025_nav_bringup` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `behavior_trees` | 目录 | Nav2 行为树 XML 配置目录。 |
| `config` | 目录 | 运行参数和节点配置目录。 |
| `launch` | 目录 | ROS 2 launch 启动文件目录。 |
| `map` | 目录 | 二维栅格地图资源目录。 |
| `pcd` | 目录 | 三维点云地图或点云数据目录。 |
| `rviz` | 目录 | RViz 可视化配置目录。 |
| `scripts` | 目录 | 可执行脚本目录。 |

## README / 实际调用状态

| 项 | 当前状态 | 说明 |
|---|---|---|
| `launch` | 主阅读入口 | README 的 `rm_navigation_simulation_launch.py`、`rm_navigation_reality_launch.py` 和多车仿真入口都在这里。 |
| `config` | 主参数目录 | `params_file` 默认指向 `config/simulation/nav2_params.yaml` 或 `config/reality/nav2_params.yaml`。 |
| `map` | 由 `map` / `world` 参数决定 | `world:=xxx` 会默认拼成 `map/<simulation|reality>/xxx.yaml`，也可以用 `map:=完整路径` 覆盖。 |
| `pcd` | 由 `prior_pcd_file` 参数决定 | 定位模式会把该文件传给 `point_lio`、`prior_pcd_publisher.py` 和 `small_gicp_relocalization`。 |
| `scripts/prior_pcd_publisher.py` | 已被调用 | `localization_launch.py` 直接启动它，不是闲置脚本。 |
| `behavior_trees` | Nav2 参数间接调用 | 由 `nav2_params.yaml` 中 BT Navigator 的 XML 路径使用，launch 不会直接启动。 |
| `rviz` | 条件调用 | `use_rviz:=True` 时通过 `rviz_launch.py` 打开 `nav2_default_view.rviz`。 |

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `CMakeLists.txt` | 文件 | CMake/ament 构建配置，定义包、依赖、目标和安装规则。（project：`pb2025_nav_bringup`）。 |
| `package.xml` | 文件 | ROS 2 包清单，声明包名、构建类型和依赖。（包名：`pb2025_nav_bringup`）。 |
