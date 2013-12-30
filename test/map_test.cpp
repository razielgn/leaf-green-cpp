#include "gtest/gtest.h"
#include "map.hpp"

namespace green_leaf {
  class MapTest : public ::testing::Test {
  protected:
    MapTest()
      : point_(Point(0, 0))
      , map_(Map(point_))
    {
    }

    const Point point_;
    const Map map_;
  };

  TEST_F(MapTest, DrawOffset) {
    const Point dimensions = Point(176, 144);

    EXPECT_EQ(Point(112, 74), map_.drawOffset(Point(0, 0), dimensions));
    EXPECT_EQ(Point(16, -22), map_.drawOffset(Point(6, 6), dimensions));
    EXPECT_EQ(Point(0, 10),   map_.drawOffset(Point(7, 4), dimensions));
    EXPECT_EQ(Point(0, -6),   map_.drawOffset(Point(7, 5), dimensions));
    EXPECT_EQ(Point(0, -22),  map_.drawOffset(Point(7, 6), dimensions));
  }
}
