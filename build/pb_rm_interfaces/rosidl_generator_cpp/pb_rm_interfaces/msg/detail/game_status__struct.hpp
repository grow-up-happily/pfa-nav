// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__GameStatus __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__GameStatus __declspec(deprecated)
#endif

namespace pb_rm_interfaces
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
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->game_progress = 0;
      this->stage_remain_time = 0l;
    }
  }

  explicit GameStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->game_progress = 0;
      this->stage_remain_time = 0l;
    }
  }

  // field types and members
  using _game_progress_type =
    uint8_t;
  _game_progress_type game_progress;
  using _stage_remain_time_type =
    int32_t;
  _stage_remain_time_type stage_remain_time;

  // setters for named parameter idiom
  Type & set__game_progress(
    const uint8_t & _arg)
  {
    this->game_progress = _arg;
    return *this;
  }
  Type & set__stage_remain_time(
    const int32_t & _arg)
  {
    this->stage_remain_time = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t NOT_START =
    0u;
  static constexpr uint8_t PREPARATION =
    1u;
  static constexpr uint8_t SELF_CHECKING =
    2u;
  static constexpr uint8_t COUNT_DOWN =
    3u;
  static constexpr uint8_t RUNNING =
    4u;
  static constexpr uint8_t GAME_OVER =
    5u;

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::GameStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::GameStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::GameStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::GameStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::GameStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::GameStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::GameStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::GameStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::GameStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::GameStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__GameStatus
    std::shared_ptr<pb_rm_interfaces::msg::GameStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__GameStatus
    std::shared_ptr<pb_rm_interfaces::msg::GameStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GameStatus_ & other) const
  {
    if (this->game_progress != other.game_progress) {
      return false;
    }
    if (this->stage_remain_time != other.stage_remain_time) {
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
  pb_rm_interfaces::msg::GameStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GameStatus_<ContainerAllocator>::NOT_START;
#endif  // __cplusplus < 201703L
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
constexpr uint8_t GameStatus_<ContainerAllocator>::COUNT_DOWN;
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

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_
