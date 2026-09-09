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

#include "loam_interface/loam_interface.hpp"

#include <stdexcept>

#include "pcl_ros/transforms.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

namespace loam_interface
{

LoamInterfaceNode::LoamInterfaceNode(const rclcpp::NodeOptions & options)
: Node("loam_interface", options)
{
  this->declare_parameter<std::string>("state_estimation_topic", "");
  this->declare_parameter<std::string>("registered_scan_topic", "");
  this->declare_parameter<bool>("use_ground_truth", false);
  this->declare_parameter<std::string>("ground_truth_odometry_topic", "");
  this->declare_parameter<std::string>("sensor_scan_topic", "");
  this->declare_parameter<std::string>("odom_frame", "odom");
  this->declare_parameter<std::string>("base_frame", "");
  this->declare_parameter<std::string>("lidar_frame", "");

  this->get_parameter("state_estimation_topic", state_estimation_topic_);
  this->get_parameter("registered_scan_topic", registered_scan_topic_);
  this->get_parameter("use_ground_truth", use_ground_truth_);
  this->get_parameter("ground_truth_odometry_topic", ground_truth_odometry_topic_);
  this->get_parameter("sensor_scan_topic", sensor_scan_topic_);
  this->get_parameter("odom_frame", odom_frame_);
  this->get_parameter("base_frame", base_frame_);
  this->get_parameter("lidar_frame", lidar_frame_);

  base_frame_to_lidar_initialized_ = false;
  ground_truth_initialized_ = false;

  tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
  tf_listener_ = std::make_unique<tf2_ros::TransformListener>(*tf_buffer_);
  // tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(this);

  pcd_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("registered_scan", 5);
  odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("lidar_odometry", 5);

  if (use_ground_truth_) {
    if (ground_truth_odometry_topic_.empty() || sensor_scan_topic_.empty()) {
      throw std::invalid_argument(
        "ground_truth_odometry_topic and sensor_scan_topic are required when "
        "use_ground_truth is true");
    }
    RCLCPP_WARN(
      get_logger(), "Simulation ground-truth mode enabled; Point-LIO remains diagnostic only");
    ground_truth_odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
      ground_truth_odometry_topic_, 10,
      std::bind(&LoamInterfaceNode::groundTruthOdometryCallback, this, std::placeholders::_1));
    ground_truth_pcd_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
      sensor_scan_topic_, rclcpp::SensorDataQoS(),
      std::bind(&LoamInterfaceNode::groundTruthPointCloudCallback, this, std::placeholders::_1));
  } else {
    pcd_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
      registered_scan_topic_, 5,
      std::bind(&LoamInterfaceNode::pointCloudCallback, this, std::placeholders::_1));
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
      state_estimation_topic_, 5,
      std::bind(&LoamInterfaceNode::odometryCallback, this, std::placeholders::_1));
  }
}

void LoamInterfaceNode::groundTruthOdometryCallback(
  const nav_msgs::msg::Odometry::ConstSharedPtr msg)
{
  tf2::Transform tf_world_to_base;
  tf2::fromMsg(msg->pose.pose, tf_world_to_base);

  std::lock_guard<std::mutex> lock(ground_truth_mutex_);
  if (!ground_truth_initialized_) {
    try {
      const auto tf_stamped = tf_buffer_->lookupTransform(
        base_frame_, lidar_frame_, msg->header.stamp, rclcpp::Duration::from_seconds(0.5));
      tf2::fromMsg(tf_stamped.transform, tf_base_to_lidar_);
    } catch (const tf2::TransformException & ex) {
      RCLCPP_WARN(get_logger(), "Ground-truth TF lookup failed: %s Retrying...", ex.what());
      return;
    }
    tf_world_to_initial_base_ = tf_world_to_base.inverse();
    ground_truth_initialized_ = true;
  }

  tf_odom_to_base_ = tf_world_to_initial_base_ * tf_world_to_base;
}

void LoamInterfaceNode::groundTruthPointCloudCallback(
  const sensor_msgs::msg::PointCloud2::ConstSharedPtr msg)
{
  tf2::Transform tf_odom_to_lidar;
  {
    std::lock_guard<std::mutex> lock(ground_truth_mutex_);
    if (!ground_truth_initialized_) {
      RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 2000, "Waiting for ground-truth odometry");
      return;
    }
    tf_odom_to_lidar = tf_odom_to_base_ * tf_base_to_lidar_;
  }

  nav_msgs::msg::Odometry odom;
  odom.header.stamp = msg->header.stamp;
  odom.header.frame_id = odom_frame_;
  odom.child_frame_id = lidar_frame_;
  const auto & origin = tf_odom_to_lidar.getOrigin();
  odom.pose.pose.position.x = origin.x();
  odom.pose.pose.position.y = origin.y();
  odom.pose.pose.position.z = origin.z();
  odom.pose.pose.orientation = tf2::toMsg(tf_odom_to_lidar.getRotation());
  odom_pub_->publish(odom);

  sensor_msgs::msg::PointCloud2 registered_scan;
  pcl_ros::transformPointCloud(odom_frame_, tf_odom_to_lidar, *msg, registered_scan);
  pcd_pub_->publish(registered_scan);
}

