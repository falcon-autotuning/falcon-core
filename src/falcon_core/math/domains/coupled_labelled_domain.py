"""A collection of coupled labelled domains to be attached together."""

from .base_coupled_labelled_domain import BaseCoupledLabelledDomain
from .dependancies import Generic, TypeVar
from .typing import Any

T = TypeVar("T", bound=Any)


class CoupledLabelledDomain(BaseCoupledLabelledDomain, Generic[T]):
    """A collection of coupled labelled domains to be attached together."""
