import os
import pathlib
import subprocess
import sys

from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext

# The name of the python package from pyproject.toml
PKG_NAME = "falcon_core"


class CMakeExtension(Extension):
    """A custom extension for CMake projects."""

    def __init__(self, name, sourcedir=""):
        super().__init__(name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)


class CMakeBuild(build_ext):
    """A custom build command that runs CMake."""

    def build_extension(self, ext):
        if not isinstance(ext, CMakeExtension):
            super().build_extension(ext)
            return

        # The directory for build artifacts
        build_temp = pathlib.Path(self.build_temp)
        build_temp.mkdir(parents=True, exist_ok=True)

        # The path to the Python executable
        python_exe = sys.executable

        # The output directory for the compiled module, relative to the project root.
        # This matches the `package_dir` and `where` settings.
        output_dir = pathlib.Path(self.get_ext_fullpath(ext.name)).parent.resolve()

        # Configure CMake
        cmake_args = [
            f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={output_dir}",
            f"-DPYTHON_EXECUTABLE={python_exe}",
            "-DCMAKE_BUILD_TYPE=Release",
        ]

        # Build with CMake
        build_args = ["--config", "Release"]

        # Run CMake configure
        subprocess.check_call(["cmake", ext.sourcedir] + cmake_args, cwd=self.build_temp)
        # Run CMake build
        subprocess.check_call(["cmake", "--build", "."] + build_args, cwd=self.build_temp)


# The setup() call is now simpler, as metadata is in pyproject.toml.
# We only need to specify the custom build steps for the C++ extension.
setup(
    cmdclass={"build_ext": CMakeBuild},
    ext_modules=[CMakeExtension(PKG_NAME)],
    zip_safe=False,
)
