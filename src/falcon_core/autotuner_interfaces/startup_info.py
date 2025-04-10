"""Allows seeds to be specified for testing after compiling all information."""

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from ..device_interfaces import BaseConnection
    from ..packaging.testing import AbstractGeneratedData
    from ..typing import Any, Mapping
    from .names import Channel, Channels


class StartupInfo:
    """Holds startup information for all Abstract1D workers.

    Allows seeds to be passed in at runtime.
    """

    values: "Any"
    _generator: type["AbstractGeneratedData"] | None
    _channels: "Channels | None"
    _kwargs: "Mapping[str, Mapping[Channel | BaseConnection | str, float | str | int]] | None"
    _seed: int | None

    def __init__(
        self,
        generator: type["AbstractGeneratedData"] | None = None,
        seed: int | None = None,
        channels: "Channels | None" = None,
        kwargs: "Mapping[str, Mapping[Channel | BaseConnection | str, float | str | int]] | None" = None,
    ):
        """Initializes a StartupInfo1D object.

        Args:
            seed (int): The seed.
            generator (type[AbstractGeneratedData1D]): The generator.
            channels (list[Channel]): The channels.
            kwargs (Mapping[str, Mapping[Channel | Gate | Ohmic | str, float | str | int]]): The kwargs.
        """
        self._generator = generator
        self._channels = channels
        self._kwargs = kwargs
        self._seed = seed

        if any(
            attribute is None
            for attribute in [
                self._generator,
                self._channels,
                self._kwargs,
                seed,
            ]
        ):
            self.values = {}
            return
        assert self._seed is not None
        self.values = {}
        self.__call__(seed=self._seed)

    def __call__(
        self,
        seed: int,
    ) -> "Any":
        """Generates the values."""
        if any(
            attribute is None
            for attribute in [
                self._generator,
                self._channels,
                self._kwargs,
            ]
        ):
            msg = f"""All of generator, channels, kwargs must be specified
                 when using the {self.__class__.__name__} class."""
            raise ValueError(msg)
        return self.values

    def getStartupInfo(
        self,
    ) -> "Any":
        """Returns the values."""
        return self.values
