#include "collisions_layer.hpp"

namespace green_leaf {
  CollisionsLayer::CollisionsLayer(Vector2 size, Vector2 tile_size, const std::vector<Rectangle> rectangles)
    : tile_size_(tile_size)
    , size_(size)
    , rectangles_(rectangles)
    , blocked_tiles_(std::vector<bool>((unsigned long)(size.x() * size.y()), true))
    , disallowed_moves_(std::unordered_set<std::pair<Vector2, Vector2>>())
  {
    for(const auto rect_ : rectangles) {
      Rectangle rect = rect_ / tile_size;
      Vector2 fin = rect.origin() + rect.size();

      if(rect.size().x() == 0) {
        for(int y = rect.origin().y(); y < fin.y(); y++) {
          disallowed_moves_.insert(
            std::make_pair(
              Vector2(rect.origin().x() - 1, y),
              Vector2(rect.origin().x(),     y)
            )
          );
        }
      } else if(rect.size().y() == 0) {
        for(int x = rect.origin().x(); x < fin.x(); x++) {
          disallowed_moves_.insert(
            std::make_pair(
              Vector2(x, rect.origin().y() - 1),
              Vector2(x, rect.origin().y())
            )
          );
        }
      } else {
        for(int y = rect.origin().y(); y < fin.y(); y++) {
          for(int x = rect.origin().x(); x < fin.x(); x++) {
            setTileBlockeAt(Vector2(x, y));
          }
        }
      }
    }
  }

  bool CollisionsLayer::canMove(Vector2 origin, Vector2 destination) const {
    if(destination.x() >= size_.x() || destination.y() >= size_.y())
      return false;

    if(destination.x() < 0 || destination.y() < 0)
      return false;

    if(isTileBlocked(destination))
      return false;

    if(disallowed_moves_.count(std::make_pair(origin, destination)) > 0)
      return false;

    if(disallowed_moves_.count(std::make_pair(destination, origin)) > 0)
      return false;

    return true;
  }

  unsigned long tile_index(Vector2 pos, Vector2 size) {
    return (unsigned long)(pos.x() + pos.y() * size.x());
  }

  bool CollisionsLayer::isTileBlocked(Vector2 pos) const {
    return !blocked_tiles_[tile_index(pos, size_)];
  }

  void CollisionsLayer::setTileBlockeAt(Vector2 pos) {
    blocked_tiles_[tile_index(pos, size_)] = false;
  }
}
