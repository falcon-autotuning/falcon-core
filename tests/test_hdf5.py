import tempfile
from pathlib import Path
from typing import TYPE_CHECKING

import numpy as np
import pytest

from falcon_core.communications.hdf5.data import HDF5Data
from falcon_core.communications.messages.measurement_request import MeasurementRequest
from falcon_core.communications.messages.measurement_response import MeasurementResponse
from falcon_core.instrument_interfaces.instrument_types import INSTRUMENT_TYPES
from falcon_core.instrument_interfaces.names import Knob
from falcon_core.instrument_interfaces.waveforms.cartesian_waveform import (
    CartesianWaveform,
)
from falcon_core.math.arrays.measured_array import MeasuredArray
from falcon_core.math.domains import KnobDomain
from falcon_core.math.domains.coupled_knob_domain import CoupledKnobDomain
from falcon_core.math.labelled_arrays.base_labelled_array import AcquisitionContext
from falcon_core.math.labelled_arrays.labelled_measured_array import (
    LabelledMeasuredArray,
)
from falcon_core.math.labelled_arrays.labelled_measured_arrays import (
    LabelledMeasuredArrays,
)
from falcon_core.math.spaces.dependancies import Axes, Domain
from falcon_core.physics.device_structures.barrier_gate import BarrierGate
from falcon_core.physics.device_structures.ohmic import Ohmic
from falcon_core.physics.device_structures.plunger_gate import PlungerGate
from falcon_core.physics.units import Units

if TYPE_CHECKING:
    from falcon_core.math.spaces.dependancies import ControlArray


@pytest.fixture
def shape():
    return (69, 37, 42)


@pytest.fixture
def domain_labels():
    coupled_knob_domain1 = CoupledKnobDomain(
        [
            KnobDomain.from_knob_and_domain(
                knob=Knob(
                    default_name="knob1",
                    pseudo_name=PlungerGate("P1"),
                    units=Units.VOLT,
                ),
                domain=Domain((-1, 1.8)),
            ),
            KnobDomain.from_knob_and_domain(
                knob=Knob(
                    default_name="knob2",
                    pseudo_name=BarrierGate("B1"),
                    units=Units.VOLT,
                ),
                domain=Domain((-2, 1.3)),
            ),
        ]
    )
    coupled_knob_domain2 = CoupledKnobDomain(
        [
            KnobDomain.from_knob_and_domain(
                knob=Knob(
                    default_name="knob3",
                    pseudo_name=BarrierGate("B5"),
                    units=Units.VOLT,
                ),
                domain=Domain((-0, 1.3)),
            )
        ]
    )
    coupled_knob_domain3 = CoupledKnobDomain(
        [
            KnobDomain.from_knob_and_domain(
                knob=Knob(
                    default_name="knob4",
                    pseudo_name=BarrierGate("B9"),
                    units=Units.VOLT,
                ),
                domain=Domain((-0.2, 0.3)),
            )
        ]
    )
    return Axes(
        [
            coupled_knob_domain1,
            coupled_knob_domain2,
            coupled_knob_domain3,
        ]
    )


@pytest.fixture
def ranges(shape: tuple[int, ...]):
    arr = np.random.rand(*shape)
    measured_array = MeasuredArray(arr)
    # Create a label (AcquisitionContext)
    label = AcquisitionContext(
        instrument_type=INSTRUMENT_TYPES.AMNMETER,
        units=Units.AMPERE,
        connection=Ohmic("test_connection"),
    )
    # Create a LabelledMeasuredArray
    labelled_array = LabelledMeasuredArray(measured_array, label)
    # Create LabelledMeasuredArrays collection
    return LabelledMeasuredArrays([labelled_array])


@pytest.fixture
def response(ranges):
    return MeasurementResponse(arrays=ranges)


@pytest.fixture
def waveform(domain_labels: Axes[CoupledKnobDomain], shape: tuple[int, ...]):
    wave = CartesianWaveform.from_divisions(
        divisions=Axes([s - 1 for s in shape]),
        axes=domain_labels,
    )
    wave._space.space.compile()
    return wave


@pytest.fixture
def unit_domain(waveform: CartesianWaveform):
    count = waveform._space._axes.dimension
    axes = Axes([int(value) for value in np.arange(start=0, stop=count, step=1)])
    return waveform._space._space.create_array(axes=axes)  # type: ignore[]


@pytest.fixture
def measurement_request(
    domain_labels: Axes[CoupledKnobDomain],
    unit_domain: Axes["ControlArray"],
    shape: tuple[int, ...],
):
    return MeasurementRequest(
        meter_transforms=[],
        measurement_name="test",
        message="Conversion tests",
        waveforms=[
            CartesianWaveform.from_divisions(
                divisions=Axes([s - 1 for s in shape]),
                axes=domain_labels,
            )
        ],
    )


@pytest.fixture
def measurement_title():
    return "test"


@pytest.fixture
def unique_id():
    return "123"


@pytest.fixture
def timestamp():
    return "now"


@pytest.fixture
def hdf5_data(
    domain_labels: Axes[CoupledKnobDomain],
    measurement_request: MeasurementRequest,
    response: MeasurementResponse,
    ranges: LabelledMeasuredArrays,
    unit_domain: Axes["ControlArray"],
    measurement_title: str,
    unique_id: str,
    timestamp: str,
    shape: tuple[int, ...],
):
    metadata = {
        "jsonable_request": measurement_request.to_json(),
        "jsonable_response": response.to_json(),
    }
    return HDF5Data(
        shape=Axes([s - 1 for s in shape]),
        unit_domain=unit_domain,
        domain_labels=domain_labels,
        ranges=ranges,
        metadata=metadata,
        measurement_title=measurement_title,
        timestamp=timestamp,
        unique_id=unique_id,
    )


def test_json_serialization(hdf5_data):
    json_str = hdf5_data.to_json()
    loaded = HDF5Data.from_json(json_str)
    assert loaded._dimensions == hdf5_data._dimensions
    assert loaded._metadata == hdf5_data._metadata
    assert loaded._ranges == hdf5_data._ranges
    assert loaded._measurement_title == hdf5_data._measurement_title
    assert loaded._unique_id == hdf5_data._unique_id
    assert loaded._timestamp == hdf5_data._timestamp


def test_hdf5_file_serialization(hdf5_data):
    with tempfile.NamedTemporaryFile(delete=False) as tmp:
        hdf5_data.to_file(tmp.name)
        loaded = HDF5Data.from_file(tmp.name)
        assert loaded._dimensions == hdf5_data._dimensions
        assert loaded._metadata == hdf5_data._metadata
        assert loaded._measurement_title == hdf5_data._measurement_title
        assert loaded._unique_id == hdf5_data._unique_id
        assert loaded._timestamp == hdf5_data._timestamp
        assert loaded._ranges == hdf5_data._ranges
        assert loaded._domains == hdf5_data._domains
    Path.unlink(tmp.name)


def test_communications_serialization(
    measurement_request: MeasurementRequest,
    response: MeasurementResponse,
    measurement_title: str,
    unique_id: str,
    timestamp: str,
):
    print("the measurement request is", measurement_request)
    data = HDF5Data.from_communications(
        request=measurement_request,
        response=response,
        measurement_title=measurement_title,
        unique_id=unique_id,
        timestamp=timestamp,
    )
    with tempfile.NamedTemporaryFile(delete=False) as tmp:
        data.to_file(tmp.name)
        loaded = HDF5Data.from_file(tmp.name)
    loaded_response, loaded_request = loaded.to_communications()
    assert loaded_request == measurement_request
    assert loaded_response == response
