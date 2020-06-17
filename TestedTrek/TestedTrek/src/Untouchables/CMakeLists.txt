set (SOURCES SampleClient.cpp)

add_library(Untouchables ${SOURCES})

target_link_libraries(Untouchables
    StarTrek)

target_include_directories(Untouchables PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
