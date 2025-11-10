// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'NOT_DETECTED'.
/**
  * const for RFID status
  * RFID card not detected
 */
enum
{
  pb_rm_interfaces__msg__RfidStatus__NOT_DETECTED = 0
};

/// Constant 'DETECTED'.
/**
  * RFID card detected
 */
enum
{
  pb_rm_interfaces__msg__RfidStatus__DETECTED = 1
};

/// Struct defined in msg/RfidStatus in the package pb_rm_interfaces.
/**
  * 机器人 RFID 模块状态 (裁判系统串口协议 V1.7.0 0x0209)
 */
typedef struct pb_rm_interfaces__msg__RfidStatus
{
  /// 己方基地增益点
  bool base_gain_point;
  /// 己方中央高地增益点
  bool central_highland_gain_point;
  /// 对方中央高地增益点
  bool enemy_central_highland_gain_point;
  /// 己方梯形高地增益点
  bool friendly_trapezoidal_highland_gain_point;
  /// 对方梯形高地增益点
  bool enemy_trapezoidal_highland_gain_point;
  /// 己方地形跨越增益点（飞坡）（靠近己方一侧飞坡前）
  bool friendly_fly_ramp_front_gain_point;
  /// 己方地形跨越增益点（飞坡）（靠近己方一侧飞坡后）
  bool friendly_fly_ramp_back_gain_point;
  /// 对方地形跨越增益点（飞坡）（靠近对方一侧飞坡前）
  bool enemy_fly_ramp_front_gain_point;
  /// 对方地形跨越增益点（飞坡）（靠近对方一侧飞坡后）
  bool enemy_fly_ramp_back_gain_point;
  /// 己方地形跨越增益点（中央高地下方）
  bool friendly_central_highland_lower_gain_point;
  /// 己方地形跨越增益点（中央高地上方）
  bool friendly_central_highland_upper_gain_point;
  /// 对方地形跨越增益点（中央高地下方）
  bool enemy_central_highland_lower_gain_point;
  /// 对方地形跨越增益点（中央高地上方）
  bool enemy_central_highland_upper_gain_point;
  /// 己方地形跨越增益点（公路下方）
  bool friendly_highway_lower_gain_point;
  /// 己方地形跨越增益点（公路上方）
  bool friendly_highway_upper_gain_point;
  /// 对方地形跨越增益点（公路下方）
  bool enemy_highway_lower_gain_point;
  /// 对方地形跨越增益点（公路上方）
  bool enemy_highway_upper_gain_point;
  /// 己方堡垒增益点
  bool friendly_fortress_gain_point;
  /// 己方前哨站增益点
  bool friendly_outpost_gain_point;
  /// 己方与兑换区不重叠的补给区/RMUL 补给区
  bool friendly_supply_zone_non_exchange;
  /// 己方与兑换区重叠的补给区
  bool friendly_supply_zone_exchange;
  /// 己方大资源岛增益点
  bool friendly_big_resource_island;
  /// 对方大资源岛增益点
  bool enemy_big_resource_island;
  /// 中心增益点（仅 RMUL 适用）
  bool center_gain_point;
} pb_rm_interfaces__msg__RfidStatus;

// Struct for a sequence of pb_rm_interfaces__msg__RfidStatus.
typedef struct pb_rm_interfaces__msg__RfidStatus__Sequence
{
  pb_rm_interfaces__msg__RfidStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__RfidStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_H_
