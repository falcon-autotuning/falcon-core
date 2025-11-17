# Makefile to simplify the CMake build process for falcon-core-c-api
.PHONY: all build clean clean-all
C_API_BUILD_DIR := build
CC ?= clang
CXX ?= clang++

VCPKG_TOOLCHAIN := $(shell vcpkg integrate install --triplet=x64-linux-dynamic | grep -o '/.*\.cmake' | head -n1)
CORE_ROOT := $(PWD)/../cpp
CORE_BUILD_DIR := $(CORE_ROOT)/build
VCPKG_INSTALLED := vcpkg_installed
VCPKG_DEBUG_LIB := $(PWD)/build/vcpkg_installed/x64-linux-dynamic/debug/lib
GENERATED_MANIFEST := generated_template_manifest.txt

USE_VCPKG ?= 1

ifeq ($(USE_VCPKG),1)
  TOOLCHAIN_ARG = -DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
									-DVCPKG_TARGET_TRIPLET=x64-linux-dynamic \
									-DVCPKG_INSTALLED_DIR=$(C_API_BUILD_DIR)/vcpkg_installed \
									-DCMAKE_PREFIX_PATH="$(CORE_BUILD_DIR);$(VCPKG_INSTALLED)/x64-linux-dynamic"
  VCPKG_ENV = VCPKG_FEATURE_FLAGS=fail-on-unavailable
else
  TOOLCHAIN_ARG = -DCMAKE_PREFIX_PATH="$(CORE_BUILD_DIR)"
  VCPKG_ENV =
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
	@echo "--- Configuring and Building C API with Ninja ---"
	@mkdir -p $(C_API_BUILD_DIR)
	@$(VCPKG_ENV) cmake -G Ninja \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		$(TOOLCHAIN_ARG) \
		-DCORE_ROOT=$(CORE_ROOT) \
		-DUSE_VCPKG=$(USE_VCPKG) \
   	-S . -B $(C_API_BUILD_DIR)
	@ninja -C $(C_API_BUILD_DIR)
	strip build/libfalcon_core_c_api.so
	@echo "--- Build complete. C API library is now in $(C_API_BUILD_DIR) ---"

build-dev: generate_types 
	@if [ ! -d "$(CORE_BUILD_DIR)" ]; then \
		echo "Error: C++ core must be built first (missing $(CORE_BUILD_DIR))."; \
		exit 1; \
	fi
	@echo "--- Configuring and Building C API with Ninja ---"
	@mkdir -p $(C_API_BUILD_DIR)
	@echo "CC=$(CC)" > $(C_API_BUILD_DIR)/compiler.env
	@echo "CXX=$(CXX)" >> $(C_API_BUILD_DIR)/compiler.env
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$(CORE_BUILD_DIR):$$LD_LIBRARY_PATH \
	$(VCPKG_ENV) cmake -G Ninja \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		$(TOOLCHAIN_ARG) \
		-DCORE_ROOT=$(CORE_ROOT) \
		-DUSE_VCPKG=$(USE_VCPKG) \
		-DFALCON_CORE_DEV=ON \
   	 -S . -B $(C_API_BUILD_DIR) 
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$(CORE_BUILD_DIR):$$LD_LIBRARY_PATH \
	ninja -C $(C_API_BUILD_DIR) -d stats
	@echo "--- Build complete. C API library is now in $(C_API_BUILD_DIR) ---"

define LOAD_COMPILER_ENV
  if [ -f $(C_API_BUILD_DIR)/compiler.env ]; then . $(BUILD_DIR)/compiler.env; fi
endef
# Detect compiler for coverage tools
COVERAGE_TOOL = $(shell [ -f $(C_API_BUILD_DIR)/compiler.env ] && . $(C_API_BUILD_DIR)/compiler.env; \
	[ "$$(basename $${CXX:-clang++})" = "clang++" ] && echo llvm-cov || echo gcov)

PROFDATA_TOOL = $(shell [ -f $(C_API_BUILD_DIR)/compiler.env ] && . $(C_API_BUILD_DIR)/compiler.env; \
	[ "$$(basename $${CXX:-clang++})" = "clang++" ] && echo llvm-profdata || echo gcov-tool)

# check coverage of entire module
run-all-tests:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@LLVM_PROFILE_FILE="$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profraw" LD_LIBRARY_PATH=$(C_API_BUILD_DIR):$(CORE_BUILD_DIR):$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests
	@llvm-profdata merge -sparse $(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profraw -o $(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata
else
	@GCOV_PREFIX="$(BUILD_DIR)" LD_LIBRARY_PATH=$(C_API_BUILD_DIR):$(CORE_BUILD_DIR):$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests
endif

#check coverage of all the modles listed in the test_filter.txt
run-subset-tests:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@LLVM_PROFILE_FILE="$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profraw" LD_LIBRARY_PATH=$(C_API_BUILD_DIR):$(CORE_BUILD_DIR):$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(BUILD_DIR)/falcon_core_c_api_run_tests --gtest_filter="$$(paste -sd: test_filter.txt)"
	@llvm-profdata merge -sparse $(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profraw -o $(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata
else
	@GCOV_PREFIX="$(BUILD_DIR)" LD_LIBRARY_PATH=$(C_API_BUILD_DIR):$(CORE_BUILD_DIR):$(VCPKG_DEBUG_LIB):$$LD_LIBRARY_PATH ./$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests --gtest_filter="$$(paste -sd: test_filter.txt)"
endif

# launches the interactive html for the entire coverage run
cov-html:
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov show ./$(C_API_BUILD_DIR)/libfalcon_core_c_api.so -instr-profile=$(C_APIBUILD_DIR)/falcon_core_c_api_run_tests.profdata \
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
	@llvm-cov show ./$(C_API_BUILD_DIR)/libfalcon_core_c_api.so -instr-profile=$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata $(FILE) \
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
	@llvm-cov report ./$(C_API_BUILD_DIR)/libfalcon_core_c_api.so -instr-profile=$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata \
		-ignore-filename-regex='(vcpkg_installed|tests/)' \
		-Xdemangler c++filt -Xdemangler -n
else
	@gcovr src/ . --txt --exclude 'vcpkg_installed|tests/'
endif

coverage-overview: coverage
ifeq ($(COVERAGE_TOOL),llvm-cov)
	@llvm-cov report ./$(C_API_BUILD_DIR)/libfalcon_core_c_api.so -instr-profile=$(C_API_BUILD_DIR)/falcon_core_c_api_run_tests.profdata \
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
