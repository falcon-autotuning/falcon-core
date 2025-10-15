# Makefile to simplify the CMake build process for falcon-core with vcpkg

.PHONY: all build build-part install test clean setup-vcpkg clean-all

# Variables
BUILD_DIR := build
PYTHON_DIST := dist/python
GO_DIST := dist/go
OUT_PYTHON_DIR := ${PYTHON_DIST}/src/falcon_core
CPP_TARGET := falcon_core_cpp

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
	@mkdir -p $(OUT_PYTHON_DIR)
	@cmake -G Ninja \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DCMAKE_C_COMPILER_LAUNCHER=ccache \
		-DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON \
		-DCMAKE_C_FLAGS="-O2" \
		-DCMAKE_CXX_FLAGS="-g -O2" \
		-DCMAKE_TOOLCHAIN_FILE="$$(vcpkg integrate install --triplet=x64-linux-dynamic | grep -o '/.*\.cmake' | head -n1)" \
		-DVCPKG_TARGET_TRIPLET=x64-linux-dynamic \
		-DCPP_TARGET=$(CPP_TARGET) \
		-DBUILD_TESTS=OFF \
		. -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@ninja -C $(BUILD_DIR) -d stats
	@echo "--- Build complete ---"

build-dev:
	@echo "--- Configuring and Building C++ Extension (dev, tests, coverage) ---"
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
		-DCMAKE_CXX_FLAGS="-g -O0 -fprofile-instr-generate -fcoverage-mapping" \
		-DCMAKE_TOOLCHAIN_FILE="$$(vcpkg integrate install --triplet=x64-linux-dynamic | grep -o '/.*\.cmake' | head -n1)" \
		-DVCPKG_TARGET_TRIPLET=x64-linux-dynamic \
		-DCPP_TARGET=$(CPP_TARGET) \
		-DBUILD_TESTS=ON \
		. -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@LD_LIBRARY_PATH=$(BUILD_DIR)/vcpkg_installed/x64-linux-dynamic/debug/lib:$$LD_LIBRARY_PATH ninja -C $(BUILD_DIR) -d stats
	@echo "--- Build complete ---"

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

install:
	@echo "--- Installing library and headers ---"
	@mkdir -p /usr/local/lib
	@mkdir -p /usr/local/include
	@cp $(BUILD_DIR)/libfalcon_core_cpp.so /usr/local/lib/
	@cp -r include/falcon_core_cpp /usr/local/include/
	@echo "--- Install complete ---"

uninstall:
	@echo "--- Uninstalling library and headers ---"
	@rm -f /usr/local/lib/libfalcon_core_cpp.so
	@rm -rf /usr/local/include/falcon_core_cpp
	@echo "--- Uninstall complete ---"

subset-coverage-overview: subset-coverage
	@llvm-cov report ./build/run_tests -instr-profile=run_tests.profdata \
		-ignore-filename-regex='(vcpkg_installed|tests/)' \
		-Xdemangler c++filt -Xdemangler -n                                                                     [15:00:01]

coverage-overview: coverage
	@llvm-cov report ./build/run_tests -instr-profile=run_tests.profdata -ignore-filename-regex='(vcpkg_installed|tests/)' -Xdemangler c++filt -Xdemangler -n                                                                     [15:00:01]

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

# Move the python types into the built package
python-types:
	@echo "--- Copying Python type stubs to the package directory ---"
	@cd $(PYTHON_DIST)/typings/falcon_core && \
	find . -name '*.pyi' | while read f; do \
	  mkdir -p "../../src/falcon_core/$$(dirname "$$f")"; \
	  echo "Copying $$f to $(OUT_PYTHON_DIR)/$$f"; \
	  cp "$$f" "../../src/falcon_core/$$f"; \
	done
	@touch $(PYTHON_DIST)/src/falcon_core/py.typed

setup-venv:
	@echo "--- Setting up Python virtual environment ---"
	uv venv --clear
	uv pip install './dist/python[test]' -v

python-test: clean build python-types setup-venv
	@echo "--- Prepared to run python tests ---"
	@while read testfile; do \
		pytest -W ignore::DeprecationWarning ${PYTHON_DIST}/tests/$$testfile; \
	done < python_test_filter.txt
