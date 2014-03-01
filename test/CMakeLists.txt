project(green-leaf-tests C CXX)

add_definitions(
  -Wno-missing-field-initializers
)

file(
  GLOB
  TEST_FILES
  "${TEST_DIR}/*_test.cpp"
)

set(SRC_FILES
  "${SRC_DIR}/collisions_layer.cpp"
  "${SRC_DIR}/game_time.cpp"
  "${SRC_DIR}/input_key.cpp"
  "${SRC_DIR}/jsoncpp.cpp"
  "${SRC_DIR}/map.cpp"
  "${SRC_DIR}/map_json_source.cpp"
  "${SRC_DIR}/player_movement.cpp"
  "${SRC_DIR}/rectangle.cpp"
  "${SRC_DIR}/screen_manager.cpp"
  "${SRC_DIR}/tile_layer.cpp"
  "${SRC_DIR}/tile_set.cpp"
  "${SRC_DIR}/vector2.cpp"
)

set(GTEST_FILES
  "${TEST_DIR}/gmock-gtest-all.cc"
)

set(GREEN_LEAF_TESTS_SRC
  ${TEST_FILES}
  ${SRC_FILES}
  ${GTEST_FILES}
  runner.cpp
)

add_custom_target(test
  COMMAND green-leaf-tests
  ARGS "--gtest_shuffle" "--gtest_color=yes" "--gtest_output=xml"
  DEPENDS green-leaf-tests
)

add_executable(green-leaf-tests
  EXCLUDE_FROM_ALL
  ${GREEN_LEAF_TESTS_SRC}
)

add_dependencies(green-leaf-tests GoogleMock)

include_directories(
  ${SRC_DIR}
  ${TEST_DIR}
)

target_link_libraries(green-leaf-tests
  -lpthread
)
