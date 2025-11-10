// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:srv/ControlTask.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__CONTROL_TASK__STRUCT_H_
#define RMOSS_INTERFACES__SRV__DETAIL__CONTROL_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'START'.
enum
{
  rmoss_interfaces__srv__ControlTask_Request__START = 1
};

/// Constant 'STOP'.
enum
{
  rmoss_interfaces__srv__ControlTask_Request__STOP = 2
};

/// Struct defined in srv/ControlTask in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__ControlTask_Request
{
  /// request fields
  uint8_t cmd;
} rmoss_interfaces__srv__ControlTask_Request;

// Struct for a sequence of rmoss_interfaces__srv__ControlTask_Request.
typedef struct rmoss_interfaces__srv__ControlTask_Request__Sequence
{
  rmoss_interfaces__srv__ControlTask_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__ControlTask_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ControlTask in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__ControlTask_Response
{
  bool success;
} rmoss_interfaces__srv__ControlTask_Response;

// Struct for a sequence of rmoss_interfaces__srv__ControlTask_Response.
typedef struct rmoss_interfaces__srv__ControlTask_Response__Sequence
{
  rmoss_interfaces__srv__ControlTask_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__ControlTask_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__SRV__DETAIL__CONTROL_TASK__STRUCT_H_
