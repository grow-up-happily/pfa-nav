// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__TRAITS_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pb_rm_interfaces/msg/detail/rfid_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pb_rm_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RfidStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: base_gain_point
  {
    out << "base_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.base_gain_point, out);
    out << ", ";
  }

  // member: central_highland_gain_point
  {
    out << "central_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.central_highland_gain_point, out);
    out << ", ";
  }

  // member: enemy_central_highland_gain_point
  {
    out << "enemy_central_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_gain_point, out);
    out << ", ";
  }

  // member: friendly_trapezoidal_highland_gain_point
  {
    out << "friendly_trapezoidal_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_trapezoidal_highland_gain_point, out);
    out << ", ";
  }

  // member: enemy_trapezoidal_highland_gain_point
  {
    out << "enemy_trapezoidal_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_trapezoidal_highland_gain_point, out);
    out << ", ";
  }

  // member: friendly_fly_ramp_front_gain_point
  {
    out << "friendly_fly_ramp_front_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fly_ramp_front_gain_point, out);
    out << ", ";
  }

  // member: friendly_fly_ramp_back_gain_point
  {
    out << "friendly_fly_ramp_back_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fly_ramp_back_gain_point, out);
    out << ", ";
  }

  // member: enemy_fly_ramp_front_gain_point
  {
    out << "enemy_fly_ramp_front_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fly_ramp_front_gain_point, out);
    out << ", ";
  }

  // member: enemy_fly_ramp_back_gain_point
  {
    out << "enemy_fly_ramp_back_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fly_ramp_back_gain_point, out);
    out << ", ";
  }

  // member: friendly_central_highland_lower_gain_point
  {
    out << "friendly_central_highland_lower_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_lower_gain_point, out);
    out << ", ";
  }

  // member: friendly_central_highland_upper_gain_point
  {
    out << "friendly_central_highland_upper_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_upper_gain_point, out);
    out << ", ";
  }

  // member: enemy_central_highland_lower_gain_point
  {
    out << "enemy_central_highland_lower_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_lower_gain_point, out);
    out << ", ";
  }

  // member: enemy_central_highland_upper_gain_point
  {
    out << "enemy_central_highland_upper_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_upper_gain_point, out);
    out << ", ";
  }

  // member: friendly_highway_lower_gain_point
  {
    out << "friendly_highway_lower_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_highway_lower_gain_point, out);
    out << ", ";
  }

  // member: friendly_highway_upper_gain_point
  {
    out << "friendly_highway_upper_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_highway_upper_gain_point, out);
    out << ", ";
  }

  // member: enemy_highway_lower_gain_point
  {
    out << "enemy_highway_lower_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_highway_lower_gain_point, out);
    out << ", ";
  }

  // member: enemy_highway_upper_gain_point
  {
    out << "enemy_highway_upper_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_highway_upper_gain_point, out);
    out << ", ";
  }

  // member: friendly_fortress_gain_point
  {
    out << "friendly_fortress_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fortress_gain_point, out);
    out << ", ";
  }

  // member: friendly_outpost_gain_point
  {
    out << "friendly_outpost_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_outpost_gain_point, out);
    out << ", ";
  }

  // member: friendly_supply_zone_non_exchange
  {
    out << "friendly_supply_zone_non_exchange: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_supply_zone_non_exchange, out);
    out << ", ";
  }

  // member: friendly_supply_zone_exchange
  {
    out << "friendly_supply_zone_exchange: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_supply_zone_exchange, out);
    out << ", ";
  }

  // member: friendly_big_resource_island
  {
    out << "friendly_big_resource_island: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_big_resource_island, out);
    out << ", ";
  }

  // member: enemy_big_resource_island
  {
    out << "enemy_big_resource_island: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_big_resource_island, out);
    out << ", ";
  }

  // member: center_gain_point
  {
    out << "center_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.center_gain_point, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RfidStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: base_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "base_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.base_gain_point, out);
    out << "\n";
  }

  // member: central_highland_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "central_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.central_highland_gain_point, out);
    out << "\n";
  }

  // member: enemy_central_highland_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_central_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_gain_point, out);
    out << "\n";
  }

  // member: friendly_trapezoidal_highland_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_trapezoidal_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_trapezoidal_highland_gain_point, out);
    out << "\n";
  }

  // member: enemy_trapezoidal_highland_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_trapezoidal_highland_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_trapezoidal_highland_gain_point, out);
    out << "\n";
  }

  // member: friendly_fly_ramp_front_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_fly_ramp_front_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fly_ramp_front_gain_point, out);
    out << "\n";
  }

  // member: friendly_fly_ramp_back_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_fly_ramp_back_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fly_ramp_back_gain_point, out);
    out << "\n";
  }

  // member: enemy_fly_ramp_front_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_fly_ramp_front_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fly_ramp_front_gain_point, out);
    out << "\n";
  }

  // member: enemy_fly_ramp_back_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_fly_ramp_back_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_fly_ramp_back_gain_point, out);
    out << "\n";
  }

  // member: friendly_central_highland_lower_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_central_highland_lower_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_lower_gain_point, out);
    out << "\n";
  }

  // member: friendly_central_highland_upper_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_central_highland_upper_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_central_highland_upper_gain_point, out);
    out << "\n";
  }

  // member: enemy_central_highland_lower_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_central_highland_lower_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_lower_gain_point, out);
    out << "\n";
  }

  // member: enemy_central_highland_upper_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_central_highland_upper_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_central_highland_upper_gain_point, out);
    out << "\n";
  }

  // member: friendly_highway_lower_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_highway_lower_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_highway_lower_gain_point, out);
    out << "\n";
  }

  // member: friendly_highway_upper_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_highway_upper_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_highway_upper_gain_point, out);
    out << "\n";
  }

  // member: enemy_highway_lower_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_highway_lower_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_highway_lower_gain_point, out);
    out << "\n";
  }

  // member: enemy_highway_upper_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_highway_upper_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_highway_upper_gain_point, out);
    out << "\n";
  }

  // member: friendly_fortress_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_fortress_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_fortress_gain_point, out);
    out << "\n";
  }

  // member: friendly_outpost_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_outpost_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_outpost_gain_point, out);
    out << "\n";
  }

  // member: friendly_supply_zone_non_exchange
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_supply_zone_non_exchange: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_supply_zone_non_exchange, out);
    out << "\n";
  }

  // member: friendly_supply_zone_exchange
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_supply_zone_exchange: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_supply_zone_exchange, out);
    out << "\n";
  }

  // member: friendly_big_resource_island
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "friendly_big_resource_island: ";
    rosidl_generator_traits::value_to_yaml(msg.friendly_big_resource_island, out);
    out << "\n";
  }

  // member: enemy_big_resource_island
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_big_resource_island: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_big_resource_island, out);
    out << "\n";
  }

  // member: center_gain_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_gain_point: ";
    rosidl_generator_traits::value_to_yaml(msg.center_gain_point, out);
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

}  // namespace pb_rm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use pb_rm_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pb_rm_interfaces::msg::RfidStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  pb_rm_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pb_rm_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pb_rm_interfaces::msg::RfidStatus & msg)
{
  return pb_rm_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pb_rm_interfaces::msg::RfidStatus>()
{
  return "pb_rm_interfaces::msg::RfidStatus";
}

template<>
inline const char * name<pb_rm_interfaces::msg::RfidStatus>()
{
  return "pb_rm_interfaces/msg/RfidStatus";
}

template<>
struct has_fixed_size<pb_rm_interfaces::msg::RfidStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pb_rm_interfaces::msg::RfidStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pb_rm_interfaces::msg::RfidStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__TRAITS_HPP_
