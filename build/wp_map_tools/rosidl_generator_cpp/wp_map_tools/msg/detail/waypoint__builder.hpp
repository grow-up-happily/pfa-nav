// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wp_map_tools:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__BUILDER_HPP_
#define WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wp_map_tools/msg/detail/waypoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wp_map_tools
{

namespace msg
{

namespace builder
{

class Init_Waypoint_pose
{
public:
  explicit Init_Waypoint_pose(::wp_map_tools::msg::Waypoint & msg)
  : msg_(msg)
  {}
  ::wp_map_tools::msg::Waypoint pose(::wp_map_tools::msg::Waypoint::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wp_map_tools::msg::Waypoint msg_;
};

class Init_Waypoint_name
{
public:
  explicit Init_Waypoint_name(::wp_map_tools::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_pose name(::wp_map_tools::msg::Waypoint::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Waypoint_pose(msg_);
  }

private:
  ::wp_map_tools::msg::Waypoint msg_;
};

class Init_Waypoint_frame_id
{
public:
  Init_Waypoint_frame_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Waypoint_name frame_id(::wp_map_tools::msg::Waypoint::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_Waypoint_name(msg_);
  }

private:
  ::wp_map_tools::msg::Waypoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wp_map_tools::msg::Waypoint>()
{
  return wp_map_tools::msg::builder::Init_Waypoint_frame_id();
}

}  // namespace wp_map_tools

#endif  // WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__BUILDER_HPP_
