C_API_BUILD_DIR := build
C_API_TARGET := falcon_core_c_api
VCPKG_TOOLCHAIN := $(shell vcpkg integrate install --triplet=x64-linux-dynamic | grep -o '/.*\.cmake' | head -n1)
CORE_ROOT := $(PWD)/../cpp
CORE_BUILD_DIR := $(CORE_ROOT)/build
VCPKG_INSTALLED := vcpkg_installed
VCPKG_DEBUG_LIB := $(PWD)/vcpkg_installed/x64-linux-dynamic/debug/lib
GENERATED_MANIFEST := generated_template_manifest.txt

.PHONY: all build clean clean-all

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
	@cmake -G Ninja \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DCMAKE_C_COMPILER_LAUNCHER=ccache \
		-DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON \
		-DCMAKE_C_FLAGS="-O0 -fprofile-instr-generate -fcoverage-mapping" \
		-DCMAKE_CXX_FLAGS="-g -O0 -fprofile-instr-generate -fcoverage-mapping" \
  	-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
   	-DVCPKG_INSTALLED_DIR=$(PWD)/vcpkg_installed \
		-DVCPKG_TARGET_TRIPLET=x64-linux \
		-DCMAKE_PREFIX_PATH="$(CORE_BUILD_DIR);$(VCPKG_INSTALLED)/x64-linux" \
   	-DC_API_TARGET=$(C_API_TARGET) \
		-DCORE_ROOT=$(CORE_ROOT) \
   	-S . -B $(C_API_BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@ninja -C $(C_API_BUILD_DIR) -d stats
	@echo "--- Build complete. C API library is now in $(C_API_BUILD_DIR) ---"

build-dev: generate_types 
	@if [ ! -d "$(CORE_BUILD_DIR)" ]; then \
		echo "Error: C++ core must be built first (missing $(CORE_BUILD_DIR))."; \
		exit 1; \
	fi
	@echo "--- Configuring and Building C API with Ninja ---"
	@mkdir -p $(C_API_BUILD_DIR)
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$(CORE_BUILD_DIR):$$LD_LIBRARY_PATH \
	cmake -G Ninja \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DCMAKE_C_COMPILER_LAUNCHER=ccache \
		-DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON \
		-DCMAKE_C_FLAGS="-O0 -fprofile-instr-generate -fcoverage-mapping" \
		-DCMAKE_CXX_FLAGS="-g -O0 -fprofile-instr-generate -fcoverage-mapping" \
  	-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
		-DVCPKG_TARGET_TRIPLET=x64-linux-dynamic \
		-DCMAKE_PREFIX_PATH="$(CORE_BUILD_DIR);$(VCPKG_INSTALLED)/x64-linux-dynamic" \
   	-DC_API_TARGET=$(C_API_TARGET) \
		-DCORE_ROOT=$(CORE_ROOT) \
		-DBUILD_TESTS=ON \
   	 -S . -B $(C_API_BUILD_DIR) 
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$(CORE_BUILD_DIR):$$LD_LIBRARY_PATH \
	ninja -C $(C_API_BUILD_DIR) -d stats
	@echo "--- Build complete. C API library is now in $(C_API_BUILD_DIR) ---"

# check coverage of entire module
run-all-tests:
	@LLVM_PROFILE_FILE="run_tests.profraw" LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$(CORE_BUILD_DIR):$$LD_LIBRARY_PATH ./build/run_tests
	@llvm-profdata merge -sparse run_tests.profraw -o run_tests.profdata

#check coverage of all the modles listed in the test_filter.txt
run-subset-tests:
	@LLVM_PROFILE_FILE="build/run_tests.profraw" ./build/run_tests --gtest_filter="$$(paste -sd: test_filter.txt)"
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
	@llvm-cov report ./build/lib$(C_API_TARGET).so -instr-profile=run_tests.profdata \
		-ignore-filename-regex='(cpp/include/)' \
		-Xdemangler c++filt -Xdemangler -n                                                                     [15:00:01]

coverage-overview: coverage
	@llvm-cov report ./build/lib$(C_API_TARGET).so -instr-profile=run_tests.profdata -ignore-filename-regex='(cpp/include/)' -Xdemangler c++filt -Xdemangler -n                                                                     [15:00:01]

clean:
	@echo "--- Cleaning build directory and compiled extension ---"
	@rm -rf $(C_API_BUILD_DIR)
	@if [ -f $(GENERATED_MANIFEST) ]; then \
		while read -r f; do [ -n "$$f" ] && rm "$$f"; done < $(GENERATED_MANIFEST); \
		: > $(GENERATED_MANIFEST); \
	fi

clean-all: clean
	@echo "--- Cleaning vcpkg cache ---"
	@rm -rf $(VCPKG_INSTALLED)

debug-test:
	LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$(CORE_BUILD_DIR):$$LD_LIBRARY_PATH \
	gdb --args build/run_tests --gtest_filter="GateRelationsCAPI_Fixture.InitConstructor"
