"""This module contains the RaySpace class."""

from .dependancies import Axes, CartesianDiscretizer, Domain, Jsonable, PolarDiscretizer
from .unit_space import UnitSpace


class RaySpace(UnitSpace, Jsonable):
    """A Ray space.

    A Ray space is a unit space with a single axis and a polar axis.
    """

    def __init__(
        self,
        dr: float,
        dtheta: float,
        domain=Domain(bounds=(0, 1), greater_bound_contained=False),
    ):
        """Initialize the RaySpace object.

        Args:
            dr (float): The delta for the radial axis.
            dtheta (float): The delta for the angular axis.
            domain (Domain, optional): The domain of the space. Defaults to Domain(bounds=(0, 1), greater_bound_contained=False).
        """
        super().__init__(
            axes=Axes([CartesianDiscretizer(delta=dr), PolarDiscretizer(delta=dtheta)]),
            domain=domain,
        )
