from falcon_core.physics.device_structures.connection import Connection


def test_barrier_construction():
    barrier = Connection.BarrierGate("B1")
    assert barrier.name() == "B1"
    assert barrier.is_barrier_gate()
    assert barrier.is_dot_gate()
    assert barrier.is_gate()
    assert not barrier.is_ohmic()


def test_plunger_construction():
    plunger = Connection.PlungerGate("P1")
    assert plunger.name() == "P1"
    assert plunger.is_plunger_gate()
    assert plunger.is_dot_gate()
    assert plunger.is_gate()
    assert not plunger.is_ohmic()


def test_reservoir_construction():
    reservoir = Connection.ReservoirGate("R1")
    assert reservoir.name() == "R1"
    assert reservoir.is_reservoir_gate()
    assert not reservoir.is_dot_gate()
    assert reservoir.is_gate()
    assert not reservoir.is_ohmic()


def test_screening_construction():
    screening = Connection.ScreeningGate("S1")
    assert screening.name() == "S1"
    assert screening.is_screening_gate()
    assert not screening.is_dot_gate()
    assert screening.is_gate()
    assert not screening.is_ohmic()


def test_ohmic_construction():
    screening = Connection.Ohmic("O1")
    assert screening.name() == "O1"
    assert screening.is_ohmic()
    assert not screening.is_dot_gate()
    assert not screening.is_gate()
