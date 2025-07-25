"""A point is a bunch of quantities indexed by connection."""

from typing import TYPE_CHECKING, cast, overload

from ..generic import Jsonable
from ..math.quantity import Quantity
from ..physics.units import SymbolUnit, Units

if TYPE_CHECKING:
    from ..physics.device_structures.base_connection import BaseConnection


type RawPoint = dict[BaseConnection, float]
type RawPointWUnits[T: SymbolUnit] = dict[BaseConnection, Quantity[T]]


class Point[T: SymbolUnit](Jsonable):
    """A bunch of quantities indexed by connection."""

    _coordinates: RawPointWUnits[T]
    _unit: T

    @overload
    def __init__(self, coordinates: RawPointWUnits[T]): ...

    @overload
    def __init__(self, coordinates: RawPoint, unit: T): ...

    def __init__(
        self,
        coordinates: RawPointWUnits | RawPoint,
        unit: T | None = None,
    ) -> None:
        """Starts the point object."""
        self._coordinates = {}
        if unit is None:
            self._unit = cast("T", Units.VOLT)
            for conn, value in coordinates.items():
                if isinstance(value, float | int):
                    self[conn] = Quantity(value, unit=self._unit)
                else:
                    value.convert_to(self._unit)
                    self[conn] = value
        else:
            self._unit = unit
            for conn, value in coordinates.items():
                if not isinstance(value, float | int):
                    msg = f"Only supports float or int type when setting a unit on init. The type received was {type(value)}."
                    raise TypeError(msg)
                self[conn] = Quantity(value, unit=self._unit)

    @property
    def coordinates(self) -> RawPointWUnits[T]:
        """Returns the coordinates of the point."""
        return self._coordinates

    @property
    def connections(self) -> list["BaseConnection"]:
        """Returns the connections of the point."""
        return list(self._coordinates.keys())

    @property
    def unit(self) -> T:
        """Returns the unit for the point."""
        return self._unit

    def __getitem__(self, index: "BaseConnection") -> "Quantity[T]":
        """Returns the quantity at the index specified."""
        return self.coordinates[index]

    def __setitem__(
        self,
        index: "BaseConnection",
        value: "Quantity[T]",
    ) -> None:
        """Sets the coordinate at the index and the value."""
        self._coordinates[index] = value
