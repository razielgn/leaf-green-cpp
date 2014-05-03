#include "player_animation.hpp"

#include "content.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "movement.hpp"
#include "player_movement.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  PlayerAnimation::PlayerAnimation()
    : frame_(Vector2(0, 0))
    , alternate_movement_(AlternateMovement::Right)
  {
  }

  void PlayerAnimation::loadContent(const Content& content) {
    texture_ = content.loadTexture("hero.png");
  }

  void PlayerAnimation::alternateMovement() {
    if(alternate_movement_ == AlternateMovement::Right) {
      alternate_movement_ = AlternateMovement::Left;
    } else {
      alternate_movement_ = AlternateMovement::Right;
    }
  }

  float PlayerAnimation::animationProgress(bool clashing) const {
    if(clashing) {
      return 0.5f;
    } else {
      return 0.6f;
    }
  }

  Vector2 PlayerAnimation::nextAnimationFrame() const {
    if(alternate_movement_ == AlternateMovement::Right) {
      return Vector2(1, frame_.y());
    } else {
      return Vector2(3, frame_.y());
    }
  }

  Vector2 PlayerAnimation::stillAnimationFrame() const {
    return Vector2(0, frame_.y());
  }

  void PlayerAnimation::update(const PlayerMovement& player_movement) {
    switch(player_movement.movement()) {
      case Movement::Down:
        frame_ = Vector2(frame_.x(), 0); break;
      case Movement::Left:
        frame_ = Vector2(frame_.x(), 1); break;
      case Movement::Up:
        frame_ = Vector2(frame_.x(), 2); break;
      case Movement::Right:
        frame_ = Vector2(frame_.x(), 3); break;
      default: break;
    }

    if(player_movement.progress() >= animationProgress(player_movement.clashing())) {
      frame_ = stillAnimationFrame();

      if(player_movement.finished()) {
        alternateMovement();
      }
    } else {
      frame_ = nextAnimationFrame();
    }
  }

  void PlayerAnimation::draw(const Graphics& graphics) const {
    Rectangle source(frame_ * frame_size_, frame_size_);
    Vector2 offset = graphics.size() / 2 - frame_size_ / 2;

    graphics.drawTexture(*texture_, offset, source);
  }
}
