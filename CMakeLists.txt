project(green-leaf C CXX)

cmake_minimum_required(VERSION 2.8)

add_executable(green-leaf main.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_Image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

target_link_libraries(green-leaf
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
)
