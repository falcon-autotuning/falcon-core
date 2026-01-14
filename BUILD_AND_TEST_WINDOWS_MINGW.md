# Build & Test Instructions — Windows (MinGW-w64)

This document describes a **Windows cross-compilation build** using **MinGW-w64**
inside an **Arch Linux Docker image**.

The resulting binaries are **Windows `.exe` / `.dll` artifacts**, even though the
build runs on Linux.

---

## Design overview

- One Docker image: **Arch Linux + MinGW-w64**
- Cross-compilation target: `x86_64-w64-mingw32`
- Build order:
  1. `cpp/` (C++ core)
  2. `c-api/` (C wrapper)
- Compilation occurs during `docker build`

---

## Expected repository layout

```
repo-root/
├── cpp/
├── c-api/
└── docker/
    └── arch-windows-mingw.Dockerfile
```

---

## Dockerfile: `docker/arch-windows-mingw.Dockerfile`

```dockerfile
FROM archlinux:latest

RUN pacman -Syu --noconfirm && pacman -S --noconfirm \
    base-devel git \
    mingw-w64 \
    mingw-w64-cmake \
    mingw-w64-boost \
    mingw-w64-cereal \
    mingw-w64-hdf5 \
    mingw-w64-yaml-cpp \
    mingw-w64-openssl \
    mingw-w64-sqlite3 \
    mingw-w64-nlohmann-json \
    cmake ninja python \
    && pacman -Scc --noconfirm

ENV CC=x86_64-w64-mingw32-gcc
ENV CXX=x86_64-w64-mingw32-g++
ENV AR=x86_64-w64-mingw32-ar
ENV RANLIB=x86_64-w64-mingw32-ranlib
ENV STRIP=x86_64-w64-mingw32-strip

WORKDIR /repo
COPY . /repo

# ---- Build C++ core for Windows ----
WORKDIR /repo/cpp
RUN USE_VCPKG=0 make build-dev

# ---- Build C-API for Windows ----
WORKDIR /repo/c-api
RUN USE_VCPKG=0 make build-dev
```

---

## Build the Windows image

```bash
docker build -f docker/arch-windows-mingw.Dockerfile -t falcon-core:windows-mingw .
```

---

## Interactive debugging

```bash
docker run -it --rm falcon-core:windows-mingw bash
```

---

## Summary

This image validates:

- MinGW-w64 dependency resolution
- Windows cross-compilation
- C++ / C-API link compatibility
