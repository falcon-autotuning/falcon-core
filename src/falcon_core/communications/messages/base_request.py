"""A request for a measrurement that Falcon can perform."""

from .dependancies import Jsonable


class BaseRequest(Jsonable):
    """A request for something."""

    _message: str

    def __init__(
        self,
        message: str,
    ):
        """Initialize the Request object."""
        self._message = message

    @property
    def message(self) -> str:
        """Return the message."""
        return self._message
