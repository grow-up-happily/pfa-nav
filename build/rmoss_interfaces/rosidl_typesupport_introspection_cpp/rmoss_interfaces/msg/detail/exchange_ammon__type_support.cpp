// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rmoss_interfaces:msg/ExchangeAmmon.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rmoss_interfaces/msg/detail/exchange_ammon__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rmoss_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ExchangeAmmon_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rmoss_interfaces::msg::ExchangeAmmon(_init);
}

void ExchangeAmmon_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rmoss_interfaces::msg::ExchangeAmmon *>(message_memory);
  typed_message->~ExchangeAmmon();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExchangeAmmon_message_member_array[2] = {
  {
    "robot_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rmoss_interfaces::msg::ExchangeAmmon, robot_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ammo_request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rmoss_interfaces::msg::ExchangeAmmon, ammo_request),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExchangeAmmon_message_members = {
  "rmoss_interfaces::msg",  // message namespace
  "ExchangeAmmon",  // message name
  2,  // number of fields
  sizeof(rmoss_interfaces::msg::ExchangeAmmon),
  ExchangeAmmon_message_member_array,  // message members
  ExchangeAmmon_init_function,  // function to initialize message memory (memory has to be allocated)
  ExchangeAmmon_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExchangeAmmon_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExchangeAmmon_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rmoss_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rmoss_interfaces::msg::ExchangeAmmon>()
{
  return &::rmoss_interfaces::msg::rosidl_typesupport_introspection_cpp::ExchangeAmmon_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rmoss_interfaces, msg, ExchangeAmmon)() {
  return &::rmoss_interfaces::msg::rosidl_typesupport_introspection_cpp::ExchangeAmmon_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
