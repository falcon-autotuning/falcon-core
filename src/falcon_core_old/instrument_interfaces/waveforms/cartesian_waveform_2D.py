"""A 2D measurement on a cartesian domain with any time dependant phenomena."""

from typing import TYPE_CHECKING

from .cartesian_waveform import CartesianWaveform
from .dependancies import Domain, Jsonable

if TYPE_CHECKING:
    from ...physics.device_structures import Connection
    from ...typing import Instrument
    from .typing import Axes, CoupledKnobDomain, PortTransform, Self


NUM_DIMENSIONS = 2


class CartesianWaveform2D(CartesianWaveform, Jsonable):
    """A 2D measurement on a cartesian domain with any time dependant phenomena."""

    @classmethod
    def from_divisions(
        cls,
        divisions: "Axes[int]",
        axes: "Axes[CoupledKnobDomain]",
        increasing: "Axes[dict[Connection | Instrument, bool]]",
        transforms: "list[PortTransform]" = [],
        domain: Domain = Domain(bounds=(0, 1)),
    ) -> "Self":
        """Create a CartesianWaveform from raw deltas.

        Args:
            divisions: the number of divisions for each axis.
            axes: the axes of the CartesianSpace.
            domain: the base domain of the CartesianSpace.
            transforms: the transforms to apply to the waveform.
            increasing: if the array should increase following the domain or not

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
            increasing=increasing,
        )
