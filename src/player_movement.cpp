#include "player_movement.hpp"

#include "game_time.hpp"
#include "input.hpp"
#include "input_key.hpp"
#include "movement.hpp"

namespace green_leaf {
  PlayerMovement::PlayerMovement(const Movement start)
    : movement_(start)
    , elapsed_mseconds_(0)
    , moving_(false)
    , finished_(false)
    , clashing_(false)
  {
  }

  void PlayerMovement::update(Input& input, const GameTime game_time) {
    if(finished_) {
      finished_ = false;
      moving_ = false;
      clashing_ = false;
      elapsed_mseconds_ = 0;
    }

    if(elapsed_mseconds_ == 0) {
      if(input.isKeyDown(InputKey::Right)) {
        movement_ = Movement::Right;
        moving_ = true;
      } else if(input.isKeyDown(InputKey::Left)) {
        movement_ = Movement::Left;
        moving_ = true;
      } else if(input.isKeyDown(InputKey::Up)) {
        movement_ = Movement::Up;
        moving_ = true;
      } else if(input.isKeyDown(InputKey::Down)) {
        movement_ = Movement::Down;
        moving_ = true;
      } else {
        return;
      }
    }

    elapsed_mseconds_ += game_time.elapsed();

    if(elapsed_mseconds_ >= movement_time()) {
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
