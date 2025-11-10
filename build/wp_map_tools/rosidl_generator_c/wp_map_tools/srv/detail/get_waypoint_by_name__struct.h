// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wp_map_tools:srv/GetWaypointByName.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__STRUCT_H_
#define WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetWaypointByName in the package wp_map_tools.
typedef struct wp_map_tools__srv__GetWaypointByName_Request
{
  rosidl_runtime_c__String name;
} wp_map_tools__srv__GetWaypointByName_Request;

// Struct for a sequence of wp_map_tools__srv__GetWaypointByName_Request.
typedef struct wp_map_tools__srv__GetWaypointByName_Request__Sequence
{
  wp_map_tools__srv__GetWaypointByName_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wp_map_tools__srv__GetWaypointByName_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'name'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/GetWaypointByName in the package wp_map_tools.
typedef struct wp_map_tools__srv__GetWaypointByName_Response
{
  rosidl_runtime_c__String name;
  geometry_msgs__msg__Pose pose;
} wp_map_tools__srv__GetWaypointByName_Response;

// Struct for a sequence of wp_map_tools__srv__GetWaypointByName_Response.
typedef struct wp_map_tools__srv__GetWaypointByName_Response__Sequence
{
  wp_map_tools__srv__GetWaypointByName_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wp_map_tools__srv__GetWaypointByName_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__STRUCT_H_
