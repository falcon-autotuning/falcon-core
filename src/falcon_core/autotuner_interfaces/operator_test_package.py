"""Package that holds testing information for the Operator."""

import warnings
from typing import TYPE_CHECKING

from .manager_test_package import (
    ManagerTestPackage,
)

if TYPE_CHECKING:
    from ..device_interfaces import Gates, Ohmics
    from .manager_test_package import worker_package
    from .names.channel import Channel, Channels
    from .names.manager_name import ManagerName


class SeedlessManagerTestPackage:
    """Holds all of the parameters for a test case of a manager.

    Does not contain a seed.
    """

    def __init__(
        self,
        global_gates: "Gates",
        global_ohmics: "Ohmics",
        current_offset: dict["Channel", float],
        current_channels: "Channels",
        name: str,
        worker_parameter: "worker_package" = {},
    ) -> None:
        """Initializes the manager test package without a seed."""
        self.global_gates = global_gates
        self.global_ohmics = global_ohmics
        self.current_offset = current_offset
        self.current_channels = current_channels
        self.name = name
        self.worker_package = worker_parameter

    def __call__(self, seed: int):
        """Used to launch a Manager Test Package using a seed."""
        return ManagerTestPackage(
            global_gates=self.global_gates,
            global_ohmics=self.global_ohmics,
            current_offset=self.current_offset,
            current_channels=self.current_channels,
            name=self.name,
            seed=seed,
            worker_parameter=self.worker_package,
        )


class ManagerTestUnits:
    """Collection of similar managers for testing.

    Contains a pointer to index what the current manager selected is.
    """

    index: int = 0
    _values: list[SeedlessManagerTestPackage]

    def __init__(self) -> None:
        self.index = 0
        self._values = []

    def create_unit(
        self,
        global_gates: "Gates",
        global_ohmics: "Ohmics",
        current_offset: dict["Channel", float],
        current_channels: "Channels",
        name: str,
        worker_parameters: "worker_package" = {},
    ) -> SeedlessManagerTestPackage:
        """Adds a new unit to the collection.

        Args:
            global_gates: List of global gates.
            global_ohmics: List of global ohmics.
            current_offset: Dictionary of channel names and their corresponding current offsets.
            current_channels: List of current channels.
            name: name for the printing of files.
            worker_parameters: Dictionary of worker parameter names and their corresponding values.

        Returns:
            A new unit.
        """
        out = SeedlessManagerTestPackage(
            worker_parameter=worker_parameters,
            global_gates=global_gates,
            global_ohmics=global_ohmics,
            current_offset=current_offset,
            current_channels=current_channels,
            name=name,
        )
        self._values.append(out)
        return out

    def get_next_unit(self) -> SeedlessManagerTestPackage:
        """Returns the current unit and updates the count for next time."""
        out = self.get_unit()
        self.index += 1
        return out

    def get_unit(self) -> SeedlessManagerTestPackage:
        """Returns the current unit."""
        if len(self._values) < self.index + 1:
            warnings.warn("Index out of bounds.")
            self.index -= 1
        return self.get_indexed_unit(self.index)

    def get_indexed_unit(self, index: int) -> SeedlessManagerTestPackage:
        """Returns the indexed unit."""
        return self._values[index]


class OperatorTestPackage:
    """Package that holds testing information for the Operator.

    Attributes:
        worker_parameters: Dictionary of worker parameter names and their corresponding values.
        workers: Dictionary of worker names and their corresponding BasicWorker instances.
        global_gates: List of global gates.
        global_ohmics: List of global ohmics.
        current_offset: Dictionary of channel names and their corresponding current offsets.
        current_channels: List of current channels.
        name: name for the printing of files.
        seed: seed for the random number generator.
    """

    global_gates: "Gates"
    global_ohmics: "Ohmics"
    current_offset: dict["Channel", float]
    name: str
    seed: int
    manager_packages: dict["ManagerName", ManagerTestUnits]
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
        name: str,
        seed: int,
        manager_packages: dict["ManagerName", ManagerTestUnits] = {},
    ):
        self.global_gates = global_gates
        self.global_ohmics = global_ohmics
        self.current_offset = current_offset
        self.name = name
        self.seed = seed
        self.manager_packages = manager_packages

    def create_managers(self, managertype: "ManagerName") -> ManagerTestUnits:
        """Generates the manager test package to be filled out.

        Use add_unit to add subsequent managers

        Args:
            managertype: The type of manager to be generated.

        Returns:
            The generated manager test package.
        """
        if managertype not in self.manager_packages:
            self.manager_packages[managertype] = ManagerTestUnits()
        return self.manager_packages[managertype]

    def select_test_package(
        self,
        managertype: "ManagerName",
        seed: int,
    ) -> ManagerTestPackage:
        """Selects and startup a manager test package.

        Args:
            managertype: The type of manager to be generated.
            seed : The seed for the random number generator.

        Returns:
            The generated manager test package.
        """
        return self.manager_packages[managertype].get_next_unit()(seed=seed)
