// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/Models.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__MODELS__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__MODELS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__Models __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__Models __declspec(deprecated)
#endif

namespace pb_rm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Models_
{
  using Type = Models_<ContainerAllocator>;

  explicit Models_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->chassis = "";
      this->gimbal = "";
      this->shoot = "";
      this->arm = "";
      this->custom_controller = "";
    }
  }

  explicit Models_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : chassis(_alloc),
    gimbal(_alloc),
    shoot(_alloc),
    arm(_alloc),
    custom_controller(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->chassis = "";
      this->gimbal = "";
      this->shoot = "";
      this->arm = "";
      this->custom_controller = "";
    }
  }

  // field types and members
  using _chassis_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _chassis_type chassis;
  using _gimbal_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _gimbal_type gimbal;
  using _shoot_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _shoot_type shoot;
  using _arm_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _arm_type arm;
  using _custom_controller_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _custom_controller_type custom_controller;

  // setters for named parameter idiom
  Type & set__chassis(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->chassis = _arg;
    return *this;
  }
  Type & set__gimbal(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->gimbal = _arg;
    return *this;
  }
  Type & set__shoot(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->shoot = _arg;
    return *this;
  }
  Type & set__arm(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->arm = _arg;
    return *this;
  }
  Type & set__custom_controller(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->custom_controller = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::Models_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::Models_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::Models_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::Models_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::Models_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::Models_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::Models_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::Models_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::Models_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::Models_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__Models
    std::shared_ptr<pb_rm_interfaces::msg::Models_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__Models
    std::shared_ptr<pb_rm_interfaces::msg::Models_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Models_ & other) const
  {
    if (this->chassis != other.chassis) {
      return false;
    }
    if (this->gimbal != other.gimbal) {
      return false;
    }
    if (this->shoot != other.shoot) {
      return false;
    }
    if (this->arm != other.arm) {
      return false;
    }
    if (this->custom_controller != other.custom_controller) {
      return false;
    }
    return true;
  }
  bool operator!=(const Models_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Models_

// alias to use template instance with default allocator
using Models =
  pb_rm_interfaces::msg::Models_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__MODELS__STRUCT_HPP_
