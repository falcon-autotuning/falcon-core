"""A template for compiling a unit space."""

from typing import TYPE_CHECKING

from .constants import PI
from .dependancies import (
    Axes,
    BaseArray,
    CartesianDiscretizer,
    ControlArray,
    ControlArray1D,
    Domain,
    Jsonable,
    PolarDiscretizer,
    itertools,
    np,
)

if TYPE_CHECKING:
    from .typing import BaseDiscretizer


class UnitSpace(Jsonable):
    """A unit space.

    A unit space is a hypercube of measurement space.
    It is defined by a set of axes, each of which can be discretized.

    This unitspace can be compiled and packed into the space when necessary.
    """

    _axes: "Axes[BaseDiscretizer]"
    _domain: Domain
    _ranges: "Axes[ControlArray1D]"
    _space: "BaseArray"
    _shape: list[int]

    def __init__(
        self,
        axes: "Axes[BaseDiscretizer]",
        domain: Domain = Domain(bounds=(0, 1), greater_bound_contained=False),
    ):
        """Initialize the UnitSpaceTemplate object."""
        self._axes = axes
        self._domain = domain
        self._make_discrete_axes()
        self.compute_shape()

    @property
    def axes(self) -> "Axes[BaseDiscretizer]":
        """Return the axes."""
        return self._axes

    @property
    def domain(self) -> Domain:
        """Return the domain."""
        return self._domain

    @property
    def space(self) -> "BaseArray":
        """Returns the stored space."""
        return self._space

    @property
    def shape(self) -> tuple[int, ...]:
        """Return the shape of the unit space."""
        return tuple(self._shape)

    def __getitem__(self, index: int) -> "BaseDiscretizer":
        """Return the axis at the given index."""
        return self._axes[index]

    def __len__(self) -> int:
        """Return the number of axes."""
        return len(self._axes)

    def __iter__(self):
        """Return an iterator over the axes."""
        return iter(self._axes)

    def _make_discrete_axes(self):
        """Return the axes as discrete.

        The axes are discretized into a set of ranges.

        Raises:
            ValueError: If the discretizer is not supported
        """
        ranges = []
        for discretizer in self:
            if isinstance(discretizer, CartesianDiscretizer):
                factor = 1
            elif isinstance(discretizer, PolarDiscretizer):
                factor = PI / 2
            else:
                msg = f"Discretizer {discretizer} not supported."
                raise ValueError(msg)
            domain = self.domain.scale(factor=factor).intersect(discretizer.domain)
            bounds = domain.bounds
            delta = discretizer.delta
            lower_bound = (
                bounds[0] + delta if not domain.lesser_bound_contained else bounds[0]
            )
            upper_bound = (
                bounds[1] + delta if domain.greater_bound_contained else bounds[1]
            )
            ranges.append(
                ControlArray1D(
                    np.arange(start=lower_bound, stop=upper_bound, step=delta)
                )
            )
        self._ranges = Axes(ranges)

    def compute_shape(self):
        """Compute the shape of the unit space."""
        self._shape = [len(array) for array in self._ranges]

    def compile(self):
        """Compile the unit space into a space."""
        space = np.array(list(itertools.product(*list(self._ranges)[::-1])))
        self._space = BaseArray(space[:, ::-1])

    @property
    def dimension(self):
        """Return the number of dimensions."""
        return len(self)

    def create_array(
        self,
        axes: "Axes[int]",
    ) -> "Axes[ControlArray]":
        """Return the projection of the space onto the given axes.

        The projection contains the indexes of the axes to project onto.

        Args:
            axes: The axes to project onto.
        """
        if axes.dimension == 1:
            return Axes([self._ranges[0]])
        return Axes(
            [
                ControlArray(data=array)
                for array in np.meshgrid(
                    *[self._ranges[i]._data for i in axes],
                    indexing="ij",
                )
            ]
        )
