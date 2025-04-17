"""Many transfromations for port objects to analytic time domain functions."""

from typing import TYPE_CHECKING

from .dependancies import Knob
from .port_transforms import PortTransforms

if TYPE_CHECKING:
    from .knob_transform import KnobTransform
    from .port_transform import PortTransform
    from .typing import Sequence


class KnobTransforms(PortTransforms[Knob]):
    """Many transfromations for port objects to analytic time domain functions."""

    def __init__(
        self,
        transforms: "list[KnobTransform] | Sequence[PortTransform[Knob]]",
    ):
        """Initialize the PortTransform object."""
        self._transforms = transforms
