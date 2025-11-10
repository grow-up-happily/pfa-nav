// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from pb_rm_interfaces:msg/Models.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/models__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "pb_rm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pb_rm_interfaces/msg/detail/models__struct.h"
#include "pb_rm_interfaces/msg/detail/models__functions.h"
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

#include "rosidl_runtime_c/string.h"  // arm, chassis, custom_controller, gimbal, shoot
#include "rosidl_runtime_c/string_functions.h"  // arm, chassis, custom_controller, gimbal, shoot

// forward declare type support functions


using _Models__ros_msg_type = pb_rm_interfaces__msg__Models;

static bool _Models__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Models__ros_msg_type * ros_message = static_cast<const _Models__ros_msg_type *>(untyped_ros_message);
  // Field name: chassis
  {
    const rosidl_runtime_c__String * str = &ros_message->chassis;
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

  // Field name: gimbal
  {
    const rosidl_runtime_c__String * str = &ros_message->gimbal;
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

  // Field name: shoot
  {
    const rosidl_runtime_c__String * str = &ros_message->shoot;
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

  // Field name: arm
  {
    const rosidl_runtime_c__String * str = &ros_message->arm;
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

  // Field name: custom_controller
  {
    const rosidl_runtime_c__String * str = &ros_message->custom_controller;
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

  return true;
}

static bool _Models__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Models__ros_msg_type * ros_message = static_cast<_Models__ros_msg_type *>(untyped_ros_message);
  // Field name: chassis
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->chassis.data) {
      rosidl_runtime_c__String__init(&ros_message->chassis);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->chassis,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'chassis'\n");
      return false;
    }
  }

  // Field name: gimbal
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->gimbal.data) {
      rosidl_runtime_c__String__init(&ros_message->gimbal);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->gimbal,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'gimbal'\n");
      return false;
    }
  }

  // Field name: shoot
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->shoot.data) {
      rosidl_runtime_c__String__init(&ros_message->shoot);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->shoot,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'shoot'\n");
      return false;
    }
  }

  // Field name: arm
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->arm.data) {
      rosidl_runtime_c__String__init(&ros_message->arm);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->arm,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'arm'\n");
      return false;
    }
  }

  // Field name: custom_controller
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->custom_controller.data) {
      rosidl_runtime_c__String__init(&ros_message->custom_controller);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->custom_controller,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'custom_controller'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t get_serialized_size_pb_rm_interfaces__msg__Models(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Models__ros_msg_type * ros_message = static_cast<const _Models__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name chassis
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->chassis.size + 1);
  // field.name gimbal
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->gimbal.size + 1);
  // field.name shoot
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->shoot.size + 1);
  // field.name arm
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->arm.size + 1);
  // field.name custom_controller
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->custom_controller.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Models__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_pb_rm_interfaces__msg__Models(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t max_serialized_size_pb_rm_interfaces__msg__Models(
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

  // member: chassis
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
  // member: gimbal
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
  // member: shoot
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
  // member: arm
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
  // member: custom_controller
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

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pb_rm_interfaces__msg__Models;
    is_plain =
      (
      offsetof(DataType, custom_controller) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Models__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_pb_rm_interfaces__msg__Models(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Models = {
  "pb_rm_interfaces::msg",
  "Models",
  _Models__cdr_serialize,
  _Models__cdr_deserialize,
  _Models__get_serialized_size,
  _Models__max_serialized_size
};

static rosidl_message_type_support_t _Models__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Models,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pb_rm_interfaces, msg, Models)() {
  return &_Models__type_support;
}

#if defined(__cplusplus)
}
#endif
