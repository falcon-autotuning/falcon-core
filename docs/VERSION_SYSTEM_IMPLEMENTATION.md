# Falcon Core Version System and GitHub Workflow Updates

This document summarizes the implementation of a comprehensive version system and GitHub workflow improvements for the Falcon Core project.

## Overview

The following features have been implemented:

1. **Version System** - Complete version tracking for both C++ core and C-API libraries
2. **GitHub Workflow Fixes** - Proper tag handling instead of commit hashes for releases
3. **Command-line Version Utility** - Cross-platform `falcon_core_info` utility with `--version` support
4. **Git Integration** - Automatic Git commit and tag information in builds

## 🚀 Features Implemented

### 1. C++ Core Library Version System

**Files Added/Modified:**
- `cpp/include/falcon_core/version.hpp` - Version API declarations
- `cpp/src/version.cpp` - Version implementation
- `cpp/CMakeLists.txt` - Git version detection and compile definitions

**API Functions:**
```cpp
namespace falcon_core {
    std::string get_version();        // "1.0.0" or "1.0.0-v1.1.0" 
    std::string get_git_commit();     // Git commit hash
    std::string get_git_tag();        // Git tag if available
    std::string get_full_version();   // "1.0.0 (commit abc1234)"
}
```

### 2. C-API Library Version System

**Files Added/Modified:**
- `c-api/include/falcon_core/version_c_api.h` - C version API declarations
- `c-api/src/falcon_core/version_c_api.cpp` - C version implementation  
- `c-api/CMakeLists.txt` - Git version detection and compile definitions

**API Functions:**
```c
const char* falcon_core_c_api_get_version(void);
const char* falcon_core_c_api_get_git_commit(void);
const char* falcon_core_c_api_get_git_tag(void);
const char* falcon_core_c_api_get_full_version(void);
const char* falcon_core_cpp_get_version(void);      // Access C++ version from C
const char* falcon_core_cpp_get_full_version(void); // Access C++ full version from C
```

### 3. Command-Line Version Utility

**Files Added:**
- `utils/falcon_core_info.cpp` - Cross-platform version utility

**Usage:**
```bash
# Default: Show brief version info
./falcon_core_info

# Show version information  
./falcon_core_info --version
./falcon_core_info -v

# Show detailed version with Git info
./falcon_core_info --full

# Show specific library versions
./falcon_core_info --cpp-version
./falcon_core_info --c-api-version

# Show help
./falcon_core_info --help
./falcon_core_info -h
```

**Sample Output:**
```
$ ./falcon_core_info --full
Falcon Core Libraries - Full Version Information:
================================================
C++ Core Library:
  Version:     1.0.0
  Git Commit:  a1b2c3d4e5f6789
  Git Tag:     v1.0.0
  Full:        1.0.0 (commit a1b2c3d)

C-API Library:
  Version:     1.0.0
  Git Commit:  a1b2c3d4e5f6789
  Git Tag:     v1.0.0
  Full:        1.0.0 (commit a1b2c3d)
```

### 4. GitHub Workflow Improvements

**Files Modified:**
- `.github/workflows/create-release.yml` - Fixed to use actual Git tags

**Behavior:**
- **Tag Push** (e.g., `git push origin v1.2.0`): Creates release with tag `v1.2.0`
- **Regular Push**: Creates release with commit hash (e.g., `abc1234`)

## 🛠 How It Works

### Git Version Detection

The CMake configuration automatically detects:
1. **Git Commit Hash**: Full SHA of current commit
2. **Git Tag**: If current commit is tagged or nearest tag
3. **Project Version**: From CMake `project(VERSION x.y.z)`

### Build-Time Integration

During build, CMake injects Git information as compile-time definitions:
```cmake
target_compile_definitions(
  library_target
  PRIVATE
  FALCON_CORE_VERSION="${FALCON_CORE_VERSION}"
  FALCON_CORE_GIT_COMMIT="${FALCON_CORE_GIT_COMMIT}"
  FALCON_CORE_GIT_TAG="${FALCON_CORE_GIT_TAG}")
```

