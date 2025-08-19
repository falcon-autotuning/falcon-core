"""Typing definitions for waveforms within the instrument interfaces."""

from ...math.axes import Axes
from ...math.domains import CoupledKnobDomain
from ...typing import Self, Sequence
from ..names import Knob
from ..port_transforms.port_transform import PortTransform

__all__ = [
    "PortTransform",
    "CoupledKnobDomain",
    "Self",
    "Axes",
    "Knob",
    "Sequence",
]
