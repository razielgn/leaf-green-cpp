#ifndef GL_MAP_JSON_SOURCE_HPP
#define GL_MAP_JSON_SOURCE_HPP

#include "map_source.hpp"

namespace green_leaf {
  class Content;
  class Texture;
  class TileSet;

  class MapJsonSource : public MapSource {
  public:
    MapJsonSource(const Content* content, std::string path);
    ~MapJsonSource();

    Vector2 resolution() const {
      return resolution_;
    }

    Vector2 tile_size() const {
      return tile_size_;
    }

    const TileLayer* backgroundLayer() const {
      return background_tile_layer_;
    }

    const TileLayer* decorationsLayer() const {
      return decorations_tile_layer_;
    }

    const TileLayer* floorLayer() const {
      return floor_tile_layer_;
    }

    const TileLayer* foregroundLayer() const {
      return foreground_tile_layer_;
    }

    const CollisionsLayer* collisionsLayer() const {
      return collisions_layer_;
    }

  private:
    Vector2 resolution_;
    Vector2 tile_size_;

    Texture* background_texture_;
    Texture* decorations_texture_;

    const TileSet* background_tile_set_;
    const TileSet* decorations_tile_set_;

    const TileLayer* background_tile_layer_;
    const TileLayer* floor_tile_layer_;
    const TileLayer* decorations_tile_layer_;
    const TileLayer* foreground_tile_layer_;
    const CollisionsLayer* collisions_layer_;
  };
}

#endif
