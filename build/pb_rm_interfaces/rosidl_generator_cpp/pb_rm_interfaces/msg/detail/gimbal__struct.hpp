// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/Gimbal.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__Gimbal __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__Gimbal __declspec(deprecated)
#endif

namespace pb_rm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Gimbal_
{
  using Type = Gimbal_<ContainerAllocator>;

  explicit Gimbal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pitch = 0.0f;
      this->yaw = 0.0f;
      this->pitch_min_range = 0.0f;
      this->pitch_max_range = 0.0f;
      this->yaw_min_range = 0.0f;
      this->yaw_max_range = 0.0f;
    }
  }

  explicit Gimbal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pitch = 0.0f;
      this->yaw = 0.0f;
      this->pitch_min_range = 0.0f;
      this->pitch_max_range = 0.0f;
      this->yaw_min_range = 0.0f;
      this->yaw_max_range = 0.0f;
    }
  }

  // field types and members
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _pitch_min_range_type =
    float;
  _pitch_min_range_type pitch_min_range;
  using _pitch_max_range_type =
    float;
  _pitch_max_range_type pitch_max_range;
  using _yaw_min_range_type =
    float;
  _yaw_min_range_type yaw_min_range;
  using _yaw_max_range_type =
    float;
  _yaw_max_range_type yaw_max_range;

  // setters for named parameter idiom
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__pitch_min_range(
    const float & _arg)
  {
    this->pitch_min_range = _arg;
    return *this;
  }
  Type & set__pitch_max_range(
    const float & _arg)
  {
    this->pitch_max_range = _arg;
    return *this;
  }
  Type & set__yaw_min_range(
    const float & _arg)
  {
    this->yaw_min_range = _arg;
    return *this;
  }
  Type & set__yaw_max_range(
    const float & _arg)
  {
    this->yaw_max_range = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::Gimbal_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::Gimbal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::Gimbal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::Gimbal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::Gimbal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::Gimbal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::Gimbal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::Gimbal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::Gimbal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::Gimbal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__Gimbal
    std::shared_ptr<pb_rm_interfaces::msg::Gimbal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__Gimbal
    std::shared_ptr<pb_rm_interfaces::msg::Gimbal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gimbal_ & other) const
  {
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->pitch_min_range != other.pitch_min_range) {
      return false;
    }
    if (this->pitch_max_range != other.pitch_max_range) {
      return false;
    }
    if (this->yaw_min_range != other.yaw_min_range) {
      return false;
    }
    if (this->yaw_max_range != other.yaw_max_range) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gimbal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gimbal_

// alias to use template instance with default allocator
using Gimbal =
  pb_rm_interfaces::msg::Gimbal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GIMBAL__STRUCT_HPP_
