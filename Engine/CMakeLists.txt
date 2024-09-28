cmake_minimum_required(VERSION 3.5.0)
project(Engine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 17)

file(GLOB_RECURSE SOURCES Source/*.cpp Source/*.c)

include_directories(Include Dependencies/Include)
link_directories(Dependencies/Libraries)

add_library(Engine ${SOURCES})

include(CTest)
enable_testing()

