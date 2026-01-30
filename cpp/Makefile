# Makefile to simplify the CMake build process for falcon-core-cpp
# Cross-platform: Linux and Windows (MSYS / MINGW / native)

.PHONY: all build build-part install test clean setup-vcpkg clean-all build-dev run-all-tests run-subset-tests cov-html cov-term coverage coverage-html subset-coverage subset-coverage-html subset-coverage-overview coverage-overview rebuild-dev

# Base paths
CPP_DIR := $(abspath $(CURDIR))
BUILD_DIR := $(CPP_DIR)/build
PWD := $(CPP_DIR)

# Platform detection (works on Linux, MINGW/MSYS, and native Windows)
UNAME_S := $(shell uname -s 2>/dev/null || echo Unknown)
IS_MINGW := $(findstring MINGW,$(UNAME_S))
IS_CYGWIN := $(findstring CYGWIN,$(UNAME_S))
IS_WINDOWS_NT := $(filter Windows_NT,$(OS))
ifeq ($(or $(IS_MINGW),$(IS_CYGWIN),$(IS_WINDOWS_NT)),)
  PLATFORM := linux
else
  PLATFORM := windows
endif

# Default compilers (user can override from environment)
ifeq ($(PLATFORM),windows)
  # prefer clang-cl when available; user can pass CC/ CXX to override
  CC ?= clang-cl
  CXX ?= clang-cl
  VCPKG_TRIPLET := x64-windows
  VCPKG_DEBUG_BIN := $(PWD)/vcpkg_installed/x64-windows/bin
  VCPKG_RELEASE_LIB := $(PWD)/vcpkg_installed/x64-windows/lib
  EXE_SUFFIX := .exe
  STRIP_CMD := # no-op (strip not usually present); set to "llvm-strip" if you have it
  RUN_PREFIX := PATH=$(VCPKG_DEBUG_BIN):$$PATH
	VCPKG_TOOLCHAIN ?= $(CPP_DIR)/../../../vcpkg/scripts/buildsystems/vcpkg.cmake
	USE_VCPKG ?= 1
  # On Windows, Ninja + clang-cl: still pass CMAKE_C_COMPILER / CMAKE_CXX_COMPILER
else
  CC ?= clang
  CXX ?= clang++
  VCPKG_TRIPLET := x64-linux-dynamic
  VCPKG_DEBUG_LIB := $(PWD)/vcpkg_installed/x64-linux-dynamic/debug/lib
  VCPKG_RELEASE_LIB := $(PWD)/vcpkg_installed/x64-linux-dynamic/lib
  EXE_SUFFIX :=
  STRIP_CMD := strip
  VCPKG_TOOLCHAIN ?= $(shell which vcpkg >/dev/null 2>&1 && vcpkg integrate install --triplet=$(VCPKG_TRIPLET) 2>/dev/null | grep -o '/.*\.cmake' | head -n1 || echo $(PWD)/vcpkg/scripts/buildsystems/vcpkg.cmake)
  RUN_PREFIX := LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH
	USE_VCPKG ?= 0
endif

ifeq ($(USE_VCPKG),1)
  VCPKG_INSTALLED := vcpkg_installed
  # attempt to discover a usable vcpkg toolchain file (may differ by platform)
  TOOLCHAIN_ARG := -DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) -DVCPKG_TARGET_TRIPLET=$(VCPKG_TRIPLET) -DVCPKG_INSTALLED_DIR=$(PWD)/vcpkg_installed
  VCPKG_ENV := VCPKG_FEATURE_FLAGS=fail-on-unavailable
else
  TOOLCHAIN_ARG :=
  VCPKG_ENV :=
endif

all: setup-vcpkg build

# Setup vcpkg toolchain
setup-vcpkg:
	@echo "--- Setting up vcpkg ---"
	@which vcpkg > /dev/null 2>&1 || (echo "Error: vcpkg not found in PATH. Please install vcpkg and add it to your PATH."; exit 1)
	@echo "Using vcpkg from: $$(which vcpkg)"
	@echo "Installing dependencies (triplet: $(VCPKG_TRIPLET))..."
	@vcpkg install --triplet=$(VCPKG_TRIPLET)

build:
	@echo "--- Configuring and Building C++ Extension (release, no tests) on $(PLATFORM) ---"
	@mkdir -p $(BUILD_DIR)
ifeq ($(PLATFORM),linux)
	@$(VCPKG_ENV) cmake -G Ninja \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		$(TOOLCHAIN_ARG) \
		-DUSE_VCPKG=$(USE_VCPKG) \
		. -S . -B $(BUILD_DIR)
else
	@echo "--- Running Windows-style cmake + ninja (using variables) ---"
	@$(VCPKG_ENV) cmake -B build -S . -G "Ninja" \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
		-DVCPKG_MANIFEST_DIR=./ \
		-DVCPKG_INSTALLED_DIR=$(PWD)/build/vcpkg_installed \
		-DCMAKE_BUILD_TYPE=Release \
		-DUSE_VCPKG=$(USE_VCPKG)
	@ninja -C build -v
endif
	ninja -C $(BUILD_DIR) -j $(shell nproc 2>/dev/null || echo 1)
	@if [ -n "$(STRIP_CMD)" ]; then $(STRIP_CMD) $(BUILD_DIR)/libfalcon_core_cpp.so 2>/dev/null || true; fi
	@echo "--- Build complete ---"

