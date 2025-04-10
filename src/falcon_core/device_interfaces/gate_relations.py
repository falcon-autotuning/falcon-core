"""Class definition used for organization of gates per channel."""

from .gate import Gate, Gates


class GateDict(dict[Gate, Gates]):
    """holds the gate dictionary used to organize the gate relation lookup dictionary from the operators."""

    valid_values = list[Gate]

    def __init__(self):
        """Constructor initializes gatedict."""
        super().__init__()

    def __getitem__(self, key: Gate) -> valid_values:
        """Allows user to get items like dict."""
        return super().__getitem__(key)

    def __setitem__(self, key: Gate, value: valid_values) -> None:
        """Allows user to set items like dict."""
        super().__setitem__(key, value)
