-include ./code_docs/capi_docs/capi_docs.mk

# Platform detection (works on Linux, MINGW/MSYS, and native Windows)
UNAME_S := $(shell uname -s 2>/dev/null || echo Unknown)
IS_MINGW := $(findstring MINGW,$(UNAME_S))
IS_CYGWIN := $(findstring CYGWIN,$(UNAME_S))
IS_WINDOWS_NT := $(filter Windows_NT,$(OS))
GENERATED_MANIFEST := generated_template_manifest.txt
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
  CMAKE_GENERATOR := Ninja
  VCPKG_TRIPLET := x64-windows
  VCPKG_DEBUG_BIN := $(PWD)/vcpkg_installed/x64-windows/bin
  VCPKG_RELEASE_LIB := $(PWD)/vcpkg_installed/x64-windows/lib
  EXE_SUFFIX := .exe
  NPROC := 4
  STRIP_CMD := # no-op (strip not usually present); set to "llvm-strip" if you have it
	RUN_PREFIX := PATH=$(VCPKG_DEBUG_BIN):$(VCPKG_RELEASE_LIB):$$PATH
	SUDO ?= sudo
  PYTHON_EXECUTABLE ?= python
  # On Windows, Ninja + clang-cl: still pass CMAKE_C_COMPILER / CMAKE_CXX_COMPILER
else
  CMAKE_GENERATOR := Ninja
  VCPKG_TRIPLET := x64-linux-dynamic
  VCPKG_DEBUG_LIB := $(PWD)/vcpkg_installed/x64-linux-dynamic/debug/lib
  VCPKG_RELEASE_LIB := $(PWD)/vcpkg_installed/x64-linux-dynamic/lib
  EXE_SUFFIX :=
  NPROC := $(shell nproc 2>/dev/null || echo 4)
  STRIP_CMD := strip
	RUN_PREFIX := LD_LIBRARY_PATH=$(VCPKG_DEBUG_LIB):$(VCPKG_RELEASE_LIB):$$LD_LIBRARY_PATH
	SUDO :=
	PYTHON_EXECUTABLE ?= python3
	export CC=clang
	export CXX=clang++
endif

# Paths
ENV_FILE := .nuget-credentials
ifeq ($(wildcard $(ENV_FILE)),)
  $(info [Makefile] $(ENV_FILE) not found, skipping environment sourcing)
else
  include $(ENV_FILE)
  export $(shell sed 's/=.*//' $(ENV_FILE) | xargs)
  $(info [Makefile] Loaded environment from $(ENV_FILE))
endif
# ── Paths ─────────────────────────────────────────────────────────────────────
VCPKG_ROOT ?= $(CURDIR)/vcpkg
VCPKG_TOOLCHAIN ?= $(VCPKG_ROOT)/scripts/buildsystems/vcpkg.cmake
VCPKG_INSTALLED_DIR ?= $(CURDIR)/vcpkg_installed
FEED_URL ?= 
NUGET_API_KEY ?=
FEED_NAME ?= 
USERNAME ?=
VCPKG_BINARY_SOURCES ?= ""
ifeq ($(strip $(FEED_URL)),)
  CMAKE_VCPKG_BINARY_SOURCES :=
else
	VCPKG_BINARY_SOURCES := "clear;nuget,$(FEED_URL),readwrite"
  CMAKE_VCPKG_BINARY_SOURCES := -DVCPKG_BINARY_SOURCES=$(VCPKG_BINARY_SOURCES)
endif

BUILD_DIR_DEBUG := build/debug
BUILD_DIR_RELEASE := build/release

INSTALL_PREFIX ?= /opt/falcon
INSTALL_LIBDIR := $(INSTALL_PREFIX)/lib
INSTALL_INCLUDEDIR := $(INSTALL_PREFIX)/include

