"""A distinct measurement on a cartesian domain with any time dependant phenomena."""

from typing import TYPE_CHECKING

from .base_waveform import BaseWaveform
from .dependancies import (
    BaseCartesianDiscreteSpace,
    Generic,
    IdentityTransform,
    TypeVar,
)

if TYPE_CHECKING:
    from .typing import Knob, KnobTransform, PortTransform, Self, Sequence

T = TypeVar("T", bound=BaseCartesianDiscreteSpace)


class BaseCartesianWaveform(BaseWaveform, Generic[T]):
    """A distinct measurement on a cartesian domain with any time dependant phenomena."""

    def __init__(
        self,
        space: T,
        transforms: "list[KnobTransform] | Sequence[PortTransform[Knob]]" = [],
    ):
        super().__init__(space, transforms)

    @property
    def space(self) -> T:
        """Return the cartesian space."""
        return self._space

    @classmethod
    def identity_tranform(
        cls,
        space: T,
    ) -> "Self":
        """Create a list of identity transforms for the space."""
        knobs = space.knobs
        return cls(
            space=space,
            transforms=[IdentityTransform(knob=knob, knobs=knobs) for knob in knobs],
        )
