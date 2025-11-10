// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wp_map_tools:srv/SaveWaypoints.idl
// generated code does not contain a copyright notice
#include "wp_map_tools/srv/detail/save_waypoints__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `filename`
#include "rosidl_runtime_c/string_functions.h"

bool
wp_map_tools__srv__SaveWaypoints_Request__init(wp_map_tools__srv__SaveWaypoints_Request * msg)
{
  if (!msg) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__init(&msg->filename)) {
    wp_map_tools__srv__SaveWaypoints_Request__fini(msg);
    return false;
  }
  return true;
}

void
wp_map_tools__srv__SaveWaypoints_Request__fini(wp_map_tools__srv__SaveWaypoints_Request * msg)
{
  if (!msg) {
    return;
  }
  // filename
  rosidl_runtime_c__String__fini(&msg->filename);
}

bool
wp_map_tools__srv__SaveWaypoints_Request__are_equal(const wp_map_tools__srv__SaveWaypoints_Request * lhs, const wp_map_tools__srv__SaveWaypoints_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->filename), &(rhs->filename)))
  {
    return false;
  }
  return true;
}

bool
wp_map_tools__srv__SaveWaypoints_Request__copy(
  const wp_map_tools__srv__SaveWaypoints_Request * input,
  wp_map_tools__srv__SaveWaypoints_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__copy(
      &(input->filename), &(output->filename)))
  {
    return false;
  }
  return true;
}

