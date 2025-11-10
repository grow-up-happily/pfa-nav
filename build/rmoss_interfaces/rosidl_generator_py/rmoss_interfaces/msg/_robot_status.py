# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rmoss_interfaces:msg/RobotStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotStatus(type):
    """Metaclass of message 'RobotStatus'."""

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
                'rmoss_interfaces.msg.RobotStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_status

            from geometry_msgs.msg import Transform
            if Transform.__class__._TYPE_SUPPORT is None:
                Transform.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotStatus(metaclass=Metaclass_RobotStatus):
    """Message class 'RobotStatus'."""

    __slots__ = [
        '_id',
        '_level',
        '_name',
        '_remain_hp',
        '_max_hp',
        '_total_projectiles',
        '_used_projectiles',
        '_hit_projectiles',
        '_gt_tf',
    ]

    _fields_and_field_types = {
        'id': 'uint8',
        'level': 'uint8',
        'name': 'string',
        'remain_hp': 'int32',
        'max_hp': 'int32',
        'total_projectiles': 'int32',
        'used_projectiles': 'int32',
        'hit_projectiles': 'int32',
        'gt_tf': 'geometry_msgs/Transform',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Transform'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.level = kwargs.get('level', int())
        self.name = kwargs.get('name', str())
        self.remain_hp = kwargs.get('remain_hp', int())
        self.max_hp = kwargs.get('max_hp', int())
        self.total_projectiles = kwargs.get('total_projectiles', int())
        self.used_projectiles = kwargs.get('used_projectiles', int())
        self.hit_projectiles = kwargs.get('hit_projectiles', int())
        from geometry_msgs.msg import Transform
        self.gt_tf = kwargs.get('gt_tf', Transform())

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
        if self.id != other.id:
            return False
        if self.level != other.level:
            return False
        if self.name != other.name:
            return False
        if self.remain_hp != other.remain_hp:
            return False
        if self.max_hp != other.max_hp:
            return False
        if self.total_projectiles != other.total_projectiles:
            return False
        if self.used_projectiles != other.used_projectiles:
            return False
        if self.hit_projectiles != other.hit_projectiles:
            return False
        if self.gt_tf != other.gt_tf:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'id' field must be an unsigned integer in [0, 255]"
        self._id = value

    @builtins.property
    def level(self):
        """Message field 'level'."""
        return self._level

    @level.setter
    def level(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'level' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'level' field must be an unsigned integer in [0, 255]"
        self._level = value

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def remain_hp(self):
        """Message field 'remain_hp'."""
        return self._remain_hp

    @remain_hp.setter
    def remain_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'remain_hp' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'remain_hp' field must be an integer in [-2147483648, 2147483647]"
        self._remain_hp = value

    @builtins.property
    def max_hp(self):
        """Message field 'max_hp'."""
        return self._max_hp

    @max_hp.setter
    def max_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_hp' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'max_hp' field must be an integer in [-2147483648, 2147483647]"
        self._max_hp = value

    @builtins.property
    def total_projectiles(self):
        """Message field 'total_projectiles'."""
        return self._total_projectiles

    @total_projectiles.setter
    def total_projectiles(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'total_projectiles' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'total_projectiles' field must be an integer in [-2147483648, 2147483647]"
        self._total_projectiles = value

    @builtins.property
    def used_projectiles(self):
        """Message field 'used_projectiles'."""
        return self._used_projectiles

    @used_projectiles.setter
    def used_projectiles(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'used_projectiles' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'used_projectiles' field must be an integer in [-2147483648, 2147483647]"
        self._used_projectiles = value

    @builtins.property
    def hit_projectiles(self):
        """Message field 'hit_projectiles'."""
        return self._hit_projectiles

    @hit_projectiles.setter
    def hit_projectiles(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hit_projectiles' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'hit_projectiles' field must be an integer in [-2147483648, 2147483647]"
        self._hit_projectiles = value

    @builtins.property
    def gt_tf(self):
        """Message field 'gt_tf'."""
        return self._gt_tf

    @gt_tf.setter
    def gt_tf(self, value):
        if __debug__:
            from geometry_msgs.msg import Transform
            assert \
                isinstance(value, Transform), \
                "The 'gt_tf' field must be a sub message of type 'Transform'"
        self._gt_tf = value
