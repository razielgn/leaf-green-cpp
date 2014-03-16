#ifndef GL_BITMAP_FONT_HPP
#define GL_BITMAP_FONT_HPP

#include "texture.hpp"

#include <memory>

namespace green_leaf {
  class Graphics;

  class BitmapFont {
  public:
    BitmapFont(std::unique_ptr<const Texture> texture);

    unsigned int drawString(const Graphics& graphics, Vector2 offset, const std::string string) const;
  private:
    std::unique_ptr<const Texture> texture_;

    // Returns the drawn character width.
    unsigned int drawCharacter(const Graphics& graphics, Vector2 offset, const char c) const;
  };
}

#endif
