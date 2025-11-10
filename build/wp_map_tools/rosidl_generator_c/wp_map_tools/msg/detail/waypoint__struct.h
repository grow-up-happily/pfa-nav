// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wp_map_tools:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__STRUCT_H_
#define WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'frame_id'
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/Waypoint in the package wp_map_tools.
typedef struct wp_map_tools__msg__Waypoint
{
  rosidl_runtime_c__String frame_id;
  rosidl_runtime_c__String name;
  geometry_msgs__msg__Pose pose;
} wp_map_tools__msg__Waypoint;

// Struct for a sequence of wp_map_tools__msg__Waypoint.
typedef struct wp_map_tools__msg__Waypoint__Sequence
{
  wp_map_tools__msg__Waypoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wp_map_tools__msg__Waypoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WP_MAP_TOOLS__MSG__DETAIL__WAYPOINT__STRUCT_H_
