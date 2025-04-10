"""An array of ND data."""

from .base_array import BaseArray
from .dependancies import Generic, Jsonable, TypeVar, arrayND

T = TypeVar("T", bound=arrayND)


class MeasuredArray(BaseArray, Jsonable, Generic[T]):
    """An array of ND data."""

    def __init__(self, data: T):
        """Initialize the MeasuredArray object."""
        BaseArray.__init__(self, data=data)
