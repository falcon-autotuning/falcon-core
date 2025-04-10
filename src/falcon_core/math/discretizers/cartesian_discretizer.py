"""A special discretizer for cartesian coordinate systems."""

from .base_discretizer import BaseDiscretizer
from .dependancies import Domain


class CartesianDiscretizer(BaseDiscretizer):
    """A special discretizer for cartesian coordinate systems."""

    def __init__(self, delta: float):
        """Initialize the CartesianDiscretizer object."""
        domain = Domain(bounds=(-1.0, 1.0))
        super().__init__(delta=delta, domain=domain)
