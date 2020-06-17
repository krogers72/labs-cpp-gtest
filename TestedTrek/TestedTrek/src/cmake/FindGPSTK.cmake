# FindGPSTK.cmake
#
# Finds the GPSTK library and include files
#
# This will define the following variables
#
#   GPSTK_FOUND
#   GPSTK_INCLUDE_DIRS - GPSTk inlcudes will be found in ${GPSTK_INCLUDE_DIRS}/gpstk
#   GPSTK_LIBRARY_DIRS
#   GPSTK_VERSION
#
# and the following imported targets
#
#   gpstk::GPSTK
#

set (GPSTK_VER_MAJOR "2")
set (GPSTK_VER_MINOR "10")
set (GPSTK_VER_PATCH "6")
set (GPSTK_VER "${GPSTK_VER_MAJOR}.${GPSTK_VER_MINOR}.${GPSTK_VER_PATCH}")

find_library(GPSTK_LIB_SO gpstk
    PATHS "$ENV{TOOLSPATH}/gpstk-${GPSTK_VER}/lib"
    NO_DEFAULT_PATH)

mark_as_advanced(GPSTK_LIB_SO)

if (NOT ${GPSTK_LIB_SO} STREQUAL "GPSTK_LIB_SO-NOTFOUND")
    set(GPSTK_FOUND TRUE)
    set(GPSTK_INCLUDE_DIRS "$ENV{TOOLSPATH}/gpstk-${GPSTK_VER}/include")
    set(GPSTK_LIBRARY_DIRS ${GPSTK_LIB_SO})
    set(GPSTK_VERSION ${GPSTK_VER})
endif()

message("GPSTK - VERSION: ${GPSTK_VERSION} INCLUDE: ${GPSTK_INCLUDE_DIRS}  ---  LIB: ${GPSTK_LIBRARY_DIRS}")
if (GPSTK_FOUND AND NOT TARGET gpstk::GPSTK)
    add_library(gpstk::GPSTK SHARED IMPORTED)
    set_target_properties(gpstk::GPSTK PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${GPSTK_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${GPSTK_LIB_SO}")
endif()
