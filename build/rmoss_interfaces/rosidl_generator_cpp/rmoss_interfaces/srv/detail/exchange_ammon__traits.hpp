// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmoss_interfaces:srv/ExchangeAmmon.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__TRAITS_HPP_
#define RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rmoss_interfaces/srv/detail/exchange_ammon__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmoss_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExchangeAmmon_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_name
  {
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
    out << ", ";
  }

  // member: ammo_amount
  {
    out << "ammo_amount: ";
    rosidl_generator_traits::value_to_yaml(msg.ammo_amount, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExchangeAmmon_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
    out << "\n";
  }

  // member: ammo_amount
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ammo_amount: ";
    rosidl_generator_traits::value_to_yaml(msg.ammo_amount, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExchangeAmmon_Request & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::srv::ExchangeAmmon_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::srv::ExchangeAmmon_Request & msg)
{
  return rmoss_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::srv::ExchangeAmmon_Request>()
{
  return "rmoss_interfaces::srv::ExchangeAmmon_Request";
}

template<>
inline const char * name<rmoss_interfaces::srv::ExchangeAmmon_Request>()
{
  return "rmoss_interfaces/srv/ExchangeAmmon_Request";
}

template<>
struct has_fixed_size<rmoss_interfaces::srv::ExchangeAmmon_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rmoss_interfaces::srv::ExchangeAmmon_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rmoss_interfaces::srv::ExchangeAmmon_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rmoss_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExchangeAmmon_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExchangeAmmon_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExchangeAmmon_Response & msg, bool use_flow_style = false)
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
  const rmoss_interfaces::srv::ExchangeAmmon_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rmoss_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rmoss_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rmoss_interfaces::srv::ExchangeAmmon_Response & msg)
{
  return rmoss_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rmoss_interfaces::srv::ExchangeAmmon_Response>()
{
  return "rmoss_interfaces::srv::ExchangeAmmon_Response";
}

template<>
inline const char * name<rmoss_interfaces::srv::ExchangeAmmon_Response>()
{
  return "rmoss_interfaces/srv/ExchangeAmmon_Response";
}

template<>
struct has_fixed_size<rmoss_interfaces::srv::ExchangeAmmon_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rmoss_interfaces::srv::ExchangeAmmon_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rmoss_interfaces::srv::ExchangeAmmon_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rmoss_interfaces::srv::ExchangeAmmon>()
{
  return "rmoss_interfaces::srv::ExchangeAmmon";
}

template<>
inline const char * name<rmoss_interfaces::srv::ExchangeAmmon>()
{
  return "rmoss_interfaces/srv/ExchangeAmmon";
}

template<>
struct has_fixed_size<rmoss_interfaces::srv::ExchangeAmmon>
  : std::integral_constant<
    bool,
    has_fixed_size<rmoss_interfaces::srv::ExchangeAmmon_Request>::value &&
    has_fixed_size<rmoss_interfaces::srv::ExchangeAmmon_Response>::value
  >
{
};

template<>
struct has_bounded_size<rmoss_interfaces::srv::ExchangeAmmon>
  : std::integral_constant<
    bool,
    has_bounded_size<rmoss_interfaces::srv::ExchangeAmmon_Request>::value &&
    has_bounded_size<rmoss_interfaces::srv::ExchangeAmmon_Response>::value
  >
{
};

template<>
struct is_service<rmoss_interfaces::srv::ExchangeAmmon>
  : std::true_type
{
};

template<>
struct is_service_request<rmoss_interfaces::srv::ExchangeAmmon_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rmoss_interfaces::srv::ExchangeAmmon_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__TRAITS_HPP_
