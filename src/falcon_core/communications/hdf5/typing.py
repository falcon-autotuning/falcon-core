"""Typing definitions for Falcon communications module."""

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from ..typing import TypeAlias

from pathlib import Path

from ...math.arrays.control_array import ControlArray
from ...math.domains import CoupledKnobDomain
from ...math.labelled_arrays.labelled_measured_arrays import (
    LabelledMeasuredArrays,
)
from ...typing import arrayND

Dimension: "TypeAlias" = int
DimensionIndex: "TypeAlias" = str
ConnectionName: "TypeAlias" = str
Data: "TypeAlias" = str
AxisLabel: "TypeAlias" = str
Unit: "TypeAlias" = str
AxisMetadata: "TypeAlias" = dict[str, Unit | int]
AxisLabels: "TypeAlias" = dict[AxisLabel, AxisMetadata]
Domain: "TypeAlias" = dict[str, Data | AxisLabels]
Range: "TypeAlias" = dict[str, Data | Unit]
Ranges: "TypeAlias" = dict[AxisLabel, Range]
Domains: "TypeAlias" = dict[DimensionIndex, Domain]
Dimensions: "TypeAlias" = dict[DimensionIndex, Dimension]
Metadata: "TypeAlias" = dict[str, str]

__all__ = [
    "ControlArray",
    "CoupledKnobDomain",
    "LabelledMeasuredArrays",
    "Path",
    "arrayND",
]
