"""A specific type of port_tranform that is used to handle data in a time frame going into a port."""

from .dependancies import Meter
from .port_transforms import PortTransforms


class MeterTransforms(PortTransforms[Meter]):
    """A specific type of port_tranform that is used to handle data in a time frame going into a port."""
