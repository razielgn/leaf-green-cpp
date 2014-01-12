#ifndef GL_MAP_HPP
#define GL_MAP_HPP

#include "vector2.hpp"

namespace green_leaf {
  class Content;
  class Graphics;
  class MapSource;
  class PlayerMovement;

  class Map {
  public:
    Map(const MapSource* map_source, Vector2 playerPosition);

    void update(const PlayerMovement* player_movement, Vector2 screenSize);
    void drawBackground(const Graphics* graphics) const;
    void drawForeground(const Graphics* graphics) const;

    // TODO: Mark private, it's here just for testing purposes.
    Vector2 drawOffset(Vector2 center, Vector2 screenSize) const;

  private:
    const MapSource* map_source_;

    Vector2 playerPosition_;
    Vector2 destination_;
    Vector2 screenOffset_;
  };
}

#endif
