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

arrayND: TypeAlias = npt.NDArray[np.float64]  # ND array of float64
array1D: TypeAlias = arrayND  # 1D array of float64
array2D: TypeAlias = arrayND  # 2D array of float64
array3D: TypeAlias = arrayND  # 3D array of float64
arrays: TypeAlias = arrayND | array1D | array2D | array3D  # Any array type

JSONprimitivesWithoutNone: TypeAlias = str | int | float | bool
JSONprimitives: TypeAlias = JSONprimitivesWithoutNone | None
JsonableAttributeName: "TypeAlias" = str

analytic_function: TypeAlias = Callable[..., float]

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
