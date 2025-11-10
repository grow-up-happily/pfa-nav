// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmoss_interfaces:msg/GimbalCmd.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/msg/detail/gimbal_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `position`
// Member `velocity`
#include "rmoss_interfaces/msg/detail/gimbal__functions.h"

bool
rmoss_interfaces__msg__GimbalCmd__init(rmoss_interfaces__msg__GimbalCmd * msg)
{
  if (!msg) {
    return false;
  }
  // tid
  // yaw_type
  msg->yaw_type = 1;
  // pitch_type
  msg->pitch_type = 1;
  // position
  if (!rmoss_interfaces__msg__Gimbal__init(&msg->position)) {
    rmoss_interfaces__msg__GimbalCmd__fini(msg);
    return false;
  }
  // velocity
  if (!rmoss_interfaces__msg__Gimbal__init(&msg->velocity)) {
    rmoss_interfaces__msg__GimbalCmd__fini(msg);
    return false;
  }
  return true;
}

void
rmoss_interfaces__msg__GimbalCmd__fini(rmoss_interfaces__msg__GimbalCmd * msg)
{
  if (!msg) {
    return;
  }
  // tid
  // yaw_type
  // pitch_type
  // position
  rmoss_interfaces__msg__Gimbal__fini(&msg->position);
  // velocity
  rmoss_interfaces__msg__Gimbal__fini(&msg->velocity);
}

bool
rmoss_interfaces__msg__GimbalCmd__are_equal(const rmoss_interfaces__msg__GimbalCmd * lhs, const rmoss_interfaces__msg__GimbalCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tid
  if (lhs->tid != rhs->tid) {
    return false;
  }
  // yaw_type
  if (lhs->yaw_type != rhs->yaw_type) {
    return false;
  }
  // pitch_type
  if (lhs->pitch_type != rhs->pitch_type) {
    return false;
  }
  // position
  if (!rmoss_interfaces__msg__Gimbal__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // velocity
  if (!rmoss_interfaces__msg__Gimbal__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  return true;
}

bool
rmoss_interfaces__msg__GimbalCmd__copy(
  const rmoss_interfaces__msg__GimbalCmd * input,
  rmoss_interfaces__msg__GimbalCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // tid
  output->tid = input->tid;
  // yaw_type
  output->yaw_type = input->yaw_type;
  // pitch_type
  output->pitch_type = input->pitch_type;
  // position
  if (!rmoss_interfaces__msg__Gimbal__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // velocity
  if (!rmoss_interfaces__msg__Gimbal__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  return true;
}

rmoss_interfaces__msg__GimbalCmd *
rmoss_interfaces__msg__GimbalCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__GimbalCmd * msg = (rmoss_interfaces__msg__GimbalCmd *)allocator.allocate(sizeof(rmoss_interfaces__msg__GimbalCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmoss_interfaces__msg__GimbalCmd));
  bool success = rmoss_interfaces__msg__GimbalCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmoss_interfaces__msg__GimbalCmd__destroy(rmoss_interfaces__msg__GimbalCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmoss_interfaces__msg__GimbalCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmoss_interfaces__msg__GimbalCmd__Sequence__init(rmoss_interfaces__msg__GimbalCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__GimbalCmd * data = NULL;

  if (size) {
    data = (rmoss_interfaces__msg__GimbalCmd *)allocator.zero_allocate(size, sizeof(rmoss_interfaces__msg__GimbalCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmoss_interfaces__msg__GimbalCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmoss_interfaces__msg__GimbalCmd__fini(&data[i - 1]);
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
rmoss_interfaces__msg__GimbalCmd__Sequence__fini(rmoss_interfaces__msg__GimbalCmd__Sequence * array)
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
      rmoss_interfaces__msg__GimbalCmd__fini(&array->data[i]);
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

rmoss_interfaces__msg__GimbalCmd__Sequence *
rmoss_interfaces__msg__GimbalCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__GimbalCmd__Sequence * array = (rmoss_interfaces__msg__GimbalCmd__Sequence *)allocator.allocate(sizeof(rmoss_interfaces__msg__GimbalCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmoss_interfaces__msg__GimbalCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmoss_interfaces__msg__GimbalCmd__Sequence__destroy(rmoss_interfaces__msg__GimbalCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmoss_interfaces__msg__GimbalCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmoss_interfaces__msg__GimbalCmd__Sequence__are_equal(const rmoss_interfaces__msg__GimbalCmd__Sequence * lhs, const rmoss_interfaces__msg__GimbalCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmoss_interfaces__msg__GimbalCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmoss_interfaces__msg__GimbalCmd__Sequence__copy(
  const rmoss_interfaces__msg__GimbalCmd__Sequence * input,
  rmoss_interfaces__msg__GimbalCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmoss_interfaces__msg__GimbalCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmoss_interfaces__msg__GimbalCmd * data =
      (rmoss_interfaces__msg__GimbalCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmoss_interfaces__msg__GimbalCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmoss_interfaces__msg__GimbalCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmoss_interfaces__msg__GimbalCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
