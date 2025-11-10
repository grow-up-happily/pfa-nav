# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/Gimbal.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Gimbal(type):
    """Metaclass of message 'Gimbal'."""

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
            module = import_type_support('pb_rm_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'pb_rm_interfaces.msg.Gimbal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gimbal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gimbal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gimbal
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gimbal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gimbal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Gimbal(metaclass=Metaclass_Gimbal):
    """Message class 'Gimbal'."""

    __slots__ = [
        '_pitch',
        '_yaw',
        '_pitch_min_range',
        '_pitch_max_range',
        '_yaw_min_range',
        '_yaw_max_range',
    ]

    _fields_and_field_types = {
        'pitch': 'float',
        'yaw': 'float',
        'pitch_min_range': 'float',
        'pitch_max_range': 'float',
        'yaw_min_range': 'float',
        'yaw_max_range': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pitch = kwargs.get('pitch', float())
        self.yaw = kwargs.get('yaw', float())
        self.pitch_min_range = kwargs.get('pitch_min_range', float())
        self.pitch_max_range = kwargs.get('pitch_max_range', float())
        self.yaw_min_range = kwargs.get('yaw_min_range', float())
        self.yaw_max_range = kwargs.get('yaw_max_range', float())

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
        if self.pitch != other.pitch:
            return False
        if self.yaw != other.yaw:
            return False
        if self.pitch_min_range != other.pitch_min_range:
            return False
        if self.pitch_max_range != other.pitch_max_range:
            return False
        if self.yaw_min_range != other.yaw_min_range:
            return False
        if self.yaw_max_range != other.yaw_max_range:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pitch(self):
        """Message field 'pitch'."""
        return self._pitch

    @pitch.setter
    def pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw = value

    @builtins.property
    def pitch_min_range(self):
        """Message field 'pitch_min_range'."""
        return self._pitch_min_range

    @pitch_min_range.setter
    def pitch_min_range(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_min_range' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch_min_range' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch_min_range = value

    @builtins.property
    def pitch_max_range(self):
        """Message field 'pitch_max_range'."""
        return self._pitch_max_range

    @pitch_max_range.setter
    def pitch_max_range(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_max_range' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch_max_range' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch_max_range = value

    @builtins.property
    def yaw_min_range(self):
        """Message field 'yaw_min_range'."""
        return self._yaw_min_range

    @yaw_min_range.setter
    def yaw_min_range(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_min_range' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_min_range' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_min_range = value

    @builtins.property
    def yaw_max_range(self):
        """Message field 'yaw_max_range'."""
        return self._yaw_max_range

    @yaw_max_range.setter
    def yaw_max_range(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_max_range' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_max_range' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_max_range = value
