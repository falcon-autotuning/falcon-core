"""Template for standard core config functionality."""

from typing import TYPE_CHECKING

from .constants import CONNECTION_TO_ATTRIBUTE_NAME
from .dependancies import (
    BarrierGate,
    DotGate,
    Jsonable,
    PlungerGate,
    deepcopy,
    overload,
)
from .typing import (
    BaseConnections,
    DotGates,
    Gates,
)

if TYPE_CHECKING:
    from .dependancies import Ohmics
    from .typing import (
        BarrierGates,
        Connection,
        Connections,
        Gate,
        Ohmic,
        PlungerGates,
        ReservoirGate,
        ReservoirGates,
        ScreeningGate,
        ScreeningGates,
        UsefulConnectionType,
    )


class StandardConfigConnections(Jsonable):
    """Base config functionality. Used for core config classes."""

    _screening_gates: "ScreeningGates"
    _reservoir_gates: "ReservoirGates"
    _plunger_gates: "PlungerGates"
    _barrier_gates: "BarrierGates"
    _ohmics: "Ohmics"

    def __init__(
        self,
        screening_gates: "ScreeningGates",
        reservoir_gates: "ReservoirGates",
        plunger_gates: "PlungerGates",
        barrier_gates: "BarrierGates",
        ohmics: "Ohmics",
    ) -> None:
        """Constructs the different gate types holders.

        Args:
            screening_gates (ScreeningGates): The screening gates.
            reservoir_gates (ReservoirGates): The reservoir gates.
            plunger_gates (PlungerGates): The plunger gates.
            barrier_gates (BarrierGates): The barrier gates.
            ohmics (Ohmics): The ohmics.
        """
        self._screening_gates = screening_gates
        self._reservoir_gates = reservoir_gates
        self._plunger_gates = plunger_gates
        self._barrier_gates = barrier_gates
        self._ohmics = ohmics

    @property
    def screening_gates(self) -> "ScreeningGates":
        """The screening gates of the config."""
        return self._screening_gates

    @property
    def reservoir_gates(self) -> "ReservoirGates":
        """The reservoir gates of the config."""
        return self._reservoir_gates

    @property
    def plunger_gates(self) -> "PlungerGates":
        """The plunger gates of the config."""
        return self._plunger_gates

    @property
    def barrier_gates(self) -> "BarrierGates":
        """The barrier gates of the config."""
        return self._barrier_gates

    @property
    def ohmics(self) -> "Ohmics":
        """The ohmics of the config."""
        return self._ohmics

    @overload
    def get_connections(  # noqa: D102
        self,
        connection_type: type["Ohmic"],
    ) -> "Ohmics": ...

    @overload
    def get_connections(  # noqa: D102, F811 , PGH003# type: ignore
        self,
        connection_type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def get_connections(  # noqa: D102, F811
        self,
        connection_type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def get_connections(  # noqa: D102, F811
        self,
        connection_type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def get_connections(  # noqa: D102, F811
        self,
        connection_type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    @overload
    def get_connections(  # noqa: F811, D102
        self,
        connection_type: type["DotGate"],
    ) -> "DotGates": ...

    @overload
    def get_connections(  # noqa: F811, D102
        self,
        connection_type: type["Gate"],
    ) -> "Gates": ...

    def get_connections(  # noqa: F811
        self,
        connection_type: "UsefulConnectionType",
    ) -> "Connections":
        """Gets connections of the list of type from the config.

        Args:
            connection_type: one of the types of connections

        Returns:
            list of connections of the type
        """
        if connection_type in CONNECTION_TO_ATTRIBUTE_NAME:
            return deepcopy(
                self.__getattribute__(CONNECTION_TO_ATTRIBUTE_NAME[connection_type])  # type: ignore  # noqa: PGH003
            )
        if connection_type == DotGate:
            return DotGates(
                [
                    *self.get_connections(connection_type=PlungerGate),
                    *self.get_connections(connection_type=BarrierGate),
                ]
            )
        return self.get_all_gates()

    @overload
    def get_connection(  # noqa: D102
        self,
        connection_type: type["Ohmic"],
    ) -> "Ohmic": ...

    @overload
    def get_connection(  # noqa: D102, F811
        self,
        connection_type: type["BarrierGate"],
    ) -> "BarrierGate": ...

    @overload
    def get_connection(  # noqa: D102, F811
        self,
        connection_type: type["PlungerGate"],
    ) -> "PlungerGate": ...

    @overload
    def get_connection(  # noqa: D102, F811
        self,
        connection_type: type["ReservoirGate"],
    ) -> "ReservoirGate": ...

    @overload
    def get_connection(  # noqa: D102, F811
        self,
        connection_type: type["ScreeningGate"],
    ) -> "ScreeningGate": ...

    @overload
    def get_connection(  # noqa: F811, D102
        self,
        connection_type: type["DotGate"],
    ) -> "DotGate": ...

    @overload
    def get_connection(  # noqa: F811, D102
        self,
        connection_type: type["Gate"],
    ) -> "Gate": ...

    def get_connection(  # noqa: F811
        self,
        connection_type: "UsefulConnectionType",
    ) -> "Connection":
        """Gets the first connection of the list of type from the config.

        Args:
            connection_type: one of the types of connections

        Returns:
            connection of the type
        """
        return self.get_connections(connection_type)[0]

    def get_all_gates(self) -> "Gates":
        """Gets all of the gates for this collection from the Config."""
        return Gates(
            [
                *self.screening_gates,
                *self.reservoir_gates,
                *self.plunger_gates,
                *self.barrier_gates,
            ]
        )

    def get_all_ohmics(self) -> "Ohmics":
        """Gets all of the ohmics for this collection from the Config."""
        return deepcopy(self.ohmics)

    def get_all_connections(self) -> "BaseConnections":
        """Gets all of the connections for this collection from the Config."""
        return BaseConnections(
            [
                *self.get_all_gates(),
                *self.get_all_ohmics(),
            ]
        )

    def has_ohmic(self, ohmic: "Ohmic") -> bool:
        """If this Ohmic is a member of this group or not.

        Args:
            ohmic : to be querried

        Returns:
            existence
        """
        return ohmic in self.get_all_ohmics()

    def has_gate(self, gate: "Gate") -> bool:
        """If this Gate is a member of this group or not.

        Args:
            gate : to be querried

        Returns:
            existence
        """
        return gate in self.get_all_gates()
