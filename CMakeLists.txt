cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_Image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_definitions(
  -std=c++1y
  -g
  -Wall
  -Wextra
  -Werror
  -pedantic
)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  add_definitions(
    -stdlib=libc++
  )

  set(extra_linker_flags
    -lc++ -lc++abi
  )
endif()

add_subdirectory("${SRC_DIR}")
add_subdirectory("${TEST_DIR}")
