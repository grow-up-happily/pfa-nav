// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:msg/ExchangeAmmon.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__EXCHANGE_AMMON__TRAITS_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__EXCHANGE_AMMON__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/msg/detail/exchange_ammon__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmoss_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ExchangeAmmon & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_name
  {
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
    out << ", ";
  }

  // member: ammo_request
  {
    out << "ammo_request: ";
    rosidl_generator_traits::value_to_yaml(msg.ammo_request, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExchangeAmmon & msg,
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

  // member: ammo_request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ammo_request: ";
    rosidl_generator_traits::value_to_yaml(msg.ammo_request, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExchangeAmmon & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::msg::ExchangeAmmon & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::msg::ExchangeAmmon & msg)
{
  return rmoss_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::msg::ExchangeAmmon>()
{
  return "rmoss_interfaces::msg::ExchangeAmmon";
}

template<>
inline const char * name<rmoss_interfaces::msg::ExchangeAmmon>()
{
  return "rmoss_interfaces/msg/ExchangeAmmon";
}

template<>
struct has_fixed_size<rmoss_interfaces::msg::ExchangeAmmon>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rmoss_interfaces::msg::ExchangeAmmon>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rmoss_interfaces::msg::ExchangeAmmon>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__MSG__DETAIL__EXCHANGE_AMMON__TRAITS_HPP_
