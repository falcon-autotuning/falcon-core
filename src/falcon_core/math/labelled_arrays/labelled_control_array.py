"""An array with a port label."""

from typing import TYPE_CHECKING

from .base_labelled_array import BaseLabelledArray
from .dependancies import ControlArray, TypeVar, arrayND

if TYPE_CHECKING:
    from .dependancies import AcquisitionContext
    from .typing import Self

T = TypeVar("T", bound=arrayND)


class LabelledControlArray[T: arrayND](
    BaseLabelledArray[ControlArray[T]],
):
    """An array with a port label."""

    def __init__(self, array: ControlArray[T], label: "AcquisitionContext"):
        """Initialize the LabelledArray object."""
        super().__init__(array, label)

    @classmethod
    def from_array(
        cls,
        array: T,
        label: "AcquisitionContext",
    ) -> "Self":
        """Create a LabelledArray from an array.

        Args:
            array: The data array.
            label: The label.

        Returns:
            The LabelledArray object.
        """
        return cls(array=ControlArray(data=array), label=label)
