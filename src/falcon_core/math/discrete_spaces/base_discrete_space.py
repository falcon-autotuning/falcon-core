"""A discrete space can fill an entire domain with a set of discrete values."""

from typing import TYPE_CHECKING

from .dependancies import (
    Axes,
    Jsonable,
    LabelledControlArray,
)
from .typing import (
    ControlArray,
    Knob,
)

if TYPE_CHECKING:
    from .dependancies import Domain
    from .typing import (
        CoupledKnobDomain,
        UnitSpace,
    )


class BaseDiscreteSpace(Jsonable):
    """A discrete space can fill an entire domain with a set of discrete values."""

    _space: "UnitSpace"
    _axes: "Axes[CoupledKnobDomain]"

    def __init__(
        self,
        space: "UnitSpace",
        axes: "Axes[CoupledKnobDomain]",
    ):
        """Initialize the DiscreteSpace object.

        The order of the Knobs in the axes are defined to line up with the space.

        Args:
            space: the space that the discrete values fill.
            axes: the axes of the discrete values.
        """
        self._space = space
        self._axes = axes
        self.validate_unit_space_dimensionality_matches_knobs()
        self.validate_knob_uniqueness()

    def validate_unit_space_dimensionality_matches_knobs(self):
        """Validate that the unit space dimensionality matches the knobs."""
        assert self._space.dimension == self._axes.dimension, (
            "The unit space dimensionality must match the knobs."
        )

    def validate_knob_uniqueness(self):
        """Validate that the knobs are unique."""
        old_names = set()
        for axis in self._axes:
            new_names = set(axis.knobs.get_default_names())
            assert new_names.isdisjoint(old_names), "The default names must be unique."
            old_names.update(new_names)

    def get_axis(
        self,
        knob: "Knob",
    ) -> int:
        """Return the index of the axis containing the given knob.

        Args:
            knob: The knob to search for.

        Returns:
            The index of the axis containing the given knob.

        Raises:
            ValueError: If the knob is not found.
        """
        for axis in self._axes:
            if knob in axis.knobs:
                return self._axes.index(axis)
        msg = f"Knob {knob} not found in the axes."
        raise ValueError(msg)

    def get_domain(
        self,
        knob: "Knob",
    ) -> "Domain":
        """Return the domain of the given knob.

        Args:
            knob: The knob to search for.

        Returns:
            The domain of the given knob.
        """
        axis = self.get_axis(knob=knob)
        coupled_domain = self._axes[axis]
        return coupled_domain.get_domain(search=knob)

    def get_projection(
        self,
        projection: "Axes[Knob]",
    ) -> "Axes[LabelledControlArray]":
        """Return the projection of the space onto the given axes.

        Args:
            projection: The axes to project onto.

        Returns:
            The projection of the space onto the given axes.
        """
        assert projection.dimension == self._space.dimension, (
            "The projection dimensionality must be less than or equal to the space dimensionality."
        )
        projection_axes = Axes([self.get_axis(knob=knob) for knob in projection])

        assert projection.dimension == len(set(projection_axes.axes)), (
            "The projection axes must be unique."
        )
        unitprojections = self._space.create_array(axes=projection_axes)

        scaled_projections: list[ControlArray] = []
        for unitprojection, knob in zip(unitprojections, projection):
            assert isinstance(unitprojection, ControlArray), (
                f"Expected the type of each unit projection to be Control Array, but it was {type(unitprojection)}"
            )
            assert isinstance(knob, Knob), (
                f"Expected the type of the the knob to be a Knob, but it was {type(knob)}"
            )
            domain = self.get_domain(knob=knob)
            difference = domain.range
            min_value = domain.lesser_bound
            scaled_projections.append(unitprojection * difference + min_value)

        return Axes(
            [
                LabelledControlArray.from_port(array=proj.data, port=knob)
                for proj, knob in zip(scaled_projections, projection)
            ]
        )
