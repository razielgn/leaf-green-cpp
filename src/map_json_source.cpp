#include "map_json_source.hpp"

#include "collisions_layer.hpp"
#include "content.hpp"
#include "json/json.h"
#include "texture.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"

#include <fstream>

namespace green_leaf {
  Json::Value findObjectWithName(const Json::Value array, const std::string name) {
    for(const auto object : array) {
      if(object["name"] == name) {
        return object;
      }
    }

    throw "Could not find object.";
  }

  const TileLayer* extractTileLayer(Vector2 dimension, const Json::Value layers, const std::string name, const TileSet* tile_set) {
    std::vector<unsigned int> background_tiles;
    Json::Value layer = findObjectWithName(layers, name);
    Json::Value data = layer["data"];

    for(const auto tile_gid : data) {
      background_tiles.push_back(tile_gid.asUInt());
    }

    return new TileLayer(dimension, *tile_set, background_tiles);
  }

  const TileSet* extractTileSet(const Content* content, Vector2 tile_size, Json::Value tile_sets, std::string name) {
    Json::Value tile_set = findObjectWithName(tile_sets, name);
    std::string texture_path = tile_set["image"].asString();
    unsigned int start_code = tile_set["firstgid"].asUInt();
    std::unique_ptr<const Texture> texture(content->loadTexture(texture_path));

    return new TileSet(std::move(texture), tile_size, start_code);
  }

  const CollisionsLayer* extractCollisionsLayer(Vector2 dimension, Json::Value layers, std::string name, Vector2 tile_size) {
    Json::Value collisions_layer = findObjectWithName(layers, name);
    Json::Value json_rectangles = collisions_layer["objects"];
    std::vector<Rectangle> rectangles;

    for(const auto rectangle : json_rectangles) {
      rectangles.emplace_back(
        rectangle["x"].asInt(),
        rectangle["y"].asInt(),
        rectangle["width"].asInt(),
        rectangle["height"].asInt()
      );
    }

    return new CollisionsLayer(dimension, tile_size, rectangles);
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

    background_tile_set_  = extractTileSet(content, tile_size_, root["tilesets"], std::string("background"));
    decorations_tile_set_ = extractTileSet(content, tile_size_, root["tilesets"], std::string("decorations"));

    background_tile_layer_  = extractTileLayer(dimension, root["layers"], std::string("background"), background_tile_set_);
    floor_tile_layer_       = extractTileLayer(dimension, root["layers"], std::string("floor"), decorations_tile_set_);
    decorations_tile_layer_ = extractTileLayer(dimension, root["layers"], std::string("decorations"), decorations_tile_set_);
    foreground_tile_layer_  = extractTileLayer(dimension, root["layers"], std::string("foreground"), decorations_tile_set_);

    collisions_layer_ = extractCollisionsLayer(dimension, root["layers"], "collisions", tile_size_);
  }

  MapJsonSource::~MapJsonSource() {
    delete background_tile_set_;
    delete decorations_tile_set_;

    delete background_tile_layer_;
    delete floor_tile_layer_;
    delete decorations_tile_layer_;
    delete foreground_tile_layer_;

    delete collisions_layer_;
  }
}
