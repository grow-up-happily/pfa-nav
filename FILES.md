# . 文件说明

> 自动生成，用于快速了解 `.` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `.vscode` | 目录 | VS Code 工作区配置目录。 |
| `docs` | 目录 | 项目文档目录。 |
| `images` | 目录 | 图片资源目录。 |
| `pb2025_sentry_nav.wiki` | 目录 | 项目 Wiki 文档目录。 |
| `src` | 目录 | 源码目录。 |

## 根目录脚本去留建议

### README / 代码调用状态

| 文件或脚本组 | 当前状态 | 说明 |
|---|---|---|
1| `README.md` 中的主流程 | 直接调用 ROS 入口 | README 直接使用 `rmu_gazebo_simulator`、`pb2025_nav_bringup`、`wp_map_tools` 等 ROS launch/run 命令；不会自动执行根目录 Python 脚本。 |

2| `build.sh` / `nav.sh` / `slam.sh` | 手动包装入口 | 内部会调用 `pb2025_nav_bringup` launch；README 没要求必须通过这些脚本启动，测试 Ubuntu 时可直接跑 README 命令。 |

3| `save.sh` | 当前主 README 未直接调用 | README 使用 `nav2_map_server map_saver_cli` 保存地图；`save.sh` 也是保存地图包装脚本，但路径仍有硬编码。 |

4| `start.sh` | 当前主 README 未调用 | 只做 `cd ~/project/pfa-nav` 和 source 环境，路径固定，换机器测试前不要当通用入口。 |

5| `game.py` | README 提到但不自动调用 | README 提醒要改 `ActionClient` 话题；实际需要手动 `python3 game.py ...` 运行，不在 ROS launch 链里。 |

6| `auto_nav.py` / `auto_nav_su.py` / `nav.py` / `goal_pose_publisher.py` | 当前主 README / launch 未自动调用 | 都是手动导航脚本；`test_auto_nav.py` 只测试 `auto_nav.py` 的部分逻辑。 |

7| `game_sim.py` / `hp_nav.py` / `hp_gimbal_nav.py` / `send.py` / `cmd_vel_to_gimbal.py` / `cmd_to_gimbal.py` / `mock_gimbal.py` | 当前主 README / launch 未自动调用 | 属于手动运行或串口/云台调试工具；不要因为未进 launch 就直接删，先按实车调试需求确认。 |

8| `auto_align_map.py` / `hero_to_sentry_map_converter.py` / `convert_lidar_pose_pcd.py` | 离线工具 | 地图/点云转换工具，不属于导航启动链；只在转换地图或修正雷达位姿时读。 |

9| `waypoints.yaml` | 被手动脚本和 `wp_map_tools` 使用 | `game.py`、`nav.py`、`auto_nav*.py`、`hp*.py` 默认读它；`wp_map_tools` 保存/编辑航点也会涉及。 |

10| `true_pram.yaml` / `test.yaml` / `test.pgm` | 当前主 launch 未使用 | 更像历史参数快照和测试地图；正式导航默认参数在 `src/pb2025_sentry_nav/pb2025_nav_bringup/config/` 下。 |


### 保留优先

| 脚本 | 原因 |
|---|---|
| `install_pfa_nav_deps.sh` | Ubuntu 22.04 / ROS 2 Humble 依赖安装入口。 |

| `auto_nav_su.py` | 当前功能最完整的航点导航脚本，含红蓝航点、裁判控制、直线/基地校准等扩展逻辑。 |

| `cmd_vel_to_gimbal.py` | 独立的 `/cmd_vel` 到云台串口协议桥，功能清晰。 |

| `hp_gimbal_nav.py` | 整合低血量导航和云台串口发送；若实车需要血量策略，优先保留这个集成版。 |

| `auto_align_map.py` | 地图自动对齐工具。 |

| `hero_to_sentry_map_converter.py` | Hero 地图转哨兵地图工具。 |

| `convert_lidar_pose_pcd.py` | 点云在不同雷达安装位姿之间转换。 |

| `slam.sh` | 仿真 SLAM 包装脚本，带 rosbag、栅格地图和 PCD 保存逻辑。 |


| `ros2_record_safe.sh` | 断电风险场景下更安全的 rosbag 录制脚本。 |

| `test_auto_nav.py` | `auto_nav.py` 相关纯计算逻辑测试。 |

| `mock_gimbal.py` | 云台串口协议本地模拟/调试辅助。 |


导航脚本之间的区别
| 脚本组 | 重复点 | 建议 |
|---|---|---|


| `auto_nav.py` / `auto_nav_su.py` | 都是自动航点导航，`auto_nav_su.py` 功能更多且默认话题更通用。 | 若 `auto_nav_su.py` 实测通过，可把它作为主版本，删除或归档 `auto_nav.py`。 |


| `nav.py` / `auto_nav.py` / `auto_nav_su.py` | `nav.py` 是简化循环导航，功能被后两者覆盖。 | 若不再需要最小 demo，优先考虑删除 `nav.py`。 |


