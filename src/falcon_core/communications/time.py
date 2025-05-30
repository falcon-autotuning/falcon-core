"""Our timing module so everyone knows what time it is."""

import math
import time


class Time:
    """An object that represents the current time for falcon needs."""

    _micro_seconds_since_epoch: int

    def __init__(self, micro_seconds_since_epoch: int | None = None):
        """Initialize the Time object with the current time or a specific time."""
        if micro_seconds_since_epoch is None:
            self._micro_seconds_since_epoch = math.floor(time.time() * 1_000_000)
        else:
            self._micro_seconds_since_epoch = micro_seconds_since_epoch

    @property
    def micro_seconds_since_epoch(self) -> int:
        """Get the time in microseconds since the epoch."""
        return self._micro_seconds_since_epoch

    @property
    def time(self) -> int:
        """Get the time in microseconds since the epoch."""
        return self._micro_seconds_since_epoch

    def __str__(self) -> str:
        """Converts the time to a string."""
        return time.strftime(
            "%Y-%m-%d %H:%M:%S",
            time.localtime(self._micro_seconds_since_epoch / 1000000),
        )
