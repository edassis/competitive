#!/bin/bash

C=gcc-11 CXX=g++-11 cmake -G "Unix Makefiles" -B build -DCMAKE_BUILD_TYPE=Debug
#cmake -G "Unix Makefiles" -B build -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_BUILD_TYPE=Debug
# cmake -G "Unix Makefiles" -B build -DCMAKE_BUILD_TYPE=Debug

cmake --build build --clean-first -j 7
