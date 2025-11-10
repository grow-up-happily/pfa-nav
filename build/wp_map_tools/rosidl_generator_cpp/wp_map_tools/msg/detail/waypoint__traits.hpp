// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wp_map_tools:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__TRAITS_HPP_
#define WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wp_map_tools/msg/detail/waypoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace wp_map_tools
{

namespace msg
{

inline void to_flow_style_yaml(
  const Waypoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: frame_id
  {
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Waypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Waypoint & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace wp_map_tools

namespace rosidl_generator_traits
{

[[deprecated("use wp_map_tools::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const wp_map_tools::msg::Waypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  wp_map_tools::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wp_map_tools::msg::to_yaml() instead")]]
inline std::string to_yaml(const wp_map_tools::msg::Waypoint & msg)
{
  return wp_map_tools::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wp_map_tools::msg::Waypoint>()
{
  return "wp_map_tools::msg::Waypoint";
}

template<>
inline const char * name<wp_map_tools::msg::Waypoint>()
{
  return "wp_map_tools/msg/Waypoint";
}

template<>
struct has_fixed_size<wp_map_tools::msg::Waypoint>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<wp_map_tools::msg::Waypoint>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<wp_map_tools::msg::Waypoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__TRAITS_HPP_
