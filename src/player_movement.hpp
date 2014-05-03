#ifndef GL_PLAYER_MOVEMENT_HPP
#define GL_PLAYER_MOVEMENT_HPP

#include "movement.hpp"

namespace green_leaf {
  class Input;
  class GameTime;

  class PlayerMovement {
  public:
    PlayerMovement(const Movement direction);

    void update(Input& input, const GameTime game_time);

    void clashing(bool clashing) {
      clashing_ = clashing;
    }

    Movement movement() const {
      return movement_;
    }

    Movement direction() const {
      return direction_;
    }

    bool moving() const {
      return movement_ != Movement::Still;
    }

    bool still() const {
      return !moving();
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
    Movement direction_;
    int elapsed_mseconds_;
    bool finished_;
    bool clashing_;

    int movement_time() const;
  };
}

#endif
