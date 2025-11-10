// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/Buff.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__BUFF__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__BUFF__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__Buff __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__Buff __declspec(deprecated)
#endif

namespace pb_rm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Buff_
{
  using Type = Buff_<ContainerAllocator>;

  explicit Buff_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->recovery_buff = 0;
      this->cooling_buff = 0;
      this->defence_buff = 0;
      this->vulnerability_buff = 0;
      this->attack_buff = 0;
      this->remaining_energy = 0;
    }
  }

  explicit Buff_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->recovery_buff = 0;
      this->cooling_buff = 0;
      this->defence_buff = 0;
      this->vulnerability_buff = 0;
      this->attack_buff = 0;
      this->remaining_energy = 0;
    }
  }

  // field types and members
  using _recovery_buff_type =
    uint8_t;
  _recovery_buff_type recovery_buff;
  using _cooling_buff_type =
    uint8_t;
  _cooling_buff_type cooling_buff;
  using _defence_buff_type =
    uint8_t;
  _defence_buff_type defence_buff;
  using _vulnerability_buff_type =
    uint8_t;
  _vulnerability_buff_type vulnerability_buff;
  using _attack_buff_type =
    uint16_t;
  _attack_buff_type attack_buff;
  using _remaining_energy_type =
    uint8_t;
  _remaining_energy_type remaining_energy;

  // setters for named parameter idiom
  Type & set__recovery_buff(
    const uint8_t & _arg)
  {
    this->recovery_buff = _arg;
    return *this;
  }
  Type & set__cooling_buff(
    const uint8_t & _arg)
  {
    this->cooling_buff = _arg;
    return *this;
  }
  Type & set__defence_buff(
    const uint8_t & _arg)
  {
    this->defence_buff = _arg;
    return *this;
  }
  Type & set__vulnerability_buff(
    const uint8_t & _arg)
  {
    this->vulnerability_buff = _arg;
    return *this;
  }
  Type & set__attack_buff(
    const uint16_t & _arg)
  {
    this->attack_buff = _arg;
    return *this;
  }
  Type & set__remaining_energy(
    const uint8_t & _arg)
  {
    this->remaining_energy = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::Buff_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::Buff_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::Buff_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::Buff_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::Buff_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::Buff_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::Buff_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::Buff_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::Buff_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::Buff_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__Buff
    std::shared_ptr<pb_rm_interfaces::msg::Buff_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__Buff
    std::shared_ptr<pb_rm_interfaces::msg::Buff_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Buff_ & other) const
  {
    if (this->recovery_buff != other.recovery_buff) {
      return false;
    }
    if (this->cooling_buff != other.cooling_buff) {
      return false;
    }
    if (this->defence_buff != other.defence_buff) {
      return false;
    }
    if (this->vulnerability_buff != other.vulnerability_buff) {
      return false;
    }
    if (this->attack_buff != other.attack_buff) {
      return false;
    }
    if (this->remaining_energy != other.remaining_energy) {
      return false;
    }
    return true;
  }
  bool operator!=(const Buff_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Buff_

// alias to use template instance with default allocator
using Buff =
  pb_rm_interfaces::msg::Buff_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__BUFF__STRUCT_HPP_
