include(CMakePrintHelpers)

cmake_minimum_required(VERSION 3.16.3)
project(competitive VERSION 0.1.0)

# message(STATUS "CC from ENV: $ENV{CC}")
# message(STATUS "CXX from ENV: $ENV{CXX}")

set(MY_FLAGS "")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MY_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_FLAGS}")
# include_directories and target_include_directories didn't work
# Mac always overrides the specified path. Setting this seems to solve:
# set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES "/opt/homebrew/include/c++/12/aarch64-apple-darwin21")
# set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR})
#SET(CMAKE_OSX_SYSROOT "$ENV{HOME}/.platformio/packages/toolchain-xtensa32/xtensa-esp32-elf/sysroot")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
# message(${OUTPUT_NAME})
#INCLUDE(ctEST)
#ENABLE_TESTING()

# include_directories(BEFORE SYSTEM "/opt/homebrew/include/c++/11")
include_directories(BEFORE SYSTEM "include")

add_executable(a src/main.cpp)
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

#include_directories(SYSTEM "C:/dev/TDM-GCC-32/lib/gcc/mingw32/10.3.0/include/c++/mingw32")
# target_include_directories(a SYSTEM PRIVATE ${CMAKE_SOURCE_DIR})
# target_include_directories(a SYSTEM PRIVATE "/opt/homebrew/include/c++/11")
# target_precompile_headers(a PRIVATE <bits/stdc++.h>)
#target_link_directories(${PROJECT_NAME} PRIVATE "C:/dev/TDM-GCC-32/lib/gcc/mingw32/10.3.0/include/c++")

#get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#foreach(dir ${dirs})
#message(STATUS "dir='${dir}'")
#endforeach()

#cmake_print_variables(CMAKE_CXX_FLAGS)
#cmake_print_properties(TARGETS a PROPERTIES CMAKE_CXX_FLAGS)
