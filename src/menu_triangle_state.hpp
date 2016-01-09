#pragma once

#include "game_time.hpp"

namespace green_leaf {
  struct MenuTriangleState {
    MenuTriangleState();

    unsigned int offset() const {
      return offset_;
    }

    void update(GameTime game_time);

  private:
    enum Direction {
      Down,
      Up
    };

    unsigned int elapsed_;
    unsigned int offset_;
    Direction direction_;
  };
}
