#include "menu_triangle_state.hpp"

namespace green_leaf {
  MenuTriangleState::MenuTriangleState()
    : elapsed_(0u)
    , offset_(0u)
    , direction_(Direction::Down)
  {
  }

  void MenuTriangleState::update(GameTime game_time) {
    elapsed_ += game_time.elapsed();

    if(elapsed_ < ANIMATION_TIME) {
      return;
    }

    elapsed_ = 0u;

    if(direction_ == Direction::Down) {
      offset_++;
    } else {
      offset_--;
    }

    if(offset_ == 2) {
      direction_ = Direction::Up;
    } else if (offset_ == 0) {
      direction_ = Direction::Down;
    }
  }
}
