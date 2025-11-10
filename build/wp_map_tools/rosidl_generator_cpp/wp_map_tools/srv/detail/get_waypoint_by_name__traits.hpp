// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wp_map_tools:srv/GetWaypointByName.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__TRAITS_HPP_
#define WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wp_map_tools/srv/detail/get_waypoint_by_name__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace wp_map_tools
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetWaypointByName_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetWaypointByName_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetWaypointByName_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace wp_map_tools

namespace rosidl_generator_traits
{

[[deprecated("use wp_map_tools::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const wp_map_tools::srv::GetWaypointByName_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  wp_map_tools::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wp_map_tools::srv::to_yaml() instead")]]
inline std::string to_yaml(const wp_map_tools::srv::GetWaypointByName_Request & msg)
{
  return wp_map_tools::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wp_map_tools::srv::GetWaypointByName_Request>()
{
  return "wp_map_tools::srv::GetWaypointByName_Request";
}

template<>
inline const char * name<wp_map_tools::srv::GetWaypointByName_Request>()
{
  return "wp_map_tools/srv/GetWaypointByName_Request";
}

template<>
struct has_fixed_size<wp_map_tools::srv::GetWaypointByName_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<wp_map_tools::srv::GetWaypointByName_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<wp_map_tools::srv::GetWaypointByName_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace wp_map_tools
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetWaypointByName_Response & msg,
  std::ostream & out)
{
  out << "{";
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
  const GetWaypointByName_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const GetWaypointByName_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace wp_map_tools

namespace rosidl_generator_traits
{

[[deprecated("use wp_map_tools::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const wp_map_tools::srv::GetWaypointByName_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  wp_map_tools::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wp_map_tools::srv::to_yaml() instead")]]
inline std::string to_yaml(const wp_map_tools::srv::GetWaypointByName_Response & msg)
{
  return wp_map_tools::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wp_map_tools::srv::GetWaypointByName_Response>()
{
  return "wp_map_tools::srv::GetWaypointByName_Response";
}

template<>
inline const char * name<wp_map_tools::srv::GetWaypointByName_Response>()
{
  return "wp_map_tools/srv/GetWaypointByName_Response";
}

template<>
struct has_fixed_size<wp_map_tools::srv::GetWaypointByName_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<wp_map_tools::srv::GetWaypointByName_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<wp_map_tools::srv::GetWaypointByName_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<wp_map_tools::srv::GetWaypointByName>()
{
  return "wp_map_tools::srv::GetWaypointByName";
}

template<>
inline const char * name<wp_map_tools::srv::GetWaypointByName>()
{
  return "wp_map_tools/srv/GetWaypointByName";
}

template<>
struct has_fixed_size<wp_map_tools::srv::GetWaypointByName>
  : std::integral_constant<
    bool,
    has_fixed_size<wp_map_tools::srv::GetWaypointByName_Request>::value &&
    has_fixed_size<wp_map_tools::srv::GetWaypointByName_Response>::value
  >
{
};

template<>
struct has_bounded_size<wp_map_tools::srv::GetWaypointByName>
  : std::integral_constant<
    bool,
    has_bounded_size<wp_map_tools::srv::GetWaypointByName_Request>::value &&
    has_bounded_size<wp_map_tools::srv::GetWaypointByName_Response>::value
  >
{
};

template<>
struct is_service<wp_map_tools::srv::GetWaypointByName>
  : std::true_type
{
};

template<>
struct is_service_request<wp_map_tools::srv::GetWaypointByName_Request>
  : std::true_type
{
};

template<>
struct is_service_response<wp_map_tools::srv::GetWaypointByName_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__TRAITS_HPP_
