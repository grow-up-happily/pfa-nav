# src/pb2025_sentry_nav/pb2025_nav_bringup/config/simulation 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav/pb2025_nav_bringup/config/simulation` 这一层目录中的文件和子目录作用。

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `nav2_params.yaml` | 文件 | YAML 参数配置，用于 nav2 params。 |

## README / 实际调用状态

| 文件 | 当前状态 | 说明 |
|---|---|---|
| `nav2_params.yaml` | 仿真入口默认参数文件 | `rm_navigation_simulation_launch.py` 默认 `params_file` 指向它；`joy_teleop_launch.py` 也用它读取手柄配置。 |

## 参数注意

| 参数 | 当前用法 | 注意 |
|---|---|---|
| `yaml_filename` | 由 launch 的 `map` 参数重写 | 默认按 `map/simulation/<world>.yaml` 选择地图，README 示例常用 `world:=rmuc_2025`。 |
| `prior_pcd.prior_pcd_map_path` / `prior_pcd_file` | 由 launch 的 `prior_pcd_file` 传入 | 仿真入口默认 `pcd/simulation/scans.pcd`，但当前仓库的 `pcd` 下未看到 `simulation/scans.pcd`；定位模式测试前要补文件或显式覆盖参数。 |
