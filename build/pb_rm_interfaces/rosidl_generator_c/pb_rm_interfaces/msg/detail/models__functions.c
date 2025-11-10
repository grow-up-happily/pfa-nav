// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pb_rm_interfaces:msg/Models.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/models__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `chassis`
// Member `gimbal`
// Member `shoot`
// Member `arm`
// Member `custom_controller`
#include "rosidl_runtime_c/string_functions.h"

bool
pb_rm_interfaces__msg__Models__init(pb_rm_interfaces__msg__Models * msg)
{
  if (!msg) {
    return false;
  }
  // chassis
  if (!rosidl_runtime_c__String__init(&msg->chassis)) {
    pb_rm_interfaces__msg__Models__fini(msg);
    return false;
  }
  // gimbal
  if (!rosidl_runtime_c__String__init(&msg->gimbal)) {
    pb_rm_interfaces__msg__Models__fini(msg);
    return false;
  }
  // shoot
  if (!rosidl_runtime_c__String__init(&msg->shoot)) {
    pb_rm_interfaces__msg__Models__fini(msg);
    return false;
  }
  // arm
  if (!rosidl_runtime_c__String__init(&msg->arm)) {
    pb_rm_interfaces__msg__Models__fini(msg);
    return false;
  }
  // custom_controller
  if (!rosidl_runtime_c__String__init(&msg->custom_controller)) {
    pb_rm_interfaces__msg__Models__fini(msg);
    return false;
  }
  return true;
}

void
pb_rm_interfaces__msg__Models__fini(pb_rm_interfaces__msg__Models * msg)
{
  if (!msg) {
    return;
  }
  // chassis
  rosidl_runtime_c__String__fini(&msg->chassis);
  // gimbal
  rosidl_runtime_c__String__fini(&msg->gimbal);
  // shoot
  rosidl_runtime_c__String__fini(&msg->shoot);
  // arm
  rosidl_runtime_c__String__fini(&msg->arm);
  // custom_controller
  rosidl_runtime_c__String__fini(&msg->custom_controller);
}

bool
pb_rm_interfaces__msg__Models__are_equal(const pb_rm_interfaces__msg__Models * lhs, const pb_rm_interfaces__msg__Models * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // chassis
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->chassis), &(rhs->chassis)))
  {
    return false;
  }
  // gimbal
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->gimbal), &(rhs->gimbal)))
  {
    return false;
  }
  // shoot
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->shoot), &(rhs->shoot)))
  {
    return false;
  }
  // arm
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->arm), &(rhs->arm)))
  {
    return false;
  }
  // custom_controller
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->custom_controller), &(rhs->custom_controller)))
  {
    return false;
  }
  return true;
}

bool
pb_rm_interfaces__msg__Models__copy(
  const pb_rm_interfaces__msg__Models * input,
  pb_rm_interfaces__msg__Models * output)
{
  if (!input || !output) {
    return false;
  }
  // chassis
  if (!rosidl_runtime_c__String__copy(
      &(input->chassis), &(output->chassis)))
  {
    return false;
  }
  // gimbal
  if (!rosidl_runtime_c__String__copy(
      &(input->gimbal), &(output->gimbal)))
  {
    return false;
  }
  // shoot
  if (!rosidl_runtime_c__String__copy(
      &(input->shoot), &(output->shoot)))
  {
    return false;
  }
  // arm
  if (!rosidl_runtime_c__String__copy(
      &(input->arm), &(output->arm)))
  {
    return false;
  }
  // custom_controller
  if (!rosidl_runtime_c__String__copy(
      &(input->custom_controller), &(output->custom_controller)))
  {
    return false;
  }
  return true;
}

pb_rm_interfaces__msg__Models *
pb_rm_interfaces__msg__Models__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__Models * msg = (pb_rm_interfaces__msg__Models *)allocator.allocate(sizeof(pb_rm_interfaces__msg__Models), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pb_rm_interfaces__msg__Models));
  bool success = pb_rm_interfaces__msg__Models__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pb_rm_interfaces__msg__Models__destroy(pb_rm_interfaces__msg__Models * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pb_rm_interfaces__msg__Models__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pb_rm_interfaces__msg__Models__Sequence__init(pb_rm_interfaces__msg__Models__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__Models * data = NULL;

  if (size) {
    data = (pb_rm_interfaces__msg__Models *)allocator.zero_allocate(size, sizeof(pb_rm_interfaces__msg__Models), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pb_rm_interfaces__msg__Models__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pb_rm_interfaces__msg__Models__fini(&data[i - 1]);
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
pb_rm_interfaces__msg__Models__Sequence__fini(pb_rm_interfaces__msg__Models__Sequence * array)
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
      pb_rm_interfaces__msg__Models__fini(&array->data[i]);
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

pb_rm_interfaces__msg__Models__Sequence *
pb_rm_interfaces__msg__Models__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__Models__Sequence * array = (pb_rm_interfaces__msg__Models__Sequence *)allocator.allocate(sizeof(pb_rm_interfaces__msg__Models__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pb_rm_interfaces__msg__Models__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pb_rm_interfaces__msg__Models__Sequence__destroy(pb_rm_interfaces__msg__Models__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pb_rm_interfaces__msg__Models__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pb_rm_interfaces__msg__Models__Sequence__are_equal(const pb_rm_interfaces__msg__Models__Sequence * lhs, const pb_rm_interfaces__msg__Models__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pb_rm_interfaces__msg__Models__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pb_rm_interfaces__msg__Models__Sequence__copy(
  const pb_rm_interfaces__msg__Models__Sequence * input,
  pb_rm_interfaces__msg__Models__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pb_rm_interfaces__msg__Models);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pb_rm_interfaces__msg__Models * data =
      (pb_rm_interfaces__msg__Models *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pb_rm_interfaces__msg__Models__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pb_rm_interfaces__msg__Models__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pb_rm_interfaces__msg__Models__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
