// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'NOT_START'.
/**
  * constants for game progress
  * 未开始比赛
 */
enum
{
  pb_rm_interfaces__msg__GameStatus__NOT_START = 0
};

/// Constant 'PREPARATION'.
/**
  * 准备阶段
 */
enum
{
  pb_rm_interfaces__msg__GameStatus__PREPARATION = 1
};

/// Constant 'SELF_CHECKING'.
/**
  * 十五秒裁判系统自检阶段
 */
enum
{
  pb_rm_interfaces__msg__GameStatus__SELF_CHECKING = 2
};

/// Constant 'COUNT_DOWN'.
/**
  * 五秒倒计时
 */
enum
{
  pb_rm_interfaces__msg__GameStatus__COUNT_DOWN = 3
};

/// Constant 'RUNNING'.
/**
  * 比赛中
 */
enum
{
  pb_rm_interfaces__msg__GameStatus__RUNNING = 4
};

/// Constant 'GAME_OVER'.
/**
  * 比赛结算中
 */
enum
{
  pb_rm_interfaces__msg__GameStatus__GAME_OVER = 5
};

/// Struct defined in msg/GameStatus in the package pb_rm_interfaces.
/**
  * 比赛状态数据 (裁判系统串口协议 V1.7.0 0x0001)
 */
typedef struct pb_rm_interfaces__msg__GameStatus
{
  uint8_t game_progress;
  /// 当前阶段剩余时间，单位：秒
  int32_t stage_remain_time;
} pb_rm_interfaces__msg__GameStatus;

// Struct for a sequence of pb_rm_interfaces__msg__GameStatus.
typedef struct pb_rm_interfaces__msg__GameStatus__Sequence
{
  pb_rm_interfaces__msg__GameStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__GameStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_
