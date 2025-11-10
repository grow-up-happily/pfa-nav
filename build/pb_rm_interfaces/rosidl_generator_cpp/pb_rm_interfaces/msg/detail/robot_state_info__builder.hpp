// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/RobotStateInfo.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/robot_state_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotStateInfo_models
{
public:
  explicit Init_RobotStateInfo_models(::pb_rm_interfaces::msg::RobotStateInfo & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::RobotStateInfo models(::pb_rm_interfaces::msg::RobotStateInfo::_models_type arg)
  {
    msg_.models = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStateInfo msg_;
};

class Init_RobotStateInfo_header
{
public:
  Init_RobotStateInfo_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStateInfo_models header(::pb_rm_interfaces::msg::RobotStateInfo::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotStateInfo_models(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStateInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::RobotStateInfo>()
{
  return pb_rm_interfaces::msg::builder::Init_RobotStateInfo_header();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__BUILDER_HPP_
