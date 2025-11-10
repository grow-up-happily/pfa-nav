// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:msg/GimbalCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
// Member 'velocity'
#include "rmoss_interfaces/msg/detail/gimbal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__msg__GimbalCmd __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__msg__GimbalCmd __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GimbalCmd_
{
  using Type = GimbalCmd_<ContainerAllocator>;

  explicit GimbalCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init),
    velocity(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->yaw_type = 1;
      this->pitch_type = 1;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->tid = 0;
      this->yaw_type = 0;
      this->pitch_type = 0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tid = 0;
    }
  }

  explicit GimbalCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init),
    velocity(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->yaw_type = 1;
      this->pitch_type = 1;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->tid = 0;
      this->yaw_type = 0;
      this->pitch_type = 0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tid = 0;
    }
  }

  // field types and members
  using _tid_type =
    uint8_t;
  _tid_type tid;
  using _yaw_type_type =
    uint8_t;
  _yaw_type_type yaw_type;
  using _pitch_type_type =
    uint8_t;
  _pitch_type_type pitch_type;
  using _position_type =
    rmoss_interfaces::msg::Gimbal_<ContainerAllocator>;
  _position_type position;
  using _velocity_type =
    rmoss_interfaces::msg::Gimbal_<ContainerAllocator>;
  _velocity_type velocity;

  // setters for named parameter idiom
  Type & set__tid(
    const uint8_t & _arg)
  {
    this->tid = _arg;
    return *this;
  }
  Type & set__yaw_type(
    const uint8_t & _arg)
  {
    this->yaw_type = _arg;
    return *this;
  }
  Type & set__pitch_type(
    const uint8_t & _arg)
  {
    this->pitch_type = _arg;
    return *this;
  }
  Type & set__position(
    const rmoss_interfaces::msg::Gimbal_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__velocity(
    const rmoss_interfaces::msg::Gimbal_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t ABSOLUTE_ANGLE =
    1u;
  static constexpr uint8_t RELATIVE_ANGLE =
    2u;
  static constexpr uint8_t VELOCITY =
    3u;
  static constexpr uint8_t FOLLOW_CHASSIS =
    4u;

  // pointer types
  using RawPtr =
    rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__msg__GimbalCmd
    std::shared_ptr<rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__msg__GimbalCmd
    std::shared_ptr<rmoss_interfaces::msg::GimbalCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GimbalCmd_ & other) const
  {
    if (this->tid != other.tid) {
      return false;
    }
    if (this->yaw_type != other.yaw_type) {
      return false;
    }
    if (this->pitch_type != other.pitch_type) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const GimbalCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GimbalCmd_

// alias to use template instance with default allocator
using GimbalCmd =
  rmoss_interfaces::msg::GimbalCmd_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GimbalCmd_<ContainerAllocator>::ABSOLUTE_ANGLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GimbalCmd_<ContainerAllocator>::RELATIVE_ANGLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GimbalCmd_<ContainerAllocator>::VELOCITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GimbalCmd_<ContainerAllocator>::FOLLOW_CHASSIS;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_HPP_
