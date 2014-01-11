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

namespace green_leaf {
  Map::Map(Vector2 center)
    : center_(center)
    , dimension_(Vector2(176, 144))
    , destination_(center_)
    , offset_(center_)
  {
  }

  void Map::loadContent(const Content* content) {
    background_ = content->loadTexture("map.png");
  }

  void Map::unloadContent() {
    delete background_;
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

  void Map::draw(Graphics* graphics) {
    Rectangle destination(offset_, dimension_);

    graphics->drawTexture(background_, &destination);
  }
}
