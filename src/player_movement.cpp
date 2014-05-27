#include "player_movement.hpp"

#include "game_time.hpp"
#include "player_input.hpp"

namespace green_leaf {
  PlayerMovement::PlayerMovement(const Direction direction)
    : movement_(Movement::Still)
    , direction_(direction)
    , elapsed_mseconds_(0)
    , finished_(false)
    , clashing_(false)
  {
  }

  void PlayerMovement::reset() {
    finished_ = false;
    clashing_ = false;
    elapsed_mseconds_ = 0;
  }

  void PlayerMovement::update(PlayerInput& input, const GameTime game_time) {
    if(finished_) {
      reset();
    }

    if(elapsed_mseconds_ == 0) {
      movement_ = Movement::Walking;

      if(input.right()) {
        direction_ = Direction::Right;
      } else if(input.left()) {
        direction_ = Direction::Left;
      } else if(input.up()) {
        direction_ = Direction::Up;
      } else if(input.down()) {
        direction_ = Direction::Down;
      } else {
        movement_ = Movement::Still;
        return;
      }
    }

    elapsed_mseconds_ += game_time.elapsed();

    if(elapsed_mseconds_ >= movement_time()) {
      elapsed_mseconds_ = movement_time();
      finished_ = true;
    }
  }

  int PlayerMovement::movement_time() const {
    if(clashing_) {
      return clashing_movement_time_;
    } else {
      return walking_movement_time_;
    }
  }
}
