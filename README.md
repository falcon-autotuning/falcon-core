# Falcon Core

[![Linux CI](https://github.com/falcon-autotuning/falcon-core/actions/workflows/ci-linux.yml/badge.svg?branch=dev)](https://github.com/falcon-autotuning/falcon-core/actions/workflows/ci-linux.yml?query=branch:dev)
[![Windows CI](https://github.com/falcon-autotuning/falcon-core/actions/workflows/ci-windows.yml/badge.svg?branch=dev)](https://github.com/falcon-autotuning/falcon-core/actions/workflows/ci-windows.yml?query=branch:dev)
Core utilities for all falcon applications used for autotuning of quantum devices.

This repository contains the main datatypes that can be used for serialization within falcon. All of the source code is written in C++14. It can be found at /cpp.

## Key Features

- 🚀 **High Performance**: Optimized C++ core with minimal overhead
- 📊 **Data Serialization**: Comprehensive support for HDF5
- 🧪 **Quantum Device Control**: Built for quantum hardware autotuning
- 🖥️ **Cross-Platform**: Supports Windows and Linux

## Quick Start

Supported platforms (CI)

- Linux
- Windows

We maintain CI workflows for both Linux and Windows; the badges above reflect the latest test/build status for that branch.

### Installation

For detailed installation instructions, see the [Installation Guide](docs/installation.md).

**Quick install for development:**

```bash
# Clone the repository
git clone https://github.com/falcon-autotuning/falcon-core.git
cd falcon-core

# Build C++ core
cd cpp
make clean-all && make all

# Build C API
cd ../c-api
make all
```

### User-Facing Libraries

For Python and other high-level language bindings, see [falcon-core-libs](https://github.com/falcon-autotuning/falcon-core-libs).

## Documentation

📖 **[Full Documentation](docs/index.md)** - Comprehensive guides and API reference

- [Installation Guide](docs/installation.md) - Detailed installation instructions
- [Developer Guide](docs/developer-guide.md) - Contributing and development workflow
- [C++ Core Documentation](docs/cpp-core.md) - C++ API and implementation details
- [C API Documentation](docs/c-api.md) - C API wrapper and usage
- [Documentation Generation](docs/code-docs.md) - Automated documentation pipeline

### Building Documentation Website

This project uses [MkDocs](https://www.mkdocs.org/) for documentation:

```bash
# Install MkDocs
pip install mkdocs mkdocs-material

# Serve documentation locally
mkdocs serve

# Build static site
mkdocs build
```

Visit <http://localhost:8000> to view the documentation.

## Repository Structure

```
falcon-core/
├── cpp/              # C++ core implementation (lowest level)
├── c-api/            # C API wrapper (exposed C-compatible interface)
├── code_docs/        # Auto-generated documentation pipeline
├── packaging/        # Distribution packages
└── docs/             # Documentation source files
```

The C++ core provides the foundational layer, the C API provides a stable wrapper for language bindings, and the documentation pipeline automatically generates API docs from source code.

For user-facing libraries (Python, etc.), see [falcon-core-libs](https://github.com/falcon-autotuning/falcon-core-libs).

## Dependencies

### Core Dependencies

Required for building the C++ core:

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

Additional dependencies for development

- gtest@1.16.0 (unit testing)
- clang or gcc (C++ compiler)
- vcpkg (package manager)
- ninja (build system)
- ccache (recommended, for faster builds)

### Packaged Dependencies

Some dependencies are packaged in the `packaging/` folder for convenience:

- xsimd@13.2.0
- xtensor@0.25.0
- xtensor-io@0.13.0
- xtl@0.7.5

Install these packages (on Arch Linux):

```bash
cd packaging/xtl && makepkg -si && cd ../..
cd packaging/xsimd && makepkg -si && cd ../..
cd packaging/xtensor && makepkg -si && cd ../..
cd packaging/xtensor-io && makepkg -si && cd ../..
```

## Building from Source

### Prerequisites

1. **Install vcpkg**: Follow [vcpkg installation instructions](https://learn.microsoft.com/en-us/vcpkg/get_started/overview)
2. **Install build tools**: clang/gcc, ninja, ccache (recommended)

### Build C++ Core

```bash
cd cpp
make clean-all && make all
```

For subsequent builds:

## Getting started for devs

We use [clang](https://clang.llvm.org/) /(llvm/) as our main compiler, but [gcc](https://gcc.gnu.org/) should also work. The code is tested on Linux and Windows via CI. You need one of the above C compilers installed and a working CMake/Ninja toolchain.

We use vcpkg to manage all of our C++ dependencies. This needs to be installed following distro specific [instruction](https://learn.microsoft.com/en-us/vcpkg/get_started/overview).
With vcpkg we use [ninja](https://ninja-build.org/) as our build system. This also needs to be installed on your system.
Finally we recommend using [ccache](https://ccache.dev/) to speed up compilation times.

With those 3 precursors setup, to build run in the cpp directory

```console
make clean-all; make all 
```

### User-Facing Libraries

For Python and other high-level language bindings, see [falcon-core-libs](https://github.com/falcon-autotuning/falcon-core-libs).

To build subsequent times you can use

```console
📖 **[Full Documentation](docs/index.md)** - Comprehensive guides and API reference

- [Installation Guide](docs/installation.md) - Detailed installation instructions
- [Developer Guide](docs/developer-guide.md) - Contributing and development workflow
- [C++ Core Documentation](docs/cpp-core.md) - C++ API and implementation details
- [C API Documentation](docs/c-api.md) - C API wrapper and usage
- [Documentation Generation](docs/code-docs.md) - Automated documentation pipeline

### Building Documentation Website

This project uses [MkDocs](https://www.mkdocs.org/) for documentation:

```bash
# Install MkDocs
pip install mkdocs mkdocs-material

# Serve documentation locally
mkdocs serve

# Build static site
mkdocs build
```

Visit <http://localhost:8000> to view the documentation.

## Repository Structure

```
falcon-core/
├── cpp/              # C++ core implementation (lowest level)
├── c-api/            # C API wrapper (exposed C-compatible interface)
├── code_docs/        # Auto-generated documentation pipeline
├── packaging/        # Distribution packages
└── docs/             # Documentation source files
```

The C++ core provides the foundational layer, the C API provides a stable wrapper for language bindings, and the documentation pipeline automatically generates API docs from source code.

For user-facing libraries (Python, etc.), see [falcon-core-libs](https://github.com/falcon-autotuning/falcon-core-libs).

## Dependencies

### Core Dependencies

Required for building the C++ core:

- boost@1.88.0
- bzip2@1.0.8
- cereal@1.3.2 (serialization)
- expat@2.7.1
- exprtk@0.0.2
- hdf5@1.14.6 (HDF5 support)
- highfive@3.1.1 (C++ HDF5 interface)
- nlohmann-json@3.12.0 (JSON support)
- openssl@3.5.2
- python3@3.12.9
- sqlite3@3.50.4
- xsimd@13.2.0 (SIMD operations)
- xtensor@0.25.0 (multi-dimensional arrays)
- xtensor-io@0.13.0 (array I/O)
- xtl@0.7.5
- yaml-cpp@0.8.0 (YAML support)
- zlib@1.3.1

### Development Dependencies

Additional dependencies for development:

- gtest@1.16.0 (unit testing)
- clang or gcc (C++ compiler)
- vcpkg (package manager)
- ninja (build system)
- ccache (recommended, for faster builds)

### Packaged Dependencies

Some dependencies are packaged in the `packaging/` folder for convenience:

- xsimd@13.2.0
- xtensor@0.25.0
- xtensor-io@0.13.0
- xtl@0.7.5

Install these packages (on Arch Linux):

```bash
cd packaging/xtl && makepkg -si && cd ../..
cd packaging/xsimd && makepkg -si && cd ../..
cd packaging/xtensor && makepkg -si && cd ../..
cd packaging/xtensor-io && makepkg -si && cd ../..
```

## Building from Source

### Prerequisites

1. **Install vcpkg**: Follow [vcpkg installation instructions](https://learn.microsoft.com/en-us/vcpkg/get_started/overview)
2. **Install build tools**: clang/gcc, ninja, ccache (recommended)

### Build C++ Core

```bash
cd cpp
make clean-all && make all
```

For subsequent builds:

```bash
make build
```

If things get weird you may want to throw a `make clean` every so often.
Conversely to target building specific folders in C you can specify

The C API requires the C++ core to be built first:

```bash
cd c-api
make all
```

The compiled library will be at `dist/c_api/libfalcon_core.so`

### Build Commands Reference

**In the `cpp/` directory:**

```bash
# Full clean build (first time or after major changes)
make clean-all && make all

# Incremental build
make build

# Clean build artifacts
make clean

# Build specific files (faster iteration)
make build-part DIRS="file/path;targetted/file.cpp" TESTS="all/tests/here;this/specific/one.cpp"

# Build with sanitizers (for debugging memory issues)
make build-and-sanitize

# Run tests
make test

# View code coverage
make coverage-overview
```

**In the `c-api/` directory:**

- CI configuration files live in `.github/workflows/`. We run builds and tests for Linux and Windows; please make sure new tests run in both environments where applicable.
- The build status badges at the top of this README use the workflow filenames `ci-linux.yml` and `ci-windows.yml` and show the `dev` branch status. If you use different workflow filenames, update the badge URLs accordingly.
- To add the docs site, we use mkdocs with the configuration in `mkdocs.yml` and content in `docs/`.

```bash
# Build C API
make all

# Run C API tests
make test
```

For more details, see the [Developer Guide](docs/developer-guide.md).

## Development

### Code Style

- **C++**: C++14 standard, formatted with `.clang-format`
- **C API**: C-compatible interface with `falcon_` prefix

### Documentation

All public APIs must have documentation:

- **C++**: Doxygen comments
- **C API**: Auto-generated from C++ documentation

### Testing

```bash
# C++ tests
cd cpp && make test

# C API tests
cd c-api && make test
```

### Documentation Pipeline

The C API documentation is automatically generated from C++ documentation:

```bash
# Run the full documentation pipeline
make -f code_docs/capi_docs/capi_docs.mk docs-all

# Check documentation coverage
make -f code_docs/capi_docs/capi_docs.mk docs-coverage
```

See [Documentation Generation](docs/code-docs.md) for details.

## Contributing

We welcome contributions! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

### Quick Contribution Guide

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Make your changes
4. Write tests for your changes
5. Ensure all tests pass
6. Update documentation as needed
7. Commit your changes (`git commit -m 'Add amazing feature'`)
8. Push to your branch (`git push origin feature/amazing-feature`)
9. Open a Pull Request

## License

This project is licensed under the BSD 3-Clause License. See [LICENSE.txt](LICENSE.txt) for the full license text.

Copyright (c) 2023-2024 Tyler Kovach, Daniel Schug, Zachery Merino

## Acknowledgments

- Built with modern C++14 for performance and reliability
- Uses vcpkg for dependency management
- Leverages xtensor for multi-dimensional array operations
- Documentation powered by Doxygen and MkDocs

## Support

- 📚 **Documentation**: [docs/](docs/index.md)
- 🐛 **Issues**: [GitHub Issues](https://github.com/falcon-autotuning/falcon-core/issues)
- 💬 **Discussions**: [GitHub Discussions](https://github.com/falcon-autotuning/falcon-core/discussions)

## Links

- [Installation Guide](docs/installation.md)
- [Developer Guide](docs/developer-guide.md)
- [C++ Core Documentation](docs/cpp-core.md)
- [C API Documentation](docs/c-api.md)
- [Contributing Guidelines](CONTRIBUTING.md)
- [License](LICENSE.txt)
- [User-Facing Libraries](https://github.com/falcon-autotuning/falcon-core-libs)
