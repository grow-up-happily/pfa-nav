# Nav2 Isolated Noise Filter Design

## Goal

Before Nav2 plans a path, ignore isolated obstacle noise that appears in the custom
`pb_nav2_costmap_2d::IntensityVoxelLayer`. The filter must be configurable from
YAML so the required number of nearby occupied grid cells can be tuned without
rebuilding.

## Current Behavior

Both simulation and reality Nav2 configs use `IntensityVoxelLayer` in local and
global costmaps. Each update resets the layer, reads PointCloud2 observations,
filters only by height, intensity, and range, then immediately writes every
accepted point's 2D cell as `LETHAL_OBSTACLE`. A single noisy point can therefore
enter the costmap and influence SmacPlannerHybrid.

## Design

Add a small neighborhood filter inside `IntensityVoxelLayer` before cells are
written to `costmap_`.

The layer will first collect candidate obstacle cells from the current
observations. It will then keep a candidate only when enough other candidate
cells exist within a square neighborhood around that cell. Rejected cells are not
written as lethal obstacles, so the planner sees them as absent.

Configurable parameters:

- `noise_filter_enabled`: enable or disable the filter. Default `false` in code,
  set to `true` in this project's Nav2 configs.
- `noise_filter_radius_cells`: neighborhood radius in costmap cells. A value of
  `1` checks the 8 surrounding cells plus the center cell.
- `noise_filter_min_neighbors`: minimum number of occupied candidate cells in the
  neighborhood, including the center cell. A value of `2` removes true single-cell
  noise while preserving pairs and larger clusters.

The requested "judgment grid count" is `noise_filter_min_neighbors`.

## Scope

Update the custom costmap layer and the two project Nav2 configs:

- `src/pb2025_sentry_nav/pb_nav2_plugins/.../intensity_voxel_layer.*`
- `src/pb2025_sentry_nav/pb2025_nav_bringup/config/simulation/nav2_params.yaml`
- `src/pb2025_sentry_nav/pb2025_nav_bringup/config/reality/nav2_params.yaml`

The filter applies to both local and global costmaps in simulation and reality.

## Testing

Add focused unit tests for the neighborhood decision logic so parameter changes
are covered without needing to launch ROS. Then build/test `pb_nav2_plugins`.

Manual tuning can start with:

- `noise_filter_enabled: true`
- `noise_filter_radius_cells: 1`
- `noise_filter_min_neighbors: 2`

If real obstacles become too sparse, lower the threshold or disable the filter. If
noise still leaks through, raise `noise_filter_min_neighbors` to `3`.
