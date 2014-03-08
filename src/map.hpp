#ifndef GL_MAP_HPP
#define GL_MAP_HPP

#include "map_offset.hpp"
#include "vector2.hpp"

namespace green_leaf {
  class Graphics;
  class MapSource;
  class PlayerMovement;

  class Map {
  public:
    Map(const MapSource* map_source, Vector2 player_position, Vector2 screen_size);

    void update(PlayerMovement* player_movement);
    void drawBackground(const Graphics* graphics) const;
    void drawForeground(const Graphics* graphics) const;

  private:
    const MapSource* map_source_;
    const MapOffset map_offset_;

    Vector2 player_position_;
    Vector2 destination_;
    Vector2 screen_offset_;

    bool camera_stopped_;
  };
}

#endif
