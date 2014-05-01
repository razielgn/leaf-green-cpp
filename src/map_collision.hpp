#ifndef GL_MAP_COLLISION_HPP
#define GL_MAP_COLLISION_HPP

#include "vector2.hpp"

namespace green_leaf {
  class CollisionsLayer;
  class PlayerMovement;

  class MapCollision {
  public:
    MapCollision(const CollisionsLayer& collisions_layer);

    void update(PlayerMovement& player_movement, const Vector2 position, const Vector2 destination) const;

  private:
    const CollisionsLayer& collisions_layer_;
  };
}

#endif
