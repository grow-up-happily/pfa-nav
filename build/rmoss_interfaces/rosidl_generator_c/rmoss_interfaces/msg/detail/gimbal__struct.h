// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:msg/Gimbal.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GIMBAL__STRUCT_H_
#define RMOSS_INTERFACES__MSG__DETAIL__GIMBAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Gimbal in the package rmoss_interfaces.
/**
  * msg for Gimbal, pitch and yaw.
 */
typedef struct rmoss_interfaces__msg__Gimbal
{
  float yaw;
  float pitch;
} rmoss_interfaces__msg__Gimbal;

// Struct for a sequence of rmoss_interfaces__msg__Gimbal.
typedef struct rmoss_interfaces__msg__Gimbal__Sequence
{
  rmoss_interfaces__msg__Gimbal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__msg__Gimbal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GIMBAL__STRUCT_H_
