#include "bitmap_font.hpp"

#include "graphics.hpp"
#include "unused.hpp"
#include "utf8/checked.h"

#include <map>

namespace green_leaf {
  const std::map<uint32_t, Rectangle> chars {
    { L'!', Rectangle(132, 28, 6, 14) },
    { L',', Rectangle( 44, 42, 4, 14) },
    { L'-', Rectangle(149, 28, 6, 14) },
    { L'.', Rectangle(144, 28, 4, 14) },
    { L'0', Rectangle( 72, 28, 6, 14) },
    { L'1', Rectangle( 78, 28, 6, 14) },
    { L'2', Rectangle( 84, 28, 6, 14) },
    { L'3', Rectangle( 90, 28, 6, 14) },
    { L'4', Rectangle( 96, 28, 6, 14) },
    { L'5', Rectangle(102, 28, 6, 14) },
    { L'6', Rectangle(108, 28, 6, 14) },
    { L'7', Rectangle(114, 28, 6, 14) },
    { L'8', Rectangle(120, 28, 6, 14) },
    { L'9', Rectangle(126, 28, 6, 14) },
    { L'?', Rectangle(138, 28, 6, 14) },
    { L'A', Rectangle( 64, 42, 6, 14) },
    { L'B', Rectangle( 70, 42, 6, 14) },
    { L'C', Rectangle( 76, 42, 6, 14) },
    { L'D', Rectangle( 82, 42, 6, 14) },
    { L'E', Rectangle( 88, 42, 6, 14) },
    { L'F', Rectangle( 94, 42, 6, 14) },
    { L'G', Rectangle(100, 42, 6, 14) },
    { L'H', Rectangle(106, 42, 6, 14) },
    { L'I', Rectangle(112, 42, 6, 14) },
    { L'J', Rectangle(118, 42, 6, 14) },
    { L'K', Rectangle(124, 42, 6, 14) },
    { L'L', Rectangle(130, 42, 6, 14) },
    { L'M', Rectangle(136, 42, 6, 14) },
    { L'N', Rectangle(142, 42, 6, 14) },
    { L'O', Rectangle(148, 42, 6, 14) },
    { L'P', Rectangle(154, 42, 6, 14) },
    { L'Q', Rectangle(160, 42, 6, 14) },
    { L'R', Rectangle(166, 42, 6, 14) },
    { L'S', Rectangle(172, 42, 6, 14) },
    { L'T', Rectangle(178, 42, 6, 14) },
    { L'U', Rectangle(184, 42, 6, 14) },
    { L'V', Rectangle(190, 42, 6, 14) },
    { L'W', Rectangle(196, 42, 6, 14) },
    { L'X', Rectangle(202, 42, 6, 14) },
    { L'Y', Rectangle(208, 42, 6, 14) },
    { L'Z', Rectangle(214, 42, 6, 14) },
    { L'a', Rectangle(  0, 56, 6, 14) },
    { L'b', Rectangle(  6, 56, 6, 14) },
    { L'c', Rectangle( 12, 56, 6, 14) },
    { L'd', Rectangle( 18, 56, 6, 14) },
    { L'e', Rectangle( 24, 56, 6, 14) },
    { L'f', Rectangle( 30, 56, 5, 14) },
    { L'g', Rectangle( 35, 56, 6, 14) },
    { L'h', Rectangle( 41, 56, 6, 14) },
    { L'i', Rectangle( 47, 56, 4, 14) },
    { L'j', Rectangle( 51, 56, 6, 14) },
    { L'k', Rectangle( 57, 56, 5, 14) },
    { L'l', Rectangle( 62, 56, 5, 14) },
    { L'm', Rectangle( 67, 56, 6, 14) },
    { L'n', Rectangle( 73, 56, 5, 14) },
    { L'o', Rectangle( 78, 56, 6, 14) },
    { L'p', Rectangle( 84, 56, 6, 14) },
    { L'q', Rectangle( 90, 56, 6, 14) },
    { L'r', Rectangle( 96, 56, 5, 14) },
    { L's', Rectangle(101, 56, 5, 14) },
    { L't', Rectangle(106, 56, 5, 14) },
    { L'u', Rectangle(111, 56, 6, 14) },
    { L'v', Rectangle(117, 56, 6, 14) },
    { L'w', Rectangle(123, 56, 6, 14) },
    { L'x', Rectangle(129, 56, 6, 14) },
    { L'y', Rectangle(135, 56, 6, 14) },
    { L'z', Rectangle(141, 56, 6, 14) },
    { L'é', Rectangle(183, 0, 6, 14) },
    { L'…', Rectangle(  0, 42, 6, 14) },
    { L'\'', Rectangle( 45, 51, 3, 10) },
  };

  const unsigned int space_width = 6;

  BitmapFont::BitmapFont(std::unique_ptr<const Texture> texture)
    : texture_(std::move(texture))
  {
  }

  unsigned int BitmapFont::drawCharacter(const Graphics& graphics, Vector2 offset, uint32_t c) const {
    auto search = chars.find(c);

    if(search == chars.end()) {
      return space_width;
    }

    Rectangle source_rect = search->second;
    graphics.drawTexture(*texture_, offset, source_rect);

    return source_rect.width();
  }

  unsigned int BitmapFont::drawString(const Graphics& graphics, Vector2 offset, const std::string str) const {
    utf8::iterator<std::string::const_iterator> it(str.begin(), str.begin(), str.end());

    for(; it.base() != str.end(); it++) {
      uint32_t c = *it;
      int char_width = drawCharacter(graphics, offset, c);
      offset = offset + Vector2(char_width, 0);
    }

    return offset.x();
  }
}
