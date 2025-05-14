"""The various external dependencies required by Falcon."""

import collections
import contextlib
import importlib
import inspect
import io
import itertools
import json
import pickle
import random
import sys
import time
import uuid
from abc import abstractmethod
from base64 import b64decode, b64encode
from copy import copy, deepcopy
from dataclasses import dataclass
from enum import Enum
from functools import wraps
from io import IOBase
from itertools import chain
from math import log10
from pathlib import Path
from typing import overload

import dill  # type: ignore  # noqa: PGH003
import numpy as np
import valkey  # type: ignore  # noqa: PGH003
import yaml
from scipy.ndimage import (  # type: ignore  # noqa: PGH003
    uniform_filter1d as untyped_uniform_filter1d,
)

__all__ = [
    "importlib",
    "yaml",
    "collections",
    "uuid",
    "log10",
    "wraps",
    "abstractmethod",
    "time",
    "valkey",
    "chain",
    "dill",
    "contextlib",
    "itertools",
    "pickle",
    "b64decode",
    "b64encode",
    "inspect",
    "random",
    "overload",
    "deepcopy",
    "copy",
    "json",
    "dataclass",
    "Enum",
    "np",
    "sys",
    "IOBase",
    "Path",
    "io",
    "untyped_uniform_filter1d",
]
