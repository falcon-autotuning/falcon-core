"""A no frills implementation of a discrete space."""

from typing import TYPE_CHECKING

from .base_discrete_space import BaseDiscreteSpace
from .dependancies import Jsonable

if TYPE_CHECKING:
    from ...physics.device_structures import Connection
    from ...typing import Instrument
    from ..axes import Axes
    from .typing import CoupledKnobDomain, UnitSpace


class DiscreteSpace(BaseDiscreteSpace, Jsonable):
    """A no frills implementation of a discrete space."""

    def __init__(
        self,
        space: "UnitSpace",
        axes: "Axes[CoupledKnobDomain]",
        increasing: "Axes[dict['Connection | Instrument', bool]]",
    ):
        """Initialize the DiscreteSpace object.

        The order of the Knobs in the axes are defined to line up with the space.

        Args:
            space: the space that the discrete values fill.
            axes: the axes of the discrete values.
        """
        super().__init__(space=space, axes=axes, increasing=increasing)

    @property
    def space(self) -> "UnitSpace":
        """Return the space."""
        return self._space

    @property
    def axes(self) -> "Axes[CoupledKnobDomain]":
        """Return the axes."""
        return self._axes
