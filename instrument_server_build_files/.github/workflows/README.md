# GitHub Workflows

This directory contains CI/CD workflows for the Instrument Script Server project.

## Workflows

### 1. Arch Linux Build and Test (`arch-linux.yml`)

**Trigger:** Push to main, pull requests, manual dispatch, or called by other workflows

**Purpose:** Build and test the project on Arch Linux

**Steps:**
1. Sets up Arch Linux container on Ubuntu runner
2. Installs all required dependencies (clang, cmake, ninja, lua, **boost**, etc.)
3. Installs sol2 header-only library from source (v3.3.0)
4. Runs `make clean` to ensure clean build
5. Runs `make build` to compile the project
6. Runs `make unit-test` to execute unit tests
7. Runs `make integration-tests` to execute integration tests
8. Uploads build artifacts (binaries + LICENSE)

**Optimizations:**
- Caches Pacman packages to speed up dependency installation

**Key Fix:**
- sol2 is not available in Arch repos, so it's cloned from GitHub
- Boost is required for Boost.Interprocess used in SharedQueue

### 2. Windows Build and Test (`windows.yml`)

**Trigger:** Push to main, pull requests, manual dispatch, or called by other workflows

**Purpose:** Build and test natively on Windows using MSYS2

**Steps:**
1. Uses Windows runner with MSYS2 environment
2. Installs MinGW64 toolchain and all dependencies (including **Boost**)
3. Installs sol2 header-only library from source (v3.3.0)
4. Builds with CMake and Ninja
5. Runs unit tests and validates exit codes
6. Runs integration tests and validates exit codes
7. Packages binaries with LICENSE
8. Uploads Windows package for release

**Optimizations:**
- Caches MSYS2 packages for faster builds
- Uses exit codes for reliable test validation

**Key Changes:**
- Simplified to native Windows build only (removed cross-compilation complexity)
- sol2 installed from source since not in MSYS2 repos
- Boost installed for Boost.Interprocess support
- Uses exit codes instead of grep patterns for test validation

### 3. Release (`release.yml`)

**Trigger:** Push to main, tags starting with 'v*', or manual dispatch

**Purpose:** Create GitHub releases with compiled binaries for all platforms

**Dependencies:**
- Calls `arch-linux.yml` workflow with `contents: read` permission
- Calls `windows.yml` workflow with `contents: read` permission
- Only proceeds if both workflows succeed

**Steps:**
1. Downloads Arch Linux binaries artifact
2. Downloads Windows binaries artifact
3. Creates platform-specific archives:
   - `instrument-server-arch-linux-x64.tar.gz`
   - `instrument-server-windows-x64.zip`
4. Generates release notes with installation instructions
5. Creates GitHub release with:
   - Platform archives
   - LICENSE file
   - Installation instructions

**Release Behavior:**
- Tags starting with 'v*': Creates proper release
- Push to main: Creates draft/prerelease for testing
- Manual dispatch: Creates release based on current ref

**Key Fix:**
- Reusable workflows now properly inherit `contents: read` permission from caller

## Artifacts

All workflows upload artifacts that are accessible from the GitHub Actions UI:

- **arch-linux-binaries**: Compiled binaries for Arch Linux (7 days retention)
- **windows-binaries**: Native Windows binaries (7 days retention)

## Testing Strategy

The workflows ensure quality through:

1. **Arch Linux**: Native build and test using Makefile targets
2. **Windows**: Native build and test with MSYS2, validates exit codes
3. **Release**: Only creates releases if all platform tests pass

## Dependencies

### Arch Linux
- base-devel, git, cmake, ninja
- clang, lld, llvm
- lua, luajit
- spdlog, nlohmann-json, yaml-cpp
- gtest
- **boost** (for Boost.Interprocess)
- sol2 (installed from source)

### Windows (MSYS2/MinGW64)
- cmake, ninja, gcc
- lua, luajit
- spdlog, nlohmann-json, yaml-cpp
- gtest
- **boost** (for Boost.Interprocess)
- sol2 (installed from source)

## Caching

Workflows cache dependency packages to improve build times:

- **Arch Linux**: `/var/cache/pacman/pkg`
- **Windows**: MSYS2 package cache and mingw64 directory

Cache keys are based on workflow file hashes to invalidate when dependencies change.

## Testing Workflows Locally

See [TESTING.md](TESTING.md) for detailed instructions on how to test workflows locally before pushing changes.

Quick summary:
- **Arch Linux**: `docker run --rm -v $(pwd):/workspace -w /workspace archlinux:latest bash /workspace/.github/workflows/test-arch.sh`
- **Windows**: Run `test-windows.sh` from MSYS2 MinGW 64-bit shell

## Known Issues & Solutions

### Boost.Interprocess Dependency
The code uses Boost.Interprocess for shared memory IPC. Both workflows now install the Boost library.

### sol2 Installation
sol2 is a header-only library that's not available in standard package repositories. Both workflows clone it directly from GitHub (v3.3.0) and copy headers to the appropriate include directory.

### Reusable Workflow Permissions
GitHub Actions requires reusable workflows to explicitly inherit permissions. The release workflow now passes `permissions: contents: read` to called workflows.

### Windows Cross-Compilation
Initial cross-compilation approach was complex and had missing dependencies. Simplified to native Windows builds using MSYS2 for reliability.

## Future Improvements

Potential enhancements:
- Add macOS build workflow
- Implement code coverage reporting
- Add static analysis (cppcheck, clang-tidy)
- Create Docker images as artifacts
- Add performance regression testing
