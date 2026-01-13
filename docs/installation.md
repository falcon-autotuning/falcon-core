# Installation Guide

This guide covers installation of Falcon Core for different use cases.

## Overview

Falcon Core can be installed in several ways:
- From source (for development)
- Via package manager (for users on Arch Linux)
- As a Python package (for Python users)

## Dependencies

### Core C++ Dependencies

These dependencies are required for building the C++ core:

- boost@1.88.0
- bzip2@1.0.8#6
- cereal@1.3.2#1
- expat@2.7.1
- exprtk@0.0.2
- hdf5@1.14.6
- highfive@3.1.1
- nlohmann-json@3.12.0
- openssl@3.5.2
- python3@3.12.9
- sqlite3@3.50.4
- xsimd@13.2.0
- xtensor@0.25.0
- xtensor-io@0.13.0
- xtl@0.7.5
- yaml-cpp@0.8.0
- zlib@1.3.1

### Development Dependencies

Additional dependencies for development:

- gtest:x64-linux-dynamic@1.16.0 (unit testing)
- clang or gcc (C++ compiler)
- vcpkg (package manager)
- ninja (build system)
- ccache (recommended, compilation cache)

## Installation Methods

### Method 1: Package Manager (Arch Linux)

For Arch Linux users, packages are available for some dependencies.

#### Install Packaged Dependencies

Some dependencies are packaged in the `packaging/` folder:

```bash
# Install xtl
cd packaging/xtl
makepkg -si
cd ../..

# Install xsimd
cd packaging/xsimd
makepkg -si
cd ../..

# Install xtensor
cd packaging/xtensor
makepkg -si
cd ../..

# Install xtensor-io
cd packaging/xtensor-io
makepkg -si
cd ../..
```

#### Install Falcon Core

```bash
cd packaging/falcon-core-cpp
makepkg -si
cd ../..
```

For development version:
```bash
cd packaging/falcon-core-cpp-dev
makepkg -si
cd ../..
```

### Method 2: Build from Source

#### Prerequisites

1. **Install vcpkg**

   Follow the [vcpkg installation instructions](https://learn.microsoft.com/en-us/vcpkg/get_started/overview) for your distribution.

2. **Install Build Tools**

   ```bash
   # On Arch Linux
   sudo pacman -S clang ninja ccache

   # On Ubuntu/Debian
   sudo apt install clang ninja-build ccache

   # On Fedora
   sudo dnf install clang ninja-build ccache
   ```

#### Build C++ Core

1. **Navigate to cpp directory**:
   ```bash
   cd cpp
   ```

2. **Initial build** (first time or after major changes):
   ```bash
   make clean-all
   make all
   ```

3. **Subsequent builds**:
   ```bash
   make build
   ```

4. **Run tests**:
   ```bash
   make test
   ```

#### Build C API

The C API requires the C++ core to be built first.

1. **Navigate to c-api directory**:
   ```bash
   cd c-api
   ```

2. **Build**:
   ```bash
   make all
   ```

The compiled library will be at: `dist/c_api/libfalcon_core.so`

### Method 3: Python Package

For Python users, install the Python bindings:

```bash
# From the repository root
pip install -e src/
```

Or for a specific Python version:
```bash
python3.12 -m pip install -e src/
```

This installs the `falcon_core` Python package with all submodules.

## Verification

### Verify C++ Build

```bash
cd cpp
make test
```

All tests should pass.

### Verify C API Build

```bash
cd c-api
make test
```

### Verify Python Installation

```python
import falcon_core
print(falcon_core.__file__)
```

Should print the installation path without errors.

## Troubleshooting

### vcpkg Issues

If vcpkg fails to install dependencies:

1. **Update vcpkg**:
   ```bash
   cd /path/to/vcpkg
   git pull
   ./bootstrap-vcpkg.sh
   ```

2. **Clear vcpkg cache**:
   ```bash
   vcpkg remove --outdated
   vcpkg install --clean-after-build
   ```

### Compilation Errors

If compilation fails:

1. **Clean build artifacts**:
   ```bash
   make clean
   make clean-all
   ```

2. **Check compiler version**:
   ```bash
   clang --version  # Should be reasonably recent
   ```

3. **Verify dependencies**:
   ```bash
   vcpkg list
   ```

### Runtime Errors

If you encounter runtime errors:

1. **Run with sanitizers**:
   ```bash
   make build-and-sanitize
   ```

2. **Check library path**:
   ```bash
   export LD_LIBRARY_PATH=/path/to/falcon-core/dist/c_api:$LD_LIBRARY_PATH
   ```

### Python Import Errors

If Python can't find the module:

1. **Verify installation**:
   ```bash
   pip list | grep falcon
   ```

2. **Install in development mode**:
   ```bash
   pip install -e src/
   ```

3. **Check PYTHONPATH**:
   ```bash
   export PYTHONPATH=/path/to/falcon-core/src:$PYTHONPATH
   ```

## Platform-Specific Notes

### Linux

Falcon Core is primarily developed and tested on Linux. Both Arch Linux and Ubuntu are supported.

### macOS

macOS support is experimental. You will need to install dependencies via Homebrew:

```bash
# Install Homebrew if not already installed
# See https://brew.sh

# Install dependencies
brew install boost hdf5 yaml-cpp nlohmann-json cmake ninja ccache

# Install vcpkg following the instructions at:
# https://learn.microsoft.com/en-us/vcpkg/get_started/overview

# Then follow the "Build from Source" instructions above
```

Note: Some dependencies may need to be installed via vcpkg if not available in Homebrew.

### Windows

Windows support is limited. Consider using WSL (Windows Subsystem for Linux) for the best experience.

## Next Steps

After installation:
- Read the [Developer Guide](developer-guide.md) for development setup
- Explore the [C++ Core Documentation](cpp-core.md)
- Check out the [C API Documentation](c-api.md)
- Review [Repository Structure](repository-structure.md)

## Getting Help

If you encounter issues:
1. Check the [troubleshooting section](#troubleshooting)
2. Review the logs in `code_docs/capi_docs/logs/`
3. Open an issue on GitHub with:
   - Your platform and compiler version
   - Full error messages
   - Steps to reproduce
