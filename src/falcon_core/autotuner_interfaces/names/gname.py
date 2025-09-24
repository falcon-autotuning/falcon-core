"""Group naming convention for indexingconfig files."""

from .name_base import NameBase


class Gname(NameBase):
    """Names of the form "group#" where # is a int."""

    _index_string = "group"

    def __init__(self, value: str | int):
        super().__init__(value)

    @property
    def gname(self) -> str:
        """Return the gname."""
        return self.name
