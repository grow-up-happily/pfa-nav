# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/RobotStatus.idl
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
        'ARMOR_HIT': 0,
        'SYSTEM_OFFLINE': 1,
        'OVER_SHOOT_SPEED': 2,
        'OVER_HEAT': 3,
        'OVER_POWER': 4,
        'ARMOR_COLLISION': 5,
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
                'pb_rm_interfaces.msg.RobotStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_status

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'ARMOR_HIT': cls.__constants['ARMOR_HIT'],
            'SYSTEM_OFFLINE': cls.__constants['SYSTEM_OFFLINE'],
            'OVER_SHOOT_SPEED': cls.__constants['OVER_SHOOT_SPEED'],
            'OVER_HEAT': cls.__constants['OVER_HEAT'],
            'OVER_POWER': cls.__constants['OVER_POWER'],
            'ARMOR_COLLISION': cls.__constants['ARMOR_COLLISION'],
        }

    @property
    def ARMOR_HIT(self):
        """Message constant 'ARMOR_HIT'."""
        return Metaclass_RobotStatus.__constants['ARMOR_HIT']

    @property
    def SYSTEM_OFFLINE(self):
        """Message constant 'SYSTEM_OFFLINE'."""
        return Metaclass_RobotStatus.__constants['SYSTEM_OFFLINE']

    @property
    def OVER_SHOOT_SPEED(self):
        """Message constant 'OVER_SHOOT_SPEED'."""
        return Metaclass_RobotStatus.__constants['OVER_SHOOT_SPEED']

    @property
    def OVER_HEAT(self):
        """Message constant 'OVER_HEAT'."""
        return Metaclass_RobotStatus.__constants['OVER_HEAT']

    @property
    def OVER_POWER(self):
        """Message constant 'OVER_POWER'."""
        return Metaclass_RobotStatus.__constants['OVER_POWER']

    @property
    def ARMOR_COLLISION(self):
        """Message constant 'ARMOR_COLLISION'."""
        return Metaclass_RobotStatus.__constants['ARMOR_COLLISION']


