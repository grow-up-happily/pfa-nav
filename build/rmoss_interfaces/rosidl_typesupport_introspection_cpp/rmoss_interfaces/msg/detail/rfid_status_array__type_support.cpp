// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rmoss_interfaces:msg/RfidStatusArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rmoss_interfaces/msg/detail/rfid_status_array__struct.hpp"
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

void RfidStatusArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rmoss_interfaces::msg::RfidStatusArray(_init);
}

void RfidStatusArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rmoss_interfaces::msg::RfidStatusArray *>(message_memory);
  typed_message->~RfidStatusArray();
}

size_t size_function__RfidStatusArray__robot_rfid_status(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rmoss_interfaces::msg::RfidStatus> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RfidStatusArray__robot_rfid_status(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rmoss_interfaces::msg::RfidStatus> *>(untyped_member);
  return &member[index];
}

void * get_function__RfidStatusArray__robot_rfid_status(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rmoss_interfaces::msg::RfidStatus> *>(untyped_member);
  return &member[index];
}

void fetch_function__RfidStatusArray__robot_rfid_status(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rmoss_interfaces::msg::RfidStatus *>(
    get_const_function__RfidStatusArray__robot_rfid_status(untyped_member, index));
  auto & value = *reinterpret_cast<rmoss_interfaces::msg::RfidStatus *>(untyped_value);
  value = item;
}

void assign_function__RfidStatusArray__robot_rfid_status(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rmoss_interfaces::msg::RfidStatus *>(
    get_function__RfidStatusArray__robot_rfid_status(untyped_member, index));
  const auto & value = *reinterpret_cast<const rmoss_interfaces::msg::RfidStatus *>(untyped_value);
  item = value;
}

void resize_function__RfidStatusArray__robot_rfid_status(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rmoss_interfaces::msg::RfidStatus> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RfidStatusArray_message_member_array[1] = {
  {
    "robot_rfid_status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rmoss_interfaces::msg::RfidStatus>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rmoss_interfaces::msg::RfidStatusArray, robot_rfid_status),  // bytes offset in struct
    nullptr,  // default value
    size_function__RfidStatusArray__robot_rfid_status,  // size() function pointer
    get_const_function__RfidStatusArray__robot_rfid_status,  // get_const(index) function pointer
    get_function__RfidStatusArray__robot_rfid_status,  // get(index) function pointer
    fetch_function__RfidStatusArray__robot_rfid_status,  // fetch(index, &value) function pointer
    assign_function__RfidStatusArray__robot_rfid_status,  // assign(index, value) function pointer
    resize_function__RfidStatusArray__robot_rfid_status  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RfidStatusArray_message_members = {
  "rmoss_interfaces::msg",  // message namespace
  "RfidStatusArray",  // message name
  1,  // number of fields
  sizeof(rmoss_interfaces::msg::RfidStatusArray),
  RfidStatusArray_message_member_array,  // message members
  RfidStatusArray_init_function,  // function to initialize message memory (memory has to be allocated)
  RfidStatusArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RfidStatusArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RfidStatusArray_message_members,
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
get_message_type_support_handle<rmoss_interfaces::msg::RfidStatusArray>()
{
  return &::rmoss_interfaces::msg::rosidl_typesupport_introspection_cpp::RfidStatusArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rmoss_interfaces, msg, RfidStatusArray)() {
  return &::rmoss_interfaces::msg::rosidl_typesupport_introspection_cpp::RfidStatusArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
