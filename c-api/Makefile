C_API_BUILD_DIR := build
C_API_TARGET := falcon_core_c_api
VCPKG_TOOLCHAIN := ../vcpkg/scripts/buildsystems/vcpkg.cmake
CORE_BUILD_DIR := ../build
VCPKG_INSTALLED := ../vcpkg_installed
SO_DIRECTORY := ../dist/c_api

.PHONY: all build clean clean-all

all: build

generate_pair:
	@python3 ./generate_pair.py

generate_list:
	@python3 ./generate_list.py

generate_map:
	@python3 ./generate_map.py

build: generate_pair generate_list generate_map
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
		-DCMAKE_TOOLCHAIN_FILE="$(VCPKG_ROOT)/scripts/buildsystems/vcpkg.cmake" \
		-DVCPKG_TARGET_TRIPLET=x64-linux \
		-DCMAKE_PREFIX_PATH="$(CORE_BUILD_DIR);$(VCPKG_INSTALLED)/x64-linux" \
		-S . -B $(C_API_BUILD_DIR)
	@if [ ! -e compile_commands.json ]; then ln -s build/compile_commands.json .; fi
	@ninja -C $(C_API_BUILD_DIR) -d stats
	@echo "--- Build complete. C API library is now in $(C_API_BUILD_DIR) ---"

clean:
	@if [ -d "$(C_API_BUILD_DIR)" ]; then \
		echo "Cleaning $(C_API_BUILD_DIR) ..."; \
		rm -rf $(C_API_BUILD_DIR)/*; \
		rm -rf $(C_API_BUILD_DIR)/.[!.]*; \
	else \
		echo "Error: C_API_BUILD_DIR is not set correctly or does not exist!"; \
		exit 1; \
	fi
	@if [ -d "$(SO_DIRECTORY)" ]; then \
		echo "Cleaning $(SO_DIRECTORY) ..."; \
		rm -rf $(SO_DIRECTORY)/*; \
		rm -rf $(SO_DIRECTORY)/.[!.]*; \
	else \
		echo "Error: SO_DIRECTORY is not set correctly or does not exist!"; \
		exit 1; \
	fi

clean-all: clean
	@echo "--- Cleaning vcpkg cache ---"
	@rm -rf $(VCPKG_INSTALLED)
