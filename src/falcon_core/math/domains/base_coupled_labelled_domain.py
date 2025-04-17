"""A collection of coupled labelled domains to be attached together."""

from typing import TYPE_CHECKING

from .constants import INSTRUMENT_TYPES
from .dependancies import Connection, Generic, Jsonable, Knob, TypeVar

if TYPE_CHECKING:
    from .labelled_domain import LabelledDomain
    from .typing import Sequence

T = TypeVar("T", bound=Jsonable)


class BaseCoupledLabelledDomain(Jsonable, Generic[T]):
    """A collection of coupled labelled domains to be attached together."""

    _domains: "Sequence[LabelledDomain[T]]"

    def __init__(self, domains: "Sequence[LabelledDomain[T]]"):
        """Initialize the CoupledLabelledDomain object."""
        self._domains = domains

    @property
    def domains(self) -> list["LabelledDomain[T]"]:
        """Return the domains."""
        return [domain for domain in self._domains]

    @property
    def labels(self) -> list[T]:
        """Return the labels."""
        return [domain.label for domain in self._domains]

    def get_domain(
        self,
        search: Jsonable,
    ) -> "LabelledDomain":
        """Return the domain with the given knob.

        Args:
            knob: The knob to search for.

        Returns:
            The domain with the given knob.

        Raises:
            ValueError: If the knob is not found.
        """
        for domain in self._domains:
            if isinstance(domain._label, Knob) and (
                isinstance(search, Knob)
                and domain._label == search
                or isinstance(search, Connection)
                and domain._label.pseudo_name == search
                or isinstance(search, INSTRUMENT_TYPES)
                and domain._label.instrument_type == search
            ):
                return domain
        if isinstance(search, Knob):
            type = "Knob"
        elif isinstance(search, Connection):
            type = "Connection"
        elif isinstance(search, INSTRUMENT_TYPES):
            type = "Instrument Type"
        else:
            type = search.__class__.__name__
        msg = f"{type} {search} not found in coupled knob domain."
        raise ValueError(msg)

    def _get_primary_domain(
        self,
        primary: Jsonable,
    ) -> "LabelledDomain":
        """Gets the primary domain assocated with the primary control.

        Args:
            primary : the primary control

        Returns:
            LabelledDomain : the primary domain

        Raises:
            ValueError : if the primary control is not found in the domains
        """
        for domain in self._domains:
            if isinstance(domain._label, Knob) and (
                isinstance(primary, Connection)
                and domain._label.pseudo_name == primary
                or isinstance(primary, INSTRUMENT_TYPES)
                and domain._label.instrument_type == primary
            ):
                return domain
        msg = f"Primary control {primary} not found in domains {self._domains}"
        raise ValueError(msg)

    def __iter__(self):
        """Return an iterator over the domains."""
        return iter(self._domains)
