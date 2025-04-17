"""A domain with a label for pretty much anything."""

from .dependancies import Generic, Jsonable, TypeVar
from .domain import Domain

T = TypeVar("T", bound=Jsonable)


class BaseLabelledDomain(Domain, Jsonable, Generic[T]):
    """A domain with a label for pretty much anything."""

    _label: "T"

    def __init__(
        self,
        bounds: tuple[float, float],
        label: "T",
        lesser_bound_contained: bool = True,
        greater_bound_contained: bool = True,
    ):
        """Initialize the LabelledDomain object."""
        super().__init__(
            bounds,
            lesser_bound_contained=lesser_bound_contained,
            greater_bound_contained=greater_bound_contained,
        )
        self._label = label

    @property
    def label(self) -> "T":
        """Return the label of the domain."""
        return self._label

    @property
    def domain(self) -> Domain:
        """Return the domain."""
        return Domain(
            bounds=self.bounds,
            lesser_bound_contained=self.lesser_bound_contained,
            greater_bound_contained=self.greater_bound_contained,
        )
