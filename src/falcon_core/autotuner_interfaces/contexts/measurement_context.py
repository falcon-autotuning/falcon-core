"""Base context that is used to describe measurements without unit information."""

from typing import TYPE_CHECKING

from .base_context import BaseContext

if TYPE_CHECKING:
    from .acquisition_context import AcquisitionContext
    from .typing import Connection, Self


class MeasurementContext(BaseContext):
    """A measurement context that describes measurements without unit information.

    This class captures the connection and instrument type aspects of a measurement
    but does not include unit information. The AcquisitionContext subclass
    adds unit handling functionality.
    """

    _connection: "Connection | None"
    _instrument_type: str

    def __init__(
        self,
        connection: "Connection | None",
        instrument_type: str,
    ):
        """Initialize the MeasurementContext object.

        Args:
            connection: The connection associated with the measurement
            instrument_type: The type of instrument used for the measurement
        """
        super().__init__(
            connection=connection,
            instrument_type=instrument_type,
        )

    @classmethod
    def from_aquisition_context(
        cls,
        acquisition_context: "AcquisitionContext",
    ) -> "Self":
        """Create a MeasurementContext from an AcquisitionContext.

        Args:
            acquisition_context: The acquisition context.

        Returns:
            The MeasurementContext object.
        """
        return cls(
            connection=acquisition_context.connection,
            instrument_type=acquisition_context.instrument_type,
        )
