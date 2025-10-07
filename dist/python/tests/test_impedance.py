from falcon_core.physics.device_structures.connection import Connection
from falcon_core.physics.device_structures.impedance import Impedance


def test_impedance_construction():
    imp = Impedance(Connection.BarrierGate("B1"), 1000.0, 1e-12)
    assert imp.connection().name() == "B1"
    assert imp.resistance() == 1000.0
    assert imp.capacitance() == 1e-12
