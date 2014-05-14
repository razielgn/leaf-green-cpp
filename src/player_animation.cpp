#include "player_animation.hpp"

#include "content.hpp"
#include "graphics.hpp"
#include "player_movement.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  namespace {
    const Vector2 frame_size = Vector2(16, 20);

    unsigned int directionIndex(const Direction direction) {
      switch(direction) {
        case Direction::Down:  return 0u; break;
        case Direction::Left:  return 1u; break;
        case Direction::Up:    return 2u; break;
        case Direction::Right: return 3u; break;
      }

      return 0;
    }

    float animationProgress(bool clashing) {
      if(clashing) {
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

  PlayerAnimation::PlayerAnimation(const Direction direction)
    : frame_(0, directionIndex(direction))
    , alternate_movement_(AlternateMovement::Right)
  {
  }

  void PlayerAnimation::loadContent(const Content& content) {
    texture_ = content.loadTexture("hero.gif");
  }

  void PlayerAnimation::update(const PlayerMovement& player_movement) {
    unsigned int direction_index = directionIndex(player_movement.direction());
    unsigned int movement_index = 0;

    if(player_movement.progress() < animationProgress(player_movement.clashing())) {
      movement_index = movementIndex(alternate_movement_);
    }

    if(player_movement.finished()) {
      alternate_movement_ = alternateMovement(alternate_movement_);
    }

    frame_ = Vector2(movement_index, direction_index);
  }

  void PlayerAnimation::draw(const Graphics& graphics) const {
    Rectangle source(frame_ * frame_size, frame_size);
    Vector2 offset = graphics.size() / 2 - frame_size / 2 - Vector2(0, 2);

    graphics.drawTexture(*texture_, offset, source);
  }
}
