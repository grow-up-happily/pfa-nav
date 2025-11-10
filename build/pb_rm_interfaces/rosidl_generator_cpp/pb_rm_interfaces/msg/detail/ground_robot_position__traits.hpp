// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pb_rm_interfaces:msg/GroundRobotPosition.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__TRAITS_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pb_rm_interfaces/msg/detail/ground_robot_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'hero_position'
// Member 'engineer_position'
// Member 'standard_3_position'
// Member 'standard_4_position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace pb_rm_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GroundRobotPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: hero_position
  {
    out << "hero_position: ";
    to_flow_style_yaml(msg.hero_position, out);
    out << ", ";
  }

  // member: engineer_position
  {
    out << "engineer_position: ";
    to_flow_style_yaml(msg.engineer_position, out);
    out << ", ";
  }

  // member: standard_3_position
  {
    out << "standard_3_position: ";
    to_flow_style_yaml(msg.standard_3_position, out);
    out << ", ";
  }

  // member: standard_4_position
  {
    out << "standard_4_position: ";
    to_flow_style_yaml(msg.standard_4_position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GroundRobotPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hero_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hero_position:\n";
    to_block_style_yaml(msg.hero_position, out, indentation + 2);
  }

  // member: engineer_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "engineer_position:\n";
    to_block_style_yaml(msg.engineer_position, out, indentation + 2);
  }

  // member: standard_3_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "standard_3_position:\n";
    to_block_style_yaml(msg.standard_3_position, out, indentation + 2);
  }

  // member: standard_4_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "standard_4_position:\n";
    to_block_style_yaml(msg.standard_4_position, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GroundRobotPosition & msg, bool use_flow_style = false)
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
  const pb_rm_interfaces::msg::GroundRobotPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  pb_rm_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pb_rm_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pb_rm_interfaces::msg::GroundRobotPosition & msg)
{
  return pb_rm_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pb_rm_interfaces::msg::GroundRobotPosition>()
{
  return "pb_rm_interfaces::msg::GroundRobotPosition";
}

template<>
inline const char * name<pb_rm_interfaces::msg::GroundRobotPosition>()
{
  return "pb_rm_interfaces/msg/GroundRobotPosition";
}

template<>
struct has_fixed_size<pb_rm_interfaces::msg::GroundRobotPosition>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<pb_rm_interfaces::msg::GroundRobotPosition>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<pb_rm_interfaces::msg::GroundRobotPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__TRAITS_HPP_
