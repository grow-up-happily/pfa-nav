// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/Models.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__MODELS__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__MODELS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'chassis'
// Member 'gimbal'
// Member 'shoot'
// Member 'arm'
// Member 'custom_controller'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Models in the package pb_rm_interfaces.
typedef struct pb_rm_interfaces__msg__Models
{
  rosidl_runtime_c__String chassis;
  rosidl_runtime_c__String gimbal;
  rosidl_runtime_c__String shoot;
  rosidl_runtime_c__String arm;
  rosidl_runtime_c__String custom_controller;
} pb_rm_interfaces__msg__Models;

// Struct for a sequence of pb_rm_interfaces__msg__Models.
typedef struct pb_rm_interfaces__msg__Models__Sequence
{
  pb_rm_interfaces__msg__Models * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__Models__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__MODELS__STRUCT_H_
