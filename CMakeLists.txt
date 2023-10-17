if(LINUX)
  cmake_minimum_required(VERSION 3.13.4)
else()
  cmake_minimum_required(VERSION 3.27.7)
endif()

set(TARGET bbb-playground)

if(LINUX)
  set(CMAKE_C_COMPILER "/usr/bin/clang-13")
  set(CMAKE_CXX_COMPILER "/usr/bin/clang++-13")
endif()

project(${TARGET})

add_definitions("-std=c++2a")

add_executable(${TARGET} src/app/main.cpp)

if(LINUX)
  target_link_libraries(${TARGET} PRIVATE librobotcontrol.so.1.0.5)
endif()

target_include_directories(${TARGET} PRIVATE src/fmt)

target_include_directories(${TARGET} PRIVATE src/include)
