project(green-leaf C CXX)

set(GREEN_LEAF_SRC
  ${SRC_FILES}
  ${MAIN_FILES}
)

add_executable(green-leaf ${GREEN_LEAF_SRC})

target_link_libraries(green-leaf
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
)
