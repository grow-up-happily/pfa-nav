// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rmoss_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
#define RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'gt_tf'
#include "geometry_msgs/msg/detail/transform__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rmoss_interfaces__msg__RobotStatus __attribute__((deprecated))
#else
# define DEPRECATED__rmoss_interfaces__msg__RobotStatus __declspec(deprecated)
#endif

namespace rmoss_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStatus_
{
  using Type = RobotStatus_<ContainerAllocator>;

  explicit RobotStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gt_tf(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->level = 0;
      this->name = "";
      this->remain_hp = 0l;
      this->max_hp = 0l;
      this->total_projectiles = 0l;
      this->used_projectiles = 0l;
      this->hit_projectiles = 0l;
    }
  }

  explicit RobotStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    gt_tf(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->level = 0;
      this->name = "";
      this->remain_hp = 0l;
      this->max_hp = 0l;
      this->total_projectiles = 0l;
      this->used_projectiles = 0l;
      this->hit_projectiles = 0l;
    }
  }

  // field types and members
  using _id_type =
    uint8_t;
  _id_type id;
  using _level_type =
    uint8_t;
  _level_type level;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _remain_hp_type =
    int32_t;
  _remain_hp_type remain_hp;
  using _max_hp_type =
    int32_t;
  _max_hp_type max_hp;
  using _total_projectiles_type =
    int32_t;
  _total_projectiles_type total_projectiles;
  using _used_projectiles_type =
    int32_t;
  _used_projectiles_type used_projectiles;
  using _hit_projectiles_type =
    int32_t;
  _hit_projectiles_type hit_projectiles;
  using _gt_tf_type =
    geometry_msgs::msg::Transform_<ContainerAllocator>;
  _gt_tf_type gt_tf;

  // setters for named parameter idiom
  Type & set__id(
    const uint8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__level(
    const uint8_t & _arg)
  {
    this->level = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__remain_hp(
    const int32_t & _arg)
  {
    this->remain_hp = _arg;
    return *this;
  }
  Type & set__max_hp(
    const int32_t & _arg)
  {
    this->max_hp = _arg;
    return *this;
  }
  Type & set__total_projectiles(
    const int32_t & _arg)
  {
    this->total_projectiles = _arg;
    return *this;
  }
  Type & set__used_projectiles(
    const int32_t & _arg)
  {
    this->used_projectiles = _arg;
    return *this;
  }
  Type & set__hit_projectiles(
    const int32_t & _arg)
  {
    this->hit_projectiles = _arg;
    return *this;
  }
  Type & set__gt_tf(
    const geometry_msgs::msg::Transform_<ContainerAllocator> & _arg)
  {
    this->gt_tf = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rmoss_interfaces::msg::RobotStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rmoss_interfaces::msg::RobotStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::RobotStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rmoss_interfaces::msg::RobotStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::RobotStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::RobotStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rmoss_interfaces::msg::RobotStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rmoss_interfaces::msg::RobotStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::RobotStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rmoss_interfaces::msg::RobotStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rmoss_interfaces__msg__RobotStatus
    std::shared_ptr<rmoss_interfaces::msg::RobotStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rmoss_interfaces__msg__RobotStatus
    std::shared_ptr<rmoss_interfaces::msg::RobotStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStatus_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->level != other.level) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->remain_hp != other.remain_hp) {
      return false;
    }
    if (this->max_hp != other.max_hp) {
      return false;
    }
    if (this->total_projectiles != other.total_projectiles) {
      return false;
    }
    if (this->used_projectiles != other.used_projectiles) {
      return false;
    }
    if (this->hit_projectiles != other.hit_projectiles) {
      return false;
    }
    if (this->gt_tf != other.gt_tf) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStatus_

// alias to use template instance with default allocator
using RobotStatus =
  rmoss_interfaces::msg::RobotStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rmoss_interfaces

#endif  // RMOSS_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
