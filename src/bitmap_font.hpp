#pragma once

#include "texture.hpp"

#include <memory>

namespace green_leaf {
  class Graphics;

  class BitmapFont {
  public:
    BitmapFont(std::unique_ptr<const Texture> texture);

    unsigned int drawString(const Graphics& graphics, Vector2 offset, const std::string string) const;
    unsigned int drawString(const Graphics& graphics, Vector2 offset, const std::string string, size_t chars) const;
  private:
    std::unique_ptr<const Texture> texture_;

    // Returns the drawn character width.
    unsigned int drawCharacter(const Graphics& graphics, Vector2 offset, uint32_t c) const;
  };
}
