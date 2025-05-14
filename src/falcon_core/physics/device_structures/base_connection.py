"""A generic BaseConnection on a quantum dot device."""

from typing import TYPE_CHECKING

from .dependancies import Generic, Jsonable, TypeVar, overload

if TYPE_CHECKING:
    from .typing import Any

T = TypeVar("T", bound="BaseConnection")


class BaseConnections(Jsonable, Generic[T]):
    """Contains multiple different connections for a single sample."""

    _values: list[T]

    def __init__(self, connections: list[T]):
        """Initialize the BaseConnections object.

        Args:
            a list of connection objects.
        """
        self._values = connections

    @overload
    def __getitem__(self, index: int) -> T: ...
    @overload
    def __getitem__(self, index: slice) -> list[T]: ...
    def __getitem__(self, index: int | slice) -> T | list[T]:
        """Get a connection by index."""
        if isinstance(index, slice):
            return self._values[index]
        return self._values[index]

    def __len__(self) -> int:
        """Get the number of connections."""
        return len(self._values)

    def __iter__(self):
        """Iterate over the connections."""
        return iter(self._values)

    def __contains__(self, item: "Any") -> bool:
        """Check if a connection is in the list."""
        if isinstance(item, BaseConnection):
            return item in self._values
        return False

    def __setitem__(self, index: int, value: T) -> None:
        """Set a connection at a specific index.

        Args:
            index: The index to set the connection at.
            value: The connection object to set.
        """
        self._values[index] = value

    def index(self, value: T) -> int:
        """Get the index of a connection.

        Args:
            value: The connection object to find.

        Returns:
            The index of the connection object.
        """
        return self._values.index(value)


class BaseConnection(Jsonable):
    """Contains the name corresponding to a particular BaseConnection on the sample."""

    _name: str

    def __init__(
        self,
        name: str,
    ) -> None:
        """Initialize the BaseConnection object.

        Args:
            name (str): The name of the BaseConnection.
        """
        self._name = name

    @property
    def name(self) -> str:
        """Return the name of the BaseConnection."""
        return self._name

    @overload
    def __add__(
        self,
        other: str,
    ) -> str: ...

    @overload
    def __add__(
        self,
        other: "BaseConnections | BaseConnection",
    ) -> "BaseConnections": ...

    def __add__(
        self,
        other: "str | BaseConnections | BaseConnection",
    ) -> str | BaseConnections:
        """Addition support."""
        if isinstance(other, str):
            return self.name + other
        if isinstance(other, BaseConnection):
            return BaseConnections([self, other])
        if isinstance(other, list):
            for element in other:
                if not isinstance(element, BaseConnection):
                    msg = f"Addition only works between Gate and Ohmic objects through concatenation. You supplied a {type(element)}"
                    raise TypeError(msg)
            other.append(self)
            return other
        msg = f"Addition only works between Gate and Ohmic objects through concatenation. You supplied a {type(other)}"
        raise TypeError(msg)

    def __radd__(
        self,
        other: "str | BaseConnections | BaseConnection",
    ) -> str | BaseConnections:
        """Addition support."""
        return self.__add__(other)

    def __str__(self) -> str:
        return self.name
