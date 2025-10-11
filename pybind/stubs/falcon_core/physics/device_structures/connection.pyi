from __future__ import annotations
import builtins as __builtin__
from falcon_core.generic.song import Song
from falcon_core.physics.device_structures import _falcon_core_connection
import sys
import typing
__all__: list[str] = ['Connection', 'ConnectionSP', 'DeviceFeature_BarrierGate', 'DeviceFeature_Ohmic', 'DeviceFeature_PlungerGate', 'DeviceFeature_ReservoirGate', 'DeviceFeature_ScreeningGate', 'SHARED_PTR_DISOWN', 'Song']
class Connection:
    __hash__: typing.ClassVar[None] = None
    @staticmethod
    def BarrierGate(name):
        """
        
        Construct a BarrierGate with a name.
        :type name: string
        :param name: The name of the connection.
        """
    @staticmethod
    def Ohmic(name):
        """
        
        Construct a Ohmic with a name.
        :type name: string
        :param name: The name of the connection.
        """
    @staticmethod
    def PlungerGate(name):
        """
        
        Construct a PlungerGate with a name.
        :type name: string
        :param name: The name of the connection.
        """
    @staticmethod
    def ReservoirGate(name):
        """
        
        Construct a ReservoirGate with a name.
        :type name: string
        :param name: The name of the connection.
        """
    @staticmethod
    def ScreeningGate(name):
        """
        
        Construct a ScreeningGate with a name.
        :type name: string
        :param name: The name of the connection.
        """
    @staticmethod
    def __swig_destroy__(object):
        ...
    @staticmethod
    def from_json_string(json):
        ...
    def __eq__(self, other):
        ...
    def __init__(self, name, type):
        """
        
        Construct a Connection with a name and type.
        :type name: string
        :param name: The name of the connection.
        :type type: int
        :param type: The type of the connection (DeviceFeature).
        """
    def __lt__(self, other):
        ...
    def __ne__(self, other):
        ...
    def __repr__(self):
        ...
    def is_barrier_gate(self):
        """
        Check if the connection is a barriergate.
        """
    def is_dot_gate(self):
        """
        Check if the connection is a plungergate or barriergate.
        """
    def is_gate(self):
        """
        
        Check if the connection is any type of gate (barrier, plunger,
        reservoir, screening).
        """
    def is_ohmic(self):
        """
        Check if the connection is an ohmic contact.
        """
    def is_plunger_gate(self):
        """
        Check if the connection is a plunger gate.
        """
    def is_reservoir_gate(self):
        """
        Check if the connection is a reservoir gate.
        """
    def is_screening_gate(self):
        """
        Check if the connection is a screening gate.
        """
    def name(self):
        """
        
        The name of the connection.
        :rtype: string
        :return: The name as a string.
        """
    def type(self):
        """
        
        The type of the connection.
        :rtype: string
        :return: The type as a string.
        """
    @property
    def thisown(self):
        """
        The membership flag
        """
    @thisown.setter
    def thisown(self, v):
        ...
class ConnectionSP:
    __hash__: typing.ClassVar[None] = None
    @staticmethod
    def __swig_destroy__(object):
        ...
    def __eq__(self, other):
        ...
    def __init__(self):
        ...
    def __neq__(self, other):
        ...
    def __repr__(self):
        ...
    def is_barrier_gate(self):
        ...
    def is_dot_gate(self):
        ...
    def is_gate(self):
        ...
    def is_ohmic(self):
        ...
    def is_plunger_gate(self):
        ...
    def is_reservoir_gate(self):
        ...
    def is_screening_gate(self):
        ...
    def name(self):
        ...
    def to_json_string(self):
        ...
    def type(self):
        ...
    @property
    def thisown(self):
        """
        The membership flag
        """
    @thisown.setter
    def thisown(self, v):
        ...
class _SwigNonDynamicMeta(type):
    """
    Meta class to enforce nondynamic attributes (no new attributes) for a class
    """
    @classmethod
    def __setattr__(cls, name, value):
        ...
def _swig_add_metaclass(metaclass):
    """
    Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass
    """
def _swig_repr(self):
    ...
def _swig_setattr_nondynamic_class_variable(set):
    ...
def _swig_setattr_nondynamic_instance_variable(set):
    ...
DeviceFeature_BarrierGate: int = 0
DeviceFeature_Ohmic: int = 4
DeviceFeature_PlungerGate: int = 1
DeviceFeature_ReservoirGate: int = 2
DeviceFeature_ScreeningGate: int = 3
SHARED_PTR_DISOWN: int = 0
_swig_python_version_info: sys.version_info  # value = sys.version_info(major=3, minor=13, micro=7, releaselevel='final', serial=0)
