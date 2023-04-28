# libcee - Useful C and C++ utils.

A collection of useful C and C++ functions I've written over the while.

## Building and Installing

To build and install you will need meson and ninja installed.

Under linux, the following should work:

    meson setup release
    ninja -C release
    sudo meson install --no-rebuild -C release

Under windows, place the resulting dll in the same location as the executable or statically compile the .lib file and bundle directly with the exe.