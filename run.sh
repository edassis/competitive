#!/bin/bash
cmake -G "Unix Makefiles" -B build -DCMAKE_C_COMPILER=/opt/homebrew/bin/gcc-11 -DCMAKE_CXX_COMPILER=/opt/homebrew/bin/g++-11 -DCMAKE_BUILD_TYPE=Debug

#cmake -G "Unix Makefiles" -B build -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_BUILD_TYPE=Debug

# cmake -G "Unix Makefiles" -B build -DCMAKE_BUILD_TYPE=Debug

cmake --build build --clean-first