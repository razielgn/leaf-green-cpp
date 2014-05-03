#include "map_json_source.hpp"

#include "collisions_layer.hpp"
#include "content.hpp"
#include "json/json.h"
#include "texture.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"
#include "utils/string.hpp"

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

    return std::make_unique<const TileLayer>(dimension, tile_set, background_tiles);
  }

  std::unique_ptr<const TileSet> extractTileSet(const Content& content, Vector2 tile_size, const Json::Value tile_sets, const std::string name) {
    Json::Value tile_set = findObjectWithName(tile_sets, name);

    const std::string texture_path = tile_set["image"].asString();
    unsigned int start_code = tile_set["firstgid"].asUInt();
    std::unique_ptr<const Texture> texture = content.loadTexture(texture_path);

    return std::make_unique<const TileSet>(std::move(texture), tile_size, start_code);
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

    return std::make_unique<const CollisionsLayer>(dimension, tile_size, rectangles);
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

  message extractMessage(const std::string string_message) {
    auto lines = utils::split(string_message, "\n");

    if(lines.size() == 1) {
      return std::make_pair(lines[0], "");
    } else {
      return std::make_pair(lines[0], lines[1]);
    }
  }

  std::vector<message> extractMessages(const Json::Value properties) {
    const Json::Value json_messages = properties["message"];

    if(!json_messages) {
      return {};
    }

    std::vector<message> messages;
    auto split_messages = utils::split(json_messages.asString(), "|");

    for(auto single_message : split_messages) {
      messages.push_back(extractMessage(single_message));
    }

    return messages;
  }

  std::vector<Object> extractObjects(const Json::Value layers, const std::string name, const Vector2 tile_size) {
    const Json::Value layer = findObjectWithName(layers, name);
    const Json::Value json_objects = layer["objects"];
    std::vector<Object> objects;

    for(const auto json_object : json_objects) {
      objects.emplace_back(
        extractRectangle(json_object) / tile_size,
        extractMessages(json_object["properties"])
      );
    }

    return objects;
  }

  const Json::Value parseJson(const std::string path) {
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
    const Json::Value root = parseJson(path);

    Vector2 dimension = extractDimension(root);
    tile_size_ = extractTileSize(root);
    resolution_ = dimension * tile_size_;

    background_tile_set_  = extractTileSet(content, tile_size_, root["tilesets"], "background");
    decorations_tile_set_ = extractTileSet(content, tile_size_, root["tilesets"], "decorations");

    background_tile_layer_  = extractTileLayer(dimension, root["layers"], "background",  *background_tile_set_);
    floor_tile_layer_       = extractTileLayer(dimension, root["layers"], "floor",       *decorations_tile_set_);
    decorations_tile_layer_ = extractTileLayer(dimension, root["layers"], "decorations", *decorations_tile_set_);
    foreground_tile_layer_  = extractTileLayer(dimension, root["layers"], "foreground",  *decorations_tile_set_);

    collisions_layer_ = extractCollisionsLayer(dimension, root["layers"], "collisions", tile_size_);

    objects_ = extractObjects(root["layers"], "objects", tile_size_);
  }
}
