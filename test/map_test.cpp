#include "gtest/gtest.h"
#include "content_mock.hpp"
#include "map.hpp"

namespace green_leaf {
  class MapTest : public ::testing::Test {
  protected:
    MapTest()
      : vec_(Vector2(0, 0))
      , map_(Map(vec_))
    {
      map_.loadContent(&content_);
    }

    ~MapTest() {
      map_.unloadContent();
    }

    const Vector2 vec_;
    const ContentMock content_;
    Map map_;
  };

  TEST_F(MapTest, DrawOffset) {
    const Vector2 dimensions = Vector2(176, 144);

    EXPECT_EQ(Vector2(112, 74), map_.drawOffset(Vector2(0, 0), dimensions));
    EXPECT_EQ(Vector2(16, -22), map_.drawOffset(Vector2(6, 6), dimensions));
    EXPECT_EQ(Vector2(0, 10),   map_.drawOffset(Vector2(7, 4), dimensions));
    EXPECT_EQ(Vector2(0, -6),   map_.drawOffset(Vector2(7, 5), dimensions));
    EXPECT_EQ(Vector2(0, -22),  map_.drawOffset(Vector2(7, 6), dimensions));
  }
}
