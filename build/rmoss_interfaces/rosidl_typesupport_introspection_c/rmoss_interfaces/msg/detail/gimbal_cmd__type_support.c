// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rmoss_interfaces:msg/GimbalCmd.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rmoss_interfaces/msg/detail/gimbal_cmd__rosidl_typesupport_introspection_c.h"
#include "rmoss_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rmoss_interfaces/msg/detail/gimbal_cmd__functions.h"
#include "rmoss_interfaces/msg/detail/gimbal_cmd__struct.h"


// Include directives for member types
// Member `position`
// Member `velocity`
#include "rmoss_interfaces/msg/gimbal.h"
// Member `position`
// Member `velocity`
#include "rmoss_interfaces/msg/detail/gimbal__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rmoss_interfaces__msg__GimbalCmd__init(message_memory);
}

void rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_fini_function(void * message_memory)
{
  rmoss_interfaces__msg__GimbalCmd__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_member_array[5] = {
  {
    "tid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rmoss_interfaces__msg__GimbalCmd, tid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rmoss_interfaces__msg__GimbalCmd, yaw_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rmoss_interfaces__msg__GimbalCmd, pitch_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rmoss_interfaces__msg__GimbalCmd, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rmoss_interfaces__msg__GimbalCmd, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_members = {
  "rmoss_interfaces__msg",  // message namespace
  "GimbalCmd",  // message name
  5,  // number of fields
  sizeof(rmoss_interfaces__msg__GimbalCmd),
  rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_member_array,  // message members
  rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_init_function,  // function to initialize message memory (memory has to be allocated)
  rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_type_support_handle = {
  0,
  &rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rmoss_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rmoss_interfaces, msg, GimbalCmd)() {
  rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rmoss_interfaces, msg, Gimbal)();
  rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rmoss_interfaces, msg, Gimbal)();
  if (!rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_type_support_handle.typesupport_identifier) {
    rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rmoss_interfaces__msg__GimbalCmd__rosidl_typesupport_introspection_c__GimbalCmd_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
