// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmoss_interfaces:msg/ExchangeAmmon.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/msg/detail/exchange_ammon__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_name`
#include "rosidl_runtime_c/string_functions.h"

bool
rmoss_interfaces__msg__ExchangeAmmon__init(rmoss_interfaces__msg__ExchangeAmmon * msg)
{
  if (!msg) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__init(&msg->robot_name)) {
    rmoss_interfaces__msg__ExchangeAmmon__fini(msg);
    return false;
  }
  // ammo_request
  return true;
}

void
rmoss_interfaces__msg__ExchangeAmmon__fini(rmoss_interfaces__msg__ExchangeAmmon * msg)
{
  if (!msg) {
    return;
  }
  // robot_name
  rosidl_runtime_c__String__fini(&msg->robot_name);
  // ammo_request
}

bool
rmoss_interfaces__msg__ExchangeAmmon__are_equal(const rmoss_interfaces__msg__ExchangeAmmon * lhs, const rmoss_interfaces__msg__ExchangeAmmon * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_name), &(rhs->robot_name)))
  {
    return false;
  }
  // ammo_request
  if (lhs->ammo_request != rhs->ammo_request) {
    return false;
  }
  return true;
}

bool
rmoss_interfaces__msg__ExchangeAmmon__copy(
  const rmoss_interfaces__msg__ExchangeAmmon * input,
  rmoss_interfaces__msg__ExchangeAmmon * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_name), &(output->robot_name)))
  {
    return false;
  }
  // ammo_request
  output->ammo_request = input->ammo_request;
  return true;
}

rmoss_interfaces__msg__ExchangeAmmon *
rmoss_interfaces__msg__ExchangeAmmon__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__ExchangeAmmon * msg = (rmoss_interfaces__msg__ExchangeAmmon *)allocator.allocate(sizeof(rmoss_interfaces__msg__ExchangeAmmon), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmoss_interfaces__msg__ExchangeAmmon));
  bool success = rmoss_interfaces__msg__ExchangeAmmon__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmoss_interfaces__msg__ExchangeAmmon__destroy(rmoss_interfaces__msg__ExchangeAmmon * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmoss_interfaces__msg__ExchangeAmmon__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmoss_interfaces__msg__ExchangeAmmon__Sequence__init(rmoss_interfaces__msg__ExchangeAmmon__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__ExchangeAmmon * data = NULL;

  if (size) {
    data = (rmoss_interfaces__msg__ExchangeAmmon *)allocator.zero_allocate(size, sizeof(rmoss_interfaces__msg__ExchangeAmmon), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmoss_interfaces__msg__ExchangeAmmon__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmoss_interfaces__msg__ExchangeAmmon__fini(&data[i - 1]);
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
rmoss_interfaces__msg__ExchangeAmmon__Sequence__fini(rmoss_interfaces__msg__ExchangeAmmon__Sequence * array)
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
      rmoss_interfaces__msg__ExchangeAmmon__fini(&array->data[i]);
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

rmoss_interfaces__msg__ExchangeAmmon__Sequence *
rmoss_interfaces__msg__ExchangeAmmon__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__ExchangeAmmon__Sequence * array = (rmoss_interfaces__msg__ExchangeAmmon__Sequence *)allocator.allocate(sizeof(rmoss_interfaces__msg__ExchangeAmmon__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmoss_interfaces__msg__ExchangeAmmon__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmoss_interfaces__msg__ExchangeAmmon__Sequence__destroy(rmoss_interfaces__msg__ExchangeAmmon__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmoss_interfaces__msg__ExchangeAmmon__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmoss_interfaces__msg__ExchangeAmmon__Sequence__are_equal(const rmoss_interfaces__msg__ExchangeAmmon__Sequence * lhs, const rmoss_interfaces__msg__ExchangeAmmon__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmoss_interfaces__msg__ExchangeAmmon__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmoss_interfaces__msg__ExchangeAmmon__Sequence__copy(
  const rmoss_interfaces__msg__ExchangeAmmon__Sequence * input,
  rmoss_interfaces__msg__ExchangeAmmon__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmoss_interfaces__msg__ExchangeAmmon);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmoss_interfaces__msg__ExchangeAmmon * data =
      (rmoss_interfaces__msg__ExchangeAmmon *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmoss_interfaces__msg__ExchangeAmmon__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmoss_interfaces__msg__ExchangeAmmon__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmoss_interfaces__msg__ExchangeAmmon__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
