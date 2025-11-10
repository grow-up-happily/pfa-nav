# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/EventData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EventData(type):
    """Metaclass of message 'EventData'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'UNOCCUPIED': 0,
        'OCCUPIED_FRIEND': 1,
        'OCCUPIED_ENEMY': 2,
        'OCCUPIED_BOTH': 3,
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
                'pb_rm_interfaces.msg.EventData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__event_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__event_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__event_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__event_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__event_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'UNOCCUPIED': cls.__constants['UNOCCUPIED'],
            'OCCUPIED_FRIEND': cls.__constants['OCCUPIED_FRIEND'],
            'OCCUPIED_ENEMY': cls.__constants['OCCUPIED_ENEMY'],
            'OCCUPIED_BOTH': cls.__constants['OCCUPIED_BOTH'],
        }

    @property
    def UNOCCUPIED(self):
        """Message constant 'UNOCCUPIED'."""
        return Metaclass_EventData.__constants['UNOCCUPIED']

    @property
    def OCCUPIED_FRIEND(self):
        """Message constant 'OCCUPIED_FRIEND'."""
        return Metaclass_EventData.__constants['OCCUPIED_FRIEND']

    @property
    def OCCUPIED_ENEMY(self):
        """Message constant 'OCCUPIED_ENEMY'."""
        return Metaclass_EventData.__constants['OCCUPIED_ENEMY']

    @property
    def OCCUPIED_BOTH(self):
        """Message constant 'OCCUPIED_BOTH'."""
        return Metaclass_EventData.__constants['OCCUPIED_BOTH']


class EventData(metaclass=Metaclass_EventData):
    """
    Message class 'EventData'.

    Constants:
      UNOCCUPIED
      OCCUPIED_FRIEND
      OCCUPIED_ENEMY
      OCCUPIED_BOTH
    """

    __slots__ = [
        '_non_overlapping_supply_zone',
        '_overlapping_supply_zone',
        '_supply_zone',
        '_small_energy',
        '_big_energy',
        '_central_highland',
        '_trapezoidal_highland',
        '_center_gain_zone',
    ]

    _fields_and_field_types = {
        'non_overlapping_supply_zone': 'uint8',
        'overlapping_supply_zone': 'uint8',
        'supply_zone': 'uint8',
        'small_energy': 'uint8',
        'big_energy': 'uint8',
        'central_highland': 'uint8',
        'trapezoidal_highland': 'uint8',
        'center_gain_zone': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.non_overlapping_supply_zone = kwargs.get('non_overlapping_supply_zone', int())
        self.overlapping_supply_zone = kwargs.get('overlapping_supply_zone', int())
        self.supply_zone = kwargs.get('supply_zone', int())
        self.small_energy = kwargs.get('small_energy', int())
        self.big_energy = kwargs.get('big_energy', int())
        self.central_highland = kwargs.get('central_highland', int())
        self.trapezoidal_highland = kwargs.get('trapezoidal_highland', int())
        self.center_gain_zone = kwargs.get('center_gain_zone', int())

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
        if self.non_overlapping_supply_zone != other.non_overlapping_supply_zone:
            return False
        if self.overlapping_supply_zone != other.overlapping_supply_zone:
            return False
        if self.supply_zone != other.supply_zone:
            return False
        if self.small_energy != other.small_energy:
            return False
        if self.big_energy != other.big_energy:
            return False
        if self.central_highland != other.central_highland:
            return False
        if self.trapezoidal_highland != other.trapezoidal_highland:
            return False
        if self.center_gain_zone != other.center_gain_zone:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def non_overlapping_supply_zone(self):
        """Message field 'non_overlapping_supply_zone'."""
        return self._non_overlapping_supply_zone

    @non_overlapping_supply_zone.setter
    def non_overlapping_supply_zone(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'non_overlapping_supply_zone' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'non_overlapping_supply_zone' field must be an unsigned integer in [0, 255]"
        self._non_overlapping_supply_zone = value

    @builtins.property
    def overlapping_supply_zone(self):
        """Message field 'overlapping_supply_zone'."""
        return self._overlapping_supply_zone

    @overlapping_supply_zone.setter
    def overlapping_supply_zone(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'overlapping_supply_zone' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'overlapping_supply_zone' field must be an unsigned integer in [0, 255]"
        self._overlapping_supply_zone = value

    @builtins.property
    def supply_zone(self):
        """Message field 'supply_zone'."""
        return self._supply_zone

    @supply_zone.setter
    def supply_zone(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'supply_zone' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'supply_zone' field must be an unsigned integer in [0, 255]"
        self._supply_zone = value

    @builtins.property
    def small_energy(self):
        """Message field 'small_energy'."""
        return self._small_energy

    @small_energy.setter
    def small_energy(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'small_energy' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'small_energy' field must be an unsigned integer in [0, 255]"
        self._small_energy = value

    @builtins.property
    def big_energy(self):
        """Message field 'big_energy'."""
        return self._big_energy

    @big_energy.setter
    def big_energy(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'big_energy' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'big_energy' field must be an unsigned integer in [0, 255]"
        self._big_energy = value

    @builtins.property
    def central_highland(self):
        """Message field 'central_highland'."""
        return self._central_highland

    @central_highland.setter
    def central_highland(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'central_highland' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'central_highland' field must be an unsigned integer in [0, 255]"
        self._central_highland = value

    @builtins.property
    def trapezoidal_highland(self):
        """Message field 'trapezoidal_highland'."""
        return self._trapezoidal_highland

    @trapezoidal_highland.setter
    def trapezoidal_highland(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trapezoidal_highland' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'trapezoidal_highland' field must be an unsigned integer in [0, 255]"
        self._trapezoidal_highland = value

    @builtins.property
    def center_gain_zone(self):
        """Message field 'center_gain_zone'."""
        return self._center_gain_zone

    @center_gain_zone.setter
    def center_gain_zone(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_gain_zone' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'center_gain_zone' field must be an unsigned integer in [0, 255]"
        self._center_gain_zone = value
