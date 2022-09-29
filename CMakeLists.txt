cmake_minimum_required(VERSION 3.0.0)

project(GrimoireEngine C)

add_library(dices_lib STATIC ./src/engine/dices/dices.c)
target_include_directories(dices_lib PUBLIC ./src/engine/dices/)
add_library(traveler_lib STATIC ./src/engine/traveler/traveler.c)
target_include_directories(traveler_lib PUBLIC ./src/engine/traveler/)

add_executable(GrimoireEngine src/main.c)

target_link_libraries(
    GrimoireEngine PRIVATE 
    dices_lib 
    traveler_lib
)
