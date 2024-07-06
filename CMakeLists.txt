cmake_minimum_required(VERSION 3.28)
project(game_of_life C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/SDL2)

find_package(SDL2 REQUIRED)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(CUnit REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${CUNIT_INCLUDE_DIRS} includes)

add_executable(
        game_of_life
        src/main.c
        src/grid.c
        src/renderer.c
        src/game.c
)

add_executable(
        runGridTests
        tests/test_grid.c
        src/grid.c
)

add_executable(
        runRendererTests
        tests/test_renderer.c
        src/renderer.c
        src/grid.c
)

add_executable(
        runGameTests
        tests/test_game.c
        src/game.c
        src/renderer.c
        src/grid.c
)

target_link_libraries(game_of_life ${SDL2_LIBRARIES})
target_link_libraries(runGridTests ${CUNIT_LIBRARIES})
target_link_libraries(runRendererTests ${CUNIT_LIBRARIES} ${SDL2_LIBRARIES})
target_link_libraries(runGameTests ${CUNIT_LIBRARIES} ${SDL2_LIBRARIES})
