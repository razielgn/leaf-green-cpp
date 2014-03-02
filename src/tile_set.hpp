#ifndef GL_TILE_SET_HPP
#define GL_TILE_SET_HPP

#include "rectangle.hpp"
#include "vector2.hpp"

namespace green_leaf {
  class Texture;

  class TileSet {
  public:
    TileSet(const Texture* texture, const Vector2 tile_size, unsigned int start_code);
    ~TileSet();

    Rectangle rectangleFromCode(unsigned int tile_code) const;

    const Texture* texture() const {
      return texture_;
    }

    const Vector2 tileSize() const {
      return tile_size_;
    }

    int startCode() const {
      return start_code_;
    }

  private:
    const Vector2 tile_grid_;
    const Vector2 tile_size_;
    const Texture* texture_;

    const unsigned int start_code_;
  };
}

#endif
