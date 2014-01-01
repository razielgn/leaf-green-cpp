#ifndef GL_TILE_SET_HPP
#define GL_TILE_SET_HPP

#include "vector2.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  class Texture;

  class TileSet {
  public:
    TileSet(const Texture* texture, const Vector2 tile_size, unsigned int first_gid);

    Rectangle rectangleFromCode(unsigned int tile_code) const;

    const Texture* texture() const {
      return texture_;
    }

    const Vector2 tile_size() const {
      return tile_size_;
    }

  private:
    const Vector2 tile_grid_;
    const Vector2 tile_size_;
    const Texture* texture_;

    const unsigned int first_gid_;
  };
}

#endif
