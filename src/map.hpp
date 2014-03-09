#ifndef GL_MAP_HPP
#define GL_MAP_HPP

#include "map_offset.hpp"
#include "vector2.hpp"

namespace green_leaf {
  class CollisionsLayer;
  class Graphics;
  class MapSource;
  class PlayerMovement;

  class Map {
  public:
    Map(const MapSource& map_source, Vector2 player_position, Vector2 screen_size);

    void update(PlayerMovement& player_movement, const CollisionsLayer& collisions_layer);
    void drawBackground(const Graphics& graphics, const MapSource& map_source) const;
    void drawForeground(const Graphics& graphics, const MapSource& map_source) const;

  private:
    const MapOffset map_offset_;

    Vector2 player_position_;
    Vector2 destination_;
    Vector2 screen_offset_;

    bool camera_stopped_;
  };
}

#endif
