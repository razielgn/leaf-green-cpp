#include "game_time.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "input_key.hpp"
#include "map.hpp"
#include "movement.hpp"
#include "point.hpp"
#include "rectangle.hpp"
#include "texture.hpp"

namespace green_leaf {
  Map::Map(Point center)
    : center_(center)
    , dimension_(Point(176, 144))
    , elapsed_(0)
    , destination_(center_)
    , offset_(center_)
    , movement_(Movement::Still)
  {
  }

  void Map::loadContent(Graphics* graphics) {
    background_ = Texture::fromPath(graphics, "map.png");
  }

  void Map::unloadContent() {
    delete background_;
  }

  void Map::update(Input* input, GameTime* game_time) {
    if(elapsed_ == 0) {
      if(input->isKeyDown(InputKey::Right)) {
        movement_ = Movement::Right;
        destination_ = center_ + Point(1, 0);
      } else if(input->isKeyDown(InputKey::Left)) {
        movement_ = Movement::Left;
        destination_ = center_ - Point(1, 0);
      } else if(input->isKeyDown(InputKey::Up)) {
        movement_ = Movement::Up;
        destination_ = center_ - Point(0, 1);
      } else if(input->isKeyDown(InputKey::Down)) {
        movement_ = Movement::Down;
        destination_ = center_ + Point(0, 1);
      } else {
        movement_ = Movement::Still;
      }
    }

    offset_ = drawOffset(center_, dimension_);

    if(movement_ != Movement::Still) {
      elapsed_ += game_time->elapsed();

      Point destination = drawOffset(destination_, dimension_);
      offset_ = offset_ + (destination - offset_) * (elapsed_ / float(movement_time_));

      if(elapsed_ >= movement_time_) {
        center_ = destination_;
        elapsed_ = 0;
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
    Rectangle destination(
      offset_.x(),
      offset_.y(),
      dimension_.x(),
      dimension_.y()
    );

    graphics->drawTexture(background_, &destination);
  }
}
