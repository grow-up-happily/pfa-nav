// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/GroundRobotPosition.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'hero_position'
// Member 'engineer_position'
// Member 'standard_3_position'
// Member 'standard_4_position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__GroundRobotPosition __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__GroundRobotPosition __declspec(deprecated)
#endif

namespace pb_rm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GroundRobotPosition_
{
  using Type = GroundRobotPosition_<ContainerAllocator>;

  explicit GroundRobotPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : hero_position(_init),
    engineer_position(_init),
    standard_3_position(_init),
    standard_4_position(_init)
  {
    (void)_init;
  }

  explicit GroundRobotPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : hero_position(_alloc, _init),
    engineer_position(_alloc, _init),
    standard_3_position(_alloc, _init),
    standard_4_position(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _hero_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _hero_position_type hero_position;
  using _engineer_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _engineer_position_type engineer_position;
  using _standard_3_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _standard_3_position_type standard_3_position;
  using _standard_4_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _standard_4_position_type standard_4_position;

  // setters for named parameter idiom
  Type & set__hero_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->hero_position = _arg;
    return *this;
  }
  Type & set__engineer_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->engineer_position = _arg;
    return *this;
  }
  Type & set__standard_3_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->standard_3_position = _arg;
    return *this;
  }
  Type & set__standard_4_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->standard_4_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__GroundRobotPosition
    std::shared_ptr<pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__GroundRobotPosition
    std::shared_ptr<pb_rm_interfaces::msg::GroundRobotPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GroundRobotPosition_ & other) const
  {
    if (this->hero_position != other.hero_position) {
      return false;
    }
    if (this->engineer_position != other.engineer_position) {
      return false;
    }
    if (this->standard_3_position != other.standard_3_position) {
      return false;
    }
    if (this->standard_4_position != other.standard_4_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const GroundRobotPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GroundRobotPosition_

// alias to use template instance with default allocator
using GroundRobotPosition =
  pb_rm_interfaces::msg::GroundRobotPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__STRUCT_HPP_
