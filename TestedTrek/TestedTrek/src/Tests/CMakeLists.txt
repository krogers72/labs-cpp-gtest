set (SOURCES MockGalaxy.cpp MockKlingon.cpp PhaserCharacterizationTests.cpp PhotonCharacterizationTests.cpp)

add_executable(AllTests ${SOURCES})

target_link_libraries(AllTests
    gtest
    gmock
    StarTrek
    Untouchables)
