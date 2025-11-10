// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:srv/ControlTask.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__CONTROL_TASK__BUILDER_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__CONTROL_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/srv/detail/control_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace srv
{

namespace builder
{

class Init_ControlTask_Request_cmd
{
public:
  Init_ControlTask_Request_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rmoss_interfaces::srv::ControlTask_Request cmd(::rmoss_interfaces::srv::ControlTask_Request::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::srv::ControlTask_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::ControlTask_Request>()
{
  return rmoss_interfaces::srv::builder::Init_ControlTask_Request_cmd();
}

}  // namespace rmoss_interfaces


namespace rmoss_interfaces
{

namespace srv
{

namespace builder
{

class Init_ControlTask_Response_success
{
public:
  Init_ControlTask_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rmoss_interfaces::srv::ControlTask_Response success(::rmoss_interfaces::srv::ControlTask_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::srv::ControlTask_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::ControlTask_Response>()
{
  return rmoss_interfaces::srv::builder::Init_ControlTask_Response_success();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__CONTROL_TASK__BUILDER_HPP_
