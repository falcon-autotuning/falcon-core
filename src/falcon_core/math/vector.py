"""Vector control parameters for feature optimizers."""

from collections.abc import Mapping
from typing import TYPE_CHECKING, cast

from ..generic import Jsonable
from .quantity import Quantity

from physics.device_structures.base_connection import BaseConnection

from ..dependancies import deepcopy, np, overload

if TYPE_CHECKING:
    from falcon_core.communications.voltage_states import DeviceVoltageStates
    from falcon_core.physics.units import SymbolUnit

    from physics.device_structures.base_connection import BaseConnections

type Point = Mapping[BaseConnection, Quantity]
type RawPoint = Mapping[BaseConnection, float]


class Vector(Jsonable):
    """A point in device gate space. And is N dimensional."""

    _end_quantities: Point
    _start_quantities: Point
    _connections: list[BaseConnection]
    _unit: "SymbolUnit"

    @overload
    def __init__(self, end_point: Point): ...
    @overload
    def __init__(self, end_point: Point, start_point: Point): ...

    @overload
    def __init__(self, end_point: RawPoint, start_point: None, unit: "SymbolUnit"): ...
    @overload
    def __init__(
        self, end_point: RawPoint, start_point: RawPoint, unit: "SymbolUnit"
    ): ...

    def __init__(
        self,
        end_point: Point | RawPoint,
        start_point: Point | RawPoint | None = None,
        unit: "SymbolUnit | None" = None,
    ) -> None:
        """Constructs a point.

        Args:
            value : the value of the point
            unit: optional type unit for the point
        """
        end_connections = set(end_point.keys())
        all_connections = end_connections
        self._connections = list(all_connections)
        if start_point is not None:
            all_connections = set(start_point.keys()).union(set(end_point.keys()))
        primary_quantity = list(end_point.values())[0]
        extra_end_connections = all_connections - end_connections
        if isinstance(primary_quantity, Quantity):
            self._unit = primary_quantity.unit
            for quant in end_point.values():
                if not isinstance(quant, Quantity):
                    msg = "Mixed types were used. All of the values must be Quantity or float not some of each."
                    raise TypeError(msg)
                quant.convert_to(self._unit)
            end_point = cast("Point", end_point)
            self._end_quantities = end_point
        else:
            if unit is None:
                msg = "The unit needs to specified when Quantities are not used"
                raise ValueError(msg)
            self._unit = unit
            end_point = cast("RawPoint", end_point)
            self._end_quantities = {
                comp: Quantity(value, unit=self.unit)
                for comp, value in end_point.items()
            }
        for connection in extra_end_connections:
            self._end_quantities = {
                connection: Quantity(0.0, unit=self.unit),
                **self._end_quantities,
            }
        self._start_quantities = {
            c: Quantity(0.0, unit=self.unit) for c in all_connections
        }
        if start_point is not None:
            extra_start_connections = all_connections - set(start_point.keys())
            primary_quantity = list(start_point.values())[0]
            if isinstance(primary_quantity, Quantity):
                for quant in start_point.values():
                    if not isinstance(quant, Quantity):
                        msg = "Mixed types were used. All of the values must be Quantity or float not some of each."
                        raise TypeError(msg)
                    quant.convert_to(self._unit)
                start_point = cast("Point", start_point)
                self._start_quantities = start_point
            else:
                if unit is None:
                    msg = "The unit needs to specified when Quantities are not used"
                    raise ValueError(msg)
                self._unit = unit
                start_point = cast("RawPoint", start_point)
                self._start_quantities = {
                    comp: Quantity(value, unit=self.unit)
                    for comp, value in start_point.items()
                }

            for connection in extra_start_connections:
                self._start_quantities = {
                    connection: Quantity(0.0, unit=self.unit),
                    **self._start_quantities,
                }

    @property
    def end_quantities(self) -> Point:
        """Returns the map of quantities."""
        return self._end_quantities

    @property
    def end_map(self) -> RawPoint:
        """Returns the map of the point."""
        return {comp: value.value for comp, value in self.end_quantities.items()}

    @property
    def start_quantities(self) -> Point:
        """Returns the map of quantities."""
        return self._start_quantities

    @property
    def start_map(self) -> RawPoint:
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
            self._end_quantities = {
                connection: Quantity(value[1], unit=self.unit),
                **self._end_quantities,
            }
            self._start_quantities = {
                connection: Quantity(value[0], unit=self.unit),
                **self._start_quantities,
            }
        else:
            for conn in connection:
                self._end_quantities = {
                    conn: Quantity(value[1], unit=self.unit),
                    **self._end_quantities,
                }
                self._start_quantities = {
                    conn: Quantity(value[0], unit=self.unit),
                    **self._start_quantities,
                }

    def __neg__(self) -> "Vector":
        """The negation of a point is a point."""
        return Vector(
            end_point=self.start_quantities,
            start_point=self.end_quantities,
        )

    # def __neg__(self) -> "Vector":
    #     """The negation of a point is a point."""
    #     return Vector(
    #         end_point=self.end_quantities,
    #         start_point={k: -1 * v for k, v in self.start_quantities.items()},
    #     )

    def update_start_from_states(self, state: "DeviceVoltageStates") -> "Vector":
        """Updates the vector to start from the given DeviceVoltageStates
        Args:
            state: the new device voltage state
        Returns:
            the displaced vector which starts at the given state.
        """
        new_origin = {}
        # for connection in self._end_quantities:
        #     dv_state = state.find_state(connection)
        #     if dv_state is None:
        #         raise RuntimeError(
        #             f"Vector contains a connection {connection} which is not in the current device voltage states."
        #         )
        #     new_origin[connection] = Quantity(dv_state.value, unit=self._unit)
        for dv_state in state.states:
            connection = dv_state.connection
            new_origin[connection] = Quantity(dv_state.value, unit=self._unit)
        return self.translate(new_origin)

    def translate(
        self,
        point: Point | RawPoint,
        unit: "SymbolUnit | None" = None,
    ) -> "Vector":
        """Displaces the origin of a vector by a point.

        Args:
            point: the displacement
            unit: the unit if the displacement is not Quantities

        Returns:
            the displaced vector that is translated
        """
        all_components = set(point.keys()).union(self.connections)
        primary_component = list(point.values())[0]
        start = {component: 0.0 for component in all_components}
        end = {component: 0.0 for component in all_components}
        for component, value in self.start_map.items():
            start[component] += value
        for component, value in self.end_map.items():
            end[component] += value
        if not isinstance(primary_component, Quantity):
            if unit is None:
                msg = "The unit must be specified when not using Quantities"
                raise TypeError(msg)
            point = cast("RawPoint", point)
            point = {
                component: Quantity(value=value, unit=unit)
                for component, value in point.items()
            }
        point = cast("Point", point)
        for component in point.values():
            component.convert_to(self.unit)
        for component, value in point.items():
            start[component] += value.value
        for component, value in point.items():
            end[component] += value.value
        return Vector(
            end_point=end,
            start_point=start,
            unit=self.unit,
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
