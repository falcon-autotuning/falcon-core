# Falcon Core

[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](LICENSE.txt)

Core utilities and datatypes for autotuning quantum devices. Falcon Core provides a robust, high-performance library for quantum device calibration and parameter optimization.

## Overview

Falcon Core is a multi-layered library designed for quantum device autotuning:

- **C++ Core** (`cpp/`) - High-performance C++14 implementation with core datatypes and algorithms
- **C API** (`c-api/`) - Stable C-compatible wrapper exposing the C++ functionality
- **Python Bindings** (`src/`) - Pythonic interface for easy integration
- **Automated Documentation** (`code_docs/`) - Pipeline for generating and synchronizing API documentation

### Key Features

- 🚀 **High Performance**: Optimized C++ core with minimal overhead
- 🔒 **Type Safety**: Strong typing with modern C++14 features
- 🌐 **Multi-Language Support**: C++, C API, and Python interfaces
- 📊 **Data Serialization**: Comprehensive support for HDF5, JSON, and YAML
- 🧪 **Quantum Device Control**: Built for quantum hardware autotuning
- 📚 **Well Documented**: Auto-generated documentation from source code

## Quick Start

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

### Python Usage

```bash
# Install Python bindings
pip install -e src/
```

```python
import falcon_core
# Use the library
```

## Documentation

📖 **[Full Documentation](docs/index.md)** - Comprehensive guides and API reference

- [Repository Structure](docs/repository-structure.md) - Overview of the codebase organization
- [C++ Core Documentation](docs/cpp-core.md) - C++ API and implementation details
- [C API Documentation](docs/c-api.md) - C API wrapper and usage
- [Documentation Generation](docs/code-docs.md) - Automated documentation pipeline
- [Installation Guide](docs/installation.md) - Detailed installation instructions
- [Developer Guide](docs/developer-guide.md) - Contributing and development workflow

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

Visit http://localhost:8000 to view the documentation.

## Repository Structure

```
falcon-core/
├── cpp/              # C++ core implementation (lowest level)
├── c-api/            # C API wrapper (exposed C-compatible interface)
├── src/              # Python bindings
├── code_docs/        # Auto-generated documentation pipeline
├── packaging/        # Distribution packages
└── docs/             # Documentation source files
```

### Component Overview

- **C++ Core** (`cpp/`) - The foundational layer written in C++14, containing core datatypes, algorithms, and utilities for quantum device autotuning
- **C API** (`c-api/`) - A stable C-compatible wrapper that exposes the C++ functionality, enabling language bindings and ensuring ABI stability
- **Python Bindings** (`src/`) - Python interface providing Pythonic access to the library
- **Documentation Generation** (`code_docs/`) - Automated pipeline that extracts documentation from C++ and generates C API documentation

For a detailed breakdown, see [Repository Structure](docs/repository-structure.md).

## Dependencies

### Core Dependencies

Required for building the C++ core:

* boost@1.88.0
* bzip2@1.0.8
* cereal@1.3.2 (serialization)
* expat@2.7.1
* exprtk@0.0.2
* hdf5@1.14.6 (HDF5 support)
* highfive@3.1.1 (C++ HDF5 interface)
* nlohmann-json@3.12.0 (JSON support)
* openssl@3.5.2
* python3@3.12.9
* sqlite3@3.50.4
* xsimd@13.2.0 (SIMD operations)
* xtensor@0.25.0 (multi-dimensional arrays)
* xtensor-io@0.13.0 (array I/O)
* xtl@0.7.5
* yaml-cpp@0.8.0 (YAML support)
* zlib@1.3.1

### Development Dependencies

Additional dependencies for development:

* gtest@1.16.0 (unit testing)
* clang or gcc (C++ compiler)
* vcpkg (package manager)
* ninja (build system)
* ccache (recommended, for faster builds)

### Packaged Dependencies

Some dependencies are packaged in the `packaging/` folder for convenience:

* xsimd@13.2.0
* xtensor@0.25.0
* xtensor-io@0.13.0
* xtl@0.7.5

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

### Build C API

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
- **Python**: PEP 8 compliant with type hints

### Documentation

All public APIs must have documentation:
- **C++**: Doxygen comments
- **C API**: Auto-generated from C++ documentation
- **Python**: Google-style docstrings

### Testing

```bash
# C++ tests
cd cpp && make test

# C API tests
cd c-api && make test

# Python tests
cd src && python -m pytest
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

- [Repository Structure](docs/repository-structure.md)
- [Installation Guide](docs/installation.md)
- [Developer Guide](docs/developer-guide.md)
- [C++ Core Documentation](docs/cpp-core.md)
- [C API Documentation](docs/c-api.md)
- [Contributing Guidelines](CONTRIBUTING.md)
- [License](LICENSE.txt)
