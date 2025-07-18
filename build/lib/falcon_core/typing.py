"""ALl of the various typings required by Falcon."""

from collections.abc import (
    Callable,
    Iterable,
    Iterator,
    Mapping,
    Sequence,
)
from types import GenericAlias
from typing import (
    Any,
    ClassVar,
    Generic,
    Literal,
    Protocol,
    Self,
    TypeAlias,
    TypeVar,
    cast,
    get_args,
    get_origin,
    runtime_checkable,
)

import numpy.typing as npt

from .dependancies import np

type arrayND = npt.NDArray[np.float64]  # ND array of float64
type array1D = arrayND  # 1D array of float64
type array2D = arrayND  # 2D array of float64
type array3D = arrayND  # 3D array of float64
type arrays = arrayND | array1D | array2D | array3D  # Any array type

type JSONprimitivesWithoutNone = str | int | float | bool
type JSONprimitives = JSONprimitivesWithoutNone | None
type JsonableAttributeName = str
type Instrument = str
type analytic_function = Callable[..., float]

__all__ = [
    "Any",
    "GenericAlias",
    "Protocol",
    "runtime_checkable",
    "Iterable",
    "Self",
    "get_origin",
    "get_args",
    "cast",
    "TypeAlias",
    "Sequence",
    "TypeVar",
    "ClassVar",
    "Generic",
    "npt",
    "Callable",
    "Mapping",
    "array1D",
    "JSONprimitives",
    "JSONprimitivesWithoutNone",
    "Iterator",
    "Literal",
]
