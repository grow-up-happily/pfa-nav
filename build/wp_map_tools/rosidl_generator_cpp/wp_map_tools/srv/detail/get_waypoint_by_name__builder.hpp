// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wp_map_tools:srv/GetWaypointByName.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__BUILDER_HPP_
#define WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wp_map_tools/srv/detail/get_waypoint_by_name__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wp_map_tools
{

namespace srv
{

namespace builder
{

class Init_GetWaypointByName_Request_name
{
public:
  Init_GetWaypointByName_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::wp_map_tools::srv::GetWaypointByName_Request name(::wp_map_tools::srv::GetWaypointByName_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wp_map_tools::srv::GetWaypointByName_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wp_map_tools::srv::GetWaypointByName_Request>()
{
  return wp_map_tools::srv::builder::Init_GetWaypointByName_Request_name();
}

}  // namespace wp_map_tools


namespace wp_map_tools
{

namespace srv
{

namespace builder
{

class Init_GetWaypointByName_Response_pose
{
public:
  explicit Init_GetWaypointByName_Response_pose(::wp_map_tools::srv::GetWaypointByName_Response & msg)
  : msg_(msg)
  {}
  ::wp_map_tools::srv::GetWaypointByName_Response pose(::wp_map_tools::srv::GetWaypointByName_Response::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wp_map_tools::srv::GetWaypointByName_Response msg_;
};

class Init_GetWaypointByName_Response_name
{
public:
  Init_GetWaypointByName_Response_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetWaypointByName_Response_pose name(::wp_map_tools::srv::GetWaypointByName_Response::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_GetWaypointByName_Response_pose(msg_);
  }

private:
  ::wp_map_tools::srv::GetWaypointByName_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wp_map_tools::srv::GetWaypointByName_Response>()
{
  return wp_map_tools::srv::builder::Init_GetWaypointByName_Response_name();
}

}  // namespace wp_map_tools

#endif  // WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__BUILDER_HPP_
