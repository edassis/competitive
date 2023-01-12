#!/bin/bash

OS=$(uname)
if [ "$OS" = "Darwin" ]; then
  export CC=gcc-12
  export CXX=g++-12
else
  export CC=gcc
  export CXX=g++ 
fi

cmake -G "Unix Makefiles" -B build -DCMAKE_BUILD_TYPE=Debug
#cmake -G "Unix Makefiles" -B build -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_BUILD_TYPE=Debug
# cmake -G "Unix Makefiles" -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --clean-first -j 7

unset CC
unset CXX
