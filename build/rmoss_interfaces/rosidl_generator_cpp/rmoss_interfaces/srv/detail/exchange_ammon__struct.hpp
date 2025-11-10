// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:srv/ExchangeAmmon.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__STRUCT_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__srv__ExchangeAmmon_Request __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__srv__ExchangeAmmon_Request __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExchangeAmmon_Request_
{
  using Type = ExchangeAmmon_Request_<ContainerAllocator>;

  explicit ExchangeAmmon_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
      this->ammo_amount = 0l;
    }
  }

  explicit ExchangeAmmon_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
      this->ammo_amount = 0l;
    }
  }

  // field types and members
  using _robot_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_name_type robot_name;
  using _ammo_amount_type =
    int32_t;
  _ammo_amount_type ammo_amount;

  // setters for named parameter idiom
  Type & set__robot_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_name = _arg;
    return *this;
  }
  Type & set__ammo_amount(
    const int32_t & _arg)
  {
    this->ammo_amount = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__srv__ExchangeAmmon_Request
    std::shared_ptr<rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__srv__ExchangeAmmon_Request
    std::shared_ptr<rmoss_interfaces::srv::ExchangeAmmon_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExchangeAmmon_Request_ & other) const
  {
    if (this->robot_name != other.robot_name) {
      return false;
    }
    if (this->ammo_amount != other.ammo_amount) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExchangeAmmon_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExchangeAmmon_Request_

// alias to use template instance with default allocator
using ExchangeAmmon_Request =
  rmoss_interfaces::srv::ExchangeAmmon_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rmoss_interfaces


#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__srv__ExchangeAmmon_Response __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__srv__ExchangeAmmon_Response __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExchangeAmmon_Response_
{
  using Type = ExchangeAmmon_Response_<ContainerAllocator>;

  explicit ExchangeAmmon_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit ExchangeAmmon_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__srv__ExchangeAmmon_Response
    std::shared_ptr<rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__srv__ExchangeAmmon_Response
    std::shared_ptr<rmoss_interfaces::srv::ExchangeAmmon_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExchangeAmmon_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExchangeAmmon_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExchangeAmmon_Response_

// alias to use template instance with default allocator
using ExchangeAmmon_Response =
  rmoss_interfaces::srv::ExchangeAmmon_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rmoss_interfaces

namespace rmoss_interfaces
{

namespace srv
{

struct ExchangeAmmon
{
  using Request = rmoss_interfaces::srv::ExchangeAmmon_Request;
  using Response = rmoss_interfaces::srv::ExchangeAmmon_Response;
};

}  // namespace srv

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__STRUCT_HPP_
