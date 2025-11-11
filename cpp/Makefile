# Makefile to simplify the CMake build process for falcon-core with vcpkg

.PHONY: all build build-part install test clean setup-vcpkg clean-all

# Variables
BUILD_DIR := build
CPP_TARGET := falcon_core_cpp
VCPKG_INSTALLED := vcpkg_installed
VCPKG_DEBUG_LIB := $(PWD)/vcpkg_installed/x64-linux-dynamic/debug/lib
VCPKG_TOOLCHAIN := $(shell vcpkg integrate install --triplet=x64-linux-dynamic | grep -o '/.*\.cmake' | head -n1)

USE_VCPKG ?= 1

ifeq ($(USE_VCPKG),1)
  TOOLCHAIN_ARG = -DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
                  -DVCPKG_TARGET_TRIPLET=x64-linux-dynamic \
                  -DVCPKG_INSTALLED_DIR=$(PWD)/vcpkg_installed
  VCPKG_ENV = VCPKG_FEATURE_FLAGS=fail-on-unavailable
else
  TOOLCHAIN_ARG =
  VCPKG_ENV =
endif


all: setup-vcpkg build

# Setup vcpkg toolchain
setup-vcpkg:
	@echo "--- Setting up vcpkg ---"
	@which vcpkg > /dev/null 2>&1 || (echo "Error: vcpkg not found in PATH. Please install vcpkg and add it to your PATH."; exit 1)
	@echo "Using vcpkg from: $$(which vcpkg)"
	@echo "Installing dependencies..."
	@vcpkg install --triplet=x64-linux-dynamic

build:
	@echo "--- Configuring and Building C++ Extension (release, no tests) ---"
	@mkdir -p $(BUILD_DIR)
	@$(VCPKG_ENV) cmake -G Ninja \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DCMAKE_C_COMPILER_LAUNCHER=ccache \
		-DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON \
		-DCMAKE_C_FLAGS="-O2" \
		-DCMAKE_CXX_FLAGS="-g -O2" \
		$(TOOLCHAIN_ARG) \
		-DCPP_TARGET=$(CPP_TARGET) \
		-DBUILD_TESTS=OFF \
		-DUSE_VCPKG=$(USE_VCPKG) \
		. -S . -B $(BUILD_DIR)
	@echo "--- Build complete ---"

build-dev:
	@echo "--- Configuring and Building C++ Extension (dev, tests, coverage) ---"
	@mkdir -p $(BUILD_DIR)
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH \
	$(VCPKG_ENV) cmake -G Ninja \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DCMAKE_C_COMPILER_LAUNCHER=ccache \
		-DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON \
		-DCMAKE_C_FLAGS="-O0 -fprofile-instr-generate -fcoverage-mapping" \
		-DCMAKE_CXX_FLAGS="-g -O0 -fprofile-instr-generate -fcoverage-mapping" \
		$(TOOLCHAIN_ARG) \
		-DCPP_TARGET=$(CPP_TARGET) \
		-DBUILD_TESTS=ON \
		-DUSE_VCPKG=$(USE_VCPKG) \
		. -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH \
	ninja -C $(BUILD_DIR) -d stats
	@echo "--- Build complete ---"

# check coverage of entire module
run-all-tests:
	@LLVM_PROFILE_FILE="$(BUILD_DIR)/falcon_core_cpp_run_tests.profraw" LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(BUILD_DIR)/falcon_core_cpp_run_tests
	@llvm-profdata merge -sparse $(BUILD_DIR)/falcon_core_cpp_run_tests.profraw -o $(BUILD_DIR)/falcon_core_cpp_run_tests.profdata

#check coverage of all the modles listed in the test_filter.txt
run-subset-tests:
	@LLVM_PROFILE_FILE="$(BUILD_DIR)/falcon_core_cpp_run_tests.profraw" LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(BUILD_DIR)/falcon_core_cpp_run_tests --gtest_filter="$$(paste -sd: test_filter.txt)"
	@llvm-profdata merge -sparse $(BUILD_DIR)/falcon_core_cpp_run_tests.profraw -o $(BUILD_DIR)/falcon_core_cpp_run_tests.profdata

# launches the interactive html for the entire coverage run
cov-html:
	@llvm-cov show ./$(BUILD_DIR)/lib$(CPP_TARGET).so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata \
	  -format=html -output-dir=coverage_html \
	  -ignore-filename-regex='(vcpkg_installed|tests/)' \
		-Xdemangler c++filt -Xdemangler -n
	@xdg-open coverage_html/index.html

# Usage: make coverage-term FILE=/path/to/source.cpp
cov-term:
	@llvm-cov show ./$(BUILD_DIR)/lib$(CPP_TARGET).so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata $(FILE) \
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
	@llvm-cov report ./$(BUILD_DIR)/lib$(CPP_TARGET).so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata \
		-ignore-filename-regex='(vcpkg_installed|tests/)' \
		-Xdemangler c++filt -Xdemangler -n

coverage-overview: coverage
	@llvm-cov report ./$(BUILD_DIR)/lib$(CPP_TARGET).so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata -ignore-filename-regex='(vcpkg_installed|tests/)' -Xdemangler c++filt -Xdemangler -n

# Clean up build artifacts
clean:
	@echo "--- Cleaning build directory and compiled extension ---"
	@rm -rf $(BUILD_DIR)
	@rm -rf ./coverage_html/

clean-all: clean
	@echo "--- Cleaning vcpkg cache ---"
ifeq ($(USE_VCPKG),1)
	@echo "--- Cleaning vcpkg cache ---"
	@rm -rf $(VCPKG_INSTALLED)
endif

rebuild-dev: clean-all build-dev
	@echo "--- Cleaning and building (dev)"
