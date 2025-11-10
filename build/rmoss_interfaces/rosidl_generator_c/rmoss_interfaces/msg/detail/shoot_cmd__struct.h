// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rmoss_interfaces:msg/ShootCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__STRUCT_H_
#define RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ShootCmd in the package rmoss_interfaces.
/**
  * cmd msg for shooter
  * id of task
 */
typedef struct rmoss_interfaces__msg__ShootCmd
{
  uint8_t tid;
  uint8_t type;
  /// control data
  uint8_t projectile_num;
  float projectile_velocity;
} rmoss_interfaces__msg__ShootCmd;

// Struct for a sequence of rmoss_interfaces__msg__ShootCmd.
typedef struct rmoss_interfaces__msg__ShootCmd__Sequence
{
  rmoss_interfaces__msg__ShootCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rmoss_interfaces__msg__ShootCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__STRUCT_H_
