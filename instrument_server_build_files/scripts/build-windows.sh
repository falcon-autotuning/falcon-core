#!/usr/bin/env bash
set -euo pipefail

# Defaults (can be overridden via env)
MINGW_SYSROOT="${MINGW_SYSROOT:-/usr/x86_64-w64-mingw32}"
CROSS_GCC="${CROSS_GCC:-x86_64-w64-mingw32-gcc}"
TOOLCHAIN_TEMPLATE="${TOOLCHAIN_TEMPLATE:-cmake/toolchains/mingw-clang-toolchain.cmake.tpl}"
TMP_TOOLCHAIN="${TMP_TOOLCHAIN:-/tmp/mingw-clang-toolchain.cmake}"
BUILD_DIR="${BUILD_DIR:-./build-win}"
CMAKE="${CMAKE:-cmake}"
NINJA="${NINJA:-ninja}"

# Ensure script is running under bash
if [ -z "${BASH_VERSION:-}" ]; then
  echo "ERROR: This script requires bash." >&2
  exit 2
fi

echo "MINGW_SYSROOT='${MINGW_SYSROOT}'"
echo "CROSS_GCC='${CROSS_GCC}'"
echo "MINGW_GCC_LIBDIR=''"
echo "MINGW_GCC_TOOLCHAIN_FLAG=''"
echo "MINGW_GCC_LDFLAGS=''"

# print the variable we're about to look for
echo "Looking for cross-gcc:  ${CROSS_GCC}"

MINGW_GCC_LIBDIR=""
MINGW_GCC_TOOLCHAIN_FLAG=""
if command -v "${CROSS_GCC}" >/dev/null 2>&1; then
  echo "Found CROSS_GCC:  ${CROSS_GCC}"
  # get full path to libgcc.a from the cross gcc
  libgcc_path="$("${CROSS_GCC}" -print-file-name=libgcc.a 2>/dev/null || true)"
  echo "libgcc_path:  '${libgcc_path}'"
  if [ -n "${libgcc_path}" ] && [ -f "${libgcc_path}" ] && [ "${libgcc_path}" != "libgcc.a" ]; then
    MINGW_GCC_LIBDIR="$(dirname "${libgcc_path}")"
    echo "  MINGW_GCC_LIBDIR=${MINGW_GCC_LIBDIR}"
  fi

  # Try to query the gcc sysroot/toolchain prefix. This is what clang expects for --gcc-toolchain.
  gcc_sysroot="$("${CROSS_GCC}" -print-sysroot 2>/dev/null || true)"
  if [ -n "${gcc_sysroot}" ]; then
    MINGW_GCC_TOOLCHAIN_FLAG="--gcc-toolchain=${gcc_sysroot}"
    echo "  MINGW_GCC_TOOLCHAIN_FLAG=${MINGW_GCC_TOOLCHAIN_FLAG}"
  else
    # fallback: try to synthesize a reasonable prefix from libgcc path
    # libgcc_path example: /usr/lib/gcc/x86_64-w64-mingw32/15.2.0
    if [ -n "${MINGW_GCC_LIBDIR}" ]; then
      # parent parent of libgcc_dir -> /usr (approx), e.g. dirname(dirname(/usr/lib/gcc/...)) => /usr/lib
      fallback_prefix="$(dirname "$(dirname "${MINGW_GCC_LIBDIR}")")"
      MINGW_GCC_TOOLCHAIN_FLAG="--gcc-toolchain=${fallback_prefix}"
      echo "  MINGW_GCC_TOOLCHAIN_FLAG(fallback)=${MINGW_GCC_TOOLCHAIN_FLAG}"
    fi
  fi
else
  echo "cross-gcc not found in PATH: ${CROSS_GCC}"
fi

if [ -z "${MINGW_GCC_LIBDIR}" ]; then
  echo 'ERROR: Could not find MINGW_GCC_LIBDIR' >&2
  exit 1
fi

MINGW_GCC_LDFLAGS="-L${MINGW_GCC_LIBDIR}"
echo "Final configuration:"
echo "  MINGW_SYSROOT=${MINGW_SYSROOT}"
echo "  MINGW_GCC_LIBDIR=${MINGW_GCC_LIBDIR}"
echo "  MINGW_GCC_TOOLCHAIN_FLAG=${MINGW_GCC_TOOLCHAIN_FLAG}"
echo "  MINGW_GCC_LDFLAGS=${MINGW_GCC_LDFLAGS}"

# Generate toolchain file (substitute the toolchain flag and LDFLAGS)
sed -e "s|@MINGW_SYSROOT@|${MINGW_SYSROOT}|g" \
  -e "s|@MINGW_GCC_LDFLAGS@|${MINGW_GCC_LDFLAGS}|g" \
  -e "s|@MINGW_GCC_TOOLCHAIN_FLAG@|${MINGW_GCC_TOOLCHAIN_FLAG}|g" \
  "${TOOLCHAIN_TEMPLATE}" >"${TMP_TOOLCHAIN}"

echo ""
echo "Generated toolchain file:"
cat "${TMP_TOOLCHAIN}"
echo ""

# Run CMake + Ninja
echo "Running CMake..."
"${CMAKE}" -S . -B "${BUILD_DIR}" -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE="${TMP_TOOLCHAIN}" \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake_ret=$?
if [ "${cmake_ret}" -ne 0 ]; then
  echo "CMake configuration failed" >&2
  exit "${cmake_ret}"
fi

echo "Running Ninja..."
"${NINJA}" -C "${BUILD_DIR}"
