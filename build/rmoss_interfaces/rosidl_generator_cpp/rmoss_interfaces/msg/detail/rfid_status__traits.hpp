// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__TRAITS_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/msg/detail/rfid_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmoss_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RfidStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_name
  {
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
    out << ", ";
  }

  // member: supplier_area_is_triggered
  {
    out << "supplier_area_is_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.supplier_area_is_triggered, out);
    out << ", ";
  }

  // member: center_area_is_triggered
  {
    out << "center_area_is_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.center_area_is_triggered, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RfidStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
    out << "\n";
  }

  // member: supplier_area_is_triggered
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "supplier_area_is_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.supplier_area_is_triggered, out);
    out << "\n";
  }

  // member: center_area_is_triggered
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_area_is_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.center_area_is_triggered, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RfidStatus & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::msg::RfidStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::msg::RfidStatus & msg)
{
  return rmoss_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::msg::RfidStatus>()
{
  return "rmoss_interfaces::msg::RfidStatus";
}

template<>
inline const char * name<rmoss_interfaces::msg::RfidStatus>()
{
  return "rmoss_interfaces/msg/RfidStatus";
}

template<>
struct has_fixed_size<rmoss_interfaces::msg::RfidStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rmoss_interfaces::msg::RfidStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rmoss_interfaces::msg::RfidStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__TRAITS_HPP_
