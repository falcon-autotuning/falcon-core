"""Various classes associated with the config dictionary uponloadup."""

from typing import TYPE_CHECKING

from ..geometries import NeighborGate
from .constants import CONNECTION_TO_ATTRIBUTE_NAME
from .dependancies import (
    DotGate,
    Gate,
    GateRelations,
    Jsonable,
    Ohmic,
    ReservoirGate,
    ScreeningGate,
    collections,
    overload,
)
from .standard_config_connections import StandardConfigConnections
from .typing import (
    Gates,
)

if TYPE_CHECKING:
    from .dependancies import (
        BarrierGate,
        Ohmics,
        PlungerGate,
    )
    from .group import Group
    from .typing import (
        BarrierGates,
        BaseConnection,
        Channel,
        Channels,
        Connection,
        DotGates,
        Gname,
        Impedance,
        Impedances,
        Mapping,
        PlungerGates,
        ReservoirGates,
        ScreeningGates,
        UsefulGates,
        UsefulGateType,
    )


class Config(StandardConfigConnections, Jsonable):
    """The imported config for the autotuner."""

    _num_unique_channels: int
    _groups: dict["Gname", "Group"]
    _wiring_DC: "Impedances"
    _channels: "Channels"

    def __init__(
        self,
        screening_gates: "ScreeningGates",
        plunger_gates: "PlungerGates",
        ohmics: "Ohmics",
        barrier_gates: "BarrierGates",
        reservoir_gates: "ReservoirGates",
        groups: dict["Gname", "Group"],
        wiring_DC: "Impedances",
    ) -> None:
        """After the constructor provides some verification on Gates imported."""
        super().__init__(
            screening_gates=screening_gates,
            plunger_gates=plunger_gates,
            ohmics=ohmics,
            barrier_gates=barrier_gates,
            reservoir_gates=reservoir_gates,
        )
        self._groups = groups
        self._wiring_DC = wiring_DC
        self._num_unique_channels = len(self.get_all_gnames())
        assert self._num_unique_channels > 0

        self.compile_channels()
        self.check_group_consistency()
        self.check_impendance_consistency()

    @property
    def num_unique_channels(self) -> int:
        return self._num_unique_channels

    @property
    def groups(self) -> dict["Gname", "Group"]:
        return self._groups

    @property
    def wiring_DC(self) -> "Impedances":
        return self._wiring_DC

    @property
    def channels(self) -> "Channels":
        return self._channels

    def check_impendance_consistency(self) -> None:
        """Check that all impedances are consistent.

        None of the gates or ohmics should be missing from the impedances.

        Raises:
            ValueError: If the impedances are inconsistent
        """
        if len(self.wiring_DC) == 0:
            return
        for connection in self.get_all_connections():
            if connection not in [impedance.connection for impedance in self.wiring_DC]:
                msg = f"{connection} not in wiringDC. Include all or none."
                raise ValueError(msg)

    def check_group_consistency(self) -> None:
        """Check that all groups are consistent.

        None of the gates or ohmics should be missing from the groups.

        Raises:
            ValueError: If the groups are inconsistent
        """
        for connection_type, connection_name in CONNECTION_TO_ATTRIBUTE_NAME.items():
            collection: list[BaseConnection] = []
            for group in self.get_all_groups():
                collection += group.get_connections(connection_type=connection_type)
            if set(self.__getattribute__(connection_name)) != set(collection):
                msg = f"Inconsistent {connection_name} between groups and the total"
                raise ValueError(msg)

    def get_impedance(
        self,
        connection: "BaseConnection",
    ) -> "Impedance | None":
        """Searches through the config and finds the connection in the dcwiring."""
        for impedance in self.wiring_DC:
            if impedance.connection == connection:
                return impedance
        return None

    def get_all_gnames(self) -> list["Gname"]:
        """Searches through the config and finds all group names."""
        return list(self.groups.keys())

    def get_all_groups(self) -> list["Group"]:
        """Searches through config and finds all Group."""
        return list(self.groups.values())

    def compile_channels(self) -> None:
        """Searches through all Group and collects all of the Channel."""
        self._channels = [group.name for group in self.get_all_groups()]

    def has_channel(self, channel: "Channel") -> bool:
        """Validates if this is a proper Channel name in the set of all device Channels.

        Args:
            channel : the Channel that is to be tested

        Returns:
            existence
        """
        return channel in self._channels

    def has_gname(self, group: "Gname") -> bool:
        """Validates if this is a proper gatename.

        Args:
            group: the selected group that needs to be checked.

        Returns:
            existence
        """
        return group in self.get_all_gnames()

    def select_group(self, gname: "Gname") -> "Group | None":
        """Finds a group from the name and returns it.

        Args:
            gname : the Gname to search for

        Returns:
        the associated group if it exists.
        """
        if self.has_gname(group=gname):
            return self.groups[gname]
        return None

    def get_dot_number(self, channel: "Channel") -> int | None:
        """Task to find the number of dots associated with a current channel from the config.

        Args:
            channel : the current channel we are searching for

        Returns:
            The value found in the config
        """
        if not self.has_channel(channel=channel):
            return None
        for group in self.get_all_groups():
            if group.has_channel(channel=channel):
                return group.get_num_dots()
        return None

    def ohmic_in_charge_sensor(self, ohmic: Ohmic) -> bool | None:
        """If the ohmic is inside of a charge sensor channel this outputs true.

        Args:
            ohmic : the ohmic that we are interested in diagnosing

        Returns:
            boolean if ohmic is valid
        """
        if not self.has_ohmic(ohmic=ohmic):
            return None
        for group in self.get_all_groups():
            if group.is_chargesensor() and group.has_ohmic(ohmic=ohmic):
                return True
        return False

    def get_associated_ohmic(self, rgate: "ReservoirGate") -> Ohmic | None:
        """Every reservoir gate has an associated ohmic.

        This pulls the associated ohmic from the config.
        """
        for group in self.get_all_groups():
            if not group.has_gate(gate=rgate):
                continue
            left_reservoir = group.order.left_reservoir
            right_reservoir = group.order.right_reservoir
            if left_reservoir.name == rgate.name:
                return left_reservoir.ohmic
            if right_reservoir.name == rgate.name:
                return right_reservoir.ohmic
        return None

    def get_current_channels(self) -> "Channels":
        """Gets all of the current channels from the config.

        Returns:
            list of all of the current channels
        """
        return self._channels

    def get_gname(self, channel: "Channel") -> "Gname | None":
        """Gets the associated Gname with a Channel if it exists.

        Args:
            channel : the channel of interest

        Returns:
        If the channel is calid, the Gname
        """
        if not self.has_channel(channel=channel):
            return None
        for gname, group in self.groups.items():
            if group.has_channel(channel=channel):
                return gname
        return None

    @overload
    def get_group_gates(  # noqa: D102, F811 , PGH003 # type: ignore
        self,
        gname: "Gname",
        gate_type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        gate_type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        gate_type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        gate_type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        gate_type: type["DotGate"],
    ) -> "DotGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        gate_type: type["Gate"],
    ) -> "Gates": ...

    def get_group_gates(  # noqa: F811
        self,
        gname: "Gname",
        gate_type: "UsefulGateType",
    ) -> "UsefulGates | None":
        """Gets all of the gates of a gatetype associated with the selected group from the config.

        Args:
            gname : the selected Gname to sample from
            gate_type : the type of gate of interest

        Returns:
        If the Gname is valid, the list of gates
        """
        if not self.has_gname(group=gname):
            return None
        group = self.select_group(gname=gname)
        if group is not None:
            return group.get_connections(connection_type=gate_type)
        return None

    @overload
    def get_channel_gates(  # noqa: D102, F811 , PGH003 # type: ignore
        self,
        channel: "Channel",
        gate_type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: "Channel",
        gate_type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: "Channel",
        gate_type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: "Channel",
        gate_type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: "Channel",
        gate_type: type["DotGate"],
    ) -> "DotGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: "Channel",
        gate_type: type["Gate"],
    ) -> "Gates": ...

    def get_channel_gates(  # noqa: F811
        self,
        channel: "Channel",
        gate_type: "UsefulGateType",
    ) -> "UsefulGates | None":
        """Gets all of the gates of gatetype associated with the selected current channel from the config.

        Args:
            channel : the name of the channel of interest
            gate_type : the type of connection of interest

        Returns:
            If the channel is valid the list of gates
        """
        gname = self.get_gname(channel=channel)
        if gname is None:
            return None
        return self.get_group_gates(
            gname=gname,
            gate_type=gate_type,
        )

    def get_all_channel_gates(self, channel: "Channel") -> "Gates | None":
        """Gets all of the gates associated with the selected current channel from the config.

        Args:
            channel : the name of the channel of interest

        Returns:
            If the channel is valid the list of gates
        """
        if not self.has_channel(channel=channel):
            return None
        for group in self.get_all_groups():
            gates = group.get_all_channel_gates(channel=channel)
            if gates is not None:
                return gates
        return None

    def get_channel_ohmics(self, channel: "Channel") -> "Ohmics | None":
        """Gets all of the ohmics associated with the selected current channel.

        Args:
            channel : the channel of interest

        Returns:
            If the channel is valid, the list of ohmics
        """
        if not self.has_channel(channel=channel):
            return None
        for group in self.get_all_groups():
            if group.has_channel(channel=channel):
                return group.get_all_ohmics()
        return None

    def get_channel_order(self, channel: "Channel") -> "list[Connection] | None":
        """Gets all of the gates in order at the selected channel from the config.

        TODO: DEPRECATE this function

        Args:
            channel : the channel of interest

        Returns:
            If the channel is valid, the list of gates and ohmics
        """
        if not self.has_channel(channel=channel):
            return None
        for group in self.get_all_groups():
            if group.has_channel(channel=channel):
                return group.order.lineararray
        return None

    def get_channel_order_no_ohmics(
        self,
        channel: "Channel",
    ) -> "list[DotGate | ReservoirGate] | None":
        """Gets all of the gates in the order at the selected channel from the config with no ohmics.

        Args:
            channel : the channel of interest

        Returns:
            If the channel is valid, the list of gates
        """
        order = self.get_channel_order(channel=channel)
        if order is None:
            return None
        typed_order: list[DotGate | ReservoirGate] = []
        for gate in order:
            if type(gate) is Gate or isinstance(gate, (Ohmic | ScreeningGate)):
                continue
            assert isinstance(gate, (DotGate | ReservoirGate))
            typed_order.append(gate)
        return typed_order

    def get_num_unique_channels(self) -> int:
        """Returns the number of unique channels associated with the current sample.

        Returns:
            number of channels
        """
        return self.num_unique_channels

    def return_channels_from_gate(self, gate: "Gate") -> "Channels | None":
        """Returns a list of channels a given gate belongs to.

        Args:
            gate : the gatename to search for

        Returns:
            If gate is valid, list of current channels that this gate belongs to
        """
        if not self.has_gate(gate=gate):
            return None

        channels: set[Channel] = set()
        for group in self.get_all_groups():
            if group.has_gate(gate=gate):
                channels.union([group.name])
        return list(channels)

    def return_channel_from_gate(self, gate: "Gate") -> "Channel | None":
        """Returns the channel a given gate belongs to.

        If the gate is in multiple channels, it will return the first channel it finds.

        Args:
            gate : the gatename to search for

        Returns:
            If gate is valid, the current channel that this gate belongs to
        """
        channels = self.return_channels_from_gate(gate=gate)
        if channels is None:
            return None
        return channels[0]

    def ohmic_in_channel(self, ohmic: Ohmic, channel: "Channel") -> bool | None:
        """Checks if the ohmic is inside of the channel.

        Args:
            ohmic : the ohmic that we are interested in diagnosing
            channel : the channel we are interested in querrying

        Returns:
            If the channel is valid, a boolean value indicating if ohmic is in the channel
        """
        if (not self.has_channel(channel=channel)) or (not self.has_ohmic(ohmic=ohmic)):
            return None
        for group in self.get_all_groups():
            if group.has_channel(channel=channel):
                return group.has_ohmic(ohmic=ohmic)
        return None

    def get_dot_channel_neighbors(
        self,
        dotgate: "DotGate",
    ) -> tuple["NeighborGate", "NeighborGate"] | None:
        """Gets the nearby neighbors of the selected gate in the dot channel.

        Args:
            dotgate : the gate of interest (must be in dot channel)

        Returns:
            tuple of the two neighboring gates (left, right)
        """
        channel = self.return_channel_from_gate(gate=dotgate)
        if channel is None:
            return None
        gname = self.get_gname(channel=channel)
        if gname is None:
            return None
        group = self.select_group(gname=gname)
        if group is None:
            return None

        for connection in group.order.all_dot_gates():
            if dotgate.name == connection.name:
                left_neighbor = connection.left_neighbor
                right_neighbor = connection.right_neighbor
                assert isinstance(left_neighbor, NeighborGate)
                assert isinstance(right_neighbor, NeighborGate)
                return (left_neighbor, right_neighbor)
        return None

    @overload
    def get_gate_dict(  # noqa: D102 , PGH003# type: ignore
        self,
        gate_type: type["BarrierGate"],
    ) -> dict["Channel", "BarrierGates"]: ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["PlungerGate"],
    ) -> dict["Channel", "PlungerGates"]: ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["ReservoirGate"],
    ) -> dict["Channel", "ReservoirGates"]: ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["ScreeningGate"],
    ) -> dict["Channel", "ScreeningGates"]: ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["DotGate"],
    ) -> dict["Channel", "DotGates"]: ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["Gate"],
    ) -> dict["Channel", "Gates"]: ...

    def get_gate_dict(  # noqa: F811
        self,
        gate_type: "UsefulGateType",
    ) -> "Mapping[Channel, UsefulGates]":
        """Returns gates of a certain gatetype indexed by channel.

        Args:
            gate_type : the type of gate we want

        Returns:
            dictionary containing the type of gate we want
        """
        out: Mapping[Channel, UsefulGates] = {}
        for group in self.get_all_groups():
            gates = group.get_connections(connection_type=gate_type)
            out = {**out, group.name: gates}
        return out

    @overload
    def get_isolated_gates(  # noqa: D102, F811 , PGH003# type: ignore
        self,
        gate_type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def get_isolated_gates(  # noqa: D102, F811
        self,
        gate_type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def get_isolated_gates(  # noqa: D102, F811
        self,
        gate_type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def get_isolated_gates(  # noqa: D102, F811
        self,
        gate_type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    @overload
    def get_isolated_gates(  # noqa: F811, D102
        self,
        gate_type: type["DotGate"],
    ) -> "DotGates": ...

    @overload
    def get_isolated_gates(  # noqa: F811, D102
        self,
        gate_type: type["Gate"],
    ) -> "Gates": ...

    def get_isolated_gates(  # noqa: F811
        self,
        gate_type: "UsefulGateType",
    ) -> "UsefulGates | None":
        """Task to find isolated gates stored in the config.

        Args:
            gate_type : string corresponding to the gatetype pulled from the config

        Returns:
            list : set of all gates that are unshared of the gatetype
        """
        gates: list[Gate] = []
        for group in self.get_all_groups():
            connection = group.get_connection(connection_type=gate_type)
            gates.append(connection)
        gate_count = collections.Counter(gates)
        # Removing gates that are counted once
        return Gates([gate for gate, count in gate_count.items() if count == 1])

    @overload
    def get_shared_gates(  # noqa: D102, F811 , PGH003 # type: ignore
        self,
        gate_type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        gate_type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        gate_type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        gate_type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        gate_type: type["DotGate"],
    ) -> "DotGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        gate_type: type["Gate"],
    ) -> "Gates": ...

    def get_shared_gates(  # noqa: F811
        self,
        gate_type: "UsefulGateType",
    ) -> "UsefulGates | None":
        """Task to find shared gates stored in the config.
        nvim newline at arbitrary line number
                Args:
                    gate_type : string corresponding to the gatetype pulled from the config.

        Returns:
                    dict : organized from most shared to least shared gate of the gatetype
        """
        gates = []
        for group in self.get_all_groups():
            connection = group.get_connection(connection_type=gate_type)
            gates.append(connection)
        gate_count = collections.Counter(gates)
        # Removing gates that are counted once
        isolated_channel = self.get_isolated_gates(gate_type=gate_type)
        if isolated_channel is None:
            return None
        # The dictionary of more than counted once gates
        shared_gates = {
            k: v
            for k, v in gate_count.items()
            if k in (set(gate_count.keys()) - set(isolated_channel))
        }
        # sorting the dictionary from high to low
        return Gates(
            [
                k
                for k, v in sorted(
                    shared_gates.items(), key=lambda item: item[1], reverse=True
                )
            ]
        )

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811 , PGH003 # type: ignore
        self,
        gate_type: type["BarrierGate"],
        channel: "Channel",
    ) -> "BarrierGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["PlungerGate"],
        channel: "Channel",
    ) -> "PlungerGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["ReservoirGate"],
        channel: "Channel",
    ) -> "ReservoirGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["ScreeningGate"],
        channel: "Channel",
    ) -> "ScreeningGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["DotGate"],
        channel: "Channel",
    ) -> "DotGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["Gate"],
        channel: "Channel",
    ) -> "Gates": ...

    def get_shared_channel_gates(  # noqa: F811
        self,
        gate_type,
        channel: "Channel",
    ) -> "UsefulGates | None":
        """Finds the shared gates of the gatetype in the selected channel.

        Args:
            gate_type: the particular gatetype of interest
            channel: the channel of the device of interest

        Returns:
            the list of all gates of the gateytpe that are shared in the selected channel
        """
        shared_gates = self.get_shared_gates(gate_type=gate_type)
        channel_gates = self.get_channel_gates(channel=channel, gate_type=gate_type)
        if channel_gates is None:
            return None
        return Gates(list(set([*shared_gates]).intersection(set([*channel_gates]))))

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811 , PGH003 # type: ignore
        self,
        gate_type: type["BarrierGate"],
        channel: "Channel",
    ) -> "BarrierGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["PlungerGate"],
        channel: "Channel",
    ) -> "PlungerGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["ReservoirGate"],
        channel: "Channel",
    ) -> "ReservoirGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["ScreeningGate"],
        channel: "Channel",
    ) -> "ScreeningGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["DotGate"],
        channel: "Channel",
    ) -> "DotGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811
        self,
        gate_type: type["Gate"],
        channel: "Channel",
    ) -> "Gates": ...

    def get_isolated_channel_gates(  # noqa: F811
        self,
        gate_type: "UsefulGateType",
        channel: "Channel",
    ) -> "UsefulGates | None":
        """Finds the isolated gates of the gatetype in the selected channel.

        Args:
            gate_type: the particular gatetype of interest
            channel: the channel of the device of interest

        Returns:
            the list of all gates of the gatetype that are isolated in the selected channel
        """
        isolated_gates = self.get_isolated_gates(gate_type=gate_type)
        channel_gates = self.get_channel_gates(channel=channel, gate_type=gate_type)
        if channel_gates is None:
            return None
        return Gates(list(set([*isolated_gates]).intersection(set([*channel_gates]))))

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811 , PGH003 # type: ignore
        self,
        gate_type: type["BarrierGate"],
    ) -> dict["Channel", "BarrierGates"]: ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["PlungerGate"],
    ) -> dict["Channel", "PlungerGates"]: ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["ReservoirGate"],
    ) -> dict["Channel", "ReservoirGates"]: ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["ScreeningGate"],
    ) -> dict["Channel", "ScreeningGates"]: ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["DotGate"],
    ) -> dict["Channel", "DotGates"]: ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        gate_type: type["Gate"],
    ) -> dict["Channel", "Gates"]: ...

    def get_unshared_gate_dict(  # noqa: F811
        self,
        gate_type: "UsefulGateType",
    ) -> "Mapping[Channel, UsefulGates]":
        """Returns gates of a certain gatetype indexed by channel which are unshared.

        Args:
            gate_type : the type of gate we want

        Returns:
            dictionary containing the type of gate we want indexed by channel
        """
        out: Mapping[Channel, UsefulGates] = {}
        gates = self.get_gate_dict(gate_type=gate_type)
        unshared = self.get_isolated_gates(gate_type=gate_type)
        for channel in self.get_current_channels():
            if all([gate in unshared for gate in gates[channel]]):
                out = {**out, channel: gates[channel]}
        return out

    def generate_gate_relations(self) -> GateRelations:
        """Generates the gate relations in the config."""
        out = {}
        for gate in self.get_all_gates():
            out[gate] = []
            for group in self.get_all_groups():
                if not group.has_gate(gate=gate):
                    continue
                gates = group.order.query_neighbors(gate=gate)
                out[gate] = [*out[gate], *gates]
        return GateRelations(out)
