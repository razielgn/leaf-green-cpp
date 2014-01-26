#ifndef GL_TILE_LAYER_HPP
#define GL_TILE_LAYER_HPP

#include <vector>

#include "vector2.hpp"

namespace green_leaf {
  class Graphics;
  class TileSet;

  class TileLayer {
  public:
    TileLayer(Vector2 size, const TileSet* tile_set, std::vector<unsigned int> tiles);
    ~TileLayer();

    Vector2 size() const {
      return size_;
    }

    std::vector<unsigned int> tiles() const {
      return tiles_;
    }

    const TileSet* tileSet() const {
      return tile_set_;
    }

    void draw(const Graphics* graphics, const Vector2 offset) const;

  private:
    const TileSet* tile_set_;

    const Vector2 size_;
    const std::vector<unsigned int> tiles_;
  };
}

#endif
