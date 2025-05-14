from falcon_core.instrument_interfaces.instrument_types import INSTRUMENT_TYPES
from falcon_core.instrument_interfaces.names import Knob
from falcon_core.math.axes import Axes
from falcon_core.math.discrete_spaces.base_discrete_space import BaseDiscreteSpace
from falcon_core.math.discretizers import CartesianDiscretizer
from falcon_core.math.domains.coupled_knob_domain import CoupledKnobDomain
from falcon_core.math.domains.knob_domain import KnobDomain
from falcon_core.math.spaces import UnitSpace
from falcon_core.physics import PlungerGate
from falcon_core.physics.units import Units

Timer = Knob(
    default_name=INSTRUMENT_TYPES.CLOCK.value,
    pseudo_name=None,
    instrument_type=INSTRUMENT_TYPES.CLOCK,
    description="Clock",
    units=Units.SECOND,
)


def test_get_projection_runs():
    # Create 2D unit space
    discretizers = [CartesianDiscretizer(delta=0.1), CartesianDiscretizer(delta=0.1)]
    axes = Axes(discretizers)
    uspace = UnitSpace(axes=axes)
    uspace.compile()

    # Create Knob objects for each axis
    knobs = [
        Knob(
            default_name=f"x{i}",
            pseudo_name=PlungerGate(f"P{i}"),
        )
        for i in range(2)
    ]

    # Create KnobDomains for each Knob
    knob_domains_list = [
        KnobDomain.from_knob(
            knob=knob,
            bounds=(0.0, 1.0),
        )
        for knob in knobs
    ]
    # Create CoupledKnobDomain axes for BaseDiscreteSpace
    coupled_knob_domains = Axes([CoupledKnobDomain([kd]) for kd in knob_domains_list])
    bds = BaseDiscreteSpace(space=uspace, axes=coupled_knob_domains)

    # Project onto both Knobs
    projection = Axes(knobs)
    result = bds.get_projection(projection)

    assert isinstance(result, Axes)
    assert result.dimension == 2
    assert len(result.axes) == 2


def test_get_projection_runs_with_instrument():
    # Create 2D unit space
    discretizers = [
        CartesianDiscretizer(delta=0.1),
        CartesianDiscretizer(delta=0.1),
        CartesianDiscretizer(delta=0.1),
    ]
    axes = Axes(discretizers)
    uspace = UnitSpace(axes=axes)
    uspace.compile()

    # Create Knob objects for each axis
    knobs = [
        Knob(
            default_name=f"x{i}",
            pseudo_name=PlungerGate(f"P{i}"),
        )
        for i in range(2)
    ] + [Timer]

    # Create KnobDomains for each Knob
    knob_domains_list = [
        KnobDomain.from_knob(
            knob=knob,
            bounds=(0.0, 1.0),
        )
        for knob in knobs
    ]
    # Create CoupledKnobDomain axes for BaseDiscreteSpace
    coupled_knob_domains = Axes([CoupledKnobDomain([kd]) for kd in knob_domains_list])
    bds = BaseDiscreteSpace(space=uspace, axes=coupled_knob_domains)

    # Project onto both Knobs
    projection = Axes(knobs)
    result = bds.get_projection(projection)

    assert isinstance(result, Axes)
    assert result.dimension == 3
    assert len(result.axes) == 3
