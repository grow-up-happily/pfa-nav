// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:srv/GetMode.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__GET_MODE__BUILDER_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__GET_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/srv/detail/get_mode__struct.hpp"
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
auto build<::rmoss_interfaces::srv::GetMode_Request>()
{
  return ::rmoss_interfaces::srv::GetMode_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace rmoss_interfaces


namespace rmoss_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetMode_Response_mode
{
public:
  Init_GetMode_Response_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rmoss_interfaces::srv::GetMode_Response mode(::rmoss_interfaces::srv::GetMode_Response::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::srv::GetMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::GetMode_Response>()
{
  return rmoss_interfaces::srv::builder::Init_GetMode_Response_mode();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__GET_MODE__BUILDER_HPP_
