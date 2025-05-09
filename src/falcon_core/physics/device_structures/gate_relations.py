"""Class definition used for organization of gates per channel."""

from .gate import Gate, Gates


class GateRelations(dict[Gate, Gates]):
    """holds the gate dictionary used to organize the gate relation lookup dictionary from the operators."""

    def __init__(self, *args, **kwargs):
        """Constructor initializes gatedict."""
        super().__init__(*args, **kwargs)

    def __getitem__(self, key: Gate) -> Gates:
        """Allows user to get items like dict."""
        return super().__getitem__(key)

    def __setitem__(self, key: Gate, value: Gates) -> None:
        """Allows user to set items like dict."""
        super().__setitem__(key, value)
