// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:msg/RfidStatusArray.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__STRUCT_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'robot_rfid_status'
#include "rmoss_interfaces/msg/detail/rfid_status__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__msg__RfidStatusArray __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__msg__RfidStatusArray __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RfidStatusArray_
{
  using Type = RfidStatusArray_<ContainerAllocator>;

  explicit RfidStatusArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit RfidStatusArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _robot_rfid_status_type =
    std::vector<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>>>;
  _robot_rfid_status_type robot_rfid_status;

  // setters for named parameter idiom
  Type & set__robot_rfid_status(
    const std::vector<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rmoss_interfaces::msg::RfidStatus_<ContainerAllocator>>> & _arg)
  {
    this->robot_rfid_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__msg__RfidStatusArray
    std::shared_ptr<rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__msg__RfidStatusArray
    std::shared_ptr<rmoss_interfaces::msg::RfidStatusArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RfidStatusArray_ & other) const
  {
    if (this->robot_rfid_status != other.robot_rfid_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const RfidStatusArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RfidStatusArray_

// alias to use template instance with default allocator
using RfidStatusArray =
  rmoss_interfaces::msg::RfidStatusArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__RFID_STATUS_ARRAY__STRUCT_HPP_
