// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rmoss_interfaces:msg/RfidStatusArray.idl
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
#include "rmoss_interfaces/msg/detail/rfid_status_array__struct.h"
#include "rmoss_interfaces/msg/detail/rfid_status_array__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "rmoss_interfaces/msg/detail/rfid_status__functions.h"
// end nested array functions include
bool rmoss_interfaces__msg__rfid_status__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * rmoss_interfaces__msg__rfid_status__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool rmoss_interfaces__msg__rfid_status_array__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
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
    assert(strncmp("rmoss_interfaces.msg._rfid_status_array.RfidStatusArray", full_classname_dest, 55) == 0);
  }
  rmoss_interfaces__msg__RfidStatusArray * ros_message = _ros_message;
  {  // robot_rfid_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_rfid_status");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'robot_rfid_status'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!rmoss_interfaces__msg__RfidStatus__Sequence__init(&(ros_message->robot_rfid_status), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create rmoss_interfaces__msg__RfidStatus__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    rmoss_interfaces__msg__RfidStatus * dest = ros_message->robot_rfid_status.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!rmoss_interfaces__msg__rfid_status__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rmoss_interfaces__msg__rfid_status_array__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RfidStatusArray */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rmoss_interfaces.msg._rfid_status_array");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RfidStatusArray");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rmoss_interfaces__msg__RfidStatusArray * ros_message = (rmoss_interfaces__msg__RfidStatusArray *)raw_ros_message;
  {  // robot_rfid_status
    PyObject * field = NULL;
    size_t size = ros_message->robot_rfid_status.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    rmoss_interfaces__msg__RfidStatus * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->robot_rfid_status.data[i]);
      PyObject * pyitem = rmoss_interfaces__msg__rfid_status__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_rfid_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
