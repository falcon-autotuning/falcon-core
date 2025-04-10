"""A group of arrays that have been labelled and kept together."""

from .base_labelled_arrays import BaseLabelledArrays
from .dependancies import Generic, TypeVar, arrayND
from .labelled_measured_array import LabelledMeasuredArray

U = TypeVar("U", bound=arrayND)


class LabelledMeasuredArrays(BaseLabelledArrays[LabelledMeasuredArray[U]], Generic[U]):
    """A series of arrays that have been labelled and kept together."""

    def __init__(self, arrays: list[LabelledMeasuredArray[U]]) -> None:
        """Initialize the LabelledArrays object."""
        super().__init__(arrays=arrays)
