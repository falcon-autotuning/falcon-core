"""A base class for all contexts."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .typing import Connection, Instrument, InstrumentPort, Self


class BaseContext(Jsonable):
    """A base class for all measurement contexts.

    This class provides common functionality for contexts, capturing
    the connection and instrument type aspects of a measurement
    without unit information.
    """

    _connection: "Connection | None"
    _instrument_type: "Instrument"

    def __init__(
        self,
        connection: "Connection | None",
        instrument_type: "Instrument",
    ):
        """Initialize the BaseContext object.

        Args:
            connection: The connection associated with the measurement
            instrument_type: The type of instrument used for the measurement
        """
        super().__init__()
        self._connection = connection
        self._instrument_type = instrument_type

    @property
    def connection(self) -> "Connection | None":
        """Return the connection."""
        assert self._connection is not None, (
            "Connection is None, Tried to invoke invalid comparison."
        )
        return self._connection

    @property
    def instrument_type(self) -> "Instrument":
        """Return the instrument type."""
        return self._instrument_type

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
        )

    def __eq__(self, other):
        """Return True if the contexts are equal."""
        if not isinstance(other, BaseContext):
            return False
        return (
            self._connection == other._connection
            and self._instrument_type == other._instrument_type
        )

    def __hash__(self):
        """Return the hash of the context."""
        return hash((self._connection, self._instrument_type))
