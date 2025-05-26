"""A type of function that does nothig to the underlying discrete data."""

from typing import TYPE_CHECKING

from .analytic_function import AnalyticFunction
from .constants import INSTRUMENT_TYPES
from .dependancies import Knobs
from .validated_analytic_function import ValidatedAnalyticFunction

if TYPE_CHECKING:
    from .analytic_function import Number
    from .typing import Knob


class IdentityFunction(AnalyticFunction):
    """A special type of AnalyticFunction that does nothing to the underlying discrete data."""

    @property
    def knob(self) -> "Knob":
        """Return the knob for this function."""
        return self._knob

    @classmethod
    def _function(
        cls,
        x: "Number" = 0.0,
        **parameters: "Number",
    ) -> "Number":
        return x

    def __init__(self, knob: "Knob") -> None:
        """Initialize the IdentityFunction object.

        Args:
            knob: the knob for the function.
        """
        self._knob = knob
        super().__init__(
            mapping={
                self.knob.instrument_facing_name(): "x",
                INSTRUMENT_TYPES.CLOCK: "t",
            }
        )


class Identity(ValidatedAnalyticFunction[Knobs]):
    """A type of function that does nothing to the underlying discrete data."""

    def __init__(
        self,
        knobs: Knobs,
        knob: "Knob",
    ):
        """Initialize the Identity object.

        Args:
            knobs: the knobs for the function.
            knob: the selected knob for the function.
        """
        super().__init__(ports=knobs, function=IdentityFunction(knob=knob))
