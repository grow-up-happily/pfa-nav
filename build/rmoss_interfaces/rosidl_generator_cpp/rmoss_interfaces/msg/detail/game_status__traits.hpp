// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__TRAITS_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/msg/detail/game_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmoss_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GameStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: total_time
  {
    out << "total_time: ";
    rosidl_generator_traits::value_to_yaml(msg.total_time, out);
    out << ", ";
  }

  // member: current_time
  {
    out << "current_time: ";
    rosidl_generator_traits::value_to_yaml(msg.current_time, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GameStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: total_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_time: ";
    rosidl_generator_traits::value_to_yaml(msg.total_time, out);
    out << "\n";
  }

  // member: current_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_time: ";
    rosidl_generator_traits::value_to_yaml(msg.current_time, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GameStatus & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::msg::GameStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::msg::GameStatus & msg)
{
  return rmoss_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::msg::GameStatus>()
{
  return "rmoss_interfaces::msg::GameStatus";
}

template<>
inline const char * name<rmoss_interfaces::msg::GameStatus>()
{
  return "rmoss_interfaces/msg/GameStatus";
}

template<>
struct has_fixed_size<rmoss_interfaces::msg::GameStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rmoss_interfaces::msg::GameStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rmoss_interfaces::msg::GameStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__TRAITS_HPP_
