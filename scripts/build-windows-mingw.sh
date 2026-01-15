#!/usr/bin/env bash
# Cross-compile falcon-core for Windows using MinGW on Arch Linux
# This script is designed to run inside the falcon-arch-ci Docker container
set -euo pipefail

# Defaults (can be overridden via env)
MINGW_SYSROOT="${MINGW_SYSROOT:-/usr/x86_64-w64-mingw32}"
CROSS_GCC="${CROSS_GCC:-x86_64-w64-mingw32-gcc}"
CROSS_GPP="${CROSS_GPP:-x86_64-w64-mingw32-g++}"
TOOLCHAIN_TEMPLATE="${TOOLCHAIN_TEMPLATE:-cmake/mingw-clang-toolchain.cmake.tpl}"
TMP_TOOLCHAIN="${TMP_TOOLCHAIN:-/tmp/mingw-clang-toolchain.cmake}"
BUILD_DIR_CPP="${BUILD_DIR_CPP:-./cpp/build-mingw}"
BUILD_DIR_C_API="${BUILD_DIR_C_API:-./c-api/build-mingw}"
CMAKE="${CMAKE:-cmake}"
NINJA="${NINJA:-ninja}"
RUN_TESTS="${RUN_TESTS:-0}"  # Set to 1 to run tests with Wine
FALCON_CORE_DEV="${FALCON_CORE_DEV:-OFF}"  # Set to ON to build tests

echo "=== Falcon-Core Windows Cross-Compilation with MinGW ==="
echo ""

# Ensure script is running under bash
if [ -z "${BASH_VERSION:-}" ]; then
  echo "ERROR: This script requires bash." >&2
  exit 2
fi

# Check we're at repo root
if [[ ! -d cpp || ! -d c-api ]]; then
  echo "ERROR: Run this from the repo root (where cpp/ and c-api/ exist)." >&2
  exit 1
fi

echo "Configuration:"
echo "  MINGW_SYSROOT='${MINGW_SYSROOT}'"
echo "  CROSS_GCC='${CROSS_GCC}'"
echo "  CROSS_GPP='${CROSS_GPP}'"
echo "  FALCON_CORE_DEV='${FALCON_CORE_DEV}'"
echo "  RUN_TESTS='${RUN_TESTS}'"
echo ""

# Check for MinGW toolchain
if ! command -v "${CROSS_GCC}" >/dev/null 2>&1; then
  echo "ERROR: MinGW cross-compiler not found: ${CROSS_GCC}" >&2
  echo "Install with: pacman -S mingw-w64-gcc" >&2
  exit 1
fi

if ! command -v clang >/dev/null 2>&1; then
  echo "ERROR: clang not found in PATH" >&2
  echo "Install with: pacman -S clang" >&2
  exit 1
fi

if ! command -v lld >/dev/null 2>&1; then
  echo "ERROR: lld (LLVM linker) not found in PATH" >&2
  echo "Install with: pacman -S lld" >&2
  exit 1
fi

echo "Looking for cross-gcc: ${CROSS_GCC}"
MINGW_GCC_LIBDIR=""
MINGW_GCC_TOOLCHAIN_FLAG=""

if command -v "${CROSS_GCC}" >/dev/null 2>&1; then
  echo "Found CROSS_GCC: ${CROSS_GCC}"
  
  # Get full path to libgcc.a from the cross gcc
  libgcc_path="$("${CROSS_GCC}" -print-file-name=libgcc.a 2>/dev/null || true)"
  echo "  libgcc_path: '${libgcc_path}'"
  
  if [ -n "${libgcc_path}" ] && [ -f "${libgcc_path}" ] && [ "${libgcc_path}" != "libgcc.a" ]; then
    MINGW_GCC_LIBDIR="$(dirname "${libgcc_path}")"
    echo "  MINGW_GCC_LIBDIR=${MINGW_GCC_LIBDIR}"
  fi

  # Try to query the gcc sysroot/toolchain prefix
  gcc_sysroot="$("${CROSS_GCC}" -print-sysroot 2>/dev/null || true)"
  if [ -n "${gcc_sysroot}" ]; then
    MINGW_GCC_TOOLCHAIN_FLAG="--gcc-toolchain=${gcc_sysroot}"
    echo "  MINGW_GCC_TOOLCHAIN_FLAG=${MINGW_GCC_TOOLCHAIN_FLAG}"
  else
    # Fallback: synthesize a reasonable prefix from libgcc path
    if [ -n "${MINGW_GCC_LIBDIR}" ]; then
      fallback_prefix="$(dirname "$(dirname "${MINGW_GCC_LIBDIR}")")"
      MINGW_GCC_TOOLCHAIN_FLAG="--gcc-toolchain=${fallback_prefix}"
      echo "  MINGW_GCC_TOOLCHAIN_FLAG(fallback)=${MINGW_GCC_TOOLCHAIN_FLAG}"
    fi
  fi
