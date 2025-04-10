"""Package that holds testing information for the Manager."""

from typing import TYPE_CHECKING

from ..dependancies import dataclass

if TYPE_CHECKING:
    from ..device_interfaces import BaseConnection, Gates, Ohmics
    from ..drivers import ChannelData2D
    from ..drivers.measured_data_1D import MeasuredData1D
    from ..typing import Any, Callable, Mapping, array1D
    from .names.channel import Channel


@dataclass
class BasicWorkerTestPackage:
    """Package that holds testing information for the Worker.

    Attributes:
        data: Dictionary of channel names and their corresponding ChannelData1D instances.
        global_gates: List of global gates.
        global_ohmics: List of global ohmics.
        name: name for the printing of files.
    """

    data: "Any"
    global_gates: "Gates"
    global_ohmics: "Ohmics"


@dataclass
class WorkerTestPackage(BasicWorkerTestPackage):
    """Package that holds testing information for the Worker.

    Attributes:
        data: Dictionary of channel names and their corresponding ChannelData1D instances.
        global_gates: List of global gates.
        global_ohmics: List of global ohmics.
        name: name for the printing of files.
    """

    data: "Mapping[Channel, Callable[[BaseConnection, array1D], MeasuredData1D]]"


@dataclass
class WorkerTestPackage2D(BasicWorkerTestPackage):
    """Package that holds testing information for the Worker.

    Attributes:
        data: Dictionary of channel names and their corresponding ChannelData1D instances.
        global_gates: List of global gates.
        global_ohmics: List of global ohmics.
        name: name for the printing of files.
    """

    data: "Mapping[Channel, Callable[[BaseConnection, BaseConnection, array1D, array1D], ChannelData2D]]"
