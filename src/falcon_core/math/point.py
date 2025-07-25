"""A point is a bunch of quantities indexed by connection."""

from typing import TYPE_CHECKING, cast, overload

from ..generic import Jsonable
from ..math.quantity import Quantity
from ..physics.units import SymbolUnit, Units

if TYPE_CHECKING:
    from ..physics.device_structures.base_connection import BaseConnection


type RawPoint = dict[BaseConnection, float]
type RawPointWUnits[T: SymbolUnit] = dict[BaseConnection, Quantity[T]]


class Point(Jsonable):
    """A bunch of quantities indexed by connection."""

    _coordinates: RawPointWUnits
    _unit: SymbolUnit

    @overload
    def __init__(self, coordinates: RawPointWUnits): ...

    @overload
    def __init__(self, coordinates: RawPoint, unit: SymbolUnit): ...

    def __init__(
        self,
        coordinates: RawPointWUnits | RawPoint,
        unit: SymbolUnit | None = None,
    ) -> None:
        """Starts the point object."""
        self._coordinates = {}
        if unit is None:
            self._unit = cast("SymbolUnit", Units.VOLT)
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
    def coordinates(self) -> RawPointWUnits:
        """Returns the coordinates of the point."""
        return self._coordinates

    @property
    def connections(self) -> list["BaseConnection"]:
        """Returns the connections of the point."""
        return list(self._coordinates.keys())

    @property
    def unit(self) -> SymbolUnit:
        """Returns the unit for the point."""
        return self._unit

    def __getitem__(self, index: "BaseConnection") -> "Quantity":
        """Returns the quantity at the index specified."""
        return self.coordinates[index]

    def __setitem__(
        self,
        index: "BaseConnection",
        value: "Quantity",
    ) -> None:
        """Sets the coordinate at the index and the value."""
        self._coordinates[index] = value
