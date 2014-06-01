#include "player_movement.hpp"

#include "maybe.hpp"
#include "player_input.hpp"

namespace green_leaf {
  namespace {
    Maybe<Direction> fromInput(const PlayerInput &input) {
      if(input.right()) {
        return Direction::Right;
      } else if(input.left()) {
        return Direction::Left;
      } else if(input.down()) {
        return Direction::Down;
      } else if(input.up()) {
        return Direction::Up;
      }

      return Nothing<Direction>();
    }
  }

  PlayerMovement::PlayerMovement(Direction direction)
    : direction_(direction)
  {
    reset();
  }

  void PlayerMovement::update(const PlayerInput &input) {
    const auto maybe_direction = fromInput(input);

    if(maybe_direction.nothing()) {
      reset();
      return;
    }

    const auto prev_direction = direction_;
    direction_ = maybe_direction.value();

    if(state_ == MovementState::Moving) {
      return;
    }

    if(direction_ == prev_direction) {
      state_ = MovementState::Moving;
    } else {
      state_ = MovementState::Turning;
    }
  }

  void PlayerMovement::reset() {
    state_ = MovementState::Idle;
  }
}
