// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from wp_map_tools:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "wp_map_tools/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "wp_map_tools/msg/detail/waypoint__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace wp_map_tools
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wp_map_tools
cdr_serialize(
  const wp_map_tools::msg::Waypoint & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wp_map_tools
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  wp_map_tools::msg::Waypoint & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wp_map_tools
get_serialized_size(
  const wp_map_tools::msg::Waypoint & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wp_map_tools
max_serialized_size_Waypoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace wp_map_tools

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wp_map_tools
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wp_map_tools, msg, Waypoint)();

#ifdef __cplusplus
}
#endif

#endif  // WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