else
  echo "ERROR: cross-gcc not found in PATH: ${CROSS_GCC}" >&2
  exit 1
fi

if [ -z "${MINGW_GCC_LIBDIR}" ]; then
  echo 'ERROR: Could not find MINGW_GCC_LIBDIR' >&2
  exit 1
fi

MINGW_GCC_LDFLAGS="-L${MINGW_GCC_LIBDIR}"

echo ""
echo "Final MinGW configuration:"
echo "  MINGW_SYSROOT=${MINGW_SYSROOT}"
echo "  MINGW_GCC_LIBDIR=${MINGW_GCC_LIBDIR}"
echo "  MINGW_GCC_TOOLCHAIN_FLAG=${MINGW_GCC_TOOLCHAIN_FLAG}"
echo "  MINGW_GCC_LDFLAGS=${MINGW_GCC_LDFLAGS}"
echo ""

# Generate toolchain file from template
if [ ! -f "${TOOLCHAIN_TEMPLATE}" ]; then
  echo "ERROR: Toolchain template not found: ${TOOLCHAIN_TEMPLATE}" >&2
  exit 1
fi

echo "Generating CMake toolchain file..."
sed -e "s|@MINGW_SYSROOT@|${MINGW_SYSROOT}|g" \
  -e "s|@MINGW_GCC_LDFLAGS@|${MINGW_GCC_LDFLAGS}|g" \
  -e "s|@MINGW_GCC_TOOLCHAIN_FLAG@|${MINGW_GCC_TOOLCHAIN_FLAG}|g" \
  "${TOOLCHAIN_TEMPLATE}" >"${TMP_TOOLCHAIN}"

echo "Generated toolchain file:"
cat "${TMP_TOOLCHAIN}"
echo ""

# ========================================
# Build C++ Core
# ========================================
echo "=== Building C++ Core for Windows ==="
cd cpp

# Clean previous build
rm -rf "${BUILD_DIR_CPP#./cpp/}"
mkdir -p "${BUILD_DIR_CPP#./cpp/}"

echo "Running CMake for C++ core..."
"${CMAKE}" -S . -B "${BUILD_DIR_CPP#./cpp/}" -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE="${TMP_TOOLCHAIN}" \
  -DCMAKE_BUILD_TYPE=Release \
  -DUSE_VCPKG=OFF \
  -DFALCON_CORE_DEV="${FALCON_CORE_DEV}" \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake_ret=$?
if [ "${cmake_ret}" -ne 0 ]; then
  echo "ERROR: CMake configuration failed for C++ core" >&2
  exit "${cmake_ret}"
fi

echo "Running Ninja for C++ core..."
"${NINJA}" -C "${BUILD_DIR_CPP#./cpp/}"
ninja_ret=$?
if [ "${ninja_ret}" -ne 0 ]; then
  echo "ERROR: Build failed for C++ core" >&2
  exit "${ninja_ret}"
fi

echo "✓ C++ core build completed successfully"
echo ""

# Go back to repo root
cd ..

# ========================================
# Build C-API
# ========================================
echo "=== Building C-API for Windows ==="
cd c-api

# Clean previous build
rm -rf "${BUILD_DIR_C_API#./c-api/}"
mkdir -p "${BUILD_DIR_C_API#./c-api/}"

echo "Running CMake for C-API..."
"${CMAKE}" -S . -B "${BUILD_DIR_C_API#./c-api/}" -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE="${TMP_TOOLCHAIN}" \
  -DCMAKE_BUILD_TYPE=Release \
  -DUSE_VCPKG=OFF \
  -DFALCON_CORE_DEV="${FALCON_CORE_DEV}" \
  -DCORE_ROOT="../cpp" \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake_ret=$?
if [ "${cmake_ret}" -ne 0 ]; then
  echo "ERROR: CMake configuration failed for C-API" >&2
  exit "${cmake_ret}"
fi

echo "Running Ninja for C-API..."
"${NINJA}" -C "${BUILD_DIR_C_API#./c-api/}"
ninja_ret=$?
if [ "${ninja_ret}" -ne 0 ]; then
  echo "ERROR: Build failed for C-API" >&2
  exit "${ninja_ret}"
fi

echo "✓ C-API build completed successfully"
echo ""

# Go back to repo root
cd ..

# ========================================
# Summary
# ========================================
echo "=== Build Summary ==="
echo ""
echo "Windows binaries have been cross-compiled successfully:"
echo ""
echo "C++ Core:"
if [ -f "cpp/${BUILD_DIR_CPP#./cpp/}/falcon_core_cpp.dll" ]; then
  ls -lh "cpp/${BUILD_DIR_CPP#./cpp/}/falcon_core_cpp.dll"
