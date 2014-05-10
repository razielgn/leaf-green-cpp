#include "bitmap_font.hpp"

#include "gmock/gmock.h"
#include "graphics_mock.hpp"
#include "texture_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

  class BitmapFontTest : public Test {
  protected:
    BitmapFontTest() { }

    std::unique_ptr<TextureMock> texture_ = std::make_unique<TextureMock>(Vector2(0, 0));
    GraphicsMock graphics_;
    BitmapFont font_ = BitmapFont(std::move(texture_));
  };

  TEST_F(BitmapFontTest, DrawString) {
    EXPECT_CALL(graphics_, drawTexture(_, Vector2( 2, 2), Rectangle(106, 42, 6, 14))); // H
    EXPECT_CALL(graphics_, drawTexture(_, Vector2( 8, 2), Rectangle( 24, 56, 6, 14))); // e
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(14, 2), Rectangle( 62, 56, 5, 14))); // l
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(19, 2), Rectangle( 47, 56, 4, 14))); // i
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(23, 2), Rectangle(144, 28, 4, 14))); // .

    EXPECT_CALL(graphics_, drawTexture(_, Vector2(33, 2), Rectangle(126, 28, 6, 14))); // 9
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(39, 2), Rectangle(132, 28, 6, 14))); // !

    EXPECT_CALL(graphics_, drawTexture(_, Vector2(51, 2), Rectangle(112, 42, 6, 14))); // I
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(57, 2), Rectangle(106, 56, 5, 14))); // t
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(62, 2), Rectangle( 45, 51, 3, 10))); // '
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(65, 2), Rectangle(101, 56, 5, 14))); // s

    EXPECT_CALL(graphics_, drawTexture(_, Vector2(76, 2), Rectangle( 35, 56, 6, 14))); // g
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(82, 2), Rectangle( 78, 56, 6, 14))); // o
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(88, 2), Rectangle( 44, 42, 4, 14))); // ,
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(92, 2), Rectangle(111, 56, 6, 14))); // u

    EXPECT_EQ(98u, font_.drawString(graphics_, Vector2(2, 2), "Heli. 9! It's go,u"));
  }

  TEST_F(BitmapFontTest, DrawUtf8) {
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(0, 0), Rectangle(183, 0, 6, 14))); // é
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(6, 0), Rectangle( 0, 42, 6, 14))); // …

    EXPECT_EQ(12u, font_.drawString(graphics_, Vector2(0, 0), "é…"));
  }

  TEST_F(BitmapFontTest, DrawUtf8WithZeroChars) {
    EXPECT_CALL(graphics_, drawTexture(_, A<Vector2>(), _)).Times(0);

    EXPECT_EQ(0u, font_.drawString(graphics_, Vector2(0, 0), "é…", 0));
  }

  TEST_F(BitmapFontTest, DrawUtf8WithOneChar) {
    EXPECT_CALL(graphics_, drawTexture(_, Vector2(0, 0), Rectangle(183, 0, 6, 14))); // é

    EXPECT_EQ(6u, font_.drawString(graphics_, Vector2(0, 0), "é…", 1));
  }
}
