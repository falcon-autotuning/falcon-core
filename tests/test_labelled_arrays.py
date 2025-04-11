"""Tests for labelled array classes."""

import pytest

from falcon_core.autotuner_interfaces.contexts import AcquisitionContext
from falcon_core.dependancies import np
from falcon_core.instrument_interfaces.names import (
    Knob,
    Knobs,
    Meter,
    Meters,
)
from falcon_core.math.arrays import ControlArray, MeasuredArray
from falcon_core.math.labelled_arrays import (
    LabelledControlArray,
    LabelledControlArrays,
    LabelledMeasuredArray,
    LabelledMeasuredArrays,
)
from falcon_core.physics import Ohmic, PlungerGate, Units
from falcon_core.typing import array1D


class TestLabelledControlArray:
    """Test suite for LabelledControlArray class."""

    @pytest.fixture
    def raw_data(self) -> array1D:
        """Create sample raw data for testing.

        Returns:
            array1D: A 1D array of data.
        """
        return np.linspace(-1.0, 1.0, 10)

    @pytest.fixture
    def control_array(self, raw_data: array1D) -> ControlArray[array1D]:
        """Create a sample ControlArray for testing.

        Returns:
            ControlArray: A ControlArray object.
        """
        return ControlArray(data=raw_data)

    @pytest.fixture
    def knob(self) -> Knob:
        """Create a sample Knob for testing.

        Returns:
            Knob: A Knob object.
        """
        return Knob(
            default_name="gate1",
            units=Units.VOLT,
            pseudo_name=PlungerGate("P1"),
        )

    @pytest.fixture
    def acquisition_context(
        self,
        knob: Knob,
    ) -> AcquisitionContext:
        """Create a sample AcquisitionContext for testing.

        Args:
            knob (Knob): A Knob object.

        Returns:
            AcquisitionContext: An AcquisitionContext object.
        """
        return AcquisitionContext.from_instrument_port(port=knob)

    def test_initialization(
        self,
        control_array: ControlArray[array1D],
        acquisition_context: AcquisitionContext,
    ):
        """Test initialization of LabelledControlArray."""
        labelled_array = LabelledControlArray(
            array=control_array, label=acquisition_context
        )

        # Check that the data was passed correctly
        assert labelled_array.array, control_array

        # Check that the label was passed correctly
        assert labelled_array.label == acquisition_context
        assert labelled_array.label.connection == acquisition_context.connection
        assert labelled_array.label.units == acquisition_context.units

    def test_properties(
        self,
        control_array: ControlArray[array1D],
        acquisition_context: AcquisitionContext,
    ):
        """Test properties of LabelledControlArray."""
        labelled_array = LabelledControlArray(
            array=control_array, label=acquisition_context
        )

        # Test data property
        assert labelled_array.array, control_array

        # Test connection property via the label
        assert labelled_array.label.connection == acquisition_context.connection

        # Test shape property (inherited from ControlArray)
        assert labelled_array.array.shape == control_array.shape

    def test_serialization(
        self,
        control_array: ControlArray[array1D],
        acquisition_context: AcquisitionContext,
    ):
        """Test serialization and deserialization of LabelledControlArray."""
        labelled_array = LabelledControlArray(
            array=control_array, label=acquisition_context
        )

        # Test to_dict and from_dict
        data_dict = labelled_array.to_dict()
        reconstructed = LabelledControlArray[array1D].from_dict(data_dict)

        assert reconstructed.array, labelled_array.array
        assert reconstructed.label.units == labelled_array.label.units
        assert (
            reconstructed.label.instrument_type == labelled_array.label.instrument_type
        )

        # Test to_json and from_json
        json_str = labelled_array.to_json()
        reconstructed_from_json = LabelledControlArray[array1D].from_json(json_str)

        assert reconstructed_from_json.array, labelled_array.array
        assert reconstructed_from_json.label.units == labelled_array.label.units


