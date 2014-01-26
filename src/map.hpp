#ifndef GL_MAP_HPP
#define GL_MAP_HPP

#include "vector2.hpp"

namespace green_leaf {
  class Content;
  class Graphics;
  class MapSource;
  class PlayerMovement;

  class MapOffset {
  public:
    MapOffset(Vector2 tile_size, Vector2 screen_size);

    Vector2 centerOffset(Vector2 center) const;

  private:
    const Vector2 tile_size_;
    const Vector2 screen_size_;
  };

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
