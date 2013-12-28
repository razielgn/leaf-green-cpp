cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_Image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_definitions(
  -std=c++11
  -Wall
  -Wextra
  -pedantic
)

add_subdirectory(src)
add_subdirectory(test)
