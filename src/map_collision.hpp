#pragma once
#ifndef GL_MAP_COLLISION_HPP
#define GL_MAP_COLLISION_HPP

#include "vector2.hpp"

namespace green_leaf {
  class CollisionsLayer;

  class MapCollision {
  public:
    MapCollision(const CollisionsLayer& collisions_layer);

    bool canMove(const Vector2 position, const Vector2 destination) const;

  private:
    const CollisionsLayer& collisions_layer_;
  };
}

#endif
