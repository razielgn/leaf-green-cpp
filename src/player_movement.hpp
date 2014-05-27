#pragma once
#ifndef GL_PLAYER_MOVEMENT_HPP
#define GL_PLAYER_MOVEMENT_HPP

#include "direction.hpp"

namespace green_leaf {
  class PlayerInput;
  class GameTime;

  enum class Movement {
    Still,
    Turning,
    Walking
  };

  class PlayerMovement {
  public:
    PlayerMovement(const Direction direction);

    void update(PlayerInput& input, const GameTime game_time);

    void reset();

    void clashing(bool clashing) {
      clashing_ = clashing;
    }

    Direction direction() const {
      return direction_;
    }

    bool moving() const {
      return movement_ != Movement::Still;
    }

    bool finished() const {
      return finished_;
    }

    bool clashing() const {
      return clashing_;
    }

    // Returns a value between 0 and 1, indicating the animation progress.
    float progress() const {
      return elapsed_mseconds_ / float(movement_time());
    }

  private:
    const int walking_movement_time_ = 250;
    const int clashing_movement_time_ = 500;

    Movement movement_;
    Direction direction_;
    int elapsed_mseconds_;
    bool finished_;
    bool clashing_;

    int movement_time() const;
  };
}

#endif
