cmake_minimum_required(VERSION 3.10)
project(Rewrite)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/main.cpp")

add_executable(Rewrite ${SOURCES})
