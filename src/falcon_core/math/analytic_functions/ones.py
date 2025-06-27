"""A function that is all ones."""

from typing import TYPE_CHECKING

from .analytic_function import AnalyticFunction
from .constants import INSTRUMENT_TYPES
from .dependancies import Ports
from .validated_analytic_function import ValidatedAnalyticFunction

if TYPE_CHECKING:
    from .analytic_function import Number


class ConstantFunction(AnalyticFunction):
    """A special type of AnalyticFunction that multiplies a constant onto the data."""

    @property
    def scale(self) -> "Number":
        """Returns the scale factor for this function."""
        return self._scale

    def _function(
        self,
        **parameters: "Number",
    ) -> "Number":
        return self.scale

    def __init__(self, scale: "Number") -> None:
        """Initialize the IdentityFunction object.

        Args:
            scale: The scale factor for the function.
        """
        self._scale = scale
        super().__init__(
            mapping={
                INSTRUMENT_TYPES.CLOCK: "t",
            }
        )


class Constant[T: Ports](ValidatedAnalyticFunction[T]):
    """A type of function that does nothing to the underlying discrete data."""

    def __init__(
        self,
        ports: T,
        scale: "Number",
    ):
        """Initialize the Identity object.

        Args:
            knobs: the knobs for the function.
            scale: the scale factor for the function.
        """
        super().__init__(ports=ports, function=ConstantFunction(scale=scale))
