#!/bin/sh -eu 
# This script runs from within the build dir
libdir="/usr/local/lib"
incdir="/usr/local/include/libcee"
pkgdir="/usr/share/pkgconfig"

# Create directories
mkdir -p $libdir
mkdir -p $incdir

# Copy the main library and the headers 
cp "libcee.so" "${libdir}/."
cp -r "../include/." "${incdir}/."
cp "../libcee.pc" "${pkgdir}/."
