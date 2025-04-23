"""A restricted Enum class that only allows JsonablePrimitive values."""

from .dependancies import Enum as StandardEnum
from .dependancies import JSONprimitives


class Enum(StandardEnum):
    """A restricted Enum class that only allows JsonablePrimitive values."""

    def __new__(cls, value):
        """When making a new Enum we need to validate the value."""
        # Validate that the value is a JsonablePrimitive
        if not isinstance(value, JSONprimitives):
            msg = f"Enum value must be a JsonablePrimitive (int, float, str, or None), got {type(value).__name__}"
            raise TypeError(msg)
        obj = object.__new__(cls)
        obj._value_ = value
        return obj
