# MinGW cross-compilation toolchain for Windows
# This file is a template; the build script will substitute variables marked with @...@

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# MinGW toolchain
set(MINGW_SYSROOT @MINGW_SYSROOT@)
set(CMAKE_SYSROOT ${MINGW_SYSROOT})

# Compilers - using clang with MinGW target
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Target triple for MinGW
set(target x86_64-w64-mingw32)

# Compiler flags for cross-compilation
set(CMAKE_C_COMPILER_TARGET ${target})
set(CMAKE_CXX_COMPILER_TARGET ${target})

# Additional flags for MinGW compatibility
set(CMAKE_C_FLAGS_INIT "@MINGW_GCC_TOOLCHAIN_FLAG@ -fuse-ld=lld")
set(CMAKE_CXX_FLAGS_INIT "@MINGW_GCC_TOOLCHAIN_FLAG@ -fuse-ld=lld")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS_INIT "@MINGW_GCC_LDFLAGS@")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "@MINGW_GCC_LDFLAGS@")
set(CMAKE_MODULE_LINKER_FLAGS_INIT "@MINGW_GCC_LDFLAGS@")

# Search paths
set(CMAKE_FIND_ROOT_PATH ${MINGW_SYSROOT})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Windows-specific settings
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_SUFFIX ".dll")
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")
set(CMAKE_EXECUTABLE_SUFFIX ".exe")

# Disable vcpkg for cross-compilation (use system MinGW packages)
set(USE_VCPKG OFF CACHE BOOL "Use vcpkg" FORCE)
