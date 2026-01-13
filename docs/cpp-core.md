# C++ Core Documentation

The C++ core is the lowest-level implementation of Falcon Core, providing the fundamental datatypes and algorithms for quantum device autotuning.

## Overview

The C++ core is written in C++14 and leverages modern C++ features for type safety and performance. It provides the foundation upon which all other language interfaces are built.

## Directory Structure

```
cpp/
├── include/           # Public C++ header files
├── src/               # C++ implementation files
├── tests/             # C++ unit tests
├── CMakeLists.txt     # CMake configuration
├── Makefile           # Build orchestration
└── vcpkg.json         # Dependency manifest
```

## Key Features

### Data Types

The C++ core defines fundamental datatypes for:
- Quantum device parameters
- Measurement results
- Configuration structures
- Serialization formats

### Algorithms

Core algorithms for:
- Data processing
- Parameter optimization
- Device calibration
- State management

### Dependencies

The C++ core depends on:

- **boost** (1.88.0) - General utilities and algorithms
- **cereal** (1.3.2) - Serialization framework
- **hdf5** (1.14.6) - HDF5 file format support
- **highfive** (3.1.1) - C++ HDF5 interface
- **nlohmann-json** (3.12.0) - JSON parsing and serialization
- **xsimd** (13.2.0) - SIMD operations
- **xtensor** (0.25.0) - Multi-dimensional arrays
- **xtensor-io** (0.13.0) - Array I/O operations
- **yaml-cpp** (0.8.0) - YAML parsing

For development:
- **gtest** (1.16.0) - Unit testing framework

## Building

### Prerequisites

1. **Compiler**: clang (LLVM) or gcc with C++14 support
2. **vcpkg**: Package manager for C++ dependencies
3. **ninja**: Fast build system
4. **ccache**: (recommended) Compilation cache for faster builds

### Build Commands

Initial build:
```bash
cd cpp
make clean-all
make all
```

Subsequent builds:
```bash
make build
```

Partial builds (specific files):
```bash
make build-part DIRS="file/path;targetted/file.cpp" TESTS="all/tests/here;this/specific/one.cpp"
```

Build with sanitizers (for debugging):
```bash
make build-and-sanitize
```

### Testing

Run all tests:
```bash
make test
```

### Code Coverage

View coverage report:
```bash
make coverage-overview
```

## API Documentation

Detailed API documentation is generated from Doxygen comments in the header files. The documentation extraction process is automated through the `code_docs` pipeline.

## Design Principles

1. **Performance**: Optimize for speed and minimal memory overhead
2. **Type Safety**: Leverage C++ type system for compile-time checks
3. **Modularity**: Clean separation of concerns with well-defined interfaces
4. **Documentation**: Comprehensive Doxygen comments for all public APIs
5. **Testing**: Thorough unit test coverage for all functionality

## Contributing

When contributing to the C++ core:

1. Follow the existing code style (enforced by `.clang-format`)
2. Add Doxygen comments to all public APIs
3. Write unit tests for new functionality
4. Ensure all tests pass before submitting
5. Run sanitizers to catch memory issues

For more details, see the [Developer Guide](developer-guide.md).
