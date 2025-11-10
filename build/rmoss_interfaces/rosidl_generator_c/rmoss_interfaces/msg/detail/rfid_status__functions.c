// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmoss_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/msg/detail/rfid_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_name`
#include "rosidl_runtime_c/string_functions.h"

bool
rmoss_interfaces__msg__RfidStatus__init(rmoss_interfaces__msg__RfidStatus * msg)
{
  if (!msg) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__init(&msg->robot_name)) {
    rmoss_interfaces__msg__RfidStatus__fini(msg);
    return false;
  }
  // supplier_area_is_triggered
  // center_area_is_triggered
  return true;
}

void
rmoss_interfaces__msg__RfidStatus__fini(rmoss_interfaces__msg__RfidStatus * msg)
{
  if (!msg) {
    return;
  }
  // robot_name
  rosidl_runtime_c__String__fini(&msg->robot_name);
  // supplier_area_is_triggered
  // center_area_is_triggered
}

bool
rmoss_interfaces__msg__RfidStatus__are_equal(const rmoss_interfaces__msg__RfidStatus * lhs, const rmoss_interfaces__msg__RfidStatus * rhs)
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
  // supplier_area_is_triggered
  if (lhs->supplier_area_is_triggered != rhs->supplier_area_is_triggered) {
    return false;
  }
  // center_area_is_triggered
  if (lhs->center_area_is_triggered != rhs->center_area_is_triggered) {
    return false;
  }
  return true;
}

bool
rmoss_interfaces__msg__RfidStatus__copy(
  const rmoss_interfaces__msg__RfidStatus * input,
  rmoss_interfaces__msg__RfidStatus * output)
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
  // supplier_area_is_triggered
  output->supplier_area_is_triggered = input->supplier_area_is_triggered;
  // center_area_is_triggered
  output->center_area_is_triggered = input->center_area_is_triggered;
  return true;
}

rmoss_interfaces__msg__RfidStatus *
rmoss_interfaces__msg__RfidStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__RfidStatus * msg = (rmoss_interfaces__msg__RfidStatus *)allocator.allocate(sizeof(rmoss_interfaces__msg__RfidStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmoss_interfaces__msg__RfidStatus));
  bool success = rmoss_interfaces__msg__RfidStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmoss_interfaces__msg__RfidStatus__destroy(rmoss_interfaces__msg__RfidStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmoss_interfaces__msg__RfidStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmoss_interfaces__msg__RfidStatus__Sequence__init(rmoss_interfaces__msg__RfidStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__RfidStatus * data = NULL;

  if (size) {
    data = (rmoss_interfaces__msg__RfidStatus *)allocator.zero_allocate(size, sizeof(rmoss_interfaces__msg__RfidStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmoss_interfaces__msg__RfidStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmoss_interfaces__msg__RfidStatus__fini(&data[i - 1]);
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
rmoss_interfaces__msg__RfidStatus__Sequence__fini(rmoss_interfaces__msg__RfidStatus__Sequence * array)
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
      rmoss_interfaces__msg__RfidStatus__fini(&array->data[i]);
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

rmoss_interfaces__msg__RfidStatus__Sequence *
rmoss_interfaces__msg__RfidStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__RfidStatus__Sequence * array = (rmoss_interfaces__msg__RfidStatus__Sequence *)allocator.allocate(sizeof(rmoss_interfaces__msg__RfidStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmoss_interfaces__msg__RfidStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmoss_interfaces__msg__RfidStatus__Sequence__destroy(rmoss_interfaces__msg__RfidStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmoss_interfaces__msg__RfidStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmoss_interfaces__msg__RfidStatus__Sequence__are_equal(const rmoss_interfaces__msg__RfidStatus__Sequence * lhs, const rmoss_interfaces__msg__RfidStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmoss_interfaces__msg__RfidStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmoss_interfaces__msg__RfidStatus__Sequence__copy(
  const rmoss_interfaces__msg__RfidStatus__Sequence * input,
  rmoss_interfaces__msg__RfidStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmoss_interfaces__msg__RfidStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmoss_interfaces__msg__RfidStatus * data =
      (rmoss_interfaces__msg__RfidStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmoss_interfaces__msg__RfidStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmoss_interfaces__msg__RfidStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmoss_interfaces__msg__RfidStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
