"""A Cartesian space."""

from .dependancies import Axes, CartesianDiscretizer, Domain, Jsonable
from .unit_space import UnitSpace


class CartesianSpace(UnitSpace, Jsonable):
    """A Cartesian ND space.

    A Cartesian ND space is a unit space with a N axis.
    """

    def __init__(
        self,
        deltas: list[float],
        domain=Domain(bounds=(0, 1), greater_bound_contained=False),
    ):
        """Initialize the Cartesian1DSpace object."""
        super().__init__(
            axes=Axes([CartesianDiscretizer(delta=delta) for delta in deltas]),
            domain=domain,
        )
