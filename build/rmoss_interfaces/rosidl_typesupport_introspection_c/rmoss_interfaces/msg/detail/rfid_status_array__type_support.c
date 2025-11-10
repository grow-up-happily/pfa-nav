// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rmoss_interfaces:msg/RfidStatusArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rmoss_interfaces/msg/detail/rfid_status_array__rosidl_typesupport_introspection_c.h"
#include "rmoss_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rmoss_interfaces/msg/detail/rfid_status_array__functions.h"
#include "rmoss_interfaces/msg/detail/rfid_status_array__struct.h"


// Include directives for member types
// Member `robot_rfid_status`
#include "rmoss_interfaces/msg/rfid_status.h"
// Member `robot_rfid_status`
#include "rmoss_interfaces/msg/detail/rfid_status__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rmoss_interfaces__msg__RfidStatusArray__init(message_memory);
}

void rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_fini_function(void * message_memory)
{
  rmoss_interfaces__msg__RfidStatusArray__fini(message_memory);
}

size_t rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__size_function__RfidStatusArray__robot_rfid_status(
  const void * untyped_member)
{
  const rmoss_interfaces__msg__RfidStatus__Sequence * member =
    (const rmoss_interfaces__msg__RfidStatus__Sequence *)(untyped_member);
  return member->size;
}

const void * rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__get_const_function__RfidStatusArray__robot_rfid_status(
  const void * untyped_member, size_t index)
{
  const rmoss_interfaces__msg__RfidStatus__Sequence * member =
    (const rmoss_interfaces__msg__RfidStatus__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__get_function__RfidStatusArray__robot_rfid_status(
  void * untyped_member, size_t index)
{
  rmoss_interfaces__msg__RfidStatus__Sequence * member =
    (rmoss_interfaces__msg__RfidStatus__Sequence *)(untyped_member);
  return &member->data[index];
}

void rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__fetch_function__RfidStatusArray__robot_rfid_status(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rmoss_interfaces__msg__RfidStatus * item =
    ((const rmoss_interfaces__msg__RfidStatus *)
    rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__get_const_function__RfidStatusArray__robot_rfid_status(untyped_member, index));
  rmoss_interfaces__msg__RfidStatus * value =
    (rmoss_interfaces__msg__RfidStatus *)(untyped_value);
  *value = *item;
}

void rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__assign_function__RfidStatusArray__robot_rfid_status(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rmoss_interfaces__msg__RfidStatus * item =
    ((rmoss_interfaces__msg__RfidStatus *)
    rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__get_function__RfidStatusArray__robot_rfid_status(untyped_member, index));
  const rmoss_interfaces__msg__RfidStatus * value =
    (const rmoss_interfaces__msg__RfidStatus *)(untyped_value);
  *item = *value;
}

bool rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__resize_function__RfidStatusArray__robot_rfid_status(
  void * untyped_member, size_t size)
{
  rmoss_interfaces__msg__RfidStatus__Sequence * member =
    (rmoss_interfaces__msg__RfidStatus__Sequence *)(untyped_member);
  rmoss_interfaces__msg__RfidStatus__Sequence__fini(member);
  return rmoss_interfaces__msg__RfidStatus__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_message_member_array[1] = {
  {
    "robot_rfid_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rmoss_interfaces__msg__RfidStatusArray, robot_rfid_status),  // bytes offset in struct
    NULL,  // default value
    rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__size_function__RfidStatusArray__robot_rfid_status,  // size() function pointer
    rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__get_const_function__RfidStatusArray__robot_rfid_status,  // get_const(index) function pointer
    rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__get_function__RfidStatusArray__robot_rfid_status,  // get(index) function pointer
    rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__fetch_function__RfidStatusArray__robot_rfid_status,  // fetch(index, &value) function pointer
    rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__assign_function__RfidStatusArray__robot_rfid_status,  // assign(index, value) function pointer
    rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__resize_function__RfidStatusArray__robot_rfid_status  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_message_members = {
  "rmoss_interfaces__msg",  // message namespace
  "RfidStatusArray",  // message name
  1,  // number of fields
  sizeof(rmoss_interfaces__msg__RfidStatusArray),
  rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_message_member_array,  // message members
  rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_init_function,  // function to initialize message memory (memory has to be allocated)
  rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_message_type_support_handle = {
  0,
  &rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rmoss_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rmoss_interfaces, msg, RfidStatusArray)() {
  rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rmoss_interfaces, msg, RfidStatus)();
  if (!rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_message_type_support_handle.typesupport_identifier) {
    rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rmoss_interfaces__msg__RfidStatusArray__rosidl_typesupport_introspection_c__RfidStatusArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
