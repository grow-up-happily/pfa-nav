// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rmoss_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/msg/detail/rfid_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rmoss_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rmoss_interfaces/msg/detail/rfid_status__struct.h"
#include "rmoss_interfaces/msg/detail/rfid_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // robot_name
#include "rosidl_runtime_c/string_functions.h"  // robot_name

// forward declare type support functions


using _RfidStatus__ros_msg_type = rmoss_interfaces__msg__RfidStatus;

static bool _RfidStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RfidStatus__ros_msg_type * ros_message = static_cast<const _RfidStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_name
  {
    const rosidl_runtime_c__String * str = &ros_message->robot_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: supplier_area_is_triggered
  {
    cdr << (ros_message->supplier_area_is_triggered ? true : false);
  }

  // Field name: center_area_is_triggered
  {
    cdr << (ros_message->center_area_is_triggered ? true : false);
  }

  return true;
}

static bool _RfidStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RfidStatus__ros_msg_type * ros_message = static_cast<_RfidStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->robot_name.data) {
      rosidl_runtime_c__String__init(&ros_message->robot_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->robot_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'robot_name'\n");
      return false;
    }
  }

  // Field name: supplier_area_is_triggered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->supplier_area_is_triggered = tmp ? true : false;
  }

  // Field name: center_area_is_triggered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->center_area_is_triggered = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rmoss_interfaces
size_t get_serialized_size_rmoss_interfaces__msg__RfidStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RfidStatus__ros_msg_type * ros_message = static_cast<const _RfidStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name robot_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->robot_name.size + 1);
  // field.name supplier_area_is_triggered
  {
    size_t item_size = sizeof(ros_message->supplier_area_is_triggered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_area_is_triggered
  {
    size_t item_size = sizeof(ros_message->center_area_is_triggered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RfidStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rmoss_interfaces__msg__RfidStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rmoss_interfaces
size_t max_serialized_size_rmoss_interfaces__msg__RfidStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: robot_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: supplier_area_is_triggered
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: center_area_is_triggered
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rmoss_interfaces__msg__RfidStatus;
    is_plain =
      (
      offsetof(DataType, center_area_is_triggered) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RfidStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rmoss_interfaces__msg__RfidStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RfidStatus = {
  "rmoss_interfaces::msg",
  "RfidStatus",
  _RfidStatus__cdr_serialize,
  _RfidStatus__cdr_deserialize,
  _RfidStatus__get_serialized_size,
  _RfidStatus__max_serialized_size
};

static rosidl_message_type_support_t _RfidStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RfidStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rmoss_interfaces, msg, RfidStatus)() {
  return &_RfidStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
