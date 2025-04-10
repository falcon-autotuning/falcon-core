"""A respopnse for a request that Falcon posited to a measurement server."""

from typing import TYPE_CHECKING

from .dependancies import Generic, Jsonable, TypeVar, arrayND

if TYPE_CHECKING:
    from .typing import LabelledMeasuredArrays

T = TypeVar("T", bound=arrayND)


class Response(Jsonable, Generic[T]):
    """A response for a request that Falcon posited to a measurement server."""

    _arrays: "LabelledMeasuredArrays[T]"

    def __init__(
        self,
        arrays: "LabelledMeasuredArrays[T]",
    ):
        """Initialize the Return object."""
        self._arrays = arrays

    @property
    def arrays(self) -> "LabelledMeasuredArrays[T]":
        """Return the dataset."""
        return self._arrays
