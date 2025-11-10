// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pb_rm_interfaces:msg/Models.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pb_rm_interfaces/msg/detail/models__rosidl_typesupport_introspection_c.h"
#include "pb_rm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pb_rm_interfaces/msg/detail/models__functions.h"
#include "pb_rm_interfaces/msg/detail/models__struct.h"


// Include directives for member types
// Member `chassis`
// Member `gimbal`
// Member `shoot`
// Member `arm`
// Member `custom_controller`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pb_rm_interfaces__msg__Models__init(message_memory);
}

void pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_fini_function(void * message_memory)
{
  pb_rm_interfaces__msg__Models__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_message_member_array[5] = {
  {
    "chassis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Models, chassis),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gimbal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Models, gimbal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "shoot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Models, shoot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "arm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Models, arm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "custom_controller",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pb_rm_interfaces__msg__Models, custom_controller),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_message_members = {
  "pb_rm_interfaces__msg",  // message namespace
  "Models",  // message name
  5,  // number of fields
  sizeof(pb_rm_interfaces__msg__Models),
  pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_message_member_array,  // message members
  pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_init_function,  // function to initialize message memory (memory has to be allocated)
  pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_message_type_support_handle = {
  0,
  &pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pb_rm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pb_rm_interfaces, msg, Models)() {
  if (!pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_message_type_support_handle.typesupport_identifier) {
    pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pb_rm_interfaces__msg__Models__rosidl_typesupport_introspection_c__Models_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
