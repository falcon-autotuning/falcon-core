"""Many transfromations for port objects to analytic time domain functions."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .dependancies import InstrumentPort
    from .port_transform import PortTransform


class PortTransforms(Jsonable):
    """Many transfromations for port objects to analytic time domain functions."""

    _transforms: "list[PortTransform]"

    def __init__(
        self,
        transforms: "list[PortTransform]",
    ):
        """Initialize the PortTransform object."""
        self._transforms = transforms

    @property
    def transforms(self) -> "list[PortTransform]":
        """Return the port."""
        return [transform for transform in self._transforms]

    def __getitem__(
        self,
        port: "InstrumentPort",
    ) -> "PortTransform":
        """Return the port.

        Args:
            port: The port to search for.

        Returns:
            The port with the given port.

        Raises:
            ValueError: If the port is not found.
        """
        for transform in self._transforms:
            if transform.port == port:
                return transform
        msg = f"Port {port} not found in transforms."
        raise ValueError(msg)

    def __len__(self) -> int:
        """Return the port."""
        return len(self._transforms)

    def __iter__(self):
        """Return the port."""
        return iter(self._transforms)
