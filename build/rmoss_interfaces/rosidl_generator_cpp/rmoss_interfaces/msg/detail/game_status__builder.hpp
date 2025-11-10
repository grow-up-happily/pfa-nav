// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/msg/detail/game_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace msg
{

namespace builder
{

class Init_GameStatus_result
{
public:
  explicit Init_GameStatus_result(::rmoss_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::msg::GameStatus result(::rmoss_interfaces::msg::GameStatus::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_current_time
{
public:
  explicit Init_GameStatus_current_time(::rmoss_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_result current_time(::rmoss_interfaces::msg::GameStatus::_current_time_type arg)
  {
    msg_.current_time = std::move(arg);
    return Init_GameStatus_result(msg_);
  }

private:
  ::rmoss_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_total_time
{
public:
  explicit Init_GameStatus_total_time(::rmoss_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_current_time total_time(::rmoss_interfaces::msg::GameStatus::_total_time_type arg)
  {
    msg_.total_time = std::move(arg);
    return Init_GameStatus_current_time(msg_);
  }

private:
  ::rmoss_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_status
{
public:
  Init_GameStatus_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GameStatus_total_time status(::rmoss_interfaces::msg::GameStatus::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GameStatus_total_time(msg_);
  }

private:
  ::rmoss_interfaces::msg::GameStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::msg::GameStatus>()
{
  return rmoss_interfaces::msg::builder::Init_GameStatus_status();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
