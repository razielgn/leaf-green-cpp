#ifndef GL_COLLISIONS_LAYER_HPP
#define GL_COLLISIONS_LAYER_HPP

#include "rectangle.hpp"

#include <vector>
#include <unordered_set>

namespace std {
  template <> struct hash<pair<green_leaf::Vector2, green_leaf::Vector2>>
  {
    size_t operator()(const pair<green_leaf::Vector2, green_leaf::Vector2> &pair) const {
      std::hash<green_leaf::Vector2> hasher;

      return hasher(pair.first) ^ hasher(pair.second);
    }
  };
}

namespace green_leaf {
  class CollisionsLayer {
  public:
    CollisionsLayer(Vector2 size, Vector2 tile_size, const std::vector<Rectangle> rectangles);

    bool canMove(Vector2 origin, Vector2 destination) const;

    std::vector<Rectangle> rectangles() const {
      return rectangles_;
    }

  private:
    const Vector2 tile_size_;
    const Vector2 size_;
    const std::vector<Rectangle> rectangles_;
    std::vector<bool> blocked_tiles_;
    std::unordered_set<std::pair<Vector2, Vector2>> disallowed_moves_;

    bool isTileBlocked(Vector2 pos) const;
    void setTileBlockeAt(Vector2 pos);
  };
}

#endif
