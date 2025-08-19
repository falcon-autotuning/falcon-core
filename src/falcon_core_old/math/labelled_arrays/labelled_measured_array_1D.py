"""A 1D measured array with a port label."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable, MeasuredArray1D, array1D, cast
from .is_labelled_1D import IsLabelled1D
from .labelled_measured_array import LabelledMeasuredArray

if TYPE_CHECKING:
    from .dependancies import AcquisitionContext
    from .typing import Self


class LabelledMeasuredArray1D(
    LabelledMeasuredArray[array1D],
    IsLabelled1D,
    Jsonable,
):
    """A 1D measured array with a port label."""

    def __init__(self, array: MeasuredArray1D, label: "AcquisitionContext"):
        """Initialize the LabelledMeasuredArray1D object."""
        super().__init__(array, label)

    @property
    def array(self) -> MeasuredArray1D:
        """Get the array with the correct type.

        Overrides the parent class property to provide a more specific return type.

        Returns:
            The array with the correct type.
        """
        return cast(MeasuredArray1D, self._array)

    @classmethod
    def from_array(
        cls,
        array: array1D,
        label: "AcquisitionContext",
    ) -> "Self":
        """Create a LabelledMeasuredArray1D from a 1D array.

        Args:
            array: The 1D data array.
            label: The label.

        Returns:
            The LabelledMeasuredArray1D object.
        """
        return cls(array=MeasuredArray1D(data=array), label=label)

    def smooth(self, size: int) -> None:
        """Smooth the data using a uniform filter."""
        if not hasattr(self.array, "smooth"):
            msg = "Array does not support smoothing"
            raise TypeError(msg)
        self.array.smooth(size)
