// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/GimbalCmd.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/gimbal_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_GimbalCmd_velocity
{
public:
  explicit Init_GimbalCmd_velocity(::pb_rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::GimbalCmd velocity(::pb_rm_interfaces::msg::GimbalCmd::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_position
{
public:
  explicit Init_GimbalCmd_position(::pb_rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_velocity position(::pb_rm_interfaces::msg::GimbalCmd::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_GimbalCmd_velocity(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_pitch_type
{
public:
  explicit Init_GimbalCmd_pitch_type(::pb_rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_position pitch_type(::pb_rm_interfaces::msg::GimbalCmd::_pitch_type_type arg)
  {
    msg_.pitch_type = std::move(arg);
    return Init_GimbalCmd_position(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_yaw_type
{
public:
  explicit Init_GimbalCmd_yaw_type(::pb_rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_pitch_type yaw_type(::pb_rm_interfaces::msg::GimbalCmd::_yaw_type_type arg)
  {
    msg_.yaw_type = std::move(arg);
    return Init_GimbalCmd_pitch_type(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_header
{
public:
  Init_GimbalCmd_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GimbalCmd_yaw_type header(::pb_rm_interfaces::msg::GimbalCmd::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GimbalCmd_yaw_type(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GimbalCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::GimbalCmd>()
{
  return pb_rm_interfaces::msg::builder::Init_GimbalCmd_header();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__BUILDER_HPP_
