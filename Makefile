# Additional makefile(s)..

# Include doc pipeline rules (ignore if missing)
-include ./code_docs/capi_docs/capi_docs.mk

# --------------------------------------------------------------------
# Top-level build/test/clean rules for cpp and c-api
# --------------------------------------------------------------------
CC ?= clang
CCX ?= clang++
USE_VCPKG ?= 0

.PHONY: all build build-dev build-devl test test-cpp test-c-api clean clean-all prepare-release

build:
	$(MAKE) -C cpp build USE_VCPKG=$(USE_VCPKG) CC=$(CC) CCX=$(CCX)
	$(MAKE) -C c-api build USE_VCPKG=$(USE_VCPKG) CC=$(CC) CCX=$(CCX)

build-dev:
	$(MAKE) -C cpp build-dev USE_VCPKG=$(USE_VCPKG) CC=$(CC) CCX=$(CCX)
	$(MAKE) -C c-api build-dev USE_VCPKG=$(USE_VCPKG) CC=$(CC) CCX=$(CCX)

build-devl: build-dev

test: test-cpp test-c-api

test-cpp:
	echo "Beginning testing the cpp"
	( $(MAKE) -C cpp coverage-overview ) > cpp-coverage-report.txt 2>&1

test-c-api:
	echo "Beginning testing the c-api"
	( $(MAKE) -C c-api coverage-overview ) > c-api-coverage-report.txt 2>&1

clean:
	$(MAKE) -C cpp clean
	$(MAKE) -C c-api clean
	rm cpp-coverage-report.txt c-api-coverage-report.txt

clean-all: clean
	$(MAKE) -C cpp clean-all
	$(MAKE) -C c-api clean-all

all: build

prepare-release:
	rm -rf out && mkdir -p out
	cp cpp/build/libfalcon_core_cpp.so out/
	cp c-api/build/libfalcon_core_c_api.so out/
	zip -r out/falcon-core.zip . -x "cpp/build/*" "c-api/build/*" ".git/*" ".venv/*" "dist/*" ".cache/*" "pybind/*" "go/*" "packaging/*" "cpp/vcpkg_installed/*" "vcpkg_installed/*"
	cd c-api && zip -r ../out/falcon-core-c-api-headers.zip include
	cd cpp && zip -r ../out/falcon-core-cpp-headers.zip include
