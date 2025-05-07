"""Base class for all groups of connections."""

from .base_connection import BaseConnection
from .dependancies import Generic, Jsonable, TypeVar

T = TypeVar("T", bound=BaseConnection)


class BaseConnections(Jsonable, Generic[T]):
    """Contains multiple different connections for a single sample."""

    _values: list[T]

    def __init__(self, connections: list[T]):
        """Initialize the BaseConnections object.

        Args:
            a list of connection objects.
        """
        self._values = connections

    def __getitem__(self, index: int) -> T:
        """Get a connection by index."""
        return self._values[index]

    def __len__(self) -> int:
        """Get the number of connections."""
        return len(self._values)

    def __iter__(self):
        """Iterate over the connections."""
        return iter(self._values)

    def __contains__(self, item: T) -> bool:
        """Check if a connection is in the list."""
        return item in self._values

    def __setitem__(self, index: int, value: T) -> None:
        """Set a connection at a specific index.

        Args:
            index: The index to set the connection at.
            value: The connection object to set.
        """
        self._values[index] = value
