"""A 1D control array with a port label."""

from typing import TYPE_CHECKING

from .dependancies import ControlArray1D, Jsonable, array1D, cast
from .is_labelled_1D import IsLabelled1D
from .labelled_control_array import LabelledControlArray

if TYPE_CHECKING:
    from .dependancies import AcquisitionContext
    from .typing import Self


class LabelledControlArray1D(
    LabelledControlArray[array1D],
    IsLabelled1D,
    Jsonable,
):
    """A 1D control array with a port label."""

    def __init__(self, array: ControlArray1D, label: "AcquisitionContext"):
        """Initialize the LabelledControlArray1D object."""
        super().__init__(array, label)

    @property
    def array(self) -> ControlArray1D:
        """Get the array with the correct type.

        Overrides the parent class property to provide a more specific return type.

        Returns:
            The array with the correct type.
        """
        return cast(ControlArray1D, self._array)

    @classmethod
    def from_array(
        cls,
        array: array1D,
        label: "AcquisitionContext",
    ) -> "Self":
        """Create a LabelledControlArray1D from a 1D array.

        Args:
            array: The 1D data array.
            label: The label.

        Returns:
            The LabelledControlArray1D object.
        """
        return cls(array=ControlArray1D(data=array), label=label)