class TestLabelledControlArrays:
    """Test suite for LabelledControlArrays class."""

    @pytest.fixture
    def knobs(self) -> Knobs:
        """Create sample Knobs for testing.

        Returns:
            Knobs: A Knobs object.
        """
        return Knobs(
            [
                Knob(
                    default_name=f"gate{i}",
                    units=Units.VOLT,
                    pseudo_name=PlungerGate(name=f"P{i}"),
                )
                for i in range(1, 4)
            ]
        )

    @pytest.fixture
    def acquisition_contexts(
        self,
        knobs: Knobs,
    ) -> list[AcquisitionContext]:
        """Create sample AcquisitionContexts for testing.

        Args:
            knobs (Knobs): A Knobs object.

        Returns:
            list[AcquisitionContext]: A list of AcquisitionContext objects.
        """
        return [AcquisitionContext.from_instrument_port(port=knob) for knob in knobs]

    @pytest.fixture
    def labelled_control_arrays(
        self,
        acquisition_contexts: list[AcquisitionContext],
    ) -> LabelledControlArrays[array1D]:
        """Create sample LabelledControlArrays for testing.

        Args:
            acquisition_contexts (list[AcquisitionContext]): A list of AcquisitionContext objects.

        Returns:
            LabelledControlArrays: A LabelledControlArrays object.
        """
        arrays = []
        for i, context in enumerate(acquisition_contexts):
            # Create arrays with different shapes to test handling of heterogeneous arrays
            data = np.linspace(-1.0, 1.0, 10 + i)
            control_array = ControlArray[array1D](data=data)
            labelled_array = LabelledControlArray[array1D](
                array=control_array, label=context
            )
            arrays.append(labelled_array)

        return LabelledControlArrays(arrays=arrays)

    def test_initialization(
        self,
        labelled_control_arrays: LabelledControlArrays[array1D],
        acquisition_contexts: list[AcquisitionContext],
    ):
        """Test initialization of LabelledControlArrays."""
        # Check length
        assert len(labelled_control_arrays) == len(acquisition_contexts)

        # Check items were added correctly
        for i, context in enumerate(acquisition_contexts):
            assert labelled_control_arrays[context].label == context

    def test_getitem(
        self,
        labelled_control_arrays: LabelledControlArrays[array1D],
        acquisition_contexts: list[AcquisitionContext],
    ):
        """Test getitem access by name and index."""
        # Access by index
        first_array = labelled_control_arrays[acquisition_contexts[0]]
        assert isinstance(first_array, LabelledControlArray)

    def test_iteration(
        self,
        labelled_control_arrays: LabelledControlArrays[array1D],
    ):
        """Test iteration over LabelledControlArrays."""
        count = 0
        for array in labelled_control_arrays:
            assert isinstance(array, LabelledControlArray)
            count += 1

        assert count == len(labelled_control_arrays)

    def test_serialization(
        self,
        labelled_control_arrays: LabelledControlArrays[array1D],
    ):
        """Test serialization of LabelledControlArrays."""
        # Test to_dict and from_dict
        data_dict = labelled_control_arrays.to_dict()
        reconstructed = LabelledControlArrays[array1D].from_dict(data_dict)

        assert len(reconstructed) == len(labelled_control_arrays)

        for context in labelled_control_arrays.labels:
            assert reconstructed[context].array, labelled_control_arrays[context].array
            assert (
                reconstructed[context].label.units
                == labelled_control_arrays[context].label.units
            )


