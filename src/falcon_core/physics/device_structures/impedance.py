"""A primitiv class to organize fridge impedance calibrations."""

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from .base_connection import BaseConnection
    from .typing import TypeAlias

Impedances: "TypeAlias" = list["Impedance"]


class Impedance:
    """The net impedance of the fridge wiring leading to connection on sample.

    Args:
        connection (Connection): the connection to the sample
        resistance (float): the net resistance leading to the sample in the fridge [1/S]
        capacitance (float): the net capacitance leadign to the sample in the fridge [F]
    """

    def __init__(
        self,
        connection: "BaseConnection",
        resistance: float,
        capacitance: float,
    ) -> None:
        """Initialize the Impedance object."""
        self.connection = connection
        self.resistance = resistance
        self.capacitance = capacitance
