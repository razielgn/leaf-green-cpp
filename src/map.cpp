#include "content.hpp"
#include "game_time.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "input_key.hpp"
#include "map.hpp"
#include "movement.hpp"
#include "player_movement.hpp"
#include "vector2.hpp"
#include "rectangle.hpp"
#include "sdl_texture.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"

namespace green_leaf {
  Map::Map(Vector2 center)
    : center_(center)
    , dimension_(Vector2(0, 0))
    , destination_(center_)
    , offset_(center_)
  {
  }

  void Map::loadContent(const Content* content) {
    texture_background_ = content->loadTexture("background.png");
    texture_objects_ = content->loadTexture("decorations.png");
    tile_set_background_ = new TileSet(texture_background_, Vector2(16, 16), 1);
    tile_set_objects_ = new TileSet(texture_objects_, Vector2(16, 16), 401);

    std::vector<unsigned int> background_tiles = { 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 23, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    tile_layer_background_ = new TileLayer(Vector2(11, 9), std::string("background"), background_tiles);

    std::vector<unsigned int> floor_tiles = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 432, 433, 444, 445, 445, 445, 446, 0, 0, 0, 441, 442, 443, 454, 455, 455, 455, 456, 0, 0, 0, 0, 0, 0, 454, 455, 455, 455, 456, 0, 0, 0, 0, 0, 0, 464, 465, 465, 465, 466, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    tile_layer_floor_ = new TileLayer(Vector2(11, 9), std::string("floor"), floor_tiles);

    std::vector<unsigned int> object_tiles = { 401, 402, 403, 404, 405, 0, 0, 0, 0, 0, 409, 411, 412, 413, 414, 415, 0, 0, 407, 408, 0, 419, 421, 422, 423, 424, 425, 0, 0, 417, 418, 410, 0, 0, 0, 0, 0, 0, 0, 0, 427, 428, 420, 0, 0, 0, 0, 0, 0, 416, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 426, 0, 0, 0, 0, 0, 451, 452, 453, 0, 0, 436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    tile_layer_objects_ = new TileLayer(Vector2(11, 9), std::string("objects"), object_tiles);

    std::vector<unsigned int> foreground_tiles = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 461, 462, 463, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    tile_layer_foreground_ = new TileLayer(Vector2(11, 9), std::string("foreground"), foreground_tiles);

    dimension_ = tile_set_background_->tile_size() * tile_layer_background_->size();
  }

  void Map::unloadContent() {
    delete texture_background_;
    delete texture_objects_;
    delete tile_set_background_;
    delete tile_set_objects_;
    delete tile_layer_background_;
    delete tile_layer_objects_;
    delete tile_layer_floor_;
    delete tile_layer_foreground_;
  }

  void Map::update(const PlayerMovement* player_movement) {
    if(player_movement->moving()) {
      switch(player_movement->movement()) {
        case Movement::Right:
          destination_ = center_ + Vector2(1, 0); break;
        case Movement::Left:
          destination_ = center_ - Vector2(1, 0); break;
        case Movement::Up:
          destination_ = center_ - Vector2(0, 1); break;
        case Movement::Down:
          destination_ = center_ + Vector2(0, 1); break;
        default: break;
      }
    }

    offset_ = drawOffset(center_, dimension_);

    if(player_movement->moving()) {
      Vector2 destination = drawOffset(destination_, dimension_);
      offset_ = offset_ + (destination - offset_) * player_movement->progress();

      if(player_movement->finished()) {
        center_ = destination_;
      }
    }
  }

  Vector2 Map::drawOffset(Vector2 center, Vector2 map_dimension) const {
    return
      (map_dimension / 2) -
      (center * tile_set_background_->tile_size()) +
      Vector2(24, 2);
      // TODO: Why the hell do we need to add (24, 2)?
  }

  void Map::drawBackground(const Graphics* graphics) const {
    tile_layer_background_->draw(graphics, tile_set_background_, offset_);
    tile_layer_floor_->draw(graphics, tile_set_objects_, offset_);
    tile_layer_objects_->draw(graphics, tile_set_objects_, offset_);
  }

  void Map::drawForeground(const Graphics* graphics) const {
    tile_layer_foreground_->draw(graphics, tile_set_objects_, offset_);
  }
}
