// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:msg/ShootCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__BUILDER_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/msg/detail/shoot_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace msg
{

namespace builder
{

class Init_ShootCmd_projectile_velocity
{
public:
  explicit Init_ShootCmd_projectile_velocity(::rmoss_interfaces::msg::ShootCmd & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::msg::ShootCmd projectile_velocity(::rmoss_interfaces::msg::ShootCmd::_projectile_velocity_type arg)
  {
    msg_.projectile_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::msg::ShootCmd msg_;
};

class Init_ShootCmd_projectile_num
{
public:
  explicit Init_ShootCmd_projectile_num(::rmoss_interfaces::msg::ShootCmd & msg)
  : msg_(msg)
  {}
  Init_ShootCmd_projectile_velocity projectile_num(::rmoss_interfaces::msg::ShootCmd::_projectile_num_type arg)
  {
    msg_.projectile_num = std::move(arg);
    return Init_ShootCmd_projectile_velocity(msg_);
  }

private:
  ::rmoss_interfaces::msg::ShootCmd msg_;
};

class Init_ShootCmd_type
{
public:
  explicit Init_ShootCmd_type(::rmoss_interfaces::msg::ShootCmd & msg)
  : msg_(msg)
  {}
  Init_ShootCmd_projectile_num type(::rmoss_interfaces::msg::ShootCmd::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_ShootCmd_projectile_num(msg_);
  }

private:
  ::rmoss_interfaces::msg::ShootCmd msg_;
};

class Init_ShootCmd_tid
{
public:
  Init_ShootCmd_tid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ShootCmd_type tid(::rmoss_interfaces::msg::ShootCmd::_tid_type arg)
  {
    msg_.tid = std::move(arg);
    return Init_ShootCmd_type(msg_);
  }

private:
  ::rmoss_interfaces::msg::ShootCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::msg::ShootCmd>()
{
  return rmoss_interfaces::msg::builder::Init_ShootCmd_tid();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__BUILDER_HPP_
