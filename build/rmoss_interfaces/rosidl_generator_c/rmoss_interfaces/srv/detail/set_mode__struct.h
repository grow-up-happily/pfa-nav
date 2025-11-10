// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:srv/SetMode.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__SET_MODE__STRUCT_H_
#define RMOSS_INTERFACES__SRV__DETAIL__SET_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetMode in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__SetMode_Request
{
  int32_t mode;
} rmoss_interfaces__srv__SetMode_Request;

// Struct for a sequence of rmoss_interfaces__srv__SetMode_Request.
typedef struct rmoss_interfaces__srv__SetMode_Request__Sequence
{
  rmoss_interfaces__srv__SetMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__SetMode_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetMode in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__SetMode_Response
{
  bool success;
} rmoss_interfaces__srv__SetMode_Response;

// Struct for a sequence of rmoss_interfaces__srv__SetMode_Response.
typedef struct rmoss_interfaces__srv__SetMode_Response__Sequence
{
  rmoss_interfaces__srv__SetMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__SetMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__SRV__DETAIL__SET_MODE__STRUCT_H_
