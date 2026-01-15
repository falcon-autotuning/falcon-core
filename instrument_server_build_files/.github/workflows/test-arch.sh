#!/bin/bash
# Test script for Arch Linux workflow
# This simulates what the workflow will do

set -e  # Exit on any error

echo "=== Testing Arch Linux Workflow ==="
echo ""

# Check if running in Docker
if [ ! -f /.dockerenv ] && [ ! -f /run/.containerenv ]; then
    echo "ERROR: This script should be run inside an Arch Linux container"
    echo "Run with: docker run --rm -v \$(pwd):/workspace -w /workspace archlinux:latest bash /workspace/.github/workflows/test-arch.sh"
    exit 1
fi

echo "Step 1: Update system and install dependencies..."
pacman -Syu --noconfirm
pacman -S --noconfirm \
    base-devel \
    git \
    cmake \
    ninja \
    clang \
    lld \
    llvm \
    lua \
    luajit \
    spdlog \
    nlohmann-json \
    yaml-cpp \
    gtest \
    boost

echo ""
echo "Step 2: Install sol2 (header-only library)..."
if [ ! -d /tmp/sol2 ]; then
    git clone --depth 1 --branch v3.3.0 https://github.com/ThePhD/sol2.git /tmp/sol2
fi
mkdir -p /usr/local/include/sol
cp -r /tmp/sol2/include/sol/* /usr/local/include/sol/

echo ""
echo "Step 3: Clean build directory..."
make clean || true

echo ""
echo "Step 4: Build project..."
make build

echo ""
echo "Step 5: Run unit tests..."
make unit-test
echo "Unit tests completed"

echo ""
echo "Step 6: Run integration tests..."
make integration-tests
echo "Integration tests completed"

echo ""
echo "=== Arch Linux Workflow Test PASSED ==="
