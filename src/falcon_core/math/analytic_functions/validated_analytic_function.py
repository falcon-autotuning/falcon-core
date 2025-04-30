"""A validated analytic function describing a function on some input variables."""

from typing import TYPE_CHECKING

from .analytic_function import AnalyticFunction
from .dependancies import Generic, Jsonable, Ports, TypeVar, inspect

if TYPE_CHECKING:
    from .typing import InstrumentPort

T = TypeVar("T", bound=Ports)


class ValidatedAnalyticFunction(Jsonable, Generic[T]):
    """An analytic function describing a function on some input variables."""

    _function: AnalyticFunction
    _ports: T

    def __init__(
        self,
        ports: T,
        function: AnalyticFunction | None = None,
    ):
        """Initialize the AnalyticFunction object.

        Args:
            ports: the list of possible input variables.
                The names must match the variable strings in the args of function.
            function: the symbolic function stored in this
                Note that the function must at least take a single argument, t.
        """
        super().__init__()
        self.ports = ports
        if function is None:
            self.function = AnalyticFunction()
        else:
            self.function = function

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

    def _validate_function_signature(self, function: AnalyticFunction):
        """Extract the variables from the function and compare to knobs.

        Raises:
            ValueError: If the variables in the function are not in the knobs.
        """
        input_variables = set(
            list(inspect.signature(function.function).parameters.keys())
        )
        if "t" not in input_variables:
            msg = "Function must at least take a single argument, t."
            raise ValueError(msg)
        if missing_vars := input_variables - set(self.input_variables):
            msg = (
                f"Function requires input variables {missing_vars} "
                f"that are not included in the provided knobs: {self.ports}"
            )
            raise ValueError(msg)

    @property
    def ports(self) -> "T":
        """Return the variables."""
        return self._ports

    @ports.setter
    def ports(self, value: "T"):
        """Sets the knobs."""
        self._ports = value

    @property
    def function(self) -> AnalyticFunction:
        """Access an analytic function in this format."""
        return self._function

    @function.setter
    def function(self, value: AnalyticFunction):
        """Stores function in private variables.

        The function must at least take a single argument, t.

        All of its arguments should be port.pseudo_name.name
        """
        self._validate_function_signature(function=value)
        self._function = value

    @property
    def input_variables(self) -> list[str]:
        """Return the input variables of the function."""
        return ["t"] + self.ports._get_raw_names()

    def _support_runtime_names(
        self,
        func: AnalyticFunction,
    ) -> AnalyticFunction:
        """Allows a function to support runtime attributes.

        These attributes can be used for input variables.

        Args:
            func: Base function that accepts **kwargs

        Returns:
            A function with the specified parameter names
        """

        # Create a wrapper with a signature
        def wrapper(**kwargs):
            return func.function(**kwargs)

        # Create the signature
        sig = inspect.Signature(
            [
                inspect.Parameter(name, inspect.Parameter.VAR_KEYWORD)
                for name in self.input_variables
            ]
        )

        setattr(wrapper, "__signature__", sig)
        return AnalyticFunction(wrapper)
