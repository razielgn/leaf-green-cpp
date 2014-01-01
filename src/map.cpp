#include "game_time.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "input_key.hpp"
#include "map.hpp"
#include "movement.hpp"
#include "player_movement.hpp"
#include "point.hpp"
#include "rectangle.hpp"
#include "texture.hpp"

namespace green_leaf {
  Map::Map(Point center)
    : center_(center)
    , dimension_(Point(176, 144))
    , destination_(center_)
    , offset_(center_)
  {
  }

  void Map::loadContent(Graphics* graphics) {
    background_ = Texture::fromPath(graphics, "map.png");
  }

  void Map::unloadContent() {
    delete background_;
  }

  void Map::update(Input* input, GameTime* game_time, PlayerMovement* player_movement) {
#pragma unused(game_time)
#pragma unused(input)

    if(player_movement->moving()) {
      switch(player_movement->movement()) {
        case Movement::Right:
          destination_ = center_ + Point(1, 0); break;
        case Movement::Left:
          destination_ = center_ - Point(1, 0); break;
        case Movement::Up:
          destination_ = center_ - Point(0, 1); break;
        case Movement::Down:
          destination_ = center_ + Point(0, 1); break;
        default: break;
      }
    }

    offset_ = drawOffset(center_, dimension_);

    if(player_movement->moving()) {
      Point destination = drawOffset(destination_, dimension_);
      offset_ = offset_ + (destination - offset_) * player_movement->progress();

      if(player_movement->finished()) {
        center_ = destination_;
      }
    }
  }

  Point Map::drawOffset(Point center, Point map_dimension) const {
    return Point(
      (map_dimension.x() / 2 - center.x() * tile_size_) + 24,
      (map_dimension.y() / 2 - center.y() * tile_size_) + 2
    );
  }

  void Map::draw(Graphics* graphics) {
    Rectangle destination(offset_, dimension_);

    graphics->drawTexture(background_, &destination);
  }
}
