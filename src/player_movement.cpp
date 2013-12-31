#include "game_time.hpp"
#include "input.hpp"
#include "player_movement.hpp"

namespace green_leaf {
  PlayerMovement::PlayerMovement()
    : movement_(Movement::Still)
    , elapsed_mseconds_(0)
    , moving_(false)
    , finished_(false)
  {
  }

  void PlayerMovement::update(Input* input, GameTime* game_time) {
    if(finished_) {
      finished_ = false;
      moving_ = false;
      elapsed_mseconds_ = 0;
    }

    if(elapsed_mseconds_ == 0) {
      if(input->isKeyDown(InputKey::Right)) {
        movement_ = Movement::Right;
        moving_ = true;
      } else if(input->isKeyDown(InputKey::Left)) {
        movement_ = Movement::Left;
        moving_ = true;
      } else if(input->isKeyDown(InputKey::Up)) {
        movement_ = Movement::Up;
        moving_ = true;
      } else if(input->isKeyDown(InputKey::Down)) {
        movement_ = Movement::Down;
        moving_ = true;
      } else {
        movement_ = Movement::Still;
        return;
      }
    }

    elapsed_mseconds_ += game_time->elapsed();

    if(elapsed_mseconds_ >= movement_time_) {
      finished_ = true;
    }
  }
}
