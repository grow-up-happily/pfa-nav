# src/pb2025_sentry_nav/pb2025_nav_bringup/config 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav/pb2025_nav_bringup/config` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `reality` | 目录 | 项目子目录。 |
| `simulation` | 目录 | 项目子目录。 |

## README / 实际调用状态

| 目录 | 当前状态 | 说明 |
|---|---|---|
| `simulation` | 仿真入口默认使用 | `rm_navigation_simulation_launch.py` 默认 `params_file` 指向 `simulation/nav2_params.yaml`。 |
| `reality` | 实车入口默认使用 | `rm_navigation_reality_launch.py` 默认 `params_file` 指向 `reality/nav2_params.yaml`；根 README 还明确要求在 `reality/mid360_user_config.json` 配雷达和本机 IP。 |

## 参数覆盖关系

| 参数/资源 | 当前用法 | 注意 |
|---|---|---|
| `map` | launch 根据 `world` 拼出地图 YAML，再写入 Nav2 参数的 `yaml_filename` | 不要只看 `nav2_params.yaml` 固定值，实际地图由 launch 参数决定。 |
| `prior_pcd_file` | launch 传给 point_lio、prior_pcd publisher、small_gicp | YAML 里相关路径多为注释或占位，实际以 launch 参数为准。 |
| `teleop_twist_joy_node` | `joy_teleop_launch.py` 从同一个 `params_file` 读取 | 改手柄映射时要改当前模式对应的 `nav2_params.yaml`。 |
