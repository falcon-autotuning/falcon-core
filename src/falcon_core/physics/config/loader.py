"""Module for loading config files.

This module defines the configLoader class, which is used to load a config file.
"""

from typing import TYPE_CHECKING

from .config_manipulations import ConfigManipulations
from .dependancies import Path, yaml
from .utilities import Utilities

if TYPE_CHECKING:
    from .typing import Any


class Loader(
    Utilities,
    ConfigManipulations,
):
    """Special configFuncs with the ability to load a config on startup."""

    _config_path: Path

    def __init__(
        self,
        config_path: Path,
    ) -> None:
        """Constructor for special config loading utility.

        Should not be initialized if the config path is unknown.

        Input:
            config_path : path from root to the config file created by the user
        """
        # Load YAML file
        self._config_path = config_path
        config = self.load_config()

        Utilities.__init__(
            self,
            config=self.unpack_device_config(config=config["config"]),
        )

    def load_config(self) -> dict[str, "Any"]:
        """Load the config file.

        Returns:
            dict : the config dictionary
        """
        with Path.open(self._config_path) as file:
            return yaml.safe_load(file)
