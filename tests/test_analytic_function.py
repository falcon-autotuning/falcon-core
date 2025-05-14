"""Test the AnalyticFunction class."""

from falcon_core.instrument_interfaces.instrument_types import INSTRUMENT_TYPES
from falcon_core.instrument_interfaces.names import Knob, Knobs
from falcon_core.math.analytic_functions import (
    AnalyticFunction,
    Identity,
    ValidatedAnalyticFunction,
)
from falcon_core.physics import PlungerGate
from falcon_core.physics.units import Units


class Clock(Knob):
    def __init__(self):
        super().__init__(
            default_name=INSTRUMENT_TYPES.CLOCK.value,
            pseudo_name=None,
            instrument_type=INSTRUMENT_TYPES.CLOCK,
            description="Clock",
            units=Units.SECOND,
        )


def test_analytic_function_identity():
    """Test initialization+compile of UnitSpace class for weird 3D space."""
    # stuff = [str(chr(i)) for i in range(ord('a'), ord('h'))]
    stuff = ["a", "b", "c", "d", "e", "f", "g", "h"]
    knobs = Knobs(
        [
            Knob(default_name=stuffi, pseudo_name=PlungerGate(name=stuffi))
            for stuffi in stuff
        ]
        + [Clock()]
    )
    knob = knobs[0]

    id = Identity(knobs=knobs, knob=knob)
    jid = id.to_json()
    idfromjson = Identity.from_json(jid)
    assert id == idfromjson
    assert id(**{key: 0.0 for key in knobs._get_instrument_facing_names()}) == 0
    assert idfromjson(**{key: 0.0 for key in knobs._get_instrument_facing_names()}) == 0


class mult2(AnalyticFunction):
    @classmethod
    def _function(cls, t: float = 0.0, a: float = 0.0, **parameters) -> float:
        return a * 2


def test_analytic_function_custom():
    """Test initialization+compile of UnitSpace class for weird 3D space."""
    stuff = ["a"]
    knobs = Knobs(
        [
            Knob(default_name=stuffi, pseudo_name=PlungerGate(name=stuffi))
            for stuffi in stuff
        ]
        + [Clock()]
    )

    af = ValidatedAnalyticFunction(
        ports=knobs,
        function=mult2(mapping={"a": "a", INSTRUMENT_TYPES.CLOCK.value: "t"}),
    )
    assert af.function.function(a=1, t=0) == 2
    assert af.function.function(t=0, a=1) == 2
    jaf = af.to_json()
    af_from_json = ValidatedAnalyticFunction.from_json(jaf)
    # assert af == af_from_json
    assert af_from_json.function.function(t=0, a=1) == 2
