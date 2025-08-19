"""An analytic function describing a function on some input variables."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .typing import TypeAlias

InstrumentFacingName: "TypeAlias" = str
VariableName: "TypeAlias" = str
Number: "TypeAlias" = float
InstrumentFacingVariableMap: "TypeAlias" = dict[InstrumentFacingName, VariableName]


class AnalyticFunction(Jsonable):
    """A class wrapper for a function to be used to describe analytic time domain shapes.

    This object can wrap a function of the form
    def func(cls, t: Number=0.0, x : Number=0.0,..., **parameters: Number) -> Number
    where the user can specify specific arguments if they so choose.
    Every argument muct be a keyword argument, so you must supply a default value.
    """

    _mapping: InstrumentFacingVariableMap

    @property
    def mapping(self) -> InstrumentFacingVariableMap:
        """Return a mapping of the function's arguments to their names."""
        return self._mapping

    def _function(self, **parameters: Number) -> Number: ...

    def __init__(
        self,
        mapping: InstrumentFacingVariableMap,
    ):
        self._mapping = mapping

    def name_mapping(
        self,
        **name_pairs: Number,
    ) -> dict[VariableName, Number]:
        """Maps the names of the space onto the functions arguments."""
        return {
            self.mapping[key]: value
            for key, value in name_pairs.items()
            if key in self.mapping
        }

    def function(self, **parameters: Number) -> Number:
        """Returns the analytic function."""
        # Validate that the provided kwargs match the expected parameters of _function
        function_arguments = self.name_mapping(**parameters)
        return self._function(**function_arguments)
