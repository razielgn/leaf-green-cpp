#include "map_json_source.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"
#include "content.hpp"
#include "texture.hpp"
#include "json/json.h"

#include <fstream>

namespace green_leaf {
  Json::Value findObjectWithName(const Json::Value array, const std::string name) {
    for(const Json::Value &object : array) {
      if(object["name"] == name) {
        return object;
      }
    }

    throw "Could not find object.";
  }

  const TileLayer* extractLayer(Vector2 dimension, const Json::Value layers, const std::string name, const TileSet* tile_set) {
    std::vector<unsigned int> background_tiles;
    Json::Value layer = findObjectWithName(layers, name);
    Json::Value data = layer["data"];

    for(const Json::Value &tile_gid : data) {
      background_tiles.push_back(tile_gid.asInt());
    }

    return new TileLayer(dimension, tile_set, background_tiles);
  }

  const TileSet* extractTileSet(const Content* content, Vector2 tile_size, Json::Value tile_sets, std::string name, Texture** texture) {
    Json::Value tile_set = findObjectWithName(tile_sets, name);
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

    background_tile_set_  = extractTileSet(content, tile_size_, root["tilesets"], std::string("background"), &background_texture_);
    decorations_tile_set_ = extractTileSet(content, tile_size_, root["tilesets"], std::string("decorations"), &decorations_texture_);

    background_tile_layer_  = extractLayer(dimension, root["layers"], std::string("background"), background_tile_set_);
    floor_tile_layer_       = extractLayer(dimension, root["layers"], std::string("floor"), decorations_tile_set_);
    decorations_tile_layer_ = extractLayer(dimension, root["layers"], std::string("decorations"), decorations_tile_set_);
    foreground_tile_layer_  = extractLayer(dimension, root["layers"], std::string("foreground"), decorations_tile_set_);
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

}
