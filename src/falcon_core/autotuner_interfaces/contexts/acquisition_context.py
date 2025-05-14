"""A context that is used to describe the acquisition of data with units."""

from typing import TYPE_CHECKING

from .dependancies import BaseContext, Jsonable, SymbolUnit, Units
from .typing import Connection, Instrument

if TYPE_CHECKING:
    from .typing import InstrumentPort, Self


class AcquisitionContext(BaseContext, Jsonable):
    """A context that describes data acquisition with unit information.

    This class extends BaseContext by adding unit information,
    allowing for complete specification of measurements with physical units.
    """

    _units: SymbolUnit

    def __init__(
        self,
        connection: Connection | None,
        instrument_type: "Instrument",
        units: SymbolUnit,
    ):
        """Initialize the AcquisitionContext object.

        Args:
            connection: The connection associated with the measurement
            instrument_type: The type of instrument used for the measurement
            units: The physical units for the measurements
        """
        super().__init__(connection=connection, instrument_type=instrument_type)
        self._units = units

    @property
    def units(self) -> SymbolUnit:
        """Return the units."""
        return self._units

    @classmethod
    def from_instrument_port(cls, port: "InstrumentPort") -> "Self":
        """Create an AcquisitionContext from an InstrumentPort.

        Args:
            port: The instrument port.

        Returns:
            The AcquisitionContext object.
        """
        return cls(
            connection=port.pseudo_name,
            instrument_type=port.instrument_type,
            units=port.units,
        )

    @classmethod
    def from_measurement_context(
        cls,
        measurement_context: "BaseContext",
        unit: SymbolUnit = Units.DIMENSIONLESS,
    ) -> "Self":
        """Create an AcquisitionContext from a MeasurementContext.

        Args:
            measurement_context: The measurement context.
            unit: The unit to use for the measurement context.

        Returns:
            The AcquisitionContext object.
        """
        return cls(
            connection=measurement_context.connection,
            instrument_type=measurement_context.instrument_type,
            units=unit,
        )

    def __truediv__(self, other: object) -> "AcquisitionContext":
        """Divide the units.

        The context on top keeps all other details.

        Args:
            other: The object to divide by.

        Returns:
            The divided context.

        Raises:
            TypeError: If the other object is not an AcquisitionContext or a SymbolUnit.
        """
        if not isinstance(other, SymbolUnit | AcquisitionContext):
            msg = f"unsupported operand type(s) for /: 'AcquisitionContext' and '{type(other)}'"
            raise TypeError(msg)
        if isinstance(other, SymbolUnit):
            return AcquisitionContext(
                connection=self.connection,
                instrument_type=self.instrument_type,
                units=self.units / other,
            )
        return AcquisitionContext(
            connection=self.connection,
            instrument_type=self.instrument_type,
            units=self.units / other.units,
        )

    def __eq__(self, other):
        """Return True if the contexts are equal."""
        if not isinstance(other, AcquisitionContext):
            return False
        return super().__eq__(other) and self._units == other._units

    def match_connection(self, other: Connection) -> bool:
        """Returns if the connection is inside this context."""
        return self.connection == other

    def match_instrument_type(self, other: "Instrument") -> bool:
        """Returns if the instrument type is inside this context."""
        return self.instrument_type == other

    def match_raw_arg(self, other: "Connection | Instrument") -> bool:
        """Returns if the raw argument is inside this context."""
        if isinstance(other, Connection):
            return self.match_connection(other)
        assert isinstance(other, Instrument)
        return self.match_instrument_type(other)

    def __hash__(self):
        return super().__hash__()
