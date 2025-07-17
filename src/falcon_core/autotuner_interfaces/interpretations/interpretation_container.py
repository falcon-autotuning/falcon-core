"""Container for storing values associated with different interpretation contexts."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable, Units

if TYPE_CHECKING:
    from .interpretation_context import InterpretationContext
    from .typing import Any, Connection, Iterator, SymbolUnit


class InterpretationContainer[T](Jsonable):
    """A container for storing values associated with different interpretation contexts.

    This container acts like a dictionary that maps InterpretationContext objects to values
    of a generic type T. All contexts in the container must have the same unit.
    """

    _data: dict["InterpretationContext", T | None]
    _unit: "SymbolUnit | None"

    def __init__(
        self,
        contexts: list["InterpretationContext"] = [],
    ):
        """Initialize the InterpretationContainer.

        Args:
            contexts: Optional list of contexts to initialize the container with (values set to None)

        Raises:
            ValueError: If the contexts have different units
        """
        super().__init__()
        self._data = {}
        self._unit = None

        # Initialize with provided contexts
        if contexts and len(contexts) > 0:
            # Get the unit from the first context
            self._unit = contexts[0].unit

            # Check that all contexts have the same unit
            for context in contexts:
                if context.unit != self._unit:
                    msg = f"All contexts must have the same unit. Expected {self._unit}, got {context.unit}"
                    raise ValueError(msg)
                self.add_context(context)

    @property
    def unit(self) -> "SymbolUnit":
        """Return the unit that all contexts in this container must have."""
        assert self._unit is not None, (
            "The unit cannot be accessed until a context is added."
        )
        return self._unit

    def add_context(
        self, context: "InterpretationContext", value: T | None = None
    ) -> None:
        """Add a context with an optional value.

        Args:
            context: The interpretation context to add
            value: Optional value to associate with the context (default: None)

        Raises:
            ValueError: If the context has a different unit than existing contexts
        """
        # If this is the first context, set the unit
        if self._unit is None:
            self._unit = context.unit
        # Otherwise, check that the unit matches
        elif context.unit != self._unit:
            msg = f"All contexts must have the same unit. Expected {self._unit}, got {context.unit}"
            raise ValueError(msg)

        self._data[context] = value

    def get_contexts(self) -> list["InterpretationContext"]:
        """Get all InterpretationContext objects in this container.

        Returns:
            A list of all interpretation contexts
        """
        return list(self._data.keys())

    def select_by_connection(
        self, connection: "Connection"
    ) -> list["InterpretationContext"]:
        """Select contexts that involve a specific connection.

        Args:
            connection: The connection to search for

        Returns:
            A list of contexts that involve the specified connection in either
            independent or dependent variables
        """
        results = []
        for context in self._data:
            # Check independent variables
            for i in range(context.dimension):
                indep_var = context.get_independent_variable(i)
                if indep_var.connection == connection:
                    results.append(context)
                    continue  # Found in independent variables, no need to check dependents

            # Check dependent variables
            for dep_var in context.dependent_variables:
                if dep_var.connection == connection:
                    results.append(context)
                    break  # Found in dependent variables

        return results

    def select_by_connections(
        self, connections: list["Connection"]
    ) -> list["InterpretationContext"]:
        """Select contexts that involve all of the specified connections.

        Args:
            connections: List of connections to search for

        Returns:
            A list of contexts that involve all specified connections
        """
        # Start with all contexts
        matching_contexts = set(self._data.keys())

        # Filter for each connection
        for connection in connections:
            # Get contexts that match this connection
            contexts_with_connection = set(self.select_by_connection(connection))

            # Keep only contexts that match all connections so far
            matching_contexts &= contexts_with_connection

            # Early exit if no matches
            if not matching_contexts:
                return []

        return list(matching_contexts)

    def select_by_independent_connection(
        self, connection: "Connection"
    ) -> list["InterpretationContext"]:
        """Select contexts that have a specific connection as independent variable.

        Args:
            connection: The connection to search for

        Returns:
            A list of contexts with the specified connection as an independent variable
        """
        results = []
        for context in self._data:
            # Check independent variables
            for i in range(context.dimension):
                indep_var = context.get_independent_variable(i)
                if indep_var.connection == connection:
                    results.append(context)
                    break  # Found in independent variables

        return results

    def select_by_dependent_connection(
        self, connection: "Connection"
    ) -> list["InterpretationContext"]:
        """Select contexts that have a specific connection as dependent variable.

        Args:
            connection: The connection to search for

        Returns:
            A list of contexts with the specified connection as a dependent variable
        """
        results = []
        for context in self._data:
            # Check dependent variables
            for dep_var in context.dependent_variables:
                if dep_var.connection == connection:
                    results.append(context)
                    break  # Found in dependent variables

        return results

    def select_contexts(
        self,
        independent_connections: "list[Connection]| Connection| None" = None,
        dependent_connections: "list[Connection]| Connection| None" = None,
    ) -> list["InterpretationContext"]:
        """Select contexts based on specific independent and/or dependent connections.

        Args:
            independent_connections: Connection(s) to match in independent variables
            dependent_connections: Connection(s) to match in dependent variables

        Returns:
            A list of contexts that match all specified criteria
        """
        # Start with all contexts
        matching_contexts = set(self._data.keys())

        # Process independent connections
        if independent_connections is not None:
            # Convert single connection to list
            if not isinstance(independent_connections, list):
                independent_connections = [independent_connections]

            for connection in independent_connections:
                contexts = set(self.select_by_independent_connection(connection))
                matching_contexts &= contexts

                # Early exit if no matches
                if not matching_contexts:
                    return []

        # Process dependent connections
        if dependent_connections is not None:
            # Convert single connection to list
            if not isinstance(dependent_connections, list):
                dependent_connections = [dependent_connections]

            for connection in dependent_connections:
                contexts = set(self.select_by_dependent_connection(connection))
                matching_contexts &= contexts

                # Early exit if no matches
                if not matching_contexts:
                    return []

        return list(matching_contexts)

    # MutableMapping implementation
    def __getitem__(self, key: "InterpretationContext") -> T | None:
        """Get the value associated with the given context."""
        return self._data[key]

    def __setitem__(self, key: "InterpretationContext", value: T | None) -> None:
        """Set the value associated with the given context.

        Args:
            key: The context to set the value for
            value: The value to store

        Raises:
            ValueError: If the context has a different unit than existing contexts
        """
        # If this is a new context, ensure it has the right unit
        if key not in self._data:
            if self._unit is None:
                self._unit = key.unit
            elif key.unit != self._unit:
                msg = f"All contexts must have the same unit. Expected {self._unit}, got {key.unit}"
                raise ValueError(msg)

        self._data[key] = value

    def __delitem__(self, key: "InterpretationContext") -> None:
        """Remove the context and its associated value from the container."""
        del self._data[key]

        # If we've removed all contexts, reset the unit
        if len(self._data) == 0:
            self._unit = Units.DIMENSIONLESS

    def __iter__(self) -> "Iterator[InterpretationContext]":
        """Return an iterator over the contexts."""
        return iter(self._data)

    def __len__(self) -> int:
        """Return the number of contexts in the container."""
        return len(self._data)

    def items(self):
        """Return a view of (context, value) pairs."""
        return self._data.items()

    def values(self):
        """Return a view of values in the container."""
        return self._data.values()

    def keys(self):
        """Return a view of contexts in the container."""
        return self._data.keys()

    def __eq__(self, other: "Any") -> bool:
        """Check if this container equals another object.

        Args:
            other: The object to compare with

        Returns:
            True if equal, False otherwise
        """
        if not isinstance(other, InterpretationContainer):
            return False

        return self._unit == other._unit and self._data == other._data
