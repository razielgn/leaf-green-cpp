#include "player_movement.hpp"

#include "game_time.hpp"
#include "keyboard_input.hpp"
#include "input_key.hpp"
#include "movement.hpp"

namespace green_leaf {
  PlayerMovement::PlayerMovement(const Movement direction)
    : movement_(Movement::Still)
    , direction_(direction)
    , elapsed_mseconds_(0)
    , finished_(false)
    , clashing_(false)
  {
  }

  void PlayerMovement::update(KeyboardInput& input, const GameTime game_time) {
    if(finished_) {
      finished_ = false;
      clashing_ = false;
      elapsed_mseconds_ = 0;
      direction_ = movement_;
      movement_ = Movement::Still;
    }

    if(elapsed_mseconds_ == 0) {
      if(input.isKeyDown(InputKey::Right)) {
        movement_ = Movement::Right;
      } else if(input.isKeyDown(InputKey::Left)) {
        movement_ = Movement::Left;
      } else if(input.isKeyDown(InputKey::Up)) {
        movement_ = Movement::Up;
      } else if(input.isKeyDown(InputKey::Down)) {
        movement_ = Movement::Down;
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
