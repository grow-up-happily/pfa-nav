// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rmoss_interfaces:msg/ShootCmd.idl
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
#include "rmoss_interfaces/msg/detail/shoot_cmd__struct.h"
#include "rmoss_interfaces/msg/detail/shoot_cmd__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rmoss_interfaces__msg__shoot_cmd__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("rmoss_interfaces.msg._shoot_cmd.ShootCmd", full_classname_dest, 40) == 0);
  }
  rmoss_interfaces__msg__ShootCmd * ros_message = _ros_message;
  {  // tid
    PyObject * field = PyObject_GetAttrString(_pymsg, "tid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // type
    PyObject * field = PyObject_GetAttrString(_pymsg, "type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // projectile_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "projectile_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->projectile_num = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // projectile_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "projectile_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->projectile_velocity = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rmoss_interfaces__msg__shoot_cmd__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ShootCmd */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rmoss_interfaces.msg._shoot_cmd");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ShootCmd");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rmoss_interfaces__msg__ShootCmd * ros_message = (rmoss_interfaces__msg__ShootCmd *)raw_ros_message;
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
  {  // type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // projectile_num
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->projectile_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "projectile_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // projectile_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->projectile_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "projectile_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
