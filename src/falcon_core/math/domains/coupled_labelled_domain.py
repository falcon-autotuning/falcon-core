"""A collection of coupled labelled domains to be attached together."""

from .base_coupled_labelled_domain import BaseCoupledLabelledDomain
from .dependancies import Generic, Jsonable, TypeVar

T = TypeVar("T", bound=Jsonable)


class CoupledLabelledDomain(BaseCoupledLabelledDomain, Generic[T]):
    """A collection of coupled labelled domains to be attached together."""
