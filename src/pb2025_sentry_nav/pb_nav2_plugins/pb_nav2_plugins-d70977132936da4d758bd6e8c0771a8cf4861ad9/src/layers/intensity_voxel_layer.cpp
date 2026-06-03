// Copyright 2025 Lihan Chen
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "pb_nav2_plugins/layers/intensity_voxel_layer.hpp"

#include <unordered_map>
#include <vector>

#include "sensor_msgs/point_cloud2_iterator.hpp"

#define VOXEL_BITS 16

using nav2_costmap_2d::FREE_SPACE;
using nav2_costmap_2d::LETHAL_OBSTACLE;
using nav2_costmap_2d::NO_INFORMATION;

using nav2_costmap_2d::Observation;
using nav2_costmap_2d::ObservationBuffer;

namespace pb_nav2_costmap_2d
{

void IntensityVoxelLayer::onInitialize()
{
  auto node = node_.lock();
  clock_ = node->get_clock();
  ObstacleLayer::onInitialize();
  footprint_clearing_enabled_ =
    node->get_parameter(name_ + ".footprint_clearing_enabled").as_bool();
  enabled_ = node->get_parameter(name_ + ".enabled").as_bool();
  max_obstacle_height_ = node->get_parameter(name_ + ".max_obstacle_height").as_double();
  combination_method_ = node->get_parameter(name_ + ".combination_method").as_int();

  size_z_ = node->declare_parameter(name_ + ".z_voxels", 16);
  origin_z_ = node->declare_parameter(name_ + ".origin_z", 16.0);
  min_obstacle_intensity_ = node->declare_parameter(name_ + ".min_obstacle_intensity", 0.1);
  max_obstacle_intensity_ = node->declare_parameter(name_ + ".max_obstacle_intensity", 2.0);
  z_resolution_ = node->declare_parameter(name_ + ".z_resolution", 0.05);
  unknown_threshold_ =
    node->declare_parameter(name_ + ".unknown_threshold", 15) + (VOXEL_BITS - size_z_);
  mark_threshold_ = node->declare_parameter(name_ + ".mark_threshold", 0);
  publish_voxel_ = node->declare_parameter(name_ + ".publish_voxel_map", false);
  noise_filter_enabled_ = node->declare_parameter(name_ + ".noise_filter_enabled", false);

  int noise_filter_min_cluster_cells =
    node->declare_parameter(name_ + ".noise_filter_min_cluster_cells", 5);
  if (noise_filter_min_cluster_cells < 1) {
    RCLCPP_WARN(
      node->get_logger(),
      "Parameter %s.noise_filter_min_cluster_cells must be at least 1. Using 1.", name_.c_str());
    noise_filter_min_cluster_cells = 1;
  }
  noise_filter_min_cluster_cells_ = static_cast<unsigned int>(noise_filter_min_cluster_cells);

  if (publish_voxel_) {
    voxel_pub_ = node->create_publisher<nav2_msgs::msg::VoxelGrid>("voxel_grid", 1);
  }

  matchSize();
}

IntensityVoxelLayer::~IntensityVoxelLayer() {}

void IntensityVoxelLayer::updateFootprint(
  double robot_x, double robot_y, double robot_yaw, double * min_x, double * min_y, double * max_x,
  double * max_y)
{
  if (!footprint_clearing_enabled_) {
    return;
  }

  nav2_costmap_2d::transformFootprint(
    robot_x, robot_y, robot_yaw, getFootprint(), transformed_footprint_);

  for (auto & i : transformed_footprint_) {
    touch(i.x, i.y, min_x, min_y, max_x, max_y);
  }

  setConvexPolygonCost(transformed_footprint_, nav2_costmap_2d::FREE_SPACE);
}

void IntensityVoxelLayer::matchSize()
{
  ObstacleLayer::matchSize();
  voxel_grid_.resize(size_x_, size_y_, size_z_);
}

void IntensityVoxelLayer::reset()
{
  ObstacleLayer::reset();
  resetMaps();
}

void IntensityVoxelLayer::resetMaps()
{
  ObstacleLayer::resetMaps();
  voxel_grid_.reset();
}

void IntensityVoxelLayer::updateBounds(
  double robot_x, double robot_y, double robot_yaw, double * min_x, double * min_y, double * max_x,
  double * max_y)
{
  // update origin information for rolling costmap publication
  if (rolling_window_) {
    updateOrigin(robot_x - getSizeInMetersX() / 2, robot_y - getSizeInMetersY() / 2);
  }

  // reset maps each iteration
  resetMaps();

  // if not enabled, stop here
  if (!enabled_) {
    return;
  }

  // get the maximum sized window required to operate
  useExtraBounds(min_x, min_y, max_x, max_y);

  // get the marking observations
  bool current = true;
  std::vector<Observation> observations;
  current = getMarkingObservations(observations) && current;

  // update the global current status
  current_ = current;

  std::vector<ObstacleCell> obstacle_cells;

  // place the new obstacles into a priority queue... each with a priority of zero to begin with
  for (const auto & obs : observations) {
    double sq_obstacle_max_range = obs.obstacle_max_range_ * obs.obstacle_max_range_;
    double sq_obstacle_min_range = obs.obstacle_min_range_ * obs.obstacle_min_range_;

    sensor_msgs::PointCloud2ConstIterator<float> it_x(*obs.cloud_, "x");
    sensor_msgs::PointCloud2ConstIterator<float> it_y(*obs.cloud_, "y");
    sensor_msgs::PointCloud2ConstIterator<float> it_z(*obs.cloud_, "z");
    sensor_msgs::PointCloud2ConstIterator<float> it_i(*obs.cloud_, "intensity");
    for (; it_x != it_x.end(); ++it_x, ++it_y, ++it_z, ++it_i) {
      double px = *it_x, py = *it_y, pz = *it_z;

      // if the obstacle is too low/high, we won't add it
      if (pz < min_obstacle_height_ || pz > max_obstacle_height_) {
        continue;
      }

      // if the intensity is not in the range we want, we won't add it
      if (*it_i < min_obstacle_intensity_ || *it_i > max_obstacle_intensity_) {
        continue;
      }

      // compute the squared distance from the hitpoint to the pointcloud's origin
      double sq_dist = (px - obs.origin_.x) * (px - obs.origin_.x) +
                       (py - obs.origin_.y) * (py - obs.origin_.y) +
                       (pz - obs.origin_.z) * (pz - obs.origin_.z);

      // if the point is far/close enough away... we won't consider it
      if (sq_dist <= sq_obstacle_min_range || sq_dist >= sq_obstacle_max_range) {
        continue;
      }

      // now we need to compute the map coordinates for the observation
      unsigned int mx, my, mz;
      if (pz < origin_z_) {
        if (!worldToMap3D(px, py, origin_z_, mx, my, mz)) {
          continue;
        }
      } else if (!worldToMap3D(px, py, pz, mx, my, mz)) {
        continue;
      }

      // mark the cell in the voxel grid and check if we should also mark it in the costmap
      if (voxel_grid_.markVoxelInMap(mx, my, mz, mark_threshold_)) {
        unsigned int index = getIndex(mx, my);

        if (noise_filter_enabled_) {
          obstacle_cells.push_back(
            {mx, my, index, static_cast<double>(px), static_cast<double>(py)});
        } else {
          costmap_[index] = LETHAL_OBSTACLE;
          touch(static_cast<double>(px), static_cast<double>(py), min_x, min_y, max_x, max_y);
        }
      }
    }
  }

  if (noise_filter_enabled_) {
    markFilteredObstacleCells(obstacle_cells, min_x, min_y, max_x, max_y);
  }

  if (publish_voxel_) {
    nav2_msgs::msg::VoxelGrid grid_msg;
    unsigned int size = voxel_grid_.sizeX() * voxel_grid_.sizeY();
    grid_msg.size_x = voxel_grid_.sizeX();
    grid_msg.size_y = voxel_grid_.sizeY();
    grid_msg.size_z = voxel_grid_.sizeZ();
    grid_msg.data.resize(size);
    memcpy(&grid_msg.data[0], voxel_grid_.getData(), size * sizeof(unsigned int));

    grid_msg.origin.x = origin_x_;
    grid_msg.origin.y = origin_y_;
    grid_msg.origin.z = origin_z_;

    grid_msg.resolutions.x = resolution_;
    grid_msg.resolutions.y = resolution_;
    grid_msg.resolutions.z = z_resolution_;
    grid_msg.header.frame_id = global_frame_;
    grid_msg.header.stamp = clock_->now();
    voxel_pub_->publish(grid_msg);
  }

  updateFootprint(robot_x, robot_y, robot_yaw, min_x, min_y, max_x, max_y);
}

void IntensityVoxelLayer::markFilteredObstacleCells(
  const std::vector<ObstacleCell> & obstacle_cells, double * min_x, double * min_y, double * max_x,
  double * max_y)
{
  if (obstacle_cells.empty()) {
    return;
  }

  std::vector<ObstacleCell> unique_cells;
  unique_cells.reserve(obstacle_cells.size());

  std::unordered_map<unsigned int, std::size_t> cell_lookup;
  cell_lookup.reserve(obstacle_cells.size());

  for (const auto & cell : obstacle_cells) {
    if (cell_lookup.find(cell.index) != cell_lookup.end()) {
      continue;
    }

    cell_lookup.emplace(cell.index, unique_cells.size());
    unique_cells.push_back(cell);
  }

  std::vector<bool> visited(unique_cells.size(), false);
  std::vector<std::size_t> component;
  std::vector<std::size_t> open_cells;

  for (std::size_t start = 0; start < unique_cells.size(); ++start) {
    if (visited[start]) {
      continue;
    }

    component.clear();
    open_cells.clear();
    open_cells.push_back(start);
    visited[start] = true;

    while (!open_cells.empty()) {
      std::size_t current = open_cells.back();
      open_cells.pop_back();
      component.push_back(current);

      const auto & cell = unique_cells[current];
      const int cell_mx = static_cast<int>(cell.mx);
      const int cell_my = static_cast<int>(cell.my);

      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          if (dx == 0 && dy == 0) {
            continue;
          }

          const int nx = cell_mx + dx;
          const int ny = cell_my + dy;
          if (nx < 0 || ny < 0) {
            continue;
          }

          const unsigned int neighbor_mx = static_cast<unsigned int>(nx);
          const unsigned int neighbor_my = static_cast<unsigned int>(ny);
          if (neighbor_mx >= size_x_ || neighbor_my >= size_y_) {
            continue;
          }

          const unsigned int neighbor_index = getIndex(neighbor_mx, neighbor_my);
          auto neighbor = cell_lookup.find(neighbor_index);
          if (neighbor == cell_lookup.end() || visited[neighbor->second]) {
            continue;
          }

          visited[neighbor->second] = true;
          open_cells.push_back(neighbor->second);
        }
      }
    }

    if (component.size() < static_cast<std::size_t>(noise_filter_min_cluster_cells_)) {
      continue;
    }

    for (std::size_t cell_index : component) {
      const auto & cell = unique_cells[cell_index];
      costmap_[cell.index] = LETHAL_OBSTACLE;
      touch(cell.wx, cell.wy, min_x, min_y, max_x, max_y);
    }
  }
}

void IntensityVoxelLayer::updateOrigin(double new_origin_x, double new_origin_y)
{
  // project the new origin into the grid
  int cell_ox, cell_oy;
  cell_ox = static_cast<int>((new_origin_x - origin_x_) / resolution_);
  cell_oy = static_cast<int>((new_origin_y - origin_y_) / resolution_);

  // update the origin with the appropriate world coordinates
  origin_x_ = origin_x_ + cell_ox * resolution_;
  origin_y_ = origin_y_ + cell_oy * resolution_;
}

}  // namespace pb_nav2_costmap_2d

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(pb_nav2_costmap_2d::IntensityVoxelLayer, nav2_costmap_2d::Layer)