build-dev:
	@echo "--- Configuring and Building C++ Extension (dev, tests, coverage) on $(PLATFORM) ---"
	@mkdir -p $(BUILD_DIR)
	@echo "CC=$(CC)" > $(BUILD_DIR)/compiler.env
	@echo "CXX=$(CXX)" >> $(BUILD_DIR)/compiler.env
ifeq ($(PLATFORM),linux)
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH \
	$(VCPKG_ENV) cmake -G Ninja \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		$(TOOLCHAIN_ARG) \
		-DUSE_VCPKG=$(USE_VCPKG) \
		-DFALCON_CORE_DEV=ON \
		. -S . -B $(BUILD_DIR)
else
	@echo "--- Running Windows-style cmake + ninja (using variables) ---"
	@$(VCPKG_ENV) cmake -B build -S . -G "Ninja" \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
		-DVCPKG_MANIFEST_DIR=./ \
		-DVCPKG_INSTALLED_DIR=$(PWD)/build/vcpkg_installed \
		-DCMAKE_BUILD_TYPE=Release \
		-DFALCON_CORE_DEV=ON \
		-DUSE_VCPKG=$(USE_VCPKG)
	@ninja -C build -v
endif
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi;
	@echo "--- Build complete ---"
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi;
	ninja -C $(BUILD_DIR) -j $(shell nproc 2>/dev/null || echo 1) -d stats
	@echo "--- Build complete ---"

# Shell helper to load compiler.env if present (used inside $(shell ...))
define LOAD_COMPILER_ENV
  if [ -f $(BUILD_DIR)/compiler.env ]; then . $(BUILD_DIR)/compiler.env; fi
endef

# Detect compiler for coverage tools (works across platforms)
COVERAGE_TOOL = $(shell if [ -f $(BUILD_DIR)/compiler.env ]; then . $(BUILD_DIR)/compiler.env; fi; \
  if [ "$${CXX:-$(CXX)}" != "" ]; then b=$$(basename $${CXX}); else b=""; fi; \
  if [ "$$b" = "clang++" -o "$$b" = "clang" -o "$$b" = "clang-cl" ]; then echo llvm-cov; else echo gcov; fi)

PROFDATA_TOOL = $(shell if [ -f $(BUILD_DIR)/compiler.env ]; then . $(BUILD_DIR)/compiler.env; fi; \
  if [ "$${CXX:-$(CXX)}" != "" ]; then b=$$(basename $${CXX}); else b=""; fi; \
  if [ "$$b" = "clang++" -o "$$b" = "clang" -o "$$b" = "clang-cl" ]; then echo llvm-profdata; else echo gcov-tool; fi)

# test runner targets
RUN_TEST_EXE := $(BUILD_DIR)/falcon_core_cpp_run_tests$(EXE_SUFFIX)

run-all-tests:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@echo "--- Running all tests (llvm-cov path) on $(PLATFORM) ---"
	@LLVM_PROFILE_FILE="$(BUILD_DIR)/falcon_core_cpp_run_tests.profraw" \
		$(RUN_PREFIX) $(RUN_TEST_EXE)
	@llvm-profdata merge -sparse $(BUILD_DIR)/falcon_core_cpp_run_tests.profraw -o $(BUILD_DIR)/falcon_core_cpp_run_tests.profdata
else
	@echo "--- Running all tests (gcov path) on $(PLATFORM) ---"
ifeq ($(PLATFORM),linux)
	@GCOV_PREFIX="$(BUILD_DIR)" LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH $(RUN_TEST_EXE)
else
	@GCOV_PREFIX="$(BUILD_DIR)" $(RUN_PREFIX) $(RUN_TEST_EXE)
endif
endif

run-subset-tests:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@echo "--- Running subset of tests (llvm-cov) on $(PLATFORM) ---"
	@LLVM_PROFILE_FILE="$(BUILD_DIR)/falcon_core_cpp_run_tests.profraw" \
		$(RUN_PREFIX) $(RUN_TEST_EXE) --gtest_filter="$$(paste -sd: test_filter.txt)"
	@llvm-profdata merge -sparse $(BUILD_DIR)/falcon_core_cpp_run_tests.profraw -o $(BUILD_DIR)/falcon_core_cpp_run_tests.profdata
else
	@echo "--- Running subset of tests (gcov) on $(PLATFORM) ---"
	@$(RUN_PREFIX) $(RUN_TEST_EXE) --gtest_filter="$$(paste -sd: test_filter.txt)"
endif

cov-html:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov show $(BUILD_DIR)/libfalcon_core_cpp.so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata \
	  -format=html -output-dir=coverage_html \
	  -ignore-filename-regex='(vcpkg_installed|tests/)' \
	  -Xdemangler c++filt -Xdemangler -n
	@xdg-open coverage_html/index.html || true
else
	@gcovr -r . --html --html-details -o coverage_html/index.html || true
	@xdg-open coverage_html/index.html || true
endif

cov-term:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov show $(BUILD_DIR)/libfalcon_core_cpp.so -instr-profile=$(BUILD_DIR)/falcon_core_cpp_run_tests.profdata $(FILE) \
	  -ignore-filename-regex='(vcpkg_installed|tests/)' \
	  -Xdemangler c++filt -Xdemangler -n
else
	@gcovr src/ . --txt -f $(FILE)
endif

# Coverage meta-targets (same names as before)
subset-coverage-html: run-subset-tests cov-html
coverage-html: run-all-tests cov-html
subset-coverage: run-subset-tests cov-term
coverage: run-all-tests cov-term
subset-coverage-overview: subset-coverage

subset-coverage-overview: subset-coverage
coverage-overview: coverage

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
	@echo "--- Cleaning and building (dev) ---"
