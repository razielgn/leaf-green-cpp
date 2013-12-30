#include "game_time.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "player.hpp"
#include "rectangle.hpp"
#include "texture.hpp"

namespace green_leaf {
  void Player::loadContent(Graphics* graphics) {
    texture_ = Texture::fromPath(graphics, "hero.png");
  }

  void Player::unloadContent() {
    delete texture_;
  }

  void Player::update(Input* input, GameTime* game_time) {
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

    frame_number_ = int(((game_time->total() / 200) % 4));
  }

  void Player::draw(Graphics* graphics) {
    int frame_w = 16;
    int frame_h = 20;
    int x = 0;

    if(walking_) {
      x = frame_w * frame_number_;
    }

    Rectangle source(
      x,
      frame_h * direction_,
      frame_w,
      frame_h
    );

    Rectangle destination(
      graphics->width() / 2 - frame_w / 2,
      graphics->height() / 2 - frame_h / 2,
      source.width(),
      source.height()
    );

    graphics->drawTexture(texture_, &destination, &source);
  }
}
