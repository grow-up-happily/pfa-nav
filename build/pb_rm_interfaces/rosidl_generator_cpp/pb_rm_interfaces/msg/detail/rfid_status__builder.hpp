// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/rfid_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_RfidStatus_center_gain_point
{
public:
  explicit Init_RfidStatus_center_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::RfidStatus center_gain_point(::pb_rm_interfaces::msg::RfidStatus::_center_gain_point_type arg)
  {
    msg_.center_gain_point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_big_resource_island
{
public:
  explicit Init_RfidStatus_enemy_big_resource_island(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_center_gain_point enemy_big_resource_island(::pb_rm_interfaces::msg::RfidStatus::_enemy_big_resource_island_type arg)
  {
    msg_.enemy_big_resource_island = std::move(arg);
    return Init_RfidStatus_center_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_big_resource_island
{
public:
  explicit Init_RfidStatus_friendly_big_resource_island(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_big_resource_island friendly_big_resource_island(::pb_rm_interfaces::msg::RfidStatus::_friendly_big_resource_island_type arg)
  {
    msg_.friendly_big_resource_island = std::move(arg);
    return Init_RfidStatus_enemy_big_resource_island(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_supply_zone_exchange
{
public:
  explicit Init_RfidStatus_friendly_supply_zone_exchange(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_big_resource_island friendly_supply_zone_exchange(::pb_rm_interfaces::msg::RfidStatus::_friendly_supply_zone_exchange_type arg)
  {
    msg_.friendly_supply_zone_exchange = std::move(arg);
    return Init_RfidStatus_friendly_big_resource_island(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_supply_zone_non_exchange
{
public:
  explicit Init_RfidStatus_friendly_supply_zone_non_exchange(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_supply_zone_exchange friendly_supply_zone_non_exchange(::pb_rm_interfaces::msg::RfidStatus::_friendly_supply_zone_non_exchange_type arg)
  {
    msg_.friendly_supply_zone_non_exchange = std::move(arg);
    return Init_RfidStatus_friendly_supply_zone_exchange(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_outpost_gain_point
{
public:
  explicit Init_RfidStatus_friendly_outpost_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_supply_zone_non_exchange friendly_outpost_gain_point(::pb_rm_interfaces::msg::RfidStatus::_friendly_outpost_gain_point_type arg)
  {
    msg_.friendly_outpost_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_supply_zone_non_exchange(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_fortress_gain_point
{
public:
  explicit Init_RfidStatus_friendly_fortress_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_outpost_gain_point friendly_fortress_gain_point(::pb_rm_interfaces::msg::RfidStatus::_friendly_fortress_gain_point_type arg)
  {
    msg_.friendly_fortress_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_outpost_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_highway_upper_gain_point
{
public:
  explicit Init_RfidStatus_enemy_highway_upper_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_fortress_gain_point enemy_highway_upper_gain_point(::pb_rm_interfaces::msg::RfidStatus::_enemy_highway_upper_gain_point_type arg)
  {
    msg_.enemy_highway_upper_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_fortress_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_highway_lower_gain_point
{
public:
  explicit Init_RfidStatus_enemy_highway_lower_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_highway_upper_gain_point enemy_highway_lower_gain_point(::pb_rm_interfaces::msg::RfidStatus::_enemy_highway_lower_gain_point_type arg)
  {
    msg_.enemy_highway_lower_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_highway_upper_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_highway_upper_gain_point
{
public:
  explicit Init_RfidStatus_friendly_highway_upper_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_highway_lower_gain_point friendly_highway_upper_gain_point(::pb_rm_interfaces::msg::RfidStatus::_friendly_highway_upper_gain_point_type arg)
  {
    msg_.friendly_highway_upper_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_highway_lower_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_highway_lower_gain_point
{
public:
  explicit Init_RfidStatus_friendly_highway_lower_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_highway_upper_gain_point friendly_highway_lower_gain_point(::pb_rm_interfaces::msg::RfidStatus::_friendly_highway_lower_gain_point_type arg)
  {
    msg_.friendly_highway_lower_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_highway_upper_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_central_highland_upper_gain_point
{
public:
  explicit Init_RfidStatus_enemy_central_highland_upper_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_highway_lower_gain_point enemy_central_highland_upper_gain_point(::pb_rm_interfaces::msg::RfidStatus::_enemy_central_highland_upper_gain_point_type arg)
  {
    msg_.enemy_central_highland_upper_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_highway_lower_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_central_highland_lower_gain_point
{
public:
  explicit Init_RfidStatus_enemy_central_highland_lower_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_central_highland_upper_gain_point enemy_central_highland_lower_gain_point(::pb_rm_interfaces::msg::RfidStatus::_enemy_central_highland_lower_gain_point_type arg)
  {
    msg_.enemy_central_highland_lower_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_central_highland_upper_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_central_highland_upper_gain_point
{
public:
  explicit Init_RfidStatus_friendly_central_highland_upper_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_central_highland_lower_gain_point friendly_central_highland_upper_gain_point(::pb_rm_interfaces::msg::RfidStatus::_friendly_central_highland_upper_gain_point_type arg)
  {
    msg_.friendly_central_highland_upper_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_central_highland_lower_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_central_highland_lower_gain_point
{
public:
  explicit Init_RfidStatus_friendly_central_highland_lower_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_central_highland_upper_gain_point friendly_central_highland_lower_gain_point(::pb_rm_interfaces::msg::RfidStatus::_friendly_central_highland_lower_gain_point_type arg)
  {
    msg_.friendly_central_highland_lower_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_central_highland_upper_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_fly_ramp_back_gain_point
{
public:
  explicit Init_RfidStatus_enemy_fly_ramp_back_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_central_highland_lower_gain_point enemy_fly_ramp_back_gain_point(::pb_rm_interfaces::msg::RfidStatus::_enemy_fly_ramp_back_gain_point_type arg)
  {
    msg_.enemy_fly_ramp_back_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_central_highland_lower_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_fly_ramp_front_gain_point
{
public:
  explicit Init_RfidStatus_enemy_fly_ramp_front_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_fly_ramp_back_gain_point enemy_fly_ramp_front_gain_point(::pb_rm_interfaces::msg::RfidStatus::_enemy_fly_ramp_front_gain_point_type arg)
  {
    msg_.enemy_fly_ramp_front_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_fly_ramp_back_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_fly_ramp_back_gain_point
{
public:
  explicit Init_RfidStatus_friendly_fly_ramp_back_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_fly_ramp_front_gain_point friendly_fly_ramp_back_gain_point(::pb_rm_interfaces::msg::RfidStatus::_friendly_fly_ramp_back_gain_point_type arg)
  {
    msg_.friendly_fly_ramp_back_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_fly_ramp_front_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_fly_ramp_front_gain_point
{
public:
  explicit Init_RfidStatus_friendly_fly_ramp_front_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_fly_ramp_back_gain_point friendly_fly_ramp_front_gain_point(::pb_rm_interfaces::msg::RfidStatus::_friendly_fly_ramp_front_gain_point_type arg)
  {
    msg_.friendly_fly_ramp_front_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_fly_ramp_back_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_trapezoidal_highland_gain_point
{
public:
  explicit Init_RfidStatus_enemy_trapezoidal_highland_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_fly_ramp_front_gain_point enemy_trapezoidal_highland_gain_point(::pb_rm_interfaces::msg::RfidStatus::_enemy_trapezoidal_highland_gain_point_type arg)
  {
    msg_.enemy_trapezoidal_highland_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_fly_ramp_front_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_trapezoidal_highland_gain_point
{
public:
  explicit Init_RfidStatus_friendly_trapezoidal_highland_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_trapezoidal_highland_gain_point friendly_trapezoidal_highland_gain_point(::pb_rm_interfaces::msg::RfidStatus::_friendly_trapezoidal_highland_gain_point_type arg)
  {
    msg_.friendly_trapezoidal_highland_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_trapezoidal_highland_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_central_highland_gain_point
{
public:
  explicit Init_RfidStatus_enemy_central_highland_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_trapezoidal_highland_gain_point enemy_central_highland_gain_point(::pb_rm_interfaces::msg::RfidStatus::_enemy_central_highland_gain_point_type arg)
  {
    msg_.enemy_central_highland_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_trapezoidal_highland_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_central_highland_gain_point
{
public:
  explicit Init_RfidStatus_central_highland_gain_point(::pb_rm_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_central_highland_gain_point central_highland_gain_point(::pb_rm_interfaces::msg::RfidStatus::_central_highland_gain_point_type arg)
  {
    msg_.central_highland_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_central_highland_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_base_gain_point
{
public:
  Init_RfidStatus_base_gain_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RfidStatus_central_highland_gain_point base_gain_point(::pb_rm_interfaces::msg::RfidStatus::_base_gain_point_type arg)
  {
    msg_.base_gain_point = std::move(arg);
    return Init_RfidStatus_central_highland_gain_point(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RfidStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::RfidStatus>()
{
  return pb_rm_interfaces::msg::builder::Init_RfidStatus_base_gain_point();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__BUILDER_HPP_
