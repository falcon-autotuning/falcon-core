"""Generic config manipulation functions. These work on the raw config files."""

from typing import TYPE_CHECKING

from .core import (
    Config,
    Group,
)
from .core.standard_config_connections import StandardConfigConnections
from .dependancies import (
    BarrierGate,
    BaseConnections,
    Channel,
    Gate,
    Gates,
    Gname,
    Impedance,
    Impedances,
    Ohmic,
    Ohmics,
    PlungerGate,
    ReservoirGate,
    ScreeningGate,
    overload,
)

if TYPE_CHECKING:
    from .dependancies import (
        BarrierGates,
        PlungerGates,
        ReservoirGates,
        ScreeningGates,
    )
    from .typing import (
        Any,
        Connection,
        UsefulGates,
        UsefulGateType,
    )

CONFIG_TO_GATE_PRIMITIVES: dict[str, "UsefulGateType"] = {
    "ScreeningGates": ScreeningGate,
    "ReservoirGates": ReservoirGate,
    "PlungerGates": PlungerGate,
    "BarrierGates": BarrierGate,
}


class ConfigManipulations:
    """Class for config manipulation functions."""

    def unpack_device_config(
        self,
        config: dict[str, "Any"],
    ) -> Config:
        """Unpacks a config object into a Config object.

        Args:
            config (dict[str, any]): The config object to unpack.

        Returns:
            Config: The unpacked config object.
        """
        groups = {}
        for key, value in config["groups"].items():
            connections = self._extract_standard_config_connections(config=value)
            order = self._extract_order(dictionary=value, connections=connections)
            new_group = Group(
                name=Channel(name=key),
                num_dots=int(value["NumDots"]),
                order=order,
                screening_gates=connections.screening_gates,
                reservoir_gates=connections.reservoir_gates,
                plunger_gates=connections.plunger_gates,
                barrier_gates=connections.barrier_gates,
            )
            groups[Gname(value=key)] = new_group
        connections = self._extract_standard_config_connections(config=config)
        ohmics = self._extract_ohmic(
            dictionary=config,
        )
        wiring_DC = self._extract_dcwiring(
            dictionary=config,
            ohmics=ohmics,
        )
        return Config(
            ohmics=ohmics,
            wiring_DC=wiring_DC,
            groups=groups,
            screening_gates=connections.screening_gates,
            reservoir_gates=connections.reservoir_gates,
            plunger_gates=connections.plunger_gates,
            barrier_gates=connections.barrier_gates,
        )

    def _extract_dcwiring(
        self,
        dictionary: dict[str, dict[str, dict[str, float] | None]],
        ohmics: Ohmics,
    ) -> Impedances:
        """Extracts a dcwiring from a dictionary.

        Args:
            dictionary : the dictionary that is being extracted from
            ohmics : the list of ohmics
        Returns:
            a list of Impedance objects instatiated
        Raises:
            TypeError if the dcwiring loaded from the config are not of type string
        """
        outs: list[Impedance] = []
        impedances = dictionary["wiringDC"]
        for key in list(impedances.keys()):
            values = impedances[key]
            if values is None:
                continue
            if key in [ohmic.name for ohmic in ohmics]:
                outs.append(
                    Impedance(
                        connection=Ohmic(key),
                        resistance=values["resistance"],
                        capacitance=values["capacitance"],
                    )
                )
            else:
                outs.append(
                    Impedance(
                        connection=Gate(key),
                        resistance=values["resistance"],
                        capacitance=values["capacitance"],
                    )
                )
        return Impedances(outs)

    @overload
    def _extract_gates(
        self,
        dictionary: dict[str, str],
        gate_type: type["BarrierGate"],
    ) -> "BarrierGates": ...

    @overload
    def _extract_gates(
        self,
        dictionary: dict[str, str],
        gate_type: type["PlungerGate"],
    ) -> "PlungerGates": ...

    @overload
    def _extract_gates(
        self,
        dictionary: dict[str, str],
        gate_type: type["ReservoirGate"],
    ) -> "ReservoirGates": ...

    @overload
    def _extract_gates(
        self,
        dictionary: dict[str, str],
        gate_type: type["ScreeningGate"],
    ) -> "ScreeningGates": ...

    def _extract_gates(
        self,
        dictionary: dict[str, str],
        gate_type,
    ) -> "UsefulGates":
        """Extracts a gate from a dictionary where the gatetype is a key.

        Performs the tranformation from string index by ";" to list

        Args:
            dictionary : the dictionary that is being extracted from
            gate_type : the gatetype name / key to the dictionary

        Returns:
            a list of Gate objects instatiated

        Raises:
            TypeError if the gates loaded from the config are not of type string
        """
        for key, value in CONFIG_TO_GATE_PRIMITIVES.items():
            if value == gate_type:
                gatetype = key
                break
        else:
            msg = f"Invalid gate type {gate_type}"
            raise TypeError(msg)

        gates = dictionary[gatetype]
        if not isinstance(gates, str):
            msg = f"{gatetype} needs to be a str in config, delimitted by ;"
            raise TypeError(msg)
        return Gates([gate_type(gate) for gate in gates.split(";")])

    def _extract_standard_config_connections(
        self,
        config: dict[str, str],
    ) -> StandardConfigConnections:
        """Extracts the standard connections from a config dictionary.

        Args:
            config : the dictionary that is being extracted from

        Returns:
            a dictionary of the standard connections
        """
        screening_gates = self._extract_gates(
            dictionary=config,
            gate_type=ScreeningGate,
        )
        reservoir_gates = self._extract_gates(
            dictionary=config,
            gate_type=ReservoirGate,
        )
        plunger_gates = self._extract_gates(
            dictionary=config,
            gate_type=PlungerGate,
        )
        barrier_gates = self._extract_gates(
            dictionary=config,
            gate_type=BarrierGate,
        )
        return StandardConfigConnections(
            screening_gates=screening_gates,
            reservoir_gates=reservoir_gates,
            plunger_gates=plunger_gates,
            barrier_gates=barrier_gates,
            ohmics=Ohmics([]),
        )

    def _extract_ohmic(
        self,
        dictionary: dict[str, str],
    ) -> Ohmics:
        """Extracts a ohmic from a dictionary where the gatetype is a key.

        Performs the tranformation from string index by ";" to list

        Args:
            dictionary : the dictionary that is being extracted from
            gatetype : the gatetype name / key to the dictionary

        Returns:
            a list of Gate objects instatiated

        Raises:
            TypeError if the ohmic loaded from the config are not of type string
        """
        gatetype = "Ohmics"
        gates = dictionary[gatetype]
        if not isinstance(gates, str):
            msg = f"{gatetype} needs to be a str in config, delimitted by ;"
            raise TypeError(msg)
        return Ohmics([Ohmic(gate) for gate in gates.split(";")])

    def _extract_order(
        self,
        dictionary: dict[str, str],
        connections: StandardConfigConnections,
    ) -> "BaseConnections":
        """Extracts a gate from a dictionary.

        Performs the tranformation from string index by ";" to list

        Args:
            dictionary : the dictionary that is being extracted from
            connections : the various connections and their classes

        Returns:
            a list of Gate objects instatiated

        Raises:
            TypeError if the Order loaded from the config are not of type string
        """
        config = dictionary["Order"]
        if not isinstance(config, str):
            msg = "Order needs to be a str in config, delimitted by ;"
            raise TypeError(msg)
        raworder = config.split(";")
        order: list[Connection] = []
        for gate in raworder[1:-1]:
            if gate in [sgate.name for sgate in connections.screening_gates]:
                gatetype = ReservoirGate
            elif gate in [bgate.name for bgate in connections.barrier_gates]:
                gatetype = BarrierGate
            else:
                gatetype = PlungerGate
            order.append(gatetype(gate))
        order.insert(0, Ohmic(raworder[0]))
        order.append(Ohmic(raworder[-1]))
        return BaseConnections(order)
