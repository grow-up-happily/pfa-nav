// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:msg/Gimbal.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GIMBAL__TRAITS_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__GIMBAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/msg/detail/gimbal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmoss_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Gimbal & msg,
  std::ostream & out)
{
  out << "{";
  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Gimbal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gimbal & msg, bool use_flow_style = false)
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

}  // namespace rmoss_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rmoss_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rmoss_interfaces::msg::Gimbal & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::msg::Gimbal & msg)
{
  return rmoss_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::msg::Gimbal>()
{
  return "rmoss_interfaces::msg::Gimbal";
}

template<>
inline const char * name<rmoss_interfaces::msg::Gimbal>()
{
  return "rmoss_interfaces/msg/Gimbal";
}

template<>
struct has_fixed_size<rmoss_interfaces::msg::Gimbal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rmoss_interfaces::msg::Gimbal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rmoss_interfaces::msg::Gimbal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GIMBAL__TRAITS_HPP_
