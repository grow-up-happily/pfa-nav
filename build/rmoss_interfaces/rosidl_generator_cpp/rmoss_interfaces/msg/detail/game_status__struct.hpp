// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__msg__GameStatus __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__msg__GameStatus __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GameStatus_
{
  using Type = GameStatus_<ContainerAllocator>;

  explicit GameStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->status = 0;
      this->total_time = 0l;
      this->current_time = 0l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->status = 0;
      this->total_time = 0l;
      this->current_time = 0l;
      this->result = 0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0;
    }
  }

  explicit GameStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->status = 0;
      this->total_time = 0l;
      this->current_time = 0l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->status = 0;
      this->total_time = 0l;
      this->current_time = 0l;
      this->result = 0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0;
    }
  }

  // field types and members
  using _status_type =
    uint8_t;
  _status_type status;
  using _total_time_type =
    int32_t;
  _total_time_type total_time;
  using _current_time_type =
    int32_t;
  _current_time_type current_time;
  using _result_type =
    uint8_t;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__total_time(
    const int32_t & _arg)
  {
    this->total_time = _arg;
    return *this;
  }
  Type & set__current_time(
    const int32_t & _arg)
  {
    this->current_time = _arg;
    return *this;
  }
  Type & set__result(
    const uint8_t & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t PREPARATION =
    0u;
  static constexpr uint8_t SELF_CHECKING =
    1u;
  static constexpr uint8_t RUNNING =
    2u;
  static constexpr uint8_t GAME_OVER =
    3u;
  static constexpr uint8_t DRAW =
    0u;
  static constexpr uint8_t RED_WIN =
    1u;
  static constexpr uint8_t BLUE_WIN =
    2u;

  // pointer types
  using RawPtr =
    rmoss_interfaces::msg::GameStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::msg::GameStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::GameStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::GameStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::GameStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::GameStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::GameStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::GameStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::GameStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::GameStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__msg__GameStatus
    std::shared_ptr<rmoss_interfaces::msg::GameStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__msg__GameStatus
    std::shared_ptr<rmoss_interfaces::msg::GameStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GameStatus_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->total_time != other.total_time) {
      return false;
    }
    if (this->current_time != other.current_time) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const GameStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GameStatus_

// alias to use template instance with default allocator
using GameStatus =
  rmoss_interfaces::msg::GameStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GameStatus_<ContainerAllocator>::PREPARATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GameStatus_<ContainerAllocator>::SELF_CHECKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GameStatus_<ContainerAllocator>::RUNNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GameStatus_<ContainerAllocator>::GAME_OVER;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GameStatus_<ContainerAllocator>::DRAW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GameStatus_<ContainerAllocator>::RED_WIN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GameStatus_<ContainerAllocator>::BLUE_WIN;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_
