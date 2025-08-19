"""An array of 1D data."""

from .dependancies import Jsonable, uniform_filter1d
from .is_1D import Is1D
from .measured_array import MeasuredArray


class MeasuredArray1D(MeasuredArray, Is1D, Jsonable):
    """An array of 1D data."""

    def smooth(self, size: int):
        """Smooth the data using a uniform filter."""
        self._data = uniform_filter1d(
            input=self.data,
            size=size,
            mode="nearest",
        )
