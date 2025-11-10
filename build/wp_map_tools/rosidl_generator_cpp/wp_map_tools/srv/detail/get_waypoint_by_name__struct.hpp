// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wp_map_tools:srv/GetWaypointByName.idl
// generated code does not contain a copyright notice

#ifndef WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__STRUCT_HPP_
#define WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__wp_map_tools__srv__GetWaypointByName_Request __attribute__((deprecated))
#else
# define DEPRECATED__wp_map_tools__srv__GetWaypointByName_Request __declspec(deprecated)
#endif

namespace wp_map_tools
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetWaypointByName_Request_
{
  using Type = GetWaypointByName_Request_<ContainerAllocator>;

  explicit GetWaypointByName_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit GetWaypointByName_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wp_map_tools__srv__GetWaypointByName_Request
    std::shared_ptr<wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wp_map_tools__srv__GetWaypointByName_Request
    std::shared_ptr<wp_map_tools::srv::GetWaypointByName_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetWaypointByName_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetWaypointByName_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetWaypointByName_Request_

// alias to use template instance with default allocator
using GetWaypointByName_Request =
  wp_map_tools::srv::GetWaypointByName_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wp_map_tools


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wp_map_tools__srv__GetWaypointByName_Response __attribute__((deprecated))
#else
# define DEPRECATED__wp_map_tools__srv__GetWaypointByName_Response __declspec(deprecated)
#endif

namespace wp_map_tools
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetWaypointByName_Response_
{
  using Type = GetWaypointByName_Response_<ContainerAllocator>;

  explicit GetWaypointByName_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit GetWaypointByName_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wp_map_tools__srv__GetWaypointByName_Response
    std::shared_ptr<wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wp_map_tools__srv__GetWaypointByName_Response
    std::shared_ptr<wp_map_tools::srv::GetWaypointByName_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetWaypointByName_Response_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetWaypointByName_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetWaypointByName_Response_

// alias to use template instance with default allocator
using GetWaypointByName_Response =
  wp_map_tools::srv::GetWaypointByName_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wp_map_tools

namespace wp_map_tools
{

namespace srv
{

struct GetWaypointByName
{
  using Request = wp_map_tools::srv::GetWaypointByName_Request;
  using Response = wp_map_tools::srv::GetWaypointByName_Response;
};

}  // namespace srv

}  // namespace wp_map_tools

#endif  // WP_MAP_TOOLS__SRV__DETAIL__GET_WAYPOINT_BY_NAME__STRUCT_HPP_
