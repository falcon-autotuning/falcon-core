"""Tests that the config is serializeable."""

from falcon_core.physics.config.core import Config
from falcon_core.physics.config.core.group import Group
from falcon_core.physics.config.dependancies import (
    BarrierGate,
    BarrierGates,
    Channel,
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
from falcon_core.physics.device_structures.impedance import Impedances


def test_config_json_serialization():
    """Test that Config objects can be serialized to JSON and back."""
    # Create basic gate collections
    screening_gates = ScreeningGates([ScreeningGate("SG1"), ScreeningGate("SG2")])
    plunger_gates = PlungerGates([PlungerGate("P1"), PlungerGate("P2")])
    barrier_gates = BarrierGates(
        [BarrierGate("B1"), BarrierGate("B2"), BarrierGate("B3")]
    )
    reservoir_gates = ReservoirGates([ReservoirGate("R1"), ReservoirGate("R2")])
    ohmics = Ohmics([Ohmic("O1"), Ohmic("O2")])

    # Create order list for the group
    order = [
        Ohmic("O1"),
        ReservoirGate("R1"),
        BarrierGate("B1"),
        PlungerGate("P1"),
        BarrierGate("B2"),
        PlungerGate("P2"),
        BarrierGate("B3"),
        ReservoirGate("R2"),
        Ohmic("O2"),
    ]

    # Create a group
    group = Group(
        name=Channel(name="CH1"),
        num_dots=2,
        screening_gates=screening_gates,
        reservoir_gates=reservoir_gates,
        plunger_gates=plunger_gates,
        barrier_gates=barrier_gates,
        order=order,
    )

    # Create wiring impedances
    wiring_DC = Impedances(
        [
            Impedance(connection=Ohmic("O1"), resistance=1000.0, capacitance=1e-12),
            Impedance(connection=Ohmic("O2"), resistance=1000.0, capacitance=1e-12),
            Impedance(
                connection=BarrierGate("B1"), resistance=10000.0, capacitance=1e-12
            ),
            Impedance(
                connection=BarrierGate("B2"), resistance=10000.0, capacitance=1e-12
            ),
            Impedance(
                connection=BarrierGate("B3"), resistance=10000.0, capacitance=1e-12
            ),
            Impedance(
                connection=PlungerGate("P1"), resistance=10000.0, capacitance=1e-12
            ),
            Impedance(
                connection=PlungerGate("P2"), resistance=10000.0, capacitance=1e-12
            ),
            Impedance(
                connection=ReservoirGate("R1"), resistance=10000.0, capacitance=1e-12
            ),
            Impedance(
                connection=ReservoirGate("R2"), resistance=10000.0, capacitance=1e-12
            ),
            Impedance(
                connection=ScreeningGate("SG1"), resistance=10000.0, capacitance=1e-12
            ),
            Impedance(
                connection=ScreeningGate("SG2"), resistance=10000.0, capacitance=1e-12
            ),
        ]
    )

    # Create the Config object
    original_config = Config(
        screening_gates=screening_gates,
        plunger_gates=plunger_gates,
        ohmics=ohmics,
        barrier_gates=barrier_gates,
        reservoir_gates=reservoir_gates,
        groups={Gname(value="group1"): group},
        wiring_DC=wiring_DC,
    )

    # Serialize to JSON
    json_str = original_config.to_json()
    assert isinstance(json_str, str)
    assert len(json_str) > 0

    # Deserialize from JSON
    deserialized_config = Config.from_json(json_str)
    assert isinstance(deserialized_config, Config)

    # Verify basic properties are preserved
    assert (
        deserialized_config.num_unique_channels == original_config.num_unique_channels
    )
    assert len(deserialized_config.groups) == len(original_config.groups)

    # Compare channels
    assert sorted([c.name for c in deserialized_config.channels]) == sorted(
        [c.name for c in original_config.channels]
    )

    # Compare gates
    assert len(deserialized_config.get_all_gates()) == len(
        original_config.get_all_gates()
    )
    assert sorted([g.name for g in deserialized_config.get_all_gates()]) == sorted(
        [g.name for g in original_config.get_all_gates()]
    )

    # Compare ohmics
    assert len(deserialized_config.ohmics) == len(original_config.ohmics)
    assert sorted([o.name for o in deserialized_config.ohmics]) == sorted(
        [o.name for o in original_config.ohmics]
    )

    # Compare impedances
    assert len(deserialized_config.wiring_DC) == len(original_config.wiring_DC)
    for imp1, imp2 in zip(
        sorted(deserialized_config.wiring_DC, key=lambda x: x.connection.name),
        sorted(original_config.wiring_DC, key=lambda x: x.connection.name),
    ):
        assert imp1.connection.name == imp2.connection.name
        assert imp1.resistance == imp2.resistance
        assert imp1.capacitance == imp2.capacitance

    # Test that we can re-serialize the deserialized object
    json_str2 = deserialized_config.to_json()
    assert isinstance(json_str2, str)
    assert len(json_str2) > 0
