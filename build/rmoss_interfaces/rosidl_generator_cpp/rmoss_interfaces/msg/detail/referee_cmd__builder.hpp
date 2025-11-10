// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:msg/RefereeCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__BUILDER_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/msg/detail/referee_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace msg
{

namespace builder
{

class Init_RefereeCmd_robot_name
{
public:
  explicit Init_RefereeCmd_robot_name(::rmoss_interfaces::msg::RefereeCmd & msg)
  : msg_(msg)
  {}
  ::rmoss_interfaces::msg::RefereeCmd robot_name(::rmoss_interfaces::msg::RefereeCmd::_robot_name_type arg)
  {
    msg_.robot_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::msg::RefereeCmd msg_;
};

class Init_RefereeCmd_cmd
{
public:
  Init_RefereeCmd_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RefereeCmd_robot_name cmd(::rmoss_interfaces::msg::RefereeCmd::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return Init_RefereeCmd_robot_name(msg_);
  }

private:
  ::rmoss_interfaces::msg::RefereeCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::msg::RefereeCmd>()
{
  return rmoss_interfaces::msg::builder::Init_RefereeCmd_cmd();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__BUILDER_HPP_
