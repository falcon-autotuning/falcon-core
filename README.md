# falcon-core

Core utilities for all falcon applications used for autotuning of quantum devices.

This repository contains the main datatypes that can be used for serialization within falcon. All of the source code is written in  C++14. It can be found at /build and /src respectively. It is compiled via commands from the /Makefile.

The different supported languages are found in /go and /python with the folder indicating the language. Currently supported languages are Python and Go.

The C-api that binds all of the languages together is located in /c-api

## Installing

To install this package you will first need to install the core cpp implementation.

These are the dependencies that this is known to work with.

* boost@1.88.0
* bzip2@1.0.8#6
* cereal@1.3.2#1
* expat@2.7.1
* exprtk@0.0.2
* hdf5@1.14.6
* highfive@3.1.1
* nlohmann-json@3.12.0
* openssl@3.5.2
* openssl@3.5.2
* pybind11@3.0.1
* python3@3.12.9
* sqlite3@3.50.4
* xsimd@13.2.0
* xtensor@0.25.0
* xtensor-io@0.13.0
* xtl@0.7.5
* yaml-cpp@0.8.0
* zlib@1.3.1

And for the dev version this one is also needed

* gtest:x64-linux-dynamic@1.16.0

Many of these packages are available on the AUR or Pacman for Arch Linux.
Some of these packages are quite old, so we have packaged them for ease of installation.
These packages can be found in the /packaging folder.

* xsimd@13.2.0
* xtensor@0.25.0
* xtensor-io@0.13.0
* xtl@0.7.5

They can be installed via the following commands.

```console
cd /packaging/xtl
makepkg -si
cd ..
cd /xsimd
makepkg -si
cd ..
cd /xtensor
makepkg -si
cd ..
cd /xtensor-io
makepkg -si
cd ..
```

Finally the package can be installed via the following commands

```console
cd /falcon-core
makepkg -si
cd ..
```

Navigate to the README in the dist folder you are interested in using. More details can be found there on how to install falcon-core.

## Getting started for devs

We use [clang](https://clang.llvm.org/) /(llvm/) as our main compiler, but [gcc](https://gcc.gnu.org/) should also work. The code is tested on Linux. You need one of the above c compilers installed on your system.

We use vcpkg to manager all of our C++ dependencies. This needs to be installed following distro specific [instruction](https://learn.microsoft.com/en-us/vcpkg/get_started/overview)
With vcpkg we use [ninja](https://ninja-build.org/) as our build system. This also needs to be installed on your system.
Finally we recommend using [ccache](https://ccache.dev/) to speed up compilation times.

With those 3 precursors setup, to build run in the cpp directory

```console
make clean-all; make all 
```

To build subsequent times you can use

```console
make build
```

If things get weird you may want to throw a ```make clean``` every so often.
Conversely to target building specific folders in C you can specify

```console
make build-part DIRS="file/path;targetted/file.cpp" TESTS="all/tests/here;this/specific/one.cpp"
```

Also if facing segmentation faults the following command can sometimes help diagnose the issue

```console
make build-and-sanitize
```

We also have many different ways to view coverage of your code in the Makefile. The most important is

```console
make coverage-overview
```
