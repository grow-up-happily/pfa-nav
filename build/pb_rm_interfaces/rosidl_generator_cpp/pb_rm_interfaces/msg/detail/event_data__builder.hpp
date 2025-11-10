// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/EventData.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/event_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_EventData_center_gain_zone
{
public:
  explicit Init_EventData_center_gain_zone(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::EventData center_gain_zone(::pb_rm_interfaces::msg::EventData::_center_gain_zone_type arg)
  {
    msg_.center_gain_zone = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_trapezoidal_highland
{
public:
  explicit Init_EventData_trapezoidal_highland(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_center_gain_zone trapezoidal_highland(::pb_rm_interfaces::msg::EventData::_trapezoidal_highland_type arg)
  {
    msg_.trapezoidal_highland = std::move(arg);
    return Init_EventData_center_gain_zone(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_central_highland
{
public:
  explicit Init_EventData_central_highland(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_trapezoidal_highland central_highland(::pb_rm_interfaces::msg::EventData::_central_highland_type arg)
  {
    msg_.central_highland = std::move(arg);
    return Init_EventData_trapezoidal_highland(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_big_energy
{
public:
  explicit Init_EventData_big_energy(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_central_highland big_energy(::pb_rm_interfaces::msg::EventData::_big_energy_type arg)
  {
    msg_.big_energy = std::move(arg);
    return Init_EventData_central_highland(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_small_energy
{
public:
  explicit Init_EventData_small_energy(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_big_energy small_energy(::pb_rm_interfaces::msg::EventData::_small_energy_type arg)
  {
    msg_.small_energy = std::move(arg);
    return Init_EventData_big_energy(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_supply_zone
{
public:
  explicit Init_EventData_supply_zone(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_small_energy supply_zone(::pb_rm_interfaces::msg::EventData::_supply_zone_type arg)
  {
    msg_.supply_zone = std::move(arg);
    return Init_EventData_small_energy(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_overlapping_supply_zone
{
public:
  explicit Init_EventData_overlapping_supply_zone(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_supply_zone overlapping_supply_zone(::pb_rm_interfaces::msg::EventData::_overlapping_supply_zone_type arg)
  {
    msg_.overlapping_supply_zone = std::move(arg);
    return Init_EventData_supply_zone(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_non_overlapping_supply_zone
{
public:
  Init_EventData_non_overlapping_supply_zone()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EventData_overlapping_supply_zone non_overlapping_supply_zone(::pb_rm_interfaces::msg::EventData::_non_overlapping_supply_zone_type arg)
  {
    msg_.non_overlapping_supply_zone = std::move(arg);
    return Init_EventData_overlapping_supply_zone(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::EventData>()
{
  return pb_rm_interfaces::msg::builder::Init_EventData_non_overlapping_supply_zone();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__BUILDER_HPP_
