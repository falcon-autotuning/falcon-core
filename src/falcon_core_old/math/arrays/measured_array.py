"""An array of ND data."""

from .base_array import BaseArray
from .dependancies import Jsonable, arrayND


class MeasuredArray[T: arrayND](
    BaseArray,
    Jsonable,
):
    """An array of ND data."""

    def __init__(self, data: T):
        """Initialize the MeasuredArray object."""
        BaseArray.__init__(self, data=data)
