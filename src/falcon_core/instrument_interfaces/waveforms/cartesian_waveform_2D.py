"""A 2D measurement on a cartesian domain with any time dependant phenomena."""

from typing import TYPE_CHECKING

from .cartesian_waveform import CartesianWaveform
from .dependancies import Domain, Jsonable

if TYPE_CHECKING:
    from .typing import (
        Axes,
        CoupledKnobDomain,
        KnobTransform,
        Self,
    )


NUM_DIMENSIONS = 2


class CartesianWaveform2D(CartesianWaveform, Jsonable):
    """A 2D measurement on a cartesian domain with any time dependant phenomena."""

    @classmethod
    def from_divisions(
        cls,
        divisions: "Axes[int]",
        axes: "Axes[CoupledKnobDomain]",
        transforms: "list[KnobTransform]" = [],
        domain: Domain = Domain(bounds=(0, 1)),
    ) -> "Self":
        """Create a CartesianWaveform from raw deltas.

        Args:
            divisions: the number of divisions for each axis.
            axes: the axes of the CartesianSpace.
            domain: the base domain of the CartesianSpace.
            transforms: the transforms to apply to the waveform.

        Returns:
            CartesianWaveform: the CartesianWaveform.
        """
        assert divisions.dimension == axes.dimension == NUM_DIMENSIONS, (
            f"Expected {NUM_DIMENSIONS} dimensions, got {divisions.dimension} and {axes.dimension}"
        )
        return super().from_divisions(
            divisions=divisions,
            axes=axes,
            transforms=transforms,
            domain=domain,
        )
