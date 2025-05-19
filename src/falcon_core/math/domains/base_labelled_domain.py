"""A domain with a label for pretty much anything."""

from .dependancies import (
    Connection,
    Instrument,
    InstrumentPort,
    Jsonable,
    TypeVar,
)
from .domain import Domain

T = TypeVar("T", bound=Jsonable)


class BaseLabelledDomain[T](
    Domain,
    Jsonable,
):
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

    def matching_label(
        self,
        label: "T",
    ) -> bool:
        """If the label matches the given label.

        Args:
            label: The label to match.

        Returns:
            True if the label matches the given label, False otherwise.
        """
        assert isinstance(self.label, InstrumentPort), "label must be an InstrumentPort"
        return (
            isinstance(label, InstrumentPort)
            and self.label == label
            or isinstance(label, Connection)
            and self.label.pseudo_name == label
            or isinstance(label, Instrument)
            and self.label.instrument_type == label
        )
