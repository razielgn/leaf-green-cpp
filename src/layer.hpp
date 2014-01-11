#ifndef GL_LAYER_HPP
#define GL_LAYER_HPP

#include "vector2.hpp"

namespace green_leaf {
  class Graphics;
  class TileSet;

  class Layer {
  public:
    virtual ~Layer() { };

    virtual std::string name() const = 0;
    virtual Vector2 size() const = 0;

    virtual void draw(const Graphics* graphics,  const TileSet* tile_set, const Vector2 offset) const = 0;
  };
}

#endif
