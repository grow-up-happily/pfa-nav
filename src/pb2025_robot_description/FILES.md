# src/pb2025_robot_description 文件说明

> 自动生成，用于快速了解 `src/pb2025_robot_description` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `env-hooks` | 目录 | ROS/ament 环境钩子目录。 |
| `launch` | 目录 | ROS 2 launch 启动文件目录。 |
| `params` | 目录 | 项目子目录。 |
| `resource` | 目录 | ROS 包索引资源或模型资源目录。 |
| `rviz` | 目录 | RViz 可视化配置目录。 |

## README / 实际调用状态

| 项 | 当前状态 | 说明 |
|---|---|---|
| `launch/robot_description_launch.py` | 根 README 直接调用 | README 示例用它单独启动机器人描述。 |
| `robot_state_publisher_launch.py` | 实车导航条件调用 | `pb2025_nav_bringup/rm_navigation_reality_launch.py` 在 `use_robot_state_pub:=True` 时 include。 |
| `params` / 机器人描述资源 | 调传感器位姿时需要读 | Wiki 提到倒置/倾斜安装 LiDAR 时应改 robot description / SDF/Xacro 里的固连位姿，而不是改 Livox JSON 的 roll/pitch/yaw。 |
| `dependencies.repos` / `env-hooks` | 构建/环境资源 | README 主运行命令不直接调用；按依赖安装或环境问题再查。 |

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `.gitignore` | 文件 | Git 忽略规则，排除构建产物、缓存和临时文件。 |
| `CMakeLists.txt` | 文件 | CMake/ament 构建配置，定义包、依赖、目标和安装规则。（project：`pb2025_robot_description`）。 |
| `dependencies.repos` | 文件 | vcs/rosinstall 依赖仓库清单。 |
| `package.xml` | 文件 | ROS 2 包清单，声明包名、构建类型和依赖。（包名：`pb2025_robot_description`）。 |
| `README.md` | 文件 | 当前目录或模块的说明文档。 |
