"""Loads all Jsonable plugins."""

from importlib import metadata

from .dependancies import importlib

for entry_point in metadata.entry_points(group="core_messaging.plugins"):
    importlib.import_module(entry_point.value)
