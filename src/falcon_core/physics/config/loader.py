"""Module for loading config files.

This module defines the configLoader class, which is used to load a config file.
"""

from typing import TYPE_CHECKING

from .config_manipulations import ConfigManipulations
from .dependancies import Config, Path, yaml

if TYPE_CHECKING:
    from .dependancies import Config
    from .typing import Any


class Loader(
    ConfigManipulations,
):
    """Special configFuncs with the ability to load a config on startup."""

    _config_path: Path
    _config: "Config"

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
        self._config = config["config"]

    def load_config(self) -> dict[str, "Any"]:
        """Load the config file.

        Returns:
            dict : the config dictionary
        """
        with Path.open(self._config_path) as file:
            return yaml.safe_load(file)
