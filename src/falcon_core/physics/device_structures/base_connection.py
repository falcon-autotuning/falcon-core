"""A generic BaseConnection on a quantum dot device."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable, overload

if TYPE_CHECKING:
    from .typing import TypeAlias

BaseConnections: "TypeAlias" = list["BaseConnection"]


class BaseConnection(Jsonable):
    """Contains the name corresponding to a particular BaseConnection on the sample."""

    _name: str

    def __init__(
        self,
        name: str,
    ) -> None:
        """Initialize the BaseConnection object.

        Args:
            name (str): The name of the BaseConnection.
        """
        self._name = name

    @property
    def name(self) -> str:
        """Return the name of the BaseConnection."""
        return self._name

    @overload
    def __add__(
        self,
        other: str,
    ) -> str: ...

    @overload
    def __add__(
        self,
        other: "BaseConnections | BaseConnection",
    ) -> list["BaseConnection"]: ...

    def __add__(
        self,
        other: "str | BaseConnections | BaseConnection",
    ) -> str | BaseConnections:
        """Addition support."""
        if isinstance(other, str):
            return self.name + other
        if isinstance(other, BaseConnection):
            return [self, other]
        if isinstance(other, list):
            for element in other:
                if not isinstance(element, BaseConnection):
                    msg = f"Addition only works between Gate and Ohmic objects through concatenation. You supplied a {type(element)}"
                    raise TypeError(msg)
            other.append(self)
            return other
        msg = f"Addition only works between Gate and Ohmic objects through concatenation. You supplied a {type(other)}"
        raise TypeError(msg)

    def __radd__(
        self,
        other: "str | BaseConnections | BaseConnection",
    ) -> str | BaseConnections:
        """Addition support."""
        return self.__add__(other)

    def __str__(self) -> str:
        return self.name
