"""Generic types within Falcon Core."""

from .enum import Enum
from .jsonable import Jsonable
from .one_to_one_mapping import OneToOneMapping

__all__ = [
    "Jsonable",
    "Enum",
    "OneToOneMapping",
]
