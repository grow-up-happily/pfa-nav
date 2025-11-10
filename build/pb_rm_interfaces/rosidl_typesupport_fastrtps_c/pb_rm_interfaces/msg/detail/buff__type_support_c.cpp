// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from pb_rm_interfaces:msg/Buff.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/buff__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "pb_rm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pb_rm_interfaces/msg/detail/buff__struct.h"
#include "pb_rm_interfaces/msg/detail/buff__functions.h"
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


// forward declare type support functions


using _Buff__ros_msg_type = pb_rm_interfaces__msg__Buff;

static bool _Buff__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Buff__ros_msg_type * ros_message = static_cast<const _Buff__ros_msg_type *>(untyped_ros_message);
  // Field name: recovery_buff
  {
    cdr << ros_message->recovery_buff;
  }

  // Field name: cooling_buff
  {
    cdr << ros_message->cooling_buff;
  }

  // Field name: defence_buff
  {
    cdr << ros_message->defence_buff;
  }

  // Field name: vulnerability_buff
  {
    cdr << ros_message->vulnerability_buff;
  }

  // Field name: attack_buff
  {
    cdr << ros_message->attack_buff;
  }

  // Field name: remaining_energy
  {
    cdr << ros_message->remaining_energy;
  }

  return true;
}

static bool _Buff__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Buff__ros_msg_type * ros_message = static_cast<_Buff__ros_msg_type *>(untyped_ros_message);
  // Field name: recovery_buff
  {
    cdr >> ros_message->recovery_buff;
  }

  // Field name: cooling_buff
  {
    cdr >> ros_message->cooling_buff;
  }

  // Field name: defence_buff
  {
    cdr >> ros_message->defence_buff;
  }

  // Field name: vulnerability_buff
  {
    cdr >> ros_message->vulnerability_buff;
  }

  // Field name: attack_buff
  {
    cdr >> ros_message->attack_buff;
  }

  // Field name: remaining_energy
  {
    cdr >> ros_message->remaining_energy;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t get_serialized_size_pb_rm_interfaces__msg__Buff(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Buff__ros_msg_type * ros_message = static_cast<const _Buff__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name recovery_buff
  {
    size_t item_size = sizeof(ros_message->recovery_buff);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cooling_buff
  {
    size_t item_size = sizeof(ros_message->cooling_buff);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name defence_buff
  {
    size_t item_size = sizeof(ros_message->defence_buff);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vulnerability_buff
  {
    size_t item_size = sizeof(ros_message->vulnerability_buff);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name attack_buff
  {
    size_t item_size = sizeof(ros_message->attack_buff);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name remaining_energy
  {
    size_t item_size = sizeof(ros_message->remaining_energy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Buff__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_pb_rm_interfaces__msg__Buff(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t max_serialized_size_pb_rm_interfaces__msg__Buff(
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

  // member: recovery_buff
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cooling_buff
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: defence_buff
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: vulnerability_buff
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: attack_buff
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: remaining_energy
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
    using DataType = pb_rm_interfaces__msg__Buff;
    is_plain =
      (
      offsetof(DataType, remaining_energy) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Buff__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_pb_rm_interfaces__msg__Buff(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Buff = {
  "pb_rm_interfaces::msg",
  "Buff",
  _Buff__cdr_serialize,
  _Buff__cdr_deserialize,
  _Buff__get_serialized_size,
  _Buff__max_serialized_size
};

static rosidl_message_type_support_t _Buff__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Buff,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pb_rm_interfaces, msg, Buff)() {
  return &_Buff__type_support;
}

#if defined(__cplusplus)
}
#endif