class TestLabelledMeasuredArray:
    """Test suite for LabelledMeasuredArray class."""

    @pytest.fixture
    def raw_data(self) -> array1D:
        """Create sample raw data for testing.

        Returns:
            array1D: A 1D array of data.
        """
        return np.random.rand(10)

    @pytest.fixture
    def measured_array(self, raw_data: array1D) -> MeasuredArray[array1D]:
        """Create a sample MeasuredArray for testing.

        Returns:
            MeasuredArray: A MeasuredArray object.
        """
        return MeasuredArray(data=raw_data)

    @pytest.fixture
    def meter(self) -> Meter:
        """Create a sample Meter for testing.

        Returns:
            Meter: A Meter object.
        """
        return Meter(
            default_name="sensor1", units=Units.AMPERE, pseudo_name=Ohmic("O1")
        )

    @pytest.fixture
    def acquisition_context(
        self,
        meter: Meter,
    ) -> AcquisitionContext:
        """Create a sample AcquisitionContext for testing.

        Returns:
            AcquisitionContext: An AcquisitionContext object.
        """
        return AcquisitionContext.from_instrument_port(port=meter)

    def test_initialization(
        self,
        measured_array: MeasuredArray[array1D],
        acquisition_context: AcquisitionContext,
    ):
        """Test initialization of LabelledMeasuredArray."""
        labelled_array = LabelledMeasuredArray(
            array=measured_array, label=acquisition_context
        )

        # Check that the data was passed correctly
        assert labelled_array.array, measured_array

        # Check that the label was passed correctly
        assert labelled_array.label == acquisition_context
        assert labelled_array.label.units == acquisition_context.units

    def test_properties(
        self,
        measured_array: MeasuredArray[array1D],
        acquisition_context: AcquisitionContext,
    ):
        """Test properties of LabelledMeasuredArray."""
        labelled_array = LabelledMeasuredArray(
            array=measured_array, label=acquisition_context
        )

        # Test data property
        assert labelled_array.array, measured_array

        # Test port-related properties
        assert labelled_array.label.units == acquisition_context.units
        assert (
            labelled_array.label.instrument_type == acquisition_context.instrument_type
        )

        # Test shape property (inherited from MeasuredArray)
        assert labelled_array.array.shape == measured_array.shape

    def test_serialization(
        self,
        measured_array: MeasuredArray[array1D],
        acquisition_context: AcquisitionContext,
    ):
        """Test serialization and deserialization of LabelledMeasuredArray."""
        labelled_array = LabelledMeasuredArray(
            array=measured_array, label=acquisition_context
        )

        # Test to_dict and from_dict
        data_dict = labelled_array.to_dict()
        reconstructed = LabelledMeasuredArray[array1D].from_dict(data_dict)

        assert reconstructed.array, labelled_array
        assert reconstructed.label.units == labelled_array.label.units
        assert (
            reconstructed.label.instrument_type == labelled_array.label.instrument_type
        )


class TestLabelledMeasuredArrays:
    """Test suite for LabelledMeasuredArrays class."""

    @pytest.fixture
    def meters(self) -> Meters:
        """Create sample Meters for testing.

        Returns:
            Meters: A Meters object.
        """
        return Meters(
            [
                Meter(
                    default_name=f"sensor{i}",
                    units=Units.AMPERE,
                    pseudo_name=Ohmic(f"O{i}"),
                )
                for i in range(1, 4)
            ]
        )

    @pytest.fixture
    def acquisition_contexts(
        self,
        meters: Meters,
    ) -> list[AcquisitionContext]:
        """Create sample AcquisitionContexts for testing.

        Args:
            meters (Meters): A Meters object.

        Returns:
            list[AcquisitionContext]: A list of AcquisitionContext objects.
        """
        return [AcquisitionContext.from_instrument_port(port=meter) for meter in meters]

    @pytest.fixture
    def labelled_measured_arrays(
        self,
        acquisition_contexts: list[AcquisitionContext],
    ) -> LabelledMeasuredArrays[array1D]:
        """Create sample LabelledMeasuredArrays for testing.

        Args:
            acquisition_contexts (list[AcquisitionContext]): A list of AcquisitionContext objects.

        Returns:
            LabelledMeasuredArrays: A LabelledMeasuredArrays object.
        """
        arrays = []
        for i, context in enumerate(acquisition_contexts):
            # Create arrays with different shapes to test handling of heterogeneous arrays
            data = np.random.rand(5 + i, 2 + i)
            measured_array = MeasuredArray(data=data)
            labelled_array = LabelledMeasuredArray(array=measured_array, label=context)
            arrays.append(labelled_array)

        return LabelledMeasuredArrays(arrays=arrays)

    def test_initialization(
        self,
        labelled_measured_arrays: LabelledMeasuredArrays[array1D],
        acquisition_contexts: list[AcquisitionContext],
    ):
        """Test initialization of LabelledMeasuredArrays."""
        # Check length
        assert len(labelled_measured_arrays) == len(acquisition_contexts)

        # Check items were added correctly
        for context in acquisition_contexts:
            assert labelled_measured_arrays[context].label == context

    def test_getitem(
        self,
        labelled_measured_arrays: LabelledMeasuredArrays[array1D],
        acquisition_contexts: list[AcquisitionContext],
    ):
        """Test getitem access by index."""
        # Access by index
        first_array = labelled_measured_arrays[acquisition_contexts[0]]
        assert isinstance(first_array, LabelledMeasuredArray)

    def test_iteration(self, labelled_measured_arrays: LabelledMeasuredArrays[array1D]):
        """Test iteration over LabelledMeasuredArrays."""
        count = 0
        for array in labelled_measured_arrays:
            assert isinstance(array, LabelledMeasuredArray)
            count += 1

        assert count == len(labelled_measured_arrays)

    def test_serialization(
        self, labelled_measured_arrays: LabelledMeasuredArrays[array1D]
    ):
        """Test serialization of LabelledMeasuredArrays."""
        # Test to_dict and from_dict
        data_dict = labelled_measured_arrays.to_dict()
        reconstructed = LabelledMeasuredArrays[array1D].from_dict(data_dict)

        assert len(reconstructed) == len(labelled_measured_arrays)

        for context in labelled_measured_arrays.labels:
            assert reconstructed[context].array, labelled_measured_arrays[context].array
            assert (
                reconstructed[context].label.units
                == labelled_measured_arrays[context].label.units
            )


