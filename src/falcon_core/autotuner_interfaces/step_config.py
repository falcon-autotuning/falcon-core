"""Inputs to managers from within the input config file."""

from typing import TYPE_CHECKING

from ..dependancies import dataclass

if TYPE_CHECKING:
    from ..typing import Any


@dataclass(frozen=True)
class StepConfig:
    """Dictionary that contains the step_config."""

    values: dict[str, "Any"]
