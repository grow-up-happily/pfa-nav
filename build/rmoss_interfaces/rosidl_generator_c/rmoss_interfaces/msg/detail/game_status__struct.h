// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_
#define RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'PREPARATION'.
/**
  * preparation stage (free control for robot, disable referee system)
 */
enum
{
  rmoss_interfaces__msg__GameStatus__PREPARATION = 0
};

/// Constant 'SELF_CHECKING'.
/**
  * referee system self-checking stage (unable to control robot, and
  * initialize all referee system data).
 */
enum
{
  rmoss_interfaces__msg__GameStatus__SELF_CHECKING = 1
};

/// Constant 'RUNNING'.
/**
  * running stage (free control for robot, enable referee system)
 */
enum
{
  rmoss_interfaces__msg__GameStatus__RUNNING = 2
};

/// Constant 'GAME_OVER'.
/**
  * game over stage (unable to control robot, disable referee system)
 */
enum
{
  rmoss_interfaces__msg__GameStatus__GAME_OVER = 3
};

/// Constant 'DRAW'.
/**
  * game result
 */
enum
{
  rmoss_interfaces__msg__GameStatus__DRAW = 0
};

/// Constant 'RED_WIN'.
enum
{
  rmoss_interfaces__msg__GameStatus__RED_WIN = 1
};

/// Constant 'BLUE_WIN'.
enum
{
  rmoss_interfaces__msg__GameStatus__BLUE_WIN = 2
};

/// Struct defined in msg/GameStatus in the package rmoss_interfaces.
/**
  * msg for referee system
  * game status
 */
typedef struct rmoss_interfaces__msg__GameStatus
{
  uint8_t status;
  /// game time
  /// seconds
  int32_t total_time;
  /// seconds
  int32_t current_time;
  uint8_t result;
} rmoss_interfaces__msg__GameStatus;

// Struct for a sequence of rmoss_interfaces__msg__GameStatus.
typedef struct rmoss_interfaces__msg__GameStatus__Sequence
{
  rmoss_interfaces__msg__GameStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__msg__GameStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_
