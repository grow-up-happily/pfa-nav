// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:msg/ExchangeAmmon.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__EXCHANGE_AMMON__STRUCT_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__EXCHANGE_AMMON__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__msg__ExchangeAmmon __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__msg__ExchangeAmmon __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ExchangeAmmon_
{
  using Type = ExchangeAmmon_<ContainerAllocator>;

  explicit ExchangeAmmon_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
      this->ammo_request = 0;
    }
  }

  explicit ExchangeAmmon_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
      this->ammo_request = 0;
    }
  }

  // field types and members
  using _robot_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_name_type robot_name;
  using _ammo_request_type =
    uint8_t;
  _ammo_request_type ammo_request;

  // setters for named parameter idiom
  Type & set__robot_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_name = _arg;
    return *this;
  }
  Type & set__ammo_request(
    const uint8_t & _arg)
  {
    this->ammo_request = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__msg__ExchangeAmmon
    std::shared_ptr<rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__msg__ExchangeAmmon
    std::shared_ptr<rmoss_interfaces::msg::ExchangeAmmon_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExchangeAmmon_ & other) const
  {
    if (this->robot_name != other.robot_name) {
      return false;
    }
    if (this->ammo_request != other.ammo_request) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExchangeAmmon_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExchangeAmmon_

// alias to use template instance with default allocator
using ExchangeAmmon =
  rmoss_interfaces::msg::ExchangeAmmon_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__EXCHANGE_AMMON__STRUCT_HPP_
