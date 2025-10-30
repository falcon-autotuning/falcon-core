# Packaging Makefile: build/install Arch PKGBUILDs with makepkg, and build/install Fedora RPMs with rpmbuild/dnf.
# Usage (from repo root):
#  make -C packaging arch-all            # Build & install Arch packages using existing PKGBUILD dirs
#  make -C packaging arch-build-falcon-core-cpp
#  make -C packaging rpmbuild-setup
#  make -C packaging fedora-build-falcon-core-cpp
#  make -C packaging fedora-install-falcon-core-cpp
#
# The Makefile keeps the PKGBUILD files as-is and adds .spec based RPM workflows.
# For falcon-core packages, this Makefile will create a tarball from the current git
# checkout (using `git archive`) automatically if no tarball is provided, to match
# the Arch/git-based behavior.

SHELL := /bin/bash

# Directory containing this Makefile (packaging/)
THIS_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
PACKAGES := falcon-core-cpp falcon-core-cpp-dev xtl xtensor xsimd xtensor-io

SOURCES_DIR := $(THIS_DIR)/sources
SPECS_DIR := $(THIS_DIR)/specs

# rpmbuild top dir (override by setting RPMBUILD env)
RPMBUILD ?= $(HOME)/rpmbuild
RPMBUILD_SOURCES := $(RPMBUILD)/SOURCES
RPMBUILD_SPECS   := $(RPMBUILD)/SPECS

# Upstream URLs (extracted from existing PKGBUILDs)
UPSTREAM_URL_xtl        := https://github.com/xtensor-stack/xtl/archive/refs/tags/0.7.5.tar.gz
UPSTREAM_URL_xtensor    := https://github.com/xtensor-stack/xtensor/archive/refs/tags/0.25.0.tar.gz
UPSTREAM_URL_xsimd      := https://github.com/xtensor-stack/xsimd/archive/refs/tags/10.0.0.tar.gz
UPSTREAM_URL_xtensor_io := https://github.com/xtensor-stack/xtensor-io/archive/refs/tags/0.13.0.tar.gz

.PHONY: all arch-all rpmbuild-setup fedora-all clean create-falcon-source \
        arch-build-% fedora-build-% fedora-install-%

all: arch-all fedora-all

####################
# Arch (makepkg) tasks
####################
arch-all: $(patsubst %,arch-build-%, $(PACKAGES))

# Expect each PKGBUILD to live in packaging/<pkgname>/PKGBUILD OR packaging/PKGBUILD files already present at packaging/
arch-build-%:
	@echo "=> Building Arch package '$*' using makepkg (expects packaging/<pkg>/PKGBUILD or packaging/PKGBUILD files)"
	if [ -d "$(THIS_DIR)/$*" ] && [ -f "$(THIS_DIR)/$*/PKGBUILD" ]; then \
	  (cd "$(THIS_DIR)/$*" && makepkg -sri --noconfirm); \
	elif [ -f "$(THIS_DIR)/PKGBUILD" ]; then \
	  echo "Top-level PKGBUILD present (packaging/PKGBUILD). Trying makepkg in packaging dir"; \
	  (cd "$(THIS_DIR)" && makepkg -sri --noconfirm); \
	else \
	  echo "PKGBUILD for '$*' not found under $(THIS_DIR). Place it at $(THIS_DIR)/$*/PKGBUILD or $(THIS_DIR)/PKGBUILD"; exit 1; \
	fi

####################
# Fedora (rpmbuild) tasks
####################
fedora-all: rpmbuild-setup $(SOURCES_DIR)/xtl-0.7.5.tar.gz $(SOURCES_DIR)/xtensor-0.25.0.tar.gz $(SOURCES_DIR)/xsimd-10.0.0.tar.gz $(SOURCES_DIR)/xtensor-0.13.0.tar.gz $(patsubst %,fedora-build-%, $(PACKAGES))

rpmbuild-setup:
	@echo "=> Creating rpmbuild tree at $(RPMBUILD)"
	mkdir -p $(RPMBUILD)/{BUILD,RPMS,SOURCES,SPECS,SRPMS,BUILDROOT}

