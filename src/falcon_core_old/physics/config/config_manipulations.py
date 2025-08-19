"""Generic config manipulation functions. These work on the raw config files."""

from typing import TYPE_CHECKING

from falcon_core.physics.config.core.voltage_constraints import VoltageConstraints

from ...dependancies import np
from .core import (
    Config,
    Group,
)
from .core.adjacency import Adjacency
from .core.standard_config_connections import StandardConfigConnections
from .dependancies import (
    BarrierGate,
    BaseConnections,
    Channel,
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
            connections=connections,
        )

        total_gates = [
            *connections.screening_gates,
            *connections.reservoir_gates,
            *connections.plunger_gates,
            *connections.barrier_gates,
        ]
        constraints = self._extract_voltage_constraints(
            map=config, total_gates=total_gates
        )
        return Config(
            ohmics=ohmics,
            wiring_DC=wiring_DC,
            groups=groups,
            screening_gates=connections.screening_gates,
            reservoir_gates=connections.reservoir_gates,
            plunger_gates=connections.plunger_gates,
            barrier_gates=connections.barrier_gates,
            constraints=constraints,
        )

    def _extract_adjacency(
        self,
        map: dict[str, dict[str, dict[str, str]]],
        total_gates: list,
    ) -> Adjacency:
        """Given the available gates loaded from the config, lets generate the adjacency matrix for this device."""
        num_gates = len(total_gates)
        total_gate_names = [gate.name for gate in total_gates]
        adjacency = np.array(np.zeros((num_gates, num_gates)), dtype=np.bool)
        name = "adjacency"
        if name not in map:
            msg = f"Expected to find {name} in {map} but the config did not contain the entry"
            raise IndexError(msg)
        adjacency_map = map[name]
        for i, gate in enumerate(total_gate_names):
            if gate not in adjacency_map:
                continue
            adjacent_matches = adjacency_map[gate]
            if not isinstance(adjacent_matches, str):
                msg = f"Expected the type of the adjacent matches in the config to be strings, but got{type(adjacent_matches)} instead."
                raise TypeError(msg)
            gate_names = adjacent_matches.split(";")
            for j, gate in enumerate(total_gate_names):
                if gate not in gate_names:
                    continue
                adjacency[i, j] = True
                adjacency[j, i] = True

        return Adjacency(
            matrix=adjacency,
            indexes=total_gates,
        )

    def _extract_voltage_constraints(
        self,
        map: dict[str, "Any"],
        total_gates: list,
    ) -> VoltageConstraints:
        """Given the available gates and the config lets produce a voltage constraints object."""
        adjacency = self._extract_adjacency(map=map, total_gates=total_gates)
        name = "max_safe_diff"
        if name not in map:
            msg = f"Expected to find index {name} in the config but only found available indexes {map.keys()}"
            raise IndexError(msg)
        max_safe_diff = map[name]
        if not isinstance(max_safe_diff, float):
            msg = f"Expected the type of the max safe diff to be a float, but got {type(max_safe_diff)} instead."
            raise TypeError(msg)
        name = "safe_voltage_bounds"
        if name not in map:
            msg = f"Expected to find index {name} in the config but only found available indexes {map.keys()}"
            raise IndexError(msg)
        bounds = map[name]
        if not isinstance(bounds, list):
            msg = f"Expected the type of the bounds to be a list, but got {type(bounds)} instead."
            raise TypeError(msg)
        for bound in bounds:
            if not isinstance(bound, float):
                msg = f"Expected the type of a bound inside the bounds to be float, but got {type(bounds)} instead."
                raise TypeError(msg)
        if len(bounds) != 2:
            msg = f"Expected two bounds stored for the max and min, but got {len(bounds)} bounds instead."
            raise ValueError(msg)
        return VoltageConstraints(
            adjacency=adjacency,
            max_safe_diff=max_safe_diff,
            bounds=tuple(bounds),
        )

    def _extract_dcwiring(
        self,
        dictionary: dict[str, dict[str, dict[str, float] | None]],
        ohmics: Ohmics,
        connections: StandardConfigConnections,
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
                if key in [pgate.name for pgate in connections.plunger_gates]:
                    gt = PlungerGate
                elif key in [pgate.name for pgate in connections.barrier_gates]:
                    gt = BarrierGate
                elif key in [pgate.name for pgate in connections.screening_gates]:
                    gt = ScreeningGate
                elif key in [pgate.name for pgate in connections.reservoir_gates]:
                    gt = ReservoirGate
                else:
                    msg = "Cannot use that gate"
                    raise TypeError(msg)
                outs.append(
                    Impedance(
                        connection=gt(key),
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
                gatetype = ScreeningGate
            elif gate in [bgate.name for bgate in connections.barrier_gates]:
                gatetype = BarrierGate
            elif gate in [pgate.name for pgate in connections.plunger_gates]:
                gatetype = PlungerGate
            else:  # will be ReservoirGate
                gatetype = ReservoirGate
            order.append(gatetype(gate))
        order.insert(0, Ohmic(raworder[0]))
        order.append(Ohmic(raworder[-1]))
        return BaseConnections(order)
