// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rmoss_interfaces:msg/GimbalCmd.idl
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
#include "rmoss_interfaces/msg/detail/gimbal_cmd__struct.h"
#include "rmoss_interfaces/msg/detail/gimbal_cmd__functions.h"

bool rmoss_interfaces__msg__gimbal__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * rmoss_interfaces__msg__gimbal__convert_to_py(void * raw_ros_message);
bool rmoss_interfaces__msg__gimbal__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * rmoss_interfaces__msg__gimbal__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool rmoss_interfaces__msg__gimbal_cmd__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("rmoss_interfaces.msg._gimbal_cmd.GimbalCmd", full_classname_dest, 42) == 0);
  }
  rmoss_interfaces__msg__GimbalCmd * ros_message = _ros_message;
  {  // tid
    PyObject * field = PyObject_GetAttrString(_pymsg, "tid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // yaw_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->yaw_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pitch_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pitch_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // position
    PyObject * field = PyObject_GetAttrString(_pymsg, "position");
    if (!field) {
      return false;
    }
    if (!rmoss_interfaces__msg__gimbal__convert_from_py(field, &ros_message->position)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "velocity");
    if (!field) {
      return false;
    }
    if (!rmoss_interfaces__msg__gimbal__convert_from_py(field, &ros_message->velocity)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rmoss_interfaces__msg__gimbal_cmd__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GimbalCmd */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rmoss_interfaces.msg._gimbal_cmd");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GimbalCmd");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rmoss_interfaces__msg__GimbalCmd * ros_message = (rmoss_interfaces__msg__GimbalCmd *)raw_ros_message;
  {  // tid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->tid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->yaw_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pitch_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // position
    PyObject * field = NULL;
    field = rmoss_interfaces__msg__gimbal__convert_to_py(&ros_message->position);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // velocity
    PyObject * field = NULL;
    field = rmoss_interfaces__msg__gimbal__convert_to_py(&ros_message->velocity);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
