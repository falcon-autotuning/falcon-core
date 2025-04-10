"""Operator naming convention for indexing config files."""

from .name_base import NameBase


class Opname(NameBase):
    """Names of the form "op#" where # is a int."""

    def __init__(self, value: str | int):
        self.index_string = "op"
        super().__init__(value)

    @property
    def opname(self) -> str:
        """Return the opname."""
        return self.name
