// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:srv/SetColor.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__SET_COLOR__BUILDER_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__SET_COLOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/srv/detail/set_color__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetColor_Request_color
{
public:
  Init_SetColor_Request_color()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rmoss_interfaces::srv::SetColor_Request color(::rmoss_interfaces::srv::SetColor_Request::_color_type arg)
  {
    msg_.color = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::srv::SetColor_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::SetColor_Request>()
{
  return rmoss_interfaces::srv::builder::Init_SetColor_Request_color();
}

}  // namespace rmoss_interfaces


namespace rmoss_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetColor_Response_success
{
public:
  Init_SetColor_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rmoss_interfaces::srv::SetColor_Response success(::rmoss_interfaces::srv::SetColor_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::srv::SetColor_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::SetColor_Response>()
{
  return rmoss_interfaces::srv::builder::Init_SetColor_Response_success();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__SET_COLOR__BUILDER_HPP_
