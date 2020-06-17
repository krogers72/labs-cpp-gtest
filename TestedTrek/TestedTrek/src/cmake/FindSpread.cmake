# FindSpread.cmake
#
# Finds the spread library and include files
#
# This will define the following variables
#
#   Spread_FOUND
#   Spread_INCLUDE_DIRS
#   Spread_LIBRARY_DIRS
#   Spread_VERSION
#
# and the following imported targets
#
#   spread::Spread
#
# Note: EPOCHA source code expects to find spread includes with #include "spread/xxx.h".
#       Presently, we've installed spread such that the includes are found in
#       $TOOLSPATH/include/spread.
#       In order to not break any EPOCHA code, the Spread_INCLUDE_DIRS variable will be set
#       to $TOOLSPATH/include. If, at a later date, we install spread differently, we may have
#       to change that variable to keep our code compiling.
find_path(Spread_INCLUDE_DIR
    NAMES sp.h
    PATHS "$ENV{TOOLSPATH}/include"
    PATH_SUFFIXES spread)

find_library(Spread_LIB_SO tspread-core
    PATHS "$ENV{TOOLSPATH}/spread/lib"
    NO_DEFAULT_PATH)

mark_as_advanced(Spread_INCLUDE_DIR Spread_LIB_SO)

if (NOT ${Spread_INCLUDE_DIR} STREQUAL "Spread_INCLUDE_DIR-NOTFOUND" AND
        NOT ${Spread_LIB_SO} STREQUAL "Spread_LIB_SO-NOTFOUND")
    set(Spread_FOUND TRUE)
    set(Spread_INCLUDE_DIRS "$ENV{TOOLSPATH}/include")
    set(Spread_LIBRARY_DIRS ${Spread_LIB_SO})
    set(Spread_VERSION 4.0.0)
endif()

message("Spread - INCLUDE: ${Spread_INCLUDE_DIRS}  ---  LIB: ${Spread_LIBRARY_DIRS}")

if (Spread_FOUND AND NOT TARGET spread::Spread)
    add_library(spread::Spread SHARED IMPORTED)
    set_target_properties(spread::Spread PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${Spread_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${Spread_LIB_SO}")
endif()
