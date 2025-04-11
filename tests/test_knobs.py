"""Tests for the Knob class and pals."""

import pytest

from falcon_core.device_interfaces import ScreeningGate
from falcon_core.instrument_interfaces.names import Knob, Knobs
from falcon_core.instrument_interfaces.physics_units import Units
from falcon_core.math.domains import KnobDomain


def test_knob_default_name():
    """Test Knob class with default names."""
    # Test with default_name instead of name
    k = Knob(default_name="amplitude", units=Units.VOLT)
    assert k.default_name == "amplitude"
    assert k.units == Units.VOLT

    # Test with both name and default_name (name should take precedence)
    k2 = Knob(default_name="frequency", units=Units.HERTZ)
    assert k2.default_name == "frequency"
    assert k2.units == Units.HERTZ

    # Test equality with default_name
    k3 = Knob(default_name="amplitude", units=Units.VOLT)
    k4 = Knob(default_name="phase", units=Units.RADIAN)
    assert k == k3
    assert k != k4

    # Test with empty strings
    with pytest.raises(ValueError):
        Knob(default_name="", units=Units.VOLT)


def test_knob_serialization():
    """Test serialization of Knob class."""
    k = Knob(default_name="phase", units=Units.RADIAN, description="Signal phase")

    # Test to_dict and from_dict
    k_dict = k.to_dict()
    k_loaded = Knob.from_dict(k_dict)
    assert k == k_loaded
    assert k.default_name == k_loaded.default_name
    assert k.units == k_loaded.units
    assert k.description == k_loaded.description

    # Test to_json and from_json
    k_json = k.to_json()
    k_from_json = Knob.from_json(k_json)
    assert k == k_from_json


def test_knobs_initialization():
    """Test initialization of Knobs collection."""
    k1 = Knob(default_name="amp", units=Units.VOLT)
    k2 = Knob(default_name="freq", units=Units.HERTZ)
    k3 = Knob(default_name="phase", units=Units.RADIAN)

    # Test initializing with list
    knobs = Knobs([k1, k2, k3])
    assert len(knobs) == 3
    assert k1 in knobs
    assert k2 in knobs
    assert k3 in knobs

    # Test getitem
    assert knobs["amp"] == k1
    assert knobs["freq"] == k2

    # Test contains
    assert "amp" in knobs
    assert "other" not in knobs

    # Test iteration
    names = set()
    for knob in knobs:
        names.add(knob.default_name)
    assert names == {"amp", "freq", "phase"}

    # Test adding knobs
    k4 = Knob(default_name="offset", units=Units.VOLT)
    knobs.append(k4)
    assert len(knobs) == 4
    assert "offset" in knobs


def test_knobs_serialization():
    """Test serialization of Knobs collection."""
    k1 = Knob(default_name="amp", units=Units.VOLT)
    k2 = Knob(default_name="freq", units=Units.HERTZ)
    knobs = Knobs([k1, k2])

    # Test to_dict and from_dict
    knobs_dict = knobs.to_dict()
    knobs_loaded = Knobs.from_dict(knobs_dict)
    assert len(knobs) == len(knobs_loaded)
    assert knobs_loaded["amp"].units == Units.VOLT
    assert knobs_loaded["freq"].units == Units.HERTZ

    # Test to_json and from_json
    knobs_json = knobs.to_json()
    knobs_from_json = Knobs.from_json(knobs_json)
    assert len(knobs) == len(knobs_from_json)
    assert "amp" in knobs_from_json
    assert "freq" in knobs_from_json


def test_knob_domain_initialization():
    """Test initialization of KnobDomain class."""
    bounds = (0.0, 5.0)
    # Test with min, max, step
    domain = KnobDomain(default_name="voltage", bounds=bounds, units=Units.VOLT)
    assert domain.default_name == "voltage"
    assert domain.bounds == bounds
    assert not domain.is_empty()


def test_knob_domain_serialization():
    """Test serialization of KnobDomain class."""
    k = Knob(default_name="power", units=Units.WATT, pseudo_name=ScreeningGate("S2"))
    domain = KnobDomain.from_knob(knob=k, bounds=(10, 100))

    # Test to_dict and from_dict
    domain_dict = domain.to_dict()
    domain_loaded = KnobDomain.from_dict(domain_dict)
    assert domain_loaded.default_name == "power"
    assert domain_loaded.lesser_bound == 10
    assert domain_loaded.greater_bound == 100
    assert domain_loaded.units == Units.WATT
