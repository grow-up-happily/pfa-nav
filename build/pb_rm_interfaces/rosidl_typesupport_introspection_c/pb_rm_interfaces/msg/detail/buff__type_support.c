// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pb_rm_interfaces:msg/Buff.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pb_rm_interfaces/msg/detail/buff__rosidl_typesupport_introspection_c.h"
#include "pb_rm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pb_rm_interfaces/msg/detail/buff__functions.h"
#include "pb_rm_interfaces/msg/detail/buff__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pb_rm_interfaces__msg__Buff__init(message_memory);
}

void pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_fini_function(void * message_memory)
{
  pb_rm_interfaces__msg__Buff__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_message_member_array[6] = {
  {
    "recovery_buff",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Buff, recovery_buff),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cooling_buff",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Buff, cooling_buff),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "defence_buff",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Buff, defence_buff),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vulnerability_buff",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Buff, vulnerability_buff),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "attack_buff",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Buff, attack_buff),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "remaining_energy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Buff, remaining_energy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_message_members = {
  "pb_rm_interfaces__msg",  // message namespace
  "Buff",  // message name
  6,  // number of fields
  sizeof(pb_rm_interfaces__msg__Buff),
  pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_message_member_array,  // message members
  pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_init_function,  // function to initialize message memory (memory has to be allocated)
  pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_message_type_support_handle = {
  0,
  &pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pb_rm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pb_rm_interfaces, msg, Buff)() {
  if (!pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_message_type_support_handle.typesupport_identifier) {
    pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pb_rm_interfaces__msg__Buff__rosidl_typesupport_introspection_c__Buff_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