.PHONY: vcpkg-bootstrap
vcpkg-bootstrap:
	@if [ ! -d "$(VCPKG_ROOT)" ]; then \
		echo "Cloning vcpkg..."; \
		git clone https://github.com/microsoft/vcpkg.git $(VCPKG_ROOT); \
	fi
	@if [ ! -f "$(VCPKG_ROOT)/vcpkg" ]; then \
		echo "Bootstrapping vcpkg..."; \
		if [ "$$(uname -s | grep -i 'mingw\|msys\|cygwin')" ]; then \
			echo "Skipping since on windows"; \
		else \
			cd $(VCPKG_ROOT) && ./bootstrap-vcpkg.sh; \
		fi \
	fi

setup-nuget-auth:
	@if [ -z "$$NUGET_API_KEY" ]; then \
		echo "No .nuget_api_key or NUGET_API_KEY found, skipping NuGet setup (local-only build, no binary cache)."; \
		exit 0; \
	fi
	@echo "Setting up NuGet authentication for vcpkg binary caching..."
	@if [ "$$(uname -s 2>/dev/null)" != "Windows_NT" ] && [ "$$(uname -o 2>/dev/null)" != "Msys" ] && [ "$$(uname -o 2>/dev/null)" != "Cygwin" ]; then \
		if ! command -v mono >/dev/null 2>&1; then \
			echo "Error: mono is not installed. Please install mono (e.g., 'sudo pacman -S mono' on Arch, 'sudo apt install mono-complete' on Ubuntu)."; \
			exit 1; \
		fi; \
	fi
	@NUGET_EXE=$$(vcpkg fetch nuget | tail -n1); \
	if [ "$$(uname -s 2>/dev/null)" = "Linux" ]; then \
		MONO_PREFIX="mono "; \
	else \
		MONO_PREFIX=""; \
	fi; \
	$$MONO_PREFIX"$$NUGET_EXE" sources remove -Name "$(FEED_NAME)" || true; \
	$$MONO_PREFIX"$$NUGET_EXE" sources add -Name "$(FEED_NAME)" -Source "$(FEED_URL)" -Username "$(USERNAME)" -Password "$(NUGET_API_KEY)";

.PHONY: vcpkg-install-deps
vcpkg-install-deps: setup-nuget-auth 
	@echo "Installing vcpkg dependencies" 
	@echo "The binary sources are: $(VCPKG_BINARY_SOURCES)"
	VCPKG_FEATURE_FLAGS=binarycaching \
		vcpkg install \
		--overlay-ports=./ports \
		--binarysource=$(VCPKG_BINARY_SOURCES) \
		--triplet="$(VCPKG_TRIPLET)"

check-vcpkg: vcpkg-bootstrap  vcpkg-install-deps
	@echo "Checking vcpkg configuration..."
	@if [ ! -d "$(VCPKG_ROOT)" ]; then \
		echo "Error: vcpkg not found at $(VCPKG_ROOT)"; \
		echo "Run 'make deps' in the parent directory first"; \
		exit 1; \
	fi
	@if [ ! -f "$(VCPKG_TOOLCHAIN)" ]; then \
		echo "Error: vcpkg toolchain not found at $(VCPKG_TOOLCHAIN)"; \
		exit 1; \
	fi
	@echo "✓ vcpkg configuration OK"

generate_types:
	@test -f ${GENERATED_MANIFEST} || touch ${GENERATED_MANIFEST} 
		@$(PYTHON_EXECUTABLE) generate_templated_types.py --manifest $(GENERATED_MANIFEST)

configure-debug: check-vcpkg generate_types
	@echo "Configuring debug build..."
	@mkdir -p $(BUILD_DIR_DEBUG)
	cd $(BUILD_DIR_DEBUG) && cmake ../.. \
		-DCMAKE_BUILD_TYPE=Debug \
		-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
		-DVCPKG_INSTALLED_DIR=$(VCPKG_INSTALLED_DIR) \
		-DVCPKG_TARGET_TRIPLET=$(VCPKG_TRIPLET) \
		-DBUILD_TESTS=ON \
		-DUSE_CCACHE=ON \
		-DENABLE_PCH=ON \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		$(CMAKE_VCPKG_BINARY_SOURCES) \
		-DFALCON_CORE_BUILD_C_API=ON \
		-DVCPKG_OVERLAY_PORTS=../../ports \
		-G $(CMAKE_GENERATOR)
	@echo "✓ Debug build configured"

