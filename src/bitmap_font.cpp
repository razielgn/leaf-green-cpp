#include "bitmap_font.hpp"

#include "graphics.hpp"
#include "unused.hpp"

#include <map>

namespace green_leaf {
  const std::map<char, Rectangle> chars {
    { '!', Rectangle(132, 28, 6, 14) },
    { ',', Rectangle( 44, 42, 4, 14) },
    { '-', Rectangle(149, 28, 6, 14) },
    { '.', Rectangle(144, 28, 4, 14) },
    { '0', Rectangle( 72, 28, 6, 14) },
    { '1', Rectangle( 78, 28, 6, 14) },
    { '2', Rectangle( 84, 28, 6, 14) },
    { '3', Rectangle( 90, 28, 6, 14) },
    { '4', Rectangle( 96, 28, 6, 14) },
    { '5', Rectangle(102, 28, 6, 14) },
    { '6', Rectangle(108, 28, 6, 14) },
    { '7', Rectangle(114, 28, 6, 14) },
    { '8', Rectangle(120, 28, 6, 14) },
    { '9', Rectangle(126, 28, 6, 14) },
    { '?', Rectangle(138, 28, 6, 14) },
    { 'A', Rectangle( 64, 42, 6, 14) },
    { 'B', Rectangle( 70, 42, 6, 14) },
    { 'C', Rectangle( 76, 42, 6, 14) },
    { 'D', Rectangle( 82, 42, 6, 14) },
    { 'E', Rectangle( 88, 42, 6, 14) },
    { 'F', Rectangle( 94, 42, 6, 14) },
    { 'G', Rectangle(100, 42, 6, 14) },
    { 'H', Rectangle(106, 42, 6, 14) },
    { 'I', Rectangle(112, 42, 6, 14) },
    { 'J', Rectangle(118, 42, 6, 14) },
    { 'K', Rectangle(124, 42, 6, 14) },
    { 'L', Rectangle(130, 42, 6, 14) },
    { 'M', Rectangle(136, 42, 6, 14) },
    { 'N', Rectangle(142, 42, 6, 14) },
    { 'O', Rectangle(148, 42, 6, 14) },
    { 'P', Rectangle(154, 42, 6, 14) },
    { 'Q', Rectangle(160, 42, 6, 14) },
    { 'R', Rectangle(166, 42, 6, 14) },
    { 'S', Rectangle(172, 42, 6, 14) },
    { 'T', Rectangle(178, 42, 6, 14) },
    { 'U', Rectangle(184, 42, 6, 14) },
    { 'V', Rectangle(190, 42, 6, 14) },
    { 'W', Rectangle(196, 42, 6, 14) },
    { 'X', Rectangle(202, 42, 6, 14) },
    { 'Y', Rectangle(208, 42, 6, 14) },
    { 'Z', Rectangle(214, 42, 6, 14) },
    { 'a', Rectangle(  0, 56, 6, 14) },
    { 'b', Rectangle(  6, 56, 6, 14) },
    { 'c', Rectangle( 12, 56, 6, 14) },
    { 'd', Rectangle( 18, 56, 6, 14) },
    { 'e', Rectangle( 24, 56, 6, 14) },
    { 'f', Rectangle( 30, 56, 5, 14) },
    { 'g', Rectangle( 35, 56, 6, 14) },
    { 'h', Rectangle( 41, 56, 6, 14) },
    { 'i', Rectangle( 47, 56, 4, 14) },
    { 'j', Rectangle( 51, 56, 6, 14) },
    { 'k', Rectangle( 57, 56, 5, 14) },
    { 'l', Rectangle( 62, 56, 5, 14) },
    { 'm', Rectangle( 67, 56, 6, 14) },
    { 'n', Rectangle( 73, 56, 5, 14) },
    { 'o', Rectangle( 78, 56, 6, 14) },
    { 'p', Rectangle( 84, 56, 6, 14) },
    { 'q', Rectangle( 90, 56, 6, 14) },
    { 'r', Rectangle( 96, 56, 5, 14) },
    { 's', Rectangle(101, 56, 5, 14) },
    { 't', Rectangle(106, 56, 5, 14) },
    { 'u', Rectangle(111, 56, 6, 14) },
    { 'v', Rectangle(117, 56, 6, 14) },
    { 'w', Rectangle(123, 56, 6, 14) },
    { 'x', Rectangle(129, 56, 6, 14) },
    { 'y', Rectangle(135, 56, 6, 14) },
    { 'z', Rectangle(141, 56, 6, 14) },
    { '\x85', Rectangle(  0, 42, 6, 14) },
    { '\'', Rectangle( 45, 51, 3, 10) },
  };

  const int space_width = 6;

  BitmapFont::BitmapFont(std::unique_ptr<const Texture> texture)
    : texture_(std::move(texture))
  {
  }

  int BitmapFont::drawCharacter(const Graphics& graphics, Vector2 offset, const char c) const {
    auto search = chars.find(c);

    if(search == chars.end()) {
      return space_width;
    }

    Rectangle source_rect = search->second;
    graphics.drawTexture(*texture_, offset, source_rect);

    return source_rect.width();
  }

  void BitmapFont::drawString(const Graphics& graphics, Vector2 offset, const std::string string) const {
    for(const char& c : string) {
      int char_width = drawCharacter(graphics, offset, c);
      offset = offset + Vector2(char_width, 0);
    }
  }
}
