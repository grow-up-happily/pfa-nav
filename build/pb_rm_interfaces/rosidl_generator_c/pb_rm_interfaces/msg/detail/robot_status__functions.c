// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pb_rm_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/robot_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_pos`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
pb_rm_interfaces__msg__RobotStatus__init(pb_rm_interfaces__msg__RobotStatus * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  // robot_level
  // current_hp
  // maximum_hp
  // shooter_barrel_cooling_value
  // shooter_barrel_heat_limit
  // shooter_17mm_1_barrel_heat
  // robot_pos
  if (!geometry_msgs__msg__Pose__init(&msg->robot_pos)) {
    pb_rm_interfaces__msg__RobotStatus__fini(msg);
    return false;
  }
  // armor_id
  // hp_deduction_reason
  // projectile_allowance_17mm
  // remaining_gold_coin
  // is_hp_deduced
  return true;
}

void
pb_rm_interfaces__msg__RobotStatus__fini(pb_rm_interfaces__msg__RobotStatus * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  // robot_level
  // current_hp
  // maximum_hp
  // shooter_barrel_cooling_value
  // shooter_barrel_heat_limit
  // shooter_17mm_1_barrel_heat
  // robot_pos
  geometry_msgs__msg__Pose__fini(&msg->robot_pos);
  // armor_id
  // hp_deduction_reason
  // projectile_allowance_17mm
  // remaining_gold_coin
  // is_hp_deduced
}

bool
pb_rm_interfaces__msg__RobotStatus__are_equal(const pb_rm_interfaces__msg__RobotStatus * lhs, const pb_rm_interfaces__msg__RobotStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (lhs->robot_id != rhs->robot_id) {
    return false;
  }
  // robot_level
  if (lhs->robot_level != rhs->robot_level) {
    return false;
  }
  // current_hp
  if (lhs->current_hp != rhs->current_hp) {
    return false;
  }
  // maximum_hp
  if (lhs->maximum_hp != rhs->maximum_hp) {
    return false;
  }
  // shooter_barrel_cooling_value
  if (lhs->shooter_barrel_cooling_value != rhs->shooter_barrel_cooling_value) {
    return false;
  }
  // shooter_barrel_heat_limit
  if (lhs->shooter_barrel_heat_limit != rhs->shooter_barrel_heat_limit) {
    return false;
  }
  // shooter_17mm_1_barrel_heat
  if (lhs->shooter_17mm_1_barrel_heat != rhs->shooter_17mm_1_barrel_heat) {
    return false;
  }
  // robot_pos
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->robot_pos), &(rhs->robot_pos)))
  {
    return false;
  }
  // armor_id
  if (lhs->armor_id != rhs->armor_id) {
    return false;
  }
  // hp_deduction_reason
  if (lhs->hp_deduction_reason != rhs->hp_deduction_reason) {
    return false;
  }
  // projectile_allowance_17mm
  if (lhs->projectile_allowance_17mm != rhs->projectile_allowance_17mm) {
    return false;
  }
  // remaining_gold_coin
  if (lhs->remaining_gold_coin != rhs->remaining_gold_coin) {
    return false;
  }
  // is_hp_deduced
  if (lhs->is_hp_deduced != rhs->is_hp_deduced) {
    return false;
  }
  return true;
}

bool
pb_rm_interfaces__msg__RobotStatus__copy(
  const pb_rm_interfaces__msg__RobotStatus * input,
  pb_rm_interfaces__msg__RobotStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  output->robot_id = input->robot_id;
  // robot_level
  output->robot_level = input->robot_level;
  // current_hp
  output->current_hp = input->current_hp;
  // maximum_hp
  output->maximum_hp = input->maximum_hp;
  // shooter_barrel_cooling_value
  output->shooter_barrel_cooling_value = input->shooter_barrel_cooling_value;
  // shooter_barrel_heat_limit
  output->shooter_barrel_heat_limit = input->shooter_barrel_heat_limit;
  // shooter_17mm_1_barrel_heat
  output->shooter_17mm_1_barrel_heat = input->shooter_17mm_1_barrel_heat;
  // robot_pos
  if (!geometry_msgs__msg__Pose__copy(
      &(input->robot_pos), &(output->robot_pos)))
  {
    return false;
  }
  // armor_id
  output->armor_id = input->armor_id;
  // hp_deduction_reason
  output->hp_deduction_reason = input->hp_deduction_reason;
  // projectile_allowance_17mm
  output->projectile_allowance_17mm = input->projectile_allowance_17mm;
  // remaining_gold_coin
  output->remaining_gold_coin = input->remaining_gold_coin;
  // is_hp_deduced
  output->is_hp_deduced = input->is_hp_deduced;
  return true;
}

pb_rm_interfaces__msg__RobotStatus *
pb_rm_interfaces__msg__RobotStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__RobotStatus * msg = (pb_rm_interfaces__msg__RobotStatus *)allocator.allocate(sizeof(pb_rm_interfaces__msg__RobotStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pb_rm_interfaces__msg__RobotStatus));
  bool success = pb_rm_interfaces__msg__RobotStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pb_rm_interfaces__msg__RobotStatus__destroy(pb_rm_interfaces__msg__RobotStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pb_rm_interfaces__msg__RobotStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pb_rm_interfaces__msg__RobotStatus__Sequence__init(pb_rm_interfaces__msg__RobotStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__RobotStatus * data = NULL;

  if (size) {
    data = (pb_rm_interfaces__msg__RobotStatus *)allocator.zero_allocate(size, sizeof(pb_rm_interfaces__msg__RobotStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pb_rm_interfaces__msg__RobotStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pb_rm_interfaces__msg__RobotStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pb_rm_interfaces__msg__RobotStatus__Sequence__fini(pb_rm_interfaces__msg__RobotStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pb_rm_interfaces__msg__RobotStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pb_rm_interfaces__msg__RobotStatus__Sequence *
pb_rm_interfaces__msg__RobotStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__RobotStatus__Sequence * array = (pb_rm_interfaces__msg__RobotStatus__Sequence *)allocator.allocate(sizeof(pb_rm_interfaces__msg__RobotStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pb_rm_interfaces__msg__RobotStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pb_rm_interfaces__msg__RobotStatus__Sequence__destroy(pb_rm_interfaces__msg__RobotStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pb_rm_interfaces__msg__RobotStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pb_rm_interfaces__msg__RobotStatus__Sequence__are_equal(const pb_rm_interfaces__msg__RobotStatus__Sequence * lhs, const pb_rm_interfaces__msg__RobotStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pb_rm_interfaces__msg__RobotStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pb_rm_interfaces__msg__RobotStatus__Sequence__copy(
  const pb_rm_interfaces__msg__RobotStatus__Sequence * input,
  pb_rm_interfaces__msg__RobotStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pb_rm_interfaces__msg__RobotStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pb_rm_interfaces__msg__RobotStatus * data =
      (pb_rm_interfaces__msg__RobotStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pb_rm_interfaces__msg__RobotStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pb_rm_interfaces__msg__RobotStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pb_rm_interfaces__msg__RobotStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
