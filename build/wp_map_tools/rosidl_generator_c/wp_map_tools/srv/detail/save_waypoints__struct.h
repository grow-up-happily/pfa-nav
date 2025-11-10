// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wp_map_tools:srv/SaveWaypoints.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__STRUCT_H_
#define WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'filename'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SaveWaypoints in the package wp_map_tools.
typedef struct wp_map_tools__srv__SaveWaypoints_Request
{
  rosidl_runtime_c__String filename;
} wp_map_tools__srv__SaveWaypoints_Request;

// Struct for a sequence of wp_map_tools__srv__SaveWaypoints_Request.
typedef struct wp_map_tools__srv__SaveWaypoints_Request__Sequence
{
  wp_map_tools__srv__SaveWaypoints_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wp_map_tools__srv__SaveWaypoints_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SaveWaypoints in the package wp_map_tools.
typedef struct wp_map_tools__srv__SaveWaypoints_Response
{
  bool result;
} wp_map_tools__srv__SaveWaypoints_Response;

// Struct for a sequence of wp_map_tools__srv__SaveWaypoints_Response.
typedef struct wp_map_tools__srv__SaveWaypoints_Response__Sequence
{
  wp_map_tools__srv__SaveWaypoints_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wp_map_tools__srv__SaveWaypoints_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__STRUCT_H_
