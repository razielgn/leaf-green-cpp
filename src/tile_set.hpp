#ifndef GL_TILE_SET_HPP
#define GL_TILE_SET_HPP

#include "point.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  class Texture;

  class TileSet {
  public:
    TileSet(const Texture* texture, const Point tile_size, unsigned int first_gid);

    Rectangle rectangleFromCode(unsigned int tile_code) const;

    const Texture* texture() const {
      return texture_;
    }

    const Point tile_size() const {
      return tile_size_;
    }

  private:
    const Point tile_grid_;
    const Point tile_size_;
    const Texture* texture_;

    const unsigned int first_gid_;
  };
}

#endif
