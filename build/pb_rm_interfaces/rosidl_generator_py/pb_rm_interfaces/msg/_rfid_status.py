# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/RfidStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RfidStatus(type):
    """Metaclass of message 'RfidStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'NOT_DETECTED': 0,
        'DETECTED': 1,
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
                'pb_rm_interfaces.msg.RfidStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rfid_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rfid_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rfid_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rfid_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rfid_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'NOT_DETECTED': cls.__constants['NOT_DETECTED'],
            'DETECTED': cls.__constants['DETECTED'],
        }

    @property
    def NOT_DETECTED(self):
        """Message constant 'NOT_DETECTED'."""
        return Metaclass_RfidStatus.__constants['NOT_DETECTED']

    @property
    def DETECTED(self):
        """Message constant 'DETECTED'."""
        return Metaclass_RfidStatus.__constants['DETECTED']


class RfidStatus(metaclass=Metaclass_RfidStatus):
    """
    Message class 'RfidStatus'.

    Constants:
      NOT_DETECTED
      DETECTED
    """

    __slots__ = [
        '_base_gain_point',
        '_central_highland_gain_point',
        '_enemy_central_highland_gain_point',
        '_friendly_trapezoidal_highland_gain_point',
        '_enemy_trapezoidal_highland_gain_point',
        '_friendly_fly_ramp_front_gain_point',
        '_friendly_fly_ramp_back_gain_point',
        '_enemy_fly_ramp_front_gain_point',
        '_enemy_fly_ramp_back_gain_point',
        '_friendly_central_highland_lower_gain_point',
        '_friendly_central_highland_upper_gain_point',
        '_enemy_central_highland_lower_gain_point',
        '_enemy_central_highland_upper_gain_point',
        '_friendly_highway_lower_gain_point',
        '_friendly_highway_upper_gain_point',
        '_enemy_highway_lower_gain_point',
        '_enemy_highway_upper_gain_point',
        '_friendly_fortress_gain_point',
        '_friendly_outpost_gain_point',
        '_friendly_supply_zone_non_exchange',
        '_friendly_supply_zone_exchange',
        '_friendly_big_resource_island',
        '_enemy_big_resource_island',
        '_center_gain_point',
    ]

    _fields_and_field_types = {
        'base_gain_point': 'boolean',
        'central_highland_gain_point': 'boolean',
        'enemy_central_highland_gain_point': 'boolean',
        'friendly_trapezoidal_highland_gain_point': 'boolean',
        'enemy_trapezoidal_highland_gain_point': 'boolean',
        'friendly_fly_ramp_front_gain_point': 'boolean',
        'friendly_fly_ramp_back_gain_point': 'boolean',
        'enemy_fly_ramp_front_gain_point': 'boolean',
        'enemy_fly_ramp_back_gain_point': 'boolean',
        'friendly_central_highland_lower_gain_point': 'boolean',
        'friendly_central_highland_upper_gain_point': 'boolean',
        'enemy_central_highland_lower_gain_point': 'boolean',
        'enemy_central_highland_upper_gain_point': 'boolean',
        'friendly_highway_lower_gain_point': 'boolean',
        'friendly_highway_upper_gain_point': 'boolean',
        'enemy_highway_lower_gain_point': 'boolean',
        'enemy_highway_upper_gain_point': 'boolean',
        'friendly_fortress_gain_point': 'boolean',
        'friendly_outpost_gain_point': 'boolean',
        'friendly_supply_zone_non_exchange': 'boolean',
        'friendly_supply_zone_exchange': 'boolean',
        'friendly_big_resource_island': 'boolean',
        'enemy_big_resource_island': 'boolean',
        'center_gain_point': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.base_gain_point = kwargs.get('base_gain_point', bool())
        self.central_highland_gain_point = kwargs.get('central_highland_gain_point', bool())
        self.enemy_central_highland_gain_point = kwargs.get('enemy_central_highland_gain_point', bool())
        self.friendly_trapezoidal_highland_gain_point = kwargs.get('friendly_trapezoidal_highland_gain_point', bool())
        self.enemy_trapezoidal_highland_gain_point = kwargs.get('enemy_trapezoidal_highland_gain_point', bool())
        self.friendly_fly_ramp_front_gain_point = kwargs.get('friendly_fly_ramp_front_gain_point', bool())
        self.friendly_fly_ramp_back_gain_point = kwargs.get('friendly_fly_ramp_back_gain_point', bool())
        self.enemy_fly_ramp_front_gain_point = kwargs.get('enemy_fly_ramp_front_gain_point', bool())
        self.enemy_fly_ramp_back_gain_point = kwargs.get('enemy_fly_ramp_back_gain_point', bool())
        self.friendly_central_highland_lower_gain_point = kwargs.get('friendly_central_highland_lower_gain_point', bool())
        self.friendly_central_highland_upper_gain_point = kwargs.get('friendly_central_highland_upper_gain_point', bool())
        self.enemy_central_highland_lower_gain_point = kwargs.get('enemy_central_highland_lower_gain_point', bool())
        self.enemy_central_highland_upper_gain_point = kwargs.get('enemy_central_highland_upper_gain_point', bool())
        self.friendly_highway_lower_gain_point = kwargs.get('friendly_highway_lower_gain_point', bool())
        self.friendly_highway_upper_gain_point = kwargs.get('friendly_highway_upper_gain_point', bool())
        self.enemy_highway_lower_gain_point = kwargs.get('enemy_highway_lower_gain_point', bool())
        self.enemy_highway_upper_gain_point = kwargs.get('enemy_highway_upper_gain_point', bool())
        self.friendly_fortress_gain_point = kwargs.get('friendly_fortress_gain_point', bool())
        self.friendly_outpost_gain_point = kwargs.get('friendly_outpost_gain_point', bool())
        self.friendly_supply_zone_non_exchange = kwargs.get('friendly_supply_zone_non_exchange', bool())
        self.friendly_supply_zone_exchange = kwargs.get('friendly_supply_zone_exchange', bool())
        self.friendly_big_resource_island = kwargs.get('friendly_big_resource_island', bool())
        self.enemy_big_resource_island = kwargs.get('enemy_big_resource_island', bool())
        self.center_gain_point = kwargs.get('center_gain_point', bool())

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
        if self.base_gain_point != other.base_gain_point:
            return False
        if self.central_highland_gain_point != other.central_highland_gain_point:
            return False
        if self.enemy_central_highland_gain_point != other.enemy_central_highland_gain_point:
            return False
        if self.friendly_trapezoidal_highland_gain_point != other.friendly_trapezoidal_highland_gain_point:
            return False
        if self.enemy_trapezoidal_highland_gain_point != other.enemy_trapezoidal_highland_gain_point:
            return False
        if self.friendly_fly_ramp_front_gain_point != other.friendly_fly_ramp_front_gain_point:
            return False
        if self.friendly_fly_ramp_back_gain_point != other.friendly_fly_ramp_back_gain_point:
            return False
        if self.enemy_fly_ramp_front_gain_point != other.enemy_fly_ramp_front_gain_point:
            return False
        if self.enemy_fly_ramp_back_gain_point != other.enemy_fly_ramp_back_gain_point:
            return False
        if self.friendly_central_highland_lower_gain_point != other.friendly_central_highland_lower_gain_point:
            return False
        if self.friendly_central_highland_upper_gain_point != other.friendly_central_highland_upper_gain_point:
            return False
        if self.enemy_central_highland_lower_gain_point != other.enemy_central_highland_lower_gain_point:
            return False
        if self.enemy_central_highland_upper_gain_point != other.enemy_central_highland_upper_gain_point:
            return False
        if self.friendly_highway_lower_gain_point != other.friendly_highway_lower_gain_point:
            return False
        if self.friendly_highway_upper_gain_point != other.friendly_highway_upper_gain_point:
            return False
        if self.enemy_highway_lower_gain_point != other.enemy_highway_lower_gain_point:
            return False
        if self.enemy_highway_upper_gain_point != other.enemy_highway_upper_gain_point:
            return False
        if self.friendly_fortress_gain_point != other.friendly_fortress_gain_point:
            return False
        if self.friendly_outpost_gain_point != other.friendly_outpost_gain_point:
            return False
        if self.friendly_supply_zone_non_exchange != other.friendly_supply_zone_non_exchange:
            return False
        if self.friendly_supply_zone_exchange != other.friendly_supply_zone_exchange:
            return False
        if self.friendly_big_resource_island != other.friendly_big_resource_island:
            return False
        if self.enemy_big_resource_island != other.enemy_big_resource_island:
            return False
        if self.center_gain_point != other.center_gain_point:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def base_gain_point(self):
        """Message field 'base_gain_point'."""
        return self._base_gain_point

    @base_gain_point.setter
    def base_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'base_gain_point' field must be of type 'bool'"
        self._base_gain_point = value

    @builtins.property
    def central_highland_gain_point(self):
        """Message field 'central_highland_gain_point'."""
        return self._central_highland_gain_point

    @central_highland_gain_point.setter
    def central_highland_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'central_highland_gain_point' field must be of type 'bool'"
        self._central_highland_gain_point = value

    @builtins.property
    def enemy_central_highland_gain_point(self):
        """Message field 'enemy_central_highland_gain_point'."""
        return self._enemy_central_highland_gain_point

    @enemy_central_highland_gain_point.setter
    def enemy_central_highland_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enemy_central_highland_gain_point' field must be of type 'bool'"
        self._enemy_central_highland_gain_point = value

    @builtins.property
    def friendly_trapezoidal_highland_gain_point(self):
        """Message field 'friendly_trapezoidal_highland_gain_point'."""
        return self._friendly_trapezoidal_highland_gain_point

    @friendly_trapezoidal_highland_gain_point.setter
    def friendly_trapezoidal_highland_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_trapezoidal_highland_gain_point' field must be of type 'bool'"
        self._friendly_trapezoidal_highland_gain_point = value

    @builtins.property
    def enemy_trapezoidal_highland_gain_point(self):
        """Message field 'enemy_trapezoidal_highland_gain_point'."""
        return self._enemy_trapezoidal_highland_gain_point

    @enemy_trapezoidal_highland_gain_point.setter
    def enemy_trapezoidal_highland_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enemy_trapezoidal_highland_gain_point' field must be of type 'bool'"
        self._enemy_trapezoidal_highland_gain_point = value

    @builtins.property
    def friendly_fly_ramp_front_gain_point(self):
        """Message field 'friendly_fly_ramp_front_gain_point'."""
        return self._friendly_fly_ramp_front_gain_point

    @friendly_fly_ramp_front_gain_point.setter
    def friendly_fly_ramp_front_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_fly_ramp_front_gain_point' field must be of type 'bool'"
        self._friendly_fly_ramp_front_gain_point = value

    @builtins.property
    def friendly_fly_ramp_back_gain_point(self):
        """Message field 'friendly_fly_ramp_back_gain_point'."""
        return self._friendly_fly_ramp_back_gain_point

    @friendly_fly_ramp_back_gain_point.setter
    def friendly_fly_ramp_back_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_fly_ramp_back_gain_point' field must be of type 'bool'"
        self._friendly_fly_ramp_back_gain_point = value

    @builtins.property
    def enemy_fly_ramp_front_gain_point(self):
        """Message field 'enemy_fly_ramp_front_gain_point'."""
        return self._enemy_fly_ramp_front_gain_point

    @enemy_fly_ramp_front_gain_point.setter
    def enemy_fly_ramp_front_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enemy_fly_ramp_front_gain_point' field must be of type 'bool'"
        self._enemy_fly_ramp_front_gain_point = value

    @builtins.property
    def enemy_fly_ramp_back_gain_point(self):
        """Message field 'enemy_fly_ramp_back_gain_point'."""
        return self._enemy_fly_ramp_back_gain_point

    @enemy_fly_ramp_back_gain_point.setter
    def enemy_fly_ramp_back_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enemy_fly_ramp_back_gain_point' field must be of type 'bool'"
        self._enemy_fly_ramp_back_gain_point = value

    @builtins.property
    def friendly_central_highland_lower_gain_point(self):
        """Message field 'friendly_central_highland_lower_gain_point'."""
        return self._friendly_central_highland_lower_gain_point

    @friendly_central_highland_lower_gain_point.setter
    def friendly_central_highland_lower_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_central_highland_lower_gain_point' field must be of type 'bool'"
        self._friendly_central_highland_lower_gain_point = value

    @builtins.property
    def friendly_central_highland_upper_gain_point(self):
        """Message field 'friendly_central_highland_upper_gain_point'."""
        return self._friendly_central_highland_upper_gain_point

    @friendly_central_highland_upper_gain_point.setter
    def friendly_central_highland_upper_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_central_highland_upper_gain_point' field must be of type 'bool'"
        self._friendly_central_highland_upper_gain_point = value

    @builtins.property
    def enemy_central_highland_lower_gain_point(self):
        """Message field 'enemy_central_highland_lower_gain_point'."""
        return self._enemy_central_highland_lower_gain_point

    @enemy_central_highland_lower_gain_point.setter
    def enemy_central_highland_lower_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enemy_central_highland_lower_gain_point' field must be of type 'bool'"
        self._enemy_central_highland_lower_gain_point = value

    @builtins.property
    def enemy_central_highland_upper_gain_point(self):
        """Message field 'enemy_central_highland_upper_gain_point'."""
        return self._enemy_central_highland_upper_gain_point

    @enemy_central_highland_upper_gain_point.setter
    def enemy_central_highland_upper_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enemy_central_highland_upper_gain_point' field must be of type 'bool'"
        self._enemy_central_highland_upper_gain_point = value

    @builtins.property
    def friendly_highway_lower_gain_point(self):
        """Message field 'friendly_highway_lower_gain_point'."""
        return self._friendly_highway_lower_gain_point

    @friendly_highway_lower_gain_point.setter
    def friendly_highway_lower_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_highway_lower_gain_point' field must be of type 'bool'"
        self._friendly_highway_lower_gain_point = value

    @builtins.property
    def friendly_highway_upper_gain_point(self):
        """Message field 'friendly_highway_upper_gain_point'."""
        return self._friendly_highway_upper_gain_point

    @friendly_highway_upper_gain_point.setter
    def friendly_highway_upper_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_highway_upper_gain_point' field must be of type 'bool'"
        self._friendly_highway_upper_gain_point = value

    @builtins.property
    def enemy_highway_lower_gain_point(self):
        """Message field 'enemy_highway_lower_gain_point'."""
        return self._enemy_highway_lower_gain_point

    @enemy_highway_lower_gain_point.setter
    def enemy_highway_lower_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enemy_highway_lower_gain_point' field must be of type 'bool'"
        self._enemy_highway_lower_gain_point = value

    @builtins.property
    def enemy_highway_upper_gain_point(self):
        """Message field 'enemy_highway_upper_gain_point'."""
        return self._enemy_highway_upper_gain_point

    @enemy_highway_upper_gain_point.setter
    def enemy_highway_upper_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enemy_highway_upper_gain_point' field must be of type 'bool'"
        self._enemy_highway_upper_gain_point = value

    @builtins.property
    def friendly_fortress_gain_point(self):
        """Message field 'friendly_fortress_gain_point'."""
        return self._friendly_fortress_gain_point

    @friendly_fortress_gain_point.setter
    def friendly_fortress_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_fortress_gain_point' field must be of type 'bool'"
        self._friendly_fortress_gain_point = value

    @builtins.property
    def friendly_outpost_gain_point(self):
        """Message field 'friendly_outpost_gain_point'."""
        return self._friendly_outpost_gain_point

    @friendly_outpost_gain_point.setter
    def friendly_outpost_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_outpost_gain_point' field must be of type 'bool'"
        self._friendly_outpost_gain_point = value

    @builtins.property
    def friendly_supply_zone_non_exchange(self):
        """Message field 'friendly_supply_zone_non_exchange'."""
        return self._friendly_supply_zone_non_exchange

    @friendly_supply_zone_non_exchange.setter
    def friendly_supply_zone_non_exchange(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_supply_zone_non_exchange' field must be of type 'bool'"
        self._friendly_supply_zone_non_exchange = value

    @builtins.property
    def friendly_supply_zone_exchange(self):
        """Message field 'friendly_supply_zone_exchange'."""
        return self._friendly_supply_zone_exchange

    @friendly_supply_zone_exchange.setter
    def friendly_supply_zone_exchange(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_supply_zone_exchange' field must be of type 'bool'"
        self._friendly_supply_zone_exchange = value

    @builtins.property
    def friendly_big_resource_island(self):
        """Message field 'friendly_big_resource_island'."""
        return self._friendly_big_resource_island

    @friendly_big_resource_island.setter
    def friendly_big_resource_island(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'friendly_big_resource_island' field must be of type 'bool'"
        self._friendly_big_resource_island = value

    @builtins.property
    def enemy_big_resource_island(self):
        """Message field 'enemy_big_resource_island'."""
        return self._enemy_big_resource_island

    @enemy_big_resource_island.setter
    def enemy_big_resource_island(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enemy_big_resource_island' field must be of type 'bool'"
        self._enemy_big_resource_island = value

    @builtins.property
    def center_gain_point(self):
        """Message field 'center_gain_point'."""
        return self._center_gain_point

    @center_gain_point.setter
    def center_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'center_gain_point' field must be of type 'bool'"
        self._center_gain_point = value
