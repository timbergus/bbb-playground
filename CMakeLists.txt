cmake_minimum_required(VERSION 3.25.7)

project(bbb-playground)

add_definitions("-std=c++2b")

add_executable(bbb-playground src/app/main.cpp)

target_include_directories(bbb-playground PRIVATE src/include)
