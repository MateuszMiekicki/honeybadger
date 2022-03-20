#!/bin/sh
set -eux
apt remove --purge --auto-remove cmake

VERSION=3.22
BUILD=1

mkdir -p /opt
wget https://github.com/Kitware/CMake/releases/download/v${VERSION}.${BUILD}/cmake-${VERSION}.${BUILD}-linux-x86_64.tar.gz -O /opt/cmake.tar.gz
tar -xzvf /opt/cmake.tar.gz -C opt/
rm /opt/cmake.tar.gz

ln -s /opt/cmake-${VERSION}.${BUILD}-linux-x86_64/bin/* /usr/bin/