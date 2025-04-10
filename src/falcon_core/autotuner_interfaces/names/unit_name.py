"""Unit names for packaging."""

from .dependancies import Generic, TypeVar, dataclass

T = TypeVar("T", bound="UnitName")


@dataclass(frozen=True)
class UnitName(Generic[T]):
    """Names for the Units for packaging."""

    name: str

    def __hash__(self):
        """Allows it to be a key in dictionaries."""
        return hash(self.name)

    def __eq__(self: T, other: object):
        """Equality only supported between ManagerName."""
        if isinstance(other, self.__class__):
            return self.name == other.name
        return False
