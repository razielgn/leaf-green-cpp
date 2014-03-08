#include "tile_set.hpp"

#include "rectangle.hpp"
#include "texture.hpp"

namespace green_leaf {
  TileSet::TileSet(const Texture* texture, const Vector2 tile_size, unsigned int start_code_)
    : tile_grid_(texture->size() / tile_size)
    , tile_size_(tile_size)
    , texture_(std::unique_ptr<const Texture>(texture))
    , start_code_(start_code_)
  {
  }

  Rectangle TileSet::rectangleFromCode(unsigned int tile_code) const {
    tile_code -= start_code_;

    return Rectangle(
      tile_code % int(tile_grid_.x()),
      tile_code / tile_grid_.y(),
      tile_size_
    );
  }
}
