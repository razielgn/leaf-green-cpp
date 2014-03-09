#include "map_offset.hpp"

namespace green_leaf {
  MapOffset::MapOffset(Vector2 tile_size, Vector2 screen_size)
    : tile_size_(tile_size)
    , screen_size_(screen_size)
  {
  }

  Vector2 MapOffset::centerOffset(Vector2 center) const {
    return (screen_size_ / 2 - tile_size_ / 2 + Vector2(0, 2)) -
      center * tile_size_;
  }
}
