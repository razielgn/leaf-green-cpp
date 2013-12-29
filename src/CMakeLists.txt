project(green-leaf C CXX)

set(SRC_DIR ${CMAKE_CURRENT_BINARY_DIR})

file(
  GLOB
  SRC_FILES
  "${SRC_DIR}/*.cpp"
)

set(GREEN_LEAF_SRC
  ${SRC_FILES}
)

add_executable(green-leaf ${GREEN_LEAF_SRC})

target_link_libraries(green-leaf
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
)
