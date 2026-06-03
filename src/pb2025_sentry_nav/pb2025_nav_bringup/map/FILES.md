# src/pb2025_sentry_nav/pb2025_nav_bringup/map 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav/pb2025_nav_bringup/map` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `reality` | 目录 | 项目子目录。 |
| `simulation` | 目录 | 项目子目录。 |

## README / 实际调用状态

| 目录 | 当前状态 | 说明 |
|---|---|---|
| `simulation` | 仿真导航默认查这里 | `rm_navigation_simulation_launch.py` 默认把 `world:=xxx` 拼成 `map/simulation/xxx.yaml`；README 示例 `world:=rmuc_2025` 会用 `simulation/rmuc_2025.yaml`。 |
| `reality` | 实车导航默认查这里 | `rm_navigation_reality_launch.py` 默认把 `world:=xxx` 拼成 `map/reality/xxx.yaml`；当前文件主要是 `game.yaml` / `game.pgm`。 |

## 参数注意

| 参数 | 当前用法 | 注意 |
|---|---|---|
| `world` | 参与默认地图路径拼接 | `world` 不是只选择仿真世界，也决定默认地图文件名。 |
| `map` | 可覆盖完整地图 YAML 路径 | 如果要用非默认地图，直接传 `map:=/abs/path/map.yaml` 比改 YAML 更明确。 |
| `auto_save_map_dir` | SLAM 自动保存目录 | 只在 `slam:=True` 且 `auto_save_map:=True` 时使用；普通导航不会写地图。 |
