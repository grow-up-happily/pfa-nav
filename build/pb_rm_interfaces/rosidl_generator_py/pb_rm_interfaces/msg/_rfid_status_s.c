// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "pb_rm_interfaces/msg/detail/rfid_status__struct.h"
#include "pb_rm_interfaces/msg/detail/rfid_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool pb_rm_interfaces__msg__rfid_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("pb_rm_interfaces.msg._rfid_status.RfidStatus", full_classname_dest, 44) == 0);
  }
  pb_rm_interfaces__msg__RfidStatus * ros_message = _ros_message;
  {  // base_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "base_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->base_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // central_highland_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "central_highland_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->central_highland_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enemy_central_highland_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_central_highland_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->enemy_central_highland_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_trapezoidal_highland_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_trapezoidal_highland_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_trapezoidal_highland_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enemy_trapezoidal_highland_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_trapezoidal_highland_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->enemy_trapezoidal_highland_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_fly_ramp_front_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_fly_ramp_front_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_fly_ramp_front_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_fly_ramp_back_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_fly_ramp_back_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_fly_ramp_back_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enemy_fly_ramp_front_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_fly_ramp_front_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->enemy_fly_ramp_front_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enemy_fly_ramp_back_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_fly_ramp_back_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->enemy_fly_ramp_back_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_central_highland_lower_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_central_highland_lower_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_central_highland_lower_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_central_highland_upper_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_central_highland_upper_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_central_highland_upper_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enemy_central_highland_lower_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_central_highland_lower_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->enemy_central_highland_lower_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enemy_central_highland_upper_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_central_highland_upper_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->enemy_central_highland_upper_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_highway_lower_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_highway_lower_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_highway_lower_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_highway_upper_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_highway_upper_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_highway_upper_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enemy_highway_lower_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_highway_lower_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->enemy_highway_lower_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enemy_highway_upper_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_highway_upper_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->enemy_highway_upper_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_fortress_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_fortress_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_fortress_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_outpost_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_outpost_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_outpost_gain_point = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_supply_zone_non_exchange
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_supply_zone_non_exchange");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_supply_zone_non_exchange = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_supply_zone_exchange
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_supply_zone_exchange");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_supply_zone_exchange = (Py_True == field);
    Py_DECREF(field);
  }
  {  // friendly_big_resource_island
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_big_resource_island");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->friendly_big_resource_island = (Py_True == field);
    Py_DECREF(field);
  }
  {  // enemy_big_resource_island
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_big_resource_island");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->enemy_big_resource_island = (Py_True == field);
    Py_DECREF(field);
  }
  {  // center_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_gain_point");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->center_gain_point = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pb_rm_interfaces__msg__rfid_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RfidStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pb_rm_interfaces.msg._rfid_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RfidStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pb_rm_interfaces__msg__RfidStatus * ros_message = (pb_rm_interfaces__msg__RfidStatus *)raw_ros_message;
  {  // base_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->base_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "base_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // central_highland_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->central_highland_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "central_highland_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_central_highland_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->enemy_central_highland_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_central_highland_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_trapezoidal_highland_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_trapezoidal_highland_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_trapezoidal_highland_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_trapezoidal_highland_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->enemy_trapezoidal_highland_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_trapezoidal_highland_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_fly_ramp_front_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_fly_ramp_front_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_fly_ramp_front_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_fly_ramp_back_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_fly_ramp_back_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_fly_ramp_back_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_fly_ramp_front_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->enemy_fly_ramp_front_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_fly_ramp_front_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_fly_ramp_back_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->enemy_fly_ramp_back_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_fly_ramp_back_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_central_highland_lower_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_central_highland_lower_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_central_highland_lower_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_central_highland_upper_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_central_highland_upper_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_central_highland_upper_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_central_highland_lower_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->enemy_central_highland_lower_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_central_highland_lower_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_central_highland_upper_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->enemy_central_highland_upper_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_central_highland_upper_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_highway_lower_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_highway_lower_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_highway_lower_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_highway_upper_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_highway_upper_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_highway_upper_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_highway_lower_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->enemy_highway_lower_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_highway_lower_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_highway_upper_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->enemy_highway_upper_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_highway_upper_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_fortress_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_fortress_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_fortress_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_outpost_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_outpost_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_outpost_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_supply_zone_non_exchange
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_supply_zone_non_exchange ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_supply_zone_non_exchange", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_supply_zone_exchange
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_supply_zone_exchange ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_supply_zone_exchange", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_big_resource_island
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->friendly_big_resource_island ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_big_resource_island", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_big_resource_island
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->enemy_big_resource_island ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_big_resource_island", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_gain_point
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->center_gain_point ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
