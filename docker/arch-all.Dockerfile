FROM archlinux:latest

# Keep pacman fast + noninteractive
RUN sed -i 's/^#ParallelDownloads/ParallelDownloads/' /etc/pacman.conf

# Base deps from the GitHub workflow + a couple utilities it implicitly uses
# Also includes MinGW for Windows cross-compilation and Wine for testing
RUN pacman -Syu --noconfirm && \
    pacman -S --noconfirm \
      base-devel git openssh sudo \
      cereal hdf5 boost bzip2 expat nlohmann-json openssl python sqlite yaml-cpp zlib \
      ninja llvm ccache clang gtest lld \
      cmake make \
      mingw-w64-gcc \
      wine wine-mono wine-gecko \
      zip unzip tar \
      bc && \
    pacman -Scc --noconfirm


# Create the same build user as CI
RUN useradd -m builduser && \
    echo "builduser ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

WORKDIR /workspace
CMD ["/bin/bash"]
