# Developer Guide

This guide covers development workflows, coding standards, and best practices for contributing to Falcon Core.

## Development Setup

### Prerequisites

1. **Compiler**: clang (LLVM) or gcc with C++14 support
2. **Build Tools**:
   - vcpkg (C++ package manager)
   - ninja (build system)
   - ccache (recommended for faster builds)
3. **Version Control**: git
4. **Python**: Python 3.12+ (for Python bindings and scripts)

### Initial Setup

1. **Clone the repository**:
   ```bash
   git clone https://github.com/falcon-autotuning/falcon-core.git
   cd falcon-core
   ```

2. **Install vcpkg** (if not already installed):
   ```bash
   # Follow instructions at:
   # https://learn.microsoft.com/en-us/vcpkg/get_started/overview
   ```

3. **Build the C++ core**:
   ```bash
   cd cpp
   make clean-all
   make all
   ```

4. **Build the C API**:
   ```bash
   cd ../c-api
   make all
   ```

## Development Workflow

### Making Changes

1. **Create a feature branch**:
   ```bash
   git checkout -b feature/your-feature-name
   ```

2. **Make your changes** in the appropriate directory:
   - C++ core: `cpp/`
   - C API: `c-api/`
   - Python: `src/falcon_core/`
   - Documentation: `docs/`

3. **Build and test frequently**:
   ```bash
   # In cpp/ or c-api/
   make build
   make test
   ```

4. **Format your code**:
   ```bash
   # Code is auto-formatted using .clang-format
   clang-format -i path/to/file.cpp
   ```

### Testing

#### C++ Tests

```bash
cd cpp
make test                    # Run all tests
make test-verbose            # Run with verbose output
make build-and-sanitize      # Build with sanitizers
```

#### C API Tests

```bash
cd c-api
make test
```

#### Python Tests

```bash
cd src
python -m pytest
```

### Code Coverage

Check test coverage:

```bash
cd cpp
make coverage-overview       # View coverage summary
make coverage-detailed       # View detailed coverage
```

### Debugging

#### Using Sanitizers

For memory issues and undefined behavior:

```bash
cd cpp
make build-and-sanitize
```

This enables:
- AddressSanitizer (memory errors)
- UndefinedBehaviorSanitizer (UB detection)
- LeakSanitizer (memory leaks)

#### Using GDB

```bash
cd cpp/build
gdb ./test_executable
```

Common GDB commands:
```
(gdb) break main
(gdb) run
(gdb) step
(gdb) print variable
(gdb) backtrace
```

### Partial Builds

To build only specific files (faster iteration):

```bash
cd cpp
make build-part DIRS="src/specific_file.cpp" TESTS="tests/specific_test.cpp"
```

## Coding Standards

### C++ Style

- **Standard**: C++14
- **Formatting**: Enforced by `.clang-format`
- **Naming**:
  - Classes: `PascalCase`
  - Functions: `snake_case`
  - Variables: `snake_case`
  - Constants: `SCREAMING_SNAKE_CASE`
  - Private members: `snake_case_` (trailing underscore)

### C API Style

- **Types**: `FalconTypeName` (PascalCase)
- **Functions**: `falcon_module_action` (snake_case with prefix)
- **Constants**: `FALCON_CONSTANT_NAME`
- **Enums**: `FalconEnumName` for type, `FALCON_ENUM_VALUE` for values

### Documentation

#### C++ Documentation (Doxygen)

All public APIs must have Doxygen comments:

```cpp
/**
 * @brief Brief description of the function
 * 
 * Detailed description of what the function does,
 * its purpose, and any important notes.
 * 
 * @param param_name Description of parameter
 * @param another_param Description of another parameter
 * @return Description of return value
 * @throws ExceptionType When this exception is thrown
 * 
 * @code
 * // Example usage
 * MyClass obj;
 * obj.my_function(10, "test");
 * @endcode
 */
int my_function(int param_name, const char* another_param);
```

#### C API Documentation

C API documentation is auto-generated from C++ documentation. Ensure the C++ documentation is complete and accurate.

For special cases, add manual mappings in:
```
code_docs/capi_docs/c-api_user_maps/
```

#### Python Documentation

Use Python docstrings (Google style):

```python
def my_function(param1: int, param2: str) -> bool:
    """Brief description of function.
    
    Detailed description of what the function does.
    
    Args:
        param1: Description of param1
        param2: Description of param2
        
    Returns:
        Description of return value
        
    Raises:
        ValueError: When this error is raised
        
    Example:
        >>> my_function(10, "test")
        True
    """
    pass
```

