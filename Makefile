# Makefile to simplify the CMake build process for falcon-core with vcpkg

.PHONY: all build build-part install test clean setup-vcpkg clean-all

# Variables
BUILD_DIR := build
OUT_PYTHON_DIR := src/falcon_core

# Default target: setup vcpkg and build the project
forward-header-xtensor-xarray:
	@echo "--- Creating forwarding header for xtensor/xarray.hpp ---"
	@if [ ! -e vcpkg_installed/x64-linux/include/xtensor/xarray.hpp ]; then \
		echo '#include "containers/xarray.hpp"' > vcpkg_installed/x64-linux/include/xtensor/xarray.hpp; \
	fi
	@echo "--- Creating forwarding header for xtensor/xtensor.hpp ---"
	@if [ ! -e vcpkg_installed/x64-linux/include/xtensor/xtensor.hpp ]; then \
		echo '#include "containers/xtensor.hpp"' > vcpkg_installed/x64-linux/include/xtensor/xtensor.hpp; \
	fi
	@echo "--- Creating forwarding header for xtensor/xadapt.hpp ---"
	@if [ ! -e vcpkg_installed/x64-linux/include/xtensor/xadapt.hpp ]; then \
		echo '#include "containers/xadapt.hpp"' > vcpkg_installed/x64-linux/include/xtensor/xadapt.hpp; \
	fi

all: setup-vcpkg forward-header-xtensor-xarray build

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
		-DCMAKE_C_FLAGS="-O0 -fprofile-instr-generate -fcoverage-mapping" \
		-DCMAKE_CXX_FLAGS="-fsanitize=address -g -O0 -fprofile-instr-generate -fcoverage-mapping" \
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

# check coverage of entire module
run-all-tests:
	@LLVM_PROFILE_FILE="run_tests.profraw" ./build/run_tests 
	@llvm-profdata merge -sparse run_tests.profraw -o run_tests.profdata

#check coverage of all the modles listed in the test_filter.txt
run-subset-tests:
	@LLVM_PROFILE_FILE="run_tests.profraw" ./build/run_tests --gtest_filter="$$(paste -sd: test_filter.txt)"
	@llvm-profdata merge -sparse run_tests.profraw -o run_tests.profdata

# launches the interactive html for the entire coverage run
cov-html:
	@llvm-cov show ./build/run_tests -instr-profile=run_tests.profdata \
	  -format=html -output-dir=coverage_html \
	  -ignore-filename-regex='(vcpkg_installed|tests/)' \
		-Xdemangler c++filt -Xdemangler -n
	@xdg-open coverage_html/index.html

# Usage: make coverage-term FILE=/path/to/source.cpp
cov-term:
	@llvm-cov show ./build/run_tests -instr-profile=run_tests.profdata $(FILE) \
	  -ignore-filename-regex='(vcpkg_installed|tests/)' \
	  -Xdemangler c++filt -Xdemangler -n

# Usage: make subset-coverage-html
subset-coverage-html: run-subset-tests cov-html 
# Usage: make coverage-html 
coverage-html: run-all-tests cov-html 
# Usage: make subset-coverage FILE=/path/to/source.cpp
subset-coverage: run-subset-tests cov-term
# Usage: make coverage 
coverage: run-all-tests cov-term

subset-coverage-overview: subset-coverage
	@llvm-cov report ./build/run_tests -instr-profile=run_tests.profdata -ignore-filename-regex='(vcpkg_installed|tests/)' -Xdemangler c++filt -Xdemangler -n                                                                     [15:00:01]

coverage-overview: coverage
	@llvm-cov report ./build/run_tests -instr-profile=run_tests.profdata -ignore-filename-regex='(vcpkg_installed|tests/)' -Xdemangler c++filt -Xdemangler -n                                                                     [15:00:01]

# Run tests using CTest
test: build
	@echo "--- Running C++ Tests ---"
	@cd $(BUILD_DIR) && ctest -V

# Clean up build artifacts
clean:
	@echo "--- Cleaning build directory and compiled extension ---"
	@rm -rf $(BUILD_DIR)
	@rm -rf $(OUT_PYTHON_DIR)
	@rm -rf ./coverage_html/

# Clean everything including vcpkg cache
clean-all: clean
	@echo "--- Cleaning vcpkg cache ---"
	@rm -rf vcpkg_installed
