cmake_minimum_required(VERSION 3.27)
project(newproj)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(raylib)

add_executable(newproj
        main.cpp
        OrbitalCamera.cpp
        Utils.h
        Utils.cpp
        Q1.h
        Q1.cpp
        Q2.h
        Q2.cpp
)
target_link_libraries(newproj PRIVATE raylib)
