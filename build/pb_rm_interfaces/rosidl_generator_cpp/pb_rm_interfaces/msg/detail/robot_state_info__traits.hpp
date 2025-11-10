// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pb_rm_interfaces:msg/RobotStateInfo.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__TRAITS_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pb_rm_interfaces/msg/detail/robot_state_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'models'
#include "pb_rm_interfaces/msg/detail/models__traits.hpp"

namespace pb_rm_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStateInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: models
  {
    out << "models: ";
    to_flow_style_yaml(msg.models, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStateInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: models
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "models:\n";
    to_block_style_yaml(msg.models, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStateInfo & msg, bool use_flow_style = false)
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

}  // namespace pb_rm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use pb_rm_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pb_rm_interfaces::msg::RobotStateInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  pb_rm_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pb_rm_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pb_rm_interfaces::msg::RobotStateInfo & msg)
{
  return pb_rm_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pb_rm_interfaces::msg::RobotStateInfo>()
{
  return "pb_rm_interfaces::msg::RobotStateInfo";
}

template<>
inline const char * name<pb_rm_interfaces::msg::RobotStateInfo>()
{
  return "pb_rm_interfaces/msg/RobotStateInfo";
}

template<>
struct has_fixed_size<pb_rm_interfaces::msg::RobotStateInfo>
  : std::integral_constant<bool, has_fixed_size<pb_rm_interfaces::msg::Models>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<pb_rm_interfaces::msg::RobotStateInfo>
  : std::integral_constant<bool, has_bounded_size<pb_rm_interfaces::msg::Models>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<pb_rm_interfaces::msg::RobotStateInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__TRAITS_HPP_
