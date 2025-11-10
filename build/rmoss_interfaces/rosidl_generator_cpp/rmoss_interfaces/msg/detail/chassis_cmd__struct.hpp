// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:msg/ChassisCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__STRUCT_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.hpp"
// Member 'accel'
#include "geometry_msgs/msg/detail/accel__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__msg__ChassisCmd __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__msg__ChassisCmd __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ChassisCmd_
{
  using Type = ChassisCmd_<ContainerAllocator>;

  explicit ChassisCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init),
    twist(_init),
    accel(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->type = 1;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->tid = 0;
      this->type = 0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tid = 0;
    }
  }

  explicit ChassisCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init),
    twist(_alloc, _init),
    accel(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->type = 1;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->tid = 0;
      this->type = 0;
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
  using _type_type =
    uint8_t;
  _type_type type;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _twist_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _twist_type twist;
  using _accel_type =
    geometry_msgs::msg::Accel_<ContainerAllocator>;
  _accel_type accel;

  // setters for named parameter idiom
  Type & set__tid(
    const uint8_t & _arg)
  {
    this->tid = _arg;
    return *this;
  }
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__twist(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->twist = _arg;
    return *this;
  }
  Type & set__accel(
    const geometry_msgs::msg::Accel_<ContainerAllocator> & _arg)
  {
    this->accel = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t VELOCITY =
    1u;
  static constexpr uint8_t FOLLOW_GIMBAL =
    2u;
  static constexpr uint8_t SWING =
    3u;
  static constexpr uint8_t SPIN =
    4u;

  // pointer types
  using RawPtr =
    rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__msg__ChassisCmd
    std::shared_ptr<rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__msg__ChassisCmd
    std::shared_ptr<rmoss_interfaces::msg::ChassisCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChassisCmd_ & other) const
  {
    if (this->tid != other.tid) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->twist != other.twist) {
      return false;
    }
    if (this->accel != other.accel) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChassisCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChassisCmd_

// alias to use template instance with default allocator
using ChassisCmd =
  rmoss_interfaces::msg::ChassisCmd_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ChassisCmd_<ContainerAllocator>::VELOCITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ChassisCmd_<ContainerAllocator>::FOLLOW_GIMBAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ChassisCmd_<ContainerAllocator>::SWING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ChassisCmd_<ContainerAllocator>::SPIN;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__CHASSIS_CMD__STRUCT_HPP_
