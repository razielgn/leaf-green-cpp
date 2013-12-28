#include "graphics.hpp"
#include "input.hpp"
#include "map.hpp"
#include "texture.hpp"

namespace green_leaf {
  void Map::loadContent(Graphics* graphics) {
    background_ = Texture::fromPath(graphics, "map.png");
  }

  void Map::unloadContent() {
    delete background_;
  }

  void Map::update(Input* input) {
#pragma unused(input)
  }

  void Map::draw(Graphics* graphics) {
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 176;
    rect.h = 144;

    graphics->drawTexture(background_, &rect, &rect);
  }
}
