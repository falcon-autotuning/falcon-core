# Quick Build Reference for falcon-core

This document provides a quick reference for building and testing falcon-core based on the GitHub Actions workflows. For detailed instructions, see [BUILD_AND_TEST_INSTRUCTIONS.md](../BUILD_AND_TEST_INSTRUCTIONS.md) in the root directory.

## CI Workflows Overview

The repository includes the following CI workflows in `.github/workflows/`:

- **ubuntu-ci.yaml** - Ubuntu 22.04 build and test
- **arch-ci.yaml** - Arch Linux build and test (in container)
- **fedora-ci.yaml** - Fedora build and test (in container)
- **windows-ci.yaml** - Windows build and test
- **release.yaml** - Release builds for Linux and Windows

## Quick Build Commands

### Linux (with system packages)

```bash
# Install dependencies first (see main instructions)

# Build C++
cd cpp
CC=clang CXX=clang++ USE_VCPKG=0 make build-dev
make run-all-tests

# Build C-API
cd ../c-api
CC=clang CXX=clang++ USE_VCPKG=0 make build-dev
make run-all-tests
```

### Linux (with vcpkg)

```bash
# Install vcpkg first

# Build C++
cd cpp
CC=clang CXX=clang++ USE_VCPKG=1 make all
make run-all-tests

# Build C-API
cd ../c-api
CC=clang CXX=clang++ USE_VCPKG=1 make all
make run-all-tests
```

### Windows (with vcpkg)

```powershell
# Install vcpkg and dependencies

# Build C++
cd cpp
cmake --preset DEV
cmake --build build
.\build\falcon_core_cpp_run_tests.exe

# Build C-API
cd ..\c-api
cmake --preset DEV
cmake --build build
.\build\falcon_core_c_api_run_tests.exe
```

### Using Root Makefile

```bash
# Build both C++ and C-API
make build-dev USE_VCPKG=0

# Run all tests
make test
```

## Key Build Variables

- `CC` - C compiler (default: clang)
- `CXX` - C++ compiler (default: clang++)
- `USE_VCPKG` - Use vcpkg for dependencies (0=system packages, 1=vcpkg)

## Coverage Reports

Coverage reports are generated in:
- `cpp/coverage/falcon-core-cpp.txt` (min 85% required)
- `c-api/coverage/falcon-core-c-api.txt` (min 90% required)

## Workflow Triggers

All CI workflows trigger on:
- Push to `main` branch
- Pull requests to `main` branch

Release workflow triggers on:
- Tags matching `v*` (e.g., v1.0.0)

## Dependencies Summary

### Core Dependencies
- boost (filesystem, system, program-options, test)
- hdf5 (with C++ support)
- yaml-cpp
- cereal
- nlohmann-json
- openssl
- sqlite3
- gtest (for testing)

### xtensor Stack
- xtl
- xsimd
- xtensor
- xtensor-io

### Additional
- highfive (HDF5 C++ wrapper)
- exprtk (expression parser)

## Build System

- **Build tool**: CMake + Ninja
- **Primary compiler**: Clang/LLVM
- **Coverage**: llvm-cov (Clang) or gcov (GCC)
- **Caching**: ccache for faster rebuilds

## Directory Structure

```
falcon-core/
├── cpp/                  # C++ core library
│   ├── Makefile         # Build automation
│   ├── CMakeLists.txt   # CMake configuration
│   ├── src/            # Source files
│   ├── include/        # Header files
│   └── tests/          # Unit tests
├── c-api/               # C API wrapper
│   ├── Makefile         # Build automation
│   ├── CMakeLists.txt   # CMake configuration
│   ├── src/            # Source files
│   ├── include/        # Header files
│   └── tests/          # Unit tests
├── Makefile             # Root-level build automation
├── .github/
│   └── workflows/       # CI/CD workflows
└── packaging/           # Distribution packages
    ├── xtl/            # Arch PKGBUILD
    ├── xsimd/          # Arch PKGBUILD
    ├── xtensor/        # Arch PKGBUILD
    ├── xtensor-io/     # Arch PKGBUILD
    └── specs/          # RPM spec files
```

## Testing

Tests are built automatically with `build-dev` target and run with:

```bash
# C++
cd cpp
make run-all-tests

# C-API
cd c-api
make run-all-tests
```

Test executables:
- `cpp/build/falcon_core_cpp_run_tests`
- `c-api/build/falcon_core_c_api_run_tests`

## Troubleshooting

Common issues and solutions:

1. **vcpkg not found**: Install vcpkg or use `USE_VCPKG=0`
2. **Missing dependencies**: Install platform-specific packages
3. **Coverage not generated**: Use `build-dev` target, not `build`
4. **C-API fails**: Build C++ core first
5. **Slow compilation**: Install and configure ccache

## Further Reading

For detailed platform-specific instructions, dependency versions, and advanced configuration options, see:

📖 [BUILD_AND_TEST_INSTRUCTIONS.md](../BUILD_AND_TEST_INSTRUCTIONS.md)

## CI Workflow Examples

### Viewing Workflow Status

Check the Actions tab on GitHub or use GitHub CLI:

```bash
gh workflow list
gh run list --workflow=ubuntu-ci.yaml
gh run view <run-id>
```

### Local Workflow Testing

Use `act` to test workflows locally:

```bash
# Install act
brew install act  # macOS
# or download from https://github.com/nektos/act

# Run workflow
act -j build-and-test-ubuntu
```

## Contact

For issues with CI workflows or build instructions, please:
1. Check the detailed instructions in BUILD_AND_TEST_INSTRUCTIONS.md
2. Review existing GitHub Issues
3. Open a new issue with build logs and environment details
