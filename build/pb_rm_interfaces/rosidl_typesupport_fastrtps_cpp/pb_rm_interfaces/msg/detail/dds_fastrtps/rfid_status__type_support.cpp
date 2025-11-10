// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/rfid_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "pb_rm_interfaces/msg/detail/rfid_status__struct.hpp"

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

namespace pb_rm_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
cdr_serialize(
  const pb_rm_interfaces::msg::RfidStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: base_gain_point
  cdr << (ros_message.base_gain_point ? true : false);
  // Member: central_highland_gain_point
  cdr << (ros_message.central_highland_gain_point ? true : false);
  // Member: enemy_central_highland_gain_point
  cdr << (ros_message.enemy_central_highland_gain_point ? true : false);
  // Member: friendly_trapezoidal_highland_gain_point
  cdr << (ros_message.friendly_trapezoidal_highland_gain_point ? true : false);
  // Member: enemy_trapezoidal_highland_gain_point
  cdr << (ros_message.enemy_trapezoidal_highland_gain_point ? true : false);
  // Member: friendly_fly_ramp_front_gain_point
  cdr << (ros_message.friendly_fly_ramp_front_gain_point ? true : false);
  // Member: friendly_fly_ramp_back_gain_point
  cdr << (ros_message.friendly_fly_ramp_back_gain_point ? true : false);
  // Member: enemy_fly_ramp_front_gain_point
  cdr << (ros_message.enemy_fly_ramp_front_gain_point ? true : false);
  // Member: enemy_fly_ramp_back_gain_point
  cdr << (ros_message.enemy_fly_ramp_back_gain_point ? true : false);
  // Member: friendly_central_highland_lower_gain_point
  cdr << (ros_message.friendly_central_highland_lower_gain_point ? true : false);
  // Member: friendly_central_highland_upper_gain_point
  cdr << (ros_message.friendly_central_highland_upper_gain_point ? true : false);
  // Member: enemy_central_highland_lower_gain_point
  cdr << (ros_message.enemy_central_highland_lower_gain_point ? true : false);
  // Member: enemy_central_highland_upper_gain_point
  cdr << (ros_message.enemy_central_highland_upper_gain_point ? true : false);
  // Member: friendly_highway_lower_gain_point
  cdr << (ros_message.friendly_highway_lower_gain_point ? true : false);
  // Member: friendly_highway_upper_gain_point
  cdr << (ros_message.friendly_highway_upper_gain_point ? true : false);
  // Member: enemy_highway_lower_gain_point
  cdr << (ros_message.enemy_highway_lower_gain_point ? true : false);
  // Member: enemy_highway_upper_gain_point
  cdr << (ros_message.enemy_highway_upper_gain_point ? true : false);
  // Member: friendly_fortress_gain_point
  cdr << (ros_message.friendly_fortress_gain_point ? true : false);
  // Member: friendly_outpost_gain_point
  cdr << (ros_message.friendly_outpost_gain_point ? true : false);
  // Member: friendly_supply_zone_non_exchange
  cdr << (ros_message.friendly_supply_zone_non_exchange ? true : false);
  // Member: friendly_supply_zone_exchange
  cdr << (ros_message.friendly_supply_zone_exchange ? true : false);
  // Member: friendly_big_resource_island
  cdr << (ros_message.friendly_big_resource_island ? true : false);
  // Member: enemy_big_resource_island
  cdr << (ros_message.enemy_big_resource_island ? true : false);
  // Member: center_gain_point
  cdr << (ros_message.center_gain_point ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pb_rm_interfaces::msg::RfidStatus & ros_message)
{
  // Member: base_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.base_gain_point = tmp ? true : false;
  }

  // Member: central_highland_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.central_highland_gain_point = tmp ? true : false;
  }

  // Member: enemy_central_highland_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enemy_central_highland_gain_point = tmp ? true : false;
  }

  // Member: friendly_trapezoidal_highland_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_trapezoidal_highland_gain_point = tmp ? true : false;
  }

  // Member: enemy_trapezoidal_highland_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enemy_trapezoidal_highland_gain_point = tmp ? true : false;
  }

  // Member: friendly_fly_ramp_front_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_fly_ramp_front_gain_point = tmp ? true : false;
  }

  // Member: friendly_fly_ramp_back_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_fly_ramp_back_gain_point = tmp ? true : false;
  }

  // Member: enemy_fly_ramp_front_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enemy_fly_ramp_front_gain_point = tmp ? true : false;
  }

  // Member: enemy_fly_ramp_back_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enemy_fly_ramp_back_gain_point = tmp ? true : false;
  }

  // Member: friendly_central_highland_lower_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_central_highland_lower_gain_point = tmp ? true : false;
  }

  // Member: friendly_central_highland_upper_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_central_highland_upper_gain_point = tmp ? true : false;
  }

  // Member: enemy_central_highland_lower_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enemy_central_highland_lower_gain_point = tmp ? true : false;
  }

  // Member: enemy_central_highland_upper_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enemy_central_highland_upper_gain_point = tmp ? true : false;
  }

  // Member: friendly_highway_lower_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_highway_lower_gain_point = tmp ? true : false;
  }

  // Member: friendly_highway_upper_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_highway_upper_gain_point = tmp ? true : false;
  }

  // Member: enemy_highway_lower_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enemy_highway_lower_gain_point = tmp ? true : false;
  }

  // Member: enemy_highway_upper_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enemy_highway_upper_gain_point = tmp ? true : false;
  }

  // Member: friendly_fortress_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_fortress_gain_point = tmp ? true : false;
  }

  // Member: friendly_outpost_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_outpost_gain_point = tmp ? true : false;
  }

  // Member: friendly_supply_zone_non_exchange
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_supply_zone_non_exchange = tmp ? true : false;
  }

  // Member: friendly_supply_zone_exchange
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_supply_zone_exchange = tmp ? true : false;
  }

  // Member: friendly_big_resource_island
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.friendly_big_resource_island = tmp ? true : false;
  }

  // Member: enemy_big_resource_island
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enemy_big_resource_island = tmp ? true : false;
  }

  // Member: center_gain_point
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.center_gain_point = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
get_serialized_size(
  const pb_rm_interfaces::msg::RfidStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: base_gain_point
  {
    size_t item_size = sizeof(ros_message.base_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: central_highland_gain_point
  {
    size_t item_size = sizeof(ros_message.central_highland_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_central_highland_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_central_highland_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_trapezoidal_highland_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_trapezoidal_highland_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_trapezoidal_highland_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_trapezoidal_highland_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_fly_ramp_front_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_fly_ramp_front_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_fly_ramp_back_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_fly_ramp_back_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_fly_ramp_front_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_fly_ramp_front_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_fly_ramp_back_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_fly_ramp_back_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_central_highland_lower_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_central_highland_lower_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_central_highland_upper_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_central_highland_upper_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_central_highland_lower_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_central_highland_lower_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_central_highland_upper_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_central_highland_upper_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_highway_lower_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_highway_lower_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_highway_upper_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_highway_upper_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_highway_lower_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_highway_lower_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_highway_upper_gain_point
  {
    size_t item_size = sizeof(ros_message.enemy_highway_upper_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_fortress_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_fortress_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_outpost_gain_point
  {
    size_t item_size = sizeof(ros_message.friendly_outpost_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_supply_zone_non_exchange
  {
    size_t item_size = sizeof(ros_message.friendly_supply_zone_non_exchange);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_supply_zone_exchange
  {
    size_t item_size = sizeof(ros_message.friendly_supply_zone_exchange);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: friendly_big_resource_island
  {
    size_t item_size = sizeof(ros_message.friendly_big_resource_island);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_big_resource_island
  {
    size_t item_size = sizeof(ros_message.enemy_big_resource_island);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: center_gain_point
  {
    size_t item_size = sizeof(ros_message.center_gain_point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pb_rm_interfaces
max_serialized_size_RfidStatus(
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


  // Member: base_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: central_highland_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_central_highland_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_trapezoidal_highland_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_trapezoidal_highland_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_fly_ramp_front_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_fly_ramp_back_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_fly_ramp_front_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_fly_ramp_back_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_central_highland_lower_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_central_highland_upper_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_central_highland_lower_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_central_highland_upper_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_highway_lower_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_highway_upper_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_highway_lower_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_highway_upper_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_fortress_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_outpost_gain_point
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_supply_zone_non_exchange
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_supply_zone_exchange
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: friendly_big_resource_island
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_big_resource_island
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: center_gain_point
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
    using DataType = pb_rm_interfaces::msg::RfidStatus;
    is_plain =
      (
      offsetof(DataType, center_gain_point) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RfidStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const pb_rm_interfaces::msg::RfidStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RfidStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<pb_rm_interfaces::msg::RfidStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RfidStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const pb_rm_interfaces::msg::RfidStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RfidStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RfidStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RfidStatus__callbacks = {
  "pb_rm_interfaces::msg",
  "RfidStatus",
  _RfidStatus__cdr_serialize,
  _RfidStatus__cdr_deserialize,
  _RfidStatus__get_serialized_size,
  _RfidStatus__max_serialized_size
};

static rosidl_message_type_support_t _RfidStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RfidStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pb_rm_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_pb_rm_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<pb_rm_interfaces::msg::RfidStatus>()
{
  return &pb_rm_interfaces::msg::typesupport_fastrtps_cpp::_RfidStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pb_rm_interfaces, msg, RfidStatus)() {
  return &pb_rm_interfaces::msg::typesupport_fastrtps_cpp::_RfidStatus__handle;
}

#ifdef __cplusplus
}
#endif
