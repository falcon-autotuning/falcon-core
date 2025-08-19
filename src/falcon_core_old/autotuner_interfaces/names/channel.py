"""A primitive model for a current channel on a quantum dot device."""

from .dependancies import Jsonable


class Channels(Jsonable):
    """A collection of channels."""

    _values: list["Channel"]

    def __init__(self, values: list["Channel"]) -> None:
        self._values = values

    def __iter__(self):
        """How a Channels acts like an iterable."""
        return iter(self._values)

    def __len__(self) -> int:
        """How a Channels acts like a length."""
        return len(self._values)

    def __getitem__(self, index: int) -> "Channel":
        """How a Channels acts like a list."""
        return self._values[index]

    def __setitem__(self, index: int, value: "Channel") -> None:
        """How a Channels acts like a list."""
        self._values[index] = value

    def __contain__(self, value: "Channel") -> bool:
        """How a Channels acts like a list."""
        return value in self._values


class Channel(Jsonable):
    """A string corresponsing to the name of a Channel."""

    _name: str

    def __init__(self, name: str) -> None:
        self._name = name

    @property
    def name(self) -> str:
        """The name of the channel."""
        return self._name

    def __str__(self) -> str:
        """How a Channel acts like a string."""
        return self.name
