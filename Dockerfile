FROM alpine:latest

# Install build tools and Python
RUN apk add --no-cache clang clang-dev cmake ninja-build ninja-is-really-ninja ccache make python3 python3-dev py3-numpy py3-pip git g++ libc-dev openssl-dev zlib-dev
# Install Boost (filesystem and system), yaml-cpp, SWIG, and GTest
RUN apk add --no-cache boost-dev boost-filesystem boost-system yaml-cpp-dev swig gtest-dev
# Set up ccache for clang
ENV CC=clang
ENV CXX=clang++
ENV CMAKE_C_COMPILER_LAUNCHER=ccache
ENV CMAKE_CXX_COMPILER_LAUNCHER=ccache
# Install xtensor, xtl, xsimd (from source, as Alpine's packages may be outdated or missing)
WORKDIR /tmp
# xtl
RUN git clone --branch 0.8.0 --depth 1 https://github.com/xtensor-stack/xtl.git && cd xtl && mkdir build && cd build && cmake -DCMAKE_INSTALL_PREFIX=/usr .. && make -j && make install
# xsimd
RUN git clone --branch 13.2.0 --depth 1 https://github.com/xtensor-stack/xsimd.git && \
  cd xsimd && mkdir build && cd build && \
  cmake .. -DCMAKE_INSTALL_PREFIX=/usr && make -j && make install
# xtensor
RUN git clone --branch 0.27.0 --depth 1 https://github.com/xtensor-stack/xtensor.git && cd xtensor && mkdir build && cd build && cmake .. -DCMAKE_INSTALL_PREFIX=/usr && make -j && make install
# cereal (header-only, just clone)
RUN git clone --branch v1.3.2 --depth 1 https://github.com/USCiLab/cereal.git /usr/include/cereal

# Clean up
RUN rm -rf /tmp/*
# Default workdir
# RUN echo id
# ARG UID
# ARG GID
# RUN addgroup -g $GID devgroup && adduser -D -u $UID -G devgroup devuser
# USER devuser

WORKDIR /workspace
COPY . ./
# RUN echo id
# COPY Makefile /workspace/
# COPY ./ /home/workspace/



# Entrypoint for interactive use
CMD ["/bin/sh"]
