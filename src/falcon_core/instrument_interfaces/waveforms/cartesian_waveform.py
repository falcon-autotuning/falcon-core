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
    from .dependancies import Knob
    from .typing import Axes, CoupledKnobDomain, PortTransform, Self


class CartesianWaveform(BaseCartesianWaveform[CartesianDiscreteSpace], Jsonable):
    """A ND measurement on a cartesian domain with any time dependant phenomena."""

    @classmethod
    def from_divisions(
        cls,
        divisions: "Axes[int]",
        axes: "Axes[CoupledKnobDomain]",
        transforms: list["PortTransform[Knob]"],
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
        space = CartesianDiscreteSpace.from_divisions(
            divisions=divisions,
            axes=axes,
            domain=domain,
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
        domain: Domain = Domain(bounds=(0, 1)),
    ) -> "Self":
        """Create a CartesianWaveform with identity transforms.

        Args:
            divisions: the number of divisions for each axis.
            axes: the axes of the CartesianSpace.
            domain: the base domain of the CartesianSpace.

        Returns:
            CartesianWaveform: the CartesianWaveform.
        """
        space = CartesianDiscreteSpace.from_divisions(
            divisions=divisions,
            axes=axes,
            domain=domain,
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
