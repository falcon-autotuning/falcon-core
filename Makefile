# Makefile to simplify the CMake build process for falcon-core with vcpkg

.PHONY: all build build-part install test clean setup-vcpkg clean-all

# Variables
BUILD_DIR := build
OUT_PYTHON_DIR := src/falcon_core

# Default target: setup vcpkg and build the project
all: setup-vcpkg build

# Setup vcpkg toolchain
setup-vcpkg:
	@echo "--- Setting up vcpkg ---"
	@which vcpkg > /dev/null 2>&1 || (echo "Error: vcpkg not found in PATH. Please install vcpkg and add it to your PATH."; exit 1)
	@echo "Using vcpkg from: $$(which vcpkg)"
	@echo "Installing dependencies..."
	@vcpkg install --triplet=x64-linux

# Configure and build the project using CMake with vcpkg
build:
	@echo "--- Configuring and Building C++ Extension with vcpkg ---"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OUT_PYTHON_DIR)
	@cmake -G Ninja \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DCMAKE_C_COMPILER_LAUNCHER=ccache \
		-DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON \
		-DCMAKE_CXX_FLAGS="-g -O0" \
		-DCMAKE_TOOLCHAIN_FILE="$$(vcpkg integrate install --triplet=x64-linux | grep -o '/.*\.cmake' | head -n1)" \
		-DVCPKG_TARGET_TRIPLET=x64-linux \
		. -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@ninja -C $(BUILD_DIR) -d stats
	@echo "--- Build complete. Python extension is now in src/falcon_core/ ---"

# Build only selected sources and tests
build-part: setup-vcpkg
	@echo "--- Configuring and Building Selected Parts: $(DIRS), Tests: $(TESTS) ---"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OUT_PYTHON_DIR)
	@cmake -G Ninja \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DCMAKE_C_COMPILER_LAUNCHER=ccache \
		-DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON \
		-DCMAKE_CXX_FLAGS="-g -O0" \
		-DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/scripts/buildsystems/vcpkg.cmake"
		-DVCPKG_TARGET_TRIPLET=x64-linux \
		-DFALCON_CORE_DIRS="$(DIRS)" \
		-DFALCON_CORE_TESTS="$(TESTS)" \
		. -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@ninja -C $(BUILD_DIR) -d stats
	@echo "--- Partial build complete."

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

# Clean everything including vcpkg cache
clean-all: clean
	@echo "--- Cleaning vcpkg cache ---"
	@rm -rf vcpkg_installed
