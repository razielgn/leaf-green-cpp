#include "menu_triangle_state.hpp"

namespace green_leaf {
  namespace {
    const unsigned int animation_time = 150u;
  }

  MenuTriangleState::MenuTriangleState()
    : elapsed_(0u)
    , offset_(0u)
    , direction_(Direction::Down)
  {
  }

  void MenuTriangleState::update(GameTime game_time) {
    elapsed_ += game_time.elapsed();

    if(elapsed_ < animation_time) {
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
