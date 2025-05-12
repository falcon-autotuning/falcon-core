"""A collection of knobs."""

from typing import TYPE_CHECKING

from .knob import Knob
from .ports import Ports
from .dependancies import Jsonable

if TYPE_CHECKING:
    from .typing import Iterable


class Knobs(Ports[Knob], Jsonable):
    """A collection of knobs."""

    def __init__(self, knobs: "Knob | Iterable[Knob]") -> None:
        """Initialize the Knobs collection."""
        super().__init__(ports=knobs)
