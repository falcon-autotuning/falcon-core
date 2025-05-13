"""Class definition used for organization of gates per channel."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .gate import Gate, Gates


class GateRelations(Jsonable):
    """holds the gate dictionary used to organize the gate relation lookup dictionary from the operators."""

    _relation: dict["Gate", "Gates"]

    def __init__(self, input: dict["Gate", "Gates"]) -> None:
        """Constructor initializes gatedict."""
        self._relation = input

    def __getitem__(self, key: "Gate") -> "Gates":
        """Allows user to get items like dict."""
        return self._relation[key]

    def __setitem__(self, key: "Gate", value: "Gates") -> None:
        """Allows user to set items like dict."""
        self._relation[key] = value

    def items(self):
        """Returns the items in the gatedict."""
        return self._relation.items()

    def contains(self, key: "Gate") -> bool:
        """Checks if the gatedict contains the key."""
        return key in self._relation

    def keys(self) -> list["Gate"]:
        """Returns the keys in the gatedict."""
        return list(self._relation.keys())

    def values(self) -> list["Gates"]:
        """Returns the values in the gatedict."""
        return list(self._relation.values())

    def __len__(self) -> int:
        """Returns the length of the gatedict."""
        return len(self._relation)

    def __iter__(self):
        """Returns an iterator over the gatedict."""
        return iter(self._relation)
