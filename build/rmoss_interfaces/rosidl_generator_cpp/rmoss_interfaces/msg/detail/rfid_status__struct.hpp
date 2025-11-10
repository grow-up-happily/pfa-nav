// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__msg__RfidStatus __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__msg__RfidStatus __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RfidStatus_
{
  using Type = RfidStatus_<ContainerAllocator>;

  explicit RfidStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
      this->supplier_area_is_triggered = false;
      this->center_area_is_triggered = false;
    }
  }

  explicit RfidStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
      this->supplier_area_is_triggered = false;
      this->center_area_is_triggered = false;
    }
  }

  // field types and members
  using _robot_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_name_type robot_name;
  using _supplier_area_is_triggered_type =
    bool;
  _supplier_area_is_triggered_type supplier_area_is_triggered;
  using _center_area_is_triggered_type =
    bool;
  _center_area_is_triggered_type center_area_is_triggered;

  // setters for named parameter idiom
  Type & set__robot_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_name = _arg;
    return *this;
  }
  Type & set__supplier_area_is_triggered(
    const bool & _arg)
  {
    this->supplier_area_is_triggered = _arg;
    return *this;
  }
  Type & set__center_area_is_triggered(
    const bool & _arg)
  {
    this->center_area_is_triggered = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::msg::RfidStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::msg::RfidStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__msg__RfidStatus
    std::shared_ptr<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__msg__RfidStatus
    std::shared_ptr<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RfidStatus_ & other) const
  {
    if (this->robot_name != other.robot_name) {
      return false;
    }
    if (this->supplier_area_is_triggered != other.supplier_area_is_triggered) {
      return false;
    }
    if (this->center_area_is_triggered != other.center_area_is_triggered) {
      return false;
    }
    return true;
  }
  bool operator!=(const RfidStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RfidStatus_

// alias to use template instance with default allocator
using RfidStatus =
  rmoss_interfaces::msg::RfidStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_HPP_
