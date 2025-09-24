"""A standard communication request."""

from .base_message import BaseMessage


class StandardRequest(BaseMessage):
    """A standard communication request."""

    def __init__(self, message: str):
        """Initialize the StandardRequest object."""
        super().__init__(message)
