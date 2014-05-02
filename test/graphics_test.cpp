#include "gmock/gmock.h"

#include "graphics.hpp"
#include "graphics_mock.hpp"
#include "texture_mock.hpp"

#include <memory>

namespace green_leaf {
  using namespace ::testing;

  class GraphicsTest : public Test {
  protected:
    GraphicsTest() { }

    std::unique_ptr<TextureMock> texture_ = std::make_unique<TextureMock>(Vector2(0, 0));
    GraphicsMock graphics_;
  };

  TEST_F(GraphicsTest, drawTextureWithVector2Offset) {
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(1, 2, 3, 4), Rectangle(5, 6, 3, 4)));

    graphics_.drawTexture(*texture_, Vector2(1, 2), Rectangle(5, 6, 3, 4));
  }
}
