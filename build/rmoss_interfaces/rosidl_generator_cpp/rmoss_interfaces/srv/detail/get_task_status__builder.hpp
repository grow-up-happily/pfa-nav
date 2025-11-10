// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:srv/GetTaskStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__GET_TASK_STATUS__BUILDER_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__GET_TASK_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/srv/detail/get_task_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::GetTaskStatus_Request>()
{
  return ::rmoss_interfaces::srv::GetTaskStatus_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace rmoss_interfaces


namespace rmoss_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetTaskStatus_Response_status
{
public:
  Init_GetTaskStatus_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rmoss_interfaces::srv::GetTaskStatus_Response status(::rmoss_interfaces::srv::GetTaskStatus_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::srv::GetTaskStatus_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::GetTaskStatus_Response>()
{
  return rmoss_interfaces::srv::builder::Init_GetTaskStatus_Response_status();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__GET_TASK_STATUS__BUILDER_HPP_
