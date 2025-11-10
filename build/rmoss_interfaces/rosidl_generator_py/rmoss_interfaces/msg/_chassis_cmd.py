# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rmoss_interfaces:msg/ChassisCmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ChassisCmd(type):
    """Metaclass of message 'ChassisCmd'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'VELOCITY': 1,
        'FOLLOW_GIMBAL': 2,
        'SWING': 3,
        'SPIN': 4,
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
                'rmoss_interfaces.msg.ChassisCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__chassis_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__chassis_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__chassis_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__chassis_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__chassis_cmd

            from geometry_msgs.msg import Accel
            if Accel.__class__._TYPE_SUPPORT is None:
                Accel.__class__.__import_type_support__()

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

            from geometry_msgs.msg import Twist
            if Twist.__class__._TYPE_SUPPORT is None:
                Twist.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'VELOCITY': cls.__constants['VELOCITY'],
            'FOLLOW_GIMBAL': cls.__constants['FOLLOW_GIMBAL'],
            'SWING': cls.__constants['SWING'],
            'SPIN': cls.__constants['SPIN'],
            'TYPE__DEFAULT': 1,
        }

    @property
    def VELOCITY(self):
        """Message constant 'VELOCITY'."""
        return Metaclass_ChassisCmd.__constants['VELOCITY']

    @property
    def FOLLOW_GIMBAL(self):
        """Message constant 'FOLLOW_GIMBAL'."""
        return Metaclass_ChassisCmd.__constants['FOLLOW_GIMBAL']

    @property
    def SWING(self):
        """Message constant 'SWING'."""
        return Metaclass_ChassisCmd.__constants['SWING']

    @property
    def SPIN(self):
        """Message constant 'SPIN'."""
        return Metaclass_ChassisCmd.__constants['SPIN']

    @property
    def TYPE__DEFAULT(cls):
        """Return default value for message field 'type'."""
        return 1


class ChassisCmd(metaclass=Metaclass_ChassisCmd):
    """
    Message class 'ChassisCmd'.

    Constants:
      VELOCITY
      FOLLOW_GIMBAL
      SWING
      SPIN
    """

    __slots__ = [
        '_tid',
        '_type',
        '_pose',
        '_twist',
        '_accel',
    ]

    _fields_and_field_types = {
        'tid': 'uint8',
        'type': 'uint8',
        'pose': 'geometry_msgs/Pose',
        'twist': 'geometry_msgs/Twist',
        'accel': 'geometry_msgs/Accel',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Twist'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Accel'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.tid = kwargs.get('tid', int())
        self.type = kwargs.get(
            'type', ChassisCmd.TYPE__DEFAULT)
        from geometry_msgs.msg import Pose
        self.pose = kwargs.get('pose', Pose())
        from geometry_msgs.msg import Twist
        self.twist = kwargs.get('twist', Twist())
        from geometry_msgs.msg import Accel
        self.accel = kwargs.get('accel', Accel())

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
        if self.pose != other.pose:
            return False
        if self.twist != other.twist:
            return False
        if self.accel != other.accel:
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
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose' field must be a sub message of type 'Pose'"
        self._pose = value

    @builtins.property
    def twist(self):
        """Message field 'twist'."""
        return self._twist

    @twist.setter
    def twist(self, value):
        if __debug__:
            from geometry_msgs.msg import Twist
            assert \
                isinstance(value, Twist), \
                "The 'twist' field must be a sub message of type 'Twist'"
        self._twist = value

    @builtins.property
    def accel(self):
        """Message field 'accel'."""
        return self._accel

    @accel.setter
    def accel(self, value):
        if __debug__:
            from geometry_msgs.msg import Accel
            assert \
                isinstance(value, Accel), \
                "The 'accel' field must be a sub message of type 'Accel'"
        self._accel = value
