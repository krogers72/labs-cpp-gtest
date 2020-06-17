cmake_minimum_required(VERSION 3.5)

project(Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_SOURCE_DIR}/cmake" "${PROJECT_SOURCE_DIR}")

find_package(gtest REQUIRED MODULE)

#add_executable(gtest_test main.cpp)

add_subdirectory(StarTrek)
add_subdirectory(Tests)
add_subdirectory(Untouchables)
