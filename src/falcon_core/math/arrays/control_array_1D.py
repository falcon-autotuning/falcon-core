"""An array of 1D data."""

from .control_array import ControlArray
from .dependancies import Jsonable
from .is_1D import Is1D


class ControlArray1D(ControlArray, Is1D, Jsonable):
    """A domain array of 1D data."""
