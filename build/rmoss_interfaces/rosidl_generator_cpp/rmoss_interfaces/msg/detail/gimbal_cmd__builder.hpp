// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:msg/GimbalCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GIMBAL_CMD__BUILDER_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__GIMBAL_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/msg/detail/gimbal_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace msg
{

namespace builder
{

class Init_GimbalCmd_velocity
{
public:
  explicit Init_GimbalCmd_velocity(::rmoss_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::msg::GimbalCmd velocity(::rmoss_interfaces::msg::GimbalCmd::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_position
{
public:
  explicit Init_GimbalCmd_position(::rmoss_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_velocity position(::rmoss_interfaces::msg::GimbalCmd::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_GimbalCmd_velocity(msg_);
  }

private:
  ::rmoss_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_pitch_type
{
public:
  explicit Init_GimbalCmd_pitch_type(::rmoss_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_position pitch_type(::rmoss_interfaces::msg::GimbalCmd::_pitch_type_type arg)
  {
    msg_.pitch_type = std::move(arg);
    return Init_GimbalCmd_position(msg_);
  }

private:
  ::rmoss_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_yaw_type
{
public:
  explicit Init_GimbalCmd_yaw_type(::rmoss_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_pitch_type yaw_type(::rmoss_interfaces::msg::GimbalCmd::_yaw_type_type arg)
  {
    msg_.yaw_type = std::move(arg);
    return Init_GimbalCmd_pitch_type(msg_);
  }

private:
  ::rmoss_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_tid
{
public:
  Init_GimbalCmd_tid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GimbalCmd_yaw_type tid(::rmoss_interfaces::msg::GimbalCmd::_tid_type arg)
  {
    msg_.tid = std::move(arg);
    return Init_GimbalCmd_yaw_type(msg_);
  }

private:
  ::rmoss_interfaces::msg::GimbalCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::msg::GimbalCmd>()
{
  return rmoss_interfaces::msg::builder::Init_GimbalCmd_tid();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GIMBAL_CMD__BUILDER_HPP_
