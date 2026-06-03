# src/pb2025_sentry_nav/point_lio 文件说明

> 自动生成，用于快速了解 `src/pb2025_sentry_nav/point_lio` 这一层目录中的文件和子目录作用。

## 子目录

| 名称 | 类型 | 作用 |
|---|---|---|
| `config` | 目录 | 运行参数和节点配置目录。 |
| `include` | 目录 | C/C++ 头文件目录。 |
| `launch` | 目录 | ROS 2 launch 启动文件目录。 |
| `Log` | 目录 | 项目子目录。 |
| `msg` | 目录 | ROS 消息定义目录。 |
| `PCD` | 目录 | 三维点云地图或点云数据目录。 |
| `rviz_cfg` | 目录 | 项目子目录。 |
| `src` | 目录 | 源码目录。 |

## README / 实际调用状态

| 项 | 当前状态 | 说明 |
|---|---|---|
| `pointlio_mapping` | 主导航链已调用 | `pb2025_nav_bringup/launch/slam_launch.py` 和 `localization_launch.py` 都直接启动它。 |
| `launch` | 独立调试入口 | `point_lio` 自带 launch/README 适合单包调试；主导航流程不是通过它的 launch 文件启动，而是在 bringup launch 里直接起节点。 |
| `config` | 主流程会读取 | bringup 的 `params_file` 中包含 point_lio 参数，`prior_pcd.prior_pcd_map_path` 由 launch 额外传入。 |
| `PCD` / `Log` | 主 README 未直接调用 | 更像 point_lio 自带输出/调试目录；实际导航先验点云默认在 `pb2025_nav_bringup/pcd`。 |

## 参数注意

| 参数 | 当前用法 | 注意 |
|---|---|---|
| `prior_pcd.enable` / `prior_pcd.prior_pcd_map_path` | 定位模式依赖 | 路径由 `prior_pcd_file` 传入；文件不存在时先验点云定位会出问题。 |
| `pcd_save.pcd_save_en` / `pcd_save.interval` | SLAM 自动保存 | 由 `auto_save_pcd` / `auto_save_pcd_interval` 控制，只在 SLAM 链里有意义。 |

## 文件

| 名称 | 类型 | 作用 |
|---|---|---|
| `CMakeLists.txt` | 文件 | CMake/ament 构建配置，定义包、依赖、目标和安装规则。（project：`point_lio`）。 |
| `LICENSE` | 文件 | 许可证文本。 |
| `package.xml` | 文件 | ROS 2 包清单，声明包名、构建类型和依赖。（包名：`point_lio`）。 |
| `README.md` | 文件 | 当前目录或模块的说明文档。 |
