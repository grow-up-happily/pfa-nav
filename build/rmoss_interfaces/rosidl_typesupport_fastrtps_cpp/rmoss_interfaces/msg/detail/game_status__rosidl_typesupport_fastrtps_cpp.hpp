// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from rmoss_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rmoss_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "rmoss_interfaces/msg/detail/game_status__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace rmoss_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmoss_interfaces
cdr_serialize(
  const rmoss_interfaces::msg::GameStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmoss_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rmoss_interfaces::msg::GameStatus & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmoss_interfaces
get_serialized_size(
  const rmoss_interfaces::msg::GameStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmoss_interfaces
max_serialized_size_GameStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rmoss_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmoss_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rmoss_interfaces, msg, GameStatus)();

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
