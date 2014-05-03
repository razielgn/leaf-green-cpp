#ifndef GL_MOVEMENT_HPP
#define GL_MOVEMENT_HPP

#include <iostream>

namespace green_leaf {
  enum class Movement {
    Still,
    Right,
    Left,
    Up,
    Down
  };

  ::std::ostream& operator<<(::std::ostream& os, const Movement& m);
}

#endif
