#include "movement.hpp"

#include <iostream>

namespace green_leaf {
  ::std::ostream& operator<<(::std::ostream& os, const Movement& m) {
    switch(m) {
      case Movement::Right: return os << "Right"; break;
      case Movement::Left:  return os << "Left"; break;
      case Movement::Up:    return os << "Up"; break;
      case Movement::Down:  return os << "Down"; break;
      case Movement::Still: return os << "Still"; break;
    }

    return os;
  }
}
