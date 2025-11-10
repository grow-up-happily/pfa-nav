// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/Gimbal.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Gimbal in the package pb_rm_interfaces.
/**
  * msg for Gimbal, pitch and yaw.
 */
typedef struct pb_rm_interfaces__msg__Gimbal
{
  float pitch;
  float yaw;
  /// Only used in velocity control type
  float pitch_min_range;
  float pitch_max_range;
  float yaw_min_range;
  float yaw_max_range;
} pb_rm_interfaces__msg__Gimbal;

// Struct for a sequence of pb_rm_interfaces__msg__Gimbal.
typedef struct pb_rm_interfaces__msg__Gimbal__Sequence
{
  pb_rm_interfaces__msg__Gimbal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__Gimbal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__STRUCT_H_
