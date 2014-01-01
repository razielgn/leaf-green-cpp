project(green-leaf-tests C CXX)

set(BUILD_SHARED_LIBS ON)

include(ExternalProject)
ExternalProject_Add(GoogleMock
  URL "https://googlemock.googlecode.com/files/gmock-1.7.0.zip"
  DOWNLOAD_NAME "gmock-1.7.0.zip"
  URL_HASH SHA1=f9d9dd882a25f4069ed9ee48e70aff1b53e3c5a5
  PREFIX "${TEST_DIR}/gmock"
  CMAKE_ARGS -DBUILD_SHARED_LIBS=ON
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property(GoogleMock
  source_dir
  binary_dir
)

file(
  GLOB
  TEST_FILES
  "${TEST_DIR}/*_test.cpp"
)

set(SRC_FILES
  "${SRC_DIR}/game_time.cpp"
  "${SRC_DIR}/graphics.cpp"
  "${SRC_DIR}/map.cpp"
  "${SRC_DIR}/player_movement.cpp"
  "${SRC_DIR}/point.cpp"
  "${SRC_DIR}/rectangle.cpp"
  "${SRC_DIR}/tile_set.cpp"
  "${SRC_DIR}/texture.cpp"
)

set(GREEN_LEAF_TESTS_SRC
  ${TEST_FILES}
  ${SRC_FILES}
  test_helper.cpp
  runner.cpp
)

add_custom_target(test
  COMMAND green-leaf-tests
  ARGS "--gtest_shuffle"
  DEPENDS green-leaf-tests
)

add_executable(green-leaf-tests
  EXCLUDE_FROM_ALL
  ${GREEN_LEAF_TESTS_SRC}
)

add_dependencies(green-leaf-tests GoogleMock)

include_directories(
  ${SRC_DIR}
  "${source_dir}/include"
  "${source_dir}/gtest/include"
)

if(APPLE)
  set(SUFFIX ".dylib")
else(APPLE)
  set(SUFFIX ".so")
endif(APPLE)

target_link_libraries(green-leaf-tests
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
  "${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${SUFFIX}"
  "${binary_dir}/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${SUFFIX}"
)
