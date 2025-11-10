// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:msg/ChassisCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__TRAITS_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/msg/detail/chassis_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__traits.hpp"
// Member 'accel'
#include "geometry_msgs/msg/detail/accel__traits.hpp"

namespace rmoss_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ChassisCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: tid
  {
    out << "tid: ";
    rosidl_generator_traits::value_to_yaml(msg.tid, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: twist
  {
    out << "twist: ";
    to_flow_style_yaml(msg.twist, out);
    out << ", ";
  }

  // member: accel
  {
    out << "accel: ";
    to_flow_style_yaml(msg.accel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChassisCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tid: ";
    rosidl_generator_traits::value_to_yaml(msg.tid, out);
    out << "\n";
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
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

  // member: twist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist:\n";
    to_block_style_yaml(msg.twist, out, indentation + 2);
  }

  // member: accel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accel:\n";
    to_block_style_yaml(msg.accel, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChassisCmd & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::msg::ChassisCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::msg::ChassisCmd & msg)
{
  return rmoss_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::msg::ChassisCmd>()
{
  return "rmoss_interfaces::msg::ChassisCmd";
}

template<>
inline const char * name<rmoss_interfaces::msg::ChassisCmd>()
{
  return "rmoss_interfaces/msg/ChassisCmd";
}

template<>
struct has_fixed_size<rmoss_interfaces::msg::ChassisCmd>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Accel>::value && has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct has_bounded_size<rmoss_interfaces::msg::ChassisCmd>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Accel>::value && has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct is_message<rmoss_interfaces::msg::ChassisCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__TRAITS_HPP_