elif [ -f "cpp/${BUILD_DIR_CPP#./cpp/}/libfalcon_core_cpp.dll" ]; then
  ls -lh "cpp/${BUILD_DIR_CPP#./cpp/}/libfalcon_core_cpp.dll"
else
  echo "  Warning: DLL not found in expected location"
fi

if [ -f "cpp/${BUILD_DIR_CPP#./cpp/}/falcon_core_cpp_run_tests.exe" ]; then
  ls -lh "cpp/${BUILD_DIR_CPP#./cpp/}/falcon_core_cpp_run_tests.exe"
fi

echo ""
echo "C-API:"
if [ -f "c-api/${BUILD_DIR_C_API#./c-api/}/falcon_core_c_api.dll" ]; then
  ls -lh "c-api/${BUILD_DIR_C_API#./c-api/}/falcon_core_c_api.dll"
elif [ -f "c-api/${BUILD_DIR_C_API#./c-api/}/libfalcon_core_c_api.dll" ]; then
  ls -lh "c-api/${BUILD_DIR_C_API#./c-api/}/libfalcon_core_c_api.dll"
else
  echo "  Warning: DLL not found in expected location"
fi

if [ -f "c-api/${BUILD_DIR_C_API#./c-api/}/falcon_core_c_api_run_tests.exe" ]; then
  ls -lh "c-api/${BUILD_DIR_C_API#./c-api/}/falcon_core_c_api_run_tests.exe"
fi

echo ""
echo "=== Done ==="
echo ""

if [ "${RUN_TESTS}" = "1" ] || [ "${RUN_TESTS}" = "true" ]; then
  # Check if Wine is available
  if ! command -v wine >/dev/null 2>&1; then
    echo "ERROR: Wine not found. Install with: pacman -S wine wine-mono wine-gecko" >&2
    exit 1
  fi
  
  # Initialize wine prefix if needed (suppress first-run dialogs)
  export WINEPREFIX="${HOME}/.wine-falcon-test"
  export WINEDEBUG=-all  # Suppress wine debug output
  
  echo "=== Running Tests with Wine ==="
  echo ""
  
  # Test C++ Core
  CPP_TEST_EXE="cpp/${BUILD_DIR_CPP#./cpp/}/falcon_core_cpp_run_tests.exe"
  if [ -f "${CPP_TEST_EXE}" ]; then
    echo "Running C++ tests..."
    echo "Test executable: ${CPP_TEST_EXE}"
    
    # Set up Wine environment
    # Add MinGW DLLs to Wine's DLL search path
    export WINEPATH="/usr/x86_64-w64-mingw32/bin;$(cd cpp && pwd)/${BUILD_DIR_CPP#./cpp/}"
    
    # Run tests
    if wine "${CPP_TEST_EXE}"; then
      echo "✓ C++ tests passed"
    else
      test_ret=$?
      echo "✗ C++ tests failed with exit code ${test_ret}"
      exit "${test_ret}"
    fi
  else
    echo "Warning: C++ test executable not found at ${CPP_TEST_EXE}"
    echo "Ensure FALCON_CORE_DEV=ON was set during build."
  fi
  
  echo ""
  
  # Test C-API
  C_API_TEST_EXE="c-api/${BUILD_DIR_C_API#./c-api/}/falcon_core_c_api_run_tests.exe"
  if [ -f "${C_API_TEST_EXE}" ]; then
    echo "Running C-API tests..."
    echo "Test executable: ${C_API_TEST_EXE}"
    
    # Set up Wine environment with both C++ and C-API DLLs
    export WINEPATH="/usr/x86_64-w64-mingw32/bin;$(cd cpp && pwd)/${BUILD_DIR_CPP#./cpp/};$(cd c-api && pwd)/${BUILD_DIR_C_API#./c-api/}"
    
    # Run tests
    if wine "${C_API_TEST_EXE}"; then
      echo "✓ C-API tests passed"
    else
      test_ret=$?
      echo "✗ C-API tests failed with exit code ${test_ret}"
      exit "${test_ret}"
    fi
  else
    echo "Warning: C-API test executable not found at ${C_API_TEST_EXE}"
    echo "Ensure FALCON_CORE_DEV=ON was set during build."
  fi
  
  echo ""
  echo "=== All Tests Passed ==="
else
  echo "Note: These are Windows binaries. To test them, you'll need to run them on Windows"
  echo "or use Wine on Linux. Set RUN_TESTS=1 and FALCON_CORE_DEV=ON to run tests automatically."
  echo ""
  echo "Example:"
  echo "  RUN_TESTS=1 FALCON_CORE_DEV=ON bash /workspace/scripts/build-windows-mingw.sh"
fi
