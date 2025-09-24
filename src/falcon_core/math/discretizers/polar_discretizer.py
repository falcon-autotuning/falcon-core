"""A special discretizer for polar coordinate systems."""

from .base_discretizer import BaseDiscretizer
from .constants import PI
from .dependancies import Domain


class PolarDiscretizer(BaseDiscretizer):
    """A special discretizer for polar coordinate systems."""

    def __init__(self, delta: float):
        """Initialize the PolarDiscretizer object."""
        domain = Domain(bounds=(-2.0 * PI, 2.0 * PI))
        super().__init__(delta=delta, domain=domain)
