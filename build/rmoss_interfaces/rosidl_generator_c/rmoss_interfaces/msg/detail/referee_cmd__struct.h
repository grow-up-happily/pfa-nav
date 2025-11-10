// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:msg/RefereeCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__STRUCT_H_
#define RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'START_PREPARATION'.
/**
  * system cmd: transit to PREPARATION stage
 */
enum
{
  rmoss_interfaces__msg__RefereeCmd__START_PREPARATION = 0
};

/// Constant 'START_SELF_CHECKING'.
/**
  * system cmd: transit to SELF_CHECKING stage
 */
enum
{
  rmoss_interfaces__msg__RefereeCmd__START_SELF_CHECKING = 1
};

/// Constant 'START_GAME'.
/**
  * system cmd: transit to RUNNING stage
 */
enum
{
  rmoss_interfaces__msg__RefereeCmd__START_GAME = 2
};

/// Constant 'STOP_GAME'.
/**
  * system cmd: transit to GAME_OVER stage
 */
enum
{
  rmoss_interfaces__msg__RefereeCmd__STOP_GAME = 3
};

/// Constant 'KILL_ROBOT'.
/**
  * control robot cmd: kill robot with robot_name
 */
enum
{
  rmoss_interfaces__msg__RefereeCmd__KILL_ROBOT = 4
};

/// Constant 'REVIVE_ROBOT'.
/**
  * control robot cmd: revive robot with robot_name
 */
enum
{
  rmoss_interfaces__msg__RefereeCmd__REVIVE_ROBOT = 5
};

/// Constant 'PREPARATION'.
/**
  * deprecate constant definition (don't use them)
 */
enum
{
  rmoss_interfaces__msg__RefereeCmd__PREPARATION = 0
};

/// Constant 'SELF_CHECKING'.
enum
{
  rmoss_interfaces__msg__RefereeCmd__SELF_CHECKING = 1
};

// Include directives for member types
// Member 'robot_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RefereeCmd in the package rmoss_interfaces.
/**
  * msg for cmd in referee system
 */
typedef struct rmoss_interfaces__msg__RefereeCmd
{
  uint8_t cmd;
  rosidl_runtime_c__String robot_name;
} rmoss_interfaces__msg__RefereeCmd;

// Struct for a sequence of rmoss_interfaces__msg__RefereeCmd.
typedef struct rmoss_interfaces__msg__RefereeCmd__Sequence
{
  rmoss_interfaces__msg__RefereeCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__msg__RefereeCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__STRUCT_H_