# Sources (download upstream releases)
$(SOURCES_DIR):
	mkdir -p $(SOURCES_DIR)

$(SOURCES_DIR)/xtl-0.7.5.tar.gz: | $(SOURCES_DIR)
	curl -L -o $@ $(UPSTREAM_URL_xtl)

$(SOURCES_DIR)/xtensor-0.25.0.tar.gz: | $(SOURCES_DIR)
	curl -L -o $@ $(UPSTREAM_URL_xtensor)

$(SOURCES_DIR)/xsimd-10.0.0.tar.gz: | $(SOURCES_DIR)
	curl -L -o $@ $(UPSTREAM_URL_xsimd)

$(SOURCES_DIR)/xtensor-0.13.0.tar.gz: | $(SOURCES_DIR)
	curl -L -o $@ $(UPSTREAM_URL_xtensor_io)

# Create a falcon-core tarball via 'git archive' of the specified branch if needed.
create-falcon-source:
	@# Usage: make -C packaging create-falcon-source TAR=/path/to/out.tar.gz BRANCH=cpp-refactor
	@if [ -z "$(TAR)" ]; then echo "Set TAR=/path/to/out.tar.gz"; exit 1; fi
	@git archive --format=tar.gz --prefix=falcon-core-1.0.0/ ${BRANCH:-cpp-refactor} -o $(TAR)
	@echo "Created $(TAR)"

# Build an RPM given an existing spec in specs/<pkg>.spec
fedora-build-%: rpmbuild-setup
	@pkg=$*; \
	spec="$(SPECS_DIR)/$$pkg.spec"; \
	if [ ! -f "$$spec" ]; then echo "Spec file $$spec not found"; exit 1; fi; \
	echo "=> Building $$pkg from spec $$spec"; \
	cp -v "$$spec" "$(RPMBUILD_SPECS)/"; \
	case "$$pkg" in \
	  xtl) cp -v "$(SOURCES_DIR)/xtl-0.7.5.tar.gz" "$(RPMBUILD_SOURCES)/";; \
	  xtensor) cp -v "$(SOURCES_DIR)/xtensor-0.25.0.tar.gz" "$(RPMBUILD_SOURCES)/";; \
	  xsimd) cp -v "$(SOURCES_DIR)/xsimd-10.0.0.tar.gz" "$(RPMBUILD_SOURCES)/";; \
	  xtensor-io) cp -v "$(SOURCES_DIR)/xtensor-0.13.0.tar.gz" "$(RPMBUILD_SOURCES)/";; \
	  falcon-core-cpp|falcon-core-cpp-dev) \
	    if [ ! -f "$(SOURCES_DIR)/falcon-core-1.0.0.tar.gz" ]; then \
	      echo "Falcon source tarball not found. Creating one via 'git archive' from current repo branch..."; \
	      mkdir -p "$(SOURCES_DIR)"; \
	      git archive --format=tar.gz --prefix=falcon-core-1.0.0/ ${BRANCH:-cpp-refactor} -o "$(SOURCES_DIR)/falcon-core-1.0.0.tar.gz" || { echo "git archive failed. You can create a tarball manually with create-falcon-source."; exit 1; }; \
	    fi; \
	    cp -v "$(SOURCES_DIR)/falcon-core-1.0.0.tar.gz" "$(RPMBUILD_SOURCES)/";; \
	  *) echo "No source mapping for $$pkg - ensure its sources are in $(RPMBUILD_SOURCES)";; \
	esac; \
	rpmbuild -ba "$(RPMBUILD_SPECS)/$$pkg.spec"

# Install the first RPM found for a given package name
fedora-install-%:
	@pkg=$*; \
	rpmfile=$$(find "$(RPMBUILD)/RPMS" -type f -name "$$pkg-*.rpm" | head -n1); \
	if [ -z "$$rpmfile" ]; then echo "No RPM found for $$pkg in $(RPMBUILD)/RPMS"; exit 1; fi; \
	echo "=> Installing $$rpmfile via dnf"; \
	sudo dnf install -y "$$rpmfile"

clean:
	rm -rf $(SOURCES_DIR)
