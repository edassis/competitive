#!/bin/bash

OS=$(uname)
if [ "$OS" = "Darwin" ]; then
  export C=gcc-12
  export CXX=g++-12 
else
  export C=gcc
  export CXX=g++ 
fi

cmake -G "Unix Makefiles" -B build -DCMAKE_BUILD_TYPE=Debug
#cmake -G "Unix Makefiles" -B build -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_BUILD_TYPE=Debug
# cmake -G "Unix Makefiles" -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --clean-first -j 7

unset C
unset CXX
