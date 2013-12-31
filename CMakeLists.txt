cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_Image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_definitions(
  -std=c++11
  -g
  -Wall
  -Wextra
  -pedantic
)

set(SRC_DIR
  "${CMAKE_CURRENT_BINARY_DIR}/src"
)

set(TEST_DIR
  "${CMAKE_CURRENT_BINARY_DIR}/test"
)

add_subdirectory(src)
add_subdirectory(test)
