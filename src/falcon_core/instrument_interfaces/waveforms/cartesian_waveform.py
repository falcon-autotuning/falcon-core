"""A ND measurement on a cartesian domain with any time dependant phenomena."""

from typing import TYPE_CHECKING

from .base_cartesian_waveform import BaseCartesianWaveform
from .dependancies import (
    CartesianDiscreteSpace,
    Domain,
    IdentityTransform,
    Jsonable,
    Knobs,
    chain,
)

if TYPE_CHECKING:
    from ...physics.device_structures import Connection
    from ...typing import Instrument
    from .typing import Axes, CoupledKnobDomain, PortTransform, Self


class CartesianWaveform(BaseCartesianWaveform[CartesianDiscreteSpace], Jsonable):
    """A ND measurement on a cartesian domain with any time dependant phenomena."""

    @classmethod
    def from_divisions(
        cls,
        divisions: "Axes[int]",
        axes: "Axes[CoupledKnobDomain]",
        increasing: "Axes[dict[Connection | Instrument, bool]]",
        transforms: list["PortTransform"] = [],
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
        space = CartesianDiscreteSpace.from_divisions(
            divisions=divisions,
            axes=axes,
            domain=domain,
            increasing=increasing,
        )
        assert isinstance(space, CartesianDiscreteSpace), (
            "Space must be CartesianDiscreteSpace"
        )
        return cls(
            space=space,
            transforms=transforms,
        )

    @classmethod
    def setup_identity_everywhere(
        cls,
        divisions: "Axes[int]",
        axes: "Axes[CoupledKnobDomain]",
        increasing: "Axes[dict[Connection | Instrument, bool]]",
        domain: Domain = Domain(bounds=(0, 1)),
    ) -> "Self":
        """Create a CartesianWaveform with identity transforms.

        Args:
            divisions: the number of divisions for each axis.
            axes: the axes of the CartesianSpace.
            domain: the base domain of the CartesianSpace.
            increasing: if the array should increase following the domain or not

        Returns:
            CartesianWaveform: the CartesianWaveform.
        """
        space = CartesianDiscreteSpace.from_divisions(
            divisions=divisions,
            axes=axes,
            domain=domain,
            increasing=increasing,
        )
        knobs = Knobs(
            chain.from_iterable([knob_domain.knobs for knob_domain in axes.axes])
        )
        assert isinstance(space, CartesianDiscreteSpace), (
            "Space must be CartesianDiscreteSpace"
        )
        return cls(
            space=space,
            transforms=[IdentityTransform(knob, knobs) for knob in knobs],
        )
