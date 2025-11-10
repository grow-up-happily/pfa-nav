# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/GroundRobotPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GroundRobotPosition(type):
    """Metaclass of message 'GroundRobotPosition'."""

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
                'pb_rm_interfaces.msg.GroundRobotPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ground_robot_position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ground_robot_position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ground_robot_position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ground_robot_position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ground_robot_position

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GroundRobotPosition(metaclass=Metaclass_GroundRobotPosition):
    """Message class 'GroundRobotPosition'."""

    __slots__ = [
        '_hero_position',
        '_engineer_position',
        '_standard_3_position',
        '_standard_4_position',
    ]

    _fields_and_field_types = {
        'hero_position': 'geometry_msgs/Point',
        'engineer_position': 'geometry_msgs/Point',
        'standard_3_position': 'geometry_msgs/Point',
        'standard_4_position': 'geometry_msgs/Point',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.hero_position = kwargs.get('hero_position', Point())
        from geometry_msgs.msg import Point
        self.engineer_position = kwargs.get('engineer_position', Point())
        from geometry_msgs.msg import Point
        self.standard_3_position = kwargs.get('standard_3_position', Point())
        from geometry_msgs.msg import Point
        self.standard_4_position = kwargs.get('standard_4_position', Point())

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
        if self.hero_position != other.hero_position:
            return False
        if self.engineer_position != other.engineer_position:
            return False
        if self.standard_3_position != other.standard_3_position:
            return False
        if self.standard_4_position != other.standard_4_position:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def hero_position(self):
        """Message field 'hero_position'."""
        return self._hero_position

    @hero_position.setter
    def hero_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'hero_position' field must be a sub message of type 'Point'"
        self._hero_position = value

    @builtins.property
    def engineer_position(self):
        """Message field 'engineer_position'."""
        return self._engineer_position

    @engineer_position.setter
    def engineer_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'engineer_position' field must be a sub message of type 'Point'"
        self._engineer_position = value

    @builtins.property
    def standard_3_position(self):
        """Message field 'standard_3_position'."""
        return self._standard_3_position

    @standard_3_position.setter
    def standard_3_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'standard_3_position' field must be a sub message of type 'Point'"
        self._standard_3_position = value

    @builtins.property
    def standard_4_position(self):
        """Message field 'standard_4_position'."""
        return self._standard_4_position

    @standard_4_position.setter
    def standard_4_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'standard_4_position' field must be a sub message of type 'Point'"
        self._standard_4_position = value
