# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/GameStatus.idl
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
        'NOT_START': 0,
        'PREPARATION': 1,
        'SELF_CHECKING': 2,
        'COUNT_DOWN': 3,
        'RUNNING': 4,
        'GAME_OVER': 5,
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
                'pb_rm_interfaces.msg.GameStatus')
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
            'NOT_START': cls.__constants['NOT_START'],
            'PREPARATION': cls.__constants['PREPARATION'],
            'SELF_CHECKING': cls.__constants['SELF_CHECKING'],
            'COUNT_DOWN': cls.__constants['COUNT_DOWN'],
            'RUNNING': cls.__constants['RUNNING'],
            'GAME_OVER': cls.__constants['GAME_OVER'],
        }

    @property
    def NOT_START(self):
        """Message constant 'NOT_START'."""
        return Metaclass_GameStatus.__constants['NOT_START']

    @property
    def PREPARATION(self):
        """Message constant 'PREPARATION'."""
        return Metaclass_GameStatus.__constants['PREPARATION']

    @property
    def SELF_CHECKING(self):
        """Message constant 'SELF_CHECKING'."""
        return Metaclass_GameStatus.__constants['SELF_CHECKING']

    @property
    def COUNT_DOWN(self):
        """Message constant 'COUNT_DOWN'."""
        return Metaclass_GameStatus.__constants['COUNT_DOWN']

    @property
    def RUNNING(self):
        """Message constant 'RUNNING'."""
        return Metaclass_GameStatus.__constants['RUNNING']

    @property
    def GAME_OVER(self):
        """Message constant 'GAME_OVER'."""
        return Metaclass_GameStatus.__constants['GAME_OVER']


class GameStatus(metaclass=Metaclass_GameStatus):
    """
    Message class 'GameStatus'.

    Constants:
      NOT_START
      PREPARATION
      SELF_CHECKING
      COUNT_DOWN
      RUNNING
      GAME_OVER
    """

    __slots__ = [
        '_game_progress',
        '_stage_remain_time',
    ]

    _fields_and_field_types = {
        'game_progress': 'uint8',
        'stage_remain_time': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.game_progress = kwargs.get('game_progress', int())
        self.stage_remain_time = kwargs.get('stage_remain_time', int())

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
        if self.game_progress != other.game_progress:
            return False
        if self.stage_remain_time != other.stage_remain_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def game_progress(self):
        """Message field 'game_progress'."""
        return self._game_progress

    @game_progress.setter
    def game_progress(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'game_progress' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'game_progress' field must be an unsigned integer in [0, 255]"
        self._game_progress = value

    @builtins.property
    def stage_remain_time(self):
        """Message field 'stage_remain_time'."""
        return self._stage_remain_time

    @stage_remain_time.setter
    def stage_remain_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'stage_remain_time' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'stage_remain_time' field must be an integer in [-2147483648, 2147483647]"
        self._stage_remain_time = value
