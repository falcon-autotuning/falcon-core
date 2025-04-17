"""A domain with a label for pretty much anything."""

from .base_labelled_domain import BaseLabelledDomain
from .dependancies import Generic, Jsonable, TypeVar

T = TypeVar("T", bound=Jsonable)


class LabelledDomain(BaseLabelledDomain, Generic[T]):
    """A domain with a label for pretty much anything."""
