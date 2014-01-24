#include "gmock/gmock.h"

#include "collisions_layer.hpp"

namespace green_leaf {
  using namespace ::testing;

  class CollisionsLayerTest : public Test {
  protected:
    CollisionsLayerTest() { }

    const std::vector<Rectangle> rectangles_ = {
      Rectangle(  0,   0, 176,  32),
      Rectangle( 16,  80,  16,   0),
      Rectangle( 16,  96,  16,  16),
      Rectangle( 80,  64,  16,  32),
      Rectangle(112,  32,  32,  32),
      Rectangle(144,  80,  0,   32),
    };
    const CollisionsLayer collisions_layer_ = CollisionsLayer(Vector2(11, 9), Vector2(16, 16), rectangles_);
  };

  TEST_F(CollisionsLayerTest, Rectangles) {
    EXPECT_EQ(rectangles_, collisions_layer_.rectangles());
  }

  TEST_F(CollisionsLayerTest, CanMoveToEmptySpace) {
    EXPECT_TRUE(collisions_layer_.canMove(Vector2(4, 7), Vector2(4, 6)));
    EXPECT_TRUE(collisions_layer_.canMove(Vector2(4, 7), Vector2(5, 7)));
    EXPECT_TRUE(collisions_layer_.canMove(Vector2(4, 7), Vector2(3, 7)));
    EXPECT_TRUE(collisions_layer_.canMove(Vector2(4, 7), Vector2(4, 8)));
  }

  TEST_F(CollisionsLayerTest, CannotMoveOnBounds) {
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(5, 6), Vector2(5, 5)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(6, 3), Vector2(7, 3)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(2, 6), Vector2(1, 6)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(3, 2), Vector2(3, 1)));
  }

  TEST_F(CollisionsLayerTest, CannotMoveOutsideMap) {
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(0, 0), Vector2( 0, -1)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(0, 0), Vector2(-1,  0)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(10, 8), Vector2(10, 9)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(10, 8), Vector2(11, 8)));
  }

  TEST_F(CollisionsLayerTest, CannotCrossBlockedLines) {
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(1, 4), Vector2(1, 5)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(1, 5), Vector2(1, 4)));

    EXPECT_FALSE(collisions_layer_.canMove(Vector2(8, 5), Vector2(9, 5)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(9, 5), Vector2(8, 5)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(8, 6), Vector2(9, 6)));
    EXPECT_FALSE(collisions_layer_.canMove(Vector2(9, 6), Vector2(8, 6)));
  }
}
