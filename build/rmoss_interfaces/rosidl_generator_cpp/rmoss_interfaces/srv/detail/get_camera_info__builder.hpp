// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:srv/GetCameraInfo.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__GET_CAMERA_INFO__BUILDER_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__GET_CAMERA_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/srv/detail/get_camera_info__struct.hpp"
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
auto build<::rmoss_interfaces::srv::GetCameraInfo_Request>()
{
  return ::rmoss_interfaces::srv::GetCameraInfo_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace rmoss_interfaces


namespace rmoss_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetCameraInfo_Response_success
{
public:
  explicit Init_GetCameraInfo_Response_success(::rmoss_interfaces::srv::GetCameraInfo_Response & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::srv::GetCameraInfo_Response success(::rmoss_interfaces::srv::GetCameraInfo_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::srv::GetCameraInfo_Response msg_;
};

class Init_GetCameraInfo_Response_camera_info
{
public:
  Init_GetCameraInfo_Response_camera_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCameraInfo_Response_success camera_info(::rmoss_interfaces::srv::GetCameraInfo_Response::_camera_info_type arg)
  {
    msg_.camera_info = std::move(arg);
    return Init_GetCameraInfo_Response_success(msg_);
  }

private:
  ::rmoss_interfaces::srv::GetCameraInfo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::srv::GetCameraInfo_Response>()
{
  return rmoss_interfaces::srv::builder::Init_GetCameraInfo_Response_camera_info();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__GET_CAMERA_INFO__BUILDER_HPP_
