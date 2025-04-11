"""Represents fundamental physical dimensions."""

from .constants import (
    ALL_DIMENSIONS,
    DIMENSION_AMOUNT,
    DIMENSION_CURRENT,
    DIMENSION_LENGTH,
    DIMENSION_LUMINOSITY,
    DIMENSION_MASS,
    DIMENSION_TEMPERATURE,
    DIMENSION_TIME,
)


class Dimension:
    """Base SI physical dimensions."""

    # Import the 7 base SI dimensions from constants
    LENGTH = DIMENSION_LENGTH
    MASS = DIMENSION_MASS
    TIME = DIMENSION_TIME
    CURRENT = DIMENSION_CURRENT
    TEMPERATURE = DIMENSION_TEMPERATURE
    AMOUNT = DIMENSION_AMOUNT
    LUMINOSITY = DIMENSION_LUMINOSITY

    # Keep track of all valid dimensions
    _ALL_DIMENSIONS = ALL_DIMENSIONS

    @classmethod
    def is_valid(cls, dimension: str) -> bool:
        """Check if a dimension is valid.

        Args:
            dimension: The dimension to check.

        Returns:
            True if the dimension is valid.
        """
        return dimension in cls._ALL_DIMENSIONS

    def __repr__(self) -> str:
        """Return a concise representation."""
        return f"Dimension.{self}"


# Helper functions for serialization/deserialization
def validate_dimensions(dimensions: dict[str, int]) -> dict[str, int]:
    """Validate a dictionary of dimensions.

    Args:
        dimensions: The dimensions to validate.

    Returns:
        The validated dimensions.

    Raises:
        ValueError: If any dimension is invalid.
    """
    for dim in dimensions:
        if not Dimension.is_valid(dim):
            msg = f"Invalid dimension: {dim}"
            raise ValueError(msg)
    return dimensions