### Cross-Platform Compatibility

- **Linux**: Uses visibility attributes for proper symbol export
- **Windows**: Uses `__declspec(dllexport/dllimport)` for DLL compatibility
- **C Interface**: Thread-safe static buffers for C string returns

## 📋 Usage Examples

### In C++ Code

```cpp
#include <falcon_core/version.hpp>
#include <iostream>

int main() {
    std::cout << "Falcon Core C++ Version: " 
              << falcon_core::get_full_version() << std::endl;
    return 0;
}
```

### In C Code

```c
#include <falcon_core/version_c_api.h>
#include <stdio.h>

int main() {
    printf("Falcon Core C-API Version: %s\n", 
           falcon_core_c_api_get_full_version());
    printf("Underlying C++ Version: %s\n",
           falcon_core_cpp_get_full_version());
    return 0;
}
```

### Version Command Integration

Applications can now easily add `--version` support:

```cpp
if (command == "--version" || command == "-v") {
    std::cout << "my-app " << falcon_core::get_full_version() << std::endl;
    return 0;
}
```

## 🚀 Release Process

### Creating a Version Release

1. **Ensure all changes are committed**
2. **Create and push a tag:**
   ```bash
   git tag -a v1.2.0 -m "Release v1.2.0 with enhanced version system"
   git push origin v1.2.0
   ```
3. **GitHub Actions automatically:**
   - Detects the tag push
   - Runs full CI/CD pipeline
   - Creates GitHub release with tag name `v1.2.0` (not commit hash)
   - Builds and uploads cross-platform artifacts

### Verification

After release:
```bash
# Build and test version info
cd c-api && make all
./build/falcon_core_info --full

# Expected output includes tag information
# Version: 1.0.0 (if tagged) or 1.0.0-v1.2.0 (if tag differs)
# Git Tag: v1.2.0
# Git Commit: abc1234...
```

## 🔧 Build Requirements

- **Git**: Required for version detection (`find_package(Git QUIET)`)
- **CMake 3.14+**: For C-API builds
- **CMake 3.20+**: For C++ core builds
- **C++14**: Standard requirement
- **Cross-platform**: Windows (clang-cl, MSVC) and Linux (clang, gcc)

## 📁 File Structure Summary

```
falcon-core/
├── cpp/
│   ├── include/falcon_core/
│   │   └── version.hpp              # C++ version API
│   ├── src/
│   │   └── version.cpp              # C++ version implementation
│   └── CMakeLists.txt               # Git detection + compile definitions
├── c-api/
│   ├── include/falcon_core/
│   │   └── version_c_api.h          # C version API
│   ├── src/falcon_core/
│   │   └── version_c_api.cpp        # C version implementation
│   └── CMakeLists.txt               # Git detection + compile definitions
├── utils/
│   └── falcon_core_info.cpp         # Command-line version utility
└── .github/workflows/
    ├── main-pipeline.yml            # Tag triggers (already configured)
    └── create-release.yml           # Fixed tag handling
```

## 🎯 Expected Behaviors

### Version Output Examples

- **On tagged commit**: `falcon-core 1.0.0 (commit abc1234)`
- **With different tag**: `falcon-core 1.0.0-v1.2.0 (commit abc1234)`  
- **No git info**: `falcon-core unknown`

### Workflow Behavior

- **Tag push** → Release named with tag (e.g., `v1.2.0`)
- **Regular push** → Release named with commit hash (e.g., `abc1234`)

## 🏁 Summary

This implementation provides:

- ✅ **Complete version system** for both C++ and C-API libraries
- ✅ **Cross-platform compatibility** (Linux + Windows)  
- ✅ **Command-line version utility** with `--version` support
- ✅ **Git integration** with automatic commit/tag detection
- ✅ **Fixed GitHub workflows** using proper Git tags
- ✅ **Thread-safe C interface** with static buffer management
- ✅ **CMake integration** with build-time version injection

The system is ready for production use and follows industry best practices for version management in C/C++ libraries.