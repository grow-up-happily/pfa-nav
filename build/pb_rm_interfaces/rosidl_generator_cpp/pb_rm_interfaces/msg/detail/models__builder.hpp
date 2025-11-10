// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/Models.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__MODELS__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__MODELS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/models__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_Models_custom_controller
{
public:
  explicit Init_Models_custom_controller(::pb_rm_interfaces::msg::Models & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::Models custom_controller(::pb_rm_interfaces::msg::Models::_custom_controller_type arg)
  {
    msg_.custom_controller = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Models msg_;
};

class Init_Models_arm
{
public:
  explicit Init_Models_arm(::pb_rm_interfaces::msg::Models & msg)
  : msg_(msg)
  {}
  Init_Models_custom_controller arm(::pb_rm_interfaces::msg::Models::_arm_type arg)
  {
    msg_.arm = std::move(arg);
    return Init_Models_custom_controller(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Models msg_;
};

class Init_Models_shoot
{
public:
  explicit Init_Models_shoot(::pb_rm_interfaces::msg::Models & msg)
  : msg_(msg)
  {}
  Init_Models_arm shoot(::pb_rm_interfaces::msg::Models::_shoot_type arg)
  {
    msg_.shoot = std::move(arg);
    return Init_Models_arm(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Models msg_;
};

class Init_Models_gimbal
{
public:
  explicit Init_Models_gimbal(::pb_rm_interfaces::msg::Models & msg)
  : msg_(msg)
  {}
  Init_Models_shoot gimbal(::pb_rm_interfaces::msg::Models::_gimbal_type arg)
  {
    msg_.gimbal = std::move(arg);
    return Init_Models_shoot(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Models msg_;
};

class Init_Models_chassis
{
public:
  Init_Models_chassis()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Models_gimbal chassis(::pb_rm_interfaces::msg::Models::_chassis_type arg)
  {
    msg_.chassis = std::move(arg);
    return Init_Models_gimbal(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Models msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::Models>()
{
  return pb_rm_interfaces::msg::builder::Init_Models_chassis();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__MODELS__BUILDER_HPP_
