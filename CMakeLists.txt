cmake_minimum_required(VERSION 3.13.4)

set(TARGET bbb-playground)

# set(CMAKE_C_COMPILER "/usr/bin/clang-13")
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++-13")

project(${TARGET})

add_definitions("-std=c++2a")

add_executable(${TARGET} src/app/main.cpp)

# target_link_libraries(${TARGET} librobotcontrol.so.1.0.5)

target_include_directories(${TARGET} PRIVATE src/include)
