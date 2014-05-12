#pragma once
#ifndef GL_TILE_LAYER_HPP
#define GL_TILE_LAYER_HPP

#include "vector2.hpp"

#include <vector>

namespace green_leaf {
  class Graphics;
  class TileSet;

  class TileLayer {
  public:
    TileLayer(const Vector2 size, const TileSet& tile_set, const std::vector<unsigned int> tiles);

    const Vector2 size() const {
      return size_;
    }

    const std::vector<unsigned int> tiles() const {
      return tiles_;
    }

    const TileSet& tileSet() const {
      return tile_set_;
    }

    void draw(const Graphics& graphics, const Vector2 offset) const;

  private:
    const TileSet& tile_set_;

    const Vector2 size_;
    const std::vector<unsigned int> tiles_;
  };
}

#endif
