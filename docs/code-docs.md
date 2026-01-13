# Documentation Generation

Falcon Core uses an automated documentation generation pipeline to keep the C API documentation synchronized with the C++ core documentation.

## Overview

The documentation system automatically:
1. Extracts Doxygen comments from C++ headers
2. Maps C++ symbols to their C API equivalents
3. Injects documentation into C API headers
4. Tracks documentation coverage

This ensures that the C API documentation stays consistent with the C++ core as the codebase evolves.

## Pipeline Architecture

```
┌─────────────────┐
│  C++ Headers    │
│  with Doxygen   │
└────────┬────────┘
         │
         ▼
┌─────────────────────────┐
│  Extract Documentation  │
│  (extract_cpp_docs.py)  │
└────────┬────────────────┘
         │
         ▼
┌─────────────────────────┐
│   C++ Metadata Files    │
│  (cpp_metadata/*.json)  │
└────────┬────────────────┘
         │
         ▼
┌─────────────────────────┐
│  Generate Mappings      │
│  (generate_c_api_maps)  │
└────────┬────────────────┘
         │
         ▼
┌─────────────────────────┐
│   Mapping Files         │
│  (*.map.yml)            │
└────────┬────────────────┘
         │
         ▼
┌─────────────────────────┐
│  Inject Documentation   │
│  (inject_c_docs.py)     │
└────────┬────────────────┘
         │
         ▼
┌─────────────────────────┐
│  C API Headers          │
│  with Documentation     │
└─────────────────────────┘
```

## Directory Structure

```
code_docs/
└── capi_docs/
    ├── scripts/                      # Documentation generation scripts
    │   ├── extract_cpp_docs.py       # Extract Doxygen from C++
    │   ├── generate_c_api_maps.py    # Generate mapping files
    │   ├── inject_c_docs.py          # Inject docs into C API
    │   ├── doxygen_port_coverage.py  # Coverage reporting
    │   └── ...
    ├── cpp_metadata/                 # Extracted C++ documentation
    ├── c-api_user_maps/              # Manual mapping overrides
    ├── archive/                      # Archived c-api versions
    │   └── c-api_no_docs/           # Pristine c-api without docs
    ├── logs/                         # Pipeline execution logs
    └── capi_docs.mk                  # Makefile for pipeline
```

## Components

### 1. Documentation Extraction

**Script**: `extract_cpp_docs.py`

Parses C++ header files and extracts Doxygen comments into structured metadata files.

**Input**: C++ headers in `cpp/include/`
**Output**: JSON metadata files in `code_docs/capi_docs/cpp_metadata/`

**Features**:
- Parses Doxygen comment blocks
- Extracts function signatures, parameters, return values
- Handles classes, structs, enums, and functions
- Preserves documentation structure

### 2. Mapping Generation

**Script**: `generate_c_api_maps.py`

Creates mapping files that link C++ symbols to their C API equivalents.

**Input**: 
- C++ metadata from step 1
- C API headers in `c-api/include/`

**Output**: `.map.yml` files in `c-api/include/falcon_core/`

**Features**:
- Auto-detects C API functions corresponding to C++ methods
- Uses naming conventions to match symbols
- Generates YAML mapping files
- Supports manual overrides via `c-api_user_maps/`

### 3. Documentation Injection

**Script**: `inject_c_docs.py`

Injects the extracted C++ documentation into C API headers.

**Input**:
- C++ metadata
- Mapping files
- C API headers

**Output**: Updated C API headers with documentation

**Features**:
- Translates C++ documentation to C API context
- Preserves existing manual documentation
- Handles parameter name differences
- Generates appropriate Doxygen comments for C

### 4. Coverage Reporting

**Script**: `doxygen_port_coverage.py`

Tracks documentation coverage and porting progress.

**Features**:
- Calculates percentage of documented functions
- Identifies missing documentation
- Compares C++ and C API documentation
- Generates coverage reports

## Usage

### Running the Full Pipeline

