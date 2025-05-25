"""A domain for a float to fall in a range."""

from .dependancies import Jsonable


class Domain(Jsonable):
    """Bounds float to a range."""

    _lesser_bound: float
    _greater_bound: float
    _lesser_bound_contained: bool
    _greater_bound_contained: bool

    def __init__(
        self,
        bounds: tuple[float, float],
        lesser_bound_contained: bool = True,
        greater_bound_contained: bool = True,
    ):
        """Initialize the Domain object."""
        self._lesser_bound = min(list(bounds))
        self._greater_bound = max(list(bounds))
        self._lesser_bound_contained = lesser_bound_contained
        self._greater_bound_contained = greater_bound_contained

    @property
    def lesser_bound(self) -> float:
        """Return the lesser bound value."""
        return self._lesser_bound

    @property
    def greater_bound(self) -> float:
        """Return the greater bound value."""
        return self._greater_bound

    @property
    def bounds(self) -> tuple[float, float]:
        """Return the bounds of the domain."""
        return (self.lesser_bound, self.greater_bound)

    @property
    def lesser_bound_contained(self) -> bool:
        """Return whether the lesser bound is contained in the domain."""
        return self._lesser_bound_contained

    @property
    def greater_bound_contained(self) -> bool:
        """Return whether the greater bound is contained in the domain."""
        return self._greater_bound_contained

    def __contains__(self, value: float) -> bool:
        """Check if the value is in the domain.

        Args:
            value: The value to check if it is in the domain.

        Returns:
            True if the value is in the domain, False otherwise.
        """
        left_check = (
            value >= self.lesser_bound
            if self.lesser_bound_contained
            else value > self.lesser_bound
        )
        right_check = (
            value <= self.greater_bound
            if self.greater_bound_contained
            else value < self.greater_bound
        )
        return left_check and right_check

    @property
    def range(self) -> float:
        """Return the size of the domain range."""
        return self.greater_bound - self.lesser_bound

    def get_center(self) -> float:
        """Return the center value of the domain."""
        return (self.lesser_bound + self.greater_bound) / 2

    def intersect(self, other: "Domain") -> "Domain":
        """Return a new domain that is the intersection of this domain and the other domain.

        Raises:
            ValueError: If the domains don't overlap.
        """
        new_lesser = max(self.lesser_bound, other.lesser_bound)
        new_greater = min(self.greater_bound, other.greater_bound)

        # Check if the domains overlap
        if new_lesser > new_greater:
            msg = "The domains do not overlap."
            raise ValueError(msg)

        new_lesser_contained = self.lesser_bound != other.lesser_bound or (
            self.lesser_bound_contained and other.lesser_bound_contained
        )

        new_greater_contained = self.greater_bound != other.greater_bound or (
            self.greater_bound_contained and other.greater_bound_contained
        )

        return Domain(
            bounds=(new_lesser, new_greater),
            lesser_bound_contained=new_lesser_contained,
            greater_bound_contained=new_greater_contained,
        )

    def union(self, other: "Domain") -> "Domain":
        """Return a new domain that is the union of this domain and the other domain."""
        # Check if the domains can be united (they overlap or touch)
        self.intersect(other=other)

        new_lesser = min(self.lesser_bound, other.lesser_bound)
        new_greater = max(self.greater_bound, other.greater_bound)

        new_lesser_contained = (
            self.lesser_bound_contained
            if new_lesser == self.lesser_bound
            else other.lesser_bound_contained
        )

        new_greater_contained = (
            self.greater_bound_contained
            if new_greater == self.greater_bound
            else other.greater_bound_contained
        )

        return Domain(
            bounds=(new_lesser, new_greater),
            lesser_bound_contained=new_lesser_contained,
            greater_bound_contained=new_greater_contained,
        )

    def is_empty(self) -> bool:
        """Return whether the domain is empty."""
        return (
            self.lesser_bound == self.greater_bound and not self.lesser_bound_contained
        )

    def contains_domain(
        self,
        other: "Domain",
    ) -> bool:
        """Returns if this domain completely contains another domain."""
        return self.union(other=other) == self

    def shift(
        self,
        offset: float,
    ) -> "Domain":
        """Return a new domain shifted by the given offset."""
        bounds = (
            self.lesser_bound + offset,
            self.greater_bound + offset,
        )
        return Domain(
            bounds=bounds,
            lesser_bound_contained=self.lesser_bound_contained,
            greater_bound_contained=self.greater_bound_contained,
        )

    def scale(
        self,
        factor: float,
    ) -> "Domain":
        """Return a new domain scaled by the given factor around the center."""
        center = self.get_center()
        half_range = self.range / 2
        new_half_range = half_range * factor

        bounds = (
            center - new_half_range,
            center + new_half_range,
        )
        return Domain(
            bounds=bounds,
            lesser_bound_contained=self.lesser_bound_contained,
            greater_bound_contained=self.greater_bound_contained,
        )

    def calculate_transform(
        self,
        other: "Domain",
    ) -> tuple[float, float]:
        """Calculate the transform from this domain to another domain.

        Args:
            other: The other domain to transform to.

        Returns:
            the first value is the scale factor and the second value is the offset.
        """
        scale = self.range / other.range
        offset = other.lesser_bound - self.lesser_bound * scale
        return scale, offset

    def transform(self, value: float, other: "Domain") -> float:
        """Transform a value from this domain to another domain.

        Args:
            value: The value to transform.
            other: The other domain to transform to.

        Returns:
            The transformed value in the other domain.
        """
        assert value in self, "Value must be in the current domain."
        scale, offset = self.calculate_transform(other=other)
        return value * scale + offset
