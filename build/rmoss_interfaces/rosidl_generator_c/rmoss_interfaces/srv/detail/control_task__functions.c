// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmoss_interfaces:srv/ControlTask.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/srv/detail/control_task__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
rmoss_interfaces__srv__ControlTask_Request__init(rmoss_interfaces__srv__ControlTask_Request * msg)
{
  if (!msg) {
    return false;
  }
  // cmd
  return true;
}

void
rmoss_interfaces__srv__ControlTask_Request__fini(rmoss_interfaces__srv__ControlTask_Request * msg)
{
  if (!msg) {
    return;
  }
  // cmd
}

bool
rmoss_interfaces__srv__ControlTask_Request__are_equal(const rmoss_interfaces__srv__ControlTask_Request * lhs, const rmoss_interfaces__srv__ControlTask_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd
  if (lhs->cmd != rhs->cmd) {
    return false;
  }
  return true;
}

bool
rmoss_interfaces__srv__ControlTask_Request__copy(
  const rmoss_interfaces__srv__ControlTask_Request * input,
  rmoss_interfaces__srv__ControlTask_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd
  output->cmd = input->cmd;
  return true;
}

rmoss_interfaces__srv__ControlTask_Request *
rmoss_interfaces__srv__ControlTask_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__srv__ControlTask_Request * msg = (rmoss_interfaces__srv__ControlTask_Request *)allocator.allocate(sizeof(rmoss_interfaces__srv__ControlTask_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmoss_interfaces__srv__ControlTask_Request));
  bool success = rmoss_interfaces__srv__ControlTask_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmoss_interfaces__srv__ControlTask_Request__destroy(rmoss_interfaces__srv__ControlTask_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmoss_interfaces__srv__ControlTask_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmoss_interfaces__srv__ControlTask_Request__Sequence__init(rmoss_interfaces__srv__ControlTask_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__srv__ControlTask_Request * data = NULL;

  if (size) {
    data = (rmoss_interfaces__srv__ControlTask_Request *)allocator.zero_allocate(size, sizeof(rmoss_interfaces__srv__ControlTask_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmoss_interfaces__srv__ControlTask_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmoss_interfaces__srv__ControlTask_Request__fini(&data[i - 1]);
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
rmoss_interfaces__srv__ControlTask_Request__Sequence__fini(rmoss_interfaces__srv__ControlTask_Request__Sequence * array)
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
      rmoss_interfaces__srv__ControlTask_Request__fini(&array->data[i]);
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

rmoss_interfaces__srv__ControlTask_Request__Sequence *
rmoss_interfaces__srv__ControlTask_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__srv__ControlTask_Request__Sequence * array = (rmoss_interfaces__srv__ControlTask_Request__Sequence *)allocator.allocate(sizeof(rmoss_interfaces__srv__ControlTask_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmoss_interfaces__srv__ControlTask_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmoss_interfaces__srv__ControlTask_Request__Sequence__destroy(rmoss_interfaces__srv__ControlTask_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmoss_interfaces__srv__ControlTask_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmoss_interfaces__srv__ControlTask_Request__Sequence__are_equal(const rmoss_interfaces__srv__ControlTask_Request__Sequence * lhs, const rmoss_interfaces__srv__ControlTask_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmoss_interfaces__srv__ControlTask_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmoss_interfaces__srv__ControlTask_Request__Sequence__copy(
  const rmoss_interfaces__srv__ControlTask_Request__Sequence * input,
  rmoss_interfaces__srv__ControlTask_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmoss_interfaces__srv__ControlTask_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmoss_interfaces__srv__ControlTask_Request * data =
      (rmoss_interfaces__srv__ControlTask_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmoss_interfaces__srv__ControlTask_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmoss_interfaces__srv__ControlTask_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmoss_interfaces__srv__ControlTask_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
rmoss_interfaces__srv__ControlTask_Response__init(rmoss_interfaces__srv__ControlTask_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
rmoss_interfaces__srv__ControlTask_Response__fini(rmoss_interfaces__srv__ControlTask_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
rmoss_interfaces__srv__ControlTask_Response__are_equal(const rmoss_interfaces__srv__ControlTask_Response * lhs, const rmoss_interfaces__srv__ControlTask_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
rmoss_interfaces__srv__ControlTask_Response__copy(
  const rmoss_interfaces__srv__ControlTask_Response * input,
  rmoss_interfaces__srv__ControlTask_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

rmoss_interfaces__srv__ControlTask_Response *
rmoss_interfaces__srv__ControlTask_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__srv__ControlTask_Response * msg = (rmoss_interfaces__srv__ControlTask_Response *)allocator.allocate(sizeof(rmoss_interfaces__srv__ControlTask_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmoss_interfaces__srv__ControlTask_Response));
  bool success = rmoss_interfaces__srv__ControlTask_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmoss_interfaces__srv__ControlTask_Response__destroy(rmoss_interfaces__srv__ControlTask_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmoss_interfaces__srv__ControlTask_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmoss_interfaces__srv__ControlTask_Response__Sequence__init(rmoss_interfaces__srv__ControlTask_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__srv__ControlTask_Response * data = NULL;

  if (size) {
    data = (rmoss_interfaces__srv__ControlTask_Response *)allocator.zero_allocate(size, sizeof(rmoss_interfaces__srv__ControlTask_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmoss_interfaces__srv__ControlTask_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmoss_interfaces__srv__ControlTask_Response__fini(&data[i - 1]);
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
rmoss_interfaces__srv__ControlTask_Response__Sequence__fini(rmoss_interfaces__srv__ControlTask_Response__Sequence * array)
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
      rmoss_interfaces__srv__ControlTask_Response__fini(&array->data[i]);
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

rmoss_interfaces__srv__ControlTask_Response__Sequence *
rmoss_interfaces__srv__ControlTask_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__srv__ControlTask_Response__Sequence * array = (rmoss_interfaces__srv__ControlTask_Response__Sequence *)allocator.allocate(sizeof(rmoss_interfaces__srv__ControlTask_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmoss_interfaces__srv__ControlTask_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmoss_interfaces__srv__ControlTask_Response__Sequence__destroy(rmoss_interfaces__srv__ControlTask_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmoss_interfaces__srv__ControlTask_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmoss_interfaces__srv__ControlTask_Response__Sequence__are_equal(const rmoss_interfaces__srv__ControlTask_Response__Sequence * lhs, const rmoss_interfaces__srv__ControlTask_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmoss_interfaces__srv__ControlTask_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmoss_interfaces__srv__ControlTask_Response__Sequence__copy(
  const rmoss_interfaces__srv__ControlTask_Response__Sequence * input,
  rmoss_interfaces__srv__ControlTask_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmoss_interfaces__srv__ControlTask_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmoss_interfaces__srv__ControlTask_Response * data =
      (rmoss_interfaces__srv__ControlTask_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmoss_interfaces__srv__ControlTask_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmoss_interfaces__srv__ControlTask_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmoss_interfaces__srv__ControlTask_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
