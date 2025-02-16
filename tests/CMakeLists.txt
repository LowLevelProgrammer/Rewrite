# Google Test setup using FetchContent
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.tar.gz
)

# Make Google Test available
FetchContent_MakeAvailable(googletest)

include_directories(${GTEST_INCLUDE_DIRS})

# List of test source files
file(GLOB_RECURSE TEST_SOURCE_FILES "*.cpp")

add_executable(RewriteTest ${TEST_SOURCE_FILES})

# Add source files from the main project that are needed by the tests
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Remove main.cpp from the source list to avoid multiple definition of 'main'
list(REMOVE_ITEM SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp)

target_sources(RewriteTest PRIVATE ${SOURCE_FILES})

# Link against Google Test Library
target_link_libraries(RewriteTest gtest gtest_main)

# Register the test with CTest
add_test(NAME RewriteTest COMMAND RewriteTest)
