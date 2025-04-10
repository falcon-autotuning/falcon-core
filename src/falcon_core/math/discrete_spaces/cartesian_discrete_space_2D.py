"""A special type of discrete space that is restricted to a 2D cartesian domain."""

from typing import TYPE_CHECKING

from .cartesian_discrete_space import CartesianDiscreteSpace
from .dependancies import Jsonable

if TYPE_CHECKING:
    from .dependancies import Axes, CartesianSpace
    from .typing import CoupledKnobDomain

NUM_DIMENSIONS = 2


class CartesianDiscreteSpace2D(CartesianDiscreteSpace, Jsonable):
    """A special type of discrete space that is restricted to a 2D cartesian domain."""

    def __init__(self, space: "CartesianSpace", axes: "Axes[CoupledKnobDomain]"):
        """Initialize the CartesianDiscreteSpace2D object.

        Args:
            space: the space of the discrete values.
            axes: the axes of the discrete values.

        Raises:
            ValueError: if the axes do not have a dimension of NUM_DIMENSIONS.
        """
        if axes.dimension != NUM_DIMENSIONS:
            msg = f"The axes must have a dimension of {NUM_DIMENSIONS} for CartesianDiscreteSpace2D."
            raise ValueError(msg)
        super().__init__(space, axes)
