#include "rectangle.hpp"
#include "texture.hpp"
#include "tile_set.hpp"

namespace green_leaf {
  TileSet::TileSet(const Texture* texture, const Point tile_size, unsigned int first_gid)
    : tile_grid_(texture->size() / tile_size)
    , tile_size_(tile_size)
    , texture_(texture)
    , first_gid_(first_gid)
  {
  }

  Rectangle TileSet::rectangleFromCode(unsigned int tile_code) const {
    tile_code -= first_gid_;

    return Rectangle(
      tile_code % int(tile_grid_.x()),
      tile_code / tile_grid_.y(),
      tile_size_
    );
  }
}
