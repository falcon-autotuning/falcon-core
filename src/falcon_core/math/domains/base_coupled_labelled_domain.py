"""A collection of coupled labelled domains to be attached together."""

from typing import TYPE_CHECKING

from .dependancies import (
    Generic,
    Jsonable,
    TypeVar,
)

if TYPE_CHECKING:
    from .labelled_domain import BaseLabelledDomain
    from .typing import Any, Iterator, Sequence

T = TypeVar("T", bound=Jsonable)


class BaseCoupledLabelledDomain(Jsonable, Generic[T]):
    """A collection of coupled labelled domains to be attached together."""

    _domains: "Sequence[BaseLabelledDomain[T]]"

    def __init__(
        self,
        domains: "Sequence[BaseLabelledDomain[T]]",
    ):
        """Initialize the CoupledBaseLabelledDomain object."""
        self._domains = domains

    @property
    def domains(self) -> list["BaseLabelledDomain[T]"]:
        """Return the domains."""
        return [domain for domain in self._domains]

    @property
    def labels(self) -> "list[T]":
        """Return the labels."""
        return [domain.label for domain in self._domains]

    def get_domain(
        self,
        search: "Any",
    ) -> "BaseLabelledDomain[T]":
        """Return the domain with the given knob.

        Args:
            search: The element to search for.

        Returns:
            The domain with the given knob.

        Raises:
            ValueError: If the knob is not found.
        """
        domain = next(
            (domain for domain in self._domains if domain.matching_label(search)), None
        )
        if domain is None:
            msg = f"No domain found matching label: {search}"
            raise ValueError(msg)
        return domain

    def __iter__(self) -> "Iterator[BaseLabelledDomain[T]]":
        """Return an iterator over the domains."""
        return iter(self._domains)
