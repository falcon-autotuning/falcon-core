"""A type of function that does nothig to the underlying discrete data."""

from typing import TYPE_CHECKING

from .analytic_function import AnalyticFunction
from .constants import INSTRUMENT_TYPES
from .dependancies import Ports
from .validated_analytic_function import ValidatedAnalyticFunction

if TYPE_CHECKING:
    from .analytic_function import Number
    from .typing import InstrumentPort


class IdentityFunction[T: InstrumentPort](AnalyticFunction):
    """A special type of AnalyticFunction that does nothing to the underlying discrete data."""

    @property
    def port(self) -> "T":
        """Return the port for this function."""
        return self._port

    @classmethod
    def _function(
        cls,
        x: "Number" = 0.0,
        **parameters: "Number",
    ) -> "Number":
        return x

    def __init__(self, port: T) -> None:
        """Initialize the IdentityFunction object.

        Args:
            port: the port for the function.
        """
        self._port = port
        super().__init__(
            mapping={
                self.port.instrument_facing_name(): "x",
                INSTRUMENT_TYPES.CLOCK: "t",
            }
        )


class Identity[T: Ports](ValidatedAnalyticFunction[T]):
    """A type of function that does nothing to the underlying discrete data."""

    def __init__(
        self,
        ports: T,
        port: "InstrumentPort",
    ):
        """Initialize the Identity object.

        Args:
            knobs: the knobs for the function.
            knob: the selected knob for the function.
        """
        super().__init__(ports=ports, function=IdentityFunction(port=port))
