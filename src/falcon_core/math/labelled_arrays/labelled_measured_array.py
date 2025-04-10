"""An array with a port label."""

from typing import TYPE_CHECKING

from .base_labelled_array import BaseLabelledArray
from .dependancies import Generic, MeasuredArray, TypeVar, arrayND

if TYPE_CHECKING:
    from .dependancies import AcquisitionContext
    from .typing import Self

ArrayT = TypeVar("ArrayT", bound=arrayND)  # Type for the array data


class LabelledMeasuredArray(
    BaseLabelledArray[MeasuredArray[ArrayT]],
    Generic[ArrayT],
):
    """An array with a port label."""

    def __init__(
        self,
        array: MeasuredArray[ArrayT],
        label: "AcquisitionContext",
    ):
        """Initialize the LabelledArray object."""
        super().__init__(array, label)

    @classmethod
    def from_array(
        cls,
        array: ArrayT,
        label: "AcquisitionContext",
    ) -> "Self":
        """Create a LabelledArray from an array.

        Args:
            array: The data array.
            label: The label.

        Returns:
            The LabelledArray object.
        """
        return cls(array=MeasuredArray(data=array), label=label)
