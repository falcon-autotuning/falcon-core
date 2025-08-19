"""A special transform that applies the multiplicative constant function to the data."""

from typing import TYPE_CHECKING

from .dependancies import Constant, Jsonable
from .port_transform import PortTransform

if TYPE_CHECKING:
    from .typing import Ports


class ConstantTransform(PortTransform, Jsonable):
    """A special transform that applies the Constant function to the data."""

    def __init__(
        self,
        scale: float,
        ports: "Ports",
    ):
        """Initialize the IdentityTransform object."""
        transform = Constant(ports=ports, scale=scale)
        super().__init__(transform=transform, port=ports[0])
        # we are supplying port[0] for no reason other than to satify init
