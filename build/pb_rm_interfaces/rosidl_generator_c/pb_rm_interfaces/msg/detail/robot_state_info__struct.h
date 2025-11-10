// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/RobotStateInfo.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'models'
#include "pb_rm_interfaces/msg/detail/models__struct.h"

/// Struct defined in msg/RobotStateInfo in the package pb_rm_interfaces.
typedef struct pb_rm_interfaces__msg__RobotStateInfo
{
  std_msgs__msg__Header header;
  pb_rm_interfaces__msg__Models models;
} pb_rm_interfaces__msg__RobotStateInfo;

// Struct for a sequence of pb_rm_interfaces__msg__RobotStateInfo.
typedef struct pb_rm_interfaces__msg__RobotStateInfo__Sequence
{
  pb_rm_interfaces__msg__RobotStateInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__RobotStateInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__STRUCT_H_
