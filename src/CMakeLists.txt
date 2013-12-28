project(green-leaf C CXX)

set(GREEN_LEAF_SRC
  game.cpp
  graphics.cpp
  input.cpp
  main.cpp
  map.cpp
  player.cpp
  rectangle.cpp
  texture.cpp
)

add_executable(green-leaf ${GREEN_LEAF_SRC})

target_link_libraries(green-leaf
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
)
