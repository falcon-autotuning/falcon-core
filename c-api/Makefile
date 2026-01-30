# Makefile to simplify the CMake build process for falcon-core-c-api
.PHONY: all build clean clean-all

# Base paths
C_API_DIR := $(abspath $(CURDIR))
C_API_BUILD_DIR := $(C_API_DIR)/build
PWD := $(C_API_DIR)
CORE_ROOT := $(C_API_DIR)/../cpp
CORE_BUILD_DIR := $(CORE_ROOT)/build
GENERATED_MANIFEST := generated_template_manifest.txt

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

CC ?= clang
CXX ?= clang++

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
	RUN_PREFIX := PATH=$(VCPKG_DEBUG_BIN):$(CORE_BUILD_DIR):$$PATH
	VCPKG_TOOLCHAIN ?= $(CORE_ROOT)/../../../vcpkg/scripts/buildsystems/vcpkg.cmake
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
	RUN_PREFIX := LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$(CORE_BUILD_DIR):$$LD_LIBRARY_PATH
	USE_VCPKG ?= 0
endif

ifeq ($(USE_VCPKG),1)
  VCPKG_INSTALLED := vcpkg_installed
  # attempt to discover a usable vcpkg toolchain file (may differ by platform)
  TOOLCHAIN_ARG = -DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
									-DVCPKG_TARGET_TRIPLET=x64-linux-dynamic \
									-DVCPKG_INSTALLED_DIR=$(C_API_BUILD_DIR)/vcpkg_installed \
									-DCMAKE_PREFIX_PATH="$(CORE_BUILD_DIR);$(VCPKG_INSTALLED)/x64-linux-dynamic"
  VCPKG_ENV := VCPKG_FEATURE_FLAGS=fail-on-unavailable
else
  TOOLCHAIN_ARG :=
  VCPKG_ENV :=
endif


all: build

# Setup vcpkg toolchain
setup-vcpkg:
	@echo "--- Setting up vcpkg ---"
	@which vcpkg > /dev/null 2>&1 || (echo "Error: vcpkg not found in PATH. Please install vcpkg and add it to your PATH."; exit 1)
	@echo "Using vcpkg from: $$(which vcpkg)"
	@echo "Installing dependencies..."
	@vcpkg install --triplet=x64-linux-dynamic

generate_types:
	@test -f ${GENERATED_MANIFEST} || touch ${GENERATED_MANIFEST} 
	@python3 ./generate_templated_types.py --manifest $(GENERATED_MANIFEST)

build: generate_types 
	@if [ ! -d "$(CORE_BUILD_DIR)" ]; then \
		echo "Error: C++ core must be built first (missing $(CORE_BUILD_DIR))."; \
		exit 1; \
	fi
	@echo "--- Configuring and Building C-API (release, no tests) on $(PLATFORM) ---"
	@mkdir -p $(C_API_BUILD_DIR)
ifeq ($(PLATFORM), linux)
	@$(VCPKG_ENV) cmake -G Ninja \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		$(TOOLCHAIN_ARG) \
		-DCORE_ROOT=$(CORE_ROOT) \
		-DUSE_VCPKG=$(USE_VCPKG) \
   	-S . -B $(C_API_BUILD_DIR)
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
endif
	ninja -C $(C_API_BUILD_DIR) -j $(shell nproc 2>/dev/null || echo 1)
	@if [ -n "$(STRIP_CMD)" ]; then $(STRIP_CMD) $(BUILD_DIR)/libfalcon_core_cpp.so 2>/dev/null || true; fi
	@echo "--- Build complete. C API library is now in $(C_API_BUILD_DIR) ---"

build-dev: generate_types 
	@if [ ! -d "$(CORE_BUILD_DIR)" ]; then \
		echo "Error: C++ core must be built first (missing $(CORE_BUILD_DIR))."; \
		exit 1; \
	fi
	@echo "--- Configuring and Building C-API Extension (dev, tests, coverage) on $(PLATFORM) ---"
	@mkdir -p $(C_API_BUILD_DIR)
	@echo "CC=$(CC)" > $(C_API_BUILD_DIR)/compiler.env
	@echo "CXX=$(CXX)" >> $(C_API_BUILD_DIR)/compiler.env
ifeq ($(PLATFORM), linux)
	@$(RUN_PREFIX) $(VCPKG_ENV) cmake -G Ninja \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		$(TOOLCHAIN_ARG) \
		-DCORE_ROOT=$(CORE_ROOT) \
		-DUSE_VCPKG=$(USE_VCPKG) \
		-DFALCON_CORE_DEV=ON \
   	 -S . -B $(C_API_BUILD_DIR) 
else
	@echo "--- Running Windows-style cmake + ninja (using variables) ---"
	@$(RUN_PREFIX) $(VCPKG_ENV) cmake -B build -S . -G "Ninja" \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
		-DVCPKG_MANIFEST_DIR=./ \
		-DVCPKG_INSTALLED_DIR=$(PWD)/build/vcpkg_installed \
		-DCMAKE_BUILD_TYPE=Release \
		-DFALCON_CORE_DEV=ON \
		-DUSE_VCPKG=$(USE_VCPKG)