class TestMixedArrayOperations:
    """Test operations between different array types."""

    @pytest.fixture
    def control_array(self) -> ControlArray[array1D]:
        """Create a sample ControlArray.

        Returns:
            ControlArray: A ControlArray
        """
        data = np.linspace(-1, 1, 10)
        return ControlArray(data=data)

    @pytest.fixture
    def measured_array(self) -> MeasuredArray[array1D]:
        """Create a sample MeasuredArray.

        Returns:
            MeasuredArray: A MeasuredArray
        """
        data = np.random.rand(10)
        return MeasuredArray(data=data)

    @pytest.fixture
    def labelled_control_array(
        self,
        control_array: ControlArray[array1D],
    ) -> LabelledControlArray[array1D]:
        """Create a sample LabelledControlArray.

        Returns:
            LabelledControlArray: A LabelledControlArray
        """
        knob = Knob(
            default_name="gate1",
            units=Units.VOLT,
            pseudo_name=PlungerGate("P1"),
        )
        context = AcquisitionContext.from_instrument_port(port=knob)
        return LabelledControlArray(array=control_array, label=context)

    @pytest.fixture
    def labelled_measured_array(
        self,
        measured_array: MeasuredArray[array1D],
    ) -> LabelledMeasuredArray[array1D]:
        """Create a sample LabelledMeasuredArray.

        Returns:
            LabelledMeasuredArray: A LabelledMeasuredArray
        """
        meter = Meter(
            default_name="sensor1",
            units=Units.AMPERE,
            pseudo_name=Ohmic("O1"),
        )
        context = AcquisitionContext.from_instrument_port(port=meter)
        return LabelledMeasuredArray(array=measured_array, label=context)

    def test_labelled_array_comparison(
        self,
        labelled_control_array: LabelledControlArray[array1D],
        labelled_measured_array: LabelledMeasuredArray[array1D],
        control_array: ControlArray[array1D],
    ):
        """Test comparing different labelled array types."""
        # Arrays with different types should not be equal
        assert labelled_control_array != labelled_measured_array

        # Create a copy of control_array
        knob = Knob(
            default_name="gate1",
            units=Units.VOLT,
            pseudo_name=PlungerGate("P1"),
        )
        context = AcquisitionContext.from_instrument_port(port=knob)
        control_array2 = ControlArray(data=control_array.data.copy())
        control_array_labelled2 = LabelledControlArray(
            array=control_array2, label=context
        )

        # Arrays with same data and same label should be equal
        assert labelled_control_array == control_array_labelled2

        # Arrays with same data but different label should not be equal
        knob3 = Knob(
            default_name="gate2",
            units=Units.VOLT,
            pseudo_name=PlungerGate("P2"),
        )
        context3 = AcquisitionContext.from_instrument_port(port=knob3)
        control_array3 = ControlArray(data=control_array.data.copy())
        control_array_labelled3 = LabelledControlArray(
            array=control_array3, label=context3
        )
        assert labelled_control_array != control_array_labelled3

    def test_array_collections(
        self,
        labelled_control_array: LabelledControlArray[array1D],
        labelled_measured_array: LabelledMeasuredArray[array1D],
    ):
        """Test working with collections of different array types."""
        # Create collections
        control_arrays = LabelledControlArrays([labelled_control_array])
        measured_arrays = LabelledMeasuredArrays([labelled_measured_array])

        # Test basic properties
        assert len(control_arrays) == 1
        assert len(measured_arrays) == 1
