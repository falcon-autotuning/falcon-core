"""A special transform that applies the Identity function to the data."""

from typing import TYPE_CHECKING

from .dependancies import Identity, Jsonable
from .port_transform import PortTransform

if TYPE_CHECKING:
    from .dependancies import Knob, Knobs


class IdentityTransform(PortTransform, Jsonable):
    """A special transform that applies the Identity function to the data."""

    def __init__(
        self,
        knob: "Knob",
        knobs: "Knobs",
    ):
        """Initialize the IdentityTransform object."""
        transform = Identity(knobs=knobs, knob=knob)
        super().__init__(port=knob, transform=transform)
