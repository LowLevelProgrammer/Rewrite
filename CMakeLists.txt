cmake_minimum_required(VERSION 3.10)
project(Rewrite)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/Core src/EditorCore)
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Rewrite ${SOURCES})

enable_testing()

# Add subdirectory for tests
add_subdirectory(tests)
