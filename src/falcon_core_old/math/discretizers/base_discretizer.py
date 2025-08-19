"""The base discretizer class."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .dependancies import Domain


class BaseDiscretizer(Jsonable):
    """The base discritzer class that holds the discretization method.

    Attributes:
        _delta: The discretization step.
        _delta_domain: The domain of the discretizer.
    """

    _delta: float
    _delta_domain: "Domain"

    def __init__(self, delta: float, domain: "Domain"):
        """Initialize the BaseDiscretizer object.

        The delta must be within the domain.
        """
        self._delta_domain = domain
        self.delta = delta

    @property
    def delta(self) -> float:
        """Return the discretization step."""
        return self._delta

    @delta.setter
    def delta(self, delta: float):
        """Set the discretization step.

        Args:
            delta: The discretization step.

        Raises:
            ValueError: If the discretization step is not within the domain.
        """
        if delta in self.domain:
            self._delta = delta
        else:
            msg = "The discretization step should be within the domain."
            raise ValueError(msg)

    @property
    def domain(self) -> "Domain":
        """Return the domain of the discretizer."""
        return self._delta_domain
