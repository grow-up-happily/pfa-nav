// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rmoss_interfaces:msg/RfidStatusArray.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__BUILDER_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rmoss_interfaces/msg/detail/rfid_status_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rmoss_interfaces
{

namespace msg
{

namespace builder
{

class Init_RfidStatusArray_robot_rfid_status
{
public:
  Init_RfidStatusArray_robot_rfid_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rmoss_interfaces::msg::RfidStatusArray robot_rfid_status(::rmoss_interfaces::msg::RfidStatusArray::_robot_rfid_status_type arg)
  {
    msg_.robot_rfid_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rmoss_interfaces::msg::RfidStatusArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rmoss_interfaces::msg::RfidStatusArray>()
{
  return rmoss_interfaces::msg::builder::Init_RfidStatusArray_robot_rfid_status();
}

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__BUILDER_HPP_
