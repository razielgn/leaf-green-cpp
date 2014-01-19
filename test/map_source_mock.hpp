#ifndef GL_MAP_SOURCE_MOCK_HPP
#define GL_MAP_SOURCE_MOCK_HPP

#include "gmock/gmock.h"
#include "map_source.hpp"

namespace green_leaf {
  class MapSourceMock : public MapSource {
  public:
    MOCK_CONST_METHOD0(backgroundLayer, const TileLayer*());
    MOCK_CONST_METHOD0(decorationsLayer, const TileLayer*());
    MOCK_CONST_METHOD0(floorLayer, const TileLayer*());
    MOCK_CONST_METHOD0(foregroundLayer, const TileLayer*());
    MOCK_CONST_METHOD0(collisionsLayer, const CollisionsLayer*());

    MOCK_CONST_METHOD0(resolution, Vector2());
    MOCK_CONST_METHOD0(tile_size, Vector2());
  };
}

#endif
