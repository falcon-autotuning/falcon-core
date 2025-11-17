.PHONY: all build build-dev test test-cpp test-c-api clean clean-all

# Build both C++ and C API (release)
build:
	$(MAKE) -C cpp build USE_VCPKG=$(USE_VCPKG)
	$(MAKE) -C c-api build USE_VCPKG=$(USE_VCPKG)

# Build both C++ and C API (dev/tests/coverage)
build-dev:
	$(MAKE) -C cpp build-dev USE_VCPKG=$(USE_VCPKG)
	$(MAKE) -C c-api build-dev USE_VCPKG=$(USE_VCPKG)

# Run all tests in both cpp and c-api
test: test-cpp test-c-api

test-cpp:
	echo "Beginning testing the cpp"
	$(MAKE) -C cpp run-all-tests
	$(MAKE) -C cpp coverage-overview > cpp-coverage-report.txt

test-c-api:
	echo "Beginning testing the c-api"
	$(MAKE) -C c-api run-all-tests
	$(MAKE) -C c-api coverage-overview > c-api-coverage-report.txt

# Clean both
clean:
	$(MAKE) -C cpp clean
	$(MAKE) -C c-api clean

clean-all:
	$(MAKE) -C cpp clean-all
	$(MAKE) -C c-api clean-all

# Default target
all: build

prepare-release:
	rm -rf out && mkdir -p out
	cp cpp/build/libfalcon_core_cpp.so out/
	cp c-api/build/libfalcon_core_c_api.so out/
	zip -r out/falcon-core.zip . -x "cpp/build/*" "c-api/build/*" ".git/*" ".venv/*" "dist/*" ".cache/*" "pybind/*" "go/*" "packaging/*" "cpp/vcpkg_installed/*" "vcpkg_installed/*"
	cd c-api && zip -r ../out/falcon-core-c-api-headers.zip include
	cd cpp && zip -r ../out/falcon-core-cpp-headers.zip include

