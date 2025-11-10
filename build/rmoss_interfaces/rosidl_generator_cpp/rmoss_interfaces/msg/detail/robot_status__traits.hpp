// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'gt_tf'
#include "geometry_msgs/msg/detail/transform__traits.hpp"

namespace rmoss_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: level
  {
    out << "level: ";
    rosidl_generator_traits::value_to_yaml(msg.level, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: remain_hp
  {
    out << "remain_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.remain_hp, out);
    out << ", ";
  }

  // member: max_hp
  {
    out << "max_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.max_hp, out);
    out << ", ";
  }

  // member: total_projectiles
  {
    out << "total_projectiles: ";
    rosidl_generator_traits::value_to_yaml(msg.total_projectiles, out);
    out << ", ";
  }

  // member: used_projectiles
  {
    out << "used_projectiles: ";
    rosidl_generator_traits::value_to_yaml(msg.used_projectiles, out);
    out << ", ";
  }

  // member: hit_projectiles
  {
    out << "hit_projectiles: ";
    rosidl_generator_traits::value_to_yaml(msg.hit_projectiles, out);
    out << ", ";
  }

  // member: gt_tf
  {
    out << "gt_tf: ";
    to_flow_style_yaml(msg.gt_tf, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "level: ";
    rosidl_generator_traits::value_to_yaml(msg.level, out);
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

  // member: remain_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remain_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.remain_hp, out);
    out << "\n";
  }

  // member: max_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.max_hp, out);
    out << "\n";
  }

  // member: total_projectiles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_projectiles: ";
    rosidl_generator_traits::value_to_yaml(msg.total_projectiles, out);
    out << "\n";
  }

  // member: used_projectiles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "used_projectiles: ";
    rosidl_generator_traits::value_to_yaml(msg.used_projectiles, out);
    out << "\n";
  }

  // member: hit_projectiles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hit_projectiles: ";
    rosidl_generator_traits::value_to_yaml(msg.hit_projectiles, out);
    out << "\n";
  }

  // member: gt_tf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gt_tf:\n";
    to_block_style_yaml(msg.gt_tf, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStatus & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::msg::RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::msg::RobotStatus & msg)
{
  return rmoss_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::msg::RobotStatus>()
{
  return "rmoss_interfaces::msg::RobotStatus";
}

template<>
inline const char * name<rmoss_interfaces::msg::RobotStatus>()
{
  return "rmoss_interfaces/msg/RobotStatus";
}

template<>
struct has_fixed_size<rmoss_interfaces::msg::RobotStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rmoss_interfaces::msg::RobotStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rmoss_interfaces::msg::RobotStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
