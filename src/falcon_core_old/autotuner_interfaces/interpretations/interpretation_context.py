"""Context for measurements describing independent and dependent variables."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable, Units

if TYPE_CHECKING:
    from .dependancies import Axes
    from .typing import (
        MeasurementContext,
        SymbolUnit,
    )


class InterpretationContext(Jsonable):
    """A context that describes measurement variables.

    Contains an Axes of MeasurementContext for independent variables (sweep parameters),
    a list of MeasurementContext for dependent variables (measured parameters),
    and a unit for interpreting the values.
    """

    _independent_variables: "Axes[MeasurementContext]"
    _dependent_variables: list["MeasurementContext"]
    _unit: "SymbolUnit"

    def __init__(
        self,
        independent_variables: "Axes[MeasurementContext]",
        dependent_variables: list["MeasurementContext"],
        unit: "SymbolUnit" = Units.DIMENSIONLESS,
    ):
        """Initialize the InterpretationContext object.

        Args:
            independent_variables: Axes of MeasurementContext representing independent variables
            dependent_variables: List of MeasurementContext representing dependent variables
            unit: Physical unit for interpreting the measurement data (default: dimensionless)
        """
        super().__init__()
        self._independent_variables = independent_variables
        self._dependent_variables = dependent_variables
        self._unit = unit

    @property
    def independent_variables(self) -> "Axes[MeasurementContext]":
        """Return the independent variables."""
        return self._independent_variables

    @property
    def dependent_variables(self) -> list["MeasurementContext"]:
        """Return the dependent variables."""
        return self._dependent_variables

    @property
    def unit(self) -> "SymbolUnit":
        """Return the associated physical unit."""
        return self._unit

    @unit.setter
    def unit(self, unit: "SymbolUnit") -> None:
        """Set the associated physical unit.

        Args:
            unit: The physical unit to associate with this interpretation context
        """
        self._unit = unit

    @property
    def dimension(self) -> int:
        """Return the dimensionality of the measurement (number of independent variables)."""
        return self._independent_variables.dimension

    def add_dependent_variable(self, variable: "MeasurementContext") -> None:
        """Add a dependent variable to the measurement context.

        Args:
            variable: The MeasurementContext to add
        """
        self._dependent_variables.append(variable)

    def replace_dependent_variable(
        self, index: int, variable: "MeasurementContext"
    ) -> None:
        """Replace a dependent variable at the specified index.

        Args:
            index: The index of the variable to replace
            variable: The new MeasurementContext

        Raises:
            IndexError: If the index is out of range
        """
        if index < 0 or index >= len(self._dependent_variables):
            msg = f"Index {index} out of range for dependent variables"
            raise IndexError(msg)
        self._dependent_variables[index] = variable

    def get_independent_variable(self, index: int) -> "MeasurementContext":
        """Get an independent variable by index.

        Args:
            index: The index of the variable

        Returns:
            The MeasurementContext at the specified index

        Raises:
            IndexError: If the index is out of range
        """
        if index < 0 or index >= self.dimension:
            msg = f"Index {index} out of range for independent variables"
            raise IndexError(msg)
        return self._independent_variables[index]

    def with_unit(self, unit: "SymbolUnit") -> "InterpretationContext":
        """Create a new InterpretationContext with the given unit.

        Args:
            unit: The physical unit to use

        Returns:
            A new InterpretationContext with the same variables but different unit
        """
        return InterpretationContext(
            independent_variables=self._independent_variables,
            dependent_variables=self._dependent_variables,
            unit=unit,
        )