wp_map_tools__srv__SaveWaypoints_Request *
wp_map_tools__srv__SaveWaypoints_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wp_map_tools__srv__SaveWaypoints_Request * msg = (wp_map_tools__srv__SaveWaypoints_Request *)allocator.allocate(sizeof(wp_map_tools__srv__SaveWaypoints_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wp_map_tools__srv__SaveWaypoints_Request));
  bool success = wp_map_tools__srv__SaveWaypoints_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wp_map_tools__srv__SaveWaypoints_Request__destroy(wp_map_tools__srv__SaveWaypoints_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wp_map_tools__srv__SaveWaypoints_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wp_map_tools__srv__SaveWaypoints_Request__Sequence__init(wp_map_tools__srv__SaveWaypoints_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wp_map_tools__srv__SaveWaypoints_Request * data = NULL;

  if (size) {
    data = (wp_map_tools__srv__SaveWaypoints_Request *)allocator.zero_allocate(size, sizeof(wp_map_tools__srv__SaveWaypoints_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wp_map_tools__srv__SaveWaypoints_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wp_map_tools__srv__SaveWaypoints_Request__fini(&data[i - 1]);
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
wp_map_tools__srv__SaveWaypoints_Request__Sequence__fini(wp_map_tools__srv__SaveWaypoints_Request__Sequence * array)
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
      wp_map_tools__srv__SaveWaypoints_Request__fini(&array->data[i]);
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

wp_map_tools__srv__SaveWaypoints_Request__Sequence *
wp_map_tools__srv__SaveWaypoints_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wp_map_tools__srv__SaveWaypoints_Request__Sequence * array = (wp_map_tools__srv__SaveWaypoints_Request__Sequence *)allocator.allocate(sizeof(wp_map_tools__srv__SaveWaypoints_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wp_map_tools__srv__SaveWaypoints_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wp_map_tools__srv__SaveWaypoints_Request__Sequence__destroy(wp_map_tools__srv__SaveWaypoints_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wp_map_tools__srv__SaveWaypoints_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wp_map_tools__srv__SaveWaypoints_Request__Sequence__are_equal(const wp_map_tools__srv__SaveWaypoints_Request__Sequence * lhs, const wp_map_tools__srv__SaveWaypoints_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wp_map_tools__srv__SaveWaypoints_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wp_map_tools__srv__SaveWaypoints_Request__Sequence__copy(
  const wp_map_tools__srv__SaveWaypoints_Request__Sequence * input,
  wp_map_tools__srv__SaveWaypoints_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wp_map_tools__srv__SaveWaypoints_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wp_map_tools__srv__SaveWaypoints_Request * data =
      (wp_map_tools__srv__SaveWaypoints_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wp_map_tools__srv__SaveWaypoints_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wp_map_tools__srv__SaveWaypoints_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wp_map_tools__srv__SaveWaypoints_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
wp_map_tools__srv__SaveWaypoints_Response__init(wp_map_tools__srv__SaveWaypoints_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
wp_map_tools__srv__SaveWaypoints_Response__fini(wp_map_tools__srv__SaveWaypoints_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
wp_map_tools__srv__SaveWaypoints_Response__are_equal(const wp_map_tools__srv__SaveWaypoints_Response * lhs, const wp_map_tools__srv__SaveWaypoints_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
wp_map_tools__srv__SaveWaypoints_Response__copy(
  const wp_map_tools__srv__SaveWaypoints_Response * input,
  wp_map_tools__srv__SaveWaypoints_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

wp_map_tools__srv__SaveWaypoints_Response *
wp_map_tools__srv__SaveWaypoints_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wp_map_tools__srv__SaveWaypoints_Response * msg = (wp_map_tools__srv__SaveWaypoints_Response *)allocator.allocate(sizeof(wp_map_tools__srv__SaveWaypoints_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wp_map_tools__srv__SaveWaypoints_Response));
  bool success = wp_map_tools__srv__SaveWaypoints_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wp_map_tools__srv__SaveWaypoints_Response__destroy(wp_map_tools__srv__SaveWaypoints_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wp_map_tools__srv__SaveWaypoints_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wp_map_tools__srv__SaveWaypoints_Response__Sequence__init(wp_map_tools__srv__SaveWaypoints_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wp_map_tools__srv__SaveWaypoints_Response * data = NULL;

  if (size) {
    data = (wp_map_tools__srv__SaveWaypoints_Response *)allocator.zero_allocate(size, sizeof(wp_map_tools__srv__SaveWaypoints_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wp_map_tools__srv__SaveWaypoints_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wp_map_tools__srv__SaveWaypoints_Response__fini(&data[i - 1]);
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
wp_map_tools__srv__SaveWaypoints_Response__Sequence__fini(wp_map_tools__srv__SaveWaypoints_Response__Sequence * array)
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
      wp_map_tools__srv__SaveWaypoints_Response__fini(&array->data[i]);
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

wp_map_tools__srv__SaveWaypoints_Response__Sequence *
wp_map_tools__srv__SaveWaypoints_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wp_map_tools__srv__SaveWaypoints_Response__Sequence * array = (wp_map_tools__srv__SaveWaypoints_Response__Sequence *)allocator.allocate(sizeof(wp_map_tools__srv__SaveWaypoints_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wp_map_tools__srv__SaveWaypoints_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wp_map_tools__srv__SaveWaypoints_Response__Sequence__destroy(wp_map_tools__srv__SaveWaypoints_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wp_map_tools__srv__SaveWaypoints_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wp_map_tools__srv__SaveWaypoints_Response__Sequence__are_equal(const wp_map_tools__srv__SaveWaypoints_Response__Sequence * lhs, const wp_map_tools__srv__SaveWaypoints_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wp_map_tools__srv__SaveWaypoints_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wp_map_tools__srv__SaveWaypoints_Response__Sequence__copy(
  const wp_map_tools__srv__SaveWaypoints_Response__Sequence * input,
  wp_map_tools__srv__SaveWaypoints_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wp_map_tools__srv__SaveWaypoints_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wp_map_tools__srv__SaveWaypoints_Response * data =
      (wp_map_tools__srv__SaveWaypoints_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wp_map_tools__srv__SaveWaypoints_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wp_map_tools__srv__SaveWaypoints_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wp_map_tools__srv__SaveWaypoints_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
