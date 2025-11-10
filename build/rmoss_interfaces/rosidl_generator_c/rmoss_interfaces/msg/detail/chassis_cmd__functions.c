// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmoss_interfaces:msg/ChassisCmd.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/msg/detail/chassis_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `twist`
#include "geometry_msgs/msg/detail/twist__functions.h"
// Member `accel`
#include "geometry_msgs/msg/detail/accel__functions.h"

bool
rmoss_interfaces__msg__ChassisCmd__init(rmoss_interfaces__msg__ChassisCmd * msg)
{
  if (!msg) {
    return false;
  }
  // tid
  // type
  msg->type = 1;
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    rmoss_interfaces__msg__ChassisCmd__fini(msg);
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__init(&msg->twist)) {
    rmoss_interfaces__msg__ChassisCmd__fini(msg);
    return false;
  }
  // accel
  if (!geometry_msgs__msg__Accel__init(&msg->accel)) {
    rmoss_interfaces__msg__ChassisCmd__fini(msg);
    return false;
  }
  return true;
}

void
rmoss_interfaces__msg__ChassisCmd__fini(rmoss_interfaces__msg__ChassisCmd * msg)
{
  if (!msg) {
    return;
  }
  // tid
  // type
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // twist
  geometry_msgs__msg__Twist__fini(&msg->twist);
  // accel
  geometry_msgs__msg__Accel__fini(&msg->accel);
}

bool
rmoss_interfaces__msg__ChassisCmd__are_equal(const rmoss_interfaces__msg__ChassisCmd * lhs, const rmoss_interfaces__msg__ChassisCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tid
  if (lhs->tid != rhs->tid) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__are_equal(
      &(lhs->twist), &(rhs->twist)))
  {
    return false;
  }
  // accel
  if (!geometry_msgs__msg__Accel__are_equal(
      &(lhs->accel), &(rhs->accel)))
  {
    return false;
  }
  return true;
}

bool
rmoss_interfaces__msg__ChassisCmd__copy(
  const rmoss_interfaces__msg__ChassisCmd * input,
  rmoss_interfaces__msg__ChassisCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // tid
  output->tid = input->tid;
  // type
  output->type = input->type;
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__copy(
      &(input->twist), &(output->twist)))
  {
    return false;
  }
  // accel
  if (!geometry_msgs__msg__Accel__copy(
      &(input->accel), &(output->accel)))
  {
    return false;
  }
  return true;
}

rmoss_interfaces__msg__ChassisCmd *
rmoss_interfaces__msg__ChassisCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__ChassisCmd * msg = (rmoss_interfaces__msg__ChassisCmd *)allocator.allocate(sizeof(rmoss_interfaces__msg__ChassisCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmoss_interfaces__msg__ChassisCmd));
  bool success = rmoss_interfaces__msg__ChassisCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmoss_interfaces__msg__ChassisCmd__destroy(rmoss_interfaces__msg__ChassisCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmoss_interfaces__msg__ChassisCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmoss_interfaces__msg__ChassisCmd__Sequence__init(rmoss_interfaces__msg__ChassisCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__ChassisCmd * data = NULL;

  if (size) {
    data = (rmoss_interfaces__msg__ChassisCmd *)allocator.zero_allocate(size, sizeof(rmoss_interfaces__msg__ChassisCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmoss_interfaces__msg__ChassisCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmoss_interfaces__msg__ChassisCmd__fini(&data[i - 1]);
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
rmoss_interfaces__msg__ChassisCmd__Sequence__fini(rmoss_interfaces__msg__ChassisCmd__Sequence * array)
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
      rmoss_interfaces__msg__ChassisCmd__fini(&array->data[i]);
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

rmoss_interfaces__msg__ChassisCmd__Sequence *
rmoss_interfaces__msg__ChassisCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__ChassisCmd__Sequence * array = (rmoss_interfaces__msg__ChassisCmd__Sequence *)allocator.allocate(sizeof(rmoss_interfaces__msg__ChassisCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmoss_interfaces__msg__ChassisCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmoss_interfaces__msg__ChassisCmd__Sequence__destroy(rmoss_interfaces__msg__ChassisCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmoss_interfaces__msg__ChassisCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmoss_interfaces__msg__ChassisCmd__Sequence__are_equal(const rmoss_interfaces__msg__ChassisCmd__Sequence * lhs, const rmoss_interfaces__msg__ChassisCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmoss_interfaces__msg__ChassisCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmoss_interfaces__msg__ChassisCmd__Sequence__copy(
  const rmoss_interfaces__msg__ChassisCmd__Sequence * input,
  rmoss_interfaces__msg__ChassisCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmoss_interfaces__msg__ChassisCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmoss_interfaces__msg__ChassisCmd * data =
      (rmoss_interfaces__msg__ChassisCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmoss_interfaces__msg__ChassisCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmoss_interfaces__msg__ChassisCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmoss_interfaces__msg__ChassisCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
