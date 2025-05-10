"""Utilities formed from the combination of Operation and Config classes."""

from typing import TYPE_CHECKING

from .dependancies import (
    Channel,
    DotGate,
    DotGates,
    Gate,
    NeighborGate,
    overload,
)

if TYPE_CHECKING:
    from .core import Config, Group
    from .dependancies import (
        BarrierGate,
        BarrierGates,
        Channels,
        Gates,
        Gname,
        Impedance,
        Ohmic,
        Ohmics,
        PlungerGate,
        PlungerGates,
        ReservoirGate,
        ReservoirGates,
        ScreeningGate,
        ScreeningGates,
    )
    from .geometries import NeighborGate
    from .typing import (
        Connection,
        Mapping,
        UsefulGates,
        UsefulGateType,
    )


class Utilities:
    """Various tools used to deconstruct information from the config into useable pieces."""

    _config: "Config"

    def __init__(
        self,
        config: "Config",
    ):
        """Constructor for the configUser.

        Args:
            config : the config loaded from the datafile
            operations : the operations if available, else it is none
        """
        self._config = config

    @property
    def config(self) -> "Config":
        """Returns the config of the device."""
        return self._config

    def get_associated_ohmic(
        self,
        rgate: "ReservoirGate",
    ) -> "Ohmic":
        """Every reservoir gate has an associated ohmic.

        This pulls the associated ohmic from the config.
        """
        ohmic = self.get_config().get_associated_ohmic(rgate=rgate)
        if ohmic is None:
            raise TypeError
        return ohmic

    def get_impedance(
        self,
        connection: "Connection",
    ) -> "Impedance":
        """Searches through the config and finds the connection in the dcwiring."""
        out = self.get_config().get_impedance(connection=connection)
        assert out is not None, "Connection not found in dcwiring"
        return out

    def get_gname(
        self,
        channel: Channel,
    ) -> "Gname":
        """Gets the associated gname with a Channel if it exists.

        Args:
            channel : the channel of interest

        Returns:
            If the channel is calid, the gname

        Raises:
            TypeError if an invalid Channel is used
        """
        value = self.get_config().get_gname(channel=channel)
        if value is not None:
            return value
        msg = f"Invalid Channel used of {Channel}. Try again."
        raise TypeError(msg)

    @overload
    def get_isolated_gates(  # noqa: D102 , PGH003 # type: ignore
        self,
        type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def get_isolated_gates(  # noqa: F811, D102
        self,
        type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def get_isolated_gates(  # noqa: F811, D102
        self,
        type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def get_isolated_gates(  # noqa: F811, D102
        self,
        type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    @overload
    def get_isolated_gates(  # noqa: F811, D102
        self,
        type: type["DotGate"],
    ) -> "DotGates": ...

    @overload
    def get_isolated_gates(  # noqa: F811, D102
        self,
        type: type["Gate"],
    ) -> "Gates": ...

    def get_isolated_gates(  # noqa: F811
        self,
        type,
    ):
        """Gets all of the isolated gates of a gatetype from the config.

        Args:
            type : the type of gate of interest

        Returns:
            all of the gates that are isolated of the gatetype
        """
        return self.get_config().get_isolated_gates(gate_type=type)

    @overload
    def get_isolated_channel_gates(  # noqa: D102 , PGH003 # type: ignore
        self,
        type: type["BarrierGate"],
        channel: Channel,
    ) -> "BarrierGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: F811, D102
        self,
        type: type["ReservoirGate"],
        channel: Channel,
    ) -> "ReservoirGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811
        self,
        type: type["PlungerGate"],
        channel: Channel,
    ) -> "PlungerGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811
        self,
        type: type["ScreeningGate"],
        channel: Channel,
    ) -> "ScreeningGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811
        self,
        type: type["DotGate"],
        channel: Channel,
    ) -> "DotGates": ...

    @overload
    def get_isolated_channel_gates(  # noqa: D102, F811
        self,
        type: type["Gate"],
        channel: Channel,
    ) -> "Gates": ...
    def get_isolated_channel_gates(  # noqa: F811
        self,
        type: "UsefulGateType",
        channel: Channel,
    ) -> "UsefulGates":
        """Finds the isolated gates of the gatetype in the selected channel.

        Args:
            type: the particular gate type of interest
            channel: the channel of the device of interest

        Returns:
            the list of all gates of the gatetype that are isolated in the selected channel

        Raises:
            ValueError if the Channel is invalid and does not contain the gatetype
        """
        value = self.get_config().get_isolated_channel_gates(
            gate_type=type,
            channel=channel,
        )
        if value is None:
            msg = f"Invalid Channel, {channel} does not contain {type.__name__}"
            raise ValueError(msg)
        return value

    @overload
    def get_shared_channel_gates(  # noqa: D102 , PGH003 # type: ignore
        self,
        type: type["BarrierGate"],
        channel: Channel,
    ) -> "BarrierGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        type: type["ReservoirGate"],
        channel: Channel,
    ) -> "ReservoirGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        type: type["PlungerGate"],
        channel: Channel,
    ) -> "PlungerGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        type: type["ScreeningGate"],
        channel: Channel,
    ) -> "ScreeningGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        type: type["DotGate"],
        channel: Channel,
    ) -> "DotGates": ...

    @overload
    def get_shared_channel_gates(  # noqa: D102, F811
        self,
        type: type["Gate"],
        channel: Channel,
    ) -> "Gates": ...

    def get_shared_channel_gates(  # noqa: F811
        self,
        type: "UsefulGateType",
        channel: Channel,
    ) -> "UsefulGates":
        """Finds the shared gates of the gatetype in the selected channel.

        Args:
            type: the particular gatetype of interest
            channel: the channel of the device of interest

        Returns:
            the list of all gates of the gatetype that are shared in the selected channel

        Raises:
            ValueError if the Channel is invalid and does not contain the gatetype
        """
        value = self.get_config().get_shared_channel_gates(
            gate_type=type,
            channel=channel,
        )
        if value is None:
            msg = f"Invalid Channel, {channel} does not contain {type.__name__}"
            raise ValueError(msg)
        return value

    @overload
    def get_shared_gates(  # noqa: D102 , PGH003 # type: ignore
        self,
        type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        type: type["DotGate"],
    ) -> "DotGates": ...

    @overload
    def get_shared_gates(  # noqa: D102, F811
        self,
        type: type["Gate"],
    ) -> "Gates": ...

    def get_shared_gates(  # noqa: F811
        self,
        type: "UsefulGateType",
    ) -> "UsefulGates":
        """Gets all of the shared gates of a gatetype from the config.

        Args:
            type : the type of gate of interest

        Returns:
            all of the gates that are shared of the gatetype
        """
        return self.get_config().get_shared_gates(gate_type=type)

    def select_group(
        self,
        gname: "Gname",
    ) -> "Group":
        """Finds a group from the name and returns it.

        Args:
            gname : the gname to search for

        Returns:
        the associated group if it exists.
        """
        value = self.get_config().select_group(gname=gname)
        if value is not None:
            return value
        msg = "Invalid gname. Try again."
        raise TypeError(msg)

    @overload
    def get_group_gates(  # noqa: D102 , PGH003 # type: ignore
        self,
        gname: "Gname",
        type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        type: type["DotGate"],
    ) -> "DotGates": ...

    @overload
    def get_group_gates(  # noqa: D102, F811
        self,
        gname: "Gname",
        type: type["Gate"],
    ) -> "Gates": ...

    def get_group_gates(  # noqa: F811
        self,
        gname: "Gname",
        type: "UsefulGateType",
    ) -> "UsefulGates":
        """Gets all of the gates of a gatetype associated with the selected group from the config.

        Args:
            gname : the selected gname to sample from
            type : the selected gate type to collect from config

        Returns:
            the list of gates

        Raises:
            TypeError if invalid gname is used
        """
        value = self.get_config().get_group_gates(
            gname=gname,
            gate_type=type,
        )
        if value is not None:
            return value
        msg = "Invalid gname, try again."
        raise TypeError(msg)

    def get_dot_number(
        self,
        channel: Channel,
    ) -> int:
        """Task to find the number of dots associated with a current channel from the config.

        Args:
            channel : the current channel we are searching for

        Returns:
            The value found in the config

        Raises:
            ValueError if the channel is invalid
        """
        value = self.get_config().get_dot_number(channel=channel)
        if value is None:
            msg = "Invalid Channel, choose another"
            raise ValueError(msg)
        return value

    def ohmic_in_charge_sensor(
        self,
        ohmic: "Ohmic",
    ) -> bool:
        """Checks if ohmic is on charge sensor channel.

        Args:
            ohmic : the ohmic that we are interested in diagnosing

        Returns:
            if the ohmic is attached to charge sensor

        Raises:
            ValueError if the ohmic is invalid
        """
        value = self.get_config().ohmic_in_charge_sensor(ohmic=ohmic)
        if value is None:
            msg = "Invalid ohmic, choose another"
            raise ValueError(msg)
        return value

    def get_config(self) -> "Config":
        """Gets the config and returns it to the user."""
        return self.config

    def get_current_channels(self) -> list[Channel]:
        """Gets all of the current channels from the config.

        Returns:
            list of all of the current channels
        """
        return self.get_config().get_current_channels()

    def get_channel_gate_relations(self) -> dict[Channel, "Gates"]:
        """Gets all of the connections associated with each current channel from the config."""
        outs: dict[Channel, Gates] = {}
        for channel in self.get_current_channels():
            outs[channel] = self.get_channel_gates(
                channel=channel,
                type=Gate,
            )
        return outs

    @overload
    def get_channel_gates(  # noqa: D102 , PGH003 # type: ignore
        self,
        channel: Channel,
        type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: Channel,
        type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: Channel,
        type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: Channel,
        type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: Channel,
        type: type["DotGate"],
    ) -> "DotGates": ...

    @overload
    def get_channel_gates(  # noqa: D102, F811
        self,
        channel: Channel,
        type: type["Gate"],
    ) -> "Gates": ...

    def get_channel_gates(  # noqa: F811
        self,
        channel: Channel,
        type: "UsefulGateType",
    ) -> "UsefulGates":
        """Gets all of the gates of gatetype associated with the selected current channel from the config.

        Args:
            channel : the name of the channel of interest
            type : the type of gate of interest

        Returns:
            all of the gates for the channel

        Raises:
            ValueError if the Channel is invalid
        """
        value = self.get_config().get_channel_gates(channel=channel, gate_type=type)
        if value is None:
            msg = "Invalid Channel, try again"
            raise ValueError(msg)
        return value

    def get_all_channel_gates(
        self,
        channel: Channel,
    ) -> "Gates":
        """Gets all of the gates of gatetype associated with the selected current channel from the config.

        Args:
            channel : the name of the channel of interest

        Returns:
            all of the gates associated with the channel

        Raises:
            ValueError if the channel is invalid
        """
        value = self.get_config().get_all_channel_gates(channel=channel)
        if value is None:
            msg = "Invalid Channel, try again"
            raise ValueError(msg)
        return value

    def get_channel_ohmics(
        self,
        channel: Channel,
    ) -> "Ohmics":
        """Gets all of the ohmics associated with the selected current channel.

        Args:
            channel : the channel of interest

        Returns:
            the list of ohmics associated with the current channel

        Raises:
            ValueError if the channel is invalid
        """
        value = self.get_config().get_channel_ohmics(channel=channel)
        if value is None:
            msg = "Invalid Channel, try again"
            raise ValueError(msg)
        return value

    def get_channel_order(
        self,
        channel: Channel,
    ) -> "list[Connection]":
        """Gets all of the gates in order at the selected channel from the config.

        Args:
            channel : the channel of interest

        Returns:
            the list of gates and ohmics associated with the current channel in order

        Raises:
        ValueError if the channel is invalid
        """
        value = self.get_config().get_channel_order(channel=channel)
        if value is None:
            msg = "Invalid Channel, try again"
            raise ValueError(msg)
        return value

    def get_channel_order_no_ohmics(
        self,
        channel: Channel,
    ) -> list["NeighborGate"]:
        """Gets all of the gates in order at the selected channel from the config.

        Args:
            channel : the channel of interest

        Returns:
            the list of gates associated with the current channel in order

        Raises:
        ValueError if the channel is invalid
        """
        value = self.get_config().get_channel_order_no_ohmics(channel=channel)
        if value is None:
            msg = "Invalid Channel, try again"
            raise ValueError(msg)
        return value

    def get_channel_order_no_ohmics_no_res(
        self,
        channel: Channel,
    ) -> "DotGates":
        """Gets all of the gates in order at the selected channel from the config.

        Args:
            channel : the channel of interest

        Returns:
            the list of gates associated with the current channel in order

        Raises:
        ValueError if the channel is invalid
        """
        order = self.get_channel_order_no_ohmics(channel=channel)
        return DotGates([value for value in order if isinstance(value, DotGate)])

    def get_num_unique_channels(self) -> int:
        """Returns the number of unique channels associated with the current sample."""
        return self.get_config().get_num_unique_channels()

    def return_channels_from_gate(
        self,
        gate: "Gate",
    ) -> "Channels":
        """Returns a list of channels a given gate belongs to.

        Args:
            gate : the gatename to search for

        Returns:
            list of current channels that this gate belongs to

        Raises:
            ValueError if invalid gate
        """
        value = self.get_config().return_channels_from_gate(gate=gate)
        if value is None:
            msg = "Invalid Gate, try again"
            raise ValueError(msg)
        return value

    def return_channel_from_gate(
        self,
        gate: "Gate",
    ) -> Channel:
        """Returns a channel a given gate belongs to.

        To see all channels, use return_channels_from_gate instead.

        Args:
            gate : the gatename to search for

        Returns:
            list of current channels that this gate belongs to

        Raises:
            ValueError if invalid gate
        """
        return self.return_channel_from_gate(gate=gate)

    def ohmic_in_channel(
        self,
        ohmic: "Ohmic",
        channel: Channel,
    ) -> bool | None:
        """Checks if the ohmic is in the channel.

        Args:
            ohmic : the ohmic that we are interested in diagnosing
            channel : the channel we are interested in querrying

        Returns:
            boolean value indicating if ohmic is in the channel

        Raises:
            ValueError if the ohmic or channel are invalid
        """
        value = self.get_config().ohmic_in_channel(ohmic=ohmic, channel=channel)
        if value is None:
            msg = "Invalid ohmic or channel, try again"
            raise ValueError(msg)
        return value

    @overload
    def get_gate_dict(  # noqa: D102 , PGH003 # type: ignore
        self,
        type: type["BarrierGate"],
    ) -> dict[Channel, "BarrierGates"]: ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        type: type["ReservoirGate"],
    ) -> dict[Channel, "ReservoirGates"]: ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        type: type["PlungerGate"],
    ) -> dict[Channel, "PlungerGates"]: ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        type: type["ScreeningGate"],
    ) -> dict[Channel, "ScreeningGates"]: ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        type: type["DotGate"],
    ) -> "dict[Channel, DotGates]": ...

    @overload
    def get_gate_dict(  # noqa: D102, F811
        self,
        type: type["Gate"],
    ) -> "dict[Channel, Gates]": ...

    def get_gate_dict(  # noqa: F811
        self,
        type: "UsefulGateType",
    ) -> "Mapping[Channel, UsefulGates]":
        """Returns gates of a certain gatetype indexed by channel.

        Args:
            type : the type of gate we want

        Returns:
            dictionary containing the type of gate we want

        """
        return self.get_config().get_gate_dict(gate_type=type)

    @overload
    def get_unshared_gate_dict(  # noqa: D102 , PGH003 # type: ignore
        self,
        type: type["BarrierGate"],
    ) -> dict[Channel, "BarrierGates"]: ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        type: type["ReservoirGate"],
    ) -> dict[Channel, "ReservoirGates"]: ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        type: type["PlungerGate"],
    ) -> dict[Channel, "PlungerGates"]: ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        type: type["ScreeningGate"],
    ) -> dict[Channel, "ScreeningGates"]: ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        type: type["DotGate"],
    ) -> "dict[Channel, DotGates]": ...

    @overload
    def get_unshared_gate_dict(  # noqa: D102, F811
        self,
        type: type["Gate"],
    ) -> "dict[Channel, Gates]": ...
    def get_unshared_gate_dict(  # noqa: F811
        self,
        type: "UsefulGateType",
    ) -> "Mapping[Channel, UsefulGates]":
        """Gets all gates that are unshared of a particular type.

        Args:
            type : the type of gate we want

        Returns:
            dictionary containing the type of gate we want indexed by channel
        """
        return self.get_config().get_unshared_gate_dict(gate_type=type)

    def get_dot_channel_neighbors(
        self,
        dotgate: "DotGate",
    ) -> tuple["NeighborGate", "NeighborGate"]:
        """Gets the nearby neighbors of the selected gate in the dot channel.

        Args:
            dotgate : the gate of interest (must be in dot channel)

        Returns:
            tuple of the two neighboring gates (left, right)
        """
        value = self.get_config().get_dot_channel_neighbors(dotgate=dotgate)
        if value is None:
            msg = "Invalid gate, try again"
            raise ValueError(msg)
        return value

    def get_left_dot_channel_neighbor(
        self,
        dotgate: "DotGate",
    ) -> "NeighborGate":
        """Gets the left neighbor of the selected gate in the dot channel."""
        return self.get_dot_channel_neighbors(dotgate=dotgate)[0]

    def get_right_dot_channel_neighbor(
        self,
        dotgate: "DotGate",
    ) -> "NeighborGate":
        """Gets the right neighbor of the selected gate in the dot channel."""
        return self.get_dot_channel_neighbors(dotgate=dotgate)[1]
