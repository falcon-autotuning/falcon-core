"""A special type of discrete space that is restricted to a cartesian domain."""

from typing import TYPE_CHECKING

from .base_discrete_space import BaseDiscreteSpace
from .dependancies import CartesianSpace, Jsonable, Knobs

if TYPE_CHECKING:
    from ...physics.device_structures import Connection
    from ...typing import Instrument
    from .dependancies import Axes
    from .typing import CoupledKnobDomain


class BaseCartesianDiscreteSpace(BaseDiscreteSpace, Jsonable):
    """A special type of discrete space that is restricted to a cartesian domain."""

    def __init__(
        self,
        space: CartesianSpace,
        axes: "Axes[CoupledKnobDomain]",
        increasing: "Axes[dict[Connection | Instrument, bool]]",
    ):
        """Initialize the CartesianDiscreteSpace object."""
        super().__init__(space=space, axes=axes, increasing=increasing)

    @property
    def space(self) -> "CartesianSpace":
        """Return the space."""
        assert isinstance(self._space, CartesianSpace), (
            "The space is not a CartesianSpace."
        )
        return self._space

    @property
    def axes(self) -> "Axes[CoupledKnobDomain]":
        """Return the axes."""
        return self._axes

    @property
    def knobs(self):
        """Return the knobs."""
        return Knobs([knob for axis in self._axes for knob in axis.knobs])
