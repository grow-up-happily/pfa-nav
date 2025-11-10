// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wp_map_tools:srv/SaveWaypoints.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__TRAITS_HPP_
#define WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wp_map_tools/srv/detail/save_waypoints__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace wp_map_tools
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveWaypoints_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: filename
  {
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveWaypoints_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveWaypoints_Request & msg, bool use_flow_style = false)
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
  const wp_map_tools::srv::SaveWaypoints_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  wp_map_tools::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wp_map_tools::srv::to_yaml() instead")]]
inline std::string to_yaml(const wp_map_tools::srv::SaveWaypoints_Request & msg)
{
  return wp_map_tools::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wp_map_tools::srv::SaveWaypoints_Request>()
{
  return "wp_map_tools::srv::SaveWaypoints_Request";
}

template<>
inline const char * name<wp_map_tools::srv::SaveWaypoints_Request>()
{
  return "wp_map_tools/srv/SaveWaypoints_Request";
}

template<>
struct has_fixed_size<wp_map_tools::srv::SaveWaypoints_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<wp_map_tools::srv::SaveWaypoints_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<wp_map_tools::srv::SaveWaypoints_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace wp_map_tools
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveWaypoints_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveWaypoints_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveWaypoints_Response & msg, bool use_flow_style = false)
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
  const wp_map_tools::srv::SaveWaypoints_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  wp_map_tools::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wp_map_tools::srv::to_yaml() instead")]]
inline std::string to_yaml(const wp_map_tools::srv::SaveWaypoints_Response & msg)
{
  return wp_map_tools::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wp_map_tools::srv::SaveWaypoints_Response>()
{
  return "wp_map_tools::srv::SaveWaypoints_Response";
}

template<>
inline const char * name<wp_map_tools::srv::SaveWaypoints_Response>()
{
  return "wp_map_tools/srv/SaveWaypoints_Response";
}

template<>
struct has_fixed_size<wp_map_tools::srv::SaveWaypoints_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<wp_map_tools::srv::SaveWaypoints_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<wp_map_tools::srv::SaveWaypoints_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<wp_map_tools::srv::SaveWaypoints>()
{
  return "wp_map_tools::srv::SaveWaypoints";
}

template<>
inline const char * name<wp_map_tools::srv::SaveWaypoints>()
{
  return "wp_map_tools/srv/SaveWaypoints";
}

template<>
struct has_fixed_size<wp_map_tools::srv::SaveWaypoints>
  : std::integral_constant<
    bool,
    has_fixed_size<wp_map_tools::srv::SaveWaypoints_Request>::value &&
    has_fixed_size<wp_map_tools::srv::SaveWaypoints_Response>::value
  >
{
};

template<>
struct has_bounded_size<wp_map_tools::srv::SaveWaypoints>
  : std::integral_constant<
    bool,
    has_bounded_size<wp_map_tools::srv::SaveWaypoints_Request>::value &&
    has_bounded_size<wp_map_tools::srv::SaveWaypoints_Response>::value
  >
{
};

template<>
struct is_service<wp_map_tools::srv::SaveWaypoints>
  : std::true_type
{
};

template<>
struct is_service_request<wp_map_tools::srv::SaveWaypoints_Request>
  : std::true_type
{
};

template<>
struct is_service_response<wp_map_tools::srv::SaveWaypoints_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__TRAITS_HPP_
