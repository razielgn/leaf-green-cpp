#pragma once
#ifndef GL_MAP_HPP
#define GL_MAP_HPP

#include "map_offset.hpp"
#include "vector2.hpp"

namespace green_leaf {
  class Graphics;
  class MapSource;

  class Map {
  public:
    Map(const Vector2 tile_size, const Vector2 screen_size);

    void setup(const Vector2 player_position);
    void update(const float progress, const Vector2 player_position, const Vector2 destination);
    void drawBackground(const Graphics& graphics, const MapSource& map_source) const;
    void drawForeground(const Graphics& graphics, const MapSource& map_source) const;

  private:
    const MapOffset map_offset_;

    Vector2 screen_offset_;
  };
}

#endif
