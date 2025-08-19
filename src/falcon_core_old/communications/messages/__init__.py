"""All the different types of requests that can be made to falcon."""

from .measurement_request import (
    MeasurementRequest,
)
from .standard_request import (
    StandardRequest,
)

__all__ = [
    "MeasurementRequest",
    "StandardRequest",
]
