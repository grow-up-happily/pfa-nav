// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__RfidStatus __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__RfidStatus __declspec(deprecated)
#endif

namespace pb_rm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RfidStatus_
{
  using Type = RfidStatus_<ContainerAllocator>;

  explicit RfidStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->base_gain_point = false;
      this->central_highland_gain_point = false;
      this->enemy_central_highland_gain_point = false;
      this->friendly_trapezoidal_highland_gain_point = false;
      this->enemy_trapezoidal_highland_gain_point = false;
      this->friendly_fly_ramp_front_gain_point = false;
      this->friendly_fly_ramp_back_gain_point = false;
      this->enemy_fly_ramp_front_gain_point = false;
      this->enemy_fly_ramp_back_gain_point = false;
      this->friendly_central_highland_lower_gain_point = false;
      this->friendly_central_highland_upper_gain_point = false;
      this->enemy_central_highland_lower_gain_point = false;
      this->enemy_central_highland_upper_gain_point = false;
      this->friendly_highway_lower_gain_point = false;
      this->friendly_highway_upper_gain_point = false;
      this->enemy_highway_lower_gain_point = false;
      this->enemy_highway_upper_gain_point = false;
      this->friendly_fortress_gain_point = false;
      this->friendly_outpost_gain_point = false;
      this->friendly_supply_zone_non_exchange = false;
      this->friendly_supply_zone_exchange = false;
      this->friendly_big_resource_island = false;
      this->enemy_big_resource_island = false;
      this->center_gain_point = false;
    }
  }

  explicit RfidStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->base_gain_point = false;
      this->central_highland_gain_point = false;
      this->enemy_central_highland_gain_point = false;
      this->friendly_trapezoidal_highland_gain_point = false;
      this->enemy_trapezoidal_highland_gain_point = false;
      this->friendly_fly_ramp_front_gain_point = false;
      this->friendly_fly_ramp_back_gain_point = false;
      this->enemy_fly_ramp_front_gain_point = false;
      this->enemy_fly_ramp_back_gain_point = false;
      this->friendly_central_highland_lower_gain_point = false;
      this->friendly_central_highland_upper_gain_point = false;
      this->enemy_central_highland_lower_gain_point = false;
      this->enemy_central_highland_upper_gain_point = false;
      this->friendly_highway_lower_gain_point = false;
      this->friendly_highway_upper_gain_point = false;
      this->enemy_highway_lower_gain_point = false;
      this->enemy_highway_upper_gain_point = false;
      this->friendly_fortress_gain_point = false;
      this->friendly_outpost_gain_point = false;
      this->friendly_supply_zone_non_exchange = false;
      this->friendly_supply_zone_exchange = false;
      this->friendly_big_resource_island = false;
      this->enemy_big_resource_island = false;
      this->center_gain_point = false;
    }
  }

  // field types and members
  using _base_gain_point_type =
    bool;
  _base_gain_point_type base_gain_point;
  using _central_highland_gain_point_type =
    bool;
  _central_highland_gain_point_type central_highland_gain_point;
  using _enemy_central_highland_gain_point_type =
    bool;
  _enemy_central_highland_gain_point_type enemy_central_highland_gain_point;
  using _friendly_trapezoidal_highland_gain_point_type =
    bool;
  _friendly_trapezoidal_highland_gain_point_type friendly_trapezoidal_highland_gain_point;
  using _enemy_trapezoidal_highland_gain_point_type =
    bool;
  _enemy_trapezoidal_highland_gain_point_type enemy_trapezoidal_highland_gain_point;
  using _friendly_fly_ramp_front_gain_point_type =
    bool;
  _friendly_fly_ramp_front_gain_point_type friendly_fly_ramp_front_gain_point;
  using _friendly_fly_ramp_back_gain_point_type =
    bool;
  _friendly_fly_ramp_back_gain_point_type friendly_fly_ramp_back_gain_point;
  using _enemy_fly_ramp_front_gain_point_type =
    bool;
  _enemy_fly_ramp_front_gain_point_type enemy_fly_ramp_front_gain_point;
  using _enemy_fly_ramp_back_gain_point_type =
    bool;
  _enemy_fly_ramp_back_gain_point_type enemy_fly_ramp_back_gain_point;
  using _friendly_central_highland_lower_gain_point_type =
    bool;
  _friendly_central_highland_lower_gain_point_type friendly_central_highland_lower_gain_point;
  using _friendly_central_highland_upper_gain_point_type =
    bool;
  _friendly_central_highland_upper_gain_point_type friendly_central_highland_upper_gain_point;
  using _enemy_central_highland_lower_gain_point_type =
    bool;
  _enemy_central_highland_lower_gain_point_type enemy_central_highland_lower_gain_point;
  using _enemy_central_highland_upper_gain_point_type =
    bool;
  _enemy_central_highland_upper_gain_point_type enemy_central_highland_upper_gain_point;
  using _friendly_highway_lower_gain_point_type =
    bool;
  _friendly_highway_lower_gain_point_type friendly_highway_lower_gain_point;
  using _friendly_highway_upper_gain_point_type =
    bool;
  _friendly_highway_upper_gain_point_type friendly_highway_upper_gain_point;
  using _enemy_highway_lower_gain_point_type =
    bool;
  _enemy_highway_lower_gain_point_type enemy_highway_lower_gain_point;
  using _enemy_highway_upper_gain_point_type =
    bool;
  _enemy_highway_upper_gain_point_type enemy_highway_upper_gain_point;
  using _friendly_fortress_gain_point_type =
    bool;
  _friendly_fortress_gain_point_type friendly_fortress_gain_point;
  using _friendly_outpost_gain_point_type =
    bool;
  _friendly_outpost_gain_point_type friendly_outpost_gain_point;
  using _friendly_supply_zone_non_exchange_type =
    bool;
  _friendly_supply_zone_non_exchange_type friendly_supply_zone_non_exchange;
  using _friendly_supply_zone_exchange_type =
    bool;
  _friendly_supply_zone_exchange_type friendly_supply_zone_exchange;
  using _friendly_big_resource_island_type =
    bool;
  _friendly_big_resource_island_type friendly_big_resource_island;
  using _enemy_big_resource_island_type =
    bool;
  _enemy_big_resource_island_type enemy_big_resource_island;
  using _center_gain_point_type =
    bool;
  _center_gain_point_type center_gain_point;

  // setters for named parameter idiom
  Type & set__base_gain_point(
    const bool & _arg)
  {
    this->base_gain_point = _arg;
    return *this;
  }
  Type & set__central_highland_gain_point(
    const bool & _arg)
  {
    this->central_highland_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_central_highland_gain_point(
    const bool & _arg)
  {
    this->enemy_central_highland_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_trapezoidal_highland_gain_point(
    const bool & _arg)
  {
    this->friendly_trapezoidal_highland_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_trapezoidal_highland_gain_point(
    const bool & _arg)
  {
    this->enemy_trapezoidal_highland_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_fly_ramp_front_gain_point(
    const bool & _arg)
  {
    this->friendly_fly_ramp_front_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_fly_ramp_back_gain_point(
    const bool & _arg)
  {
    this->friendly_fly_ramp_back_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_fly_ramp_front_gain_point(
    const bool & _arg)
  {
    this->enemy_fly_ramp_front_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_fly_ramp_back_gain_point(
    const bool & _arg)
  {
    this->enemy_fly_ramp_back_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_central_highland_lower_gain_point(
    const bool & _arg)
  {
    this->friendly_central_highland_lower_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_central_highland_upper_gain_point(
    const bool & _arg)
  {
    this->friendly_central_highland_upper_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_central_highland_lower_gain_point(
    const bool & _arg)
  {
    this->enemy_central_highland_lower_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_central_highland_upper_gain_point(
    const bool & _arg)
  {
    this->enemy_central_highland_upper_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_highway_lower_gain_point(
    const bool & _arg)
  {
    this->friendly_highway_lower_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_highway_upper_gain_point(
    const bool & _arg)
  {
    this->friendly_highway_upper_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_highway_lower_gain_point(
    const bool & _arg)
  {
    this->enemy_highway_lower_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_highway_upper_gain_point(
    const bool & _arg)
  {
    this->enemy_highway_upper_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_fortress_gain_point(
    const bool & _arg)
  {
    this->friendly_fortress_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_outpost_gain_point(
    const bool & _arg)
  {
    this->friendly_outpost_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_supply_zone_non_exchange(
    const bool & _arg)
  {
    this->friendly_supply_zone_non_exchange = _arg;
    return *this;
  }
  Type & set__friendly_supply_zone_exchange(
    const bool & _arg)
  {
    this->friendly_supply_zone_exchange = _arg;
    return *this;
  }
  Type & set__friendly_big_resource_island(
    const bool & _arg)
  {
    this->friendly_big_resource_island = _arg;
    return *this;
  }
  Type & set__enemy_big_resource_island(
    const bool & _arg)
  {
    this->enemy_big_resource_island = _arg;
    return *this;
  }
  Type & set__center_gain_point(
    const bool & _arg)
  {
    this->center_gain_point = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t NOT_DETECTED =
    0u;
  static constexpr uint8_t DETECTED =
    1u;

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__RfidStatus
    std::shared_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__RfidStatus
    std::shared_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RfidStatus_ & other) const
  {
    if (this->base_gain_point != other.base_gain_point) {
      return false;
    }
    if (this->central_highland_gain_point != other.central_highland_gain_point) {
      return false;
    }
    if (this->enemy_central_highland_gain_point != other.enemy_central_highland_gain_point) {
      return false;
    }
    if (this->friendly_trapezoidal_highland_gain_point != other.friendly_trapezoidal_highland_gain_point) {
      return false;
    }
    if (this->enemy_trapezoidal_highland_gain_point != other.enemy_trapezoidal_highland_gain_point) {
      return false;
    }
    if (this->friendly_fly_ramp_front_gain_point != other.friendly_fly_ramp_front_gain_point) {
      return false;
    }
    if (this->friendly_fly_ramp_back_gain_point != other.friendly_fly_ramp_back_gain_point) {
      return false;
    }
    if (this->enemy_fly_ramp_front_gain_point != other.enemy_fly_ramp_front_gain_point) {
      return false;
    }
    if (this->enemy_fly_ramp_back_gain_point != other.enemy_fly_ramp_back_gain_point) {
      return false;
    }
    if (this->friendly_central_highland_lower_gain_point != other.friendly_central_highland_lower_gain_point) {
      return false;
    }
    if (this->friendly_central_highland_upper_gain_point != other.friendly_central_highland_upper_gain_point) {
      return false;
    }
    if (this->enemy_central_highland_lower_gain_point != other.enemy_central_highland_lower_gain_point) {
      return false;
    }
    if (this->enemy_central_highland_upper_gain_point != other.enemy_central_highland_upper_gain_point) {
      return false;
    }
    if (this->friendly_highway_lower_gain_point != other.friendly_highway_lower_gain_point) {
      return false;
    }
    if (this->friendly_highway_upper_gain_point != other.friendly_highway_upper_gain_point) {
      return false;
    }
    if (this->enemy_highway_lower_gain_point != other.enemy_highway_lower_gain_point) {
      return false;
    }
    if (this->enemy_highway_upper_gain_point != other.enemy_highway_upper_gain_point) {
      return false;
    }
    if (this->friendly_fortress_gain_point != other.friendly_fortress_gain_point) {
      return false;
    }
    if (this->friendly_outpost_gain_point != other.friendly_outpost_gain_point) {
      return false;
    }
    if (this->friendly_supply_zone_non_exchange != other.friendly_supply_zone_non_exchange) {
      return false;
    }
    if (this->friendly_supply_zone_exchange != other.friendly_supply_zone_exchange) {
      return false;
    }
    if (this->friendly_big_resource_island != other.friendly_big_resource_island) {
      return false;
    }
    if (this->enemy_big_resource_island != other.enemy_big_resource_island) {
      return false;
    }
    if (this->center_gain_point != other.center_gain_point) {
      return false;
    }
    return true;
  }
  bool operator!=(const RfidStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RfidStatus_

// alias to use template instance with default allocator
using RfidStatus =
  pb_rm_interfaces::msg::RfidStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RfidStatus_<ContainerAllocator>::NOT_DETECTED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RfidStatus_<ContainerAllocator>::DETECTED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_HPP_
