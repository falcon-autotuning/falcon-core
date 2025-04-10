"""All the various types of DiscreteSpaces available to use."""

from .cartesian_discrete_space import CartesianDiscreteSpace
from .cartesian_discrete_space_1D import CartesianDiscreteSpace1D
from .cartesian_discrete_space_2D import CartesianDiscreteSpace2D
from .discrete_space import DiscreteSpace

__all__ = [
    "DiscreteSpace",
    "CartesianDiscreteSpace",
    "CartesianDiscreteSpace2D",
    "CartesianDiscreteSpace1D",
]
