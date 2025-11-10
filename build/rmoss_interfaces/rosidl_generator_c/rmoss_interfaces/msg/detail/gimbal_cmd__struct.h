// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:msg/GimbalCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_H_
#define RMOSS_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_H_

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
  rmoss_interfaces__msg__GimbalCmd__ABSOLUTE_ANGLE = 1
};

/// Constant 'RELATIVE_ANGLE'.
/**
  * position control, set position by relative angle
 */
enum
{
  rmoss_interfaces__msg__GimbalCmd__RELATIVE_ANGLE = 2
};

/// Constant 'VELOCITY'.
/**
  * velocity control, set velocity
 */
enum
{
  rmoss_interfaces__msg__GimbalCmd__VELOCITY = 3
};

/// Constant 'FOLLOW_CHASSIS'.
/**
  * follow chassis, only used by yaw_type.
 */
enum
{
  rmoss_interfaces__msg__GimbalCmd__FOLLOW_CHASSIS = 4
};

// Include directives for member types
// Member 'position'
// Member 'velocity'
#include "rmoss_interfaces/msg/detail/gimbal__struct.h"

/// Struct defined in msg/GimbalCmd in the package rmoss_interfaces.
/**
  * cmd msg for controlling gimbal
  * id of task
 */
typedef struct rmoss_interfaces__msg__GimbalCmd
{
  uint8_t tid;
  /// control type
  uint8_t yaw_type;
  uint8_t pitch_type;
  /// control dada
  rmoss_interfaces__msg__Gimbal position;
  rmoss_interfaces__msg__Gimbal velocity;
} rmoss_interfaces__msg__GimbalCmd;

// Struct for a sequence of rmoss_interfaces__msg__GimbalCmd.
typedef struct rmoss_interfaces__msg__GimbalCmd__Sequence
{
  rmoss_interfaces__msg__GimbalCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__msg__GimbalCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_H_
