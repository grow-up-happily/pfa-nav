// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_H_
#define RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RfidStatus in the package rmoss_interfaces.
typedef struct rmoss_interfaces__msg__RfidStatus
{
  rosidl_runtime_c__String robot_name;
  bool supplier_area_is_triggered;
  bool center_area_is_triggered;
} rmoss_interfaces__msg__RfidStatus;

// Struct for a sequence of rmoss_interfaces__msg__RfidStatus.
typedef struct rmoss_interfaces__msg__RfidStatus__Sequence
{
  rmoss_interfaces__msg__RfidStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__msg__RfidStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_H_
