#ifndef GL_MENU_TRIANGLE_STATE_HPP
#define GL_MENU_TRIANGLE_STATE_HPP

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

    static const unsigned int ANIMATION_TIME = 150u;
  };
}

#endif
