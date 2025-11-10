// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pb_rm_interfaces:msg/EventData.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/event_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
pb_rm_interfaces__msg__EventData__init(pb_rm_interfaces__msg__EventData * msg)
{
  if (!msg) {
    return false;
  }
  // non_overlapping_supply_zone
  // overlapping_supply_zone
  // supply_zone
  // small_energy
  // big_energy
  // central_highland
  // trapezoidal_highland
  // center_gain_zone
  return true;
}

void
pb_rm_interfaces__msg__EventData__fini(pb_rm_interfaces__msg__EventData * msg)
{
  if (!msg) {
    return;
  }
  // non_overlapping_supply_zone
  // overlapping_supply_zone
  // supply_zone
  // small_energy
  // big_energy
  // central_highland
  // trapezoidal_highland
  // center_gain_zone
}

bool
pb_rm_interfaces__msg__EventData__are_equal(const pb_rm_interfaces__msg__EventData * lhs, const pb_rm_interfaces__msg__EventData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // non_overlapping_supply_zone
  if (lhs->non_overlapping_supply_zone != rhs->non_overlapping_supply_zone) {
    return false;
  }
  // overlapping_supply_zone
  if (lhs->overlapping_supply_zone != rhs->overlapping_supply_zone) {
    return false;
  }
  // supply_zone
  if (lhs->supply_zone != rhs->supply_zone) {
    return false;
  }
  // small_energy
  if (lhs->small_energy != rhs->small_energy) {
    return false;
  }
  // big_energy
  if (lhs->big_energy != rhs->big_energy) {
    return false;
  }
  // central_highland
  if (lhs->central_highland != rhs->central_highland) {
    return false;
  }
  // trapezoidal_highland
  if (lhs->trapezoidal_highland != rhs->trapezoidal_highland) {
    return false;
  }
  // center_gain_zone
  if (lhs->center_gain_zone != rhs->center_gain_zone) {
    return false;
  }
  return true;
}

bool
pb_rm_interfaces__msg__EventData__copy(
  const pb_rm_interfaces__msg__EventData * input,
  pb_rm_interfaces__msg__EventData * output)
{
  if (!input || !output) {
    return false;
  }
  // non_overlapping_supply_zone
  output->non_overlapping_supply_zone = input->non_overlapping_supply_zone;
  // overlapping_supply_zone
  output->overlapping_supply_zone = input->overlapping_supply_zone;
  // supply_zone
  output->supply_zone = input->supply_zone;
  // small_energy
  output->small_energy = input->small_energy;
  // big_energy
  output->big_energy = input->big_energy;
  // central_highland
  output->central_highland = input->central_highland;
  // trapezoidal_highland
  output->trapezoidal_highland = input->trapezoidal_highland;
  // center_gain_zone
  output->center_gain_zone = input->center_gain_zone;
  return true;
}

pb_rm_interfaces__msg__EventData *
pb_rm_interfaces__msg__EventData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__EventData * msg = (pb_rm_interfaces__msg__EventData *)allocator.allocate(sizeof(pb_rm_interfaces__msg__EventData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pb_rm_interfaces__msg__EventData));
  bool success = pb_rm_interfaces__msg__EventData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pb_rm_interfaces__msg__EventData__destroy(pb_rm_interfaces__msg__EventData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pb_rm_interfaces__msg__EventData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pb_rm_interfaces__msg__EventData__Sequence__init(pb_rm_interfaces__msg__EventData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__EventData * data = NULL;

  if (size) {
    data = (pb_rm_interfaces__msg__EventData *)allocator.zero_allocate(size, sizeof(pb_rm_interfaces__msg__EventData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pb_rm_interfaces__msg__EventData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pb_rm_interfaces__msg__EventData__fini(&data[i - 1]);
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
pb_rm_interfaces__msg__EventData__Sequence__fini(pb_rm_interfaces__msg__EventData__Sequence * array)
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
      pb_rm_interfaces__msg__EventData__fini(&array->data[i]);
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

pb_rm_interfaces__msg__EventData__Sequence *
pb_rm_interfaces__msg__EventData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__EventData__Sequence * array = (pb_rm_interfaces__msg__EventData__Sequence *)allocator.allocate(sizeof(pb_rm_interfaces__msg__EventData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pb_rm_interfaces__msg__EventData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pb_rm_interfaces__msg__EventData__Sequence__destroy(pb_rm_interfaces__msg__EventData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pb_rm_interfaces__msg__EventData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pb_rm_interfaces__msg__EventData__Sequence__are_equal(const pb_rm_interfaces__msg__EventData__Sequence * lhs, const pb_rm_interfaces__msg__EventData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pb_rm_interfaces__msg__EventData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pb_rm_interfaces__msg__EventData__Sequence__copy(
  const pb_rm_interfaces__msg__EventData__Sequence * input,
  pb_rm_interfaces__msg__EventData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pb_rm_interfaces__msg__EventData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pb_rm_interfaces__msg__EventData * data =
      (pb_rm_interfaces__msg__EventData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pb_rm_interfaces__msg__EventData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pb_rm_interfaces__msg__EventData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pb_rm_interfaces__msg__EventData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
