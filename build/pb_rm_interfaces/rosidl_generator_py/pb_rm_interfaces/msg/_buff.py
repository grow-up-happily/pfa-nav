# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/Buff.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Buff(type):
    """Metaclass of message 'Buff'."""

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
                'pb_rm_interfaces.msg.Buff')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__buff
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__buff
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__buff
            cls._TYPE_SUPPORT = module.type_support_msg__msg__buff
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__buff

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Buff(metaclass=Metaclass_Buff):
    """Message class 'Buff'."""

    __slots__ = [
        '_recovery_buff',
        '_cooling_buff',
        '_defence_buff',
        '_vulnerability_buff',
        '_attack_buff',
        '_remaining_energy',
    ]

    _fields_and_field_types = {
        'recovery_buff': 'uint8',
        'cooling_buff': 'uint8',
        'defence_buff': 'uint8',
        'vulnerability_buff': 'uint8',
        'attack_buff': 'uint16',
        'remaining_energy': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.recovery_buff = kwargs.get('recovery_buff', int())
        self.cooling_buff = kwargs.get('cooling_buff', int())
        self.defence_buff = kwargs.get('defence_buff', int())
        self.vulnerability_buff = kwargs.get('vulnerability_buff', int())
        self.attack_buff = kwargs.get('attack_buff', int())
        self.remaining_energy = kwargs.get('remaining_energy', int())

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
        if self.recovery_buff != other.recovery_buff:
            return False
        if self.cooling_buff != other.cooling_buff:
            return False
        if self.defence_buff != other.defence_buff:
            return False
        if self.vulnerability_buff != other.vulnerability_buff:
            return False
        if self.attack_buff != other.attack_buff:
            return False
        if self.remaining_energy != other.remaining_energy:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def recovery_buff(self):
        """Message field 'recovery_buff'."""
        return self._recovery_buff

    @recovery_buff.setter
    def recovery_buff(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'recovery_buff' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'recovery_buff' field must be an unsigned integer in [0, 255]"
        self._recovery_buff = value

    @builtins.property
    def cooling_buff(self):
        """Message field 'cooling_buff'."""
        return self._cooling_buff

    @cooling_buff.setter
    def cooling_buff(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cooling_buff' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cooling_buff' field must be an unsigned integer in [0, 255]"
        self._cooling_buff = value

    @builtins.property
    def defence_buff(self):
        """Message field 'defence_buff'."""
        return self._defence_buff

    @defence_buff.setter
    def defence_buff(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'defence_buff' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'defence_buff' field must be an unsigned integer in [0, 255]"
        self._defence_buff = value

    @builtins.property
    def vulnerability_buff(self):
        """Message field 'vulnerability_buff'."""
        return self._vulnerability_buff

    @vulnerability_buff.setter
    def vulnerability_buff(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vulnerability_buff' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'vulnerability_buff' field must be an unsigned integer in [0, 255]"
        self._vulnerability_buff = value

    @builtins.property
    def attack_buff(self):
        """Message field 'attack_buff'."""
        return self._attack_buff

    @attack_buff.setter
    def attack_buff(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'attack_buff' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'attack_buff' field must be an unsigned integer in [0, 65535]"
        self._attack_buff = value

    @builtins.property
    def remaining_energy(self):
        """Message field 'remaining_energy'."""
        return self._remaining_energy

    @remaining_energy.setter
    def remaining_energy(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'remaining_energy' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'remaining_energy' field must be an unsigned integer in [0, 255]"
        self._remaining_energy = value