endif
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@$(RUN_PREFIX) ninja -C $(C_API_BUILD_DIR) -j $(shell nproc 2>/dev/null || echo 1) -d stats
	@echo "--- Build complete. C API library is now in $(C_API_BUILD_DIR) ---"

define LOAD_COMPILER_ENV
  if [ -f $(C_API_BUILD_DIR)/compiler.env ]; then . $(C_API_BUILD_DIR)/compiler.env; fi
endef
# Detect compiler for coverage tools
COVERAGE_TOOL = $(shell [ -f $(C_API_BUILD_DIR)/compiler.env ] && . $(C_API_BUILD_DIR)/compiler.env; \
	[ "$$(basename $${CXX:-clang++})" = "clang++" ] && echo llvm-cov || echo gcov)

PROFDATA_TOOL = $(shell [ -f $(C_API_BUILD_DIR)/compiler.env ] && . $(C_API_BUILD_DIR)/compiler.env; \
	[ "$$(basename $${CXX:-clang++})" = "clang++" ] && echo llvm-profdata || echo gcov-tool)

# check coverage of entire module
run-all-tests:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@echo "--- Running all tests (llvm-cov path) on $(PLATFORM) ---"
	@LLVM_PROFILE_FILE="$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profraw" \
		$(RUN_PREFIX) $(RUN_TEST_EXE)
	@llvm-profdata merge -sparse $(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profraw -o $(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata
else
	@echo "--- Running all tests (gcov path) on $(PLATFORM) ---"
	@GCOV_PREFIX="$(BUILD_DIR)" $(RUN_PREFIX) $(RUN_TEST_EXE)
endif

#check coverage of all the modles listed in the test_filter.txt
run-subset-tests:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@echo "--- Running subset of tests (llvm-cov) on $(PLATFORM) ---"
	@LLVM_PROFILE_FILE="$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profraw" \
		$(RUN_PREFIX) $(RUN_TEST_EXE) --gtest_filter="$$(paste -sd: test_filter.txt)"
	@llvm-profdata merge -sparse $(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profraw -o $(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata
else
	@echo "--- Running subset of tests (gcov) on $(PLATFORM) ---"
	@GCOV_PREFIX="$(C_API_BUILD_DIR)" $(RUN_PREFIX) $(RUN_TEST_EXE) --gtest_filter="$$(paste -sd: test_filter.txt)"
endif

# launches the interactive html for the entire coverage run
cov-html:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov show $(C_API_BUILD_DIR)/libfalcon_core_c_api.so -instr-profile=$(C_APIBUILD_DIR)/falcon_core_c_api_run_tests.profdata \
	  -format=html -output-dir=coverage_html \
	  -ignore-filename-regex='(vcpkg_installed|tests/)' \
	  -Xdemangler c++filt -Xdemangler -n
	@xdg-open coverage_html/index.html
else
	@gcovr -r . --html --html-details -o coverage_html/index.html
	@xdg-open coverage_html/index.html
endif

# Usage: make coverage-term FILE=/path/to/source.cpp
cov-term:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov show $(C_API_BUILD_DIR)/libfalcon_core_c_api.so -instr-profile=$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata $(FILE) \
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
	@llvm-cov report $(C_API_BUILD_DIR)/libfalcon_core_c_api.so -instr-profile=$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata \
		-ignore-filename-regex='(vcpkg_installed|tests/)' \
		-Xdemangler c++filt -Xdemangler -n
else
	@gcovr src/ . --txt --exclude 'vcpkg_installed|tests/'
endif

coverage-overview: coverage
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov report $(C_API_BUILD_DIR)/libfalcon_core_c_api.so -instr-profile=$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata \
		-ignore-filename-regex='(vcpkg_installed|tests/|cpp/)' \
		-Xdemangler c++filt -Xdemangler -n
else
	@gcovr src/ . --txt --exclude 'vcpkg_installed|tests/'
endif

clean:
	@echo "--- Cleaning build directory and compiled extension ---"
	@rm -rf $(C_API_BUILD_DIR)
	@if [ -f $(GENERATED_MANIFEST) ]; then \
		while read -r f; do [ -n "$$f" ] && rm "$$f"; done < $(GENERATED_MANIFEST); \
		: > $(GENERATED_MANIFEST); \
	fi

clean-all: clean
	@echo "--- Cleaning vcpkg cache ---"
ifeq ($(USE_VCPKG),1)
	@echo "--- Cleaning vcpkg cache ---"
	@rm -rf $(VCPKG_INSTALLED)
endif

rebuild-dev: clean-all build-dev
	@echo "--- Cleaning and building (dev)"

debug-gtest:
	LD_LIBRARY_PATH=$(C_API_BUILD_DIR):$(CORE_BUILD_DIR):$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH \
	gdb --args $(C_API_BUILD_DIR)/falcon_core_c_api_run_tests --gtest_filter="$(TEST)"
