# FindQwt.cmake
#
# Finds the cspice library and include files
#
# This will define the following variables
#
#   cspice_FOUND
#   cspice_INCLUDE_DIRS
#   cspice_LIBRARY_DIRS
#
# and the following imported targets
#
#   cspice::cspice
#

find_library(CSPICE_LIB_AR cspice.a
    PATHS "$ENV{TOOLSPATH}/lib"
    NO_DEFAULT_PATH)

mark_as_advanced(CSPICE_LIB_AR)

if (NOT ${CSPICE_LIB_AR} STREQUAL "CSPICE_LIB_AR-NOTFOUND")
    set(CSPICE_FOUND TRUE)
    set(CSPICE_INCLUDE_DIRS "$ENV{TOOLSPATH}/include/cspice")
    set(CSPICE_LIBRARY_DIRS ${CSPICE_LIB_AR})
endif()

message("CSPICE - INCLUDE: ${CSPICE_INCLUDE_DIRS}  ---  LIB: ${CSPICE_LIBRARY_DIRS}")

if (CSPICE_FOUND AND NOT TARGET cspice::cspice)
    add_library(cspice::cspice SHARED IMPORTED)
    set_target_properties(cspice::cspice PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CSPICE_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${CSPICE_LIB_AR}")
endif()
