#include "player.hpp"

#include "content.hpp"
#include "graphics.hpp"
#include "movement_timing.hpp"
#include "player_movement.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  namespace {
    const Vector2 frame_size(16, 20);

    unsigned int directionIndex(const Direction direction) {
      switch(direction) {
        case Direction::Down:  return 0u; break;
        case Direction::Left:  return 1u; break;
        case Direction::Up:    return 2u; break;
        case Direction::Right: return 3u; break;
      }

      return 0;
    }

    float animationProgress(bool clashing, bool turning) {
      if(clashing || turning) {
        return 0.5f;
      }

      return 0.6f;
    }

    AlternateMovement alternateMovement(const AlternateMovement alternate) {
      if(alternate == AlternateMovement::Right) {
        return AlternateMovement::Left;
      }

      return AlternateMovement::Right;
    }

    unsigned int movementIndex(const AlternateMovement alternate) {
      if(alternate == AlternateMovement::Right) {
        return 1u;
      }

      return 2u;
    }
  }

  Player::Player(const Direction direction)
    : frame_(0, directionIndex(direction))
    , position_(0, 0)
    , alternate_movement_(AlternateMovement::Right)
  {
  }

  void Player::loadContent(const Content& content) {
    texture_ = content.loadTexture("hero.gif");
  }

  void Player::update(const PlayerMovement& player_movement, const MovementTiming& timing) {
    unsigned int direction_index = directionIndex(player_movement.direction());

    if(player_movement.state() == MovementState::Idle) {
      frame_ = Vector2(0, direction_index);
      return;
    }

    unsigned int movement_index = 0;
    const auto turning = player_movement.state() == MovementState::Turning;

    if(timing.progress() < animationProgress(timing.clashing(), turning)) {
      movement_index = movementIndex(alternate_movement_);
    }

    if(timing.finished()) {
      alternate_movement_ = alternateMovement(alternate_movement_);
    }

    frame_ = Vector2(movement_index, direction_index);
  }

  void Player::draw(const Graphics& graphics) const {
    const Rectangle source(frame_ * frame_size, frame_size);
    const Vector2 offset = position_ - frame_size / 2 - Vector2(0, 2);

    graphics.drawTexture(*texture_, offset, source);
  }
}
