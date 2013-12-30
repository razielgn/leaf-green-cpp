#include "game_time.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "map.hpp"
#include "point.hpp"
#include "rectangle.hpp"
#include "texture.hpp"

namespace green_leaf {
  Map::Map(Point center)
    : center_(center)
    , dimension_(Point(176, 144))
  {
  }

  void Map::loadContent(Graphics* graphics) {
    background_ = Texture::fromPath(graphics, "map.png");
  }

  void Map::unloadContent() {
    delete background_;
  }

  void Map::update(Input* input, GameTime* game_time) {
  }

  Point Map::drawOffset(Point center, Point map_dimension) const {
    return Point(
      (map_dimension.x() / 2 - center.x() * tile_size_) + 24,
      (map_dimension.y() / 2 - center.y() * tile_size_) + 2
    );
  }

  void Map::draw(Graphics* graphics) {
    Point offset = drawOffset(center_, dimension_);

    Rectangle destination(
      offset.x(),
      offset.y(),
      dimension_.x(),
      dimension_.y()
    );

    graphics->drawTexture(background_, &destination);
  }
}
