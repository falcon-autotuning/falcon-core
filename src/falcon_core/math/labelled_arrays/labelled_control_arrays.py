"""A group of doamin arrays that have been labelled and kept together."""

from .base_labelled_arrays import BaseLabelledArrays
from .dependancies import Generic, TypeVar, arrayND
from .labelled_control_array import LabelledControlArray

U = TypeVar("U", bound=arrayND)


class LabelledControlArrays(BaseLabelledArrays[LabelledControlArray[U]], Generic[U]):
    """A series of domain arrays that have been labelled and kept together."""

    def __init__(self, arrays: list[LabelledControlArray[U]]) -> None:
        """Initialize the LabelledArrays object."""
        super().__init__(arrays=arrays)
