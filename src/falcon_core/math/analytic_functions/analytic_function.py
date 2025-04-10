"""An analytic function describing a function on some input variables."""

from typing import TYPE_CHECKING

from .dependancies import Generic, Jsonable, Ports, TypeVar, inspect

if TYPE_CHECKING:
    from .typing import InstrumentPort, analytic_function

T = TypeVar("T", bound=Ports)

DEFAULT_INPUT = 0.0


class AnalyticFunction(Jsonable, Generic[T]):
    """An analytic function describing a function on some input variables."""

    _function: "analytic_function"
    _ports: T

    def __init__(
        self,
        ports: T,
        function: "analytic_function | None" = None,
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
        self._function = lambda t: t
        if function is not None:
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

    def _validate_function_signature(self, function: "analytic_function"):
        """Extract the variables from the function and compare to knobs.

        Raises:
            ValueError: If the variables in the function are not in the knobs.
        """
        input_variables = set(list(inspect.signature(function).parameters.keys()))
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
    def function(self) -> "analytic_function":
        """Access an analytic function in this format."""
        return self._function

    @function.setter
    def function(self, value: "analytic_function"):
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
        func: "analytic_function",
    ) -> "analytic_function":
        """Allows a function to support runtime attributes.

        These attributes can be used for input variables.

        Args:
            func: Base function that accepts **kwargs

        Returns:
            A function with the specified parameter names
        """

        # Create a wrapper with a signature
        def wrapper(**kwargs):
            return func(**kwargs)

        # Create the signature
        sig = inspect.Signature(
            [
                inspect.Parameter(name, inspect.Parameter.VAR_KEYWORD)
                for name in self.input_variables
            ]
        )

        setattr(wrapper, "__signature__", sig)
        return wrapper
