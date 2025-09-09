# Makefile to simplify the CMake build process for falcon-core

.PHONY: all build build-part install test clean

# Variables
BUILD_DIR := build
OUT_PYTHON_DIR := src/falcon_core

# Default target: build the project
all: build

# Configure and build the project using CMake
# This compiles the C++ code and places the Python extension in src/falcon_core
build:
	@echo "--- Configuring and Building C++ Extension ---"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OUT_PYTHON_DIR)
	@cmake -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_BUILD_WITH_INSTALL_RPATH=ON -DCMAKE_CXX_FLAGS="-g -O0" . -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@ninja -C $(BUILD_DIR) -d stats
	@echo "--- Build complete. Python extension is now in src/falcon_core/ ---"

# Build only selected sources and tests
# Example:
# make build-part DIRS="src/physics;src/utils" TESTS="tests/test_unit.cpp;tests/test_song.cpp"
build-part:
	@echo "--- Configuring and Building Selected Parts: $(DIRS), Tests: $(TESTS) ---"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OUT_PYTHON_DIR)
	@cmake -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_BUILD_WITH_INSTALL_RPATH=ON -DCMAKE_CXX_FLAGS="-g -O0" -DFALCON_CORE_DIRS="$(DIRS)" -DFALCON_CORE_TESTS="$(TESTS)" . -S . -B $(BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@ninja -C $(BUILD_DIR) -d stats
	@echo "--- Partial build complete. Python extension is now in src/falcon_core/ ---"

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

test-make-cpp:
	@gcc

docker-build:
	docker-compose build
docker-shell:
	docker-compose run --rm falcon-core
docker-make:
	docker-compose run --rm falcon-core make
docker-build-cpp:
	docker-compose run --rm falcon-core make build
docker-test:
	docker-compose run --rm falcon-core make test
docker-clean:
	docker-compose run --rm falcon-core make clean
docker-install:
	docker-compose run --rm falcon-core make install
