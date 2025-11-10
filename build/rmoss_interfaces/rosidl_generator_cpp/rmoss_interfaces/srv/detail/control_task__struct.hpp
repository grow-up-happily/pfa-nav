// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:srv/ControlTask.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__CONTROL_TASK__STRUCT_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__CONTROL_TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__srv__ControlTask_Request __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__srv__ControlTask_Request __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ControlTask_Request_
{
  using Type = ControlTask_Request_<ContainerAllocator>;

  explicit ControlTask_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd = 0;
    }
  }

  explicit ControlTask_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd = 0;
    }
  }

  // field types and members
  using _cmd_type =
    uint8_t;
  _cmd_type cmd;

  // setters for named parameter idiom
  Type & set__cmd(
    const uint8_t & _arg)
  {
    this->cmd = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t START =
    1u;
  static constexpr uint8_t STOP =
    2u;

  // pointer types
  using RawPtr =
    rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__srv__ControlTask_Request
    std::shared_ptr<rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__srv__ControlTask_Request
    std::shared_ptr<rmoss_interfaces::srv::ControlTask_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControlTask_Request_ & other) const
  {
    if (this->cmd != other.cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControlTask_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControlTask_Request_

// alias to use template instance with default allocator
using ControlTask_Request =
  rmoss_interfaces::srv::ControlTask_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ControlTask_Request_<ContainerAllocator>::START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ControlTask_Request_<ContainerAllocator>::STOP;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace rmoss_interfaces


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__srv__ControlTask_Response __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__srv__ControlTask_Response __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ControlTask_Response_
{
  using Type = ControlTask_Response_<ContainerAllocator>;

  explicit ControlTask_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ControlTask_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__srv__ControlTask_Response
    std::shared_ptr<rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__srv__ControlTask_Response
    std::shared_ptr<rmoss_interfaces::srv::ControlTask_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControlTask_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControlTask_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControlTask_Response_

// alias to use template instance with default allocator
using ControlTask_Response =
  rmoss_interfaces::srv::ControlTask_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rmoss_interfaces

namespace rmoss_interfaces
{

namespace srv
{

struct ControlTask
{
  using Request = rmoss_interfaces::srv::ControlTask_Request;
  using Response = rmoss_interfaces::srv::ControlTask_Response;
};

}  // namespace srv

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__CONTROL_TASK__STRUCT_HPP_
