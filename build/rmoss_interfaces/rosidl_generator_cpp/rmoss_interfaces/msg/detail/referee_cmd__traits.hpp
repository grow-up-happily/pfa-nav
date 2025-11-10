// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:msg/RefereeCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__TRAITS_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/msg/detail/referee_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmoss_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RefereeCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd
  {
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
    out << ", ";
  }

  // member: robot_name
  {
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RefereeCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
    out << "\n";
  }

  // member: robot_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RefereeCmd & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::msg::RefereeCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::msg::RefereeCmd & msg)
{
  return rmoss_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::msg::RefereeCmd>()
{
  return "rmoss_interfaces::msg::RefereeCmd";
}

template<>
inline const char * name<rmoss_interfaces::msg::RefereeCmd>()
{
  return "rmoss_interfaces/msg/RefereeCmd";
}

template<>
struct has_fixed_size<rmoss_interfaces::msg::RefereeCmd>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rmoss_interfaces::msg::RefereeCmd>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rmoss_interfaces::msg::RefereeCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__TRAITS_HPP_