class RobotStatus(metaclass=Metaclass_RobotStatus):
    """
    Message class 'RobotStatus'.

    Constants:
      ARMOR_HIT
      SYSTEM_OFFLINE
      OVER_SHOOT_SPEED
      OVER_HEAT
      OVER_POWER
      ARMOR_COLLISION
    """

    __slots__ = [
        '_robot_id',
        '_robot_level',
        '_current_hp',
        '_maximum_hp',
        '_shooter_barrel_cooling_value',
        '_shooter_barrel_heat_limit',
        '_shooter_17mm_1_barrel_heat',
        '_robot_pos',
        '_armor_id',
        '_hp_deduction_reason',
        '_projectile_allowance_17mm',
        '_remaining_gold_coin',
        '_is_hp_deduced',
    ]

    _fields_and_field_types = {
        'robot_id': 'uint8',
        'robot_level': 'uint8',
        'current_hp': 'uint16',
        'maximum_hp': 'uint16',
        'shooter_barrel_cooling_value': 'uint16',
        'shooter_barrel_heat_limit': 'uint16',
        'shooter_17mm_1_barrel_heat': 'uint16',
        'robot_pos': 'geometry_msgs/Pose',
        'armor_id': 'uint8',
        'hp_deduction_reason': 'uint8',
        'projectile_allowance_17mm': 'uint16',
        'remaining_gold_coin': 'uint16',
        'is_hp_deduced': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_id = kwargs.get('robot_id', int())
        self.robot_level = kwargs.get('robot_level', int())
        self.current_hp = kwargs.get('current_hp', int())
        self.maximum_hp = kwargs.get('maximum_hp', int())
        self.shooter_barrel_cooling_value = kwargs.get('shooter_barrel_cooling_value', int())
        self.shooter_barrel_heat_limit = kwargs.get('shooter_barrel_heat_limit', int())
        self.shooter_17mm_1_barrel_heat = kwargs.get('shooter_17mm_1_barrel_heat', int())
        from geometry_msgs.msg import Pose
        self.robot_pos = kwargs.get('robot_pos', Pose())
        self.armor_id = kwargs.get('armor_id', int())
        self.hp_deduction_reason = kwargs.get('hp_deduction_reason', int())
        self.projectile_allowance_17mm = kwargs.get('projectile_allowance_17mm', int())
        self.remaining_gold_coin = kwargs.get('remaining_gold_coin', int())
        self.is_hp_deduced = kwargs.get('is_hp_deduced', bool())

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
        if self.robot_id != other.robot_id:
            return False
        if self.robot_level != other.robot_level:
            return False
        if self.current_hp != other.current_hp:
            return False
        if self.maximum_hp != other.maximum_hp:
            return False
        if self.shooter_barrel_cooling_value != other.shooter_barrel_cooling_value:
            return False
        if self.shooter_barrel_heat_limit != other.shooter_barrel_heat_limit:
            return False
        if self.shooter_17mm_1_barrel_heat != other.shooter_17mm_1_barrel_heat:
            return False
        if self.robot_pos != other.robot_pos:
            return False
        if self.armor_id != other.armor_id:
            return False
        if self.hp_deduction_reason != other.hp_deduction_reason:
            return False
        if self.projectile_allowance_17mm != other.projectile_allowance_17mm:
            return False
        if self.remaining_gold_coin != other.remaining_gold_coin:
            return False
        if self.is_hp_deduced != other.is_hp_deduced:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def robot_id(self):
        """Message field 'robot_id'."""
        return self._robot_id

    @robot_id.setter
    def robot_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'robot_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'robot_id' field must be an unsigned integer in [0, 255]"
        self._robot_id = value

    @builtins.property
    def robot_level(self):
        """Message field 'robot_level'."""
        return self._robot_level

    @robot_level.setter
    def robot_level(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'robot_level' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'robot_level' field must be an unsigned integer in [0, 255]"
        self._robot_level = value

    @builtins.property
    def current_hp(self):
        """Message field 'current_hp'."""
        return self._current_hp

    @current_hp.setter
    def current_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'current_hp' field must be an unsigned integer in [0, 65535]"
        self._current_hp = value

    @builtins.property
    def maximum_hp(self):
        """Message field 'maximum_hp'."""
        return self._maximum_hp

    @maximum_hp.setter
    def maximum_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'maximum_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'maximum_hp' field must be an unsigned integer in [0, 65535]"
        self._maximum_hp = value

    @builtins.property
    def shooter_barrel_cooling_value(self):
        """Message field 'shooter_barrel_cooling_value'."""
        return self._shooter_barrel_cooling_value

    @shooter_barrel_cooling_value.setter
    def shooter_barrel_cooling_value(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'shooter_barrel_cooling_value' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'shooter_barrel_cooling_value' field must be an unsigned integer in [0, 65535]"
        self._shooter_barrel_cooling_value = value

    @builtins.property
    def shooter_barrel_heat_limit(self):
        """Message field 'shooter_barrel_heat_limit'."""
        return self._shooter_barrel_heat_limit

    @shooter_barrel_heat_limit.setter
    def shooter_barrel_heat_limit(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'shooter_barrel_heat_limit' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'shooter_barrel_heat_limit' field must be an unsigned integer in [0, 65535]"
        self._shooter_barrel_heat_limit = value

    @builtins.property
    def shooter_17mm_1_barrel_heat(self):
        """Message field 'shooter_17mm_1_barrel_heat'."""
        return self._shooter_17mm_1_barrel_heat

    @shooter_17mm_1_barrel_heat.setter
    def shooter_17mm_1_barrel_heat(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'shooter_17mm_1_barrel_heat' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'shooter_17mm_1_barrel_heat' field must be an unsigned integer in [0, 65535]"
        self._shooter_17mm_1_barrel_heat = value

    @builtins.property
    def robot_pos(self):
        """Message field 'robot_pos'."""
        return self._robot_pos

    @robot_pos.setter
    def robot_pos(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'robot_pos' field must be a sub message of type 'Pose'"
        self._robot_pos = value

    @builtins.property
    def armor_id(self):
        """Message field 'armor_id'."""
        return self._armor_id

    @armor_id.setter
    def armor_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'armor_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'armor_id' field must be an unsigned integer in [0, 255]"
        self._armor_id = value

    @builtins.property
    def hp_deduction_reason(self):
        """Message field 'hp_deduction_reason'."""
        return self._hp_deduction_reason

    @hp_deduction_reason.setter
    def hp_deduction_reason(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hp_deduction_reason' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'hp_deduction_reason' field must be an unsigned integer in [0, 255]"
        self._hp_deduction_reason = value

    @builtins.property
    def projectile_allowance_17mm(self):
        """Message field 'projectile_allowance_17mm'."""
        return self._projectile_allowance_17mm

    @projectile_allowance_17mm.setter
    def projectile_allowance_17mm(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'projectile_allowance_17mm' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'projectile_allowance_17mm' field must be an unsigned integer in [0, 65535]"
        self._projectile_allowance_17mm = value

    @builtins.property
    def remaining_gold_coin(self):
        """Message field 'remaining_gold_coin'."""
        return self._remaining_gold_coin

    @remaining_gold_coin.setter
    def remaining_gold_coin(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'remaining_gold_coin' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'remaining_gold_coin' field must be an unsigned integer in [0, 65535]"
        self._remaining_gold_coin = value

    @builtins.property
    def is_hp_deduced(self):
        """Message field 'is_hp_deduced'."""
        return self._is_hp_deduced

    @is_hp_deduced.setter
    def is_hp_deduced(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_hp_deduced' field must be of type 'bool'"
        self._is_hp_deduced = value
