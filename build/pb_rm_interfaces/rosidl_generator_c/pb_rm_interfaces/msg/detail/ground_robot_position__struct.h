// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/GroundRobotPosition.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'hero_position'
// Member 'engineer_position'
// Member 'standard_3_position'
// Member 'standard_4_position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/GroundRobotPosition in the package pb_rm_interfaces.
/**
  * 地面机器人位置数据 (裁判系统串口协议 V1.7.0 0x020B)
 */
typedef struct pb_rm_interfaces__msg__GroundRobotPosition
{
  /// 己方英雄机器人位置
  geometry_msgs__msg__Point hero_position;
  /// 己方工程机器人位置
  geometry_msgs__msg__Point engineer_position;
  /// 己方 3 号步兵机器人位置
  geometry_msgs__msg__Point standard_3_position;
  /// 己方 4 号步兵机器人位置
  geometry_msgs__msg__Point standard_4_position;
} pb_rm_interfaces__msg__GroundRobotPosition;

// Struct for a sequence of pb_rm_interfaces__msg__GroundRobotPosition.
typedef struct pb_rm_interfaces__msg__GroundRobotPosition__Sequence
{
  pb_rm_interfaces__msg__GroundRobotPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__GroundRobotPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__STRUCT_H_
