"""The simplest group of gates in the config. They cluster together to form a channel."""

from typing import TYPE_CHECKING

from ..geometries import GateGeometryArray1D
from .dependancies import Jsonable, Ohmics
from .standard_config_connections import StandardConfigConnections

if TYPE_CHECKING:
    from .typing import (
        BarrierGates,
        BaseConnections,
        Channel,
        Gates,
        PlungerGates,
        ReservoirGates,
        ScreeningGates,
    )


class Group(StandardConfigConnections, Jsonable):
    """Elements of the config that pertain to an individual group of gates."""

    _name: "Channel"
    _num_dots: int
    _order: GateGeometryArray1D

    def __init__(
        self,
        name: "Channel",
        num_dots: int,
        screening_gates: "ScreeningGates",
        reservoir_gates: "ReservoirGates",
        plunger_gates: "PlungerGates",
        barrier_gates: "BarrierGates",
        order: "BaseConnections",
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
        self._name = name
        self._num_dots = num_dots
        self._order = GateGeometryArray1D(
            lineararray=order,
            screening_gates=screening_gates,
        )
        self.compile_ohmics()

        # Check that all gates are in Order
        if set(self.get_all_gates()._values) != set(
            [
                *self.order.raw_central_gates._values,
                *self.screening_gates._values,
                *self.reservoir_gates._values,
            ]
        ):
            expr1 = set(self.get_all_gates()._values)
            expr2 = set([*self.order.raw_gates._values, *self.screening_gates._values])
            expr1 == expr2
            msg = "Gate lists and the Order are inconsistent. Some gates are not present in both"
            raise ValueError(msg)

    @property
    def name(self) -> "Channel":
        """The name of the group."""
        return self._name

    @property
    def num_dots(self) -> int:
        """The number of dots in the group."""
        return self._num_dots

    @property
    def order(self) -> "GateGeometryArray1D":
        """The order of the gates in the group."""
        return self._order

    def compile_ohmics(self) -> None:
        """Gets all of the ohmics in the Group."""
        self._ohmics = self.order.ohmics

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
        return self._num_dots

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
