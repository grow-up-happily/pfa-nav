// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:msg/RfidStatusArray.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__STRUCT_H_
#define RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_rfid_status'
#include "rmoss_interfaces/msg/detail/rfid_status__struct.h"

/// Struct defined in msg/RfidStatusArray in the package rmoss_interfaces.
typedef struct rmoss_interfaces__msg__RfidStatusArray
{
  rmoss_interfaces__msg__RfidStatus__Sequence robot_rfid_status;
} rmoss_interfaces__msg__RfidStatusArray;

// Struct for a sequence of rmoss_interfaces__msg__RfidStatusArray.
typedef struct rmoss_interfaces__msg__RfidStatusArray__Sequence
{
  rmoss_interfaces__msg__RfidStatusArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__msg__RfidStatusArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__STRUCT_H_