configure-release: check-vcpkg generate_types
	@echo "Configuring release build..."
	@mkdir -p $(BUILD_DIR_RELEASE)
	cd $(BUILD_DIR_RELEASE) && cmake ../.. \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
		-DVCPKG_INSTALLED_DIR=$(VCPKG_INSTALLED_DIR) \
		-DVCPKG_TARGET_TRIPLET=$(VCPKG_TRIPLET) \
		-DBUILD_TESTS=ON \
		-DUSE_CCACHE=ON \
		-DENABLE_PCH=ON \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		$(CMAKE_VCPKG_BINARY_SOURCES) \
		-DFALCON_CORE_BUILD_C_API=ON \
		-DVCPKG_OVERLAY_PORTS=../../ports \
		-G $(CMAKE_GENERATOR)
	@echo "✓ Release build configured"
.PHONY: all build build-dev build-devl test test-cpp test-c-api clean clean-all prepare-release

configure: configure-debug configure-release

build-debug: configure-debug
	@echo "Building debug..."
	cmake --build $(BUILD_DIR_DEBUG) -- -j$(NPROC)
	@echo "✓ Debug build complete"
	@$(MAKE) clangd-helpers

build-release: configure-release
	@echo "Building release..."
	cmake --build $(BUILD_DIR_RELEASE) -- -j$(NPROC)
	@echo "✓ Release build complete"

install: build-release
	@echo "Installing falcon-core to $(INSTALL_PREFIX)..."
	$(SUDO) cmake --install $(BUILD_DIR_RELEASE) --prefix $(INSTALL_PREFIX)
	@echo "Copying vcpkg headers and libraries..."
	$(SUDO) cp -r $(VCPKG_INSTALLED_DIR)/$(VCPKG_TRIPLET)/include/* $(INSTALL_INCLUDEDIR)/
	$(SUDO) cp -r $(VCPKG_INSTALLED_DIR)/$(VCPKG_TRIPLET)/lib/* $(INSTALL_LIBDIR)/
	$(SUDO) cp -r $(VCPKG_INSTALLED_DIR)/$(VCPKG_TRIPLET)/bin/* $(INSTALL_LIBDIR)/ || true
	@echo "✓ Installation complete"

clean:
	@echo "Cleaning build artifacts and test containers..."
	rm -rf $(BUILD_DIR_DEBUG) $(BUILD_DIR_RELEASE) build/ compile_commands.json ./vcpkg_installed/
	@echo "✓ Clean complete"

.PHONY: clangd-helpers
clangd-helpers:
	@if [ -f $(BUILD_DIR_DEBUG)/compile_commands.json ]; then \
		ln -sf $(BUILD_DIR_DEBUG)/compile_commands.json compile_commands.json; \
		echo "✓ clangd compile_commands.json symlinked"; \
	fi

test: build-release
	@echo "Running release tests..."
	cd $(BUILD_DIR_RELEASE) && ctest --output-on-failure
	@echo "✓ Tests passed"

test-debug: build-debug
	@echo "Running debug tests..."
	cd $(BUILD_DIR_DEBUG) && ctest --output-on-failure
	@echo "✓ Tests passed"

run-serialization-test:
	@$(BUILD_DIR)/integration_serialize_connection --output test.json --name "MyGate" --type PlungerGate
	@$(BUILD_DIR)/integration_deserialize_connection --input test.json --name "MyGate" --type PlungerGate
	@rm test.json
	@$(C_API_BUILD_DIR)/integration_serialize_connection_c --output test.json --name "MyGate" --type PlungerGate
	@$(C_API_BUILD_DIR)/integration_deserialize_connection_c --input test.json --name "MyGate" --type PlungerGate
	@rm test.json
