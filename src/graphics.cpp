#include "graphics.hpp"

namespace green_leaf {
  void Graphics::drawTexture(const Texture& texture, const Vector2 offset, const Rectangle source) const {
    drawTexture(texture, Rectangle(offset, source.size()), source);
  }
}
