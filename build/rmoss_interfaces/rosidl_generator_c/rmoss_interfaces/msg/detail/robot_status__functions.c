// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmoss_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/msg/detail/robot_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `gt_tf`
#include "geometry_msgs/msg/detail/transform__functions.h"

bool
rmoss_interfaces__msg__RobotStatus__init(rmoss_interfaces__msg__RobotStatus * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // level
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    rmoss_interfaces__msg__RobotStatus__fini(msg);
    return false;
  }
  // remain_hp
  // max_hp
  // total_projectiles
  // used_projectiles
  // hit_projectiles
  // gt_tf
  if (!geometry_msgs__msg__Transform__init(&msg->gt_tf)) {
    rmoss_interfaces__msg__RobotStatus__fini(msg);
    return false;
  }
  return true;
}

void
rmoss_interfaces__msg__RobotStatus__fini(rmoss_interfaces__msg__RobotStatus * msg)
{
  if (!msg) {
    return;
  }
  // id
  // level
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // remain_hp
  // max_hp
  // total_projectiles
  // used_projectiles
  // hit_projectiles
  // gt_tf
  geometry_msgs__msg__Transform__fini(&msg->gt_tf);
}

bool
rmoss_interfaces__msg__RobotStatus__are_equal(const rmoss_interfaces__msg__RobotStatus * lhs, const rmoss_interfaces__msg__RobotStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // level
  if (lhs->level != rhs->level) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // remain_hp
  if (lhs->remain_hp != rhs->remain_hp) {
    return false;
  }
  // max_hp
  if (lhs->max_hp != rhs->max_hp) {
    return false;
  }
  // total_projectiles
  if (lhs->total_projectiles != rhs->total_projectiles) {
    return false;
  }
  // used_projectiles
  if (lhs->used_projectiles != rhs->used_projectiles) {
    return false;
  }
  // hit_projectiles
  if (lhs->hit_projectiles != rhs->hit_projectiles) {
    return false;
  }
  // gt_tf
  if (!geometry_msgs__msg__Transform__are_equal(
      &(lhs->gt_tf), &(rhs->gt_tf)))
  {
    return false;
  }
  return true;
}

bool
rmoss_interfaces__msg__RobotStatus__copy(
  const rmoss_interfaces__msg__RobotStatus * input,
  rmoss_interfaces__msg__RobotStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // level
  output->level = input->level;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // remain_hp
  output->remain_hp = input->remain_hp;
  // max_hp
  output->max_hp = input->max_hp;
  // total_projectiles
  output->total_projectiles = input->total_projectiles;
  // used_projectiles
  output->used_projectiles = input->used_projectiles;
  // hit_projectiles
  output->hit_projectiles = input->hit_projectiles;
  // gt_tf
  if (!geometry_msgs__msg__Transform__copy(
      &(input->gt_tf), &(output->gt_tf)))
  {
    return false;
  }
  return true;
}

rmoss_interfaces__msg__RobotStatus *
rmoss_interfaces__msg__RobotStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__RobotStatus * msg = (rmoss_interfaces__msg__RobotStatus *)allocator.allocate(sizeof(rmoss_interfaces__msg__RobotStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmoss_interfaces__msg__RobotStatus));
  bool success = rmoss_interfaces__msg__RobotStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmoss_interfaces__msg__RobotStatus__destroy(rmoss_interfaces__msg__RobotStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmoss_interfaces__msg__RobotStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmoss_interfaces__msg__RobotStatus__Sequence__init(rmoss_interfaces__msg__RobotStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__RobotStatus * data = NULL;

  if (size) {
    data = (rmoss_interfaces__msg__RobotStatus *)allocator.zero_allocate(size, sizeof(rmoss_interfaces__msg__RobotStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmoss_interfaces__msg__RobotStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmoss_interfaces__msg__RobotStatus__fini(&data[i - 1]);
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
rmoss_interfaces__msg__RobotStatus__Sequence__fini(rmoss_interfaces__msg__RobotStatus__Sequence * array)
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
      rmoss_interfaces__msg__RobotStatus__fini(&array->data[i]);
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

rmoss_interfaces__msg__RobotStatus__Sequence *
rmoss_interfaces__msg__RobotStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__RobotStatus__Sequence * array = (rmoss_interfaces__msg__RobotStatus__Sequence *)allocator.allocate(sizeof(rmoss_interfaces__msg__RobotStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmoss_interfaces__msg__RobotStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmoss_interfaces__msg__RobotStatus__Sequence__destroy(rmoss_interfaces__msg__RobotStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmoss_interfaces__msg__RobotStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmoss_interfaces__msg__RobotStatus__Sequence__are_equal(const rmoss_interfaces__msg__RobotStatus__Sequence * lhs, const rmoss_interfaces__msg__RobotStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmoss_interfaces__msg__RobotStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmoss_interfaces__msg__RobotStatus__Sequence__copy(
  const rmoss_interfaces__msg__RobotStatus__Sequence * input,
  rmoss_interfaces__msg__RobotStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmoss_interfaces__msg__RobotStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmoss_interfaces__msg__RobotStatus * data =
      (rmoss_interfaces__msg__RobotStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmoss_interfaces__msg__RobotStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmoss_interfaces__msg__RobotStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmoss_interfaces__msg__RobotStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
