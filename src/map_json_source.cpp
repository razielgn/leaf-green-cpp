#include "map_json_source.hpp"

#include "collisions_layer.hpp"
#include "content.hpp"
#include "json/json.h"
#include "texture.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"

#include <fstream>

namespace green_leaf {
  const Json::Value findObjectWithName(const Json::Value array, const std::string name) {
    for(const auto object : array) {
      if(object["name"] == name) {
        return object;
      }
    }

    throw "Could not find object.";
  }

  std::unique_ptr<const TileLayer> extractTileLayer(Vector2 dimension, const Json::Value layers, const std::string name, const TileSet& tile_set) {
    std::vector<unsigned int> background_tiles;
    const Json::Value layer = findObjectWithName(layers, name);
    const Json::Value data = layer["data"];

    for(const auto tile_gid : data) {
      background_tiles.push_back(tile_gid.asUInt());
    }

    return std::unique_ptr<const TileLayer>(
      new TileLayer(dimension, tile_set, background_tiles)
    );
  }

  std::unique_ptr<const TileSet> extractTileSet(const Content& content, Vector2 tile_size, const Json::Value tile_sets, const std::string name) {
    Json::Value tile_set = findObjectWithName(tile_sets, name);

    const std::string texture_path = tile_set["image"].asString();
    unsigned int start_code = tile_set["firstgid"].asUInt();
    std::unique_ptr<const Texture> texture = content.loadTexture(texture_path);

    return std::unique_ptr<const TileSet>(
      new TileSet(std::move(texture), tile_size, start_code)
    );
  }

  Rectangle extractRectangle(const Json::Value rect) {
    return Rectangle(
      rect["x"].asInt(),
      rect["y"].asInt(),
      rect["width"].asInt(),
      rect["height"].asInt()
    );
  }

  std::unique_ptr<const CollisionsLayer> extractCollisionsLayer(Vector2 dimension, Json::Value layers, std::string name, Vector2 tile_size) {
    const Json::Value collisions_layer = findObjectWithName(layers, name);
    const Json::Value json_rectangles = collisions_layer["objects"];
    std::vector<Rectangle> rectangles;

    for(const auto rectangle : json_rectangles) {
      rectangles.emplace_back(extractRectangle(rectangle));
    }

    return std::unique_ptr<CollisionsLayer>(
      new CollisionsLayer(dimension, tile_size, rectangles)
    );
  }

  Vector2 extractDimension(const Json::Value root) {
    return Vector2(
      root["width"].asInt(),
      root["height"].asInt()
    );
  }

  Vector2 extractTileSize(const Json::Value root) {
    return Vector2(
      root["tilewidth"].asInt(),
      root["tileheight"].asInt()
    );
  }

  const Json::Value parseJsonPath(const std::string path) {
    Json::Value root;
    Json::Reader reader;
    std::ifstream input(path);

    const bool parsed = reader.parse(input, root);

    if(!parsed) {
      std::cout  << "Failed to parse json\n"
                 << reader.getFormattedErrorMessages();
      throw "failed to parse JSON";
    }

    return root;
  }

  MapJsonSource::MapJsonSource(const Content& content, const std::string path)
    : resolution_(Vector2(0, 0))
    , tile_size_(Vector2(0, 0))
  {
    const Json::Value root = parseJsonPath(path);

    Vector2 dimension = extractDimension(root);
    tile_size_ = extractTileSize(root);
    resolution_ = dimension * tile_size_;

    background_tile_set_  = extractTileSet(content, tile_size_, root["tilesets"], std::string("background"));
    decorations_tile_set_ = extractTileSet(content, tile_size_, root["tilesets"], std::string("decorations"));

    background_tile_layer_  = extractTileLayer(dimension, root["layers"], std::string("background"),  *background_tile_set_);
    floor_tile_layer_       = extractTileLayer(dimension, root["layers"], std::string("floor"),       *decorations_tile_set_);
    decorations_tile_layer_ = extractTileLayer(dimension, root["layers"], std::string("decorations"), *decorations_tile_set_);
    foreground_tile_layer_  = extractTileLayer(dimension, root["layers"], std::string("foreground"),  *decorations_tile_set_);

    collisions_layer_ = extractCollisionsLayer(dimension, root["layers"], "collisions", tile_size_);
  }
}
