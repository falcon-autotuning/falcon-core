"""An analytic function describing a function on some input variables."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .typing import analytic_function


class AnalyticFunction(Jsonable):
    """A class wrapper for a function to be used to describe analytic time domain shapes."""

    _value: "analytic_function"

    def __init__(self, function: "analytic_function | None" = None):
        self._value = lambda t: t
        if function is not None:
            self._value = function

    @property
    def function(self) -> "analytic_function":
        """Returns the analytic function."""
        return self._value
