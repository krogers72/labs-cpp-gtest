cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_SOURCE_DIR}/cmake" "${PROJECT_SOURCE_DIR}")

find_package(gtest REQUIRED MODULE)

#add_executable(gtest_test main.cpp)

set (SOURCES MockGalaxy.cpp MockKlingon.cpp PhaserCharacterizationTests.cpp PhotonCharacterizationTests.cpp)

add_executable(AllTests ${SOURCES})

target_link_libraries(AllTests
    gtest
    StarTrek
    Untouchables)
