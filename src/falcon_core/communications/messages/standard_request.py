"""A standard communication request."""

from .base_request import BaseRequest


class StandardRequest(BaseRequest):
    """A standard communication request."""

    def __init__(self, message: str):
        """Initialize the StandardRequest object."""
        super().__init__(message)
