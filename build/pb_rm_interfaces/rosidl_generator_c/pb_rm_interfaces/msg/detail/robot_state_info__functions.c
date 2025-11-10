// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pb_rm_interfaces:msg/RobotStateInfo.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/robot_state_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `models`
#include "pb_rm_interfaces/msg/detail/models__functions.h"

bool
pb_rm_interfaces__msg__RobotStateInfo__init(pb_rm_interfaces__msg__RobotStateInfo * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pb_rm_interfaces__msg__RobotStateInfo__fini(msg);
    return false;
  }
  // models
  if (!pb_rm_interfaces__msg__Models__init(&msg->models)) {
    pb_rm_interfaces__msg__RobotStateInfo__fini(msg);
    return false;
  }
  return true;
}

void
pb_rm_interfaces__msg__RobotStateInfo__fini(pb_rm_interfaces__msg__RobotStateInfo * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // models
  pb_rm_interfaces__msg__Models__fini(&msg->models);
}

bool
pb_rm_interfaces__msg__RobotStateInfo__are_equal(const pb_rm_interfaces__msg__RobotStateInfo * lhs, const pb_rm_interfaces__msg__RobotStateInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // models
  if (!pb_rm_interfaces__msg__Models__are_equal(
      &(lhs->models), &(rhs->models)))
  {
    return false;
  }
  return true;
}

bool
pb_rm_interfaces__msg__RobotStateInfo__copy(
  const pb_rm_interfaces__msg__RobotStateInfo * input,
  pb_rm_interfaces__msg__RobotStateInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // models
  if (!pb_rm_interfaces__msg__Models__copy(
      &(input->models), &(output->models)))
  {
    return false;
  }
  return true;
}

pb_rm_interfaces__msg__RobotStateInfo *
pb_rm_interfaces__msg__RobotStateInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__RobotStateInfo * msg = (pb_rm_interfaces__msg__RobotStateInfo *)allocator.allocate(sizeof(pb_rm_interfaces__msg__RobotStateInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pb_rm_interfaces__msg__RobotStateInfo));
  bool success = pb_rm_interfaces__msg__RobotStateInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pb_rm_interfaces__msg__RobotStateInfo__destroy(pb_rm_interfaces__msg__RobotStateInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pb_rm_interfaces__msg__RobotStateInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pb_rm_interfaces__msg__RobotStateInfo__Sequence__init(pb_rm_interfaces__msg__RobotStateInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__RobotStateInfo * data = NULL;

  if (size) {
    data = (pb_rm_interfaces__msg__RobotStateInfo *)allocator.zero_allocate(size, sizeof(pb_rm_interfaces__msg__RobotStateInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pb_rm_interfaces__msg__RobotStateInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pb_rm_interfaces__msg__RobotStateInfo__fini(&data[i - 1]);
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
pb_rm_interfaces__msg__RobotStateInfo__Sequence__fini(pb_rm_interfaces__msg__RobotStateInfo__Sequence * array)
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
      pb_rm_interfaces__msg__RobotStateInfo__fini(&array->data[i]);
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

pb_rm_interfaces__msg__RobotStateInfo__Sequence *
pb_rm_interfaces__msg__RobotStateInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__RobotStateInfo__Sequence * array = (pb_rm_interfaces__msg__RobotStateInfo__Sequence *)allocator.allocate(sizeof(pb_rm_interfaces__msg__RobotStateInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pb_rm_interfaces__msg__RobotStateInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pb_rm_interfaces__msg__RobotStateInfo__Sequence__destroy(pb_rm_interfaces__msg__RobotStateInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pb_rm_interfaces__msg__RobotStateInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pb_rm_interfaces__msg__RobotStateInfo__Sequence__are_equal(const pb_rm_interfaces__msg__RobotStateInfo__Sequence * lhs, const pb_rm_interfaces__msg__RobotStateInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pb_rm_interfaces__msg__RobotStateInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pb_rm_interfaces__msg__RobotStateInfo__Sequence__copy(
  const pb_rm_interfaces__msg__RobotStateInfo__Sequence * input,
  pb_rm_interfaces__msg__RobotStateInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pb_rm_interfaces__msg__RobotStateInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pb_rm_interfaces__msg__RobotStateInfo * data =
      (pb_rm_interfaces__msg__RobotStateInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pb_rm_interfaces__msg__RobotStateInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pb_rm_interfaces__msg__RobotStateInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pb_rm_interfaces__msg__RobotStateInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
