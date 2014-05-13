#pragma once
#ifndef GL_DIRECTION_HPP
#define GL_DIRECTION_HPP

#include <iosfwd>

namespace green_leaf {
  enum class Direction {
    Right,
    Left,
    Up,
    Down
  };

  ::std::ostream& operator<<(::std::ostream& os, const Direction& m);
}

#endif
