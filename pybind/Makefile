CORE_PY_ROOT := ../dist/python
PYTHON_PACKAGE_DIR := ${CORE_PY_ROOT}/src/falcon_core
BUILD_DIR := build

.PHONY: all build clean
all: setup-vcpkg build

setup-vcpkg:
	@echo "--- Setting up vcpkg ---"
	@which vcpkg > /dev/null 2>&1 || (echo "Error: vcpkg not found in PATH. Please install vcpkg and add it to your PATH."; exit 1)
	@echo "Using vcpkg from: $$(which vcpkg)"
	@echo "Installing dependencies..."
	@vcpkg install --triplet=x64-linux

build:
	@echo "--- Configuring and Building pybind11 modules with Ninja ---"
	@mkdir -p $(BUILD_DIR)
	@cmake -G Ninja \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DCMAKE_C_COMPILER_LAUNCHER=ccache \
		-DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON \
		-DCMAKE_C_FLAGS="-O0 -fprofile-instr-generate -fcoverage-mapping" \
		-DCMAKE_CXX_FLAGS="-g -O0 -fprofile-instr-generate -fcoverage-mapping" \
		-DCMAKE_TOOLCHAIN_FILE="$$(vcpkg integrate install --triplet=x64-linux | grep -o '/.*\.cmake' | head -n1)" \
		-DVCPKG_TARGET_TRIPLET=x64-linux \
		. -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@ninja -C $(BUILD_DIR) -d stats
	@echo "--- Build complete. Pybind11 modules are now in the output directories ---"

clean:
	@if [ "$(PYTHON_PACKAGE_DIR)" = "../dist/python/src/falcon_core" ] && [ -d "$(PYTHON_PACKAGE_DIR)" ]; then \
		echo "Cleaning $(PYTHON_PACKAGE_DIR) ..."; \
		rm -rf $(PYTHON_PACKAGE_DIR)/*; \
		rm -rf $(PYTHON_PACKAGE_DIR)/.[!.]*; \
	else \
		echo "Error: PYTHON_PACKAGE_DIR is not set correctly or does not exist!"; \
		exit 1; \
	fi
	@if [ "$(BUILD_DIR)" = "build" ] && [ -d "$(BUILD_DIR)" ]; then \
		echo "Cleaning $(BUILD_DIR) ..."; \
		rm -rf $(BUILD_DIR)/*; \
		rm -rf $(BUILD_DIR)/.[!.]*; \
	else \
		echo "Error: BUILD_DIR is not set correctly or does not exist!"; \
		exit 1; \
	fi

# Clean everything including vcpkg cache
clean-all: clean
	@echo "--- Cleaning vcpkg cache ---"
	@rm -rf vcpkg_installed

setup-venv:
	@echo "--- Setting up Python virtual environment ---"
	uv venv --clear
	uv pip install '../dist/python[test]' -v

python-test: clean build python-types setup-venv
	@echo "--- Prepared to run python tests ---"
	@while read testfile; do \
		pytest -W ignore::DeprecationWarning ${CORE_PY_ROOT}/tests/$$testfile; \
	done < python_test_filter.txt

# Move the python types into the built package
python-types:
	@echo "--- Copying Python type stubs to the package directory ---"
	@cd $(CORE_PY_ROOT)/typings/falcon_core && \
	find . -name '*.pyi' | while read f; do \
	  mkdir -p "../../src/falcon_core/$$(dirname "$$f")"; \
	  echo "Copying $$f to $(PYTHON_PACKAGE_DIR)/$$f"; \
	  cp "$$f" "../../src/falcon_core/$$f"; \
	done
	@touch $(CORE_PY_ROOT)/src/falcon_core/py.typed
