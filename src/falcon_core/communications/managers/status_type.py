"""Different allows types of operations for the context manager."""

from .dependancies import Enum


class ProgramStatusType(Enum):
    """Defines the type of operation to perform with the context manager."""

    STARTED = "started"
    RUNNING = "running"
    STOPPED = "stopped"
    PAUSED = "paused"


class ChannelStatusType(Enum):
    """Defines the type of operation to perform with the context manager."""

    FINISHED = "finished"  # TODO: finish this thought
    BUSY = "busy"
    IDLE = "idle"
