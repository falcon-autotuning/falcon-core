"""The simplest group of gates in the config. They cluster together to form a channel."""

from typing import TYPE_CHECKING

from ..geometries import GateGeometryArray1D
from .dependancies import Ohmics
from .standard_config_connections import StandardConfigConnections

if TYPE_CHECKING:
    from .typing import (
        BarrierGates,
        Channel,
        Connection,
        Gates,
        PlungerGates,
        ReservoirGates,
        ScreeningGates,
    )


class Group(StandardConfigConnections):
    """Elements of the config that pertain to an individual group of gates."""

    name: "Channel"
    num_dots: int
    order: GateGeometryArray1D

    def __init__(
        self,
        name: "Channel",
        num_dots: int,
        screening_gates: "ScreeningGates",
        reservoir_gates: "ReservoirGates",
        plunger_gates: "PlungerGates",
        barrier_gates: "BarrierGates",
        order: "list[Connection]",
    ) -> None:
        """This class holds information about a group of gates."""
        super().__init__(
            screening_gates=screening_gates,
            reservoir_gates=reservoir_gates,
            plunger_gates=plunger_gates,
            barrier_gates=barrier_gates,
            ohmics=Ohmics([]),
        )
        assert num_dots > 0
        self.name = name
        self.num_dots = num_dots
        self.order = GateGeometryArray1D(
            lineararray=order,
            screening_gates=screening_gates,
        )
        self.compile_ohmics()

        # Check that all gates are in Order
        if set(self.get_all_gates()) != set(
            [*self.order.raw_gates, *self.screening_gates]
        ):
            msg = "Gate lists and the Order are inconsistent. Some gates are not present in both"
            raise ValueError(msg)

    def compile_ohmics(self) -> None:
        """Gets all of the ohmics in the Group."""
        self.ohmics = self.order.ohmics

    def has_channel(self, channel: "Channel") -> bool:
        """Validates if this Channel is present.

        Args:
            channel : the Channel to be tested

        Returns:
            existence
        """
        return self.name == channel

    def get_num_dots(self) -> int:
        """Gets the stored NumDots."""
        return self.num_dots

    def is_chargesensor(self) -> bool:
        """Queries group if it is a chargesensor. A chargesensor has only 1 dot."""
        return self.get_num_dots() == 1

    def get_all_channel_gates(self, channel: "Channel") -> "Gates | None":
        """Gets all of the gates associated with the selected current channel from the config.

        Args:
            channel : the name of the channel of interest

        Returns:
            If channel is valid, all the gates.
        """
        if self.has_channel(channel=channel):
            return self.get_all_gates()
        return None
