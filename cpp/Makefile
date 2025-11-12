# Makefile to simplify the CMake build process for falcon-core-cpp 

.PHONY: all build build-part install test clean setup-vcpkg clean-all

# Variables
BUILD_DIR := build
CC ?= clang
CXX ?= clang++

USE_VCPKG ?= 1

ifeq ($(USE_VCPKG),1)
	VCPKG_INSTALLED = vcpkg_installed
	VCPKG_DEBUG_LIB = $(PWD)/vcpkg_installed/x64-linux-dynamic/debug/lib
	VCPKG_TOOLCHAIN = $(shell vcpkg integrate install --triplet=x64-linux-dynamic | grep -o '/.*\.cmake' | head -n1)

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
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		$(TOOLCHAIN_ARG) \
		-DUSE_VCPKG=$(USE_VCPKG) \
		. -S . -B $(BUILD_DIR)
	@echo "--- Build complete ---"

build-dev:
	@echo "--- Configuring and Building C++ Extension (dev, tests, coverage) ---"
	@mkdir -p $(BUILD_DIR)
	@echo "CC=$(CC)" > $(BUILD_DIR)/compiler.env
	@echo "CXX=$(CXX)" >> $(BUILD_DIR)/compiler.env
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH \
	$(VCPKG_ENV) cmake -G Ninja \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		$(TOOLCHAIN_ARG) \
		-DUSE_VCPKG=$(USE_VCPKG) \
		-DFALCON_CORE_DEV=ON \
		. -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi;
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH \
	ninja -C $(BUILD_DIR) -d stats
	@echo "--- Build complete ---"

define LOAD_COMPILER_ENV
  if [ -f $(BUILD_DIR)/compiler.env ]; then . $(BUILD_DIR)/compiler.env; fi
endef
# Detect compiler for coverage tools
COVERAGE_TOOL = $(shell [ -f $(BUILD_DIR)/compiler.env ] && . $(BUILD_DIR)/compiler.env; \
	[ "$$(basename $${CXX:-clang++})" = "clang++" ] && echo llvm-cov || echo gcov)

PROFDATA_TOOL = $(shell [ -f $(BUILD_DIR)/compiler.env ] && . $(BUILD_DIR)/compiler.env; \
	[ "$$(basename $${CXX:-clang++})" = "clang++" ] && echo llvm-profdata || echo gcov-tool)

run-all-tests:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@LLVM_PROFILE_FILE="$(BUILD_DIR)/falcon_core_cpp_run_tests.profraw" LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(BUILD_DIR)/falcon_core_cpp_run_tests
	@llvm-profdata merge -sparse $(BUILD_DIR)/falcon_core_cpp_run_tests.profraw -o $(BUILD_DIR)/falcon_core_cpp_run_tests.profdata
else
	@GCOV_PREFIX="$(BUILD_DIR)" LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(BUILD_DIR)/falcon_core_cpp_run_tests
endif

run-subset-tests:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@LLVM_PROFILE_FILE="$(BUILD_DIR)/falcon_core_cpp_run_tests.profraw" LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(BUILD_DIR)/falcon_core_cpp_run_tests --gtest_filter="$$(paste -sd: test_filter.txt)"
	@llvm-profdata merge -sparse $(BUILD_DIR)/falcon_core_cpp_run_tests.profraw -o $(BUILD_DIR)/falcon_core_cpp_run_tests.profdata
else
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(BUILD_DIR)/falcon_core_cpp_run_tests --gtest_filter="$$(paste -sd: test_filter.txt)"
endif

cov-html:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov show ./$(BUILD_DIR)/libfalcon_core_cpp.so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata \
	  -format=html -output-dir=coverage_html \
	  -ignore-filename-regex='(vcpkg_installed|tests/)' \
	  -Xdemangler c++filt -Xdemangler -n
	@xdg-open coverage_html/index.html
else
	@gcovr -r . --html --html-details -o coverage_html/index.html
	@xdg-open coverage_html/index.html
endif

cov-term:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov show ./$(BUILD_DIR)/libfalcon_core_cpp.so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata $(FILE) \
	  -ignore-filename-regex='(vcpkg_installed|tests/)' \
	  -Xdemangler c++filt -Xdemangler -n
else
	@gcovr src/ . --txt -f $(FILE)
endif

# Usage: make subset-coverage-html
subset-coverage-html: run-subset-tests cov-html 
# Usage: make coverage-html 
coverage-html: run-all-tests cov-html 
# Usage: make subset-coverage FILE=/path/to/source.cpp
subset-coverage: run-subset-tests cov-term
# Usage: make coverage 
coverage: run-all-tests cov-term

subset-coverage-overview: subset-coverage
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov report ./$(BUILD_DIR)/libfalcon_core_cpp.so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata \
		-ignore-filename-regex='(vcpkg_installed|tests/)' \
		-Xdemangler c++filt -Xdemangler -n
else
	@gcovr src/ . --txt --exclude 'vcpkg_installed|tests/'
endif

coverage-overview: coverage
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov report ./$(BUILD_DIR)/libfalcon_core_cpp.so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata \
		-ignore-filename-regex='(vcpkg_installed|tests/)' \
		-Xdemangler c++filt -Xdemangler -n
else
	@gcovr src/ . --txt --exclude 'vcpkg_installed|tests/'
endif

# Clean up build artifacts
clean:
	@echo "--- Cleaning build directory and compiled extension ---"
	@rm -rf $(BUILD_DIR)

clean-all: clean
	@echo "--- Cleaning vcpkg cache ---"
ifeq ($(USE_VCPKG),1)
	@echo "--- Cleaning vcpkg cache ---"
	@rm -rf $(VCPKG_INSTALLED)
endif

rebuild-dev: clean-all build-dev
	@echo "--- Cleaning and building (dev)"
