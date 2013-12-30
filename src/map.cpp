#include "game_time.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "map.hpp"
#include "rectangle.hpp"
#include "texture.hpp"

namespace green_leaf {
  void Map::loadContent(Graphics* graphics) {
    background_ = Texture::fromPath(graphics, "map.png");
  }

  void Map::unloadContent() {
    delete background_;
  }

  void Map::update(Input* input, GameTime* game_time) {
  }

  void Map::draw(Graphics* graphics) {
    Rectangle destination(0, 0, 176, 144);

    graphics->drawTexture(background_, &destination);
  }
}
