#include "map_collision.hpp"

#include "collisions_layer.hpp"
#include "direction.hpp"
#include "gtest/gtest.h"
#include "player_movement.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  using namespace ::testing;

  class MapCollisionTest : public Test {
  protected:
    MapCollisionTest() { }

    const std::vector<Rectangle> rectangles_ = {
      Rectangle(  0,   0, 176,  32),
      Rectangle( 16,  80,  16,   0),
      Rectangle( 16,  96,  16,  16),
      Rectangle( 80,  64,  16,  32),
      Rectangle(112,  32,  32,  32),
      Rectangle(144,  80,  0,   32),
    };
    const CollisionsLayer collisions_layer_ = CollisionsLayer(
      Vector2(11, 9),
      Vector2(16, 16),
      rectangles_
    );
    const MapCollision map_collision_ = MapCollision(collisions_layer_);
  };

  TEST_F(MapCollisionTest, CanMoveReturnsTrueWhenNotCrossingCollisionBounds) {
    EXPECT_TRUE(map_collision_.canMove(Vector2(4, 6), Vector2(4, 7)));
  }

  TEST_F(MapCollisionTest, CanMoveReturnsFalseWhenCrossingCollisionBounds) {
    EXPECT_FALSE(map_collision_.canMove(Vector2(5, 6), Vector2(5, 5)));
  }
}
