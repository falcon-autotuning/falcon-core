"""A primitiv class to organize fridge impedance calibrations."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .base_connection import BaseConnection


class Impedances(Jsonable):
    """A collection of impedances."""

    _values: list["Impedance"]

    def __init__(self, impedances: list["Impedance"]) -> None:
        """Initialize the Impedances object.

        Args:
            impedances (list[Impedance]): A list of impedance objects.
        """
        self._values = impedances

    def __getitem__(self, index: int) -> "Impedance":
        """Get an impedance by index."""
        return self._values[index]

    def __len__(self) -> int:
        """Get the number of impedances."""
        return len(self._values)

    def __iter__(self):
        """Iterate over the impedances."""
        return iter(self._values)

    def __contains__(self, item: "Impedance") -> bool:
        """Check if an impedance is in the list."""
        return item in self._values

    def index(self, value: "Impedance") -> int:
        """Get the index of an impedance.

        Args:
            value: The impedance object to find.

        Returns:
            The index of the impedance object.
        """
        return self._values.index(value)


class Impedance(Jsonable):
    """The net impedance of the fridge wiring leading to connection on sample."""

    _connection: "BaseConnection"
    _resistance: float
    _capacitance: float

    def __init__(
        self,
        connection: "BaseConnection",
        resistance: float,
        capacitance: float,
    ) -> None:
        """Initialize the Impedance object."""
        self._connection = connection
        self._resistance = resistance
        self._capacitance = capacitance

    @property
    def connection(self) -> "BaseConnection":
        """The connection to the sample."""
        return self._connection

    @property
    def resistance(self) -> float:
        """The net resistance leading to the sample in the fridge [1/S]."""
        return self._resistance

    @property
    def capacitance(self) -> float:
        """The net capacitance leading to the sample in the fridge [F]."""
        return self._capacitance