| `game.py` / `game_sim.py` | 都是 `GameNode`，串口指令驱动导航，主要差异是 topic / namespace。 | 合并成一个带 `--namespace` / `--mode` 参数的脚本后，删除其中一个。 |


| `hp_nav.py` / `hp_gimbal_nav.py` | `hp_nav.py` 只做血量切点，`hp_gimbal_nav.py` 同时包含血量导航和云台发送。 | 若集成版稳定，删除 `hp_nav.py`。 |


| `cmd_to_gimbal.py` / `cmd_vel_to_gimbal.py` | `cmd_to_gimbal.py` 只是导入并运行 `cmd_vel_to_gimbal.main`。 | 若没有旧命令兼容需求，删除 `cmd_to_gimbal.py`。 |


| `send.py` / `cmd_vel_to_gimbal.py` / `game.py` | 都涉及 `cmd_vel` 转串口发送，协议和话题写法不一致。 | 保留协议清晰的 `cmd_vel_to_gimbal.py`，`send.py` 作为旧版/试验脚本候选删除。 |


| `goal_pose_publisher.py` / `nav.py` / `auto_nav_su.py` | 都发送 `NavigateToPose` 目标，`goal_pose_publisher.py` 更像单点测试工具。 | 若测试入口不需要，删除或移入测试/工具目录。 |


| `build.sh` / `nav.sh` / `save.sh` / `slam.sh` | 都是导航/建图/保存包装脚本，其中 `build.sh`、`nav.sh`、`save.sh` 仍有硬编码工作区路径或命名不准。 | 不建议直接删；先统一路径和用途命名，再决定保留哪些入口。 |



## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `.gitignore` | 文件 | Git 忽略规则，排除构建产物、缓存和临时文件。 |
| `auto_align_map.py` | 文件 | Auto-align a source 2D occupancy-grid map to a reference map. |
| `auto_nav.py` | 文件 | Python 脚本/模块，用于 auto nav 相关逻辑。 |
| `auto_nav_su.py` | 文件 | Python 脚本/模块，用于 auto nav su 相关逻辑。 |
| `build.sh` | 文件 | Shell 脚本：建图模式。 |
| `cmd_to_gimbal.py` | 文件 | Python 脚本/模块，用于 cmd to gimbal 相关逻辑。 |
| `cmd_vel_to_gimbal.py` | 文件 | 订阅 /cmd_vel 话题，将 vx/vy 通过 VisionToGimbal 协议发送到 /dev/gimbal 串口。 |
| `convert_lidar_pose_pcd.py` | 文件 | Convert a saved PCD between two LiDAR mount poses. |
| `game.py` | 文件 | Python 节点/模块，定义类：GameNode |
| `game_sim.py` | 文件 | Python 节点/模块，定义类：GameNode |
| `goal_pose_publisher.py` | 文件 | Python 节点/模块，定义类：GoalPoseActionClient |
| `HERO_MAP_CONVERTER_README.md` | 文件 | Markdown 文档：地图对齐工具集 (Map Alignment Tools)。 |
| `hero_to_sentry_map_converter.py` | 文件 | Python 脚本/模块，用于 hero to sentry map converter 相关逻辑。 |
| `hp_gimbal_nav.py` | 文件 | 整合 hp_nav + cmd_vel_to_gimbal： |
| `hp_nav.py` | 文件 | Python 节点/模块，定义类：HpNavNode |
| `IMPROVEMENT_PLAN.md` | 文件 | Markdown 文档：pfa-nav 改进计划。 |
| `install_pfa_nav_deps.sh` | 文件 | Shell 脚本，用于 install pfa nav deps。 |
| `mock_gimbal.py` | 文件 | Python 工具脚本，包含函数：main |
| `nav.py` | 文件 | Python 节点/模块，定义类：NavLoop |
| `nav.sh` | 文件 | Shell 脚本：导航模式。 |
| `README.md` | 文件 | 当前目录或模块的说明文档。 |
| `ros2_record_safe.sh` | 文件 | Shell 脚本：Safer ROS 2 bag recording for machines that may lose power directly.。 |
| `save.sh` | 文件 | Shell 脚本：保存地图。 |
| `send.py` | 文件 | Python 节点/模块，定义类：VelocitySender |
| `slam.sh` | 文件 | Shell 脚本：SLAM launch wrapper: auto-save grid map + 3D PCD + rosbag on exit。 |
| `start.sh` | 文件 | Shell 脚本，用于 start。 |
| `test.pgm` | 文件 | 二维占据栅格地图图像。 |
| `test.yaml` | 文件 | YAML 数据/配置文件，用于 test。 |
| `test_auto_nav.py` | 文件 | Python 测试文件，用于验证 test auto nav 相关逻辑。 |
| `true_pram.yaml` | 文件 | YAML 数据/配置文件，用于 true pram。 |
| `waypoints.yaml` | 文件 | YAML 数据/配置文件，用于 waypoints。 |
| `yy.md` | 文件 | Markdown 文档：整体框架使用北极熊导航！派大星恩情还不完！。 |
