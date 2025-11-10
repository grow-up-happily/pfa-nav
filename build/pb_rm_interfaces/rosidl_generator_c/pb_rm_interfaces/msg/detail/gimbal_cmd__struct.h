// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/GimbalCmd.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ABSOLUTE_ANGLE'.
/**
  * constants for control type
  * position control, set position by absolute angle
 */
enum
{
  pb_rm_interfaces__msg__GimbalCmd__ABSOLUTE_ANGLE = 1
};

/// Constant 'VELOCITY'.
/**
  * velocity control, set velocity
 */
enum
{
  pb_rm_interfaces__msg__GimbalCmd__VELOCITY = 2
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'position'
// Member 'velocity'
#include "pb_rm_interfaces/msg/detail/gimbal__struct.h"

/// Struct defined in msg/GimbalCmd in the package pb_rm_interfaces.
typedef struct pb_rm_interfaces__msg__GimbalCmd
{
  std_msgs__msg__Header header;
  /// control type
  uint8_t yaw_type;
  uint8_t pitch_type;
  /// control dada
  pb_rm_interfaces__msg__Gimbal position;
  pb_rm_interfaces__msg__Gimbal velocity;
} pb_rm_interfaces__msg__GimbalCmd;

// Struct for a sequence of pb_rm_interfaces__msg__GimbalCmd.
typedef struct pb_rm_interfaces__msg__GimbalCmd__Sequence
{
  pb_rm_interfaces__msg__GimbalCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__GimbalCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_H_
