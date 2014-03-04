#ifndef GL_GRAPHICS_HPP
#define GL_GRAPHICS_HPP

#include "rectangle.hpp"
#include "vector2.hpp"

namespace green_leaf {
  class Texture;

  class Graphics {
  public:
    virtual ~Graphics() { }

    virtual void clear() const = 0;
    virtual void drawTexture(const Texture* texture, const Rectangle destination, const Rectangle source) const = 0;
    virtual void drawTexture(const Texture* texture, const Rectangle destination) const = 0;
    virtual void present() const = 0;

    virtual Vector2 size() const = 0;
  };
}

#endif
