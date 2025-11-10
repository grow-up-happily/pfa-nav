// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/Gimbal.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/gimbal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_Gimbal_yaw_max_range
{
public:
  explicit Init_Gimbal_yaw_max_range(::pb_rm_interfaces::msg::Gimbal & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::Gimbal yaw_max_range(::pb_rm_interfaces::msg::Gimbal::_yaw_max_range_type arg)
  {
    msg_.yaw_max_range = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Gimbal msg_;
};

class Init_Gimbal_yaw_min_range
{
public:
  explicit Init_Gimbal_yaw_min_range(::pb_rm_interfaces::msg::Gimbal & msg)
  : msg_(msg)
  {}
  Init_Gimbal_yaw_max_range yaw_min_range(::pb_rm_interfaces::msg::Gimbal::_yaw_min_range_type arg)
  {
    msg_.yaw_min_range = std::move(arg);
    return Init_Gimbal_yaw_max_range(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Gimbal msg_;
};

class Init_Gimbal_pitch_max_range
{
public:
  explicit Init_Gimbal_pitch_max_range(::pb_rm_interfaces::msg::Gimbal & msg)
  : msg_(msg)
  {}
  Init_Gimbal_yaw_min_range pitch_max_range(::pb_rm_interfaces::msg::Gimbal::_pitch_max_range_type arg)
  {
    msg_.pitch_max_range = std::move(arg);
    return Init_Gimbal_yaw_min_range(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Gimbal msg_;
};

class Init_Gimbal_pitch_min_range
{
public:
  explicit Init_Gimbal_pitch_min_range(::pb_rm_interfaces::msg::Gimbal & msg)
  : msg_(msg)
  {}
  Init_Gimbal_pitch_max_range pitch_min_range(::pb_rm_interfaces::msg::Gimbal::_pitch_min_range_type arg)
  {
    msg_.pitch_min_range = std::move(arg);
    return Init_Gimbal_pitch_max_range(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Gimbal msg_;
};

class Init_Gimbal_yaw
{
public:
  explicit Init_Gimbal_yaw(::pb_rm_interfaces::msg::Gimbal & msg)
  : msg_(msg)
  {}
  Init_Gimbal_pitch_min_range yaw(::pb_rm_interfaces::msg::Gimbal::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Gimbal_pitch_min_range(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Gimbal msg_;
};

class Init_Gimbal_pitch
{
public:
  Init_Gimbal_pitch()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gimbal_yaw pitch(::pb_rm_interfaces::msg::Gimbal::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Gimbal_yaw(msg_);
  }

private:
  ::pb_rm_interfaces::msg::Gimbal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::Gimbal>()
{
  return pb_rm_interfaces::msg::builder::Init_Gimbal_pitch();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__BUILDER_HPP_
