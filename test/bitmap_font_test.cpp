#include "bitmap_font.hpp"

#include "gmock/gmock.h"
#include "graphics_mock.hpp"
#include "texture_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

  class BitmapFontTest : public Test {
  protected:
    BitmapFontTest() { }

    std::unique_ptr<TextureMock> texture_ =
      std::unique_ptr<TextureMock>(new TextureMock(Vector2(0, 0)));
    GraphicsMock graphics_;
    const BitmapFont font_ = BitmapFont(std::move(texture_));
  };

  TEST_F(BitmapFontTest, DrawString) {
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle( 2, 2, 6, 14), Rectangle(106, 42, 6, 14))); // H
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle( 8, 2, 6, 14), Rectangle( 24, 56, 6, 14))); // e
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(14, 2, 5, 14), Rectangle( 62, 56, 5, 14))); // l
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(19, 2, 4, 14), Rectangle( 47, 56, 4, 14))); // i
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(23, 2, 4, 14), Rectangle(144, 28, 4, 14))); // .

    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(33, 2, 6, 14), Rectangle(126, 28, 6, 14))); // 9
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(39, 2, 6, 14), Rectangle(132, 28, 6, 14))); // !

    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(51, 2, 6, 14), Rectangle(112, 42, 6, 14))); // I
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(57, 2, 5, 14), Rectangle(106, 56, 5, 14))); // t
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(62, 2, 3, 10), Rectangle( 45, 51, 3, 10))); // '
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(65, 2, 5, 14), Rectangle(101, 56, 5, 14))); // s

    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(76, 2, 6, 14), Rectangle( 35, 56, 6, 14))); // g
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(82, 2, 6, 14), Rectangle( 78, 56, 6, 14))); // o
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(88, 2, 4, 14), Rectangle( 44, 42, 4, 14))); // ,
    EXPECT_CALL(graphics_, drawTexture(_, Rectangle(92, 2, 6, 14), Rectangle(111, 56, 6, 14))); // u

    font_.drawString(graphics_, Vector2(2, 2), "Heli. 9! It's go,u");
  }
}
