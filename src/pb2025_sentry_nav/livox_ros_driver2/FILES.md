# src/pb2025_sentry_nav/livox_ros_driver2 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav/livox_ros_driver2` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `3rdparty` | 目录 | 项目子目录。 |
| `cmake` | 目录 | CMake 包配置和查找脚本目录。 |
| `config` | 目录 | 运行参数和节点配置目录。 |
| `launch` | 目录 | ROS 2 launch 启动文件目录。 |
| `Livox-SDK2` | 目录 | 项目子目录。 |
| `msg` | 目录 | ROS 消息定义目录。 |
| `src` | 目录 | 源码目录。 |

## README / 实际调用状态

| 项 | 当前状态 | 说明 |
|---|---|---|
| `livox_ros_driver2_node` | 实车入口已调用 | `pb2025_nav_bringup/launch/rm_navigation_reality_launch.py` 直接启动它。 |
| `launch` | 独立调试入口 | Livox 自带 launch 可用于单独调雷达；当前主导航实车入口不是 include 这里的 launch，而是直接起节点。 |
| `config` | 实车参数间接使用 | `pb2025_nav_bringup/config/reality/nav2_params.yaml` 指向 `mid360_user_config.json`；根 README 要求在该 JSON 配雷达和本机 IP。 |
| `Livox-SDK2` / `3rdparty` | 构建依赖 | README 主流程不直接读，但驱动构建/运行依赖它们。 |

## 当前未调用点

| 项 | 状态 | 说明 |
|---|---|---|
| 仿真流程 | 不调用 | `rm_navigation_simulation_launch.py` 用的是 `ign_sim_pointcloud_tool`，不会启动 Livox 驱动。 |

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `CHANGELOG.md` | 文件 | Markdown 文档：Changelog。 |
| `CMakeLists.txt` | 文件 | CMake/ament 构建配置，定义包、依赖、目标和安装规则。（project：`livox_ros_driver2`）。 |
| `LICENSE.txt` | 文件 | 文本数据或日志文件，用于 LICENSE。 |
| `package.xml` | 文件 | ROS 2 包清单，声明包名、构建类型和依赖。（包名：`livox_ros_driver2`）。 |
| `README.md` | 文件 | 当前目录或模块的说明文档。 |
