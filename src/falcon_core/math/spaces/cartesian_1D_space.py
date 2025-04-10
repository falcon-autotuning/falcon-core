"""A Cartesian 1D space."""

from .cartesian_space import CartesianSpace
from .dependancies import Domain


class Cartesian1DSpace(CartesianSpace):
    """A Cartesian 1D space.

    A Cartesian 1D space is a unit space with a single axis.
    """

    def __init__(
        self,
        delta: float,
        domain=Domain(bounds=(0, 1), greater_bound_contained=False),
    ):
        """Initialize the Cartesian1DSpace object."""
        super().__init__(
            deltas=[delta],
            domain=domain,
        )
