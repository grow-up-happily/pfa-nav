// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmoss_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/msg/detail/game_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rmoss_interfaces__msg__GameStatus__init(rmoss_interfaces__msg__GameStatus * msg)
{
  if (!msg) {
    return false;
  }
  // status
  msg->status = 0;
  // total_time
  msg->total_time = 0l;
  // current_time
  msg->current_time = 0l;
  // result
  return true;
}

void
rmoss_interfaces__msg__GameStatus__fini(rmoss_interfaces__msg__GameStatus * msg)
{
  if (!msg) {
    return;
  }
  // status
  // total_time
  // current_time
  // result
}

bool
rmoss_interfaces__msg__GameStatus__are_equal(const rmoss_interfaces__msg__GameStatus * lhs, const rmoss_interfaces__msg__GameStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // total_time
  if (lhs->total_time != rhs->total_time) {
    return false;
  }
  // current_time
  if (lhs->current_time != rhs->current_time) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
rmoss_interfaces__msg__GameStatus__copy(
  const rmoss_interfaces__msg__GameStatus * input,
  rmoss_interfaces__msg__GameStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // total_time
  output->total_time = input->total_time;
  // current_time
  output->current_time = input->current_time;
  // result
  output->result = input->result;
  return true;
}

rmoss_interfaces__msg__GameStatus *
rmoss_interfaces__msg__GameStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__GameStatus * msg = (rmoss_interfaces__msg__GameStatus *)allocator.allocate(sizeof(rmoss_interfaces__msg__GameStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmoss_interfaces__msg__GameStatus));
  bool success = rmoss_interfaces__msg__GameStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmoss_interfaces__msg__GameStatus__destroy(rmoss_interfaces__msg__GameStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmoss_interfaces__msg__GameStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmoss_interfaces__msg__GameStatus__Sequence__init(rmoss_interfaces__msg__GameStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__GameStatus * data = NULL;

  if (size) {
    data = (rmoss_interfaces__msg__GameStatus *)allocator.zero_allocate(size, sizeof(rmoss_interfaces__msg__GameStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmoss_interfaces__msg__GameStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmoss_interfaces__msg__GameStatus__fini(&data[i - 1]);
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
rmoss_interfaces__msg__GameStatus__Sequence__fini(rmoss_interfaces__msg__GameStatus__Sequence * array)
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
      rmoss_interfaces__msg__GameStatus__fini(&array->data[i]);
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

rmoss_interfaces__msg__GameStatus__Sequence *
rmoss_interfaces__msg__GameStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__GameStatus__Sequence * array = (rmoss_interfaces__msg__GameStatus__Sequence *)allocator.allocate(sizeof(rmoss_interfaces__msg__GameStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmoss_interfaces__msg__GameStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmoss_interfaces__msg__GameStatus__Sequence__destroy(rmoss_interfaces__msg__GameStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmoss_interfaces__msg__GameStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmoss_interfaces__msg__GameStatus__Sequence__are_equal(const rmoss_interfaces__msg__GameStatus__Sequence * lhs, const rmoss_interfaces__msg__GameStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmoss_interfaces__msg__GameStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmoss_interfaces__msg__GameStatus__Sequence__copy(
  const rmoss_interfaces__msg__GameStatus__Sequence * input,
  rmoss_interfaces__msg__GameStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmoss_interfaces__msg__GameStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmoss_interfaces__msg__GameStatus * data =
      (rmoss_interfaces__msg__GameStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmoss_interfaces__msg__GameStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmoss_interfaces__msg__GameStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmoss_interfaces__msg__GameStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
