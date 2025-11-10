// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

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
// Member 'gt_tf'
#include "geometry_msgs/msg/detail/transform__struct.h"

/// Struct defined in msg/RobotStatus in the package rmoss_interfaces.
/**
  * msg for robot status in referee system
 */
typedef struct rmoss_interfaces__msg__RobotStatus
{
  uint8_t id;
  uint8_t level;
  rosidl_runtime_c__String name;
  int32_t remain_hp;
  int32_t max_hp;
  int32_t total_projectiles;
  int32_t used_projectiles;
  /// only for referee system
  int32_t hit_projectiles;
  geometry_msgs__msg__Transform gt_tf;
} rmoss_interfaces__msg__RobotStatus;

// Struct for a sequence of rmoss_interfaces__msg__RobotStatus.
typedef struct rmoss_interfaces__msg__RobotStatus__Sequence
{
  rmoss_interfaces__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
