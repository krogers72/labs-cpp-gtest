# FindQwt.cmake
#
# Finds the Qwt library and include files
#
# This will define the following variables
#
#   Qwt_FOUND
#   Qwt_INCLUDE_DIRS
#   Qwt_LIBRARY_DIRS
#
# and the following imported targets
#
#   qwt
#

find_library(QWT_LIB_SO qwt
    PATHS "$ENV{TOOLSPATH}/qwt/lib"
    NO_DEFAULT_PATH)

mark_as_advanced(QWT_LIB_SO)

if (NOT ${QWT_LIB_SO} STREQUAL "QWT_LIB_SO-NOTFOUND")
    set(QWT_FOUND TRUE)
    set(QWT_INCLUDE_DIRS "$ENV{TOOLSPATH}/qwt/include")
    set(QWT_LIBRARY_DIRS ${QWT_LIB_SO})
endif()

message("Qwt - INCLUDE: ${QWT_INCLUDE_DIRS}  ---  LIB: ${QWT_LIBRARY_DIRS}")

if (QWT_FOUND AND NOT TARGET qwt)
    add_library(qwt SHARED IMPORTED)
    set_target_properties(qwt PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${QWT_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${QWT_LIB_SO}")
endif()
