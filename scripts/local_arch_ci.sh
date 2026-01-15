#!/usr/bin/env bash
set -euo pipefail

# Run from repo root.
if [[ ! -d cpp || ! -d c-api || ! -d packaging ]]; then
  echo "Run this from the repo root (where cpp/, c-api/, packaging/ exist)."
  exit 1
fi

# Optional: persist caches on the host to speed up repeat runs
mkdir -p .cache/pacman .cache/ccache

docker run --rm -t \
  -v "$PWD":/workspace \
  -v "$PWD/.cache/pacman":/var/cache/pacman/pkg \
  -v "$PWD/.cache/ccache":/home/builduser/.ccache \
  -w /workspace \
  falcon-arch-ci \
  bash -lc '
    set -euo pipefail

    # Match CI: chown repo to builduser
    chown -R builduser:builduser /workspace

    # Match CI: set clang defaults for makepkg (affects AUR/PKGBUILD builds)
    grep -q "^CC=" /etc/makepkg.conf && \
      sed -i "s|^CC=.*|CC=/usr/bin/clang|" /etc/makepkg.conf || \
      echo "CC=/usr/bin/clang" >> /etc/makepkg.conf
    grep -q "^CXX=" /etc/makepkg.conf && \
      sed -i "s|^CXX=.*|CXX=/usr/bin/clang++|" /etc/makepkg.conf || \
      echo "CXX=/usr/bin/clang++" >> /etc/makepkg.conf

    # AUR: highfive + exprtk (same structure as CI)
    mkdir -p packaging
    chown builduser:builduser packaging

    runuser -u builduser -- env PATH=/usr/bin:$PATH bash -lc "
      set -euo pipefail
      mkdir -p packaging

      if [ ! -d packaging/highfive ]; then
        git clone https://aur.archlinux.org/highfive.git packaging/highfive
      fi
      if [ ! -d packaging/exprtk ]; then
        git clone https://aur.archlinux.org/exprtk.git packaging/exprtk
      fi

      cd packaging/highfive
      if ls *.pkg.tar.zst 1> /dev/null 2>&1; then
        sudo pacman -U --noconfirm ./*.pkg.tar.zst
      else
        # HighFive AUR sometimes fails check() on latest Arch/HDF5; skip tests locally
        PKGDEST="$(pwd)" makepkg -si --noconfirm --needed --nocheck
      fi
      
      cd ../exprtk
      PKGDEST=\$(pwd) makepkg -si --noconfirm --needed
    "

    # Build/test the in-repo PKGBUILDs: xtl, xsimd, xtensor, xtensor-io
    runuser -u builduser -- env PATH=/usr/bin:$PATH bash -lc "
      set -euo pipefail
      cd packaging/xtl && makepkg -si --noconfirm --syncdeps --cleanbuild
      cd ../xsimd && makepkg -si --noconfirm --syncdeps --cleanbuild
      cd ../xtensor && makepkg -si --noconfirm --syncdeps --cleanbuild
      cd ../xtensor-io && makepkg -si --noconfirm --syncdeps --cleanbuild
    "

    # Build + test cpp (dev)
    cd cpp
    CC=/usr/bin/clang CXX=/usr/bin/clang++ USE_VCPKG=0 make build-dev
    make run-all-tests
    mkdir -p coverage
    make coverage-overview > coverage/falcon-core-cpp.txt

    # Build + test c-api (dev)
    cd /workspace/c-api
    CC=/usr/bin/clang CXX=/usr/bin/clang++ USE_VCPKG=0 make build-dev
    make run-all-tests
    mkdir -p coverage
    make coverage-overview > coverage/falcon-core-c-api.txt

    echo
    echo "=== DONE ==="
    echo "CPP coverage report:   cpp/coverage/falcon-core-cpp.txt"
    echo "C-API coverage report: c-api/coverage/falcon-core-c-api.txt"
  '
