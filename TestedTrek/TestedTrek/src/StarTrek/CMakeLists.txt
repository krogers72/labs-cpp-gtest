cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_SOURCE_DIR}/cmake" "${PROJECT_SOURCE_DIR}")

find_package(gtest REQUIRED MODULE)

#add_executable(gtest_test main.cpp)

set (SOURCES Galaxy.cpp Game.cpp Klingon.cpp)

add_library(StarTrek ${SOURCES})

target_link_libraries(StarTrek
    gtest
    Untouchables)

target_include_directories(StarTrek PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
