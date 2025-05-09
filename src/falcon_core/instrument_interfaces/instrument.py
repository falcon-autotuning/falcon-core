"""A typing class for instruments."""

from .dependancies import Jsonable


class Instrument(Jsonable):
    """A name indexer for the types of instruments."""

    _value: str

    def __init__(self, value: str) -> None:
        """Initialize the Instrument object.

        Args:
            value: The value of the instrument.
        """
        self._value = value

    @property
    def value(self) -> str:
        """Return the value of the instrument."""
        return self._value
