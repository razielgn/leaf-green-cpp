#ifndef GL_MAP_SOURCE_HPP
#define GL_MAP_SOURCE_HPP

#include "vector2.hpp"

namespace green_leaf {
  class TileLayer;

  class MapSource {
  public:
    virtual ~MapSource() { };

    virtual TileLayer* backgroundLayer() const = 0;
    virtual TileLayer* decorationsLayer() const = 0;
    virtual TileLayer* floorLayer() const = 0;
    virtual TileLayer* foregroundLayer() const = 0;

    virtual Vector2 resolution() const = 0;
    virtual Vector2 tile_size() const = 0;
  };
}

#endif