## Documentation Generation

### Generate C API Documentation

```bash
# From repository root
make -f code_docs/capi_docs/capi_docs.mk docs-all
```

This runs:
1. Extract C++ documentation
2. Generate mappings
3. Inject documentation into C API
4. Report coverage

### Check Documentation Coverage

```bash
make -f code_docs/capi_docs/capi_docs.mk docs-coverage
```

## Building Documentation Website

### Setup MkDocs

```bash
pip install mkdocs mkdocs-material
```

### Build and Serve

```bash
# Serve locally
mkdocs serve

# Build static site
mkdocs build
```

Visit http://localhost:8000 to view the documentation.

## Common Tasks

### Adding a New C++ Class

1. Create header in `cpp/include/`
2. Add Doxygen documentation
3. Implement in `cpp/src/`
4. Add tests in `cpp/tests/`
5. Build and test:
   ```bash
   cd cpp
   make build
   make test
   ```

### Adding a New C API Function

1. Implement in C++ first (if not already done)
2. Add C wrapper in `c-api/include/`
3. Implement wrapper in `c-api/src/`
4. Add tests in `c-api/tests/`
5. Run documentation pipeline:
   ```bash
   make -f code_docs/capi_docs/capi_docs.mk docs-all
   ```
6. Build and test:
   ```bash
   cd c-api
   make build
   make test
   ```

### Adding Python Bindings

1. Create Python module in `src/falcon_core/`
2. Use C API via ctypes or cffi
3. Add docstrings
4. Add tests
5. Install and test:
   ```bash
   pip install -e src/
   python -m pytest src/tests/
   ```

## Git Workflow

### Commit Messages

Follow conventional commits:

```
type(scope): brief description

Detailed explanation of the changes.

Fixes #123
```

Types:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting)
- `refactor`: Code refactoring
- `test`: Adding or updating tests
- `chore`: Maintenance tasks

### Pull Request Process

1. **Create PR** with clear description
2. **Link issues** using "Fixes #123"
3. **Ensure CI passes** (all tests, linting)
4. **Request review** from maintainers
5. **Address feedback**
6. **Merge** when approved

## CI/CD

### GitHub Actions

The repository uses GitHub Actions for:
- Building C++ and C API
- Running tests
- Checking code coverage
- Linting and formatting
- Documentation generation

### Local CI Check

Before pushing, verify locally:

```bash
# Build all
cd cpp && make all && cd ..
cd c-api && make all && cd ..

# Run all tests
cd cpp && make test && cd ..
cd c-api && make test && cd ..

# Check documentation
make -f code_docs/capi_docs/capi_docs.mk docs-all
```

## Best Practices

### Performance

1. **Use const references** for large objects
2. **Enable compiler optimizations** in release builds
3. **Profile before optimizing** using tools like `perf`
4. **Use ccache** for faster compilation
5. **Avoid premature optimization**

### Memory Management

1. **Use RAII** for resource management
2. **Prefer smart pointers** over raw pointers
3. **Run sanitizers** to catch memory issues
4. **Check for leaks** regularly

### Error Handling

1. **Use exceptions** in C++ for exceptional cases
2. **Use return codes** in C API
3. **Document exceptions** in Doxygen
4. **Provide meaningful error messages**

### Testing

1. **Write tests first** (TDD when appropriate)
2. **Test edge cases** and error conditions
3. **Keep tests fast** for quick iteration
4. **Use descriptive test names**
5. **Aim for high coverage** (>80%)

## Troubleshooting

### Build Issues

```bash
# Clean everything
make clean-all

# Rebuild from scratch
make all
```

### Test Failures

```bash
# Run with verbose output
make test-verbose

# Run specific test
./build/tests/specific_test
```

### Documentation Issues

```bash
# Check logs
cat code_docs/capi_docs/logs/inject_c_docs.log

# Clean and regenerate
make -f code_docs/capi_docs/capi_docs.mk docs-clean
make -f code_docs/capi_docs/capi_docs.mk docs-all
```

## Resources

- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [Doxygen Documentation](https://www.doxygen.nl/)
- [vcpkg Documentation](https://learn.microsoft.com/en-us/vcpkg/)
- [CMake Documentation](https://cmake.org/documentation/)
- [MkDocs Documentation](https://www.mkdocs.org/)

## Getting Help

- **Documentation**: Read this guide and other docs in `docs/`
- **Issues**: Open an issue on GitHub
- **Discussions**: Use GitHub Discussions for questions
- **Code Review**: Request review from maintainers
