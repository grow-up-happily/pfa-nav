// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:msg/RfidStatusArray.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__TRAITS_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/msg/detail/rfid_status_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'robot_rfid_status'
#include "rmoss_interfaces/msg/detail/rfid_status__traits.hpp"

namespace rmoss_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RfidStatusArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_rfid_status
  {
    if (msg.robot_rfid_status.size() == 0) {
      out << "robot_rfid_status: []";
    } else {
      out << "robot_rfid_status: [";
      size_t pending_items = msg.robot_rfid_status.size();
      for (auto item : msg.robot_rfid_status) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RfidStatusArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_rfid_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_rfid_status.size() == 0) {
      out << "robot_rfid_status: []\n";
    } else {
      out << "robot_rfid_status:\n";
      for (auto item : msg.robot_rfid_status) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RfidStatusArray & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::msg::RfidStatusArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::msg::RfidStatusArray & msg)
{
  return rmoss_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::msg::RfidStatusArray>()
{
  return "rmoss_interfaces::msg::RfidStatusArray";
}

template<>
inline const char * name<rmoss_interfaces::msg::RfidStatusArray>()
{
  return "rmoss_interfaces/msg/RfidStatusArray";
}

template<>
struct has_fixed_size<rmoss_interfaces::msg::RfidStatusArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rmoss_interfaces::msg::RfidStatusArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rmoss_interfaces::msg::RfidStatusArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__TRAITS_HPP_
