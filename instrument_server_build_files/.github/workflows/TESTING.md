# Workflow Testing Guide

This document explains how to test the GitHub Actions workflows locally before pushing changes.

## Testing Arch Linux Workflow

To test the Arch Linux workflow locally, you need Docker installed:

```bash
docker run --rm -v $(pwd):/workspace -w /workspace archlinux:latest bash /workspace/.github/workflows/test-arch.sh
```

This will:
1. Update the Arch Linux system
2. Install all dependencies (including Boost)
3. Install sol2 from source
4. Build the project with make
5. Run unit and integration tests

## Testing Windows Workflow

To test the Windows workflow, you need MSYS2 installed on Windows:

1. Install MSYS2 from https://www.msys2.org/
2. Open MSYS2 MinGW 64-bit shell
3. Navigate to the repository
4. Run: `bash .github/workflows/test-windows.sh`

This will:
1. Verify MSYS2 environment
2. Install dependencies (Boost, sol2, etc.)
3. Build with CMake and Ninja
4. Run tests with exit code validation
5. Package binaries

## Key Dependencies Added

Both workflows now install:
- **Boost**: Required for Boost.Interprocess used in SharedQueue
- **sol2**: Header-only Lua binding library (installed from source)

## Validation Checklist

Before committing workflow changes:

- [ ] YAML syntax is valid (`python3 -c "import yaml; yaml.safe_load(open('file.yml'))"`)
- [ ] All dependencies are listed (Boost, sol2, etc.)
- [ ] Permissions are correctly set for reusable workflows
- [ ] Test scripts execute without errors
- [ ] Exit codes are properly checked for test validation

## Changes Made

1. **Fixed permissions issue**: Reusable workflows now have `permissions: contents: read` inherited from caller
2. **Added Boost dependency**: Both Arch and Windows workflows install Boost
3. **Validated workflows**: Created test scripts to verify workflow steps
