// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wp_map_tools:srv/SaveWaypoints.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__BUILDER_HPP_
#define WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wp_map_tools/srv/detail/save_waypoints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wp_map_tools
{

namespace srv
{

namespace builder
{

class Init_SaveWaypoints_Request_filename
{
public:
  Init_SaveWaypoints_Request_filename()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::wp_map_tools::srv::SaveWaypoints_Request filename(::wp_map_tools::srv::SaveWaypoints_Request::_filename_type arg)
  {
    msg_.filename = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wp_map_tools::srv::SaveWaypoints_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wp_map_tools::srv::SaveWaypoints_Request>()
{
  return wp_map_tools::srv::builder::Init_SaveWaypoints_Request_filename();
}

}  // namespace wp_map_tools


namespace wp_map_tools
{

namespace srv
{

namespace builder
{

class Init_SaveWaypoints_Response_result
{
public:
  Init_SaveWaypoints_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::wp_map_tools::srv::SaveWaypoints_Response result(::wp_map_tools::srv::SaveWaypoints_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wp_map_tools::srv::SaveWaypoints_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wp_map_tools::srv::SaveWaypoints_Response>()
{
  return wp_map_tools::srv::builder::Init_SaveWaypoints_Response_result();
}

}  // namespace wp_map_tools

#endif  // WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__BUILDER_HPP_
