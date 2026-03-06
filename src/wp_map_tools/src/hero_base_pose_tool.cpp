/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2017-2020, Waterplus http://www.6-robot.com
*  All rights reserved.
*********************************************************************/

#include "wp_map_tools/hero_base_pose_tool.hpp"

#include "rviz_common/load_resource.hpp"
#include <pluginlib/class_list_macros.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

namespace wp_map_tools
{
    HeroBasePoseTool::HeroBasePoseTool() : rviz_default_plugins::tools::PoseTool()
    {
        shortcut_key_ = 'h';
        topic_property_ = new rviz_common::properties::StringProperty(
            "Topic",
            "/hero_lidar/base_pose",
            "The PoseStamped topic used to update hero_lidar base pose.",
            getPropertyContainer(),
            SLOT(updateTopic()),
            this);
    }

    HeroBasePoseTool::~HeroBasePoseTool()
    {
    }

    void HeroBasePoseTool::onInitialize()
    {
        rviz_default_plugins::tools::PoseTool::onInitialize();
        setName("Hero Base Pose");
        setIcon(rviz_common::loadPixmap("package://wp_map_tools/icons/classes/AddWaypointTool.png"));
        updateTopic();
    }

    void HeroBasePoseTool::updateTopic()
    {
        raw_node_ = context_->getRosNodeAbstraction().lock()->get_raw_node();
        pub_ = raw_node_->create_publisher<geometry_msgs::msg::PoseStamped>(
            topic_property_->getStdString(),
            1);
    }

    void HeroBasePoseTool::onPoseSet(double x, double y, double theta)
    {
        tf2::Quaternion quat;
        quat.setRPY(0.0, 0.0, theta);

        geometry_msgs::msg::PoseStamped pose_msg;
        pose_msg.header.stamp = raw_node_->now();
        pose_msg.header.frame_id = context_->getFixedFrame().toStdString();
        pose_msg.pose.position.x = x;
        pose_msg.pose.position.y = y;
        pose_msg.pose.position.z = 0.0;
        pose_msg.pose.orientation = tf2::toMsg(quat);

        pub_->publish(pose_msg);
    }
}

PLUGINLIB_EXPORT_CLASS(wp_map_tools::HeroBasePoseTool, rviz_common::Tool)
