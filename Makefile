# Makefile to simplify the CMake build process for falcon-core

.PHONY: all build install test clean

# Variables
BUILD_DIR := build
OUT_PYTHON_DIR := src/falcon_core

# Default target: build the project
all: build

# Configure and build the project using CMake
# This compiles the C++ code and places the Python extension in src/falcon_core
build:
	@echo "--- Configuring and Building C++ Extension ---"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OUT_PYTHON_DIR)
	@cmake -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_BUILD_WITH_INSTALL_RPATH=ON -DCMAKE_CXX_FLAGS="-O0" . -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@ninja -C $(BUILD_DIR) -d stats
	@echo "--- Build complete. Python extension is now in src/falcon_core/ ---"

# Install the Python package using pip
install:
	@echo "--- Installing Python package ---"
	@uv pip install .

# Run tests using CTest
test: build
	@echo "--- Running C++ Tests ---"
	@cd $(BUILD_DIR) && ctest -V

# Clean up build artifacts
clean:
	@echo "--- Cleaning build directory and compiled extension ---"
	@rm -rf $(BUILD_DIR)
	@rm -rf $(OUT_PYTHON_DIR)

test-make-cpp:
	@gcc
