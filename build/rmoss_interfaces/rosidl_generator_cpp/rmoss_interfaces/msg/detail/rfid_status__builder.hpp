// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__BUILDER_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/msg/detail/rfid_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace msg
{

namespace builder
{

class Init_RfidStatus_center_area_is_triggered
{
public:
  explicit Init_RfidStatus_center_area_is_triggered(::rmoss_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::msg::RfidStatus center_area_is_triggered(::rmoss_interfaces::msg::RfidStatus::_center_area_is_triggered_type arg)
  {
    msg_.center_area_is_triggered = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_supplier_area_is_triggered
{
public:
  explicit Init_RfidStatus_supplier_area_is_triggered(::rmoss_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_center_area_is_triggered supplier_area_is_triggered(::rmoss_interfaces::msg::RfidStatus::_supplier_area_is_triggered_type arg)
  {
    msg_.supplier_area_is_triggered = std::move(arg);
    return Init_RfidStatus_center_area_is_triggered(msg_);
  }

private:
  ::rmoss_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_robot_name
{
public:
  Init_RfidStatus_robot_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RfidStatus_supplier_area_is_triggered robot_name(::rmoss_interfaces::msg::RfidStatus::_robot_name_type arg)
  {
    msg_.robot_name = std::move(arg);
    return Init_RfidStatus_supplier_area_is_triggered(msg_);
  }

private:
  ::rmoss_interfaces::msg::RfidStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::msg::RfidStatus>()
{
  return rmoss_interfaces::msg::builder::Init_RfidStatus_robot_name();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__BUILDER_HPP_
