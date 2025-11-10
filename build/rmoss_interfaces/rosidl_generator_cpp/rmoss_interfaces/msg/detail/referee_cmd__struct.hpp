// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:msg/RefereeCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__STRUCT_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__msg__RefereeCmd __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__msg__RefereeCmd __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RefereeCmd_
{
  using Type = RefereeCmd_<ContainerAllocator>;

  explicit RefereeCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->cmd = 0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->cmd = 0;
      this->robot_name = "";
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
    }
  }

  explicit RefereeCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->cmd = 0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->cmd = 0;
      this->robot_name = "";
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
    }
  }

  // field types and members
  using _cmd_type =
    uint8_t;
  _cmd_type cmd;
  using _robot_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_name_type robot_name;

  // setters for named parameter idiom
  Type & set__cmd(
    const uint8_t & _arg)
  {
    this->cmd = _arg;
    return *this;
  }
  Type & set__robot_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_name = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t START_PREPARATION =
    0u;
  static constexpr uint8_t START_SELF_CHECKING =
    1u;
  static constexpr uint8_t START_GAME =
    2u;
  static constexpr uint8_t STOP_GAME =
    3u;
  static constexpr uint8_t KILL_ROBOT =
    4u;
  static constexpr uint8_t REVIVE_ROBOT =
    5u;
  static constexpr uint8_t PREPARATION =
    0u;
  static constexpr uint8_t SELF_CHECKING =
    1u;

  // pointer types
  using RawPtr =
    rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__msg__RefereeCmd
    std::shared_ptr<rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__msg__RefereeCmd
    std::shared_ptr<rmoss_interfaces::msg::RefereeCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RefereeCmd_ & other) const
  {
    if (this->cmd != other.cmd) {
      return false;
    }
    if (this->robot_name != other.robot_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const RefereeCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RefereeCmd_

// alias to use template instance with default allocator
using RefereeCmd =
  rmoss_interfaces::msg::RefereeCmd_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RefereeCmd_<ContainerAllocator>::START_PREPARATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RefereeCmd_<ContainerAllocator>::START_SELF_CHECKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RefereeCmd_<ContainerAllocator>::START_GAME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RefereeCmd_<ContainerAllocator>::STOP_GAME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RefereeCmd_<ContainerAllocator>::KILL_ROBOT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RefereeCmd_<ContainerAllocator>::REVIVE_ROBOT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RefereeCmd_<ContainerAllocator>::PREPARATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RefereeCmd_<ContainerAllocator>::SELF_CHECKING;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__REFEREE_CMD__STRUCT_HPP_
