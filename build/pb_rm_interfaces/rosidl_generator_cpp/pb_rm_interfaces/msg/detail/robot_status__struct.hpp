// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'robot_pos'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__RobotStatus __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__RobotStatus __declspec(deprecated)
#endif

namespace pb_rm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStatus_
{
  using Type = RobotStatus_<ContainerAllocator>;

  explicit RobotStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_pos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
      this->robot_level = 0;
      this->current_hp = 0;
      this->maximum_hp = 0;
      this->shooter_barrel_cooling_value = 0;
      this->shooter_barrel_heat_limit = 0;
      this->shooter_17mm_1_barrel_heat = 0;
      this->armor_id = 0;
      this->hp_deduction_reason = 0;
      this->projectile_allowance_17mm = 0;
      this->remaining_gold_coin = 0;
      this->is_hp_deduced = false;
    }
  }

  explicit RobotStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_pos(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
      this->robot_level = 0;
      this->current_hp = 0;
      this->maximum_hp = 0;
      this->shooter_barrel_cooling_value = 0;
      this->shooter_barrel_heat_limit = 0;
      this->shooter_17mm_1_barrel_heat = 0;
      this->armor_id = 0;
      this->hp_deduction_reason = 0;
      this->projectile_allowance_17mm = 0;
      this->remaining_gold_coin = 0;
      this->is_hp_deduced = false;
    }
  }

  // field types and members
  using _robot_id_type =
    uint8_t;
  _robot_id_type robot_id;
  using _robot_level_type =
    uint8_t;
  _robot_level_type robot_level;
  using _current_hp_type =
    uint16_t;
  _current_hp_type current_hp;
  using _maximum_hp_type =
    uint16_t;
  _maximum_hp_type maximum_hp;
  using _shooter_barrel_cooling_value_type =
    uint16_t;
  _shooter_barrel_cooling_value_type shooter_barrel_cooling_value;
  using _shooter_barrel_heat_limit_type =
    uint16_t;
  _shooter_barrel_heat_limit_type shooter_barrel_heat_limit;
  using _shooter_17mm_1_barrel_heat_type =
    uint16_t;
  _shooter_17mm_1_barrel_heat_type shooter_17mm_1_barrel_heat;
  using _robot_pos_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _robot_pos_type robot_pos;
  using _armor_id_type =
    uint8_t;
  _armor_id_type armor_id;
  using _hp_deduction_reason_type =
    uint8_t;
  _hp_deduction_reason_type hp_deduction_reason;
  using _projectile_allowance_17mm_type =
    uint16_t;
  _projectile_allowance_17mm_type projectile_allowance_17mm;
  using _remaining_gold_coin_type =
    uint16_t;
  _remaining_gold_coin_type remaining_gold_coin;
  using _is_hp_deduced_type =
    bool;
  _is_hp_deduced_type is_hp_deduced;

  // setters for named parameter idiom
  Type & set__robot_id(
    const uint8_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__robot_level(
    const uint8_t & _arg)
  {
    this->robot_level = _arg;
    return *this;
  }
  Type & set__current_hp(
    const uint16_t & _arg)
  {
    this->current_hp = _arg;
    return *this;
  }
  Type & set__maximum_hp(
    const uint16_t & _arg)
  {
    this->maximum_hp = _arg;
    return *this;
  }
  Type & set__shooter_barrel_cooling_value(
    const uint16_t & _arg)
  {
    this->shooter_barrel_cooling_value = _arg;
    return *this;
  }
  Type & set__shooter_barrel_heat_limit(
    const uint16_t & _arg)
  {
    this->shooter_barrel_heat_limit = _arg;
    return *this;
  }
  Type & set__shooter_17mm_1_barrel_heat(
    const uint16_t & _arg)
  {
    this->shooter_17mm_1_barrel_heat = _arg;
    return *this;
  }
  Type & set__robot_pos(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->robot_pos = _arg;
    return *this;
  }
  Type & set__armor_id(
    const uint8_t & _arg)
  {
    this->armor_id = _arg;
    return *this;
  }
  Type & set__hp_deduction_reason(
    const uint8_t & _arg)
  {
    this->hp_deduction_reason = _arg;
    return *this;
  }
  Type & set__projectile_allowance_17mm(
    const uint16_t & _arg)
  {
    this->projectile_allowance_17mm = _arg;
    return *this;
  }
  Type & set__remaining_gold_coin(
    const uint16_t & _arg)
  {
    this->remaining_gold_coin = _arg;
    return *this;
  }
  Type & set__is_hp_deduced(
    const bool & _arg)
  {
    this->is_hp_deduced = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t ARMOR_HIT =
    0u;
  static constexpr uint8_t SYSTEM_OFFLINE =
    1u;
  static constexpr uint8_t OVER_SHOOT_SPEED =
    2u;
  static constexpr uint8_t OVER_HEAT =
    3u;
  static constexpr uint8_t OVER_POWER =
    4u;
  static constexpr uint8_t ARMOR_COLLISION =
    5u;

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__RobotStatus
    std::shared_ptr<pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__RobotStatus
    std::shared_ptr<pb_rm_interfaces::msg::RobotStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStatus_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->robot_level != other.robot_level) {
      return false;
    }
    if (this->current_hp != other.current_hp) {
      return false;
    }
    if (this->maximum_hp != other.maximum_hp) {
      return false;
    }
    if (this->shooter_barrel_cooling_value != other.shooter_barrel_cooling_value) {
      return false;
    }
    if (this->shooter_barrel_heat_limit != other.shooter_barrel_heat_limit) {
      return false;
    }
    if (this->shooter_17mm_1_barrel_heat != other.shooter_17mm_1_barrel_heat) {
      return false;
    }
    if (this->robot_pos != other.robot_pos) {
      return false;
    }
    if (this->armor_id != other.armor_id) {
      return false;
    }
    if (this->hp_deduction_reason != other.hp_deduction_reason) {
      return false;
    }
    if (this->projectile_allowance_17mm != other.projectile_allowance_17mm) {
      return false;
    }
    if (this->remaining_gold_coin != other.remaining_gold_coin) {
      return false;
    }
    if (this->is_hp_deduced != other.is_hp_deduced) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStatus_

// alias to use template instance with default allocator
using RobotStatus =
  pb_rm_interfaces::msg::RobotStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::ARMOR_HIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::SYSTEM_OFFLINE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::OVER_SHOOT_SPEED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::OVER_HEAT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::OVER_POWER;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::ARMOR_COLLISION;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
