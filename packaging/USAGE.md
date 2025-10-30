Suggested commands (run from repo root):

```bash
make -C packaging rpmbuild-setup
```

```bash
make -C packaging fedora-build-xtl
```

```bash
make -C packaging fedora-build-falcon-core-cpp
```

Notes:
- For Arch builds, ensure each PKGBUILD is available in packaging/<pkg>/PKGBUILD or packaging/PKGBUILD and run `make -C packaging arch-build-<pkg>`.
- For Fedora builds the Makefile will download upstream tarballs for header-only dependencies and will create a falcon-core source tarball from the current git branch (default branch: cpp-refactor) if one is not present.
- Ensure you have rpm-build, cmake and a C++ toolchain installed:
  - sudo dnf install rpm-build redhat-rpm-config cmake gcc-c++ make
- After rpmbuild finishes, install the produced RPM using:
  - sudo dnf install /home/<you>/rpmbuild/RPMS/x86_64/<package>-<version>-<release>.x86_64.rpm
