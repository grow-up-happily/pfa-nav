// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from pb_rm_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/robot_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "pb_rm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pb_rm_interfaces/msg/detail/robot_status__struct.h"
#include "pb_rm_interfaces/msg/detail/robot_status__functions.h"
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

#include "geometry_msgs/msg/detail/pose__functions.h"  // robot_pos

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pb_rm_interfaces
size_t get_serialized_size_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pb_rm_interfaces
size_t max_serialized_size_geometry_msgs__msg__Pose(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_pb_rm_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose)();


using _RobotStatus__ros_msg_type = pb_rm_interfaces__msg__RobotStatus;

static bool _RobotStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotStatus__ros_msg_type * ros_message = static_cast<const _RobotStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_id
  {
    cdr << ros_message->robot_id;
  }

  // Field name: robot_level
  {
    cdr << ros_message->robot_level;
  }

  // Field name: current_hp
  {
    cdr << ros_message->current_hp;
  }

  // Field name: maximum_hp
  {
    cdr << ros_message->maximum_hp;
  }

  // Field name: shooter_barrel_cooling_value
  {
    cdr << ros_message->shooter_barrel_cooling_value;
  }

  // Field name: shooter_barrel_heat_limit
  {
    cdr << ros_message->shooter_barrel_heat_limit;
  }

  // Field name: shooter_17mm_1_barrel_heat
  {
    cdr << ros_message->shooter_17mm_1_barrel_heat;
  }

  // Field name: robot_pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->robot_pos, cdr))
    {
      return false;
    }
  }

  // Field name: armor_id
  {
    cdr << ros_message->armor_id;
  }

  // Field name: hp_deduction_reason
  {
    cdr << ros_message->hp_deduction_reason;
  }

  // Field name: projectile_allowance_17mm
  {
    cdr << ros_message->projectile_allowance_17mm;
  }

  // Field name: remaining_gold_coin
  {
    cdr << ros_message->remaining_gold_coin;
  }

  // Field name: is_hp_deduced
  {
    cdr << (ros_message->is_hp_deduced ? true : false);
  }

  return true;
}

static bool _RobotStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotStatus__ros_msg_type * ros_message = static_cast<_RobotStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_id
  {
    cdr >> ros_message->robot_id;
  }

  // Field name: robot_level
  {
    cdr >> ros_message->robot_level;
  }

  // Field name: current_hp
  {
    cdr >> ros_message->current_hp;
  }

  // Field name: maximum_hp
  {
    cdr >> ros_message->maximum_hp;
  }

  // Field name: shooter_barrel_cooling_value
  {
    cdr >> ros_message->shooter_barrel_cooling_value;
  }

  // Field name: shooter_barrel_heat_limit
  {
    cdr >> ros_message->shooter_barrel_heat_limit;
  }

  // Field name: shooter_17mm_1_barrel_heat
  {
    cdr >> ros_message->shooter_17mm_1_barrel_heat;
  }

  // Field name: robot_pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->robot_pos))
    {
      return false;
    }
  }

  // Field name: armor_id
  {
    cdr >> ros_message->armor_id;
  }

  // Field name: hp_deduction_reason
  {
    cdr >> ros_message->hp_deduction_reason;
  }

  // Field name: projectile_allowance_17mm
  {
    cdr >> ros_message->projectile_allowance_17mm;
  }

  // Field name: remaining_gold_coin
  {
    cdr >> ros_message->remaining_gold_coin;
  }

  // Field name: is_hp_deduced
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_hp_deduced = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t get_serialized_size_pb_rm_interfaces__msg__RobotStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotStatus__ros_msg_type * ros_message = static_cast<const _RobotStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name robot_id
  {
    size_t item_size = sizeof(ros_message->robot_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_level
  {
    size_t item_size = sizeof(ros_message->robot_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_hp
  {
    size_t item_size = sizeof(ros_message->current_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name maximum_hp
  {
    size_t item_size = sizeof(ros_message->maximum_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name shooter_barrel_cooling_value
  {
    size_t item_size = sizeof(ros_message->shooter_barrel_cooling_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name shooter_barrel_heat_limit
  {
    size_t item_size = sizeof(ros_message->shooter_barrel_heat_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name shooter_17mm_1_barrel_heat
  {
    size_t item_size = sizeof(ros_message->shooter_17mm_1_barrel_heat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_pos

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->robot_pos), current_alignment);
  // field.name armor_id
  {
    size_t item_size = sizeof(ros_message->armor_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hp_deduction_reason
  {
    size_t item_size = sizeof(ros_message->hp_deduction_reason);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name projectile_allowance_17mm
  {
    size_t item_size = sizeof(ros_message->projectile_allowance_17mm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name remaining_gold_coin
  {
    size_t item_size = sizeof(ros_message->remaining_gold_coin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_hp_deduced
  {
    size_t item_size = sizeof(ros_message->is_hp_deduced);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RobotStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_pb_rm_interfaces__msg__RobotStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t max_serialized_size_pb_rm_interfaces__msg__RobotStatus(
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

  // member: robot_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: robot_level
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: current_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: maximum_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: shooter_barrel_cooling_value
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: shooter_barrel_heat_limit
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: shooter_17mm_1_barrel_heat
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: robot_pos
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: armor_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hp_deduction_reason
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: projectile_allowance_17mm
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: remaining_gold_coin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: is_hp_deduced
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
    using DataType = pb_rm_interfaces__msg__RobotStatus;
    is_plain =
      (
      offsetof(DataType, is_hp_deduced) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RobotStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_pb_rm_interfaces__msg__RobotStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RobotStatus = {
  "pb_rm_interfaces::msg",
  "RobotStatus",
  _RobotStatus__cdr_serialize,
  _RobotStatus__cdr_deserialize,
  _RobotStatus__get_serialized_size,
  _RobotStatus__max_serialized_size
};

static rosidl_message_type_support_t _RobotStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pb_rm_interfaces, msg, RobotStatus)() {
  return &_RobotStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
