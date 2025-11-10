// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:msg/ExchangeAmmon.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__EXCHANGE_AMMON__BUILDER_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__EXCHANGE_AMMON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/msg/detail/exchange_ammon__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace msg
{

namespace builder
{

class Init_ExchangeAmmon_ammo_request
{
public:
  explicit Init_ExchangeAmmon_ammo_request(::rmoss_interfaces::msg::ExchangeAmmon & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::msg::ExchangeAmmon ammo_request(::rmoss_interfaces::msg::ExchangeAmmon::_ammo_request_type arg)
  {
    msg_.ammo_request = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::msg::ExchangeAmmon msg_;
};

class Init_ExchangeAmmon_robot_name
{
public:
  Init_ExchangeAmmon_robot_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExchangeAmmon_ammo_request robot_name(::rmoss_interfaces::msg::ExchangeAmmon::_robot_name_type arg)
  {
    msg_.robot_name = std::move(arg);
    return Init_ExchangeAmmon_ammo_request(msg_);
  }

private:
  ::rmoss_interfaces::msg::ExchangeAmmon msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::msg::ExchangeAmmon>()
{
  return rmoss_interfaces::msg::builder::Init_ExchangeAmmon_robot_name();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__EXCHANGE_AMMON__BUILDER_HPP_
