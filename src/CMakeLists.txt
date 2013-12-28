project(green-leaf C CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_Image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

set(GREEN_LEAF_SRC
  game.cpp
  graphics.cpp
  input.cpp
  main.cpp
  map.cpp
  player.cpp
  texture.cpp
)

add_executable(green-leaf ${GREEN_LEAF_SRC})

target_link_libraries(green-leaf
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
)

add_definitions(
  -std=c++11
  -Wall
  -Wextra
  -pedantic
)
