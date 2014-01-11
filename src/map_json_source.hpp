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

    TileLayer* backgroundLayer() const;
    TileLayer* decorationsLayer() const;
    TileLayer* floorLayer() const;
    TileLayer* foregroundLayer() const;

    Vector2 resolution() const {
      return resolution_;
    }

    Vector2 tile_size() const {
      return tile_size_;
    }

  private:
    Vector2 resolution_;
    Vector2 tile_size_;

    Texture* background_texture_;
    Texture* decorations_texture_;

    TileSet* background_tile_set_;
    TileSet* decorations_tile_set_;

    TileLayer* background_tile_layer_;
    TileLayer* floor_tile_layer_;
    TileLayer* decorations_tile_layer_;
    TileLayer* foreground_tile_layer_;
  };
}

#endif
