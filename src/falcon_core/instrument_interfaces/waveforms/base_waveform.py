"""A distinct measurement.

Consisting of a measurement domain and any time dependant phenomena.
"""

from typing import TYPE_CHECKING

from .dependancies import (
    BaseDiscreteSpace,
    Jsonable,
    PortTransforms,
    TypeVar,
)

if TYPE_CHECKING:
    from .typing import PortTransform


class BaseWaveform[T: BaseDiscreteSpace](PortTransforms, Jsonable):
    """A distinct measurement.

    consists of a measurement domain and \
          any time dependant phenomena.

    you need a tranform for each knob in the space.
    """

    _space: T

    def __init__(
        self,
        space: T,
        transforms: "list[PortTransform]" = [],
    ):
        """Initialize the Waveform object."""
        super().__init__(transforms=transforms)
        self._space = space
        self.confirm_knobs_match()

    def confirm_knobs_match(self):
        """Confirm that the Knob for the function is in the function's space.

        Confirm that all the Knobs for the functions are in the DiscreteSpace.
        """
        discrete_knobs = [knob for axis in self._space._axes for knob in axis.knobs]
        function_knobs = [knob.port for knob in self.transforms]
        assert set(function_knobs).issubset(discrete_knobs), (
            f"Function knobs do not match discrete space. The function has {[name for name in function_knobs]} and the discrete space has {discrete_knobs}."
        )
