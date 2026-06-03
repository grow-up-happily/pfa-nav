# src/rmu_gazebo_simulator 文件说明

> 自动生成，用于快速了解 `src/rmu_gazebo_simulator` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `.github` | 目录 | GitHub 配置目录，通常存放 CI 工作流和仓库自动化配置。 |
| `rmu_gazebo_simulator` | 目录 | ROS 2 包目录：`rmu_gazebo_simulator`。 |
| `scripts` | 目录 | 可执行脚本目录。 |

## README / 实际调用状态

| 项 | 当前状态 | 说明 |
|---|---|---|
| `rmu_gazebo_simulator/launch/bringup_sim.launch.py` | 根 README 直接调用 | 仿真启动入口；会继续组织 Gazebo、机器人生成、裁判系统等 launch。 |
| `rmu_gazebo_simulator/launch/gazebo.launch.py` / `spawn_robots.launch.py` / `referee_system.launch.py` / `rviz.launch.py` | 内部或按需入口 | README 主流程不要求逐个手动跑，通常由 bringup 或调试流程触发。 |
| `scripts/sim.sh` | 手动包装入口 | 只是包装 `ros2 launch rmu_gazebo_simulator bringup_sim.launch.py`。 |
| `scripts/player_web` / `scripts/referee_web` | 独立 Web/裁判辅助工具 | 不属于默认导航启动链；需要调裁判/网页显示时再读。 |
| `Dockerfile` / `dependencies.repos` | 环境/依赖资源 | Ubuntu 22.04 本机测试不一定使用 Docker；按依赖缺失再查。 |

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `.gitignore` | 文件 | Git 忽略规则，排除构建产物、缓存和临时文件。 |
| `.pre-commit-config.yaml` | 文件 | YAML 数据/配置文件，用于 .pre commit config。 |
| `dependencies.repos` | 文件 | vcs/rosinstall 依赖仓库清单。 |
| `Dockerfile` | 文件 | Docker 镜像构建脚本。 |
| `LICENSE` | 文件 | 许可证文本。 |
| `README.md` | 文件 | 当前目录或模块的说明文档。 |
