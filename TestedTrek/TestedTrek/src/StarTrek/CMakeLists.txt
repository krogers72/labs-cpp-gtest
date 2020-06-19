set (SOURCES Galaxy.cpp
    Game.cpp
    Klingon.cpp
    Weapon.cpp
    PhotonWeapon.cpp
    PhaserWeapon.cpp
    RandomNumberGenerator.cpp
    RealRandomNumberGenerator.cpp
    Shield.cpp)

add_library(StarTrek ${SOURCES})

target_link_libraries(StarTrek
    Untouchables)

target_include_directories(StarTrek PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
