#include "gmock/gmock.h"

#include "collisions_layer.hpp"

namespace green_leaf {
  using namespace ::testing;

  class CollisionsLayerTest : public Test {
  protected:
    CollisionsLayerTest() { }

    const std::vector<Rectangle> rectangles_ = {
      Rectangle(80, 60, 32, 16),
      Rectangle( 0, 16, 32, 32)
    };
    const CollisionsLayer collisions_layer_ = CollisionsLayer(rectangles_);
  };

  TEST_F(CollisionsLayerTest, Rectangles) {
    EXPECT_EQ(rectangles_, collisions_layer_.rectangles());
  }
}
