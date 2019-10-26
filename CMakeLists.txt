cmake_minimum_required (VERSION 3.10.2)

project(FILTERTEST)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

################################
# GTest
################################
ADD_SUBDIRECTORY (googletest-release-1.10.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################

# Add test cpp file
add_executable( runUnitTests filter.cpp parser.cpp messages.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main)
add_test( runUnitTests runUnitTests )

