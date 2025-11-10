# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rmoss_interfaces:msg/GameStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GameStatus(type):
    """Metaclass of message 'GameStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'PREPARATION': 0,
        'SELF_CHECKING': 1,
        'RUNNING': 2,
        'GAME_OVER': 3,
        'DRAW': 0,
        'RED_WIN': 1,
        'BLUE_WIN': 2,
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
                'rmoss_interfaces.msg.GameStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__game_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__game_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__game_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__game_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__game_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'PREPARATION': cls.__constants['PREPARATION'],
            'SELF_CHECKING': cls.__constants['SELF_CHECKING'],
            'RUNNING': cls.__constants['RUNNING'],
            'GAME_OVER': cls.__constants['GAME_OVER'],
            'DRAW': cls.__constants['DRAW'],
            'RED_WIN': cls.__constants['RED_WIN'],
            'BLUE_WIN': cls.__constants['BLUE_WIN'],
            'STATUS__DEFAULT': 0,
            'TOTAL_TIME__DEFAULT': 0,
            'CURRENT_TIME__DEFAULT': 0,
        }

    @property
    def PREPARATION(self):
        """Message constant 'PREPARATION'."""
        return Metaclass_GameStatus.__constants['PREPARATION']

    @property
    def SELF_CHECKING(self):
        """Message constant 'SELF_CHECKING'."""
        return Metaclass_GameStatus.__constants['SELF_CHECKING']

    @property
    def RUNNING(self):
        """Message constant 'RUNNING'."""
        return Metaclass_GameStatus.__constants['RUNNING']

    @property
    def GAME_OVER(self):
        """Message constant 'GAME_OVER'."""
        return Metaclass_GameStatus.__constants['GAME_OVER']

    @property
    def DRAW(self):
        """Message constant 'DRAW'."""
        return Metaclass_GameStatus.__constants['DRAW']

    @property
    def RED_WIN(self):
        """Message constant 'RED_WIN'."""
        return Metaclass_GameStatus.__constants['RED_WIN']

    @property
    def BLUE_WIN(self):
        """Message constant 'BLUE_WIN'."""
        return Metaclass_GameStatus.__constants['BLUE_WIN']

    @property
    def STATUS__DEFAULT(cls):
        """Return default value for message field 'status'."""
        return 0

    @property
    def TOTAL_TIME__DEFAULT(cls):
        """Return default value for message field 'total_time'."""
        return 0

    @property
    def CURRENT_TIME__DEFAULT(cls):
        """Return default value for message field 'current_time'."""
        return 0


class GameStatus(metaclass=Metaclass_GameStatus):
    """
    Message class 'GameStatus'.

    Constants:
      PREPARATION
      SELF_CHECKING
      RUNNING
      GAME_OVER
      DRAW
      RED_WIN
      BLUE_WIN
    """

    __slots__ = [
        '_status',
        '_total_time',
        '_current_time',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'uint8',
        'total_time': 'int32',
        'current_time': 'int32',
        'result': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get(
            'status', GameStatus.STATUS__DEFAULT)
        self.total_time = kwargs.get(
            'total_time', GameStatus.TOTAL_TIME__DEFAULT)
        self.current_time = kwargs.get(
            'current_time', GameStatus.CURRENT_TIME__DEFAULT)
        self.result = kwargs.get('result', int())

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
        if self.status != other.status:
            return False
        if self.total_time != other.total_time:
            return False
        if self.current_time != other.current_time:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'status' field must be an unsigned integer in [0, 255]"
        self._status = value

    @builtins.property
    def total_time(self):
        """Message field 'total_time'."""
        return self._total_time

    @total_time.setter
    def total_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'total_time' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'total_time' field must be an integer in [-2147483648, 2147483647]"
        self._total_time = value

    @builtins.property
    def current_time(self):
        """Message field 'current_time'."""
        return self._current_time

    @current_time.setter
    def current_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_time' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'current_time' field must be an integer in [-2147483648, 2147483647]"
        self._current_time = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'result' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'result' field must be an unsigned integer in [0, 255]"
        self._result = value
