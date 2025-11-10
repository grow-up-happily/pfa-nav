// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_is_hp_deduced
{
public:
  explicit Init_RobotStatus_is_hp_deduced(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::RobotStatus is_hp_deduced(::pb_rm_interfaces::msg::RobotStatus::_is_hp_deduced_type arg)
  {
    msg_.is_hp_deduced = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_remaining_gold_coin
{
public:
  explicit Init_RobotStatus_remaining_gold_coin(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_is_hp_deduced remaining_gold_coin(::pb_rm_interfaces::msg::RobotStatus::_remaining_gold_coin_type arg)
  {
    msg_.remaining_gold_coin = std::move(arg);
    return Init_RobotStatus_is_hp_deduced(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_projectile_allowance_17mm
{
public:
  explicit Init_RobotStatus_projectile_allowance_17mm(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_remaining_gold_coin projectile_allowance_17mm(::pb_rm_interfaces::msg::RobotStatus::_projectile_allowance_17mm_type arg)
  {
    msg_.projectile_allowance_17mm = std::move(arg);
    return Init_RobotStatus_remaining_gold_coin(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_hp_deduction_reason
{
public:
  explicit Init_RobotStatus_hp_deduction_reason(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_projectile_allowance_17mm hp_deduction_reason(::pb_rm_interfaces::msg::RobotStatus::_hp_deduction_reason_type arg)
  {
    msg_.hp_deduction_reason = std::move(arg);
    return Init_RobotStatus_projectile_allowance_17mm(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_armor_id
{
public:
  explicit Init_RobotStatus_armor_id(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_hp_deduction_reason armor_id(::pb_rm_interfaces::msg::RobotStatus::_armor_id_type arg)
  {
    msg_.armor_id = std::move(arg);
    return Init_RobotStatus_hp_deduction_reason(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_robot_pos
{
public:
  explicit Init_RobotStatus_robot_pos(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_armor_id robot_pos(::pb_rm_interfaces::msg::RobotStatus::_robot_pos_type arg)
  {
    msg_.robot_pos = std::move(arg);
    return Init_RobotStatus_armor_id(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_shooter_17mm_1_barrel_heat
{
public:
  explicit Init_RobotStatus_shooter_17mm_1_barrel_heat(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_robot_pos shooter_17mm_1_barrel_heat(::pb_rm_interfaces::msg::RobotStatus::_shooter_17mm_1_barrel_heat_type arg)
  {
    msg_.shooter_17mm_1_barrel_heat = std::move(arg);
    return Init_RobotStatus_robot_pos(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_shooter_barrel_heat_limit
{
public:
  explicit Init_RobotStatus_shooter_barrel_heat_limit(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_shooter_17mm_1_barrel_heat shooter_barrel_heat_limit(::pb_rm_interfaces::msg::RobotStatus::_shooter_barrel_heat_limit_type arg)
  {
    msg_.shooter_barrel_heat_limit = std::move(arg);
    return Init_RobotStatus_shooter_17mm_1_barrel_heat(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_shooter_barrel_cooling_value
{
public:
  explicit Init_RobotStatus_shooter_barrel_cooling_value(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_shooter_barrel_heat_limit shooter_barrel_cooling_value(::pb_rm_interfaces::msg::RobotStatus::_shooter_barrel_cooling_value_type arg)
  {
    msg_.shooter_barrel_cooling_value = std::move(arg);
    return Init_RobotStatus_shooter_barrel_heat_limit(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_maximum_hp
{
public:
  explicit Init_RobotStatus_maximum_hp(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_shooter_barrel_cooling_value maximum_hp(::pb_rm_interfaces::msg::RobotStatus::_maximum_hp_type arg)
  {
    msg_.maximum_hp = std::move(arg);
    return Init_RobotStatus_shooter_barrel_cooling_value(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_current_hp
{
public:
  explicit Init_RobotStatus_current_hp(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_maximum_hp current_hp(::pb_rm_interfaces::msg::RobotStatus::_current_hp_type arg)
  {
    msg_.current_hp = std::move(arg);
    return Init_RobotStatus_maximum_hp(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_robot_level
{
public:
  explicit Init_RobotStatus_robot_level(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_current_hp robot_level(::pb_rm_interfaces::msg::RobotStatus::_robot_level_type arg)
  {
    msg_.robot_level = std::move(arg);
    return Init_RobotStatus_current_hp(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_robot_id
{
public:
  Init_RobotStatus_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_robot_level robot_id(::pb_rm_interfaces::msg::RobotStatus::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotStatus_robot_level(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::RobotStatus>()
{
  return pb_rm_interfaces::msg::builder::Init_RobotStatus_robot_id();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
