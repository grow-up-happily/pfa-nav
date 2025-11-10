// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:srv/GetCameraInfo.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__GET_CAMERA_INFO__STRUCT_H_
#define RMOSS_INTERFACES__SRV__DETAIL__GET_CAMERA_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetCameraInfo in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__GetCameraInfo_Request
{
  uint8_t structure_needs_at_least_one_member;
} rmoss_interfaces__srv__GetCameraInfo_Request;

// Struct for a sequence of rmoss_interfaces__srv__GetCameraInfo_Request.
typedef struct rmoss_interfaces__srv__GetCameraInfo_Request__Sequence
{
  rmoss_interfaces__srv__GetCameraInfo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__GetCameraInfo_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__struct.h"

/// Struct defined in srv/GetCameraInfo in the package rmoss_interfaces.
typedef struct rmoss_interfaces__srv__GetCameraInfo_Response
{
  /// The camera_info to store
  sensor_msgs__msg__CameraInfo camera_info;
  bool success;
} rmoss_interfaces__srv__GetCameraInfo_Response;

// Struct for a sequence of rmoss_interfaces__srv__GetCameraInfo_Response.
typedef struct rmoss_interfaces__srv__GetCameraInfo_Response__Sequence
{
  rmoss_interfaces__srv__GetCameraInfo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__srv__GetCameraInfo_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__SRV__DETAIL__GET_CAMERA_INFO__STRUCT_H_
