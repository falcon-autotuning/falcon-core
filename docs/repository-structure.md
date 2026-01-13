# Repository Structure

This document provides an overview of the falcon-core repository organization.

## Directory Layout

```
falcon-core/
├── cpp/                    # C++ core implementation (lowest level)
├── c-api/                  # C API wrapper (exposed C API)
├── src/                    # Python bindings and interface
├── code_docs/              # Auto-generated documentation
├── packaging/              # Package specifications for various distros
├── .github/                # GitHub workflows and CI/CD
└── docs/                   # Main documentation (this folder)
```

## Core Components

### C++ Core (`cpp/`)

The lowest-level implementation of Falcon Core, written in C++14. Contains:

- `include/` - C++ header files with core datatypes and algorithms
- `src/` - C++ source implementation files
- `tests/` - C++ unit tests
- `CMakeLists.txt` - CMake build configuration
- `vcpkg.json` - Dependency manifest for vcpkg

The C++ core provides the fundamental building blocks for all other language interfaces.

### C API (`c-api/`)

A C-compatible wrapper that exposes the C++ functionality through a stable C API. This layer:

- Provides a C interface to the C++ core
- Enables language bindings for Python, Go, and other languages
- Maintains ABI stability
- Contains:
  - `include/` - C API header files
  - `src/` - C API implementation (wraps C++ core)
  - `tests/` - C API tests
  - `CMakeLists.txt` - CMake build configuration

### Python Bindings (`src/`)

Python interface to the Falcon Core library:

- `falcon_core/` - Python package with submodules
  - `autotuner_interfaces/` - Autotuner abstractions
  - `communications/` - Communication protocols
  - `instrument_interfaces/` - Instrument control interfaces
  - `math/` - Mathematical utilities
  - `physics/` - Physics-related functionality
  - `generic/` - Generic utilities

### Documentation Generation (`code_docs/`)

Automated pipeline for generating and synchronizing documentation between C++ and C API:

- `capi_docs/` - C API documentation automation
  - `scripts/` - Python scripts for doc extraction and injection
  - `cpp_metadata/` - Extracted C++ documentation metadata
  - `c-api_user_maps/` - Manual mappings for doc translation
  - `archive/` - Archived versions of c-api for doc generation

The documentation generation process:
1. Extracts Doxygen comments from C++ headers
2. Generates mapping files between C++ and C API
3. Injects documentation into C API headers

### Packaging (`packaging/`)

Distribution packages for various platforms:

- `falcon-core-cpp/` - C++ core package
- `falcon-core-c-api/` - C API package
- `xsimd/`, `xtensor/`, `xtensor-io/`, `xtl/` - Packaged dependencies

## Build System

The repository uses:

- **CMake** with **Ninja** for C++ and C builds
- **vcpkg** for C++ dependency management
- **Makefile** for orchestrating builds and tests
- **Python setuptools** for Python package installation

## Key Files

- `Makefile` - Main build orchestration
- `LICENSE.txt` - BSD 3-Clause License
- `README.md` - Project overview and quick start
- `.gitignore` - Git ignore rules
- `.clang-format` - Code formatting configuration
