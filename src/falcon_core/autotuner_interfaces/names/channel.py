"""A primitive model for a current channel on a quantum dot device."""

from typing import TYPE_CHECKING

from .dependancies import dataclass

if TYPE_CHECKING:
    from .typing import TypeAlias

Channels: "TypeAlias" = list["Channel"]


@dataclass(frozen=True, repr=True)
class Channel:
    """A string corresponsing to the name of a Channel."""

    name: str

    def __str__(self) -> str:
        """How a Channel acts like a string."""
        return self.name
