# FindPDS_X86.cmake
#
# Finds the PDS_X86 library and include files
#
# This will define the following variables
#
#   PDS_X86_FOUND
#   PDS_X86_INCLUDE_DIRS
#   PDS_X86_LIBRARY_DIRS
#
# and the following imported targets
#
#   qwt
#

find_library(PDS_X86_LIB_SO PDS_x86
    PATHS "$ENV{TOOLSPATH}/lib"
    NO_DEFAULT_PATH)

mark_as_advanced(PDS_X86_LIB_SO)

if (NOT ${PDS_X86_LIB_SO} STREQUAL "PDS_X86_LIB_SO-NOTFOUND")
    set(PDS_X86_FOUND TRUE)
    set(PDS_X86_INCLUDE_DIRS "$ENV{TOOLSPATH}/include/PDS")
    set(PDS_X86_LIBRARY_DIRS ${PDS_X86_LIB_SO})
endif()

message("PDS_X86 - INCLUDE: ${PDS_X86_INCLUDE_DIRS}  ---  LIB: ${PDS_X86_LIBRARY_DIRS}")

if (PDS_X86_FOUND AND NOT TARGET pds::PDS_X86)
    add_library(pds::PDS_X86 SHARED IMPORTED)
    set_target_properties(pds::PDS_X86 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${PDS_X86_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${PDS_X86_LIB_SO}")
endif()
