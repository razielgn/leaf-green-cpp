#include "game_time.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "movement.hpp"
#include "player.hpp"
#include "player_movement.hpp"
#include "rectangle.hpp"
#include "texture.hpp"

namespace green_leaf {
  Player::Player()
    : frame_(Vector2(0, 0))
    , a_(0)
  {
  }

  void Player::loadContent(Graphics* graphics) {
    texture_ = Texture::fromPath(graphics, "hero.png");
  }

  void Player::unloadContent() {
    delete texture_;
  }

  void Player::update(Input* input, GameTime* game_time, PlayerMovement* player_movement) {
#pragma unused(game_time)
#pragma unused(input)

    int frame_x = frame_.x();
    int frame_y = frame_.y();

    if(player_movement->moving()) {
      switch(player_movement->movement()) {
        case Movement::Down:
          frame_y = 0; break;
        case Movement::Left:
          frame_y = 1; break;
        case Movement::Up:
          frame_y = 2; break;
        case Movement::Right:
          frame_y = 3; break;
        default: break;
      }
    }

    if(player_movement->moving()) {
      if(player_movement->progress() >= 0.6) {
        frame_x = 0;
      } else {
        if(a_ == 0) {
          frame_x = 1;
        } else {
          frame_x = 3;
        }
      }

      if(player_movement->finished()) {
        frame_x = 0;
        a_ = (a_ + 1) % 2;
      }
    }

    frame_ = Vector2(frame_x, frame_y);
  }

  void Player::draw(Graphics* graphics) {
    Rectangle source(frame_ * frame_size_, frame_size_);

    Rectangle destination(
      graphics->size() / 2 - frame_size_ / 2,
      source.size()
    );

    graphics->drawTexture(texture_, &destination, &source);
  }
}