void LoamInterfaceNode::pointCloudCallback(const sensor_msgs::msg::PointCloud2::ConstSharedPtr msg)
{
  // NOTE: Input point cloud message is based on the `lidar_odom`
  // Here we transform it to the REAL `odom` frame
  auto out = std::make_shared<sensor_msgs::msg::PointCloud2>();
  pcl_ros::transformPointCloud(odom_frame_, tf_odom_to_lidar_odom_, *msg, *out);
  pcd_pub_->publish(*out);
}

void LoamInterfaceNode::odometryCallback(const nav_msgs::msg::Odometry::ConstSharedPtr msg)
{
  // NOTE: Input odometry message is based on the `lidar_odom`
  // Here we transform it to the `odom` frame
  if (!base_frame_to_lidar_initialized_) {
    try {
      auto tf_stamped = tf_buffer_->lookupTransform(
        base_frame_, lidar_frame_, msg->header.stamp, rclcpp::Duration::from_seconds(0.5));
      tf2::Transform tf_base_frame_to_lidar;
      tf2::fromMsg(tf_stamped.transform, tf_base_frame_to_lidar);

      // Capture point_lio's first lidar pose (= rot_init from gravity alignment).
      // Without this, when point_lio is gravity-aligned (gravity = [0,0,-9.81] in YAML),
      // the lidar's initial orientation in point_lio's world is rot_init, not identity.
      // We need to subtract this off so that downstream odom frame is anchored at base
      // exactly as URDF specifies, regardless of how the IMU/lidar is mounted.
      tf2::Transform tf_lidar_init;
      tf2::fromMsg(msg->pose.pose, tf_lidar_init);

      tf_odom_to_lidar_odom_ = tf_base_frame_to_lidar * tf_lidar_init.inverse();
      base_frame_to_lidar_initialized_ = true;
    } catch (tf2::TransformException & ex) {
      RCLCPP_WARN(this->get_logger(), "TF lookup failed: %s Retrying...", ex.what());
      return;
    }
  }

  // Transform the odometry_msg (based lidar_odom) to the odom frame
  tf2::Transform tf_lidar_odom_to_lidar;
  tf2::fromMsg(msg->pose.pose, tf_lidar_odom_to_lidar);
  tf2::Transform tf_odom_to_lidar = tf_odom_to_lidar_odom_ * tf_lidar_odom_to_lidar;

  nav_msgs::msg::Odometry out;
  out.header.stamp = msg->header.stamp;
  out.header.frame_id = odom_frame_;
  out.child_frame_id = lidar_frame_;

  const auto & origin = tf_odom_to_lidar.getOrigin();
  out.pose.pose.position.x = origin.x();
  out.pose.pose.position.y = origin.y();
  out.pose.pose.position.z = origin.z();
  out.pose.pose.orientation = tf2::toMsg(tf_odom_to_lidar.getRotation());

  odom_pub_->publish(out);

  // // Publish TF: odom -> base_footprint
  // geometry_msgs::msg::TransformStamped tf_msg;
  // tf_msg.header.stamp = msg->header.stamp;
  // tf_msg.header.frame_id = odom_frame_;
  // tf_msg.child_frame_id = base_frame_;

  // // Transform from odom to base_frame (lidar to base already stored in tf_odom_to_lidar_odom_)
  // tf2::Transform tf_odom_to_base = tf_odom_to_lidar * tf_odom_to_lidar_odom_.inverse();

  // const auto & base_origin = tf_odom_to_base.getOrigin();
  // tf_msg.transform.translation.x = base_origin.x();
  // tf_msg.transform.translation.y = base_origin.y();
  // tf_msg.transform.translation.z = base_origin.z();
  // tf_msg.transform.rotation = tf2::toMsg(tf_odom_to_base.getRotation());

  // tf_broadcaster_->sendTransform(tf_msg);
}

}  // namespace loam_interface

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(loam_interface::LoamInterfaceNode)
