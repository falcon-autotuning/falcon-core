"""Test the AnalyticFunction class."""

from falcon_core.instrument_interfaces.names import Knob, Knobs
from falcon_core.math.analytic_functions import (
    AnalyticFunction,
    Identity,
    ValidatedAnalyticFunction,
)
from falcon_core.physics import PlungerGate


def test_analytic_function_identity():
    """Test initialization+compile of UnitSpace class for weird 3D space."""
    # stuff = [str(chr(i)) for i in range(ord('a'), ord('h'))]
    stuff = ["a", "b", "c", "d", "e", "f", "g", "h"]
    knobs = Knobs(
        [
            Knob(default_name=stuffi, pseudo_name=PlungerGate(name=stuffi))
            for stuffi in stuff
        ]
    )
    knob = knobs[0]

    id = Identity(knobs=knobs, knob=knob)
    jid = id.to_json()
    idfromjson = Identity.from_json(jid)
    assert id == idfromjson
    assert id.function.function(**{key: 0.0 for key in ["t"] + stuff}) == 0
    assert idfromjson.function.function(**{key: 0.0 for key in ["t"] + stuff}) == 0


def test_analytic_function_custom():
    """Test initialization+compile of UnitSpace class for weird 3D space."""
    stuff = ["a"]
    knobs = Knobs(
        [
            Knob(default_name=stuffi, pseudo_name=PlungerGate(name=stuffi))
            for stuffi in stuff
        ]
    )

    def func(t: float, a: float) -> float:
        return a * 2

    af = ValidatedAnalyticFunction(ports=knobs, function=AnalyticFunction(func))
    assert af.function.function(t=0, a=1) == 2
    assert af.function.function(a=1, t=0) == 2
    jaf = af.to_json()
    af_from_json = ValidatedAnalyticFunction.from_json(jaf)
    # assert af == af_from_json
    assert af_from_json.function.function(t=0, a=1) == 2


def test_analytic_function_custom_reversed():
    """Test initialization+compile of UnitSpace class for weird 3D space."""
    stuff = ["a"]
    knobs = Knobs(
        [
            Knob(default_name=stuffi, pseudo_name=PlungerGate(name=stuffi))
            for stuffi in stuff
        ]
    )

    def func(a: float, t: float) -> float:
        return a * 2

    af = ValidatedAnalyticFunction(ports=knobs, function=AnalyticFunction(func))
    assert af.function.function(t=0, a=1) == 2
    assert af.function.function(a=1, t=0) == 2
    jaf = af.to_json()
    af_from_json = ValidatedAnalyticFunction.from_json(jaf)
    # assert af == af_from_json
    assert af_from_json.function.function(t=0, a=1) == 2
