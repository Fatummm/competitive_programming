FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

ARG USERNAME=sirnik

RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    python3 \
    python3-pip \
    git \
    time \
    && rm -rf /var/lib/apt/lists/*


RUN usermod -l ${USERNAME} vscode
RUN groupmod -n ${USERNAME} vscode
RUN usermod -d /home/${USERNAME} -m ${USERNAME}

USER ${USERNAME}
