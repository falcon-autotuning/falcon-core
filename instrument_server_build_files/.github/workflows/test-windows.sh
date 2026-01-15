#!/bin/bash
# Test script for Windows workflow (run in MSYS2 environment)
# This simulates what the workflow will do

set -e  # Exit on any error

echo "=== Testing Windows Workflow ==="
echo ""

# Check if running in MSYS2
if [ -z "$MSYSTEM" ]; then
    echo "ERROR: This script should be run inside MSYS2 MINGW64 environment"
    echo "Please run from MSYS2 MinGW 64-bit shell"
    exit 1
fi

echo "Step 1: Install dependencies (run from MSYS2 shell)..."
echo "Run: pacman -S --noconfirm mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja mingw-w64-x86_64-gcc mingw-w64-x86_64-lua mingw-w64-x86_64-luajit mingw-w64-x86_64-spdlog mingw-w64-x86_64-nlohmann-json mingw-w64-x86_64-yaml-cpp mingw-w64-x86_64-gtest mingw-w64-x86_64-boost git"

echo ""
echo "Step 2: Install sol2 (header-only library)..."
if [ ! -d /tmp/sol2 ]; then
    git clone --depth 1 --branch v3.3.0 https://github.com/ThePhD/sol2.git /tmp/sol2
fi
mkdir -p /mingw64/include/sol
cp -r /tmp/sol2/include/sol/* /mingw64/include/sol/

echo ""
echo "Step 3: Build project..."
mkdir -p build
cd build
cmake -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_TESTS=ON \
    ..
ninja

echo ""
echo "Step 4: Run unit tests..."
if ./tests/unit_tests.exe; then
    echo "✓ Unit tests passed successfully"
else
    echo "✗ Unit tests failed"
    exit 1
fi

echo ""
echo "Step 5: Run integration tests..."
if ./tests/integration_tests.exe; then
    echo "✓ Integration tests passed successfully"
else
    echo "✗ Integration tests failed"
    exit 1
fi

echo ""
echo "Step 6: Package binaries..."
cd ..
mkdir -p windows-binaries
cp build/instrument-server.exe windows-binaries/
cp build/instrument-worker.exe windows-binaries/
cp build/libinstrument-server-core.dll windows-binaries/
cp LICENSE windows-binaries/
ls -la windows-binaries/

echo ""
echo "=== Windows Workflow Test PASSED ==="
