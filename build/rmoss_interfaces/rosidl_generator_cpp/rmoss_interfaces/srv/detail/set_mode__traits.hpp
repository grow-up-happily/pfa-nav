// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:srv/SetMode.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__SET_MODE__TRAITS_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__SET_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/srv/detail/set_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmoss_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_Request & msg, bool use_flow_style = false)
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

}  // namespace rmoss_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rmoss_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rmoss_interfaces::srv::SetMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::srv::SetMode_Request & msg)
{
  return rmoss_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::srv::SetMode_Request>()
{
  return "rmoss_interfaces::srv::SetMode_Request";
}

template<>
inline const char * name<rmoss_interfaces::srv::SetMode_Request>()
{
  return "rmoss_interfaces/srv/SetMode_Request";
}

template<>
struct has_fixed_size<rmoss_interfaces::srv::SetMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rmoss_interfaces::srv::SetMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rmoss_interfaces::srv::SetMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rmoss_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_Response & msg, bool use_flow_style = false)
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

}  // namespace rmoss_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rmoss_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rmoss_interfaces::srv::SetMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::srv::SetMode_Response & msg)
{
  return rmoss_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::srv::SetMode_Response>()
{
  return "rmoss_interfaces::srv::SetMode_Response";
}

template<>
inline const char * name<rmoss_interfaces::srv::SetMode_Response>()
{
  return "rmoss_interfaces/srv/SetMode_Response";
}

template<>
struct has_fixed_size<rmoss_interfaces::srv::SetMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rmoss_interfaces::srv::SetMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rmoss_interfaces::srv::SetMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rmoss_interfaces::srv::SetMode>()
{
  return "rmoss_interfaces::srv::SetMode";
}

template<>
inline const char * name<rmoss_interfaces::srv::SetMode>()
{
  return "rmoss_interfaces/srv/SetMode";
}

template<>
struct has_fixed_size<rmoss_interfaces::srv::SetMode>
  : std::integral_constant<
    bool,
    has_fixed_size<rmoss_interfaces::srv::SetMode_Request>::value &&
    has_fixed_size<rmoss_interfaces::srv::SetMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<rmoss_interfaces::srv::SetMode>
  : std::integral_constant<
    bool,
    has_bounded_size<rmoss_interfaces::srv::SetMode_Request>::value &&
    has_bounded_size<rmoss_interfaces::srv::SetMode_Response>::value
  >
{
};

template<>
struct is_service<rmoss_interfaces::srv::SetMode>
  : std::true_type
{
};

template<>
struct is_service_request<rmoss_interfaces::srv::SetMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rmoss_interfaces::srv::SetMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__SRV__DETAIL__SET_MODE__TRAITS_HPP_
