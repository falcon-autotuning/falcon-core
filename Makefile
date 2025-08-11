# Makefile to simplify the CMake build process for falcon-core

.PHONY: all build test clean

# Variables
BUILD_DIR := build

# Default target: build the project
all: build

# Configure and build the project using CMake
build:
	@echo "--- Configuring and Building Project ---"
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR)
	@$(MAKE) -C $(BUILD_DIR)
	@echo "--- Build complete ---"

# Run tests using CTest
test: build
	@echo "--- Running Tests ---"
	@cd $(BUILD_DIR) && ctest -V

# Clean up build artifacts
clean:
	@echo "--- Cleaning build directory ---"
	@rm -rf $(BUILD_DIR)
