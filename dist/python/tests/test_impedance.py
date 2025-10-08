from falcon_core.physics.device_structures.connection import Connection
from falcon_core.physics.device_structures.impedance import Impedance


def test_impedance_construction():
    imp = Impedance(Connection.BarrierGate("B1"), 1000.0, 1e-12)
    assert imp.connection().name() == "B1"
    assert imp.resistance() == 1000.0
    assert imp.capacitance() == 1e-12


def test_serialization():
    imp = Impedance.create(Connection.BarrierGate("B1"), 1000.0, 1e-12)
    string = imp.to_json_string()
    imp_clone = Impedance.from_json_string(string)
    assert imp == imp_clone


def test_equality():
    imp = Impedance.create(Connection.BarrierGate("B1"), 1000.0, 1e-12)
    imp_clone = imp
    assert imp == imp_clone
    imp2 = Impedance.create(Connection.PlungerGate("P1"), 1000.0, 1e-12)
    assert imp != imp2
