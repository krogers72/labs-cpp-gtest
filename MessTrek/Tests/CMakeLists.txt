set (SOURCES YourTests.cpp)

add_executable(YourTests ${SOURCES})

target_link_libraries(YourTests StarTrek gtest gmock)
