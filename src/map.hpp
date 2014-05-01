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
    Map(const MapSource& map_source, const Vector2 screen_size);

    void reset(const Vector2 player_position);
    void update(const PlayerMovement& player_movement, const Vector2 player_position, const Vector2 destination);
    void drawBackground(const Graphics& graphics, const MapSource& map_source) const;
    void drawForeground(const Graphics& graphics, const MapSource& map_source) const;

  private:
    const MapOffset map_offset_;

    Vector2 screen_offset_;
  };
}

#endif
