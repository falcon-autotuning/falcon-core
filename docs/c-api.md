# C API Documentation

The C API provides a C-compatible wrapper around the C++ core, enabling language bindings and ensuring ABI stability.

## Overview

The C API layer serves as the exposed interface for the Falcon Core library. It wraps the underlying C++ implementation in a stable C interface, which allows:

- **Language Bindings**: Python, Go, and other languages can interface with the library
- **ABI Stability**: C interfaces are more stable across compiler versions than C++
- **Cross-Language Compatibility**: C is the lingua franca for system programming

## Directory Structure

```
c-api/
├── include/           # Public C API header files
│   └── falcon_core/   # C API headers organized by module
├── src/               # C API implementation (wraps C++ core)
├── tests/             # C API tests
├── CMakeLists.txt     # CMake configuration
├── Makefile           # Build orchestration
└── vcpkg.json         # Dependency manifest
```

## Architecture

The C API follows this pattern for each C++ class or function:

1. **Opaque Pointers**: C++ objects are wrapped in opaque C pointers
2. **Constructor/Destructor**: C functions to create and destroy objects
3. **Methods**: C functions that take the opaque pointer as the first argument
4. **Error Handling**: Return codes for error propagation

Example pattern:
```c
// Opaque type
typedef struct FalconObject FalconObject;

// Constructor
FalconObject* falcon_object_create(const char* name);

// Method
int falcon_object_set_value(FalconObject* obj, double value);

// Destructor
void falcon_object_destroy(FalconObject* obj);
```

## Documentation Generation

The C API documentation is **automatically generated** from the C++ core documentation through the `code_docs` pipeline. This ensures consistency between the C++ and C API documentation.

### Documentation Pipeline

The documentation generation process:

1. **Extract**: Doxygen comments are extracted from C++ headers
   - Script: `code_docs/capi_docs/scripts/extract_cpp_docs.py`
   - Output: Metadata stored in `code_docs/capi_docs/cpp_metadata/`

2. **Map**: Mapping files link C++ symbols to their C API equivalents
   - Script: `code_docs/capi_docs/scripts/generate_c_api_maps.py`
   - Auto-generated maps: `c-api/include/falcon_core/*.map.yml`
   - Manual maps: `code_docs/capi_docs/c-api_user_maps/`

3. **Inject**: Documentation is injected into C API headers
   - Script: `code_docs/capi_docs/scripts/inject_c_docs.py`
   - Output: Updated C API headers with documentation

### Running the Documentation Pipeline

From the repository root:

```bash
# Run the complete documentation pipeline
make -f code_docs/capi_docs/capi_docs.mk docs-all

# Or run individual steps:
make -f code_docs/capi_docs/capi_docs.mk docs-setup    # Prepare clean environment
make -f code_docs/capi_docs/capi_docs.mk docs-run      # Generate documentation
make -f code_docs/capi_docs/capi_docs.mk docs-coverage # Check coverage
```

### Coverage Reporting

To see documentation coverage statistics:

```bash
make -f code_docs/capi_docs/capi_docs.mk docs-coverage
```

This reports:
- Percentage of C++ documentation ported to C API
- Functions/types with missing documentation
- Documentation quality metrics

## Building the C API

### Prerequisites

The C API requires the C++ core to be built first.

1. Build the C++ core:
   ```bash
   cd cpp
   make all
   ```

2. Build the C API:
   ```bash
   cd c-api
   make all
   ```

### Output

The compiled C API shared library (`.so` file) is located at:
```
dist/c_api/libfalcon_core.so
```

## Using the C API

### Linking

To use the C API in your application:

```c
#include <falcon_core/falcon_core.h>

// Your code here
```

Link against the shared library:
```bash
gcc -o myapp myapp.c -L/path/to/dist/c_api -lfalcon_core
```

### Python Bindings

The Python bindings in `src/falcon_core/` use the C API via ctypes or cffi to provide a Pythonic interface to the library.

## API Conventions

The C API follows these naming conventions:

- **Types**: `FalconTypeName` (PascalCase)
- **Functions**: `falcon_module_action` (snake_case with prefix)
- **Constants**: `FALCON_CONSTANT_NAME` (SCREAMING_SNAKE_CASE)
- **Enums**: `FalconEnumName` for the type, `FALCON_ENUM_VALUE` for values

## Error Handling

Functions return:
- `0` or non-negative values for success
- Negative values for errors
- Error codes are defined in `falcon_core/errors.h` (if available)

Always check return values and handle errors appropriately.

## Thread Safety

The C API provides thread-safe interfaces where applicable. Consult individual function documentation for thread-safety guarantees.

## Documentation on Website

The C API documentation will be exposed on the website through:

1. **Doxygen HTML**: Generated HTML documentation from C API headers
2. **MkDocs Integration**: C API reference integrated into the main documentation site
3. **API Reference**: Auto-generated API reference pages

See [Documentation Generation](code-docs.md) for more details on the documentation system.

## Contributing

When contributing to the C API:

1. Ensure all public functions have proper documentation comments
2. Update mapping files if adding new C API functions
3. Run the documentation pipeline to verify doc generation
4. Test the C API independently from the C++ core
5. Maintain ABI compatibility (don't break existing interfaces)

For more details, see the [Developer Guide](developer-guide.md).
