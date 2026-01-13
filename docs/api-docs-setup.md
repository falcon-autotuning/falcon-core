# API Documentation Integration

This guide explains how to integrate auto-generated API documentation into the MkDocs website.

## Overview

The Falcon Core API documentation is generated from Doxygen comments in the source code. To display this on the documentation website, you can use the `mkdoxy` plugin for MkDocs.

## Setup

### 1. Install Required Tools

```bash
# Install Doxygen
sudo apt install doxygen  # On Linux
brew install doxygen      # On macOS

# Install MkDocs plugins
pip install mkdocs-material mkdoxy
```

### 2. Configure MkDocs

Update `mkdocs.yml` to add the mkdoxy plugin:

```yaml
plugins:
  - search
  - mkdoxy:
      projects:
        cpp-core:
          src-dirs: cpp/include
          full-doc: true
        c-api:
          src-dirs: c-api/include
          full-doc: true
```

### 3. Add API Reference to Navigation

Uncomment the API Reference section in `mkdocs.yml`:

```yaml
nav:
  - Home: index.md
  - Getting Started:
      - Installation: installation.md
      - Developer Guide: developer-guide.md
  - Architecture:
      - C++ Core: cpp-core.md
      - C API: c-api.md
      - Documentation Generation: code-docs.md
  - API Reference:
      - C++ API: cpp-core/
      - C API: c-api/
```

### 4. Build Documentation

```bash
mkdocs build
```

The API documentation will be automatically generated from the Doxygen comments in the source code and integrated into the website.

## Alternative: Standalone Doxygen

If you prefer to use standalone Doxygen (without MkDocs integration):

### 1. Create Doxyfile

```bash
cd cpp
doxygen -g Doxyfile
```

Edit the Doxyfile to configure:
```
PROJECT_NAME = "Falcon Core C++ API"
INPUT = include/
RECURSIVE = YES
GENERATE_HTML = YES
OUTPUT_DIRECTORY = ../docs/cpp-api
```

### 2. Generate Documentation

```bash
cd cpp
doxygen Doxyfile
```

### 3. Link to Documentation

The generated HTML will be in `docs/cpp-api/html/`. You can link to it from your website or serve it separately.

## C API Documentation

The C API documentation follows the same process but uses the `c-api/include` directory:

```bash
cd c-api
doxygen -g Doxyfile
# Edit Doxyfile with OUTPUT_DIRECTORY = ../docs/c-api
doxygen Doxyfile
```

## Viewing API Documentation

After generation, you can:
- Serve with MkDocs: `mkdocs serve`
- Open HTML directly: `docs/cpp-api/html/index.html`
- Deploy to website along with other documentation

## Continuous Integration

For automated documentation generation on every commit:

1. Add a GitHub Actions workflow (`.github/workflows/docs.yml`)
2. Install Doxygen and MkDocs in the CI environment
3. Run `mkdocs build` or `doxygen` commands
4. Deploy to GitHub Pages or your hosting platform

## References

- [Doxygen Documentation](https://www.doxygen.nl/manual/)
- [mkdoxy Plugin](https://github.com/JakubAndrysek/mkdoxy)
- [MkDocs Material](https://squidfunk.github.io/mkdocs-material/)
