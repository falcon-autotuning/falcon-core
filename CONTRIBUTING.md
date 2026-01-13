# Contributing to Falcon Core

Thank you for your interest in contributing to Falcon Core! This document provides guidelines and instructions for contributing.

## Code of Conduct

We are committed to providing a welcoming and inclusive environment. Please be respectful and professional in all interactions.

## How to Contribute

### Reporting Issues

If you find a bug or have a feature request:

1. **Check existing issues** to avoid duplicates
2. **Create a new issue** with a clear title and description
3. **Include details**:
   - Steps to reproduce (for bugs)
   - Expected vs actual behavior
   - Your environment (OS, compiler version, etc.)
   - Relevant logs or error messages

### Proposing Changes

For significant changes:

1. **Open an issue** to discuss the change before implementing
2. **Get feedback** from maintainers
3. **Implement** once the approach is agreed upon

### Submitting Pull Requests

1. **Fork the repository** and create a feature branch
   ```bash
   git checkout -b feature/your-feature-name
   ```

2. **Make your changes** following our coding standards (see below)

3. **Write tests** for your changes

4. **Update documentation** as needed

5. **Ensure all tests pass**:
   ```bash
   cd cpp && make test
   cd ../c-api && make test
   ```

6. **Run the documentation pipeline** if you changed APIs:
   ```bash
   make -f code_docs/capi_docs/capi_docs.mk docs-all
   ```

7. **Commit your changes** with clear, descriptive commit messages:
   ```
   type(scope): brief description
   
   Detailed explanation of changes
   ```

8. **Push to your fork** and create a pull request

9. **Respond to feedback** from reviewers

## Development Setup

See the [Developer Guide](docs/developer-guide.md) for detailed setup instructions.

Quick start:
```bash
# Clone the repository
git clone https://github.com/falcon-autotuning/falcon-core.git
cd falcon-core

# Build C++ core
cd cpp
make clean-all
make all

# Build C API
cd ../c-api
make all
```

## Coding Standards

### C++ Code

- **Standard**: C++14
- **Formatting**: Use `.clang-format` configuration
  ```bash
  clang-format -i path/to/file.cpp
  ```
- **Naming Conventions**:
  - Classes: `PascalCase`
  - Functions/variables: `snake_case`
  - Constants: `SCREAMING_SNAKE_CASE`
  - Private members: `snake_case_` (trailing underscore)

### C API Code

- **Types**: `FalconTypeName` (PascalCase)
- **Functions**: `falcon_module_action` (snake_case with prefix)
- **Constants**: `FALCON_CONSTANT_NAME`

### Python Code

- **Standard**: PEP 8
- **Type hints**: Use type annotations
- **Docstrings**: Google style

## Documentation

All public APIs must be documented:

### C++ (Doxygen)

```cpp
/**
 * @brief Brief description
 * 
 * Detailed description.
 * 
 * @param param Description
 * @return Description
 */
```

### Python (Docstrings)

```python
def function(param: int) -> bool:
    """Brief description.
    
    Detailed description.
    
    Args:
        param: Description
        
    Returns:
        Description
    """
```

## Testing

- Write unit tests for all new functionality
- Ensure existing tests still pass
- Aim for high test coverage (>80%)

Run tests:
```bash
# C++ tests
cd cpp
make test

# C API tests
cd c-api
make test

# Python tests
cd src
python -m pytest
```

## Documentation Changes

When updating documentation:

1. Edit markdown files in `docs/`
2. Test locally with MkDocs:
   ```bash
   mkdocs serve
   ```
3. Verify formatting and links work correctly

## Review Process

1. **Automated checks** must pass (CI/CD)
2. **Code review** by at least one maintainer
3. **Address feedback** and update PR
4. **Approval** required before merging
5. **Squash merge** preferred to keep history clean

## What to Contribute

We welcome contributions in many forms:

- **Bug fixes**
- **New features** (discuss first via issue)
- **Performance improvements**
- **Documentation improvements**
- **Test additions**
- **Code refactoring**
- **Examples and tutorials**

## Getting Help

- **Documentation**: Read the docs in `docs/`
- **Issues**: Ask questions via GitHub issues
- **Discussions**: Use GitHub Discussions for broader questions

## License

By contributing, you agree that your contributions will be licensed under the BSD 3-Clause License. See [LICENSE.txt](LICENSE.txt) for details.

## Recognition

Contributors will be recognized in:
- Git commit history
- Release notes (for significant contributions)
- Project README (for major contributors)

## Questions?

If you have questions about contributing, feel free to:
- Open an issue with the question
- Ask in GitHub Discussions
- Contact the maintainers

Thank you for contributing to Falcon Core!
