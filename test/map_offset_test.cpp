#include "map_offset.hpp"

#include "gmock/gmock.h"

namespace green_leaf {
  using namespace ::testing;

  class MapOffsetTest : public Test {
  protected:
    MapOffsetTest() { }

    const Vector2 tile_size_ = Vector2(16, 16);
    const Vector2 screen_size_ = Vector2(240, 160);
    const MapOffset map_offset_ = MapOffset(tile_size_, screen_size_);
  };

  TEST_F(MapOffsetTest, DrawOffset) {
    EXPECT_EQ(Vector2(112, 72), map_offset_.centerOffset(Vector2(0, 0)));
    EXPECT_EQ(Vector2(16, -24), map_offset_.centerOffset(Vector2(6, 6)));
    EXPECT_EQ(Vector2(0,  8),   map_offset_.centerOffset(Vector2(7, 4)));
    EXPECT_EQ(Vector2(0, -8),   map_offset_.centerOffset(Vector2(7, 5)));
    EXPECT_EQ(Vector2(0, -24),  map_offset_.centerOffset(Vector2(7, 6)));
  }
}
