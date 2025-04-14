"""A collection of coupled knob domains to be attached together."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable, Knobs

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

    def get_domain(self, knob: "Knob") -> "KnobDomain":
        """Return the domain with the given knob.

        Args:
            knob: The knob to search for.

        Returns:
            The domain with the given knob.

        Raises:
            ValueError: If the knob is not found.
        """
        for domain in self._domains:
            if domain.knob == knob:
                return domain
        msg = f"Knob {knob} not found in coupled knob domain."
        raise ValueError(msg)

    def __iter__(self):
        """Return an iterator over the domains."""
        return iter(self._domains)
