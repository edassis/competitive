#!/usr/bin/env bash

export CC CXX

CC=gcc
CXX=g++ 

OS=$(uname)
if [ "$OS" = "Darwin" ]; then
	CC=$(compgen -c | grep gcc -m1)
	CXX=$(compgen -c | grep g++ -m1)
fi

cmake -G "Unix Makefiles" -B build -DCMAKE_BUILD_TYPE=Debug
#cmake -G "Unix Makefiles" -B build -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_BUILD_TYPE=Debug
# cmake -G "Unix Makefiles" -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --clean-first -j 7

unset CC CXX
