# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.202.3/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version (use bullseye or stretch on local arm64/Apple Silicon): bullseye, buster, stretch
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# [Choice] ARM compiler version (See https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
ARG ARM_TOOL_VERSION=10.3-2021.07

# Download x86_64 cross compilers for AArch32 bare-metal target (arm-none-eabi)
# This is a large/slow download, so do this first to maximize Docker caching.
ARG ARM_TOOL_NAME=gcc-arm-${ARM_TOOL_VERSION}-x86_64-arm-none-eabi
RUN cd /tmp && wget https://developer.arm.com/-/media/Files/downloads/gnu-a/$ARM_TOOL_VERSION/binrel/$ARM_TOOL_NAME.tar.xz

# Install dependencies
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        autoconf \
        autoconf-archive \
        automake \
        autotools-dev \
        build-essential \
        clang-format \
        git \
        libtool \
        pkg-config \
        xa65 \
        xz-utils

# Install x86_64 cross compilers for AArch32 bare-metal target (arm-none-eabi)
RUN cd /tmp && tar -xf $ARM_TOOL_NAME.tar.xz -C /opt
# RUN ln -s "/opt/$ARM_TOOL_NAME/bin"/* "/usr/local/bin/"
