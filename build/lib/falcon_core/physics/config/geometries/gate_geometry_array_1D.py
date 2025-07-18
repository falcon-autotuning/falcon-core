"""An array of gates forming a 1D current channel."""

from typing import TYPE_CHECKING

from .barrier_gate_with_neighbors import BarrierGateWithNeighbors
from .dependancies import (
    BarrierGate,
    DotGate,
    Gates,
    Jsonable,
    Ohmic,
    PlungerGate,
    ReservoirGate,
)
from .left_reservoir_with_implanted_ohmic import LeftReservoirWithImplantedOhmic
from .plunger_gate_with_neighbors import PlungerGateWithNeighbors
from .right_reservoir_with_implanted_ohmic import RightReservoirWithImplantedOhmic
from .typing import (
    Ohmics,
)

if TYPE_CHECKING:
    from .dependancies import (
        BaseConnections,
    )
    from .typing import (
        Connection,
        Gate,
        ScreeningGates,
    )


class GateGeometryArray1D(Jsonable):
    """An assumption made about the geometry of the gates in the device.

    The assumed geometry is a 1D array:
                            Screening Gate
        Ohmic, Reservoir, DotGates ... DotGates, Reservoir, Ohmic
                            Screening Gate

    Located around that channel are screening gates.
    """

    _left_reservoir: "LeftReservoirWithImplantedOhmic"
    _right_reservoir: "RightReservoirWithImplantedOhmic"
    _left_barrier: "BarrierGateWithNeighbors"
    _right_barrier: "BarrierGateWithNeighbors"
    _central_dot_gates: list["PlungerGateWithNeighbors | BarrierGateWithNeighbors"]
    _raw_central_gates: "Gates"
    _ohmics: "Ohmics"
    _screening_gates: "ScreeningGates"
    _lineararray: "BaseConnections"

    def __init__(
        self,
        lineararray: "BaseConnections",
        screening_gates: "ScreeningGates",
    ):
        """Starts the geometry of the gates.

        Args:
            lineararray (Connections): The gates and ohmics in the channel.
            screening_gates (ScreeningGates): The screening gates
            bottom_screening_gate (ScreeningGate): The bottom screening gate.
        """
        if len(screening_gates) != 2:
            msg = "Expected two screening gates."
            raise ValueError(msg)
        self._screening_gates = screening_gates
        self._lineararray = lineararray
        if len(lineararray) % 2 == 0:
            msg = f"Expected an odd number of elements in the linear array. Got {len(lineararray)} elements."
            raise ValueError(msg)

        if (not isinstance(lineararray[0], Ohmic)) or (
            not isinstance(lineararray[-1], Ohmic)
        ):
            msg = "Expected Ohmic at the ends of the linear array."
            raise TypeError(msg)

        self._ohmics = Ohmics([lineararray[0], lineararray[-1]])

        if (not isinstance(lineararray[1], ReservoirGate)) or (
            not isinstance(lineararray[-2], ReservoirGate)
        ):
            msg = f"Expected Reservoir Gates bounding the central dot gates. For reference, the linear array is {lineararray}"
            raise TypeError(msg)

        dot_gates = lineararray[2:-2]

        self.store_raw_central_gates(dot_gates=dot_gates)

        if not all([isinstance(gate, DotGate) for gate in dot_gates]):
            msg = f"Expected DotGates in the middle of the linear array. For reference, the gates in the middle of the linear array were {dot_gates}"
            raise TypeError(msg)

        if (not isinstance(dot_gates[0], BarrierGate)) or (
            not isinstance(dot_gates[-1], BarrierGate)
        ):
            msg = "Expected Barrier Gates bounding the exterior reservoir gates."
            raise TypeError(msg)

        if (not isinstance(dot_gates[1], PlungerGate)) or (
            not isinstance(dot_gates[-2], PlungerGate)
        ):
            msg = "Expected Barrier Gates bounding the exterior reservoir gates."
            raise TypeError(msg)

        self._left_reservoir = LeftReservoirWithImplantedOhmic(
            name=lineararray[1].name,
            ohmic=lineararray[0],
            right_neighbor=dot_gates[0],
        )
        self._right_reservoir = RightReservoirWithImplantedOhmic(
            name=lineararray[-2].name,
            ohmic=lineararray[-1],
            left_neighbor=dot_gates[-1],
        )

        self._left_barrier = BarrierGateWithNeighbors(
            name=dot_gates[0].name,
            left_neighbor=lineararray[1],
            right_neighbor=dot_gates[1],
        )

        self._right_barrier = BarrierGateWithNeighbors(
            name=dot_gates[-1].name,
            left_neighbor=dot_gates[-2],
            right_neighbor=lineararray[-2],
        )

        self._central_dot_gates = []
        for i in range(3, len(lineararray) - 3):
            selected_gate = lineararray[i]
            left_neighbor = lineararray[i - 1]
            right_neighbor = lineararray[i + 1]
            assert isinstance(selected_gate, DotGate)
            assert isinstance(left_neighbor, DotGate)
            assert isinstance(right_neighbor, DotGate)
            self.store_central_gate(
                selected_gates=[left_neighbor, selected_gate, right_neighbor],
            )

    @property
    def left_reservoir(self) -> "LeftReservoirWithImplantedOhmic":
        """The left reservoir in the geometry."""
        return self._left_reservoir

    @property
    def right_reservoir(self) -> "RightReservoirWithImplantedOhmic":
        """The right reservoir in the geometry."""
        return self._right_reservoir

    @property
    def left_barrier(self) -> "BarrierGateWithNeighbors":
        """The left barrier in the geometry."""
        return self._left_barrier

    @property
    def right_barrier(self) -> "BarrierGateWithNeighbors":
        """The right barrier in the geometry."""
        return self._right_barrier

    @property
    def central_dot_gates(
        self,
    ) -> "list[PlungerGateWithNeighbors | BarrierGateWithNeighbors]":
        """The central dot gates in the geometry."""
        return self._central_dot_gates

    @property
    def raw_central_gates(self) -> "Gates":
        """The raw gates in the geometry."""
        return self._raw_central_gates

    @property
    def ohmics(self) -> "Ohmics":
        """The ohmics in the geometry."""
        return self._ohmics

    @property
    def screening_gates(self) -> "ScreeningGates":
        """The screening gates in the geometry."""
        return self._screening_gates

    @property
    def lineararray(self) -> "BaseConnections":
        """The linear array of gates in the geometry."""
        return self._lineararray

    def __iter__(self):
        """Iterates over the gates in the geometry."""
        return iter(self._lineararray)

    def store_raw_central_gates(self, dot_gates: "list[Connection]") -> None:
        """Stores the raw gates in the geometry.

        Args:
            dot_gates (Connections): The dot gates.
        """
        out = []
        for gate in dot_gates:
            if isinstance(gate, DotGate):
                out.append(gate)
            else:
                msg = f"Expected DotGates in the middle of the linear array. For reference, the gates in the middle of the linear array were {dot_gates}"
                raise TypeError(msg)
        self._raw_central_gates = Gates(out)  # type: ignore[assignment]

    def store_central_gate(
        self,
        selected_gates: list[DotGate],
    ) -> None:
        """Stores a central gate in the geometry.

        Each array should contain 3 elements, the left neighbor, the selected gate, and the right neighbor.

        Args:
            selected_gates (list[DotGate, DotGate, DotGate]): The selected gates.
            selected_types (list[PlungerGate | BarrierGate]): The selected types.
        """
        left_neighbor = selected_gates[0]
        selected_gate = selected_gates[1]
        right_neighbor = selected_gates[2]
        if isinstance(selected_gate, BarrierGate):
            if not isinstance(left_neighbor, PlungerGate):
                msg = "Expected PlungerGate bounding selected BarrierGate."
                raise TypeError(msg)
            if not isinstance(right_neighbor, PlungerGate):
                msg = "Expected PlungerGate bounding selected BarrierGate."
                raise TypeError(msg)
            self.central_dot_gates.append(
                BarrierGateWithNeighbors(
                    name=selected_gate.name,
                    left_neighbor=left_neighbor,
                    right_neighbor=right_neighbor,
                )
            )
        elif isinstance(selected_gate, PlungerGate):
            if not isinstance(left_neighbor, BarrierGate):
                msg = "Expected BarrierGate bounding selected PlungerGate."
                raise TypeError(msg)
            if not isinstance(right_neighbor, BarrierGate):
                msg = "Expected BarrierGate bounding selected PlungerGate."
                raise TypeError(msg)
            self.central_dot_gates.append(
                PlungerGateWithNeighbors(
                    name=selected_gate.name,
                    left_neighbor=left_neighbor,
                    right_neighbor=right_neighbor,
                )
            )
        else:
            msg = "Expected either a PlungerGate or BarrierGate."
            raise TypeError(msg)

    def all_dot_gates(
        self,
    ) -> list["PlungerGateWithNeighbors | BarrierGateWithNeighbors"]:
        """Gets all of the dot gates in the geometry.

        Returns:
            list[PlungerGateWithNeighbors | BarrierGateWithNeighbors]: The dot gates.
        """
        return [
            self.left_barrier,
            *self.central_dot_gates,
            self.right_barrier,
        ]

    def query_neighbors(
        self,
        gate: "Gate",
    ) -> "Gates":
        """Queries the neighbors of a gate.

        Args:
            gate (Gate): The gate to query.

        Returns:
            Gates: The neighbors.
        """
        name = gate.name

        for gate_geometry in [
            *self.screening_gates,
            self.left_reservoir,
            self.right_reservoir,
            *self.all_dot_gates(),
        ]:
            if name != gate_geometry.name:
                continue
            if gate_geometry in self.screening_gates:
                return Gates(
                    [
                        self.left_barrier.left_neighbor,
                        *self.raw_central_gates,
                        self.right_barrier.right_neighbor,
                    ]
                )
            if gate_geometry == self.left_reservoir:
                return Gates(
                    [
                        self.left_reservoir.right_neighbor,
                        *self.screening_gates,
                    ]
                )
            if gate_geometry == self.right_reservoir:
                return Gates(
                    [
                        self.right_reservoir.left_neighbor,
                        *self.screening_gates,
                    ]
                )
            assert isinstance(
                gate_geometry,
                BarrierGateWithNeighbors | PlungerGateWithNeighbors,
            )
            return Gates(
                [
                    gate_geometry.left_neighbor,
                    gate_geometry.right_neighbor,
                    *self.screening_gates,
                ]
            )
        msg = f"Gate {name} not found in geometry."
        raise ValueError(msg)
