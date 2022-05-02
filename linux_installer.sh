#!/bin/sh -eu 
# This script runs from within the build dir
libdir="/usr/local/lib"
incdir="/usr/local/include/libcee"
pkgdir="/usr/share/pkgconfig"

# Create directories
mkdir -p $libdir
mkdir -p $incdir

# Copy the main library and the headers 
cp "${MESON_BUILD_ROOT}/libcee.so" "${libdir}/."
cp -r "${MESON_SOURCE_ROOT}/include/." "${incdir}/."
cp "${MESON_SOURCE_ROOT}/libcee.pc" "${pkgdir}/."
