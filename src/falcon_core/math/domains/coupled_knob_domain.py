"""A collection of coupled knob domains to be attached together."""

from typing import TYPE_CHECKING

from .constants import INSTRUMENT_TYPES
from .dependancies import Connection, Jsonable, Knobs

if TYPE_CHECKING:
    from .dependancies import Knob
    from .knob_domain import KnobDomain


class CoupledKnobDomain(Jsonable):
    """A collection of coupled knob domains to be attached together."""

    _domains: list["KnobDomain"]

    def __init__(self, domains: list["KnobDomain"]):
        """Initialize the CoupledKnobDomain object."""
        self._domains = domains

    @property
    def domains(self) -> list["KnobDomain"]:
        """Return the domains."""
        return self._domains

    @property
    def knobs(self) -> "Knobs":
        """Return the knobs."""
        return Knobs([domain.knob for domain in self._domains])

    def get_domain(
        self,
        search: "Knob | Connection | INSTRUMENT_TYPES",
    ) -> "KnobDomain":
        """Return the domain with the given knob.

        Args:
            knob: The knob to search for.

        Returns:
            The domain with the given knob.

        Raises:
            ValueError: If the knob is not found.
        """
        for domain in self._domains:
            if (
                isinstance(search, Knob)
                and domain.knob == search
                or isinstance(search, Connection)
                and domain.knob.pseudo_name == search
                or isinstance(search, INSTRUMENT_TYPES)
                and domain.knob.instrument_type == search
            ):
                return domain
        if isinstance(search, Knob):
            type = "Knob"
        elif isinstance(search, Connection):
            type = "Connection"
        elif isinstance(search, INSTRUMENT_TYPES):
            type = "Instrument Type"
        msg = f"{type} {search} not found in coupled knob domain."
        raise ValueError(msg)

    def _get_primary_domain(
        self,
        primary: Connection | INSTRUMENT_TYPES,
    ) -> KnobDomain:
        """Gets the primary domain assocated with the primary control.

        Args:
            primary : the primary control
            domains : the domains of the measurement

        Returns:
            KnobDomain : the primary domain

        Raises:
            ValueError : if the primary control is not found in the domains
        """
        for domain in self._domains:
            if (
                isinstance(primary, Connection)
                and domain.knob.pseudo_name == primary
                or isinstance(primary, INSTRUMENT_TYPES)
                and domain.knob.instrument_type == primary
            ):
                return domain
        msg = f"Primary control {primary} not found in domains {self._domains}"
        raise ValueError(msg)

    def __iter__(self):
        """Return an iterator over the domains."""
        return iter(self._domains)
