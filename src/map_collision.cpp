#include "map_collision.hpp"

#include "collisions_layer.hpp"

namespace green_leaf {
  MapCollision::MapCollision(const CollisionsLayer& collisions_layer)
    : collisions_layer_(collisions_layer)
  {
  }

  bool MapCollision::canMove(const Vector2 position, const Vector2 destination) const {
    return collisions_layer_.canMove(position, destination);
  }
}
