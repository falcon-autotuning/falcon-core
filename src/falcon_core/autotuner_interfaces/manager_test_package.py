"""Package that holds testing information for the Manager."""

from typing import TYPE_CHECKING

from ..data_workers import BasicWorker
from ..dependancies import dataclass
from ..device_interfaces import Gate, Ohmic
from .startup_info import StartupInfo

if TYPE_CHECKING:
    from ..device_interfaces import Gates, Ohmics
    from ..typing import TypeAlias
    from .names import Channel, Channels

worker_package: "TypeAlias" = dict[
    type[BasicWorker],
    dict[
        str | Ohmic | Gate,
        StartupInfo,
    ],
]


@dataclass()
class ManagerTestPackage:
    """Package that holds testing information for the Manager.

    Attributes:
        worker_parameters: Dictionary of worker parameter names and their corresponding values.
        workers: Dictionary of worker names and their corresponding BasicWorker instances.
        global_gates: List of global gates.
        global_ohmics: List of global ohmics.
        current_offset: Dictionary of cha,nnel names and their corresponding current offsets.
        current_channels: List of current channels.
        name: name for the printing of files.
        seed: seed for the random number generator.
    """

    global_gates: "Gates"
    global_ohmics: "Ohmics"
    current_offset: dict["Channel", float]
    current_channels: "Channels"
    name: str
    seed: int
    worker_parameter: worker_package
    """
    comment 1: typing that allows for the spawning of multiple workers of the same type but
        with different parameters. i.e. If we need to spawn two ReservoirPinchoff workers
        with different gates being pinched off and thus different worker parameters.
        the string has to be 'default' if you want to spawn only one worker of that type.
        the Gate has to match up with the favorite gate of the waveform for Worker1Ds
        this is the only operation for a Basic Worker.

    comment 2: typing that allows for the spawning of multi channel workers. Hence enough
        unique data gets generated for each channel.
    """

    def __init__(
        self,
        global_gates: "Gates",
        global_ohmics: "Ohmics",
        current_offset: dict["Channel", float],
        current_channels: "Channels",
        name: str,
        seed: int,
        worker_parameter: worker_package = {},
    ):
        self.global_gates = global_gates
        self.global_ohmics = global_ohmics
        self.current_offset = current_offset
        self.current_channels = current_channels
        self.name = name
        self.seed = seed
        self.worker_parameter = worker_parameter
