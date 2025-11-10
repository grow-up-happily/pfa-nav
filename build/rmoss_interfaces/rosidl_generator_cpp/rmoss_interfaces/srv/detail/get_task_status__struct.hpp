// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:srv/GetTaskStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__GET_TASK_STATUS__STRUCT_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__GET_TASK_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__srv__GetTaskStatus_Request __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__srv__GetTaskStatus_Request __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetTaskStatus_Request_
{
  using Type = GetTaskStatus_Request_<ContainerAllocator>;

  explicit GetTaskStatus_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetTaskStatus_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__srv__GetTaskStatus_Request
    std::shared_ptr<rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__srv__GetTaskStatus_Request
    std::shared_ptr<rmoss_interfaces::srv::GetTaskStatus_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetTaskStatus_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetTaskStatus_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetTaskStatus_Request_

// alias to use template instance with default allocator
using GetTaskStatus_Request =
  rmoss_interfaces::srv::GetTaskStatus_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rmoss_interfaces


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__srv__GetTaskStatus_Response __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__srv__GetTaskStatus_Response __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetTaskStatus_Response_
{
  using Type = GetTaskStatus_Response_<ContainerAllocator>;

  explicit GetTaskStatus_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit GetTaskStatus_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    uint8_t;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t RUNNING =
    1u;
  static constexpr uint8_t IDLE =
    2u;
  // guard against 'ERROR' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(ERROR)
#    pragma push_macro("ERROR")
#    undef ERROR
#  endif
#endif
  static constexpr uint8_t ERROR =
    3u;
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("ERROR")
#endif

  // pointer types
  using RawPtr =
    rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__srv__GetTaskStatus_Response
    std::shared_ptr<rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__srv__GetTaskStatus_Response
    std::shared_ptr<rmoss_interfaces::srv::GetTaskStatus_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetTaskStatus_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetTaskStatus_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetTaskStatus_Response_

// alias to use template instance with default allocator
using GetTaskStatus_Response =
  rmoss_interfaces::srv::GetTaskStatus_Response_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GetTaskStatus_Response_<ContainerAllocator>::RUNNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GetTaskStatus_Response_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
// guard against 'ERROR' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(ERROR)
#    pragma push_macro("ERROR")
#    undef ERROR
#  endif
#endif
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GetTaskStatus_Response_<ContainerAllocator>::ERROR;
#endif  // __cplusplus < 201703L
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("ERROR")
#endif

}  // namespace srv

}  // namespace rmoss_interfaces

namespace rmoss_interfaces
{

namespace srv
{

struct GetTaskStatus
{
  using Request = rmoss_interfaces::srv::GetTaskStatus_Request;
  using Response = rmoss_interfaces::srv::GetTaskStatus_Response;
};

}  // namespace srv

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__GET_TASK_STATUS__STRUCT_HPP_