From the repository root:

```bash
make -f code_docs/capi_docs/capi_docs.mk docs-all
```

This runs:
1. `docs-setup` - Prepares a clean c-api directory
2. `docs-run` - Executes the extraction, mapping, and injection
3. `docs-coverage` - Reports documentation coverage

### Running Individual Steps

```bash
# Setup: Backup current c-api and restore pristine version
make -f code_docs/capi_docs/capi_docs.mk docs-setup

# Run: Execute the documentation generation pipeline
make -f code_docs/capi_docs/capi_docs.mk docs-run

# Coverage: Check documentation coverage
make -f code_docs/capi_docs/capi_docs.mk docs-coverage

# Clean: Remove logs and backups
make -f code_docs/capi_docs/capi_docs.mk docs-clean
```

### Logs

Pipeline execution logs are saved in:
```
code_docs/capi_docs/logs/
├── extract_cpp_docs.log
├── generate_c_api_maps.log
└── inject_c_docs.log
```

## Configuration

### Paths

Key paths are configured in `capi_docs.mk`:

```makefile
CPP_ROOT              := ./cpp
C_API_ROOT            := ./c-api
CPP_METADATA_ROOT     := ./code_docs/capi_docs/cpp_metadata
USER_MAPS_DIR         := ./code_docs/capi_docs/c-api_user_maps
```

### Manual Mappings

For cases where auto-detection fails, create manual mapping files in:
```
code_docs/capi_docs/c-api_user_maps/
```

Format (YAML):
```yaml
# Manual mapping for specific function
cpp_function: "ClassName::method_name"
c_function: "falcon_class_method_name"
parameter_mappings:
  cpp_param: c_param
```

## Integration with Website

The generated C API documentation can be integrated into the website in several ways:

### 1. Doxygen HTML Generation

Generate HTML documentation from C API headers:
```bash
cd c-api
doxygen Doxyfile
```

### 2. MkDocs Integration

Include C API reference in MkDocs:

```yaml
# mkdocs.yml
nav:
  - Home: index.md
  - C API Reference: c-api.md
  - API Documentation: api/
```

### 3. Auto-generated Reference Pages

Use tools like `mkdoxy` or `breathe` to convert Doxygen to MkDocs format:

```bash
# Install mkdoxy
pip install mkdoxy

# Configure in mkdocs.yml
plugins:
  - mkdoxy:
      projects:
        c-api:
          src-dirs: c-api/include
```

## Maintenance

### Updating Documentation

When C++ documentation changes:
1. Run the pipeline to regenerate C API docs
2. Review the changes
3. Commit updated C API headers

### Adding New Functions

When adding new C API functions:
1. Add Doxygen comments to the C++ source
2. Implement the C API wrapper
3. Run the pipeline to generate documentation
4. Verify the mapping is correct
5. Add manual mapping if needed

### Troubleshooting

**Issue**: Documentation not appearing in C API
- Check that C++ function has Doxygen comments
- Verify mapping exists in `.map.yml` files
- Check logs in `code_docs/capi_docs/logs/`

**Issue**: Incorrect parameter names
- Update mapping file with correct parameter names
- Re-run the injection step

**Issue**: Coverage is low
- Add Doxygen comments to C++ functions
- Update mapping files for unmapped functions
- Run coverage report to identify gaps

## Best Practices

1. **Document C++ First**: Always write documentation in C++ headers
2. **Use Doxygen Format**: Follow Doxygen comment conventions
3. **Run Pipeline Regularly**: Keep C API docs synchronized
4. **Review Generated Docs**: Verify documentation makes sense in C context
5. **Manual Overrides**: Use user maps for special cases only
6. **Test Generated Docs**: Build and view documentation locally

## Future Enhancements

Planned improvements to the documentation system:

- Automatic website deployment of C API docs
- Interactive API explorer
- Code examples in documentation
- Multi-language documentation (C++, C, Python)
- Documentation versioning for releases
