// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:srv/GetTaskStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__GET_TASK_STATUS__STRUCT_H_
#define RMOSS_INTERFACES__SRV__DETAIL__GET_TASK_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetTaskStatus in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__GetTaskStatus_Request
{
  uint8_t structure_needs_at_least_one_member;
} rmoss_interfaces__srv__GetTaskStatus_Request;

// Struct for a sequence of rmoss_interfaces__srv__GetTaskStatus_Request.
typedef struct rmoss_interfaces__srv__GetTaskStatus_Request__Sequence
{
  rmoss_interfaces__srv__GetTaskStatus_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__GetTaskStatus_Request__Sequence;


// Constants defined in the message

/// Constant 'RUNNING'.
enum
{
  rmoss_interfaces__srv__GetTaskStatus_Response__RUNNING = 1
};

/// Constant 'IDLE'.
enum
{
  rmoss_interfaces__srv__GetTaskStatus_Response__IDLE = 2
};

/// Constant 'ERROR'.
enum
{
  rmoss_interfaces__srv__GetTaskStatus_Response__ERROR = 3
};

/// Struct defined in srv/GetTaskStatus in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__GetTaskStatus_Response
{
  /// response data
  uint8_t status;
} rmoss_interfaces__srv__GetTaskStatus_Response;

// Struct for a sequence of rmoss_interfaces__srv__GetTaskStatus_Response.
typedef struct rmoss_interfaces__srv__GetTaskStatus_Response__Sequence
{
  rmoss_interfaces__srv__GetTaskStatus_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__GetTaskStatus_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__SRV__DETAIL__GET_TASK_STATUS__STRUCT_H_
