#include "player.hpp"

#include "content.hpp"
#include "game_time.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "movement.hpp"
#include "player_movement.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  Player::Player()
    : frame_(Vector2(0, 0))
    , alternate_walk_(0)
  {
  }

  void Player::loadContent(const Content& content) {
    texture_ = std::unique_ptr<const Texture>(
      content.loadTexture("hero.png")
    );
  }

  void Player::unloadContent() {
  }

  void Player::update(const PlayerMovement& player_movement) {
    int frame_x = frame_.x();
    int frame_y = frame_.y();

    if(player_movement.moving()) {
      switch(player_movement.movement()) {
        case Movement::Down:
          frame_y = 0; break;
        case Movement::Left:
          frame_y = 1; break;
        case Movement::Up:
          frame_y = 2; break;
        case Movement::Right:
          frame_y = 3; break;
        case Movement::Still:
        default: break;
      }
    }

    if(player_movement.moving()) {
      float progress = player_movement.clashing() ? 0.5f : 0.6f;
      if(player_movement.progress() >= progress) {
        frame_x = 0;
      } else {
        if(alternate_walk_ == 0) {
          frame_x = 1;
        } else {
          frame_x = 3;
        }
      }

      if(player_movement.finished()) {
        frame_x = 0;
        alternate_walk_ = (alternate_walk_ + 1) % 2;
      }
    }

    frame_ = Vector2(frame_x, frame_y);
  }

  void Player::draw(const Graphics& graphics) const {
    Rectangle source(frame_ * frame_size_, frame_size_);

    Rectangle destination(
      graphics.size() / 2 - frame_size_ / 2,
      source.size()
    );

    graphics.drawTexture(texture_.get(), destination, source);
  }
}
