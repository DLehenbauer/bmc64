# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.202.3/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version (use bullseye or stretch on local arm64/Apple Silicon): bullseye, buster, stretch
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# Download x86_64 cross compilers for AArch32 bare-metal target (arm-none-eabi)
# This is a large/slow download, so do this first to maximize Docker caching.
ARG ARM_TOOL_NAME=gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2
RUN cd /tmp && wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2019q4/${ARM_TOOL_NAME}

# Install dependencies
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        autoconf \
        autoconf-archive \
        autotools-dev \
        build-essential \
        byacc \
        clang-format \
        git \
        flex \
        libpng-dev \
        libtool \
        pkg-config \
        xa65 \
        xz-utils

# Vice 3.3 requires automake-1.15.1.
RUN cd /tmp && wget https://ftp.gnu.org/gnu/automake/automake-1.15.1.tar.gz \
    && tar -xzvf automake-1.15.1.tar.gz \
    && cd automake-1.15.1 \
    && ./configure --prefix=/opt/aclocal-1.15 \
    && make \
    && make install

# Install x86_64 cross compilers for AArch32 bare-metal target (arm-none-eabi)
RUN cd /tmp && tar -xf $ARM_TOOL_NAME -C /opt
