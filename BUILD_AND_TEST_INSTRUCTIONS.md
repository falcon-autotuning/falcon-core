# Build and Test Instructions for falcon-core

This document provides comprehensive instructions for compiling the C++ and C-API code in the falcon-core repository and running the necessary tests. These instructions are derived from the GitHub Actions workflows in `.github/workflows/`.

## Table of Contents

1. [Prerequisites](#prerequisites)
2. [Ubuntu 22.04 Build Instructions](#ubuntu-2204-build-instructions)
3. [Arch Linux Build Instructions](#arch-linux-build-instructions)
4. [Fedora Build Instructions](#fedora-build-instructions)
5. [Windows Build Instructions](#windows-build-instructions)
6. [Using the Root Makefile](#using-the-root-makefile)
7. [Understanding Coverage Reports](#understanding-coverage-reports)
8. [Troubleshooting](#troubleshooting)

---

## Prerequisites

### Common Requirements

All platforms require:
- A C++ compiler (clang or gcc, clang is preferred)
- CMake (version >= 3.21)
- Ninja build system
- ccache (optional, but recommended for faster builds)
- Git

### Dependency Management

This project uses two approaches for dependency management:

1. **vcpkg** (recommended for development): Automatically manages C++ dependencies
2. **System packages**: Use native package managers (apt, pacman, dnf, etc.)

The build system supports both modes via the `USE_VCPKG` flag:
- `USE_VCPKG=1` (default): Use vcpkg for dependencies
- `USE_VCPKG=0`: Use system-installed packages

---

## Ubuntu 22.04 Build Instructions

### Step 1: Install System Dependencies

```bash
sudo apt-get update
sudo apt-get install -y \
  build-essential \
  clang \
  llvm \
  lld \
  ninja-build \
  cmake \
  ccache \
  curl \
  libhdf5-dev \
  libyaml-cpp-dev \
  libssl-dev \
  libsqlite3-dev \
  nlohmann-json3-dev \
  libcereal-dev \
  libboost-filesystem-dev \
  libboost-system-dev \
  libboost-program-options-dev \
  libboost-test-dev \
  libgtest-dev \
  bc
```

### Step 2: Build and Install GoogleTest

Ubuntu installs only GoogleTest sources by default, so you need to build it:

```bash
cd /usr/src/gtest
sudo cmake -S . -B build
sudo cmake --build build
sudo cmake --install build
```

### Step 3: Build and Install yaml-cpp and HDF5 from Source

The system packages for these libraries don't provide CMake config files, so we build them:

```bash
mkdir -p "$HOME/deps"
cd "$HOME/deps"

# Build yaml-cpp 0.8.0
curl -L -o yaml-cpp-0.8.0.tar.gz \
  https://github.com/jbeder/yaml-cpp/archive/refs/tags/0.8.0.tar.gz
tar xf yaml-cpp-0.8.0.tar.gz
cmake -S yaml-cpp-0.8.0 -B yaml-cpp-build \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DYAML_BUILD_SHARED_LIBS=ON \
      -DYAML_BUILD_TESTS=OFF
sudo cmake --build yaml-cpp-build --target install

# Build HDF5 1.14.3
curl -L -o hdf5-1.14.3.tar.gz \
  https://github.com/HDFGroup/hdf5/archive/refs/tags/hdf5-1_14_3.tar.gz
tar xf hdf5-1.14.3.tar.gz
cmake -S hdf5-hdf5-1_14_3 -B hdf5-build \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DBUILD_TESTING=OFF \
      -DHDF5_ENABLE_Z_LIB_SUPPORT=ON \
      -DHDF5_BUILD_CPP_LIB=ON \
      -DHDF5_BUILD_HL_LIB=ON
sudo cmake --build hdf5-build --target install
```

### Step 4: Build and Install xtensor Stack

```bash
cd "$HOME/deps"

# Build xtl 0.7.5
curl -L -o xtl-0.7.5.tar.gz \
  https://github.com/xtensor-stack/xtl/archive/refs/tags/0.7.5.tar.gz
tar xf xtl-0.7.5.tar.gz
cmake -S xtl-0.7.5 -B xtl-build \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DBUILD_TESTS=OFF
sudo cmake --build xtl-build --target install

# Build xsimd 10.0.0
curl -L -o xsimd-10.0.0.tar.gz \
  https://github.com/xtensor-stack/xsimd/archive/refs/tags/10.0.0.tar.gz
tar xf xsimd-10.0.0.tar.gz
cmake -S xsimd-10.0.0 -B xsimd-build \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DBUILD_TESTS=OFF
sudo cmake --build xsimd-build --target install

# Build xtensor 0.25.0
curl -L -o xtensor-0.25.0.tar.gz \
  https://github.com/xtensor-stack/xtensor/archive/refs/tags/0.25.0.tar.gz
tar xf xtensor-0.25.0.tar.gz
cmake -S xtensor-0.25.0 -B xtensor-build \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DBUILD_TESTS=OFF
sudo cmake --build xtensor-build --target install

# Build xtensor-io 0.13.0
curl -L -o xtensor-io-0.13.0.tar.gz \
  https://github.com/xtensor-stack/xtensor-io/archive/refs/tags/0.13.0.tar.gz
tar xf xtensor-io-0.13.0.tar.gz
cmake -S xtensor-io-0.13.0 -B xtensor-io-build \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DBUILD_TESTS=OFF
sudo cmake --build xtensor-io-build --target install
```

### Step 5: Build falcon-core C++

Navigate to your falcon-core repository directory, then:

```bash
# Replace with your actual path, e.g., cd ~/projects/falcon-core
cd /path/to/falcon-core/cpp
CC=clang CXX=clang++ USE_VCPKG=0 make build-dev
```

### Step 6: Test falcon-core C++

```bash
# In the cpp directory
make run-all-tests
mkdir -p coverage
make coverage-overview > coverage/falcon-core-cpp.txt
```

### Step 7: Build falcon-core C-API

```bash
# Navigate to c-api directory from repository root
cd ../c-api
CC=clang CXX=clang++ USE_VCPKG=0 make build-dev
```

### Step 8: Test falcon-core C-API

```bash
# In the c-api directory
make run-all-tests
mkdir -p coverage
make coverage-overview > coverage/falcon-core-c-api.txt
```

### Step 9: Verify Coverage (Optional)

Check that C++ coverage is >= 85%:

```bash
report="cpp/coverage/falcon-core-cpp.txt"
if ! grep -qE '\[  PASSED  \] [0-9]+ tests\.' "$report"; then
  echo "❌ PASSED line not found in $report"
  exit 1
fi
total_line=$(grep '^TOTAL' "$report")
if [ -z "$total_line" ]; then
  echo "❌ TOTAL line not found in $report"
  exit 1
fi
percentages=($(echo "$total_line" | grep -oE '[0-9]+\.[0-9]+%'))
for pct in "${percentages[@]}"; do
  pct_num=$(echo "$pct" | tr -d '%')
  if (( $(echo "$pct_num < 85.0" | bc -l) )); then
    echo "❌ Coverage percent $pct is less than 85%"
    exit 1
  fi
done
echo "✅ All cpp coverage checks passed."
```

Check that C-API coverage is >= 90%:

```bash
report="c-api/coverage/falcon-core-c-api.txt"
if ! grep -qE '\[  PASSED  \] [0-9]+ tests\.' "$report"; then
  echo "❌ PASSED line not found in $report"
  exit 1
fi
total_line=$(grep '^TOTAL' "$report")
if [ -z "$total_line" ]; then
  echo "❌ TOTAL line not found in $report"
  exit 1
fi
percentages=($(echo "$total_line" | grep -oE '[0-9]+\.[0-9]+%'))
for pct in "${percentages[@]}"; do
  pct_num=$(echo "$pct" | tr -d '%')
  if (( $(echo "$pct_num < 90.0" | bc -l) )); then
    echo "❌ Coverage percent $pct is less than 90%"
    exit 1
  fi
done
echo "✅ All c-api coverage checks passed."
```

---

## Arch Linux Build Instructions

### Step 1: Install System Dependencies

```bash
sudo pacman -Syu --noconfirm
sudo pacman -S --noconfirm \
  base-devel \
  git \
  openssh \
  cereal \
  hdf5 \
  boost \
  bzip2 \
  expat \
  nlohmann-json \
  openssl \
  python \
  sqlite \
  yaml-cpp \
  zlib \
  ninja \
  llvm \
  ccache \
  clang \
  gtest
```

### Step 2: Install AUR Packages

Install highfive and exprtk from AUR:

```bash
# Install highfive
git clone https://aur.archlinux.org/highfive.git
cd highfive
makepkg -si --noconfirm
cd ..

# Install exprtk
git clone https://aur.archlinux.org/exprtk.git
cd exprtk
makepkg -si --noconfirm
cd ..
```

### Step 3: Build and Install xtensor Stack PKGBUILDs

Navigate to your cloned repository:

```bash
# Example: cd ~/projects/falcon-core
cd <falcon-core-repository>/packaging

# Build and install xtl
cd xtl
makepkg -si --noconfirm --syncdeps --cleanbuild
cd ..

# Build and install xsimd
cd xsimd
makepkg -si --noconfirm --syncdeps --cleanbuild
cd ..

# Build and install xtensor
cd xtensor
makepkg -si --noconfirm --syncdeps --cleanbuild
cd ..

# Build and install xtensor-io
cd xtensor-io
makepkg -si --noconfirm --syncdeps --cleanbuild
cd ..
```

### Step 4: Build falcon-core C++

Navigate to your cloned repository:

```bash
# Example: cd ~/projects/falcon-core
cd <falcon-core-repository>/cpp
CC=/usr/bin/clang CXX=/usr/bin/clang++ USE_VCPKG=0 make build-dev
```

### Step 5: Test falcon-core C++

```bash
# In the cpp directory
make run-all-tests
mkdir -p coverage
make coverage-overview > coverage/falcon-core-cpp.txt
```

### Step 6: Build falcon-core C-API

```bash
# Navigate to c-api directory from repository root
cd ../c-api
CC=/usr/bin/clang CXX=/usr/bin/clang++ USE_VCPKG=0 make build-dev
```

### Step 7: Test falcon-core C-API

```bash
# In the c-api directory
make run-all-tests
mkdir -p coverage
make coverage-overview > coverage/falcon-core-c-api.txt
```

### Step 8: Verify Coverage

Use the same coverage verification scripts as in Ubuntu (Step 9).

---

## Fedora Build Instructions

### Step 1: Install System Dependencies

```bash
sudo dnf install -y \
  rpm-build \
  ninja-build \
  clang \
  ccache \
  python3 \
  cmake \
  boost-devel \
  hdf5-devel \
  yaml-cpp-devel \
  gcovr \
  openssl-devel \
  sqlite-devel \
  cereal-devel \
  gcc-c++ \
  make \
  bzip2 \
  tar \
  perl \
  which \
  gtest \
  gtest-devel
```

### Step 2: Prepare RPM Build Directories

```bash
mkdir -p ~/rpmbuild/SPECS ~/rpmbuild/SOURCES
```

### Step 3: Build and Install xtensor Stack via RPM

Navigate to your cloned repository:

```bash
# Example: cd ~/projects/falcon-core
cd <falcon-core-repository>/packaging/specs

# Build and install xtl
cp xtl.spec ~/rpmbuild/SPECS/
curl -L -o ~/rpmbuild/SOURCES/xtl-0.7.5.tar.gz \
  https://github.com/xtensor-stack/xtl/archive/refs/tags/0.7.5.tar.gz
rpmbuild -ba ~/rpmbuild/SPECS/xtl.spec
sudo dnf install -y ~/rpmbuild/RPMS/*/xtl-*.rpm

# Build and install xsimd
cp xsimd.spec ~/rpmbuild/SPECS/
curl -L -o ~/rpmbuild/SOURCES/xsimd-10.0.0.tar.gz \
  https://github.com/xtensor-stack/xsimd/archive/refs/tags/10.0.0.tar.gz
rpmbuild -ba ~/rpmbuild/SPECS/xsimd.spec
sudo dnf install -y ~/rpmbuild/RPMS/*/xsimd-*.rpm

# Build and install xtensor
cp xtensor.spec ~/rpmbuild/SPECS/
curl -L -o ~/rpmbuild/SOURCES/xtensor-0.25.0.tar.gz \
  https://github.com/xtensor-stack/xtensor/archive/refs/tags/0.25.0.tar.gz
rpmbuild -ba ~/rpmbuild/SPECS/xtensor.spec
sudo dnf install -y ~/rpmbuild/RPMS/*/xtensor-*.rpm

# Build and install xtensor-io
cp xtensor-io.spec ~/rpmbuild/SPECS/
curl -L -o ~/rpmbuild/SOURCES/xtensor-io-0.13.0.tar.gz \
  https://github.com/xtensor-stack/xtensor-io/archive/refs/tags/0.13.0.tar.gz
rpmbuild -ba ~/rpmbuild/SPECS/xtensor-io.spec
sudo dnf install -y ~/rpmbuild/RPMS/*/xtensor-io-*.rpm
```

### Step 4: Build and Install exprtk

```bash
# From the repository root
cp <falcon-core-repository>/packaging/specs/exprtk.spec ~/rpmbuild/SPECS/
curl -L -o ~/rpmbuild/SOURCES/exprtk-0.0.2.tar.gz \
  https://github.com/ArashPartow/exprtk/archive/refs/tags/0.0.2.tar.gz
rpmbuild -ba ~/rpmbuild/SPECS/exprtk.spec
sudo dnf install -y ~/rpmbuild/RPMS/*/exprtk-*.rpm
sudo ln -s /usr/include/exprtk/exprtk.hpp /usr/include/exprtk.hpp
```

### Step 5: Build and Install highfive

```bash
# From the repository root
cp <falcon-core-repository>/packaging/specs/highfive.spec ~/rpmbuild/SPECS/
curl -L -o ~/rpmbuild/SOURCES/highfive-3.1.1.tar.gz \
  https://github.com/highfive-devs/highfive/archive/v3.1.1.tar.gz
rpmbuild --define "_topdir $HOME/rpmbuild" -ba ~/rpmbuild/SPECS/highfive.spec
rpmfile=$(find ~/rpmbuild/RPMS -type f -name "highfive-*.rpm" | head -n1)
sudo dnf install -y "$rpmfile"
```

### Step 6: Build and Install Boost

```bash
# From the repository root
cp <falcon-core-repository>/packaging/specs/boost.spec ~/rpmbuild/SPECS/
curl -L -o ~/rpmbuild/SOURCES/boost-1.88.0.tar.gz \
  https://github.com/boostorg/boost/releases/download/boost-1.88.0/boost-1.88.0-b2-nodocs.tar.gz
rpmbuild --define "_topdir $HOME/rpmbuild" -ba ~/rpmbuild/SPECS/boost.spec
RPMS=$(find ~/rpmbuild/RPMS -type f -name "boost-*.rpm")
sudo dnf install -y $RPMS
```

### Step 7: Build falcon-core via RPM (Alternative Method)

If using the RPM spec files for falcon-core:

```bash
# Build falcon-core-cpp-dev
cp <falcon-core-repository>/packaging/specs/falcon-core-cpp-dev.spec ~/rpmbuild/SPECS/
cd <falcon-core-repository>
tar czf ~/rpmbuild/SOURCES/falcon-core-cpp-dev-1.0.0.tar.gz \
  --transform 's,^.,falcon-core-cpp-dev-1.0.0,' .
rpmbuild -ba ~/rpmbuild/SPECS/falcon-core-cpp-dev.spec
sudo dnf install -y ~/rpmbuild/RPMS/*/falcon-core-cpp-dev-*.rpm

# Build falcon-core-c-api-dev
cp <falcon-core-repository>/packaging/specs/falcon-core-c-api-dev.spec ~/rpmbuild/SPECS/
tar czf ~/rpmbuild/SOURCES/falcon-core-c-api-dev-1.0.0.tar.gz \
  --transform 's,^.,falcon-core-c-api-dev-1.0.0,' .
rpmbuild -ba ~/rpmbuild/SPECS/falcon-core-c-api-dev.spec
sudo dnf install -y ~/rpmbuild/RPMS/*/falcon-core-c-api-dev-*.rpm
```

### Step 8: Build falcon-core Directly (Alternative Method)

Instead of using RPM, you can build directly:

```bash
# Navigate to your repository
# Example: cd ~/projects/falcon-core

# Build C++
cd <falcon-core-repository>/cpp
CC=clang CXX=clang++ USE_VCPKG=0 make build-dev

# Test C++
make run-all-tests
mkdir -p coverage
make coverage-overview > coverage/falcon-core-cpp.txt

# Build C-API
cd ../c-api
CC=clang CXX=clang++ USE_VCPKG=0 make build-dev

# Test C-API
make run-all-tests
mkdir -p coverage
make coverage-overview > coverage/falcon-core-c-api.txt
```

---

## Windows Build Instructions

### Step 1: Install Dependencies

Install via Chocolatey:

```powershell
choco install ninja ccache python llvm
```

### Step 2: Install CMake

Use the actions-setup-cmake or install manually:

```powershell
# Install CMake 3.27.7 or later
# Download from https://cmake.org/download/
```

### Step 3: Install and Bootstrap vcpkg

```powershell
git clone https://github.com/microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
```

### Step 4: Install vcpkg Dependencies for C++

```powershell
cd cpp
..\vcpkg\vcpkg.exe install --triplet x64-windows
```

### Step 5: Build C++

Create a CMakePresets.json for development build:

```powershell
@"
{
  "version": 3,
  "configurePresets": [
    {
      "name": "DEV",
      "displayName": "Development build with coverage (Clang, vcpkg, Debug)",
      "generator": "Ninja",
      "binaryDir": "build",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "../vcpkg/scripts/buildsystems/vcpkg.cmake",
        "VCPKG_TARGET_TRIPLET": "x64-windows",
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_C_COMPILER": "clang",
        "CMAKE_CXX_COMPILER": "clang++",
        "USE_VCPKG": "1",
        "FALCON_CORE_DEV": "ON"
      }
    }
  ]
}
"@ | Out-File -Encoding utf8 CMakePresets.json

cmake --preset DEV
cmake --build build
```

### Step 6: Test C++

```powershell
$ErrorActionPreference = "Stop"
$buildDir = "build"
$coverageDir = "coverage"
New-Item -ItemType Directory -Force -Path $coverageDir | Out-Null

# Find the test executable
$exe = Get-ChildItem -Path $buildDir -Filter "falcon_core_cpp_run_tests*.exe" -Recurse | Select-Object -First 1

# Set profile file location
$env:LLVM_PROFILE_FILE = "$buildDir\falcon_core_cpp_run_tests.profraw"

# Run tests
& $exe.FullName

# Generate coverage
llvm-profdata merge -sparse $buildDir\falcon_core_cpp_run_tests.profraw -o $buildDir\falcon_core_cpp_run_tests.profdata
llvm-cov report $exe.FullName -instr-profile=$buildDir\falcon_core_cpp_run_tests.profdata | Out-File -Encoding utf8 $coverageDir\falcon-core-cpp.txt
```

### Step 7: Install vcpkg Dependencies for C-API

```powershell
cd ..\c-api
..\vcpkg\vcpkg.exe install --triplet x64-windows
```

### Step 8: Build C-API

```powershell
@"
{
  "version": 3,
  "configurePresets": [
    {
      "name": "DEV",
      "displayName": "Development build with coverage (Clang, vcpkg, Debug)",
      "generator": "Ninja",
      "binaryDir": "build",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "../vcpkg/scripts/buildsystems/vcpkg.cmake",
        "VCPKG_TARGET_TRIPLET": "x64-windows",
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_C_COMPILER": "clang",
        "CMAKE_CXX_COMPILER": "clang++",
        "USE_VCPKG": "1",
        "FALCON_CORE_DEV": "ON",
        "CORE_ROOT": "../cpp"
      }
    }
  ]
}
"@ | Out-File -Encoding utf8 CMakePresets.json

cmake --preset DEV
cmake --build build
```

### Step 9: Test C-API

```powershell
$buildDir = "build"
$coverageDir = "coverage"
New-Item -ItemType Directory -Force -Path $coverageDir | Out-Null

# Add build directory to PATH so the test executable can find dependencies
$env:PATH = "$PWD\$buildDir;$env:PATH"

$env:LLVM_PROFILE_FILE = "$buildDir\falcon_core_c_api_run_tests.profraw"
.\$buildDir\falcon_core_c_api_run_tests.exe
llvm-profdata merge -sparse $buildDir\falcon_core_c_api_run_tests.profraw -o $buildDir\falcon_core_c_api_run_tests.profdata
llvm-cov report .\$buildDir\falcon_core_c_api_run_tests.exe -instr-profile=$buildDir\falcon_core_c_api_run_tests.profdata | Out-File -Encoding utf8 $coverageDir\falcon-core-c-api.txt
```

---

## Using the Root Makefile

The repository includes a root-level Makefile that simplifies building both C++ and C-API components.

### Build Both Components (Release)

```bash
make build USE_VCPKG=0
```

Or with vcpkg:

```bash
make build USE_VCPKG=1
```

### Build Both Components (Dev/Tests)

```bash
make build-dev USE_VCPKG=0
```

### Run All Tests

```bash
make test
```

This will:
1. Run C++ tests and generate `cpp-coverage-report.txt`
2. Run C-API tests and generate `c-api-coverage-report.txt`

### Clean Build Artifacts

```bash
make clean        # Clean build artifacts
make clean-all    # Deep clean (removes all build directories)
```

---

## Understanding Coverage Reports

### Coverage Tools

The build system automatically detects the compiler and uses the appropriate coverage tool:

- **clang/clang++**: Uses `llvm-cov` and `llvm-profdata`
- **gcc/g++**: Uses `gcov` and `gcovr`

### Coverage Report Format

Coverage reports are generated in the `coverage/` directory:
- `cpp/coverage/falcon-core-cpp.txt` - C++ coverage report
- `c-api/coverage/falcon-core-c-api.txt` - C-API coverage report

### Coverage Thresholds

- **C++ code**: Minimum 85% coverage required
- **C-API code**: Minimum 90% coverage required

### Reading Coverage Reports

Example coverage report line:
```
TOTAL    1234    1100    89.14%    567    500    88.18%    234    210    89.74%
```

The percentages represent:
1. Line coverage
2. Function coverage
3. Branch coverage

### Advanced Coverage Commands

#### Generate HTML Coverage Report (C++)

```bash
cd cpp
make cov-html
```

#### Generate HTML Coverage Report (C-API)

```bash
cd c-api
make cov-html
```

#### Run Specific Test Filters

Edit `test_filter.txt` with test names, then:

```bash
cd cpp  # or c-api
make run-subset-tests
```

---

## Troubleshooting

### Issue: vcpkg not found

**Solution**: Install vcpkg and add it to your PATH:

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh  # Linux/Mac
# or
.\bootstrap-vcpkg.bat  # Windows
```

Add the vcpkg directory to your PATH, or set `USE_VCPKG=0` to use system packages.

### Issue: Compilation fails with missing headers

**Solution**: Ensure all dependencies are installed. Check the platform-specific instructions above.

If using `USE_VCPKG=0`, verify that all system packages are installed:
- xtl, xsimd, xtensor, xtensor-io (may need to build from source)
- boost, hdf5, yaml-cpp, cereal, etc.

### Issue: Tests fail with library not found

**Solution**: Set `LD_LIBRARY_PATH` (Linux) or `PATH` (Windows) to include the build directory:

```bash
# Linux - from repository root
export LD_LIBRARY_PATH=$(pwd)/cpp/build:$LD_LIBRARY_PATH

# Or with absolute path
export LD_LIBRARY_PATH=$HOME/projects/falcon-core/cpp/build:$LD_LIBRARY_PATH

# Windows
$env:PATH = "$PWD\cpp\build;$env:PATH"
```

### Issue: Coverage data not generated

**Solution**: Ensure you're using `build-dev` (not `build`) and that the compiler supports coverage:

```bash
make clean-all
CC=clang CXX=clang++ USE_VCPKG=0 make build-dev
```

### Issue: C-API build fails with "C++ core must be built first"

**Solution**: Build the C++ core before the C-API:

```bash
cd cpp
make build-dev
cd ../c-api
make build-dev
```

### Issue: Permission denied when installing packages

**Solution**: Use `sudo` for system-wide installations, or install to a local prefix:

```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=$HOME/.local
cmake --build build --target install
```

Then add `$HOME/.local` to your `CMAKE_PREFIX_PATH`.

### Issue: Compilation is very slow

**Solution**: Install and configure ccache:

```bash
# Linux
sudo apt-get install ccache  # Ubuntu
sudo pacman -S ccache        # Arch
sudo dnf install ccache      # Fedora

# Configure ccache
ccache --set-config=max_size=5G
ccache --set-config=compression=true

# Verify ccache is being used
ccache -s
```

### Issue: Ninja not found

**Solution**: Install ninja build system:

```bash
# Linux
sudo apt-get install ninja-build  # Ubuntu
sudo pacman -S ninja              # Arch
sudo dnf install ninja-build      # Fedora

# Windows
choco install ninja
```

---

## Additional Resources

- **CMake Documentation**: https://cmake.org/documentation/
- **Ninja Build**: https://ninja-build.org/
- **vcpkg Guide**: https://learn.microsoft.com/en-us/vcpkg/
- **clang Coverage**: https://clang.llvm.org/docs/SourceBasedCodeCoverage.html
- **GoogleTest**: https://google.github.io/googletest/

---

## Quick Reference

### Minimal Build Commands (Linux with System Packages)

```bash
# Navigate to repository (example path)
cd ~/projects/falcon-core

# Build C++
cd cpp
CC=clang CXX=clang++ USE_VCPKG=0 make build-dev

# Test C++
make run-all-tests

# Build C-API
cd ../c-api
CC=clang CXX=clang++ USE_VCPKG=0 make build-dev

# Test C-API
make run-all-tests
```

### Minimal Build Commands (Using Root Makefile)

```bash
# Navigate to repository root
cd ~/projects/falcon-core
make build-dev USE_VCPKG=0
make test
```

---

*This document is maintained to reflect the build instructions used in the GitHub Actions CI workflows. For the most up-to-date workflow configurations, refer to `.github/workflows/`.*
