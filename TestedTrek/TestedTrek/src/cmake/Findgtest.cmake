# Findgtest.cmake
#
# Finds the gtest and gmock libraries and include files
#
# This will define the following variables
#
#   gtest_FOUND
#   gtest_INCLUDE_DIRS
#   gtest_LIBRARY_DIRS
#   gmock_FOUND
#   gmock_INCLUDE_DIRS
#   gmock_LIBRARY_DIRS
#
# and the following imported targets
#
#   gtest
#   gmock
#

find_library(gtest_LIB_SO gtest
    PATHS "$ENV{TOOLSPATH}/lib"
    PATH_SUFFIXES "gtest"
    NO_DEFAULT_PATH)

mark_as_advanced(gtest_LIB_SO)

if (NOT ${gtest_LIB_SO} STREQUAL "gtest_LIB_SO-NOTFOUND")
    set(gtest_FOUND TRUE)
    set(gtest_INCLUDE_DIRS "$ENV{TOOLSPATH}/include")
    set(gtest_LIBRARY_DIRS ${gtest_LIB_SO})
endif()

find_library(gmock_LIB_SO gmock_main
    PATHS "$ENV{TOOLSPATH}/lib"
    PATH_SUFFIXES "gtest"
    NO_DEFAULT_PATH)

mark_as_advanced(gmock_LIB_SO)

if (NOT ${gmock_LIB_SO} STREQUAL "gmock_LIB_SO-NOTFOUND")
    set(gmock_FOUND TRUE)
    set(gmock_INCLUDE_DIRS "$ENV{TOOLSPATH}/include")
    set(gmock_LIBRARY_DIRS ${gmock_LIB_SO})
endif()

message("gtest - INCLUDE: ${gtest_INCLUDE_DIRS}  ---  LIB: ${gtest_LIBRARY_DIRS}")
message("gmock - INCLUDE: ${gmock_INCLUDE_DIRS}  ---  LIB: ${gmock_LIBRARY_DIRS}")

if (gtest_FOUND AND NOT TARGET gtest)
    add_library(gtest SHARED IMPORTED)
    set_target_properties(gtest PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${gtest_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${gtest_LIB_SO}")
endif()

if (gmock_FOUND AND NOT TARGET gmock)
    add_library(gmock SHARED IMPORTED)
    set_target_properties(gmock PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${gmock_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${gmock_LIB_SO}")
endif()
