// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_gt_tf
{
public:
  explicit Init_RobotStatus_gt_tf(::rmoss_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::msg::RobotStatus gt_tf(::rmoss_interfaces::msg::RobotStatus::_gt_tf_type arg)
  {
    msg_.gt_tf = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_hit_projectiles
{
public:
  explicit Init_RobotStatus_hit_projectiles(::rmoss_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_gt_tf hit_projectiles(::rmoss_interfaces::msg::RobotStatus::_hit_projectiles_type arg)
  {
    msg_.hit_projectiles = std::move(arg);
    return Init_RobotStatus_gt_tf(msg_);
  }

private:
  ::rmoss_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_used_projectiles
{
public:
  explicit Init_RobotStatus_used_projectiles(::rmoss_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_hit_projectiles used_projectiles(::rmoss_interfaces::msg::RobotStatus::_used_projectiles_type arg)
  {
    msg_.used_projectiles = std::move(arg);
    return Init_RobotStatus_hit_projectiles(msg_);
  }

private:
  ::rmoss_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_total_projectiles
{
public:
  explicit Init_RobotStatus_total_projectiles(::rmoss_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_used_projectiles total_projectiles(::rmoss_interfaces::msg::RobotStatus::_total_projectiles_type arg)
  {
    msg_.total_projectiles = std::move(arg);
    return Init_RobotStatus_used_projectiles(msg_);
  }

private:
  ::rmoss_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_max_hp
{
public:
  explicit Init_RobotStatus_max_hp(::rmoss_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_total_projectiles max_hp(::rmoss_interfaces::msg::RobotStatus::_max_hp_type arg)
  {
    msg_.max_hp = std::move(arg);
    return Init_RobotStatus_total_projectiles(msg_);
  }

private:
  ::rmoss_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_remain_hp
{
public:
  explicit Init_RobotStatus_remain_hp(::rmoss_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_max_hp remain_hp(::rmoss_interfaces::msg::RobotStatus::_remain_hp_type arg)
  {
    msg_.remain_hp = std::move(arg);
    return Init_RobotStatus_max_hp(msg_);
  }

private:
  ::rmoss_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_name
{
public:
  explicit Init_RobotStatus_name(::rmoss_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_remain_hp name(::rmoss_interfaces::msg::RobotStatus::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_RobotStatus_remain_hp(msg_);
  }

private:
  ::rmoss_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_level
{
public:
  explicit Init_RobotStatus_level(::rmoss_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_name level(::rmoss_interfaces::msg::RobotStatus::_level_type arg)
  {
    msg_.level = std::move(arg);
    return Init_RobotStatus_name(msg_);
  }

private:
  ::rmoss_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_id
{
public:
  Init_RobotStatus_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_level id(::rmoss_interfaces::msg::RobotStatus::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_RobotStatus_level(msg_);
  }

private:
  ::rmoss_interfaces::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::msg::RobotStatus>()
{
  return rmoss_interfaces::msg::builder::Init_RobotStatus_id();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
