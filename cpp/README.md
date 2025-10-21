# falcon-core-cpp

Core utilities for all falcon applications used for autotuning of quantum devices.

This repository contains the main datatypes that can be used for serialization within falcon. All of the source code is written in  C++14. It can be found at /build and /src respectively.

## Getting started for devs

We use [clang](https://clang.llvm.org/) /(llvm/) as our main compiler, but [gcc](https://gcc.gnu.org/) should also work. The code is tested on Linux. You need one of the above c compilers installed on your system.
We also heavily use [SWIG](https://www.swig.org/) to provide for our bindings in other programming languages.

We use vcpkg to manager all of our C++ dependencies. This needs to be installed following distro specific [instruction](https://learn.microsoft.com/en-us/vcpkg/get_started/overview)
With vcpkg we use [ninja](https://ninja-build.org/) as our build system. This also needs to be installed on your system.
Finally we recommend using [ccache](https://ccache.dev/) to speed up compilation times.

With those 3 precursors setup, to build run in the main directory

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
