// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rmoss_interfaces:srv/ExchangeAmmon.idl
// generated code does not contain a copyright notice

#ifndef RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__FUNCTIONS_H_
#define RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rmoss_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rmoss_interfaces/srv/detail/exchange_ammon__struct.h"

/// Initialize srv/ExchangeAmmon message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rmoss_interfaces__srv__ExchangeAmmon_Request
 * )) before or use
 * rmoss_interfaces__srv__ExchangeAmmon_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Request__init(rmoss_interfaces__srv__ExchangeAmmon_Request * msg);

/// Finalize srv/ExchangeAmmon message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
void
rmoss_interfaces__srv__ExchangeAmmon_Request__fini(rmoss_interfaces__srv__ExchangeAmmon_Request * msg);

/// Create srv/ExchangeAmmon message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rmoss_interfaces__srv__ExchangeAmmon_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
rmoss_interfaces__srv__ExchangeAmmon_Request *
rmoss_interfaces__srv__ExchangeAmmon_Request__create();

/// Destroy srv/ExchangeAmmon message.
/**
 * It calls
 * rmoss_interfaces__srv__ExchangeAmmon_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
void
rmoss_interfaces__srv__ExchangeAmmon_Request__destroy(rmoss_interfaces__srv__ExchangeAmmon_Request * msg);

/// Check for srv/ExchangeAmmon message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Request__are_equal(const rmoss_interfaces__srv__ExchangeAmmon_Request * lhs, const rmoss_interfaces__srv__ExchangeAmmon_Request * rhs);

/// Copy a srv/ExchangeAmmon message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Request__copy(
  const rmoss_interfaces__srv__ExchangeAmmon_Request * input,
  rmoss_interfaces__srv__ExchangeAmmon_Request * output);

/// Initialize array of srv/ExchangeAmmon messages.
/**
 * It allocates the memory for the number of elements and calls
 * rmoss_interfaces__srv__ExchangeAmmon_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence__init(rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence * array, size_t size);

/// Finalize array of srv/ExchangeAmmon messages.
/**
 * It calls
 * rmoss_interfaces__srv__ExchangeAmmon_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
void
rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence__fini(rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence * array);

/// Create array of srv/ExchangeAmmon messages.
/**
 * It allocates the memory for the array and calls
 * rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence *
rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence__create(size_t size);

/// Destroy array of srv/ExchangeAmmon messages.
/**
 * It calls
 * rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
void
rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence__destroy(rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence * array);

/// Check for srv/ExchangeAmmon message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence__are_equal(const rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence * lhs, const rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence * rhs);

/// Copy an array of srv/ExchangeAmmon messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence__copy(
  const rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence * input,
  rmoss_interfaces__srv__ExchangeAmmon_Request__Sequence * output);

/// Initialize srv/ExchangeAmmon message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rmoss_interfaces__srv__ExchangeAmmon_Response
 * )) before or use
 * rmoss_interfaces__srv__ExchangeAmmon_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Response__init(rmoss_interfaces__srv__ExchangeAmmon_Response * msg);

/// Finalize srv/ExchangeAmmon message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
void
rmoss_interfaces__srv__ExchangeAmmon_Response__fini(rmoss_interfaces__srv__ExchangeAmmon_Response * msg);

/// Create srv/ExchangeAmmon message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rmoss_interfaces__srv__ExchangeAmmon_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
rmoss_interfaces__srv__ExchangeAmmon_Response *
rmoss_interfaces__srv__ExchangeAmmon_Response__create();

/// Destroy srv/ExchangeAmmon message.
/**
 * It calls
 * rmoss_interfaces__srv__ExchangeAmmon_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
void
rmoss_interfaces__srv__ExchangeAmmon_Response__destroy(rmoss_interfaces__srv__ExchangeAmmon_Response * msg);

/// Check for srv/ExchangeAmmon message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Response__are_equal(const rmoss_interfaces__srv__ExchangeAmmon_Response * lhs, const rmoss_interfaces__srv__ExchangeAmmon_Response * rhs);

/// Copy a srv/ExchangeAmmon message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Response__copy(
  const rmoss_interfaces__srv__ExchangeAmmon_Response * input,
  rmoss_interfaces__srv__ExchangeAmmon_Response * output);

/// Initialize array of srv/ExchangeAmmon messages.
/**
 * It allocates the memory for the number of elements and calls
 * rmoss_interfaces__srv__ExchangeAmmon_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence__init(rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence * array, size_t size);

/// Finalize array of srv/ExchangeAmmon messages.
/**
 * It calls
 * rmoss_interfaces__srv__ExchangeAmmon_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
void
rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence__fini(rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence * array);

/// Create array of srv/ExchangeAmmon messages.
/**
 * It allocates the memory for the array and calls
 * rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence *
rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence__create(size_t size);

/// Destroy array of srv/ExchangeAmmon messages.
/**
 * It calls
 * rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
void
rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence__destroy(rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence * array);

/// Check for srv/ExchangeAmmon message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence__are_equal(const rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence * lhs, const rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence * rhs);

/// Copy an array of srv/ExchangeAmmon messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rmoss_interfaces
bool
rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence__copy(
  const rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence * input,
  rmoss_interfaces__srv__ExchangeAmmon_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RMOSS_INTERFACES__SRV__DETAIL__EXCHANGE_AMMON__FUNCTIONS_H_
