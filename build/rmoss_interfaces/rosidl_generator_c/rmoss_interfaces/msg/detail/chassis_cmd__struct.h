// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:msg/ChassisCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__STRUCT_H_
#define RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'VELOCITY'.
/**
  * constants for control type
  * velocity control, (vx,vy,w) in chassis frame.
 */
enum
{
  rmoss_interfaces__msg__ChassisCmd__VELOCITY = 1
};

/// Constant 'FOLLOW_GIMBAL'.
/**
  * velocity control, follow gimbal's yaw stick automatically,
  * (vx,vy) in gimbal's yaw frame.
 */
enum
{
  rmoss_interfaces__msg__ChassisCmd__FOLLOW_GIMBAL = 2
};

/// Constant 'SWING'.
/**
  * velocity control, swing around gimbal's yaw automatically,
  * (vx,vy) in gimbal's yaw frame.
 */
enum
{
  rmoss_interfaces__msg__ChassisCmd__SWING = 3
};

/// Constant 'SPIN'.
/**
  * velocity control, spin at an angular velocity automatically,
  * (vx,vy) in gimbal's yaw frame.
 */
enum
{
  rmoss_interfaces__msg__ChassisCmd__SPIN = 4
};

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.h"
// Member 'accel'
#include "geometry_msgs/msg/detail/accel__struct.h"

/// Struct defined in msg/ChassisCmd in the package rmoss_interfaces.
/**
  * cmd msg for controlling chassis
  * id of task
 */
typedef struct rmoss_interfaces__msg__ChassisCmd
{
  uint8_t tid;
  /// control type
  uint8_t type;
  /// control data
  geometry_msgs__msg__Pose pose;
  geometry_msgs__msg__Twist twist;
  geometry_msgs__msg__Accel accel;
} rmoss_interfaces__msg__ChassisCmd;

// Struct for a sequence of rmoss_interfaces__msg__ChassisCmd.
typedef struct rmoss_interfaces__msg__ChassisCmd__Sequence
{
  rmoss_interfaces__msg__ChassisCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__msg__ChassisCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__STRUCT_H_
