#include "map_json_source.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"
#include "content.hpp"
#include "texture.hpp"
#include "json/json.h"

#include <fstream>

namespace green_leaf {
  TileLayer* extractLayer(Vector2 dimension, Json::Value layer, TileSet* tile_set) {
    std::vector<unsigned int> background_tiles;
    Json::Value data = layer["data"];

    for(unsigned int i = 0; i < data.size(); i++) {
      background_tiles.push_back(data[i].asInt());
    }

    return new TileLayer(dimension, tile_set, background_tiles);
  }

  TileSet* extractTileSet(const Content* content, Vector2 tile_size, Json::Value tile_set, Texture** texture) {
    std::string texture_path = tile_set["image"].asString();
    unsigned int start_code = tile_set["firstgid"].asInt();

    *texture = content->loadTexture(texture_path);
    return new TileSet(*texture, tile_size, start_code);
  }

  Vector2 extractDimension(Json::Value root) {
    return Vector2(
      root["width"].asInt(),
      root["height"].asInt()
    );
  }

  Vector2 extractTileSize(Json::Value root) {
    return Vector2(
      root["tilewidth"].asInt(),
      root["tileheight"].asInt()
    );
  }

  Json::Value parseJsonPath(std::string path) {
    Json::Value root;
    Json::Reader reader;
    std::ifstream input(path);

    bool parsed = reader.parse(input, root);

    if(!parsed) {
      std::cout  << "Failed to parse json\n"
                 << reader.getFormattedErrorMessages();
      throw "failed to parse JSON";
    }

    return root;
  }

  MapJsonSource::MapJsonSource(const Content* content, std::string path)
    : resolution_(Vector2(0, 0))
    , tile_size_(Vector2(0, 0))
  {
    Json::Value root = parseJsonPath(path);

    Vector2 dimension = extractDimension(root);
    tile_size_ = extractTileSize(root);
    resolution_ = dimension * tile_size_;

    background_tile_set_  = extractTileSet(content, tile_size_, root["tilesets"][0], &background_texture_);
    decorations_tile_set_ = extractTileSet(content, tile_size_, root["tilesets"][1], &decorations_texture_);

    background_tile_layer_  = extractLayer(dimension, root["layers"][0], background_tile_set_);
    floor_tile_layer_       = extractLayer(dimension, root["layers"][1], decorations_tile_set_);
    decorations_tile_layer_ = extractLayer(dimension, root["layers"][2], decorations_tile_set_);
    foreground_tile_layer_  = extractLayer(dimension, root["layers"][3], decorations_tile_set_);
  }

  MapJsonSource::~MapJsonSource() {
    delete background_texture_;
    delete decorations_texture_;

    delete background_tile_set_;
    delete decorations_tile_set_;

    delete background_tile_layer_;
    delete floor_tile_layer_;
    delete decorations_tile_layer_;
    delete foreground_tile_layer_;
  }

  TileLayer* MapJsonSource::backgroundLayer() const {
    return background_tile_layer_;
  }

  TileLayer* MapJsonSource::decorationsLayer() const {
    return decorations_tile_layer_;
  }

  TileLayer* MapJsonSource::floorLayer() const {
    return floor_tile_layer_;
  }

  TileLayer* MapJsonSource::foregroundLayer() const {
    return foreground_tile_layer_;
  }
}
