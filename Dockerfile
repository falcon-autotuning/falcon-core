# Dockerfile for falcon-core C++ development
# Mirrors GitHub Actions Ubuntu environment
FROM ubuntu:22.04

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Update system and install base development tools
RUN apt-get update && apt-get install -y \
  build-essential \
  git \
  cmake \
  ninja-build \
  curl \
  zip \
  unzip \
  tar \
  pkg-config \
  wget \
  ccache \
  # Clang/LLVM toolchain
  clang \
  llvm \
  lld \
  # Additional utilities
  ca-certificates \
  && rm -rf /var/lib/apt/lists/*

# Install vcpkg
WORKDIR /opt
RUN git clone https://github.com/Microsoft/vcpkg.git && \
  cd vcpkg && \
  ./bootstrap-vcpkg.sh -disableMetrics

ENV PATH="/opt/vcpkg:${PATH}"
ENV VCPKG_ROOT="/opt/vcpkg"

# Set working directory
WORKDIR /workspace

# Copy only vcpkg manifest first (for Docker layer caching)
COPY cpp/vcpkg.json /workspace/cpp/vcpkg.json

# Pre-install vcpkg dependencies (this layer will be cached)
WORKDIR /workspace/cpp
RUN vcpkg install --triplet=x64-linux-dynamic

# Set up environment variables for building
ENV CC=clang
ENV CXX=clang++
ENV LD_LIBRARY_PATH=/workspace/cpp/vcpkg_installed/x64-linux-dynamic/debug/lib:/workspace/cpp/vcpkg_installed/x64-linux-dynamic/lib:${LD_LIBRARY_PATH}

# Set working directory back to project root
WORKDIR /workspace/cpp

# Default command
CMD ["/bin/bash"]
