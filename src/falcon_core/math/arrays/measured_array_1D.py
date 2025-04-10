"""An array of 1D data."""

from .dependancies import Jsonable
from .is_1D import Is1D
from .measured_array import MeasuredArray


class MeasuredArray1D(MeasuredArray, Is1D, Jsonable):
    """An array of 1D data."""
