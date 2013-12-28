#include "player.hpp"
#include "input.hpp"
#include "graphics.hpp"
#include "texture.hpp"

namespace green_leaf {
  void Player::loadContent(Graphics* graphics) {
    texture_ = Texture::from_path(graphics, "hero.png");
  }

  void Player::unloadContent() {
    delete texture_;
  }

  void Player::update(Input* input) {
    if(input->isKeyDown(Right)) {
      direction_ = 3;
      walking_ = true;
    } else if(input->isKeyDown(Left)) {
      direction_ = 1;
      walking_ = true;
    } else if(input->isKeyDown(Up)) {
      direction_ = 2;
      walking_ = true;
    } else if(input->isKeyDown(Down)) {
      direction_ = 0;
      walking_ = true;
    }

    if(input->isKeyUp(Right) ||
       input->isKeyUp(Left)  ||
       input->isKeyUp(Up)  ||
       input->isKeyUp(Down)) {
      walking_ = false;
    }
  }

  void Player::draw(Graphics* graphics) {
    SDL_Rect source_rect, dest_rect;
    int scale = 4;

    int frame_w = 16;
    int frame_h = 20;

    dest_rect.x = 200;
    dest_rect.y = 200;

    source_rect.w = frame_w;
    source_rect.h = frame_h;

    if(walking_) {
      source_rect.x = frame_w * int(((SDL_GetTicks() / 200) % 4));
    } else {
      source_rect.x = 0;
    }
    source_rect.y = frame_h * direction_;

    dest_rect.w = source_rect.w * scale;
    dest_rect.h = source_rect.h * scale;

    graphics->drawTexture(texture_, &source_rect, &dest_rect);
  }
}
