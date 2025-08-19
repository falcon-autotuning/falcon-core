"""A datatype that domains used to indicate a three state system."""

from .dependancies import Jsonable


class IncreasingAlignment(Jsonable):
    """A three state system.

    The three states are True, False, and None.

    None implies that there is no trend in the domain.
    """

    def __init__(self, alignment: bool | None = None):
        """Initialize the IncreasingAlignment object.

        Args:
            alignment: The alignment of the domain.
        """
        self._alignment = alignment

    @property
    def alignment(self) -> bool | None:
        """Return the alignment of the domain."""
        return self._alignment

    @alignment.setter
    def alignment(self, alignment: bool | None):
        """Set the alignment of the domain.

        Args:
            alignment: The alignment to set. Can be:
                - True: Domain is increasing
                - False: Domain is decreasing
                - None: No trend in the domain
        """
        self._alignment = alignment
