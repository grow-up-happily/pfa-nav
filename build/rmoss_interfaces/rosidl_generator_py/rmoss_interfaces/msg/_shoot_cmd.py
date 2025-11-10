# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rmoss_interfaces:msg/ShootCmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ShootCmd(type):
    """Metaclass of message 'ShootCmd'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rmoss_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rmoss_interfaces.msg.ShootCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__shoot_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__shoot_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__shoot_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__shoot_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__shoot_cmd

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'PROJECTILE_VELOCITY__DEFAULT': 0.0,
        }

    @property
    def PROJECTILE_VELOCITY__DEFAULT(cls):
        """Return default value for message field 'projectile_velocity'."""
        return 0.0


class ShootCmd(metaclass=Metaclass_ShootCmd):
    """Message class 'ShootCmd'."""

    __slots__ = [
        '_tid',
        '_type',
        '_projectile_num',
        '_projectile_velocity',
    ]

    _fields_and_field_types = {
        'tid': 'uint8',
        'type': 'uint8',
        'projectile_num': 'uint8',
        'projectile_velocity': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.tid = kwargs.get('tid', int())
        self.type = kwargs.get('type', int())
        self.projectile_num = kwargs.get('projectile_num', int())
        self.projectile_velocity = kwargs.get(
            'projectile_velocity', ShootCmd.PROJECTILE_VELOCITY__DEFAULT)

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.tid != other.tid:
            return False
        if self.type != other.type:
            return False
        if self.projectile_num != other.projectile_num:
            return False
        if self.projectile_velocity != other.projectile_velocity:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def tid(self):
        """Message field 'tid'."""
        return self._tid

    @tid.setter
    def tid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tid' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'tid' field must be an unsigned integer in [0, 255]"
        self._tid = value

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'type' field must be an unsigned integer in [0, 255]"
        self._type = value

    @builtins.property
    def projectile_num(self):
        """Message field 'projectile_num'."""
        return self._projectile_num

    @projectile_num.setter
    def projectile_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'projectile_num' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'projectile_num' field must be an unsigned integer in [0, 255]"
        self._projectile_num = value

    @builtins.property
    def projectile_velocity(self):
        """Message field 'projectile_velocity'."""
        return self._projectile_velocity

    @projectile_velocity.setter
    def projectile_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'projectile_velocity' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'projectile_velocity' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._projectile_velocity = value
