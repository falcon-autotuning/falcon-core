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

build-dev: setup-vcpkg generate_types 
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

clean:
	@echo "--- Cleaning build directory and compiled extension ---"
	@rm -rf $(C_API_BUILD_DIR)

clean-all: clean
	@echo "--- Cleaning vcpkg cache ---"
	@rm -rf $(VCPKG_INSTALLED)
