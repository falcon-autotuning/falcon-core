"""Typing definitions for Falcon communications module."""

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from ..typing import TypeAlias

Channel: "TypeAlias" = str

ApplicationName: "TypeAlias" = str
