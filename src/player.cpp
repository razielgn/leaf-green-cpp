#include "game_time.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "movement.hpp"
#include "player.hpp"
#include "rectangle.hpp"
#include "texture.hpp"

namespace green_leaf {
  Player::Player()
    : elapsed_(0)
    , frame_number_(0)
    , direction_(0)
    , walking_(false)
    , a_(0)
  {
  }
  void Player::loadContent(Graphics* graphics) {
    texture_ = Texture::fromPath(graphics, "hero.png");
  }

  void Player::unloadContent() {
    delete texture_;
  }

  void Player::update(Input* input, GameTime* game_time) {
    if(elapsed_ == 0) {
      if(input->isKeyDown(InputKey::Right)) {
        walking_ = true;
        direction_ = 3;
      } else if(input->isKeyDown(InputKey::Left)) {
        walking_ = true;
        direction_ = 1;
      } else if(input->isKeyDown(InputKey::Up)) {
        walking_ = true;
        direction_ = 2;
      } else if(input->isKeyDown(InputKey::Down)) {
        walking_ = true;
        direction_ = 0;
      }
    }

    if(walking_) {
      elapsed_ += game_time->elapsed();

      if(elapsed_ / float(movement_time_) >= 0.6) {
        frame_number_ = 0;
      } else {
        if(a_ == 0) {
          frame_number_ = 1;
        } else {
          frame_number_ = 3;
        }
      }

      if(elapsed_ >= movement_time_) {
        elapsed_ = 0;
        walking_ = false;
        frame_number_ = 0;
        a_ = (a_ + 1) % 2;
      }
    }
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
