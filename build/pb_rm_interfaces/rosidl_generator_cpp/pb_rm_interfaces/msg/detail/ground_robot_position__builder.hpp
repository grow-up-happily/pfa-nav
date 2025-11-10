// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/GroundRobotPosition.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/ground_robot_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_GroundRobotPosition_standard_4_position
{
public:
  explicit Init_GroundRobotPosition_standard_4_position(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::GroundRobotPosition standard_4_position(::pb_rm_interfaces::msg::GroundRobotPosition::_standard_4_position_type arg)
  {
    msg_.standard_4_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_standard_3_position
{
public:
  explicit Init_GroundRobotPosition_standard_3_position(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_standard_4_position standard_3_position(::pb_rm_interfaces::msg::GroundRobotPosition::_standard_3_position_type arg)
  {
    msg_.standard_3_position = std::move(arg);
    return Init_GroundRobotPosition_standard_4_position(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_engineer_position
{
public:
  explicit Init_GroundRobotPosition_engineer_position(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_standard_3_position engineer_position(::pb_rm_interfaces::msg::GroundRobotPosition::_engineer_position_type arg)
  {
    msg_.engineer_position = std::move(arg);
    return Init_GroundRobotPosition_standard_3_position(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_hero_position
{
public:
  Init_GroundRobotPosition_hero_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GroundRobotPosition_engineer_position hero_position(::pb_rm_interfaces::msg::GroundRobotPosition::_hero_position_type arg)
  {
    msg_.hero_position = std::move(arg);
    return Init_GroundRobotPosition_engineer_position(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::GroundRobotPosition>()
{
  return pb_rm_interfaces::msg::builder::Init_GroundRobotPosition_hero_position();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__BUILDER_HPP_
