"""Manager naming convention for ordering config files."""

from .name_base import NameBase


class Manname(NameBase):
    """Names of the form "man#" where # is a int."""

    def __init__(self, value: str | int):
        self.index_string = "man"
        super().__init__(value)

    @property
    def manname(self) -> str:
        """Return the manname."""
        return self.name
