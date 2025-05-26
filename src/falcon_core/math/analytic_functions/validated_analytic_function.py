"""A validated analytic function describing a function on some input variables."""

from typing import TYPE_CHECKING

from .constants import INSTRUMENT_TYPES
from .dependancies import Generic, Jsonable, Ports, TypeVar

if TYPE_CHECKING:
    from .analytic_function import AnalyticFunction
    from .typing import InstrumentPort

T = TypeVar("T", bound=Ports)


class ValidatedAnalyticFunction(Jsonable, Generic[T]):
    """An analytic function describing a function on some input variables."""

    _function: "AnalyticFunction"
    _ports: T

    def __init__(
        self,
        ports: T,
        function: "AnalyticFunction",
    ):
        """Initialize the AnalyticFunction object.

        Args:
            ports: the list of possible input variables.
                The names must match the variable strings in the args of function.
                The Clock port must be included in the list of ports.
            function: the symbolic function stored in this
        """
        self.ports = ports
        assert INSTRUMENT_TYPES.CLOCK in self.input_variables, (
            "User did not provide a clock port"
        )

        self.function = function

    @property
    def ports(self) -> "T":
        """Return the variables."""
        return self._ports

    @ports.setter
    def ports(self, value: "T"):
        """Sets the knobs."""
        self._ports = value

    @property
    def function(self) -> "AnalyticFunction":
        """Access an analytic function in this format."""
        return self._function

    @function.setter
    def function(self, value: "AnalyticFunction"):
        """Stores function in private variables.

        The function must at least take a single argument, t.

        All of its arguments should be port.pseudo_name.name
        """
        self._validate_function_signature(function=value)
        self._function = value

    @property
    def input_variables(self) -> list[str]:
        """Return the input variables of the function."""
        return self.ports._get_instrument_facing_names()

    def validate_port(
        self,
        port: "InstrumentPort",
    ) -> bool:
        """Validate that the port is in the domain.

        Args:
            port: the port to validate.

        Returns:
            True if the port is in the ports, False otherwise.
        """
        return port in self.ports

    def _validate_function_signature(self, function: "AnalyticFunction"):
        """Extract the variables from the function and compare to knobs.

        Raises:
            ValueError: If the variables in the function are not in the knobs.
        """
        input_variables = set(function.mapping.keys())
        if INSTRUMENT_TYPES.CLOCK not in input_variables:
            msg = "Function must always depend on a clock."
            raise ValueError(msg)
        if missing_vars := input_variables - set(self.input_variables):
            msg = (
                f"Function requires input variables {missing_vars} "
                f"that are not included in the provided knobs: {self.ports}"
            )
            raise ValueError(msg)

    def __call__(self, **kwargs) -> float:
        """Call the function with the provided arguments."""
        return self.function.function(**kwargs)
