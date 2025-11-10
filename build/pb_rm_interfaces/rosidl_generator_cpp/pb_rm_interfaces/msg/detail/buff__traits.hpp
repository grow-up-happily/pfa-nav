// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pb_rm_interfaces:msg/Buff.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__BUFF__TRAITS_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__BUFF__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pb_rm_interfaces/msg/detail/buff__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pb_rm_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Buff & msg,
  std::ostream & out)
{
  out << "{";
  // member: recovery_buff
  {
    out << "recovery_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.recovery_buff, out);
    out << ", ";
  }

  // member: cooling_buff
  {
    out << "cooling_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.cooling_buff, out);
    out << ", ";
  }

  // member: defence_buff
  {
    out << "defence_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.defence_buff, out);
    out << ", ";
  }

  // member: vulnerability_buff
  {
    out << "vulnerability_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.vulnerability_buff, out);
    out << ", ";
  }

  // member: attack_buff
  {
    out << "attack_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.attack_buff, out);
    out << ", ";
  }

  // member: remaining_energy
  {
    out << "remaining_energy: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_energy, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Buff & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: recovery_buff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "recovery_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.recovery_buff, out);
    out << "\n";
  }

  // member: cooling_buff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cooling_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.cooling_buff, out);
    out << "\n";
  }

  // member: defence_buff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "defence_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.defence_buff, out);
    out << "\n";
  }

  // member: vulnerability_buff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vulnerability_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.vulnerability_buff, out);
    out << "\n";
  }

  // member: attack_buff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "attack_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.attack_buff, out);
    out << "\n";
  }

  // member: remaining_energy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remaining_energy: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_energy, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Buff & msg, bool use_flow_style = false)
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
  const pb_rm_interfaces::msg::Buff & msg,
  std::ostream & out, size_t indentation = 0)
{
  pb_rm_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pb_rm_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pb_rm_interfaces::msg::Buff & msg)
{
  return pb_rm_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pb_rm_interfaces::msg::Buff>()
{
  return "pb_rm_interfaces::msg::Buff";
}

template<>
inline const char * name<pb_rm_interfaces::msg::Buff>()
{
  return "pb_rm_interfaces/msg/Buff";
}

template<>
struct has_fixed_size<pb_rm_interfaces::msg::Buff>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pb_rm_interfaces::msg::Buff>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pb_rm_interfaces::msg::Buff>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PB_RM_INTERFACES__MSG__DETAIL__BUFF__TRAITS_HPP_
