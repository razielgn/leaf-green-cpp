#include "movement_timing.hpp"

#include "game_time.hpp"

namespace green_leaf {
  namespace {
    unsigned int movementDuration(const bool clashing, const bool turning) {
      if(clashing) {
        return 500;
      } else if(turning) {
        return 150;
      } else {
        return 250;
      }
    }
  }

  MovementTiming::MovementTiming() {
    reset();
  }

  void MovementTiming::update(const GameTime game_time) {
    const unsigned int duration = movementDuration(clashing_, turning_);

    elapsed_ += game_time.elapsed();

    if(elapsed_ >= duration) {
      elapsed_ = duration;
    }
  }

  float MovementTiming::progress() const {
    return elapsed_ / (float)movementDuration(clashing_, turning_);
  }

  bool MovementTiming::finished() const {
    return progress() == 1.0f;
  }

  void MovementTiming::reset() {
    clashing_ = false;
    elapsed_ = 0;
    turning_ = false;
  }
}
