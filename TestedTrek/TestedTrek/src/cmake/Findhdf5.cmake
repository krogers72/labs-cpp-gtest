# Findhdf5.cmake
#
# Finds the hdf5, hdf5_cpp, hdf5_hl, and hdf5_hl_cpp libraries and include files
#
# This will define the following variables
#
#   hdf5_FOUND
#   hdf5_INCLUDE_DIRS
#   hdf5_LIBRARY_DIRS
#
# and the following imported targets
#
#   hdf5::hdf5
#   hdf5::hdf5_cpp
#   hdf5::hdf5_hl
#   hdf5::hdf5_hl_cpp
#

find_library(hdf5_LIB_SO hdf5
    PATHS "$ENV{TOOLSPATH}/lib"
    NO_DEFAULT_PATH)

find_library(hdf5_cpp_LIB_SO hdf5_cpp
    PATHS "$ENV{TOOLSPATH}/lib"
    NO_DEFAULT_PATH)

find_library(hdf5_hl_LIB_SO hdf5_hl
    PATHS "$ENV{TOOLSPATH}/lib"
    NO_DEFAULT_PATH)

find_library(hdf5_hl_cpp_LIB_SO hdf5_hl_cpp
    PATHS "$ENV{TOOLSPATH}/lib"
    NO_DEFAULT_PATH)

mark_as_advanced(hdf5_LIB_SO)

if (NOT ${hdf5_LIB_SO} STREQUAL "hdf5_LIB_SO-NOTFOUND")
    set(hdf5_FOUND TRUE)
    set(hdf5_INCLUDE_DIRS "$ENV{TOOLSPATH}/include")
    set(hdf5_LIBRARY_DIRS ${hdf5_LIB_SO})
endif()

message("hdf5 - INCLUDE: ${hdf5_INCLUDE_DIRS}  ---  LIB: ${hdf5_LIBRARY_DIRS}")

if (hdf5_FOUND AND NOT TARGET hdf5::hdf5)

    add_library(hdf5::hdf5 SHARED IMPORTED)
    set_target_properties(hdf5::hdf5 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${hdf5_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${hdf5_LIB_SO}")

    add_library(hdf5::hdf5_cpp SHARED IMPORTED)
    set_target_properties(hdf5::hdf5_cpp PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${hdf5_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${hdf5_cpp_LIB_SO}")

    add_library(hdf5::hdf5_hl SHARED IMPORTED)
    set_target_properties(hdf5::hdf5_hl PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${hdf5_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${hdf5_hl_LIB_SO}")

    add_library(hdf5::hdf5_hl_cpp SHARED IMPORTED)
    set_target_properties(hdf5::hdf5_hl_cpp PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${hdf5_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${hdf5_hl_cpp_LIB_SO}")

endif()
