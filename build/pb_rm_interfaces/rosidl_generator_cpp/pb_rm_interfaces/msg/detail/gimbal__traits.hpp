// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pb_rm_interfaces:msg/Gimbal.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__TRAITS_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pb_rm_interfaces/msg/detail/gimbal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pb_rm_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Gimbal & msg,
  std::ostream & out)
{
  out << "{";
  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: pitch_min_range
  {
    out << "pitch_min_range: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_min_range, out);
    out << ", ";
  }

  // member: pitch_max_range
  {
    out << "pitch_max_range: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_max_range, out);
    out << ", ";
  }

  // member: yaw_min_range
  {
    out << "yaw_min_range: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_min_range, out);
    out << ", ";
  }

  // member: yaw_max_range
  {
    out << "yaw_max_range: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_max_range, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Gimbal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: pitch_min_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_min_range: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_min_range, out);
    out << "\n";
  }

  // member: pitch_max_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_max_range: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_max_range, out);
    out << "\n";
  }

  // member: yaw_min_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_min_range: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_min_range, out);
    out << "\n";
  }

  // member: yaw_max_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_max_range: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_max_range, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gimbal & msg, bool use_flow_style = false)
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
  const pb_rm_interfaces::msg::Gimbal & msg,
  std::ostream & out, size_t indentation = 0)
{
  pb_rm_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pb_rm_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pb_rm_interfaces::msg::Gimbal & msg)
{
  return pb_rm_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pb_rm_interfaces::msg::Gimbal>()
{
  return "pb_rm_interfaces::msg::Gimbal";
}

template<>
inline const char * name<pb_rm_interfaces::msg::Gimbal>()
{
  return "pb_rm_interfaces/msg/Gimbal";
}

template<>
struct has_fixed_size<pb_rm_interfaces::msg::Gimbal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pb_rm_interfaces::msg::Gimbal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pb_rm_interfaces::msg::Gimbal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__TRAITS_HPP_
