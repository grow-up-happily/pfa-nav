# src/pb2025_sentry_nav/pb2025_nav_bringup/pcd 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav/pb2025_nav_bringup/pcd` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `reality` | 目录 | 项目子目录。 |

## README / 实际调用状态

| 目录/文件 | 当前状态 | 说明 |
|---|---|---|
| `reality` | 实车定位默认查这里 | `rm_navigation_reality_launch.py` 默认把 `world:=xxx` 拼成 `pcd/reality/xxx.pcd`。 |
| `simulation/scans.pcd` | launch 默认会指向，但当前仓库未看到 | `rm_navigation_simulation_launch.py` 默认 `prior_pcd_file` 是 `pcd/simulation/scans.pcd`；当前 `pcd` 下没有 `simulation` 目录，仿真定位前要补点云或显式传 `prior_pcd_file:=...`。 |

## 参数注意

| 参数 | 当前用法 | 注意 |
|---|---|---|
| `prior_pcd_file` | 定位模式使用 | 会传给 `point_lio`、`prior_pcd_publisher.py`、`small_gicp_relocalization`；文件不存在会影响定位链。 |
| `auto_save_pcd` / `auto_save_pcd_interval` | SLAM 模式使用 | 只在 `slam:=True` 时传给 `point_lio` 保存累计点云；不是普通导航读图入口。 |
