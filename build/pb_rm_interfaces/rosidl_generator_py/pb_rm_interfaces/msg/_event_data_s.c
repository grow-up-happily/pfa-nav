// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pb_rm_interfaces:msg/EventData.idl
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
#include "pb_rm_interfaces/msg/detail/event_data__struct.h"
#include "pb_rm_interfaces/msg/detail/event_data__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool pb_rm_interfaces__msg__event_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
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
    assert(strncmp("pb_rm_interfaces.msg._event_data.EventData", full_classname_dest, 42) == 0);
  }
  pb_rm_interfaces__msg__EventData * ros_message = _ros_message;
  {  // non_overlapping_supply_zone
    PyObject * field = PyObject_GetAttrString(_pymsg, "non_overlapping_supply_zone");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->non_overlapping_supply_zone = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // overlapping_supply_zone
    PyObject * field = PyObject_GetAttrString(_pymsg, "overlapping_supply_zone");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->overlapping_supply_zone = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // supply_zone
    PyObject * field = PyObject_GetAttrString(_pymsg, "supply_zone");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->supply_zone = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // small_energy
    PyObject * field = PyObject_GetAttrString(_pymsg, "small_energy");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->small_energy = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // big_energy
    PyObject * field = PyObject_GetAttrString(_pymsg, "big_energy");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->big_energy = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // central_highland
    PyObject * field = PyObject_GetAttrString(_pymsg, "central_highland");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->central_highland = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // trapezoidal_highland
    PyObject * field = PyObject_GetAttrString(_pymsg, "trapezoidal_highland");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->trapezoidal_highland = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // center_gain_zone
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_gain_zone");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->center_gain_zone = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pb_rm_interfaces__msg__event_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EventData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pb_rm_interfaces.msg._event_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EventData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pb_rm_interfaces__msg__EventData * ros_message = (pb_rm_interfaces__msg__EventData *)raw_ros_message;
  {  // non_overlapping_supply_zone
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->non_overlapping_supply_zone);
    {
      int rc = PyObject_SetAttrString(_pymessage, "non_overlapping_supply_zone", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // overlapping_supply_zone
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->overlapping_supply_zone);
    {
      int rc = PyObject_SetAttrString(_pymessage, "overlapping_supply_zone", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // supply_zone
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->supply_zone);
    {
      int rc = PyObject_SetAttrString(_pymessage, "supply_zone", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // small_energy
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->small_energy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "small_energy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // big_energy
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->big_energy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "big_energy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // central_highland
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->central_highland);
    {
      int rc = PyObject_SetAttrString(_pymessage, "central_highland", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trapezoidal_highland
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->trapezoidal_highland);
    {
      int rc = PyObject_SetAttrString(_pymessage, "trapezoidal_highland", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_gain_zone
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->center_gain_zone);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_gain_zone", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
