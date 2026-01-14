# Build & Test Instructions — Arch Linux (Native)

This document describes a **Docker-based, fully isolated build** for **Arch Linux**.
Both the **C++ core (`cpp/`)** and the **C-API (`c-api/`)** are built inside a single
Arch Linux Docker image.

---

## Design overview

- One Docker image: **Arch Linux**
- Build order inside the image:
  1. `cpp/` (C++ core)
  2. `c-api/` (C wrapper, depends on `cpp/`)
- Compilation and tests occur during `docker build`
- Containers are only created for artifact extraction or debugging

---

## Expected repository layout

```
repo-root/
├── cpp/
├── c-api/
└── docker/
    └── arch-linux-all.Dockerfile
```

---

## Dockerfile: `docker/arch-linux-all.Dockerfile`

```dockerfile
FROM archlinux:latest

RUN pacman -Syu --noconfirm && pacman -S --noconfirm \
    base-devel git \
    clang llvm lld ccache cmake ninja \
    boost cereal hdf5 yaml-cpp \
    nlohmann-json openssl sqlite \
    gtest python \
    && pacman -Scc --noconfirm

WORKDIR /repo
COPY . /repo

# ---- Build & test C++ core ----
WORKDIR /repo/cpp
RUN CC=clang CXX=clang++ USE_VCPKG=0 make build-dev \
 && make run-all-tests \
 && mkdir -p coverage \
 && make coverage-overview > coverage/falcon-core-cpp.txt

# ---- Build & test C-API ----
WORKDIR /repo/c-api
RUN CC=clang CXX=clang++ USE_VCPKG=0 make build-dev \
 && make run-all-tests \
 && mkdir -p coverage \
 && make coverage-overview > coverage/falcon-core-c-api.txt
```

---

## Build the Arch Linux image

```bash
docker build -f docker/arch-linux-all.Dockerfile -t falcon-core:arch-linux .
```

---

## Artifact extraction

```bash
id=$(docker create falcon-core:arch-linux)

docker cp "$id:/repo/cpp/coverage/falcon-core-cpp.txt" .
docker cp "$id:/repo/c-api/coverage/falcon-core-c-api.txt" .

docker rm "$id"
```

---

## Interactive debugging

```bash
docker run -it --rm falcon-core:arch-linux bash
```

---

## Summary

This image validates:

- Arch Linux packaging
- Native Clang builds
- C++ → C-API dependency correctness
