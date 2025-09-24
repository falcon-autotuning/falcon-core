"""A 1D discrete space that is restricted to a 1D cartesian domain."""

from typing import TYPE_CHECKING

from .base_cartesian_discrete_space import BaseCartesianDiscreteSpace
from .dependancies import Axes, Cartesian1DSpace, Domain, Jsonable

if TYPE_CHECKING:
    from ...physics.device_structures import Connection
    from ...typing import Instrument
    from .typing import CoupledKnobDomain


class CartesianDiscreteSpace1D(BaseCartesianDiscreteSpace, Jsonable):
    """A 1D discrete space that is restricted to a 1D cartesian domain."""

    @classmethod
    def from_division(
        cls,
        division: int,
        shared_domain: "CoupledKnobDomain",
        increasing: "Axes[dict[Connection | Instrument, bool]]",
        domain: Domain = Domain(bounds=(0, 1)),
    ) -> "BaseCartesianDiscreteSpace":
        """Create a CartesianDiscreteSpace1D from a single division.

        Args:
            division: the number of divisions for the axis.
            shared_domain: the domain of the axis.
            domain: the base domain of the Cartesian1DSpace.

        Returns:
            CartesianDiscreteSpace1D: the CartesianDiscreteSpace1D.
        """
        return cls(
            space=Cartesian1DSpace(delta=domain.range / division, domain=domain),
            axes=Axes([shared_domain]),
            increasing=increasing,
        )
