// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:srv/GetCameraInfo.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__GET_CAMERA_INFO__TRAITS_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__GET_CAMERA_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/srv/detail/get_camera_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmoss_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetCameraInfo_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetCameraInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetCameraInfo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rmoss_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rmoss_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rmoss_interfaces::srv::GetCameraInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::srv::GetCameraInfo_Request & msg)
{
  return rmoss_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::srv::GetCameraInfo_Request>()
{
  return "rmoss_interfaces::srv::GetCameraInfo_Request";
}

template<>
inline const char * name<rmoss_interfaces::srv::GetCameraInfo_Request>()
{
  return "rmoss_interfaces/srv/GetCameraInfo_Request";
}

template<>
struct has_fixed_size<rmoss_interfaces::srv::GetCameraInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rmoss_interfaces::srv::GetCameraInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rmoss_interfaces::srv::GetCameraInfo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__traits.hpp"

namespace rmoss_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetCameraInfo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: camera_info
  {
    out << "camera_info: ";
    to_flow_style_yaml(msg.camera_info, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetCameraInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: camera_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_info:\n";
    to_block_style_yaml(msg.camera_info, out, indentation + 2);
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetCameraInfo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rmoss_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rmoss_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rmoss_interfaces::srv::GetCameraInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::srv::GetCameraInfo_Response & msg)
{
  return rmoss_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::srv::GetCameraInfo_Response>()
{
  return "rmoss_interfaces::srv::GetCameraInfo_Response";
}

template<>
inline const char * name<rmoss_interfaces::srv::GetCameraInfo_Response>()
{
  return "rmoss_interfaces/srv/GetCameraInfo_Response";
}

template<>
struct has_fixed_size<rmoss_interfaces::srv::GetCameraInfo_Response>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::CameraInfo>::value> {};

template<>
struct has_bounded_size<rmoss_interfaces::srv::GetCameraInfo_Response>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::CameraInfo>::value> {};

template<>
struct is_message<rmoss_interfaces::srv::GetCameraInfo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rmoss_interfaces::srv::GetCameraInfo>()
{
  return "rmoss_interfaces::srv::GetCameraInfo";
}

template<>
inline const char * name<rmoss_interfaces::srv::GetCameraInfo>()
{
  return "rmoss_interfaces/srv/GetCameraInfo";
}

template<>
struct has_fixed_size<rmoss_interfaces::srv::GetCameraInfo>
  : std::integral_constant<
    bool,
    has_fixed_size<rmoss_interfaces::srv::GetCameraInfo_Request>::value &&
    has_fixed_size<rmoss_interfaces::srv::GetCameraInfo_Response>::value
  >
{
};

template<>
struct has_bounded_size<rmoss_interfaces::srv::GetCameraInfo>
  : std::integral_constant<
    bool,
    has_bounded_size<rmoss_interfaces::srv::GetCameraInfo_Request>::value &&
    has_bounded_size<rmoss_interfaces::srv::GetCameraInfo_Response>::value
  >
{
};

template<>
struct is_service<rmoss_interfaces::srv::GetCameraInfo>
  : std::true_type
{
};

template<>
struct is_service_request<rmoss_interfaces::srv::GetCameraInfo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rmoss_interfaces::srv::GetCameraInfo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__SRV__DETAIL__GET_CAMERA_INFO__TRAITS_HPP_
