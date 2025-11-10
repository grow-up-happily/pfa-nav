// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:srv/ExchangeAmmon.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__BUILDER_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/srv/detail/exchange_ammon__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace srv
{

namespace builder
{

class Init_ExchangeAmmon_Request_ammo_amount
{
public:
  explicit Init_ExchangeAmmon_Request_ammo_amount(::rmoss_interfaces::srv::ExchangeAmmon_Request & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::srv::ExchangeAmmon_Request ammo_amount(::rmoss_interfaces::srv::ExchangeAmmon_Request::_ammo_amount_type arg)
  {
    msg_.ammo_amount = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::srv::ExchangeAmmon_Request msg_;
};

class Init_ExchangeAmmon_Request_robot_name
{
public:
  Init_ExchangeAmmon_Request_robot_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExchangeAmmon_Request_ammo_amount robot_name(::rmoss_interfaces::srv::ExchangeAmmon_Request::_robot_name_type arg)
  {
    msg_.robot_name = std::move(arg);
    return Init_ExchangeAmmon_Request_ammo_amount(msg_);
  }

private:
  ::rmoss_interfaces::srv::ExchangeAmmon_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::ExchangeAmmon_Request>()
{
  return rmoss_interfaces::srv::builder::Init_ExchangeAmmon_Request_robot_name();
}

}  // namespace rmoss_interfaces


namespace rmoss_interfaces
{

namespace srv
{

namespace builder
{

class Init_ExchangeAmmon_Response_message
{
public:
  explicit Init_ExchangeAmmon_Response_message(::rmoss_interfaces::srv::ExchangeAmmon_Response & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::srv::ExchangeAmmon_Response message(::rmoss_interfaces::srv::ExchangeAmmon_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::srv::ExchangeAmmon_Response msg_;
};

class Init_ExchangeAmmon_Response_success
{
public:
  Init_ExchangeAmmon_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExchangeAmmon_Response_message success(::rmoss_interfaces::srv::ExchangeAmmon_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExchangeAmmon_Response_message(msg_);
  }

private:
  ::rmoss_interfaces::srv::ExchangeAmmon_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::ExchangeAmmon_Response>()
{
  return rmoss_interfaces::srv::builder::Init_ExchangeAmmon_Response_success();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__BUILDER_HPP_
