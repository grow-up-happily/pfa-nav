// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wp_map_tools:srv/SaveWaypoints.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__STRUCT_HPP_
#define WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__wp_map_tools__srv__SaveWaypoints_Request __attribute__((deprecated))
#else
# define DEPRECATED__wp_map_tools__srv__SaveWaypoints_Request __declspec(deprecated)
#endif

namespace wp_map_tools
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SaveWaypoints_Request_
{
  using Type = SaveWaypoints_Request_<ContainerAllocator>;

  explicit SaveWaypoints_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
    }
  }

  explicit SaveWaypoints_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : filename(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
    }
  }

  // field types and members
  using _filename_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _filename_type filename;

  // setters for named parameter idiom
  Type & set__filename(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->filename = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wp_map_tools__srv__SaveWaypoints_Request
    std::shared_ptr<wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wp_map_tools__srv__SaveWaypoints_Request
    std::shared_ptr<wp_map_tools::srv::SaveWaypoints_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SaveWaypoints_Request_ & other) const
  {
    if (this->filename != other.filename) {
      return false;
    }
    return true;
  }
  bool operator!=(const SaveWaypoints_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SaveWaypoints_Request_

// alias to use template instance with default allocator
using SaveWaypoints_Request =
  wp_map_tools::srv::SaveWaypoints_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wp_map_tools


#ifndef _WIN32
# define DEPRECATED__wp_map_tools__srv__SaveWaypoints_Response __attribute__((deprecated))
#else
# define DEPRECATED__wp_map_tools__srv__SaveWaypoints_Response __declspec(deprecated)
#endif

namespace wp_map_tools
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SaveWaypoints_Response_
{
  using Type = SaveWaypoints_Response_<ContainerAllocator>;

  explicit SaveWaypoints_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  explicit SaveWaypoints_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wp_map_tools__srv__SaveWaypoints_Response
    std::shared_ptr<wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wp_map_tools__srv__SaveWaypoints_Response
    std::shared_ptr<wp_map_tools::srv::SaveWaypoints_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SaveWaypoints_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const SaveWaypoints_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SaveWaypoints_Response_

// alias to use template instance with default allocator
using SaveWaypoints_Response =
  wp_map_tools::srv::SaveWaypoints_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wp_map_tools

namespace wp_map_tools
{

namespace srv
{

struct SaveWaypoints
{
  using Request = wp_map_tools::srv::SaveWaypoints_Request;
  using Response = wp_map_tools::srv::SaveWaypoints_Response;
};

}  // namespace srv

}  // namespace wp_map_tools

#endif  // WP_MAP_TOOLS__SRV__DETAIL__SAVE_WAYPOINTS__STRUCT_HPP_
