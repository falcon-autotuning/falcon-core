"""A distinct measurement.

Consisting of a measurement domain and any time dependant phenomena.
"""

from .base_waveform import BaseWaveform
from .dependancies import (
    BaseDiscreteSpace,
)


class Waveform(BaseWaveform):
    """A distinct measurement.

    consists of a measurement domain and \
          any time dependant phenomena.
    """

    @property
    def space(self) -> BaseDiscreteSpace:
        """Return the cartesian space."""
        space = self._space
        assert isinstance(space, BaseDiscreteSpace), (
            f"Expected CartesianDiscreteSpace, got {type(space)}"
        )
        return space
