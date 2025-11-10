// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ARMOR_HIT'.
/**
  * 伤害状态数据 (裁判系统串口协议 V1.7.0 0x0206)
  * const for hp_deduction_reason
  * 装甲模块被弹丸攻击导致扣血
 */
enum
{
  pb_rm_interfaces__msg__RobotStatus__ARMOR_HIT = 0
};

/// Constant 'SYSTEM_OFFLINE'.
/**
  * 裁判系统重要模块离线导致扣血
 */
enum
{
  pb_rm_interfaces__msg__RobotStatus__SYSTEM_OFFLINE = 1
};

/// Constant 'OVER_SHOOT_SPEED'.
/**
  * 射击初速度超限导致扣血
 */
enum
{
  pb_rm_interfaces__msg__RobotStatus__OVER_SHOOT_SPEED = 2
};

/// Constant 'OVER_HEAT'.
/**
  * 枪口热量超限导致扣血
 */
enum
{
  pb_rm_interfaces__msg__RobotStatus__OVER_HEAT = 3
};

/// Constant 'OVER_POWER'.
/**
  * 底盘功率超限导致扣血
 */
enum
{
  pb_rm_interfaces__msg__RobotStatus__OVER_POWER = 4
};

/// Constant 'ARMOR_COLLISION'.
/**
  * 装甲模块受到撞击导致扣血
 */
enum
{
  pb_rm_interfaces__msg__RobotStatus__ARMOR_COLLISION = 5
};

// Include directives for member types
// Member 'robot_pos'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/RobotStatus in the package pb_rm_interfaces.
/**
  * 机器人性能体系数据 (裁判系统串口协议 V1.7.0 0x0201)
 */
typedef struct pb_rm_interfaces__msg__RobotStatus
{
  /// 本机器人 ID
  uint8_t robot_id;
  /// 机器人等级
  uint8_t robot_level;
  /// 机器人当前血量
  uint16_t current_hp;
  /// 机器人血量上限
  uint16_t maximum_hp;
  /// 机器人枪口热量每秒冷却值
  uint16_t shooter_barrel_cooling_value;
  /// 机器人枪口热量上限
  uint16_t shooter_barrel_heat_limit;
  /// 实时底盘缓冲能量和射击热量数 (裁判系统串口协议 V1.7.0 0x0202)
  /// 第 1 个 17mm 发射机构的枪口热量
  uint16_t shooter_17mm_1_barrel_heat;
  /// 本机机器人位置数据 (裁判系统串口协议 V1.7.0 0x0203)
  /// 本机器人姿态
  geometry_msgs__msg__Pose robot_pos;
  /// 当扣血原因为装甲模块被弹丸攻击、受撞击、离线或测速模块离线时，
  /// 数值为装甲模块或测速模块的 ID 编号；当其他原因导致扣血时，该数值为 0
  uint8_t armor_id;
  /// 血量变化类型
  uint8_t hp_deduction_reason;
  /// 允许发弹量 (裁判系统串口协议 V1.7.0 0x0208)
  /// 17mm 弹丸剩余发射次数
  uint16_t projectile_allowance_17mm;
  /// 剩余金币数量
  uint16_t remaining_gold_coin;
  /// 血量是否下降（上位机二次处理）
  bool is_hp_deduced;
} pb_rm_interfaces__msg__RobotStatus;

// Struct for a sequence of pb_rm_interfaces__msg__RobotStatus.
typedef struct pb_rm_interfaces__msg__RobotStatus__Sequence
{
  pb_rm_interfaces__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
