cmake_minimum_required(VERSION 3.10)
project(WarehouseSimulation VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()

add_subdirectory(src/models)
add_subdirectory(src/core)
add_subdirectory(src/utils)
add_subdirectory(src/services)
add_subdirectory(src)