#ifndef GL_PLAYER_MOVEMENT_HPP
#define GL_PLAYER_MOVEMENT_HPP

namespace green_leaf {
  class Input;
  class GameTime;

  enum class Movement;

  class PlayerMovement {
  public:
    PlayerMovement();

    void update(Input* input, GameTime* game_time);

    Movement movement() const {
      return movement_;
    }

    bool moving() const {
      return moving_;
    }

    bool finished() const {
      return finished_;
    }

    // Returns a value between 0 and 1, indicating the animation progress.
    float progress() const {
      return elapsed_mseconds_ / float(movement_time_);
    }

  private:
    const int movement_time_ = 250;

    Movement movement_;
    int elapsed_mseconds_;
    bool moving_;
    bool finished_;
  };
}

#endif
