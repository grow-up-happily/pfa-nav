# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/Models.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Models(type):
    """Metaclass of message 'Models'."""

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
                'pb_rm_interfaces.msg.Models')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__models
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__models
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__models
            cls._TYPE_SUPPORT = module.type_support_msg__msg__models
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__models

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Models(metaclass=Metaclass_Models):
    """Message class 'Models'."""

    __slots__ = [
        '_chassis',
        '_gimbal',
        '_shoot',
        '_arm',
        '_custom_controller',
    ]

    _fields_and_field_types = {
        'chassis': 'string',
        'gimbal': 'string',
        'shoot': 'string',
        'arm': 'string',
        'custom_controller': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.chassis = kwargs.get('chassis', str())
        self.gimbal = kwargs.get('gimbal', str())
        self.shoot = kwargs.get('shoot', str())
        self.arm = kwargs.get('arm', str())
        self.custom_controller = kwargs.get('custom_controller', str())

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
        if self.chassis != other.chassis:
            return False
        if self.gimbal != other.gimbal:
            return False
        if self.shoot != other.shoot:
            return False
        if self.arm != other.arm:
            return False
        if self.custom_controller != other.custom_controller:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def chassis(self):
        """Message field 'chassis'."""
        return self._chassis

    @chassis.setter
    def chassis(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'chassis' field must be of type 'str'"
        self._chassis = value

    @builtins.property
    def gimbal(self):
        """Message field 'gimbal'."""
        return self._gimbal

    @gimbal.setter
    def gimbal(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'gimbal' field must be of type 'str'"
        self._gimbal = value

    @builtins.property
    def shoot(self):
        """Message field 'shoot'."""
        return self._shoot

    @shoot.setter
    def shoot(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'shoot' field must be of type 'str'"
        self._shoot = value

    @builtins.property
    def arm(self):
        """Message field 'arm'."""
        return self._arm

    @arm.setter
    def arm(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'arm' field must be of type 'str'"
        self._arm = value

    @builtins.property
    def custom_controller(self):
        """Message field 'custom_controller'."""
        return self._custom_controller

    @custom_controller.setter
    def custom_controller(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'custom_controller' field must be of type 'str'"
        self._custom_controller = value
