"""An adressable set of hypercube axes."""

from typing import TYPE_CHECKING, TypeVar

from .dependancies import Generic, Jsonable

if TYPE_CHECKING:
    from .typing import Any


T_co = TypeVar("T_co", covariant=True)


class Axes(Jsonable, Generic[T_co]):
    """An adressable set of hypercube axes.

    The order matters, as it is used to index the hypercube.
    """

    _axes: list[T_co]

    def __init__(self, axes: list[T_co]):
        """Initialize the Axes object."""
        super().__init__()
        self._axes = axes

    @property
    def axes(self) -> list[T_co]:
        """Return the axes."""
        return self._axes

    def __getitem__(self, index: int) -> T_co:
        """Return the axis at the given index."""
        return self._axes[index]

    def __len__(self) -> int:
        """Return the number of axes."""
        return len(self._axes)

    def __iter__(self):
        """Return an iterator over the axes."""
        return iter(self._axes)

    def index(self, value: "Any") -> int:
        """Return the index of the given value."""
        assert value in self._axes, f"{value} not in {self._axes}"
        return self._axes.index(value)

    @property
    def dimension(self):
        """Return the number of dimensions."""
        return len(self)
