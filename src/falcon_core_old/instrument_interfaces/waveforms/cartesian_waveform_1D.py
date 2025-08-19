"""A 1D measurement on a cartesian domain with any time dependant phenomena."""

from typing import TYPE_CHECKING

from .base_cartesian_waveform import BaseCartesianWaveform
from .dependancies import CartesianDiscreteSpace1D, Domain, IdentityTransform

if TYPE_CHECKING:
    from ...math.axes import Axes
    from ...physics.device_structures import Connection
    from ...typing import Instrument
    from .typing import CoupledKnobDomain, PortTransform


class CartesianWaveform1D(BaseCartesianWaveform[CartesianDiscreteSpace1D]):
    """A 1D measurement on a cartesian domain with any time dependant phenomena."""

    def __init__(
        self,
        space: CartesianDiscreteSpace1D,
        transforms: "list[PortTransform]" = [],
    ):
        super().__init__(space, transforms)

    @classmethod
    def from_division(
        cls: type["CartesianWaveform1D"],
        division: int,
        shared_domain: "CoupledKnobDomain",
        increasing: "Axes[dict[Connection | Instrument, bool]]",
        transforms: list["PortTransform"] = [],
        domain: Domain = Domain(bounds=(0, 1)),
    ):
        """Create a CartesianWaveform from raw deltas.

        Args:
            division: the number of divisions for the axis.
            shared_domain: the domain of the principal axis.
            domain: the base domain of the CartesianSpace.
            transforms: the transforms to apply to the waveform.
            increasing: if the array should increase following the domain or not

        Returns:
            CartesianWaveform: the CartesianWaveform.
        """
        space = CartesianDiscreteSpace1D.from_division(
            division=division,
            shared_domain=shared_domain,
            increasing=increasing,
            domain=domain,
        )
        assert isinstance(space, CartesianDiscreteSpace1D), (
            "Space must be CartesianDiscreteSpace1D"
        )
        return cls(
            space=space,
            transforms=transforms,
        )

    @classmethod
    def setup_identity_everywhere(
        cls,
        division: int,
        shared_domain: "CoupledKnobDomain",
        increasing: "Axes[dict[Connection | Instrument, bool]]",
        domain: Domain = Domain(bounds=(0, 1)),
    ):
        """Create a CartesianWaveform from raw deltas.

        Args:
            division: the number of divisions for the axis.
            shared_domain: the domain of the principal axis.
            domain: the base domain of the CartesianSpace.
            increasing: if the array should increase following the domain or not

        Returns:
            CartesianWaveform: the CartesianWaveform.
        """
        space = CartesianDiscreteSpace1D.from_division(
            division=division,
            shared_domain=shared_domain,
            domain=domain,
            increasing=increasing,
        )
        assert isinstance(space, CartesianDiscreteSpace1D), (
            "Space must be CartesianDiscreteSpace1D"
        )
        knobs = shared_domain.knobs
        return cls(
            space=space,
            transforms=[IdentityTransform(knob, knobs) for knob in knobs],
        )
