"""A collection of coupled knob domains to be attached together."""

from typing import TYPE_CHECKING

from .base_coupled_labelled_domain import BaseCoupledLabelledDomain
from .dependancies import Jsonable, Knob, Knobs, cast
from .labelled_domain import LabelledDomain
from .typing import Sequence

if TYPE_CHECKING:
    from .knob_domain import KnobDomain


class CoupledKnobDomain(BaseCoupledLabelledDomain[Knob], Jsonable):
    """A collection of coupled knob domains to be attached together."""

    def __init__(self, domains: list["KnobDomain"]):
        """Initialize the CoupledKnobDomain object."""
        labelled_domains = cast(Sequence[LabelledDomain[Knob]], domains)
        super().__init__(domains=labelled_domains)

    @property
    def knobs(self) -> "Knobs":
        """Return the knobs."""
        return Knobs(self.labels)
