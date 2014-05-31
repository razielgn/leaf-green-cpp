#pragma once
#ifndef GL_PLAYER_MOVEMENT_HPP
#define GL_PLAYER_MOVEMENT_HPP

#include "direction.hpp"

namespace green_leaf {
  class PlayerInput;

  enum class MovementState {
    Idle,
    Turning,
    Moving
  };

  class PlayerMovement {
  public:
    PlayerMovement(Direction direction);

    Direction direction() const {
      return direction_;
    }

    MovementState state() const {
      return state_;
    }

    void update(const PlayerInput &input);
    void reset();

  private:
    Direction direction_;
    MovementState state_;
  };
}

#endif
