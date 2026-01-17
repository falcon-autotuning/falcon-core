#!/usr/bin/env bash
set -euo pipefail

echo "=== Falcon-Core Windows Cross-Compilation (vcpkg + MinGW static) ==="


# Paths inside container
VCPKG_ROOT="${VCPKG_ROOT:-/opt/vcpkg}"
TRIPLET="x64-mingw-static"

# Cache locations (mounted from host recommended)
VCPKG_BINARY_CACHE="${VCPKG_BINARY_CACHE:-/workspace/.cache/vcpkg-binary-cache}"
mkdir -p "$VCPKG_BINARY_CACHE"
export VCPKG_DEFAULT_BINARY_CACHE="$VCPKG_BINARY_CACHE"

# Bootstrap vcpkg (once)
if [[ ! -x "$VCPKG_ROOT/vcpkg" ]]; then
  echo "Bootstrapping vcpkg at $VCPKG_ROOT ..."

  mkdir -p "$VCPKG_ROOT"

  # IMPORTANT: /opt/vcpkg is a bind mount; don't rm the mount point
  rm -rf "$VCPKG_ROOT"/* "$VCPKG_ROOT"/.[!.]* "$VCPKG_ROOT"/..?* 2>/dev/null || true

  git clone https://github.com/microsoft/vcpkg "$VCPKG_ROOT"
  "$VCPKG_ROOT/bootstrap-vcpkg.sh"
fi

echo "vcpkg: $("$VCPKG_ROOT/vcpkg" version | head -n 1)"
echo "triplet: $TRIPLET"

# IMPORTANT:
# Prefer manifest mode if you add vcpkg.json. If not present, install a starter set.
if [[ -f /workspace/vcpkg.json ]]; then
  echo "Found /workspace/vcpkg.json -> manifest mode install"
  "$VCPKG_ROOT/vcpkg" install --triplet "$TRIPLET"
else
  echo "No vcpkg.json found -> installing a starter dependency set"
  "$VCPKG_ROOT/vcpkg" install --triplet "$TRIPLET" \
    boost-serialization yaml-cpp hdf5 openssl nlohmann-json sqlite3 zlib bzip2 expat cereal
fi

build_one () {
  local proj="$1"
  local bdir="/workspace/${proj}/build-mingw-vcpkg-static"

  rm -rf "$bdir"   # <-- TEMPORARY: ensures clean build

  echo
  echo "=== Configure: ${proj} ==="
  cmake -S "/workspace/${proj}" -B "$bdir" -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" \
    -DVCPKG_TARGET_TRIPLET="$TRIPLET" \
    -DUSE_VCPKG=ON \
    -DCMAKE_SYSTEM_NAME=Windows \
    -DCMAKE_C_COMPILER=x86_64-w64-mingw32-gcc \
    -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ \
    -DCMAKE_RC_COMPILER=x86_64-w64-mingw32-windres \
    -DFALCON_CORE_DEV=ON


  echo "=== Build: ${proj} ==="
  cmake --build "$bdir" --verbose

  echo "=== Test: ${proj} ==="
  # Static triplet: usually no PATH/DLL games needed
  ctest --test-dir "$bdir" --output-on-failure || {
    echo "CTest failed for ${proj}."
    exit 1
  }
}

# Build both
build_one "cpp"
build_one "c-api"

echo
echo "=== DONE (vcpkg + $TRIPLET) ==="