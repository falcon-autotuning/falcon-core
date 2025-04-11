"""A standard communication request."""

from .base_message import BaseMessage


class StandardResponse(BaseMessage):
    """A standard communication request."""

    def __init__(self, message: str):
        """Initialize the StandardResponse object."""
        super().__init__(message)
