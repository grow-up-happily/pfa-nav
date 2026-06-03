# src/wp_map_tools 文件说明

> 自动生成，用于快速了解 `src/wp_map_tools` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `icons` | 目录 | 图标资源目录。 |
| `include` | 目录 | C/C++ 头文件目录。 |
| `launch` | 目录 | ROS 2 launch 启动文件目录。 |
| `media` | 目录 | 项目子目录。 |
| `meshes` | 目录 | 机器人、传感器或场景模型网格目录。 |
| `msg` | 目录 | ROS 消息定义目录。 |
| `rviz` | 目录 | RViz 可视化配置目录。 |
| `scripts` | 目录 | 可执行脚本目录。 |
| `src` | 目录 | 源码目录。 |
| `srv` | 目录 | ROS 服务定义目录。 |

## README / 实际调用状态

| 项 | 当前状态 | 说明 |
|---|---|---|
| `launch/add_waypoint_reality.launch.py` | 根 README 直接调用 | 实车添加航点入口。 |
| `launch/add_waypoint_simulation.launch.py` | 根 README 直接调用 | 仿真添加航点入口。 |
| `src/wp_saver.cpp` / `wp_saver` | 根 README 直接调用 | README 用 `ros2 run wp_map_tools wp_saver --red/--blue` 保存航点。 |
| `rviz` / `icons` / `meshes` / `media` | 航点编辑工具资源 | launch/RViz 工具会用到，不是单独启动入口。 |
| `scripts` | 当前根 README 未直接调用 | 辅助脚本目录，按航点工具问题再查。 |
| `msg` / `srv` / `include` | 工具包接口/头文件 | 给本包插件和节点使用，README 不会单独调用。 |

## 当前未调用点

| 项 | 状态 | 说明 |
|---|---|---|
| `/hero_lidar/base_pose` 相关 RViz 工具 | 只在航点/位姿工具里出现 | 主导航 launch 当前没有启动 `hero_lidar` 节点；这些工具仍可用于手动设置 Hero 位姿。 |

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `.gitignore` | 文件 | Git 忽略规则，排除构建产物、缓存和临时文件。 |
| `CMakeLists.txt` | 文件 | CMake/ament 构建配置，定义包、依赖、目标和安装规则。（project：`wp_map_tools`）。 |
| `package.xml` | 文件 | ROS 2 包清单，声明包名、构建类型和依赖。（包名：`wp_map_tools`）。 |
| `plugins_description.xml` | 文件 | XML 配置/描述文件，用于 plugins description。 |
| `README.md` | 文件 | 当前目录或模块的说明文档。 |
