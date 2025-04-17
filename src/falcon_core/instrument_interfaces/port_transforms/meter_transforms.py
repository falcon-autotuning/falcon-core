"""A specific type of port_tranform that is used to handle data in a time frame going into a port."""

from typing import TYPE_CHECKING

from .dependancies import Meter
from .port_transforms import PortTransforms

if TYPE_CHECKING:
    from .meter_transform import MeterTransform


class MeterTransforms(PortTransforms[Meter]):
    """A specific type of port_tranform that is used to handle data in a time frame going into a port."""

    def __init__(
        self,
        transforms: "list[MeterTransform]",
    ):
        """Initialize the PortTransform object."""
        self._transforms = transforms
