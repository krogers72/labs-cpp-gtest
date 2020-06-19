set (SOURCES StarTrek/Game.cpp StarTrek/Klingon.cpp StarTrek/WebGadgetProxy.h)

add_library(StarTrek ${SOURCES})

target_link_libraries(StarTrek)

target_include_directories(StarTrek PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/StarTrek
    ${CMAKE_CURRENT_SOURCE_DIR}/Untouchables)
