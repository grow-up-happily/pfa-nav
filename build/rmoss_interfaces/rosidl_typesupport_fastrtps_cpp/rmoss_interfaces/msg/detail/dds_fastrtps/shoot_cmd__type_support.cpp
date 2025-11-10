// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rmoss_interfaces:msg/ShootCmd.idl
// generated code does not contain a copyright notice
#include "rmoss_interfaces/msg/detail/shoot_cmd__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rmoss_interfaces/msg/detail/shoot_cmd__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rmoss_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmoss_interfaces
cdr_serialize(
  const rmoss_interfaces::msg::ShootCmd & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: tid
  cdr << ros_message.tid;
  // Member: type
  cdr << ros_message.type;
  // Member: projectile_num
  cdr << ros_message.projectile_num;
  // Member: projectile_velocity
  cdr << ros_message.projectile_velocity;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmoss_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rmoss_interfaces::msg::ShootCmd & ros_message)
{
  // Member: tid
  cdr >> ros_message.tid;

  // Member: type
  cdr >> ros_message.type;

  // Member: projectile_num
  cdr >> ros_message.projectile_num;

  // Member: projectile_velocity
  cdr >> ros_message.projectile_velocity;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmoss_interfaces
get_serialized_size(
  const rmoss_interfaces::msg::ShootCmd & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: tid
  {
    size_t item_size = sizeof(ros_message.tid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: type
  {
    size_t item_size = sizeof(ros_message.type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: projectile_num
  {
    size_t item_size = sizeof(ros_message.projectile_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: projectile_velocity
  {
    size_t item_size = sizeof(ros_message.projectile_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rmoss_interfaces
max_serialized_size_ShootCmd(
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


  // Member: tid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: projectile_num
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: projectile_velocity
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rmoss_interfaces::msg::ShootCmd;
    is_plain =
      (
      offsetof(DataType, projectile_velocity) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ShootCmd__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rmoss_interfaces::msg::ShootCmd *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ShootCmd__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rmoss_interfaces::msg::ShootCmd *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ShootCmd__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rmoss_interfaces::msg::ShootCmd *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ShootCmd__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ShootCmd(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ShootCmd__callbacks = {
  "rmoss_interfaces::msg",
  "ShootCmd",
  _ShootCmd__cdr_serialize,
  _ShootCmd__cdr_deserialize,
  _ShootCmd__get_serialized_size,
  _ShootCmd__max_serialized_size
};

static rosidl_message_type_support_t _ShootCmd__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ShootCmd__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rmoss_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rmoss_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<rmoss_interfaces::msg::ShootCmd>()
{
  return &rmoss_interfaces::msg::typesupport_fastrtps_cpp::_ShootCmd__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rmoss_interfaces, msg, ShootCmd)() {
  return &rmoss_interfaces::msg::typesupport_fastrtps_cpp::_ShootCmd__handle;
}

#ifdef __cplusplus
}
#endif
