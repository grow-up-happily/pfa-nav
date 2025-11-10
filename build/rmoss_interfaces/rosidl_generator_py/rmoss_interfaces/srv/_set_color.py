# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rmoss_interfaces:srv/SetColor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetColor_Request(type):
    """Metaclass of message 'SetColor_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'RED': 1,
        'BLUE': 2,
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
                'rmoss_interfaces.srv.SetColor_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_color__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_color__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_color__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_color__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_color__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'RED': cls.__constants['RED'],
            'BLUE': cls.__constants['BLUE'],
        }

    @property
    def RED(self):
        """Message constant 'RED'."""
        return Metaclass_SetColor_Request.__constants['RED']

    @property
    def BLUE(self):
        """Message constant 'BLUE'."""
        return Metaclass_SetColor_Request.__constants['BLUE']


class SetColor_Request(metaclass=Metaclass_SetColor_Request):
    """
    Message class 'SetColor_Request'.

    Constants:
      RED
      BLUE
    """

    __slots__ = [
        '_color',
    ]

    _fields_and_field_types = {
        'color': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.color = kwargs.get('color', int())

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
        if self.color != other.color:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def color(self):
        """Message field 'color'."""
        return self._color

    @color.setter
    def color(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'color' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'color' field must be an unsigned integer in [0, 255]"
        self._color = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetColor_Response(type):
    """Metaclass of message 'SetColor_Response'."""

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
                'rmoss_interfaces.srv.SetColor_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_color__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_color__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_color__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_color__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_color__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetColor_Response(metaclass=Metaclass_SetColor_Response):
    """Message class 'SetColor_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

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
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_SetColor(type):
    """Metaclass of service 'SetColor'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rmoss_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rmoss_interfaces.srv.SetColor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_color

            from rmoss_interfaces.srv import _set_color
            if _set_color.Metaclass_SetColor_Request._TYPE_SUPPORT is None:
                _set_color.Metaclass_SetColor_Request.__import_type_support__()
            if _set_color.Metaclass_SetColor_Response._TYPE_SUPPORT is None:
                _set_color.Metaclass_SetColor_Response.__import_type_support__()


class SetColor(metaclass=Metaclass_SetColor):
    from rmoss_interfaces.srv._set_color import SetColor_Request as Request
    from rmoss_interfaces.srv._set_color import SetColor_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
