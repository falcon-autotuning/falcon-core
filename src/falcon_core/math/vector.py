"""Vector control parameters for feature optimizers."""

from typing import TYPE_CHECKING, cast

from ..dependancies import deepcopy, np, overload
from ..generic import Jsonable
from ..physics.device_structures.base_connection import BaseConnection
from ..physics.units import SymbolUnit, Units
from .point import Point
from .quantity import Quantity

if TYPE_CHECKING:
    from ..communications.voltage_states import DeviceVoltageStates
    from ..physics.device_structures.base_connection import BaseConnections
    from ..physics.units import SymbolUnit
    from .point import RawPoint, RawPointWUnits


class Vector(Jsonable):
    """A point in device gate space. And is N dimensional."""

    _end: "Point"
    _start: "Point"
    _connections: list[BaseConnection]
    _unit: "SymbolUnit"

    @overload
    def __init__(
        self,
        end_point: "RawPointWUnits",
    ): ...
    @overload
    def __init__(
        self,
        end_point: "RawPointWUnits",
        start_point: "RawPointWUnits",
    ): ...

    @overload
    def __init__(
        self,
        end_point: "RawPoint",
        start_point: None,
        unit: "SymbolUnit",
    ): ...
    @overload
    def __init__(
        self,
        end_point: "RawPoint",
        start_point: "RawPoint",
        unit: "SymbolUnit",
    ): ...

    @overload
    def __init__(
        self,
        end_point: "Point",
    ): ...

    @overload
    def __init__(
        self,
        end_point: "Point",
        start_point: "Point",
    ): ...

    def __init__(
        self,
        end_point: "RawPointWUnits | RawPoint | Point",
        start_point: "RawPointWUnits | RawPoint | Point | None" = None,
        unit: "SymbolUnit | None" = None,
    ) -> None:
        """Constructs a point.

        Args:
            value : the value of the point
            unit: optional type unit for the point
        """
        if unit is None:
            unit = cast("SymbolUnit", Units.VOLT)
        if not isinstance(end_point, Point):
            first = list(end_point.values())[0]
            if isinstance(first, float):
                end_point = cast("RawPoint", end_point)
                end_point = Point(
                    end_point,
                    unit=unit,
                )
            else:
                end_point = cast("RawPointWUnits", end_point)
                if unit is not None:
                    for quant in end_point.values():
                        quant.convert_to(unit)
                end_point = Point(end_point)
        if start_point is None:
            start_point = Point(
                {conn: 0.0 for conn in end_point.connections},
                unit=unit,
            )
        elif not isinstance(start_point, Point):
            first = list(start_point.values())[0]
            if isinstance(first, float):
                start_point = cast("RawPoint", start_point)
                start_point = Point(
                    start_point,
                    unit=unit,
                )
            else:
                start_point = cast("RawPointWUnits", start_point)
                if unit is not None:
                    for quant in start_point.values():
                        quant.convert_to(unit)
                start_point = Point(start_point)
        self._end = end_point
        self._start = start_point
        self._connections = list(
            set(end_point.connections).union(set(start_point.connections))
        )
        self._unit = end_point.unit

    @property
    def end(self) -> Point:
        """Returns the point at the end."""
        return self._end

    @property
    def start(self) -> Point:
        """Returns the point at the start."""
        return self._start

    @property
    def end_quantities(self) -> "RawPointWUnits":
        """Returns the map of quantities."""
        return self._end._coordinates

    @property
    def end_map(self) -> "RawPoint":
        """Returns the map of the point."""
        return {comp: value.value for comp, value in self.end_quantities.items()}

    @property
    def start_quantities(self) -> "RawPointWUnits":
        """Returns the map of quantities."""
        return self._start._coordinates

    @property
    def start_map(self) -> "RawPoint":
        """Returns the map of the point."""
        return {comp: value.value for comp, value in self.start_quantities.items()}

    @property
    def connections(self) -> list[BaseConnection]:
        """Returns the connections for a selected point."""
        return self._connections

    @property
    def principle_connection(self) -> BaseConnection:
        """Returns the principle_connections that are the greatest."""
        big_conn = self.connections[0]
        big_value = self.end_map[big_conn] - self.start_map[big_conn]
        for conn in self.connections:
            temp_value = self.end_map[conn] - self.start_map[conn]
            if temp_value > big_value:
                big_value = temp_value
                big_conn = conn
        return big_conn

    @property
    def unit(self) -> "SymbolUnit":
        """Returns the unit of the point."""
        return self._unit

    @property
    def magnitude(self) -> float:
        """The magnitude of the vector."""
        return np.sqrt(
            sum(
                [
                    (end - start) ** 2
                    for end, start in zip(
                        self.end_map.values(), self.start_map.values()
                    )
                ]
            )
        )

    @overload
    def __getitem__(self, connection: BaseConnection) -> tuple[float, float]: ...

    @overload
    def __getitem__(
        self, connection: "BaseConnections"
    ) -> list[tuple[float, float]]: ...

    def __getitem__(
        self,
        connection: "BaseConnections[BaseConnection] | BaseConnection",
    ) -> tuple[float, float] | list[tuple[float, float]]:
        """Returns the value of the component.

        Args:
            connection : the connection
        """
        if isinstance(connection, BaseConnection):
            if connection not in self.connections:
                msg = f"The connection {connection} is not inside the Vector. Available keys are {self.connections}"
                raise KeyError(msg)
            return (self.end_map[connection], self.start_map[connection])
        outs: list[tuple[float, float]] = []
        for conn in connection:
            outs.append(self[conn])
        return outs

    def __setitem__(
        self,
        connection: "BaseConnections[BaseConnection] | BaseConnection",
        value: tuple[float, float],
    ) -> None:
        """Sets the value of the component.

        Args:
            connection : the connection
            value : the value (start, end)
        """
        if isinstance(connection, BaseConnection):
            self._end[connection] = Quantity(value[1], self.unit)
            self._start[connection] = Quantity(value[0], self.unit)
        else:
            for conn in connection:
                self._end[conn] = Quantity(value[1], self.unit)
                self._start[conn] = Quantity(value[0], self.unit)

    def __neg__(self) -> "Vector":
        """The negation of a point is a point."""
        start = deepcopy(self.start_quantities)
        self.translate_to_origin()
        new = Vector(
            end_point={conn: -1 * quan for conn, quan in self.start_quantities.items()},
        )
        return new.translate(start)

    def update_start_from_states(self, state: "DeviceVoltageStates") -> "Vector":
        """Updates the vector to start from the given DeviceVoltageStates
        Args:
            state: the new device voltage state
        Returns:
            the displaced vector which starts at the given state.
        """
        new_origin = {}
        for dv_state in state.states:
            connection = dv_state.connection
            new_origin[connection] = Quantity(dv_state.value, unit=self.unit)
        return self.translate(new_origin)

    def translate(
        self,
        point: "RawPointWUnits | RawPoint | Point",
        unit: "SymbolUnit | None" = None,
    ) -> "Vector":
        """Displaces the origin of a vector by a point.

        Args:
            point: the displacement
            unit: the unit if the displacement is not Quantities

        Returns:
            the displaced vector that is translated
        """
        if unit is None:
            unit = self.unit
        if not isinstance(point, Point):
            first = list(point.values())[0]
            if isinstance(first, float):
                point = cast("RawPoint", point)
                point = Point(
                    point,
                    unit=unit,
                )
            else:
                point = cast("RawPointWUnits", point)
                if unit is not None:
                    for quant in point.values():
                        quant.convert_to(unit)
                point = Point(point)

        all_components = set(point.connections).union(self.connections)
        start = deepcopy(self.start)
        end = deepcopy(self.end)
        for component in all_components:
            if component not in point.connections:
                point[component] = Quantity(0.0, self.unit)
            if component not in start.connections:
                start[component] = Quantity(0.0, self.unit)
            if component not in end.connections:
                end[component] = Quantity(0.0, self.unit)

        for component in point.coordinates.values():
            component.convert_to(self.unit)
        for component, value in point.coordinates.items():
            start[component] += value.value
        for component, value in point.coordinates.items():
            end[component] += value.value
        return Vector(
            end_point=end,
            start_point=start,
        )

    def translate_to_origin(self) -> "Vector":
        """Translates a vector to the origin."""
        return self.translate(
            {conn: -1 * value for conn, value in self.start_quantities.items()}
        )

    def extend(self, extension: int | float) -> "Vector":
        """Extends a vector in place with its start point anchored."""
        origin = deepcopy(self.start_map)
        displacement = {component: -value for component, value in origin.items()}
        unit_vector = self.translate(point=displacement)
        scaled_vector = unit_vector * extension
        return scaled_vector.translate(
            point=origin,
            unit=self.unit,
        )

    def shrink(self, shrink: int | float) -> "Vector":
        """Shrinks a vector in place with its start point anchored."""
        origin = deepcopy(self.start_map)
        displacement = {component: -value for component, value in origin.items()}
        unit_vector = self.translate(point=displacement)
        scaled_vector = unit_vector / shrink
        return scaled_vector.translate(
            point=origin,
            unit=self.unit,
        )

    @property
    def unit_vector(self) -> "Vector":
        """Generates the unit vector for the direction of the vector."""
        unit_vector = self.translate(
            point={
                component: -1 * value
                for component, value in self.start_quantities.items()
            }
        )
        return unit_vector / self.magnitude

    def __add__(self, other: "Vector") -> "Vector":
        """The addition of two points is a vector."""
        return Vector(
            start_point=self.start_quantities,
            end_point=other.translate(point=self.end_quantities).end_quantities,
        )

    def __sub__(self, other: "Vector") -> "Vector":
        """The subtraction of two vector is a vector."""
        return self + (-other)

    def __mul__(self, other: float | int) -> "Vector":
        """The multiplication of a vector by a scalar is a vector."""
        return Vector(
            end_point={
                connection: value * other for connection, value in self.end_map.items()
            },
            start_point={
                connection: value * other
                for connection, value in self.start_map.items()
            },
            unit=self.unit,
        )

    def __rmul__(self, other: float | int) -> "Vector":
        """The reverse multiplication of a vector by a scalar is a vector."""
        return other * self

    def __truediv__(self, other: float | int) -> "Vector":
        """The division of a vector by a scalar is a vector."""
        # return (1 / float(other)) * self
        return Vector(
            end_point={
                connection: value / float(other)
                for connection, value in self.end_map.items()
            },
            start_point={
                connection: value / float(other)
                for connection, value in self.start_map.items()
            },
            unit=self.unit,
        )

    def normalize(self) -> "Vector":
        """Returns the normalized vector starting at the anchored starting point."""
        return self.shrink(self.magnitude)

    def project(self, other: "Vector") -> "Vector":
        """Projects ourself onto the other vector."""
        if other.unit != self.unit:
            for quant in other.end_quantities.values():
                quant.convert_to(self.unit)
            for quant in other.start_quantities.values():
                quant.convert_to(self.unit)
        origin_other = other.translate(
            {comp: -value for comp, value in other.start_map.items()}
        )
        origin = self.start_map
        origin_self = self.translate(
            {comp: -value for comp, value in self.start_map.items()}
        )
        shared_components = set(self.connections).intersection(set(other.connections))
        end = {
            comp: origin_self.end_map[comp] * origin_other.end_map[comp]
            for comp in shared_components
        }
        out = Vector(
            end_point=end,
            unit=self.unit,
            start_point=None,
        )
        return out.translate(origin, unit=self.unit)
