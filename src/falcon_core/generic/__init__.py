"""Generic types within Falcon Core."""

from .jsonable import Jsonable
from .one_to_one_mapping import OneToOneMapping
from .enum import Enum

__all__ = [
    "Jsonable",
    "Enum",
    "OneToOneMapping",
]
