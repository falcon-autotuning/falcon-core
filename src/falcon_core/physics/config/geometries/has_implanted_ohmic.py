"""A reservoir gate with an ohmic below it."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .dependancies import Ohmic


class HasImplantedOhmic(Jsonable):
    """A gate with an ohmic below it."""

    ohmic: "Ohmic"

    def __init__(self, ohmic: "Ohmic") -> None:
        """Creates a reservoir gate with an ohmic below it.

        Args:
            name: The name of the gate.
            ohmic: The ohmic below the reservoir gate.
        """
        self.ohmic = ohmic
