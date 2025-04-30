"""Test for the port transforms."""

import pytest

from falcon_core.instrument_interfaces.names import (
    Knob,
    Knobs,
    Meter,
    Meters,
)
from falcon_core.instrument_interfaces.port_transforms.port_transform import (
    PortTransform,
)
from falcon_core.math.analytic_functions import AnalyticFunction, Identity
from falcon_core.physics.device_structures import Ohmic, PlungerGate


class DoNothing(AnalyticFunction):
    """A transform that does nothing."""

    def __init__(self, port: Meter):
        super().__init__(ports=Meters(port), function=lambda t: t)


class TestPortTransform:
    """Test the PortTransform class."""

    @pytest.fixture
    def knob(self) -> Knob:
        return Knob(default_name="test_knob", pseudo_name=PlungerGate("P1"))

    @pytest.fixture
    def meter(self) -> Meter:
        return Meter(default_name="test_meter", pseudo_name=Ohmic("O2"))

    @pytest.fixture
    def knob_transform(self, knob: Knob) -> Identity:
        return Identity(knobs=Knobs(knob), knob=knob)

    @pytest.fixture
    def meter_transform(self, meter: Meter) -> AnalyticFunction:
        return DoNothing(
            port=meter,
        )

    def test_port_transform_initialization_with_knob(
        self,
        knob: Knob,
        knob_transform: Identity,
    ):
        """Test that a port transform can be initialized with a knob."""
        # Create a port transform
        port_transform = PortTransform(port=knob, transform=knob_transform)

        # Check that the port transform has the correct port
        assert port_transform.port == knob
        # Check that the port transform has the correct transform
        assert port_transform.transform == knob_transform

    def test_port_transform_initialization_with_meter(
        self,
        meter: Meter,
        meter_transform: AnalyticFunction,
    ):
        """Test that a port transform can be initialized with a meter."""
        port_transform = PortTransform(
            port=meter,
            transform=meter_transform,
        )
        # Check that the port transform has the correct port
        assert port_transform.port == meter
        # Check that the port transform has the correct transform
        assert port_transform.transform == meter_transform

    def test_port_transform_validation_error(
        self,
        knob: Knob,
        meter: Meter,
        knob_transform: Identity,
        meter_transform: AnalyticFunction,
    ):
        """Test that a port transform raises an error if the transform is not valid for the port."""
        # Test that creating a port transform with mismatched port types raises an AssertionError
        with pytest.raises(AssertionError):
            PortTransform(port=knob, transform=meter_transform)

        with pytest.raises(AssertionError):
            PortTransform(port=meter, transform=knob_transform)

    def test_port_transform_to_json_from_json(
        self,
        knob: Knob,
        knob_transform: Identity,
    ):
        """Test that a port transform can be converted to and from JSON."""
        # Create a port transform
        port_transform = PortTransform(port=knob, transform=knob_transform)

        # Convert to JSON
        port_transform_json = port_transform.to_json()

        # Convert back from JSON
        recreated_port_transform = PortTransform.from_json(port_transform_json)

        # Check that the recreated port transform has the same properties
        assert recreated_port_transform.port == port_transform.port
        assert recreated_port_transform.transform == port_transform.transform

    def test_meter_transform_to_json_from_json(
        self,
        meter: Meter,
        meter_transform: AnalyticFunction,
    ):
        """Test that a port transform can be converted to and from JSON."""
        # Create a port transform
        port_transform = PortTransform(port=meter, transform=meter_transform)

        # Convert to JSON
        port_transform_json = port_transform.to_json()

        # Convert back from JSON
        recreated_port_transform = PortTransform.from_json(port_transform_json)

        # Check that the recreated port transform has the same properties
        assert recreated_port_transform.port == port_transform.port
        assert recreated_port_transform.transform == port_transform.transform
