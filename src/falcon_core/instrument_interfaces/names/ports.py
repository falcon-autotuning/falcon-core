"""A collection of ports."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable, contextlib
from .instrument_port import InstrumentPort
from .knob import Knob
from .meter import Meter
from .typing import Generic, Iterable, TypeVar

if TYPE_CHECKING:
    from .typing import Connection, Iterator

T = TypeVar("T", bound=Knob | Meter | InstrumentPort)


class Ports(Jsonable, Generic[T]):
    """A collection of ports."""

    _ports: list["T"]

    def __init__(self, ports: Iterable[T] | T | None = None) -> None:
        """Initialize a collection of ports.

        Args:
            ports: Can be:
                - None (creates an empty collection)
                - A single port object
                - An iterable of port objects
                - Multiple port objects (when used with *ports in subclasses)
        """
        if ports is None:
            self._ports = []
        elif isinstance(ports, Iterable) and not isinstance(ports, str | bytes):
            # Convert to list to ensure we can iterate multiple times
            self._ports = list(ports)
        else:
            # Single port object
            self._ports = [ports]  # type: ignore  # noqa: PGH003

    @property
    def ports(self) -> list["T"]:
        """Return the list of knobs."""
        return self._ports

    def __len__(self) -> int:
        """Return the number of knobs."""
        return len(self.ports)

    def __iter__(self) -> "Iterator[T]":
        """Return an iterator over the knobs."""
        return iter(self.ports)

    def __getitem__(self, key: int | str) -> "T":
        """Get a port by index or name.

        Args:
            key: The index or name of the port.

        Returns:
            The port at the given index or with the given name.

        Raises:
            KeyError: If no port with the given name is found
        """
        if not isinstance(key, str):
            return self.ports[key]
        for port in self.ports:
            if port.default_name == key:
                return port
        msg = f"No port with name '{key}'"
        raise KeyError(msg)

    def __contains__(self, item: T | str) -> bool:
        """Check if a port or port name is in this collection.

        Args:
            item: The port or port name to check for.

        Returns:
            True if the port or port name is in the collection, False otherwise.
        """
        if isinstance(item, str):
            return any(port.default_name == item for port in self.ports)
        return item in self.ports

    def append(self, port: "T") -> None:
        """Add a knob to the collection."""
        self.ports.append(port)

    def get_default_names(self) -> list[str]:
        """Return the default names of the ports."""
        return [port.default_name for port in self.ports]

    def get_pseudo_names(self) -> list["Connection"]:
        """Return the pseudo names of the ports.

        Raises:
            ValueError: If some ports do not have pseudo names.
        """
        with contextlib.suppress(ValueError):
            return [
                port.pseudo_name for port in self.ports if port.pseudo_name is not None
            ]
        msg = "Some ports do not have pseudo names."
        raise ValueError(msg)

    def _get_raw_names(self) -> list[str]:
        """Return the raw string names of the ports."""
        return [pseudo_name.name for pseudo_name in self.get_pseudo_names()]
