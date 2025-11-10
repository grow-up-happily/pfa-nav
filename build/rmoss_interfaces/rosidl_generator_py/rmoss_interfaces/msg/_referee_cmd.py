# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rmoss_interfaces:msg/RefereeCmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RefereeCmd(type):
    """Metaclass of message 'RefereeCmd'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'START_PREPARATION': 0,
        'START_SELF_CHECKING': 1,
        'START_GAME': 2,
        'STOP_GAME': 3,
        'KILL_ROBOT': 4,
        'REVIVE_ROBOT': 5,
        'PREPARATION': 0,
        'SELF_CHECKING': 1,
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
                'rmoss_interfaces.msg.RefereeCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__referee_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__referee_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__referee_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__referee_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__referee_cmd

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'START_PREPARATION': cls.__constants['START_PREPARATION'],
            'START_SELF_CHECKING': cls.__constants['START_SELF_CHECKING'],
            'START_GAME': cls.__constants['START_GAME'],
            'STOP_GAME': cls.__constants['STOP_GAME'],
            'KILL_ROBOT': cls.__constants['KILL_ROBOT'],
            'REVIVE_ROBOT': cls.__constants['REVIVE_ROBOT'],
            'PREPARATION': cls.__constants['PREPARATION'],
            'SELF_CHECKING': cls.__constants['SELF_CHECKING'],
            'CMD__DEFAULT': 0,
        }

    @property
    def START_PREPARATION(self):
        """Message constant 'START_PREPARATION'."""
        return Metaclass_RefereeCmd.__constants['START_PREPARATION']

    @property
    def START_SELF_CHECKING(self):
        """Message constant 'START_SELF_CHECKING'."""
        return Metaclass_RefereeCmd.__constants['START_SELF_CHECKING']

    @property
    def START_GAME(self):
        """Message constant 'START_GAME'."""
        return Metaclass_RefereeCmd.__constants['START_GAME']

    @property
    def STOP_GAME(self):
        """Message constant 'STOP_GAME'."""
        return Metaclass_RefereeCmd.__constants['STOP_GAME']

    @property
    def KILL_ROBOT(self):
        """Message constant 'KILL_ROBOT'."""
        return Metaclass_RefereeCmd.__constants['KILL_ROBOT']

    @property
    def REVIVE_ROBOT(self):
        """Message constant 'REVIVE_ROBOT'."""
        return Metaclass_RefereeCmd.__constants['REVIVE_ROBOT']

    @property
    def PREPARATION(self):
        """Message constant 'PREPARATION'."""
        return Metaclass_RefereeCmd.__constants['PREPARATION']

    @property
    def SELF_CHECKING(self):
        """Message constant 'SELF_CHECKING'."""
        return Metaclass_RefereeCmd.__constants['SELF_CHECKING']

    @property
    def CMD__DEFAULT(cls):
        """Return default value for message field 'cmd'."""
        return 0


class RefereeCmd(metaclass=Metaclass_RefereeCmd):
    """
    Message class 'RefereeCmd'.

    Constants:
      START_PREPARATION
      START_SELF_CHECKING
      START_GAME
      STOP_GAME
      KILL_ROBOT
      REVIVE_ROBOT
      PREPARATION
      SELF_CHECKING
    """

    __slots__ = [
        '_cmd',
        '_robot_name',
    ]

    _fields_and_field_types = {
        'cmd': 'uint8',
        'robot_name': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cmd = kwargs.get(
            'cmd', RefereeCmd.CMD__DEFAULT)
        self.robot_name = kwargs.get('robot_name', str())

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
        if self.cmd != other.cmd:
            return False
        if self.robot_name != other.robot_name:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cmd(self):
        """Message field 'cmd'."""
        return self._cmd

    @cmd.setter
    def cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cmd' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cmd' field must be an unsigned integer in [0, 255]"
        self._cmd = value

    @builtins.property
    def robot_name(self):
        """Message field 'robot_name'."""
        return self._robot_name

    @robot_name.setter
    def robot_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'robot_name' field must be of type 'str'"
        self._robot_name = value
