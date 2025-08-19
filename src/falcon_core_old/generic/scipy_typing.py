"""Fixes typing for scipy functions."""

from typing import TYPE_CHECKING

from .dependancies import untyped_uniform_filter1d

if TYPE_CHECKING:
    from .typing import array1D


def uniform_filter1d(
    input: "array1D",
    size: int,
    axis: int = -1,
    output: "array1D | None" = None,
    mode: str = "reflect",
    cval: float = 0,
    origin: int = 0,
) -> "array1D":
    """Apply a 1D uniform filter along the given axis.

    Wraps the scipy implementation of uniform_filter1d to fix typing.
    """
    filtered_output: array1D = untyped_uniform_filter1d(
        input=input,
        size=size,
        axis=axis,
        output=output,
        mode=mode,
        cval=cval,
        origin=origin,
    )  # type: ignore  # noqa: PGH003
    return filtered_output
