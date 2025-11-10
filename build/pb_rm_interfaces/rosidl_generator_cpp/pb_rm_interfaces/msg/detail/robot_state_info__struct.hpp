// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/RobotStateInfo.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'models'
#include "pb_rm_interfaces/msg/detail/models__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__RobotStateInfo __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__RobotStateInfo __declspec(deprecated)
#endif

namespace pb_rm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStateInfo_
{
  using Type = RobotStateInfo_<ContainerAllocator>;

  explicit RobotStateInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    models(_init)
  {
    (void)_init;
  }

  explicit RobotStateInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    models(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _models_type =
    pb_rm_interfaces::msg::Models_<ContainerAllocator>;
  _models_type models;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__models(
    const pb_rm_interfaces::msg::Models_<ContainerAllocator> & _arg)
  {
    this->models = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__RobotStateInfo
    std::shared_ptr<pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__RobotStateInfo
    std::shared_ptr<pb_rm_interfaces::msg::RobotStateInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStateInfo_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->models != other.models) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStateInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStateInfo_

// alias to use template instance with default allocator
using RobotStateInfo =
  pb_rm_interfaces::msg::RobotStateInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATE_INFO__STRUCT_HPP_
