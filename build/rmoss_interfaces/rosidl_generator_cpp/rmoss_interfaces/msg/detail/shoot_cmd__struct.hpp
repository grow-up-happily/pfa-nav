// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:msg/ShootCmd.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__STRUCT_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__msg__ShootCmd __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__msg__ShootCmd __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ShootCmd_
{
  using Type = ShootCmd_<ContainerAllocator>;

  explicit ShootCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->projectile_velocity = 0.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->tid = 0;
      this->type = 0;
      this->projectile_num = 0;
      this->projectile_velocity = 0.0f;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tid = 0;
      this->type = 0;
      this->projectile_num = 0;
    }
  }

  explicit ShootCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->projectile_velocity = 0.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->tid = 0;
      this->type = 0;
      this->projectile_num = 0;
      this->projectile_velocity = 0.0f;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tid = 0;
      this->type = 0;
      this->projectile_num = 0;
    }
  }

  // field types and members
  using _tid_type =
    uint8_t;
  _tid_type tid;
  using _type_type =
    uint8_t;
  _type_type type;
  using _projectile_num_type =
    uint8_t;
  _projectile_num_type projectile_num;
  using _projectile_velocity_type =
    float;
  _projectile_velocity_type projectile_velocity;

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
  Type & set__projectile_num(
    const uint8_t & _arg)
  {
    this->projectile_num = _arg;
    return *this;
  }
  Type & set__projectile_velocity(
    const float & _arg)
  {
    this->projectile_velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::msg::ShootCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::msg::ShootCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::ShootCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::ShootCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::ShootCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::ShootCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::ShootCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::ShootCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::ShootCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::ShootCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__msg__ShootCmd
    std::shared_ptr<rmoss_interfaces::msg::ShootCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__msg__ShootCmd
    std::shared_ptr<rmoss_interfaces::msg::ShootCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ShootCmd_ & other) const
  {
    if (this->tid != other.tid) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->projectile_num != other.projectile_num) {
      return false;
    }
    if (this->projectile_velocity != other.projectile_velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const ShootCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ShootCmd_

// alias to use template instance with default allocator
using ShootCmd =
  rmoss_interfaces::msg::ShootCmd_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__SHOOT_CMD__STRUCT_HPP_
