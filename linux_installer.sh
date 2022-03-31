#!/bin/sh -eu 
# This script runs from within the build dir
libdir="/usr/local/lib"
incdir="/usr/local/include/libsee"
pkgdir="/usr/share/pkgconfig"

# Create directories
mkdir -p $libdir
mkdir -p $incdir

# Copy the main library and the headers 
cp "libsee.so" "${libdir}/."
cp -r "../include/." "${incdir}/."
cp "../libsee.pc" "${pkgdir}/."
