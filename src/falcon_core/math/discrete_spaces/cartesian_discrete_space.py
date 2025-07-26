"""A ND discrete space that is restricted to a cartesian domain."""

from typing import TYPE_CHECKING

from .base_cartesian_discrete_space import BaseCartesianDiscreteSpace
from .dependancies import (
    Axes,
    CartesianSpace,
    Domain,
    Jsonable,
)

if TYPE_CHECKING:
    from ...physics.device_structures import Connection
    from ...typing import Instrument
    from .dependancies import Axes
    from .typing import (
        CoupledKnobDomain,
    )


class CartesianDiscreteSpace(BaseCartesianDiscreteSpace, Jsonable):
    """A ND discrete space that is restricted to a cartesian domain."""

    @classmethod
    def from_divisions(
        cls,
        divisions: "Axes[int]",
        axes: "Axes[CoupledKnobDomain]",
        increasing: "Axes[dict[Connection | Instrument, bool]]",
        domain: Domain = Domain(bounds=(0, 1)),
    ) -> "BaseCartesianDiscreteSpace":
        """Create a CartesianDiscreteSpace from raw deltas.

        Args:
            divisions: the number of divisions for each axis.
            axes: the axes of the CartesianSpace.
            domain: the base domain of the CartesianSpace.

        Returns:
            CartesianDiscreteSpace: the CartesianDiscreteSpace.
        """
        assert len(divisions) == len(axes)
        deltas = [domain.range / division for division in divisions]
        return cls(
            space=CartesianSpace(deltas=deltas, domain=domain),
            axes=axes,
            increasing=increasing,
        )
