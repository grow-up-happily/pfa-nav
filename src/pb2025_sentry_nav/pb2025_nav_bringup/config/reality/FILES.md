# src/pb2025_sentry_nav/pb2025_nav_bringup/config/reality 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav/pb2025_nav_bringup/config/reality` 这一层目录中的文件和子目录作用。

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `mid360_user_config.json` | 文件 | JSON 配置文件，用于 mid360 user config。 |
| `nav2_params.yaml` | 文件 | YAML 参数配置，用于 nav2 params。 |

## README / 实际调用状态

| 文件 | 当前状态 | 说明 |
|---|---|---|
| `nav2_params.yaml` | 实车入口默认参数文件 | `rm_navigation_reality_launch.py` 默认 `params_file` 指向它；手柄、Nav2、point_lio、Livox 等实车参数都从这里进入。 |
| `mid360_user_config.json` | 已被实车参数引用 | `nav2_params.yaml` 的 Livox 配置指向它；根 README 明确要求在这里配置雷达 IP 和本机 IP。 |

## 参数注意

| 参数 | 当前用法 | 注意 |
|---|---|---|
| `prior_pcd.prior_pcd_map_path` / `prior_pcd_file` | 由 launch 的 `prior_pcd_file` 传入 | YAML 内注释不是最终入口；默认会拼到 `pcd/reality/<world>.pcd`。 |
| `yaml_filename` | 由 launch 的 `map` 参数重写 | 默认会拼到 `map/reality/<world>.yaml`，当前实车目录只有 `game.yaml`。 |
