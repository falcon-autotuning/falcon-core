"""Dependencies for the waveform module."""

from ...dependancies import chain
from ...generic import Jsonable
from ...instrument_interfaces.names import Knob, Knobs
from ...math.discrete_spaces import CartesianDiscreteSpace, CartesianDiscreteSpace1D
from ...math.discrete_spaces.base_cartesian_discrete_space import (
    BaseCartesianDiscreteSpace,
)
from ...math.discrete_spaces.base_discrete_space import BaseDiscreteSpace
from ...math.domains import Domain
from ...typing import Generic, TypeVar
from ..port_transforms import IdentityTransform, KnobTransforms

__all__ = [
    "chain",
    "Knob",
    "Knobs",
    "Jsonable",
    "Generic",
    "TypeVar",
    "Domain",
    "KnobTransforms",
    "IdentityTransform",
    "BaseDiscreteSpace",
    "BaseCartesianDiscreteSpace",
    "CartesianDiscreteSpace1D",
    "CartesianDiscreteSpace",
]
