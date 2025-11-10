// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pb_rm_interfaces:msg/Models.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__MODELS__TRAITS_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__MODELS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pb_rm_interfaces/msg/detail/models__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pb_rm_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Models & msg,
  std::ostream & out)
{
  out << "{";
  // member: chassis
  {
    out << "chassis: ";
    rosidl_generator_traits::value_to_yaml(msg.chassis, out);
    out << ", ";
  }

  // member: gimbal
  {
    out << "gimbal: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal, out);
    out << ", ";
  }

  // member: shoot
  {
    out << "shoot: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot, out);
    out << ", ";
  }

  // member: arm
  {
    out << "arm: ";
    rosidl_generator_traits::value_to_yaml(msg.arm, out);
    out << ", ";
  }

  // member: custom_controller
  {
    out << "custom_controller: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_controller, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Models & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: chassis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chassis: ";
    rosidl_generator_traits::value_to_yaml(msg.chassis, out);
    out << "\n";
  }

  // member: gimbal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gimbal: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal, out);
    out << "\n";
  }

  // member: shoot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoot: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot, out);
    out << "\n";
  }

  // member: arm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arm: ";
    rosidl_generator_traits::value_to_yaml(msg.arm, out);
    out << "\n";
  }

  // member: custom_controller
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "custom_controller: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_controller, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Models & msg, bool use_flow_style = false)
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
  const pb_rm_interfaces::msg::Models & msg,
  std::ostream & out, size_t indentation = 0)
{
  pb_rm_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pb_rm_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pb_rm_interfaces::msg::Models & msg)
{
  return pb_rm_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pb_rm_interfaces::msg::Models>()
{
  return "pb_rm_interfaces::msg::Models";
}

template<>
inline const char * name<pb_rm_interfaces::msg::Models>()
{
  return "pb_rm_interfaces/msg/Models";
}

template<>
struct has_fixed_size<pb_rm_interfaces::msg::Models>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pb_rm_interfaces::msg::Models>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pb_rm_interfaces::msg::Models>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PB_RM_INTERFACES__MSG__DETAIL__MODELS__TRAITS_HPP_
