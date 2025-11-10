// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:msg/ChassisCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__BUILDER_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/msg/detail/chassis_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace msg
{

namespace builder
{

class Init_ChassisCmd_accel
{
public:
  explicit Init_ChassisCmd_accel(::rmoss_interfaces::msg::ChassisCmd & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::msg::ChassisCmd accel(::rmoss_interfaces::msg::ChassisCmd::_accel_type arg)
  {
    msg_.accel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::msg::ChassisCmd msg_;
};

class Init_ChassisCmd_twist
{
public:
  explicit Init_ChassisCmd_twist(::rmoss_interfaces::msg::ChassisCmd & msg)
  : msg_(msg)
  {}
  Init_ChassisCmd_accel twist(::rmoss_interfaces::msg::ChassisCmd::_twist_type arg)
  {
    msg_.twist = std::move(arg);
    return Init_ChassisCmd_accel(msg_);
  }

private:
  ::rmoss_interfaces::msg::ChassisCmd msg_;
};

class Init_ChassisCmd_pose
{
public:
  explicit Init_ChassisCmd_pose(::rmoss_interfaces::msg::ChassisCmd & msg)
  : msg_(msg)
  {}
  Init_ChassisCmd_twist pose(::rmoss_interfaces::msg::ChassisCmd::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_ChassisCmd_twist(msg_);
  }

private:
  ::rmoss_interfaces::msg::ChassisCmd msg_;
};

class Init_ChassisCmd_type
{
public:
  explicit Init_ChassisCmd_type(::rmoss_interfaces::msg::ChassisCmd & msg)
  : msg_(msg)
  {}
  Init_ChassisCmd_pose type(::rmoss_interfaces::msg::ChassisCmd::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_ChassisCmd_pose(msg_);
  }

private:
  ::rmoss_interfaces::msg::ChassisCmd msg_;
};

class Init_ChassisCmd_tid
{
public:
  Init_ChassisCmd_tid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChassisCmd_type tid(::rmoss_interfaces::msg::ChassisCmd::_tid_type arg)
  {
    msg_.tid = std::move(arg);
    return Init_ChassisCmd_type(msg_);
  }

private:
  ::rmoss_interfaces::msg::ChassisCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::msg::ChassisCmd>()
{
  return rmoss_interfaces::msg::builder::Init_ChassisCmd_tid();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__BUILDER_HPP_
