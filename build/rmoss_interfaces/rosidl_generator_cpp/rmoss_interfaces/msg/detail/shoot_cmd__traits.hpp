// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:msg/ShootCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__TRAITS_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/msg/detail/shoot_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmoss_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ShootCmd & msg,
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

  // member: projectile_num
  {
    out << "projectile_num: ";
    rosidl_generator_traits::value_to_yaml(msg.projectile_num, out);
    out << ", ";
  }

  // member: projectile_velocity
  {
    out << "projectile_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.projectile_velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ShootCmd & msg,
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

  // member: projectile_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "projectile_num: ";
    rosidl_generator_traits::value_to_yaml(msg.projectile_num, out);
    out << "\n";
  }

  // member: projectile_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "projectile_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.projectile_velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ShootCmd & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::msg::ShootCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::msg::ShootCmd & msg)
{
  return rmoss_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::msg::ShootCmd>()
{
  return "rmoss_interfaces::msg::ShootCmd";
}

template<>
inline const char * name<rmoss_interfaces::msg::ShootCmd>()
{
  return "rmoss_interfaces/msg/ShootCmd";
}

template<>
struct has_fixed_size<rmoss_interfaces::msg::ShootCmd>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rmoss_interfaces::msg::ShootCmd>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rmoss_interfaces::msg::ShootCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__TRAITS_HPP_
