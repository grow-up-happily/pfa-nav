// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rmoss_interfaces:msg/ShootCmd.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/msg/detail/shoot_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rmoss_interfaces__msg__ShootCmd__init(rmoss_interfaces__msg__ShootCmd * msg)
{
  if (!msg) {
    return false;
  }
  // tid
  // type
  // projectile_num
  // projectile_velocity
  msg->projectile_velocity = 0.0f;
  return true;
}

void
rmoss_interfaces__msg__ShootCmd__fini(rmoss_interfaces__msg__ShootCmd * msg)
{
  if (!msg) {
    return;
  }
  // tid
  // type
  // projectile_num
  // projectile_velocity
}

bool
rmoss_interfaces__msg__ShootCmd__are_equal(const rmoss_interfaces__msg__ShootCmd * lhs, const rmoss_interfaces__msg__ShootCmd * rhs)
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
  // projectile_num
  if (lhs->projectile_num != rhs->projectile_num) {
    return false;
  }
  // projectile_velocity
  if (lhs->projectile_velocity != rhs->projectile_velocity) {
    return false;
  }
  return true;
}

bool
rmoss_interfaces__msg__ShootCmd__copy(
  const rmoss_interfaces__msg__ShootCmd * input,
  rmoss_interfaces__msg__ShootCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // tid
  output->tid = input->tid;
  // type
  output->type = input->type;
  // projectile_num
  output->projectile_num = input->projectile_num;
  // projectile_velocity
  output->projectile_velocity = input->projectile_velocity;
  return true;
}

rmoss_interfaces__msg__ShootCmd *
rmoss_interfaces__msg__ShootCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__ShootCmd * msg = (rmoss_interfaces__msg__ShootCmd *)allocator.allocate(sizeof(rmoss_interfaces__msg__ShootCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rmoss_interfaces__msg__ShootCmd));
  bool success = rmoss_interfaces__msg__ShootCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rmoss_interfaces__msg__ShootCmd__destroy(rmoss_interfaces__msg__ShootCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rmoss_interfaces__msg__ShootCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rmoss_interfaces__msg__ShootCmd__Sequence__init(rmoss_interfaces__msg__ShootCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__ShootCmd * data = NULL;

  if (size) {
    data = (rmoss_interfaces__msg__ShootCmd *)allocator.zero_allocate(size, sizeof(rmoss_interfaces__msg__ShootCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rmoss_interfaces__msg__ShootCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rmoss_interfaces__msg__ShootCmd__fini(&data[i - 1]);
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
rmoss_interfaces__msg__ShootCmd__Sequence__fini(rmoss_interfaces__msg__ShootCmd__Sequence * array)
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
      rmoss_interfaces__msg__ShootCmd__fini(&array->data[i]);
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

rmoss_interfaces__msg__ShootCmd__Sequence *
rmoss_interfaces__msg__ShootCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rmoss_interfaces__msg__ShootCmd__Sequence * array = (rmoss_interfaces__msg__ShootCmd__Sequence *)allocator.allocate(sizeof(rmoss_interfaces__msg__ShootCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rmoss_interfaces__msg__ShootCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rmoss_interfaces__msg__ShootCmd__Sequence__destroy(rmoss_interfaces__msg__ShootCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rmoss_interfaces__msg__ShootCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rmoss_interfaces__msg__ShootCmd__Sequence__are_equal(const rmoss_interfaces__msg__ShootCmd__Sequence * lhs, const rmoss_interfaces__msg__ShootCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rmoss_interfaces__msg__ShootCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rmoss_interfaces__msg__ShootCmd__Sequence__copy(
  const rmoss_interfaces__msg__ShootCmd__Sequence * input,
  rmoss_interfaces__msg__ShootCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rmoss_interfaces__msg__ShootCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rmoss_interfaces__msg__ShootCmd * data =
      (rmoss_interfaces__msg__ShootCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rmoss_interfaces__msg__ShootCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rmoss_interfaces__msg__ShootCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rmoss_interfaces__msg__ShootCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
