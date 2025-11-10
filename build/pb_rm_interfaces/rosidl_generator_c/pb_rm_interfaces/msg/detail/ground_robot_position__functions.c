// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pb_rm_interfaces:msg/GroundRobotPosition.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/ground_robot_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `hero_position`
// Member `engineer_position`
// Member `standard_3_position`
// Member `standard_4_position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
pb_rm_interfaces__msg__GroundRobotPosition__init(pb_rm_interfaces__msg__GroundRobotPosition * msg)
{
  if (!msg) {
    return false;
  }
  // hero_position
  if (!geometry_msgs__msg__Point__init(&msg->hero_position)) {
    pb_rm_interfaces__msg__GroundRobotPosition__fini(msg);
    return false;
  }
  // engineer_position
  if (!geometry_msgs__msg__Point__init(&msg->engineer_position)) {
    pb_rm_interfaces__msg__GroundRobotPosition__fini(msg);
    return false;
  }
  // standard_3_position
  if (!geometry_msgs__msg__Point__init(&msg->standard_3_position)) {
    pb_rm_interfaces__msg__GroundRobotPosition__fini(msg);
    return false;
  }
  // standard_4_position
  if (!geometry_msgs__msg__Point__init(&msg->standard_4_position)) {
    pb_rm_interfaces__msg__GroundRobotPosition__fini(msg);
    return false;
  }
  return true;
}

void
pb_rm_interfaces__msg__GroundRobotPosition__fini(pb_rm_interfaces__msg__GroundRobotPosition * msg)
{
  if (!msg) {
    return;
  }
  // hero_position
  geometry_msgs__msg__Point__fini(&msg->hero_position);
  // engineer_position
  geometry_msgs__msg__Point__fini(&msg->engineer_position);
  // standard_3_position
  geometry_msgs__msg__Point__fini(&msg->standard_3_position);
  // standard_4_position
  geometry_msgs__msg__Point__fini(&msg->standard_4_position);
}

bool
pb_rm_interfaces__msg__GroundRobotPosition__are_equal(const pb_rm_interfaces__msg__GroundRobotPosition * lhs, const pb_rm_interfaces__msg__GroundRobotPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // hero_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->hero_position), &(rhs->hero_position)))
  {
    return false;
  }
  // engineer_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->engineer_position), &(rhs->engineer_position)))
  {
    return false;
  }
  // standard_3_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->standard_3_position), &(rhs->standard_3_position)))
  {
    return false;
  }
  // standard_4_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->standard_4_position), &(rhs->standard_4_position)))
  {
    return false;
  }
  return true;
}

bool
pb_rm_interfaces__msg__GroundRobotPosition__copy(
  const pb_rm_interfaces__msg__GroundRobotPosition * input,
  pb_rm_interfaces__msg__GroundRobotPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // hero_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->hero_position), &(output->hero_position)))
  {
    return false;
  }
  // engineer_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->engineer_position), &(output->engineer_position)))
  {
    return false;
  }
  // standard_3_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->standard_3_position), &(output->standard_3_position)))
  {
    return false;
  }
  // standard_4_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->standard_4_position), &(output->standard_4_position)))
  {
    return false;
  }
  return true;
}

pb_rm_interfaces__msg__GroundRobotPosition *
pb_rm_interfaces__msg__GroundRobotPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__GroundRobotPosition * msg = (pb_rm_interfaces__msg__GroundRobotPosition *)allocator.allocate(sizeof(pb_rm_interfaces__msg__GroundRobotPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pb_rm_interfaces__msg__GroundRobotPosition));
  bool success = pb_rm_interfaces__msg__GroundRobotPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pb_rm_interfaces__msg__GroundRobotPosition__destroy(pb_rm_interfaces__msg__GroundRobotPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pb_rm_interfaces__msg__GroundRobotPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pb_rm_interfaces__msg__GroundRobotPosition__Sequence__init(pb_rm_interfaces__msg__GroundRobotPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__GroundRobotPosition * data = NULL;

  if (size) {
    data = (pb_rm_interfaces__msg__GroundRobotPosition *)allocator.zero_allocate(size, sizeof(pb_rm_interfaces__msg__GroundRobotPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pb_rm_interfaces__msg__GroundRobotPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pb_rm_interfaces__msg__GroundRobotPosition__fini(&data[i - 1]);
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
pb_rm_interfaces__msg__GroundRobotPosition__Sequence__fini(pb_rm_interfaces__msg__GroundRobotPosition__Sequence * array)
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
      pb_rm_interfaces__msg__GroundRobotPosition__fini(&array->data[i]);
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

pb_rm_interfaces__msg__GroundRobotPosition__Sequence *
pb_rm_interfaces__msg__GroundRobotPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__GroundRobotPosition__Sequence * array = (pb_rm_interfaces__msg__GroundRobotPosition__Sequence *)allocator.allocate(sizeof(pb_rm_interfaces__msg__GroundRobotPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pb_rm_interfaces__msg__GroundRobotPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pb_rm_interfaces__msg__GroundRobotPosition__Sequence__destroy(pb_rm_interfaces__msg__GroundRobotPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pb_rm_interfaces__msg__GroundRobotPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pb_rm_interfaces__msg__GroundRobotPosition__Sequence__are_equal(const pb_rm_interfaces__msg__GroundRobotPosition__Sequence * lhs, const pb_rm_interfaces__msg__GroundRobotPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pb_rm_interfaces__msg__GroundRobotPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pb_rm_interfaces__msg__GroundRobotPosition__Sequence__copy(
  const pb_rm_interfaces__msg__GroundRobotPosition__Sequence * input,
  pb_rm_interfaces__msg__GroundRobotPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pb_rm_interfaces__msg__GroundRobotPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pb_rm_interfaces__msg__GroundRobotPosition * data =
      (pb_rm_interfaces__msg__GroundRobotPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pb_rm_interfaces__msg__GroundRobotPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pb_rm_interfaces__msg__GroundRobotPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pb_rm_interfaces__msg__GroundRobotPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
