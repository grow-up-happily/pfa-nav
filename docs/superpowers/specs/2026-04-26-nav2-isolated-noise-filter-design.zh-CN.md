# Nav2 孤立噪声过滤器设计

## 目标

在 Nav2 规划路径之前，忽略自定义
`pb_nav2_costmap_2d::IntensityVoxelLayer` 中出现的孤立障碍噪声和小簇障碍噪声。
过滤器必须能通过 YAML 配置，这样就可以在不重新构建的情况下调节最小障碍簇大小。

## 当前行为

仿真和实车的 Nav2 配置都会在局部 costmap 和全局 costmap 中使用
`IntensityVoxelLayer`。每次更新时，这一层会先重置自身，然后读取 PointCloud2 观测数据，
只按高度、强度和距离过滤，随后立即把每个通过过滤的点对应的二维栅格写成
`LETHAL_OBSTACLE`。因此，单个噪声点也可能进入 costmap，并影响
`SmacPlannerHybrid` 的路径规划结果。

## 设计

在 `IntensityVoxelLayer` 内部增加一个小型连通域过滤器，在单元格写入
`costmap_` 之前执行。

该层会先从当前观测数据中收集候选障碍单元格，然后把相邻的候选单元格聚合成二维
8 连通组件。只有当某个组件包含足够多候选单元格时，才保留该组件。被拒绝的组件不会写成致命障碍，
因此规划器会把它们视为不存在。

可配置参数：

- `noise_filter_enabled`：启用或禁用过滤器。代码中的默认值为 `false`，
  在本项目的 Nav2 配置中设置为 `true`。
- `noise_filter_min_cluster_cells`：保留一个障碍组件所需的最小连通候选单元格数量。
  设为 `5` 时，可以移除单个栅格噪声，以及 `2x2` 的四栅格噪声块。

需求中提到的“判断网格数量”就是 `noise_filter_min_cluster_cells`。

## 范围

更新自定义 costmap layer 和两份项目 Nav2 配置：

- `src/pb2025_sentry_nav/pb_nav2_plugins/.../intensity_voxel_layer.*`
- `src/pb2025_sentry_nav/pb2025_nav_bringup/config/simulation/nav2_params.yaml`
- `src/pb2025_sentry_nav/pb2025_nav_bringup/config/reality/nav2_params.yaml`

该过滤器会同时作用于仿真和实车中的局部 costmap 与全局 costmap。

## 测试

为连通域的保留/丢弃逻辑添加聚焦的单元测试，这样参数变化可以在不启动 ROS 的情况下被覆盖。
然后构建并测试 `pb_nav2_plugins`。

手动调参可以从以下配置开始：

- `noise_filter_enabled: true`
- `noise_filter_min_cluster_cells: 5`

如果真实障碍物变得过于稀疏，就降低阈值或禁用过滤器。如果噪声仍然漏过，就提高
`noise_filter_min_cluster_cells`。
