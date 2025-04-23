"""Dependencies for the Falcon Core generics."""

from ..dependancies import (
    b64decode,
    StandardEnum,
    b64encode,
    deepcopy,
    dill,
    json,
    np,
    pickle,
    sys,
    untyped_uniform_filter1d,
)
from ..typing import (
    Generic,
    GenericAlias,
    JSONprimitives,
    TypeVar,
    get_args,
    get_origin,
)

__all__ = [
    "b64decode",
    "b64encode",
    "StandardEnum",
    "deepcopy",
    "dill",
    "json",
    "np",
    "pickle",
    "sys",
    "GenericAlias",
    "JSONprimitives",
    "get_args",
    "get_origin",
    "Generic",
    "TypeVar",
    "untyped_uniform_filter1d",
]
