"""Dependencies for the Falcon Core generics."""

from ..dependancies import (
    b64decode,
    b64encode,
    deepcopy,
    dill,
    json,
    np,
    pickle,
    sys,
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
]
