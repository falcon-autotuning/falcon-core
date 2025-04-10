"""A Cartesian 2D space."""

from .cartesian_space import CartesianSpace
from .dependancies import Domain


class Cartesian2DSpace(CartesianSpace):
    """A Cartesian 2D space.

    A Cartesian 2D space is a unit space with a two axis.
    """

    def __init__(
        self,
        deltas: list[float],
        domain=Domain(bounds=(0, 1), greater_bound_contained=False),
    ):
        """Initialize the Cartesian1DSpace object."""
        assert len(deltas) == 2, "A 2D space must have two deltas."
        super().__init__(
            deltas=deltas,
            domain=domain,
        )
