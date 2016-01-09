#pragma once

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
