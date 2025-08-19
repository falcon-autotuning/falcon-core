"""Dependencies for the spaces module."""

from ...dependancies import itertools, np
from ...generic import Jsonable
from ..arrays import ControlArray, ControlArray1D
from ..arrays.base_array import BaseArray
from ..axes import Axes
from ..discretizers import CartesianDiscretizer, PolarDiscretizer
from ..domains import Domain

__all__ = [
    "ControlArray",
    "ControlArray1D",
    "BaseArray",
    "itertools",
    "np",
    "CartesianDiscretizer",
    "PolarDiscretizer",
    "Domain",
    "Jsonable",
    "Axes",
]
