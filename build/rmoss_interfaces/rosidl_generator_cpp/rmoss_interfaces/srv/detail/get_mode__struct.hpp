// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:srv/GetMode.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__GET_MODE__STRUCT_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__GET_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__srv__GetMode_Request __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__srv__GetMode_Request __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetMode_Request_
{
  using Type = GetMode_Request_<ContainerAllocator>;

  explicit GetMode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetMode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__srv__GetMode_Request
    std::shared_ptr<rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__srv__GetMode_Request
    std::shared_ptr<rmoss_interfaces::srv::GetMode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetMode_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetMode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetMode_Request_

// alias to use template instance with default allocator
using GetMode_Request =
  rmoss_interfaces::srv::GetMode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rmoss_interfaces


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__srv__GetMode_Response __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__srv__GetMode_Response __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetMode_Response_
{
  using Type = GetMode_Response_<ContainerAllocator>;

  explicit GetMode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0l;
    }
  }

  explicit GetMode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0l;
    }
  }

  // field types and members
  using _mode_type =
    int32_t;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__mode(
    const int32_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__srv__GetMode_Response
    std::shared_ptr<rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__srv__GetMode_Response
    std::shared_ptr<rmoss_interfaces::srv::GetMode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetMode_Response_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetMode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetMode_Response_

// alias to use template instance with default allocator
using GetMode_Response =
  rmoss_interfaces::srv::GetMode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rmoss_interfaces

namespace rmoss_interfaces
{

namespace srv
{

struct GetMode
{
  using Request = rmoss_interfaces::srv::GetMode_Request;
  using Response = rmoss_interfaces::srv::GetMode_Response;
};

}  // namespace srv

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__GET_MODE__STRUCT_HPP_
