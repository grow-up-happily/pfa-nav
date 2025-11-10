// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:srv/SetColor.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__SET_COLOR__STRUCT_H_
#define RMOSS_INTERFACES__SRV__DETAIL__SET_COLOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'RED'.
enum
{
  rmoss_interfaces__srv__SetColor_Request__RED = 1
};

/// Constant 'BLUE'.
enum
{
  rmoss_interfaces__srv__SetColor_Request__BLUE = 2
};

/// Struct defined in srv/SetColor in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__SetColor_Request
{
  /// request
  uint8_t color;
} rmoss_interfaces__srv__SetColor_Request;

// Struct for a sequence of rmoss_interfaces__srv__SetColor_Request.
typedef struct rmoss_interfaces__srv__SetColor_Request__Sequence
{
  rmoss_interfaces__srv__SetColor_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__SetColor_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetColor in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__SetColor_Response
{
  bool success;
} rmoss_interfaces__srv__SetColor_Response;

// Struct for a sequence of rmoss_interfaces__srv__SetColor_Response.
typedef struct rmoss_interfaces__srv__SetColor_Response__Sequence
{
  rmoss_interfaces__srv__SetColor_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__SetColor_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__SRV__DETAIL__SET_COLOR__STRUCT_H_
