"""A signed object can only be 1 or -1."""


class Sign(int):
    """A signed object."""

    def __new__(cls, value):
        """When creating a new Signed object follow this method."""
        if value not in [-1, 1]:
            msg = "Value can only be -1 or 1"
            raise ValueError(msg)
        return super().__new__(cls, value)
