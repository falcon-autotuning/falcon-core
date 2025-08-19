"""A special transform that applies the Identity function to the data."""

from typing import TYPE_CHECKING

from .dependancies import Identity, Jsonable
from .port_transform import PortTransform

if TYPE_CHECKING:
    from .dependancies import InstrumentPort
    from .typing import Ports


class IdentityTransform(PortTransform, Jsonable):
    """A special transform that applies the Identity function to the data."""

    def __init__(
        self,
        port: "InstrumentPort",
        ports: "Ports",
    ):
        """Initialize the IdentityTransform object."""
        transform = Identity(ports=ports, port=port)
        super().__init__(port=port, transform=transform)
