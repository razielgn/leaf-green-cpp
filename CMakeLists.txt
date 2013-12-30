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

set(SRC_DIR
  "${CMAKE_CURRENT_BINARY_DIR}/src"
)

set(TEST_DIR
  "${CMAKE_CURRENT_BINARY_DIR}/test"
)

file(
  GLOB
  TEST_FILES
  "${TEST_DIR}/*_test.cpp"
)

file(
  GLOB
  SRC_FILES
  "${SRC_DIR}/*.cpp"
)

file(
  GLOB
  MAIN_FILES
  "${SRC_DIR}/*main.cpp"
)

list(REMOVE_ITEM
  SRC_FILES "${MAIN_FILES}"
)

add_subdirectory(src)
add_subdirectory(test)
