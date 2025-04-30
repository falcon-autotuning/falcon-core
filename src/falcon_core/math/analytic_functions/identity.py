"""A type of function that does nothig to the underlying discrete data."""

from typing import TYPE_CHECKING

from .analytic_function import AnalyticFunction
from .dependancies import Knobs
from .validated_analytic_function import ValidatedAnalyticFunction

if TYPE_CHECKING:
    from .typing import Knob


class Identity(ValidatedAnalyticFunction[Knobs]):
    """A type of function that does nothig to the underlying discrete data."""

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
        super().__init__(ports=knobs)
        self.knob = knob
        self.function = self._support_runtime_names(AnalyticFunction(self.identity))

    def identity(
        self,
        **mapping: float,
    ) -> float:
        """Return the value of the function."""
        return mapping[self.knob.pseudo_name.name]
